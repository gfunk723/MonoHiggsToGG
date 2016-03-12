#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1.h>
#include <TLorentzVector.h>
#include "../../../DataFormats/Math/interface/deltaPhi.h"
#include <TMath.h>
#include <iostream>


using namespace std;

void doEff( TString inDir, TString outDir, Double_t lumi, vector<Double_t> fMETCorr ){

  cout << " Computing Efficiency for Samples in " << inDir << endl;

  vector< TString > sigNames;
  sigNames.push_back("2HDM_mZP600");
  sigNames.push_back("2HDM_mZP800");
  sigNames.push_back("2HDM_mZP1000");
  sigNames.push_back("2HDM_mZP1200");
  sigNames.push_back("2HDM_mZP1400");
  sigNames.push_back("2HDM_mZP1700");
  sigNames.push_back("2HDM_mZP2500");
  UInt_t fNSig = sigNames.size();

  vector< TFile *> inFile;
  inFile.resize(fNSig);

  vector< Int_t > original;
  original.resize(fNSig);

  for (UInt_t mc=0; mc<fNSig; mc++){
   inFile[mc] = TFile::Open(inDir+sigNames[mc]+".root");
   if ( inFile[mc] ) inFile[mc]->cd();
   else{
     cout << "File " << inDir << sigNames[mc] << ".root does not exist!" << endl;
     return;
   }

   cout << " Working on " << sigNames[mc] << endl; 

   TH1D * fSel_unwgt = (TH1D*)inFile[mc]->Get("h_selection_unwgt");
   original[mc] = fSel_unwgt->GetBinContent(1);
   //cout << "orig = " << original[mc] << endl;

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
   TLorentzVector fLorenzVecg1;
   TLorentzVector fLorenzVecg2;
   TLorentzVector fLorenzVecgg;
   TLorentzVector fLorenzVecCorrMET; 
   TLorentzVector fLorenzVecJet1;
   TLorentzVector fLorenzVecJet2;
   TLorentzVector fLorenzVecJet3;
   TLorentzVector fLorenzVecJet4;

   // counters for efficiency
   vector< Int_t > count1a;
   vector< Int_t > count1b;
   vector< Int_t > count1c;
   vector< Int_t > count1d;
   vector< Int_t > count2a;
   vector< Int_t > count2b;
   vector< Int_t > count2c;
   vector< Int_t > count2d;
   count1a.resize(fNSig);
   count1b.resize(fNSig);
   count1c.resize(fNSig);
   count1d.resize(fNSig);
   count2a.resize(fNSig);
   count2b.resize(fNSig);
   count2c.resize(fNSig);
   count2d.resize(fNSig);


   // START loop over entries in tree
   UInt_t nentries = tpho->GetEntries();
   for (UInt_t entry = 0; entry < nentries; entry++){
     tpho->GetEntry(entry);

     fLorenzVecg1.SetPtEtaPhiM(pt1,eta1,phi1,0.);
     fLorenzVecg2.SetPtEtaPhiM(pt2,eta2,phi2,0.);
     fLorenzVecgg = fLorenzVecg1 + fLorenzVecg2;
     fLorenzVecJet1.SetPtEtaPhiM(ptJetLead,etaJetLead,phiJetLead,massJetLead);
     fLorenzVecJet2.SetPtEtaPhiM(ptJetSubLead,etaJetSubLead,phiJetSubLead,massJetSubLead);
     fLorenzVecJet3.SetPtEtaPhiM(ptJet3,etaJet3,phiJet3,massJet3);
     fLorenzVecJet4.SetPtEtaPhiM(ptJet4,etaJet4,phiJet4,massJet4);

     // t1pfmet phi Correction
     Double_t t1pfmetCorrX = t1pfmet*cos(t1pfmetPhi) - (fMETCorr[0] + fMETCorr[1]*t1pfmetSumEt);
     Double_t t1pfmetCorrY = t1pfmet*sin(t1pfmetPhi) - (fMETCorr[2] + fMETCorr[3]*t1pfmetSumEt);
     Double_t t1pfmetCorrE = sqrt(t1pfmetCorrX*t1pfmetCorrX + t1pfmetCorrY*t1pfmetCorrY);
     //std::cout << "px = t1pfmet*cos(t1pfmetPhi) - (" << fMETCorr[0] << " + " << fMETCorr[1] << "*t1pfmetSumEt)" << std::endl;
     //std::cout << "py = t1pfmet*sin(t1pfmetPhi) - (" << fMETCorr[2] << " + " << fMETCorr[3] << "*t1pfmetSumEt)" << std::endl;
     fLorenzVecCorrMET.SetPxPyPzE(t1pfmetCorrX,t1pfmetCorrY,0,t1pfmetCorrE);
     Double_t t1pfmetPhiCorr = fLorenzVecCorrMET.Phi(); 
     Double_t t1pfmetCorr = fLorenzVecCorrMET.Pt();

     
     // DeltaPhi between each Jet and the MET
     // set these values to true for events w/o jets
     Bool_t max_dphiJETMETpass = true;	// max dphi Jet-MET < 2.7 
     Bool_t min_dphiJETMETpass = true;	// min dphi Jet-MET > 0.5 
     
     Double_t max_dphi_JetMET = 0.;
     Double_t min_dphi_JetMET = 10.;
     
     if ( nJets > 0 ){
       Double_t dphiJet1METmin = 10;
       Double_t dphiJet2METmin = 10;
       Double_t dphiJet3METmin = 10;
       Double_t dphiJet4METmin = 10;
       Double_t dphiJet1METmax = 0;
       Double_t dphiJet2METmax = 0;
       Double_t dphiJet3METmax = 0;
       Double_t dphiJet4METmax = 0;
       if ( ptJetLead > 50 ){
         dphiJet1METmin = TMath::Abs(deltaPhi(fLorenzVecJet1.Phi(),t1pfmetPhiCorr));
         dphiJet1METmax = TMath::Abs(deltaPhi(fLorenzVecJet1.Phi(),t1pfmetPhiCorr));
       }
       if ( ptJetSubLead > 50 ){
         dphiJet2METmin = TMath::Abs(deltaPhi(fLorenzVecJet2.Phi(),t1pfmetPhiCorr));
         dphiJet2METmax = TMath::Abs(deltaPhi(fLorenzVecJet2.Phi(),t1pfmetPhiCorr));
       }
       if ( ptJet3 > 50 ){
         dphiJet3METmin = TMath::Abs(deltaPhi(fLorenzVecJet3.Phi(),t1pfmetPhiCorr));
         dphiJet3METmax = TMath::Abs(deltaPhi(fLorenzVecJet3.Phi(),t1pfmetPhiCorr));
       }
       if ( ptJet4 > 50 ){
         dphiJet4METmin = TMath::Abs(deltaPhi(fLorenzVecJet4.Phi(),t1pfmetPhiCorr));
         dphiJet4METmax = TMath::Abs(deltaPhi(fLorenzVecJet4.Phi(),t1pfmetPhiCorr));
       }
     
       // find the min_dphi_JetMET 
       if (dphiJet1METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet1METmin;	   
       if (dphiJet2METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet2METmin;	   
       if (dphiJet3METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet3METmin;	   
       if (dphiJet4METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet4METmin;	   
       // find the max_dphi_JetMET 
       if (dphiJet1METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet1METmax;	   
       if (dphiJet2METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet2METmax;	   
       if (dphiJet3METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet3METmax;	   
       if (dphiJet4METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet4METmax;	   
     }
     
     if (max_dphi_JetMET > 2.7) max_dphiJETMETpass = false;// max dphi Jet-MET < 2.7 
     if (min_dphi_JetMET < 0.5) min_dphiJETMETpass = false;// min dphi Jet-MET > 0.5 
     
     // DeltaPhi between gg and MET
     Double_t dphiggMET = TMath::Abs(deltaPhi(fLorenzVecgg.Phi(),t1pfmetPhiCorr));
     Bool_t dphiggMETpass = false; // dphi gg-MET > 2.1
     if ( dphiggMET > 2.1 ) dphiggMETpass = true;


     // START applying cuts
     if ( !dphiggMETpass || !max_dphiJETMETpass || !min_dphiJETMETpass) continue;

     // for selection option 1 
     if ( pt1 > 0.5*mgg && pt2 > 0.25*mgg && t1pfmetCorr > 105){
       count1a[mc]++;
       if ( nEle < 2){
         count1b[mc]++;
         if ( nMuons == 0){
           count1c[mc]++;
           if ( ptgg > 90) count1d[mc]++;
         }
       }
     }  

     // for selection option 2 
     if ( pt1 > 0.65*mgg && pt2 > 0.25*mgg && t1pfmetCorr > 80){
       count2a[mc]++;
       if ( nEle < 2){
         count2b[mc]++;
         if ( nMuons == 0){
           count2c[mc]++;
           if ( ptgg > 50) count2d[mc]++;
         }
       }
     }  

   }// end loop over tree entries  

   //cout << count1a[mc] << " " << count1b[mc] << " " << count1c[mc] << " " << count1d[mc] << endl;
   //cout << count2a[mc] << " " << count2b[mc] << " " << count2c[mc] << " " << count2d[mc] << endl;

  }// end loop over sig files



 
}//end doEff
