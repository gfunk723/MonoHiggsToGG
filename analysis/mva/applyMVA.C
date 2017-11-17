#include "TROOT.h"

void applyMVA(TString path, TString addname, Int_t opt, TString sample)
{

  // --- input file
  TString filepath = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/";
  //TFile* data = new TFile(TString::Format("%s2HDM_mZP600_mA0300_skim_woVetos.root",filepath.Data()));
  TString name = TString::Format("%s_skim_woVetos",sample.Data());

  TFile* data = new TFile(TString::Format("%s%s.root",filepath.Data(),name.Data()));
  TTree* tree = (TTree*)data->Get("DiPhotonTree");

  // --- output file
  std::cout << "Running option: " << opt << std::endl;
  TFile* fout = new TFile(TString::Format("%sOutputMVA_BDT_opt%d%s_%s.root",filepath.Data(),opt,addname.Data(),name.Data()),"RECREATE");
  TTree* tout = new TTree("DiPhotonTree","");

  // --- copy histograms
  TH1F * h_entries         = (TH1F*)data->Get("h_entries");
  TH1F * h_sumW            = (TH1F*)data->Get("h_sumW");
  TH1F * h_selection       = (TH1F*)data->Get("h_selection");
  TH1F * h_selection_unwgt = (TH1F*)data->Get("h_selection_unwgt");
  TH1F * h_numbers         = (TH1F*)data->Get("h_numbers");

  // --- get the Reader to handle application
  TMVA::Tools::Instance();
  TMVA::Reader *reader = new TMVA::Reader( "!:Color:!Silent" );

  // --- setup input variables (names must match weight file names & order)
  int nvar = 7;
  Float_t var[nvar-1];
  // BDT variables
  reader->AddVariable( "dphiggmet",   &var[0]);
  reader->AddVariable( "ptgg",        &var[1]);
  if (opt > 1) reader->AddVariable( "t1pfmetCorr", &var[2]);
  if (opt > 2) reader->AddVariable( "nJets30",     &var[3]);
  if (opt > 2) reader->AddVariable( "nEle",        &var[4]);
  if (opt > 2) reader->AddVariable( "nMuons",      &var[5]);
  if (opt > 3) reader->AddVariable( "mgg",         &var[6]);
  // DNN variables
  //reader->AddVariable("ptgg",&var[0]);
  //reader->AddVariable("t1pfmetCorr",&var[1]);
  //reader->AddVariable("dphiggmet",&var[2]);
  //reader->AddVariable("dphig1met",&var[3]);
  //reader->AddVariable("dphig2met",&var[4]);
  //reader->AddVariable("detag1g2",&var[5]);
  
  // --- define TMVA method used, pick up weights file
  //reader->BookMVA("DNN method","weights_DNN_BARY/TMVAClassification_DNN.weights.xml");
  TString MVAname = TString::Format("BDT_BARY_opt%d%s/weights/TMVAClassification_BDT.weights.xml",opt,addname.Data());
  reader->BookMVA("BDT method",MVAname);

  // --- pick input variables in test sample
  Float_t testVar0;
  Float_t testVar1;
  Float_t testVar2;
  Float_t testVar3;
  Int_t  itestVar0;
  Int_t  itestVar1;
  Int_t  itestVar2;

  // BDT variables 
  tree->SetBranchAddress( "dphiggmet",   &testVar0);
  tree->SetBranchAddress( "ptgg",        &testVar1);
  if (opt > 1) tree->SetBranchAddress( "t1pfmetCorr", &testVar2);
  if (opt > 2) tree->SetBranchAddress( "nJets30",     &itestVar0);
  if (opt > 2) tree->SetBranchAddress( "nEle",        &itestVar1);
  if (opt > 2) tree->SetBranchAddress( "nMuons",      &itestVar2);
  tree->SetBranchAddress( "mgg",         &testVar3);

  Float_t	mgg;
  Float_t 	eta1;
  Float_t 	eta2;
  Float_t	chiso1;
  Float_t	chiso2;
  Int_t 	lumi; 
  Int_t 	run;
  UInt_t	event;
  Float_t	weight;
  tree->SetBranchAddress( "eta1",	&eta1);
  tree->SetBranchAddress( "eta2",	&eta2);
  tree->SetBranchAddress( "chiso1",	&chiso1);
  tree->SetBranchAddress( "chiso2",	&chiso2);
  tree->SetBranchAddress( "lumi",	&lumi);
  tree->SetBranchAddress( "run",	&run);
  tree->SetBranchAddress( "event",	&event);
  tree->SetBranchAddress( "weight",	&weight);

  // DNN variables
  //tree->SetBranchAddress("ptgg",&testVar[0]);
  //tree->SetBranchAddress("t1pfmetCorr",&testVar[1]);
  //tree->SetBranchAddress("dphiggmet",&testVar[2]);
  //tree->SetBranchAddress("dphig1met",&testVar[3]);
  //tree->SetBranchAddress("dphig2met",&testVar[4]);
  //tree->SetBranchAddress("detag1g2",&testVar[5]);

  // --- add more variables to view later
  tout->Branch( "mgg",          &testVar3 );
  tout->Branch( "eta1",		&eta1);
  tout->Branch( "eta2",		&eta2);
  tout->Branch( "chiso1",	&chiso1);
  tout->Branch( "chiso2",	&chiso2);
  tout->Branch( "lumi",		&lumi);
  tout->Branch( "run",		&run);
  tout->Branch( "event",	&event);
  tout->Branch( "weight",	&weight);
  if (opt > 0) tout->Branch( "dphiggmet",   &testVar0);
  if (opt > 0) tout->Branch( "ptgg",        &testVar1);
  if (opt > 1) tout->Branch( "t1pfmetCorr", &testVar2);
  if (opt > 2) tout->Branch( "nJets30",     &itestVar0);
  if (opt > 2) tout->Branch( "nEle",        &itestVar1);
  if (opt > 2) tout->Branch( "nMuons",      &itestVar2);
 
  // --- add branch to store response 
  Float_t MVA_response = 0.;
  tout->Branch("MVA_response", &MVA_response);

  // --- Loop over all events in tree
  for (Long64_t event=0; event < tree->GetEntries(); event++){
    if (event%1000==0) std::cout << "...Processing event: " << event << std::endl;
   
    tree->GetEntry(event);

    var[0] = testVar0;
    var[1] = testVar1;
    if (opt > 1) var[2] = testVar2;
    if (opt > 2) var[3] = float(itestVar0);
    if (opt > 2) var[4] = float(itestVar1);
    if (opt > 2) var[5] = float(itestVar2);
    if (opt > 3) var[6] = testVar3;
    mgg = testVar3;

    //MVA_response = reader->EvaluateMVA("DNN method");
    MVA_response = reader->EvaluateMVA( "BDT method" );
    //std::cout << "MVA response: " << MVA_response << event << std::endl;
    //if (event%1000==0) std::cout << "MVA response: " << MVA_response << event << std::endl;
 
    tout->Fill();
 
  }

  // --- write out histos
  h_entries->Write();
  h_sumW->Write();
  h_selection->Write();
  h_selection_unwgt->Write();
  h_numbers->Write();  

  // --- save tree
  tout->Write();
}
