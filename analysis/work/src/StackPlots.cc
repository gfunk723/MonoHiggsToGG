#include "../interface/StackPlots.hh"

StackPlots::StackPlots()
{

  //------------------------------------------------------------------------
  // Setup samples
  //------------------------------------------------------------------------
  for (TStrBoolMapIter iter = Config::SampleMap.begin(); iter != Config::SampleMap.end(); ++iter) {
    if ((*iter).second) { // Data
      fDataNames.push_back((*iter).first);
    }
    else { // MC
      if (((*iter).first).Contains("mZP",TString::kExact)) fSigNames.push_back((*iter).first);
      else fBkgNames.push_back((*iter).first);
    }
  }
  fNData = fDataNames.size();
  fNBkg  = fBkgNames.size();
  fNSig  = fSigNames.size();
  std::cout << "DataSize = " << fNData << " BkgSize = " << fNBkg << " SigSize = " << fNSig << std::endl;

  //------------------------------------------------------------------------
  // Make map to store indices for bkg samples 
  //------------------------------------------------------------------------
  for (Int_t mc = 0; mc < fNBkg; mc++){
    fBkgIndicesMap[fBkgNames[mc]] = mc;
  } 

  //------------------------------------------------------------------------
  // Setup output
  //------------------------------------------------------------------------
  fOutDir = Form("%s/stacks",Config::outdir.Data()); // where to put output stack plots 
  MakeOutDir(fOutDir); // make output directory 
  fOutFile = new TFile(Form("%s/stackplots_canv.root",fOutDir.Data()),"RECREATE"); // ouput tfile to store canvases here for quick editting

  //------------------------------------------------------------------------
  // Initialize objects
  //------------------------------------------------------------------------
  StackPlots::OpenInputFiles();            // open the input files
  StackPlots::InitTH1FNamesAndSubDNames(); // get histo names from plotnames file
  MakeSubDirs(fTH1FSubDMap,fOutDir);       // setup output subdir
  StackPlots::InitInputPlots();            // initialize input histos
  StackPlots::InitOutputCanvPads();        // initialize output canv
  StackPlots::InitOutputPlots();           // initialize output histos
  StackPlots::InitOutputLegends();         // initialize output legends
  StackPlots::InitRatioPlots();            // initialize output ratio plots
  StackPlots::InitRatioLines();            // initialize output ratio lines

}

void StackPlots::DoStack()
{

  //------------------------------------------------------------------------
  // Start running
  //------------------------------------------------------------------------
  StackPlots::MakeStackPlots();

}

void StackPlots::MakeStackPlots()
{

  //------------------------------------------------------------------------
  // Copy plots into output hists/stacks
  //------------------------------------------------------------------------
  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){

    //------------------------------------------------------------------------
    // Copy data
    //------------------------------------------------------------------------
    for (Int_t data = 0; data < fNData; data++){
      if (data==0) fOutDataTH1FHists[th1f] = (TH1F*)fInDataTH1FHists[th1f][data]->Clone();
      else         fOutDataTH1FHists[th1f]->Add(fInDataTH1FHists[th1f][data]);
    }
    fTH1FLegends[th1f]->AddEntry(fOutDataTH1FHists[th1f],"Data","epl");
 
    //------------------------------------------------------------------------
    // Copy bkg 
    //------------------------------------------------------------------------
    for (Int_t mc = 0; mc < fNBkg; mc++){
      if (mc==0) fOutBkgTH1FHists[th1f] = (TH1F*)fInBkgTH1FHists[th1f][mc]->Clone();
      else       fOutBkgTH1FHists[th1f]->Add(fInBkgTH1FHists[th1f][mc]);
    }

    //------------------------------------------------------------------------
    // Scale to data if called 
    //------------------------------------------------------------------------
    if (Config::useData && Config::scaleToData){
      Double_t dataint = fOutDataTH1FHists[th1f]->Integral();
      Double_t bkgint  = fOutBkgTH1FHists[th1f]->Integral();
      //------------------------------------------------------------------------
      // Add the bkg int. in the blinded region of mgg plots 
      //------------------------------------------------------------------------
      if (fTH1FNames[th1f].Contains("mgg",TString::kExact) && Config::doBlind){
        Int_t binLo = fOutBkgTH1FHists[th1f]->FindBin(115);
        Int_t binHi = fOutBkgTH1FHists[th1f]->FindBin(135);
        Float_t mggint = fOutBkgTH1FHists[th1f]->Integral(binLo,binHi);
        dataint += mggint;
      }
      Double_t scale = dataint/bkgint;
      fOutBkgTH1FHists[th1f]->Scale(scale);
      for (Int_t mc = 0; mc < fNBkg; mc++ ){
        fInBkgTH1FHists[th1f][mc]->Scale(scale);
      }
    }
 
    //------------------------------------------------------------------------
    // Use Gjets weighted to QCD as QCD
    //------------------------------------------------------------------------
    if (Config::doQCDrewgt){
      Double_t qcdint  = fInBkgTH1FHists[th1f][fBkgIndicesMap["QCD"]]->Integral();
      Double_t gjetint = fInBkgTH1FHists[th1f][fBkgIndicesMap["GJets"]]->Integral();
      fGJetsClone[th1f] = (TH1F*)fInBkgTH1FHists[th1f][fBkgIndicesMap["GJets"]]->Clone();
      fGJetsClone[th1f]->Scale(qcdint/gjetint);
    }  

    //------------------------------------------------------------------------
    // Merge backgrounds
    //------------------------------------------------------------------------
    if (Config::mergeBkgs){

      //------------------------------------------------------------------------
      // merge higgs bkg
      //------------------------------------------------------------------------
      fOutHiggsBkgHists[th1f] = (TH1F*)fInBkgTH1FHists[th1f][fBkgIndicesMap["ttHJetToGG"]]->Clone();
      fOutHiggsBkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["GluGluHToGG"]]);
      fOutHiggsBkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["VBFHToGG"]]);

      //------------------------------------------------------------------------
      // merge DY bkg 
      //------------------------------------------------------------------------
      fOutDYBkgHists[th1f] = (TH1F*)fInBkgTH1FHists[th1f][fBkgIndicesMap["DYJetsToLL"]]->Clone();

      //------------------------------------------------------------------------
      // merge EWK+1pho bkg 
      //------------------------------------------------------------------------
      fOutEWK1BkgHists[th1f] = (TH1F*)fInBkgTH1FHists[th1f][fBkgIndicesMap["TGJets"]]->Clone();
      fOutEWK1BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["TTGJets"]]);
      fOutEWK1BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["TTJets"]]);
      fOutEWK1BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["WGToLNuG"]]);
      fOutEWK1BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["ZGTo2LG"]]);
      fOutEWK1BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["ZGTo2NuG"]]);
      fOutEWK1BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["WJetsToLNu"]]);

      //------------------------------------------------------------------------
      // merge EWK+2pho bkg 
      //------------------------------------------------------------------------
      fOutEWK2BkgHists[th1f] = (TH1F*)fInBkgTH1FHists[th1f][fBkgIndicesMap["TTGG_0Jets"]]->Clone();
      fOutEWK2BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["ZZTo2L2Nu"]]);
      fOutEWK2BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["ZZTo2L2Q"]]);
      fOutEWK2BkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["WZTo2L2Q"]]);

      //------------------------------------------------------------------------
      // merge QCD and Gjets 
      //------------------------------------------------------------------------
      fOutJetsBkgHists[th1f] = (TH1F*)fInBkgTH1FHists[th1f][fBkgIndicesMap["GJets"]]->Clone();
      if (Config::doQCDrewgt) fOutJetsBkgHists[th1f]->Add(fGJetsClone[th1f]);
      else fOutJetsBkgHists[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["QCD"]]);
    }

    //------------------------------------------------------------------------
    // Add bkgs to stack after scaling 
    //------------------------------------------------------------------------
    if (Config::mergeBkgs){ // add merged bkgs
      fOutMCTH1FStacks[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["VHToGG"]]);
      fOutMCTH1FStacks[th1f]->Add(fOutHiggsBkgHists[th1f]);
      fOutMCTH1FStacks[th1f]->Add(fOutDYBkgHists[th1f]);
      fOutMCTH1FStacks[th1f]->Add(fOutEWK2BkgHists[th1f]);
      fOutMCTH1FStacks[th1f]->Add(fOutEWK1BkgHists[th1f]);
      fOutMCTH1FStacks[th1f]->Add(fOutJetsBkgHists[th1f]);
      fOutMCTH1FStacks[th1f]->Add(fInBkgTH1FHists[th1f][fBkgIndicesMap["DiPhoton"]]);
    }
    else { // if not merging, just add all bkgs
      for (Int_t mc = 0; mc < fNBkg; mc++){
        if (fBkgNames[mc]=="QCD"){
          if (Config::doQCDrewgt) fOutMCTH1FStacks[th1f]->Add(fGJetsClone[th1f]);
          else fOutMCTH1FStacks[th1f]->Add(fInBkgTH1FHists[th1f][mc]);
        } 
        else fOutMCTH1FStacks[th1f]->Add(fInBkgTH1FHists[th1f][mc]);
      }
    }

  }// end th1f loop

}

void StackPlots::InitRatioPlots()
{

  //------------------------------------------------------------------------
  // Initialize ratio plots 
  //------------------------------------------------------------------------
  fOutRatioTH1FHists.resize(fNTH1F); // th1f hists
  fOutRatioMCErrs.resize(fNTH1F);    // mc err hists 
}

void StackPlots::InitRatioLines()
{

  //------------------------------------------------------------------------
  // Initialize lines for ratio plots 
  //------------------------------------------------------------------------
  fOutTH1FRatioLines.resize(fNTH1F);
  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){
    fOutTH1FRatioLines[th1f] = new TLine();
  }
}

void StackPlots::InitOutputCanvPads()
{

  //------------------------------------------------------------------------
  // Initialize canvas and pads 
  //------------------------------------------------------------------------
  fOutTH1FCanvases.resize(fNTH1F);
  fOutTH1FStackPads.resize(fNTH1F);
  fOutTH1FRatioPads.resize(fNTH1F);
  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){
    fOutTH1FCanvases[th1f] = new TCanvas(Form("%s_canv",fTH1FNames[th1f].Data()),"",550,550);
    fOutTH1FCanvases[th1f]->cd();
    
    fOutTH1FStackPads[th1f] = new TPad(Form("%s_upad",fTH1FNames[th1f].Data()),"",0.0,0.3,1.0,1.0);
    fOutTH1FStackPads[th1f]->SetBottomMargin(0); // Upper and lower plot are joined
    
    fOutTH1FRatioPads[th1f] = new TPad(Form("%s_lpad",fTH1FNames[th1f].Data()),"",0.0,0.0,1.0,0.3);
    fOutTH1FRatioPads[th1f]->SetTopMargin(0);
    fOutTH1FRatioPads[th1f]->SetBottomMargin(0.3);
  }
}



void StackPlots::InitOutputLegends()
{

  //------------------------------------------------------------------------
  // Initialize legends 
  //------------------------------------------------------------------------
  fTH1FLegends.resize(fNTH1F);
  fSigLegends.resize(fNTH1F);

  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){
    fTH1FLegends[th1f] = new TLegend(0.56,0.69,0.92,0.92,NULL,"brNDC"); // x1,y1,x2,y2
    fTH1FLegends[th1f]->SetTextSize(0.036);
    fTH1FLegends[th1f]->SetNColumns(2);
    fTH1FLegends[th1f]->SetBorderSize(0);
    fTH1FLegends[th1f]->SetLineColor(1);
    fTH1FLegends[th1f]->SetLineStyle(1);
    fTH1FLegends[th1f]->SetLineWidth(1);
    fTH1FLegends[th1f]->SetFillColor(0);
    fTH1FLegends[th1f]->SetFillStyle(0);
    fTH1FLegends[th1f]->SetTextFont(42);

    fSigLegends[th1f] = new TLegend(0.56,0.55,0.74,0.68); // (x1,y1,x2,y2)
    fSigLegends[th1f]->SetHeader("m_{A} = 300 GeV with #sigma = 1pb");
    fSigLegends[th1f]->SetTextSize(0.036);
    fSigLegends[th1f]->SetNColumns(1);
    fSigLegends[th1f]->SetBorderSize(0);
    fSigLegends[th1f]->SetLineColor(1);
    fSigLegends[th1f]->SetLineStyle(1);
    fSigLegends[th1f]->SetLineWidth(1);
    fSigLegends[th1f]->SetFillColor(0);
    fSigLegends[th1f]->SetFillStyle(0);
    fSigLegends[th1f]->SetTextFont(42);
  }
}

void StackPlots::InitOutputPlots()
{

  //------------------------------------------------------------------------
  // Init output th1f hists 
  //------------------------------------------------------------------------
  fOutDataTH1FHists.resize(fNTH1F); // make enough space for data double hists
  fOutBkgTH1FHists.resize(fNTH1F);  // make enough space for bkg double hists
  fOutSigTH1FHists.resize(fNTH1F);  // make enough space for sig double hists
  fOutMCTH1FStacks.resize(fNTH1F);  // same with stack
  fOutMCUncStacks.resize(fNTH1F);   // same with stack for uncer.

  if (Config::doQCDrewgt) fGJetsClone.resize(fNTH1F);

  if (Config::mergeBkgs){
    fOutDYBkgHists.resize(fNTH1F);
    fOutEWK1BkgHists.resize(fNTH1F);
    fOutEWK2BkgHists.resize(fNTH1F);
    fOutJetsBkgHists.resize(fNTH1F);
    fOutHiggsBkgHists.resize(fNTH1F);
  }
 
  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){
    fOutMCTH1FStacks[th1f] = new THStack(Form("%s_stack",fTH1FNames[th1f].Data()),"");
    fOutMCUncStacks[th1f]  = new THStack(Form("%s_uncer",fTH1FNames[th1f].Data()),"");
  }
}

void StackPlots::InitInputPlots()
{

  //------------------------------------------------------------------------
  // Init input th1f hists 
  //------------------------------------------------------------------------
  fInDataTH1FHists.resize(fNTH1F);
  fInBkgTH1FHists.resize(fNTH1F);
  fInSigTH1FHists.resize(fNTH1F);
  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){ // loop over double hists
    //------------------------------------------------------------------------
    // Init data hists 
    //------------------------------------------------------------------------
    fInDataTH1FHists[th1f].resize(fNData); 
    for (Int_t data = 0; data < fNData; data++) { // init data double hists
	fInDataTH1FHists[th1f][data] = (TH1F*)fDataFiles[data]->Get(Form("%s",fTH1FNames[th1f].Data()));	
	CheckValidTH1F(fInDataTH1FHists[th1f][data],fTH1FNames[th1f],fDataFiles[data]->GetName());
    }

    //------------------------------------------------------------------------
    // Init bkg hists 
    //------------------------------------------------------------------------
    fInBkgTH1FHists[th1f].resize(fNBkg); 
    for (Int_t mc = 0; mc < fNBkg; mc++) { // init mc double hists
      fInBkgTH1FHists[th1f][mc] = (TH1F*)fBkgFiles[mc]->Get(Form("%s",fTH1FNames[th1f].Data()));
      CheckValidTH1F(fInBkgTH1FHists[th1f][mc],fTH1FNames[th1f],fBkgFiles[mc]->GetName());
      fInBkgTH1FHists[th1f][mc]->SetFillColor(Config::colorMap[fBkgNames[mc]]);
    }

    //------------------------------------------------------------------------
    // Init sig hists 
    //------------------------------------------------------------------------
    fInSigTH1FHists[th1f].resize(fNSig); 
    for (Int_t mc = 0; mc < fNSig; mc++) { // init mc double hists
      fInSigTH1FHists[th1f][mc] = (TH1F*)fSigFiles[mc]->Get(Form("%s",fTH1FNames[th1f].Data()));
      CheckValidTH1F(fInSigTH1FHists[th1f][mc],fTH1FNames[th1f],fSigFiles[mc]->GetName());
      fInSigTH1FHists[th1f][mc]->SetFillColor(Config::colorMap[fSigNames[mc]]);
    }
  }
}

void StackPlots::InitTH1FNamesAndSubDNames()
{

  //------------------------------------------------------------------------
  // Choose the histograms to run 
  //------------------------------------------------------------------------
  std::ifstream plots_to_run;
  plots_to_run.open(Form("%s/%s",Config::outdir.Data(),Config::plotnames.Data()),std::ios::in);

  TString plotname;
  TString subdir;

  while (plots_to_run >> plotname >> subdir) {
    fTH1FNames.push_back(plotname);
    fTH1FSubDMap[plotname] = subdir;
  }
  plots_to_run.close();

  // store the size of the number of plots
  fNTH1F = fTH1FNames.size();

  if (fTH1FNames.size() == 0) {
    std::cerr << "Somehow, no plots were read in for the stacker ...exiting..." << std::endl;
    exit(1);
  }
}

void StackPlots::OpenInputFiles()
{

  //------------------------------------------------------------------------
  // Get input files 
  //------------------------------------------------------------------------
  fDataFiles.resize(fNData);
  for (Int_t data = 0; data < fNData; data++) {
    TString datafile = Form("%s/%s/plots_%s.root",Config::outdir.Data(),fDataNames[data].Data(),fDataNames[data].Data());
    fDataFiles[data] = TFile::Open(datafile.Data());
    CheckValidFile(fDataFiles[data],datafile);
  }
  fBkgFiles.resize(fNBkg);
  for (Int_t mc = 0; mc < fNBkg; mc++) {
    TString mcfile = Form("%s/%s/plots_%s.root",Config::outdir.Data(),fBkgNames[mc].Data(),fBkgNames[mc].Data());
    fBkgFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fBkgFiles[mc],mcfile);
  }
  fSigFiles.resize(fNSig);
  for (Int_t mc = 0; mc < fNSig; mc++) {
    TString mcfile = Form("%s/%s/plots_%s.root",Config::outdir.Data(),fSigNames[mc].Data(),fSigNames[mc].Data());
    fSigFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fSigFiles[mc],mcfile);
  }
}


StackPlots::~StackPlots()
{

  //------------------------------------------------------------------------
  // Finish by deleting everything
  //------------------------------------------------------------------------
  for (Int_t th1f = 0; th1f < fNTH1F; th1f++){
    delete fOutDataTH1FHists[th1f];
    delete fOutBkgTH1FHists[th1f];
    delete fOutSigTH1FHists[th1f];
    delete fOutMCTH1FStacks[th1f];
    delete fOutMCUncStacks[th1f];
 
    delete fTH1FLegends[th1f];
    delete fSigLegends[th1f]; 

    if (Config::doQCDrewgt) delete fGJetsClone[th1f];
 
    if (Config::mergeBkgs){
      delete fOutDYBkgHists[th1f];
      delete fOutEWK1BkgHists[th1f];
      delete fOutEWK2BkgHists[th1f];
      delete fOutJetsBkgHists[th1f];
      delete fOutHiggsBkgHists[th1f];
    }

    for (Int_t data = 0; data < fNData; data++) { delete fInDataTH1FHists[th1f][data]; } 
    for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fInBkgTH1FHists[th1f][mc]; } 
    for (Int_t mc = 0; mc < fNSig; mc++)        { delete fInSigTH1FHists[th1f][mc]; } 
  }

  for (Int_t data = 0; data < fNData; data++) { delete fDataFiles[data]; }
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgFiles[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigFiles[mc]; }

  delete fOutFile;
}


