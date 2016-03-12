#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1.h>
#include <TLorentzVector.h>
#include <iostream>


using namespace std;

void doEff( TString inDir, TString outDir, Double_t lumi){

  cout << " Computing Efficiency for Samples in " << inDir << endl;

  vector< TString > sigNames;
  sigNames.push_back("2HDM_mZP600");
  sigNames.push_back("2HDM_mZP800");
  sigNames.push_back("2HDM_mZP1000");
  sigNames.push_back("2HDM_mZP1200");
  sigNames.push_back("2HDM_mZP1400");
  sigNames.push_back("2HDM_mZP1700");
  sigNames.push_back("2HDM_mZP2500");
  UInt_t nSig = sigNames.size();

  vector< TFile *> inFile;
  inFile.resize(nSig);
  for (UInt_t mc=0; mc<nSig; mc++){
   inFile[mc] = TFile::Open(inDir+sigNames[mc]+".root");
   if ( inFile[mc] ) inFile[mc]->cd();
   else{
     cout << "File " << inDir << sigNames[mc] << ".root does not exist!" << endl;
     return;
   }

   cout << " Working on " << sigNames[mc] << endl; 

   TH1D * fSel_unwgt = (TH1D*)inFile[mc]->Get("h_selection_unwgt");
   TTree * tpho = (TTree*)inFile[mc]->Get("DiPhotonTree");

   // variables from tree
   Float_t	mgg;
   Float_t	ptgg;
   Float_t	pt1; 
   Float_t	pt2; 
   Float_t	phi1;
   Float_t	phi2;
   Float_t	eta1;
   Float_t	eta2;
   Float_t	t1pfmet;
   Float_t	t1pfmetPhi;
   Float_t	t1pfmetSumEt;
   Int_t	nJets;
   Int_t	nMuons;
   Int_t	nEle;
   Float_t	ptJetLead;
   Float_t	etaJetLead;
   Float_t	phiJetLead;
   Float_t	massJetLead;
   Float_t	ptJetSubLead;
   Float_t	etaJetSubLead;
   Float_t	phiJetSubLead;
   Float_t	massJetSubLead;
   Float_t	ptJet3;
   Float_t	etaJet3;
   Float_t	phiJet3;
   Float_t	massJet3;
   Float_t	ptJet4;
   Float_t	etaJet4;
   Float_t	phiJet4;
   Float_t	massJet4;
 
   // branches from tree
   TBranch	*b_mgg;
   TBranch	*b_ptgg;
   TBranch	*b_pt1;
   TBranch	*b_pt2;
   TBranch	*b_phi1;
   TBranch	*b_phi2;
   TBranch	*b_eta1;
   TBranch	*b_eta2;
   TBranch	*b_t1pfmet;
   TBranch	*b_t1pfmetPhi;
   TBranch	*b_t1pfmetSumEt;
   TBranch	*b_nJets;
   TBranch	*b_nMuons;
   TBranch	*b_nEle;
   TBranch	*b_ptJetLead;   //!
   TBranch	*b_etaJetLead;   //!
   TBranch	*b_phiJetLead;   //!
   TBranch	*b_massJetLead;   //!
   TBranch	*b_ptJetSubLead;   //!
   TBranch	*b_etaJetSubLead;   //!
   TBranch	*b_phiJetSubLead;   //!
   TBranch	*b_massJetSubLead;   //!
   TBranch	*b_ptJet3;   //!
   TBranch	*b_etaJet3;   //!
   TBranch	*b_phiJet3;   //!
   TBranch	*b_massJet3;   //!
   TBranch	*b_ptJet4;   //!
   TBranch	*b_etaJet4;   //!
   TBranch	*b_phiJet4;   //!
   TBranch	*b_massJet4;   //!

   // set branch addresses from tree
   tpho->SetBranchAddress("mgg", &mgg, &b_mgg);
   tpho->SetBranchAddress("ptgg", &ptgg, &b_ptgg);
   tpho->SetBranchAddress("pt1", &pt1, &b_pt1);   
   tpho->SetBranchAddress("pt2", &pt2, &b_pt2);   
   tpho->SetBranchAddress("eta1", &eta1, &b_eta1);   
   tpho->SetBranchAddress("eta2", &eta2, &b_eta2);   
   tpho->SetBranchAddress("phi1", &phi1, &b_phi1);   
   tpho->SetBranchAddress("phi2", &phi2, &b_phi2);   
   tpho->SetBranchAddress("t1pfmet", &t1pfmet, &b_t1pfmet);   
   tpho->SetBranchAddress("t1pfmetPhi", &t1pfmetPhi, &b_t1pfmetPhi);
   tpho->SetBranchAddress("t1pfmetSumEt", &t1pfmetSumEt, &b_t1pfmetSumEt);   
   tpho->SetBranchAddress("nEle", &nEle, &b_nEle);
   tpho->SetBranchAddress("nMuons", &nMuons, &b_nMuons);
   tpho->SetBranchAddress("nJets", &nJets, &b_nJets);
   tpho->SetBranchAddress("ptJetLead", &ptJetLead, &b_ptJetLead);
   tpho->SetBranchAddress("etaJetLead", &etaJetLead, &b_etaJetLead);
   tpho->SetBranchAddress("phiJetLead", &phiJetLead, &b_phiJetLead);
   tpho->SetBranchAddress("massJetLead", &massJetLead, &b_massJetLead);
   tpho->SetBranchAddress("ptJetSubLead", &ptJetSubLead, &b_ptJetSubLead);
   tpho->SetBranchAddress("etaJetSubLead", &etaJetSubLead, &b_etaJetSubLead);
   tpho->SetBranchAddress("phiJetSubLead", &phiJetSubLead, &b_phiJetSubLead);
   tpho->SetBranchAddress("massJetSubLead", &massJetSubLead, &b_massJetSubLead);
   tpho->SetBranchAddress("ptJet3", &ptJet3, &b_ptJet3);
   tpho->SetBranchAddress("etaJet3", &etaJet3, &b_etaJet3);
   tpho->SetBranchAddress("phiJet3", &phiJet3, &b_phiJet3);
   tpho->SetBranchAddress("massJet3", &massJet3, &b_massJet3);
   tpho->SetBranchAddress("ptJet4", &ptJet4, &b_ptJet4);
   tpho->SetBranchAddress("etaJet4", &etaJet4, &b_etaJet4);
   tpho->SetBranchAddress("phiJet4", &phiJet4, &b_phiJet4);
   tpho->SetBranchAddress("massJet4", &massJet4, &b_massJet4);

   // Make TLorentzVector for objects
   TLorentzVector *fLorenzVecg1		= new TLorentzVector();
   TLorentzVector *fLorenzVecg2		= new TLorentzVector();
   TLorentzVector *fLorenzVecgg		= new TLorentzVector();
   TLorentzVector *fLorenzVecJet1	= new TLorentzVector();
   TLorentzVector *fLorenzVecJet2	= new TLorentzVector();
   TLorentzVector *fLorenzVecJet3	= new TLorentzVector();
   TLorentzVector *fLorenzVecJet4	= new TLorentzVector();

   UInt_t nentries = tpho->GetEntries();
   for (UInt_t entry = 0; entry < nentries; entry++){
     tpho->GetEntry(entry);

   }// end loop over tree entries  



  }// end loop over sig files
 
}//end doEff
