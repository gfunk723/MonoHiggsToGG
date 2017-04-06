#include "../interface/Optimization.hh"

Optimization::Optimization(TString inName)
{
  //------------------------------------------------------------------------
  // Setup variables from inputs
  //------------------------------------------------------------------------
  name = inName;

  //------------------------------------------------------------------------
  // Setup samples
  //------------------------------------------------------------------------
  for (TStrBoolMapIter iter = Config::SampleMap.begin(); iter != Config::SampleMap.end(); ++iter) {
    if (!(*iter).second && !((*iter).first).Contains("mZP",TString::kExact)) { // Bkg
      fBkgNames.push_back((*iter).first);
    }
  }
  fNBkg  = fBkgNames.size();
  std::cout << " BkgSize = " << fNBkg << std::endl;

  //------------------------------------------------------------------------
  // Setup signal samples
  //------------------------------------------------------------------------
  fSigNames.push_back("2HDM_mZP600_mA0300");
  fNSig  = fSigNames.size();

  //------------------------------------------------------------------------
  // Setup output
  //------------------------------------------------------------------------
  fOutDir = Form("%s/optimize",Config::outdir.Data()); // where to put output stack plots 
  MakeOutDir(fOutDir); // make output directory 
  fOutFile = new TFile(Form("%s/optplots_canv.root",fOutDir.Data()),"RECREATE"); // ouput tfile to store canvases here for quick editting

  //------------------------------------------------------------------------
  // Initialize objects
  //------------------------------------------------------------------------
  MakeSubDirs(fTH1FSubDMap,fOutDir);       // setup output subdir
  Optimization::OpenInputFiles();          // open the input files
  Optimization::OpenTTrees();              // open the input ttrees

}


void Optimization::RunOptimization()
{

  //------------------------------------------------------------------------
  // Merge all backgrounds 
  //------------------------------------------------------------------------
  //TList *list = new TList;
  //for (Int_t mc = 0; mc < fNBkg; mc++){ list->Add(fBkgTrees[mc]); }
  //bkgtree = TTree::MergeTrees(list);
  bkgtree = new TChain("tree");
  for (Int_t mc = 0; mc < fNBkg; mc++){ 
    TString mcfile = Form("%s%s.root",name.Data(),fBkgNames[mc].Data());
    bkgtree->Add(mcfile); 
  }
 
  //------------------------------------------------------------------------
  // optimization for each signal
  //------------------------------------------------------------------------
  for (Int_t mc = 0; mc < fNSig; mc++){ 
    Optimization::SetBranchAddresses(mc);     // setup branches for trees
    Optimization::ApplyCuts(false);           // bkg, apply standard + optimizing cuts
    Optimization::ApplyCuts(true);            // sig, apply standard + optimizing cuts
  }

}

void Optimization::ApplyCuts(bool sig)
{
  Int_t    phosamp; // QCD or GJets
  Float_t  wgt; 
  Int_t    metF1, metF2, metF3, metF4, metF5, metF6, metF7;
  Int_t    prompt1, prompt2;
  Float_t  pt1, pt2, phi1, phi2, eta1, eta2;
  Float_t  met, metphi;
  Int_t    nJet, nMu, nEl;
  Float_t  ptJet1, phiJet1, etaJet1, mJet1;
  Float_t  ptJet2, phiJet2, etaJet2, mJet2;
  Float_t  ptJet3, phiJet3, etaJet3, mJet3;
  Float_t  ptJet4, phiJet4, etaJet4, mJet4;

  for (UInt_t entry = 0; entry < bkgtree->GetEntries(); entry++){
    bkgtree->GetEntry(entry);
 
    if (sig){
      wgt	= sig_weight;
      metF1	= sig_metF_GV;
      metF2	= sig_metF_globalTightHalo;
      metF3	= sig_metF_HBHENoise;
      metF4	= sig_metF_HBHENoiseIso;
      metF5     = sig_metF_EcalDeadCell;
      metF6	= sig_metF_badMuon;
      metF7	= sig_metF_badChargedHadron;
      prompt1	= sig_genmatch1;
      prompt2	= sig_genmatch2;
      phosamp	= 0;
      pt1	= sig_pt1;
      pt2	= sig_pt2;
      phi1	= sig_phi1;
      phi2	= sig_phi2;
      eta1	= sig_eta1;
      eta2	= sig_eta2;
      met	= sig_t1pfmetCorr;
      metphi	= sig_t1pfmetCorrPhi;
      nJet	= sig_nJets;
      nMu	= sig_nMuon;
      nEl	= sig_nElec;
      ptJet1	= sig_ptJetLead;
      phiJet1	= sig_phiJetLead;
      etaJet1	= sig_etaJetLead;
      mJet1	= sig_massJetLead;
      ptJet2	= sig_ptJetSubLead;
      phiJet2	= sig_phiJetSubLead;
      etaJet2	= sig_etaJetSubLead;
      mJet2	= sig_massJetSubLead;
      ptJet3	= sig_ptJet3;
      phiJet3	= sig_phiJet3;
      etaJet3	= sig_etaJet3;
      mJet3	= sig_massJet3;
      ptJet4	= sig_ptJet4;
      phiJet4	= sig_phiJet4;
      etaJet4	= sig_etaJet4;
      mJet4	= sig_massJet4;
    } 

    else{
      wgt	= weight;
      metF1	= metF_GV;
      metF2	= metF_globalTightHalo;
      metF3	= metF_HBHENoise;
      metF4	= metF_HBHENoiseIso;
      metF5     = metF_EcalDeadCell;
      metF6	= metF_badMuon;
      metF7	= metF_badChargedHadron;
      prompt1	= genmatch1;
      prompt2	= genmatch2;
      phosamp	= (sampleID==15 || (sampleID >= 18 && sampleID <= 22))1:0;
      pt1	= pt1;
      pt2	= pt2;
      phi1	= phi1;
      phi2	= phi2;
      eta1	= eta1;
      eta2	= eta2;
      met	= t1pfmetCorr;
      metphi	= t1pfmetCorrPhi;
      nJet	= nJets;
      nMu	= nMuon;
      nEl	= nElec;
      ptJet1	= ptJetLead;
      phiJet1	= phiJetLead;
      etaJet1	= etaJetLead;
      mJet1	= massJetLead;
      ptJet2	= ptJetSubLead;
      phiJet2	= phiJetSubLead;
      etaJet2	= etaJetSubLead;
      mJet2	= massJetSubLead;
      ptJet3	= ptJet3;
      phiJet3	= phiJet3;
      etaJet3	= etaJet3;
      mJet3	= massJet3;
      ptJet4	= ptJet4;
      phiJet4	= phiJet4;
      etaJet4	= etaJet4;
      mJet4	= massJet4;
   }

   bool pass_metF   = (metF1 && metF2 && metF3 && metF4 && metF5 && metF6 && metF7);
   bool pass_prompt = (phosamp)?(prompt1 && prompt2):true;
 
   if (!pass_metF)   continue;
   if (!pass_prompt) continue;
   if (nJet > 2)     continue;
   if (nMu  > 0)     continue;
   if (nEl  > 0)     continue; 

  }// end loop over entries 

}

void Optimization::OpenInputFiles()
{

  //------------------------------------------------------------------------
  // Get input files 
  //------------------------------------------------------------------------
  fBkgFiles.resize(fNBkg);
  for (Int_t mc = 0; mc < fNBkg; mc++) {
    TString mcfile = Form("%s%s.root",name.Data(),fBkgNames[mc].Data());
    fBkgFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fBkgFiles[mc],mcfile);
  }
  fSigFiles.resize(fNSig);
  for (Int_t mc = 0; mc < fNSig; mc++) {
    TString mcfile = Form("%s%s.root",name.Data(),fSigNames[mc].Data());
    fSigFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fSigFiles[mc],mcfile);
  }
}

void Optimization::OpenTTrees()
{

  //------------------------------------------------------------------------
  // Get input trees 
  //------------------------------------------------------------------------
  fBkgTrees.resize(fNBkg);
  for (Int_t mc = 0; mc < fNBkg; mc++){
    fBkgTrees[mc] = (TTree*)fBkgFiles[mc]->Get("DiPhotonTree");
    CheckValidTree(fBkgTrees[mc],"DiPhotonTree",Form("%s%s.root",name.Data(),fBkgNames[mc].Data()));
  }
  fSigTrees.resize(fNSig);
  for (Int_t mc = 0; mc < fNSig; mc++){
    fSigTrees[mc] = (TTree*)fSigFiles[mc]->Get("DiPhotonTree");
    CheckValidTree(fSigTrees[mc],"DiPhotonTree",Form("%s%s.root",name.Data(),fSigNames[mc].Data()));
  }
}

void Optimization::SetBranchAddresses( Int_t mc )
{

  //------------------------------------------------------------------------
  // Set branch addresses and branch pointers  
  //------------------------------------------------------------------------
  bkgtree->SetBranchAddress("sampleID",&sampleID);
  bkgtree->SetBranchAddress("metF_GV",&metF_GV);
  bkgtree->SetBranchAddress("metF_globalTightHalo",&metF_globalTightHalo);
  bkgtree->SetBranchAddress("metF_HBHENoise",&metF_HBHENoise);
  bkgtree->SetBranchAddress("metF_HBHENoiseIso",&metF_HBHENoiseIso);
  bkgtree->SetBranchAddress("metF_EcalDeadCell",&metF_EcalDeadCell);
  bkgtree->SetBranchAddress("metF_eeBadSC",&metF_eeBadSC);
  bkgtree->SetBranchAddress("metF_badMuon",&metF_badMuon);
  bkgtree->SetBranchAddress("metF_badChargedHadron",&metF_badChargedHadron); 
  bkgtree->SetBranchAddress("genmatch1",&genmatch1);
  bkgtree->SetBranchAddress("genmatch2",&genmatch2);
  bkgtree->SetBranchAddress("weight",&weight);
  bkgtree->SetBranchAddress("mgg",&mgg);
  bkgtree->SetBranchAddress("ptgg",&ptgg);
  bkgtree->SetBranchAddress("pt1",&pt1);
  bkgtree->SetBranchAddress("pt2",&pt2);
  bkgtree->SetBranchAddress("eta1",&eta1);
  bkgtree->SetBranchAddress("eta2",&eta2);
  bkgtree->SetBranchAddress("phi1",&phi1);
  bkgtree->SetBranchAddress("phi2",&phi2);
  bkgtree->SetBranchAddress("t1pfmetCorr",&t1pfmetCorr);
  bkgtree->SetBranchAddress("t1pfmetCorrPhi",&t1pfmetCorrPhi);
  bkgtree->SetBranchAddress("nEle",&nEle);
  bkgtree->SetBranchAddress("nMuons",&nMuons);
  bkgtree->SetBranchAddress("nJets",&nJets);
  bkgtree->SetBranchAddress("ptJetLead",&ptJetLead);
  bkgtree->SetBranchAddress("etaJetLead",&etaJetLead);
  bkgtree->SetBranchAddress("phiJetLead",&phiJetLead);
  bkgtree->SetBranchAddress("massJetLead",&massJetLead);
  bkgtree->SetBranchAddress("ptJetSubLead",&ptJetSubLead);
  bkgtree->SetBranchAddress("etaJetSubLead",&etaJetSubLead);
  bkgtree->SetBranchAddress("phiJetSubLead",&phiJetSubLead);
  bkgtree->SetBranchAddress("massJetSubLead",&massJetSubLead);
  bkgtree->SetBranchAddress("ptJet3",&ptJet3);
  bkgtree->SetBranchAddress("etaJet3",&etaJet3);
  bkgtree->SetBranchAddress("phiJet3",&phiJet3);
  bkgtree->SetBranchAddress("massJet3",&massJet3);
  bkgtree->SetBranchAddress("ptJet4",&ptJet4);
  bkgtree->SetBranchAddress("etaJet4",&etaJet4);
  bkgtree->SetBranchAddress("phiJet4",&phiJet4);
  bkgtree->SetBranchAddress("massJet4",&massJet4);

  fSigTrees[mc]->SetBranchAddress("metF_GV",&sig_metF_GV);
  fSigTrees[mc]->SetBranchAddress("metF_globalTightHalo",&sig_metF_globalTightHalo);
  fSigTrees[mc]->SetBranchAddress("metF_HBHENoise",&sig_metF_HBHENoise);
  fSigTrees[mc]->SetBranchAddress("metF_HBHENoiseIso",&sig_metF_HBHENoiseIso);
  fSigTrees[mc]->SetBranchAddress("metF_EcalDeadCell",&sig_metF_EcalDeadCell);
  fSigTrees[mc]->SetBranchAddress("metF_eeBadSC",&sig_metF_eeBadSC);
  fSigTrees[mc]->SetBranchAddress("metF_badMuon",&sig_metF_badMuon);
  fSigTrees[mc]->SetBranchAddress("metF_badChargedHadron",&sig_metF_badChargedHadron); 
  fSigTrees[mc]->SetBranchAddress("genmatch1",&sig_genmatch1);
  fSigTrees[mc]->SetBranchAddress("genmatch2",&sig_genmatch2);
  fSigTrees[mc]->SetBranchAddress("weight",&sig_weight);
  fSigTrees[mc]->SetBranchAddress("mgg",&sig_mgg);
  fSigTrees[mc]->SetBranchAddress("ptgg",&sig_ptgg);
  fSigTrees[mc]->SetBranchAddress("pt1",&sig_pt1);
  fSigTrees[mc]->SetBranchAddress("pt2",&sig_pt2);
  fSigTrees[mc]->SetBranchAddress("eta1",&sig_eta1);
  fSigTrees[mc]->SetBranchAddress("eta2",&sig_eta2);
  fSigTrees[mc]->SetBranchAddress("phi1",&sig_phi1);
  fSigTrees[mc]->SetBranchAddress("phi2",&sig_phi2);
  fSigTrees[mc]->SetBranchAddress("t1pfmetCorr",&sig_t1pfmetCorr);
  fSigTrees[mc]->SetBranchAddress("t1pfmetCorrPhi",&sig_t1pfmetCorrPhi);
  fSigTrees[mc]->SetBranchAddress("nEle",&sig_nEle);
  fSigTrees[mc]->SetBranchAddress("nMuons",&sig_nMuons);
  fSigTrees[mc]->SetBranchAddress("nJets",&sig_nJets);
  fSigTrees[mc]->SetBranchAddress("ptJetLead",&sig_ptJetLead);
  fSigTrees[mc]->SetBranchAddress("etaJetLead",&sig_etaJetLead);
  fSigTrees[mc]->SetBranchAddress("phiJetLead",&sig_phiJetLead);
  fSigTrees[mc]->SetBranchAddress("massJetLead",&sig_massJetLead);
  fSigTrees[mc]->SetBranchAddress("ptJetSubLead",&sig_ptJetSubLead);
  fSigTrees[mc]->SetBranchAddress("etaJetSubLead",&sig_etaJetSubLead);
  fSigTrees[mc]->SetBranchAddress("phiJetSubLead",&sig_phiJetSubLead);
  fSigTrees[mc]->SetBranchAddress("massJetSubLead",&sig_massJetSubLead);
  fSigTrees[mc]->SetBranchAddress("ptJet3",&sig_ptJet3);
  fSigTrees[mc]->SetBranchAddress("etaJet3",&sig_etaJet3);
  fSigTrees[mc]->SetBranchAddress("phiJet3",&sig_phiJet3);
  fSigTrees[mc]->SetBranchAddress("massJet3",&sig_massJet3);
  fSigTrees[mc]->SetBranchAddress("ptJet4",&sig_ptJet4);
  fSigTrees[mc]->SetBranchAddress("etaJet4",&sig_etaJet4);
  fSigTrees[mc]->SetBranchAddress("phiJet4",&sig_phiJet4);
  fSigTrees[mc]->SetBranchAddress("massJet4",&sig_massJet4);

}

Optimization::~Optimization()
{

  //------------------------------------------------------------------------
  // Finish by deleting everything
  //------------------------------------------------------------------------
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgTrees[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigTrees[mc]; }
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgFiles[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigFiles[mc]; }

  delete fOutFile;
}
