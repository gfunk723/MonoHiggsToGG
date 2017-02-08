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
  StackPlots::InitOutputPlots();           // initialize output histos
 
}

void StackPlots::DoStack()
{

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
    for (Int_t data = 0; data < fNData; data++) { delete fInDataTH1FHists[th1f][data]; } 
    for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fInBkgTH1FHists[th1f][mc]; } 
    for (Int_t mc = 0; mc < fNSig; mc++)        { delete fInSigTH1FHists[th1f][mc]; } 
  }

  for (Int_t data = 0; data < fNData; data++) { delete fDataFiles[data]; }
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgFiles[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigFiles[mc]; }

  delete fOutFile;

}


