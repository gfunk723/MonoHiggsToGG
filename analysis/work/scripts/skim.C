#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TDirectory.h"
#include "TLorentzVector.h"
#include <iostream>
#include "../../../../DataFormats/Math/interface/deltaPhi.h"

using namespace std;

void skim(TString path, TString sample){

  // ----------------------------------------------------------------
  // get input full trees
  // ----------------------------------------------------------------
  
  cout << "Running sample: " << sample << endl;
  TFile * infile = TFile::Open(Form("%s/%s.root",path.Data(),sample.Data()));
  TTree * intree = (TTree*)infile->Get("DiPhotonTree");
  const Bool_t isMC = !sample.Contains("DoubleEG",TString::kExact);
  const Bool_t doQCD_DupRem  = (sample.Contains("QCD",TString::kExact));
  const Bool_t doGJet_DupRem = (sample.Contains("GJets",TString::kExact));
  if (doGJet_DupRem || doQCD_DupRem) cout << "doing dup removal" << endl;
  TH1F * h_entries         = (TH1F*)infile->Get("h_entries");
  TH1F * h_sumW            = (TH1F*)infile->Get("h_sumW");
  TH1F * h_selection       = (TH1F*)infile->Get("h_selection");
  TH1F * h_selection_unwgt = (TH1F*)infile->Get("h_selection_unwgt");

  // ----------------------------------------------------------------
  // set branch addresses of input needed to apply cuts
  // ----------------------------------------------------------------

  // trigger
  Int_t   hltDiphoton30Mass95;	intree->SetBranchAddress("hltDiphoton30Mass95",&hltDiphoton30Mass95);
  // pho variables 
  Float_t mgg;			intree->SetBranchAddress("mgg",&mgg);
  Float_t ptgg;			intree->SetBranchAddress("ptgg",&ptgg);
  Float_t pt1;			intree->SetBranchAddress("pt1",&pt1);
  Float_t pt2;			intree->SetBranchAddress("pt2",&pt2);
  Float_t eta1;			intree->SetBranchAddress("eta1",&eta1);
  Float_t eta2;			intree->SetBranchAddress("eta2",&eta2);
  Float_t phi1;			intree->SetBranchAddress("phi1",&phi1);
  Float_t phi2;			intree->SetBranchAddress("phi2",&phi2);

  // met variables
  Float_t t1pfmet; 		intree->SetBranchAddress("t1pfmet",&t1pfmet);
  Float_t t1pfmetPhi;		intree->SetBranchAddress("t1pfmetPhi",&t1pfmetPhi);
  Float_t t1pfmetCorr;		intree->SetBranchAddress("t1pfmetCorr",&t1pfmetCorr);
  Float_t t1pfmetCorrPhi;	intree->SetBranchAddress("t1pfmetCorrPhi",&t1pfmetCorrPhi);

  // met filters
  Int_t metF_GV;		intree->SetBranchAddress("metF_GV",&metF_GV);
  Int_t metF_globalTightHalo;	intree->SetBranchAddress("metF_globalTightHalo",&metF_globalTightHalo);
  Int_t metF_HBHENoise;		intree->SetBranchAddress("metF_HBHENoise",&metF_HBHENoise);
  Int_t metF_HBHENoiseIso;	intree->SetBranchAddress("metF_HBHENoiseIso",&metF_HBHENoiseIso);
  Int_t metF_EcalDeadCell;	intree->SetBranchAddress("metF_EcalDeadCell",&metF_EcalDeadCell);
  Int_t metF_eeBadSC;		intree->SetBranchAddress("metF_eeBadSC",&metF_eeBadSC);
  Int_t metF_badMuon;		intree->SetBranchAddress("metF_badMuon",&metF_badMuon);
  Int_t metF_badChargedHadron;  intree->SetBranchAddress("metF_badChargedHadron",&metF_badChargedHadron); 

  // QCD/GJet dup. removal
  Int_t   genmatch1;		intree->SetBranchAddress("genmatch1",&genmatch1);
  Int_t   genmatch2; 		intree->SetBranchAddress("genmatch2",&genmatch2);
  // leptons
  Int_t   nEle;			intree->SetBranchAddress("nEle",&nEle);
  Int_t   nEleMed;		intree->SetBranchAddress("nEleMed",&nEleMed);
  Int_t   nMuons;		intree->SetBranchAddress("nMuons",&nMuons);
  Int_t   nMuTight;		intree->SetBranchAddress("nMuTight",&nMuTight);
  // jet variables
  Int_t   nJets20;		intree->SetBranchAddress("nJets20",&nJets20);
  Int_t   nJets30;		intree->SetBranchAddress("nJets30",&nJets30);
  Int_t   nJets40;		intree->SetBranchAddress("nJets40",&nJets40);
  Int_t   nJets50;		intree->SetBranchAddress("nJets50",&nJets50);
  Float_t ptJetLead;		intree->SetBranchAddress("ptJetLead",&ptJetLead);
  Float_t etaJetLead;		intree->SetBranchAddress("etaJetLead",&etaJetLead);
  Float_t phiJetLead;		intree->SetBranchAddress("phiJetLead",&phiJetLead);
  Float_t massJetLead;		intree->SetBranchAddress("massJetLead",&massJetLead);
  Float_t ptJetSubLead;		intree->SetBranchAddress("ptJetSubLead",&ptJetSubLead);
  Float_t etaJetSubLead;	intree->SetBranchAddress("etaJetSubLead",&etaJetSubLead);
  Float_t phiJetSubLead;	intree->SetBranchAddress("phiJetSubLead",&phiJetSubLead);
  Float_t massJetSubLead;	intree->SetBranchAddress("massJetSubLead",&massJetSubLead);
  Float_t ptJet3;		intree->SetBranchAddress("ptJet3",&ptJet3);
  Float_t etaJet3;		intree->SetBranchAddress("etaJet3",&etaJet3);
  Float_t phiJet3;		intree->SetBranchAddress("phiJet3",&phiJet3);
  Float_t massJet3;		intree->SetBranchAddress("massJet3",&massJet3);
  Float_t ptJet4;		intree->SetBranchAddress("ptJet4",&ptJet4);
  Float_t etaJet4;		intree->SetBranchAddress("etaJet4",&etaJet4);
  Float_t phiJet4;		intree->SetBranchAddress("phiJet4",&phiJet4);
  Float_t massJet4;		intree->SetBranchAddress("massJet4",&massJet4);

  // ----------------------------------------------------------------
  // Make TLorentzVector for the pho1,pho2,dipho,jets,corr.MET
  // ----------------------------------------------------------------

  TLorentzVector fLorenzVecPho1;
  TLorentzVector fLorenzVecPho2;
  TLorentzVector fLorenzVecGG;
  TLorentzVector fLorenzVecJet1;
  TLorentzVector fLorenzVecJet2;
  TLorentzVector fLorenzVecJet3;
  TLorentzVector fLorenzVecJet4;
  TLorentzVector correctedMet;

  // ----------------------------------------------------------------
  // Pick up the MET phi correction 
  // ----------------------------------------------------------------

  std::vector< Double_t > fMETCorrMC;
  std::vector< Double_t > fMETCorrData;
  // pick up MC metCorr
  TString metStudyMC = Form("%s/metCorr_MC.root",path.Data());
  TFile *fmetCorrMC = TFile::Open(metStudyMC.Data());
  TH1D *MCmet = (TH1D*)fmetCorrMC->Get("metCorr");  
  // pick up Data metCorr
  TString metStudyData = Form("%s/metCorr_Data.root",path.Data());
  TFile *fmetCorrDATA = TFile::Open(metStudyData.Data());
  TH1D *DATAmet = (TH1D*)fmetCorrDATA->Get("metCorr");  
  for (UInt_t i=0; i<4; i++){
    fMETCorrMC.push_back(MCmet->GetBinContent(i+1));
    fMETCorrData.push_back(DATAmet->GetBinContent(i+1));
  }

  // ----------------------------------------------------------------
  // declare output skim files
  // ----------------------------------------------------------------

  TFile * outfile = new TFile(Form("%s/%s_skimmedtree.root",path.Data(),sample.Data()),"RECREATE");
  TTree * outtree = (TTree*)infile->Get("DiPhotonTree");
  // clone structure of input tree, but storing no events
  outtree = intree->CloneTree(0);
  
  // ----------------------------------------------------------------
  // Initialize any counters wanted
  // ----------------------------------------------------------------
  Int_t num_failing = 0;
  Int_t num_mufails = 0;

  // ----------------------------------------------------------------
  // loop over input tree
  // ----------------------------------------------------------------
  for (UInt_t entry = 0; entry < intree->GetEntries(); entry++)
  {

    intree->GetEntry(entry);
    //if (entry%10000 == 0) cout << " Working on event # " << entry << " / " << intree->GetEntries() << " entries" << endl;

    // ----------------------------------------------------------------
    // Fill TLorentzVector
    // ----------------------------------------------------------------

    fLorenzVecPho1.SetPtEtaPhiM(pt1,eta1,phi1,0.);
    fLorenzVecPho2.SetPtEtaPhiM(pt2,eta2,phi2,0.);
    fLorenzVecGG = fLorenzVecPho1 + fLorenzVecPho2;
    fLorenzVecJet1.SetPtEtaPhiM(ptJetLead,etaJetLead,phiJetLead,massJetLead);
    fLorenzVecJet2.SetPtEtaPhiM(ptJetSubLead,etaJetSubLead,phiJetSubLead,massJetSubLead);
    fLorenzVecJet3.SetPtEtaPhiM(ptJet3,etaJet3,phiJet3,massJet3);
    fLorenzVecJet4.SetPtEtaPhiM(ptJet4,etaJet4,phiJet4,massJet4);

    // ----------------------------------------------------------------
    // Apply the t1pfmet phi Correction (old method)
    // ----------------------------------------------------------------

    Float_t t1pfmetPhiCorr = 0;
    //-----> now just take the official corr from ntuple
    t1pfmetPhiCorr = t1pfmetCorrPhi; 

    //-----> old met phi corr recipe 
    //Double_t t1pfmetCorrX, t1pfmetCorrY, t1pfmetCorr;
    //if (!isMC){ 
    //  t1pfmetCorrX = t1pfmet*cos(t1pfmetPhi) - (fMETCorrData[0] + fMETCorrData[1]*t1pfmetSumEt);
    //  t1pfmetCorrY = t1pfmet*sin(t1pfmetPhi) - (fMETCorrData[2] + fMETCorrData[3]*t1pfmetSumEt);
    //}
    //else{
    //  t1pfmetCorrX = t1pfmet*cos(t1pfmetPhi) - (fMETCorrMC[0] + fMETCorrMC[1]*t1pfmetSumEt);
    //  t1pfmetCorrY = t1pfmet*sin(t1pfmetPhi) - (fMETCorrMC[2] + fMETCorrMC[3]*t1pfmetSumEt);
    //}
    //t1pfmetCorr = sqrt(t1pfmetCorrX*t1pfmetCorrX + t1pfmetCorrY*t1pfmetCorrY);
    //TLorentzVector correctedMet;
    //correctedMet.SetPxPyPzE(t1pfmetCorrX,t1pfmetCorrY,0,t1pfmetSumEt);
    //t1pfmetPhiCorr = correctedMet.Phi();

    // ----------------------------------------------------------------
    // look at deltaPhi(gg,MET)
    // ----------------------------------------------------------------
    Double_t dphi_ggMET = TMath::Abs(deltaPhi(fLorenzVecGG.Phi(),t1pfmetPhiCorr));

    // ----------------------------------------------------------------
    // look at deltaPhi(jet,MET)
    // ----------------------------------------------------------------
    Double_t min_dphi_JetMET = 10.;
    Double_t max_dphi_JetMET = 0.;

    if (nJets50 > 0){
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

    // ----------------------------------------------------------------
    // Apply the cuts 
    // ----------------------------------------------------------------

    const Bool_t triggered        = (isMC)?true:hltDiphoton30Mass95; // trigger for data only
    const Bool_t passMetFil_All   = (metF_GV && metF_globalTightHalo && metF_HBHENoise && metF_HBHENoiseIso 
                                    && metF_EcalDeadCell && metF_badMuon && metF_badChargedHadron);
    const Bool_t passMetFil_Data  = (isMC)?true:(metF_eeBadSC); // filter for data only
    const Bool_t passMETfilters   = (passMetFil_All && passMetFil_Data);

    const Bool_t passKinematics   = (pt1>0.5*mgg && pt2>0.25*mgg && ptgg>90 && mgg>=100 && mgg<=200);
    //const Bool_t passKinematics   = (pt1>0.33*mgg && pt2>0.25*mgg && ((mgg>=100 && mgg<=115) || (mgg >=135 && mgg<=200)));
    const Bool_t pass_GJet_DupRem = (!doGJet_DupRem || (doGJet_DupRem && (genmatch1!=1 || genmatch2!=1)));
    const Bool_t pass_QCD_DupRem  = (!doQCD_DupRem  || (doQCD_DupRem  && (genmatch1!=1 || genmatch2!=1)));
    const Bool_t passDupRemoval   = (pass_QCD_DupRem && pass_GJet_DupRem);
    //const Bool_t passLepVetos     = (nEleMed < 2 && nMuTight==0);
    const Bool_t passLepVetos     = (nEle==0 && nMuons==0);
    const Bool_t passJetVetos     = (nJets30 < 3);
    const Bool_t passDphiCuts     = (dphi_ggMET>=2.1 && min_dphi_JetMET>=0.5 /* && max_dphi_JetMET <= 2.7 */);

    if (nMuons!=0)       num_mufails++;
    if (!passMETfilters) num_failing++;

    // skim cut
    if (triggered && passMETfilters && passKinematics && passDupRemoval && passLepVetos && passDphiCuts && passJetVetos)
    {
      outtree->Fill(); // fill output tree
    }

  }// finish event loop

  cout << num_failing << " events fail met filters of " << intree->GetEntries() << " original events " << endl;
  cout << num_mufails << " events fail muon cut " << endl;


  // ----------------------------------------------------------------
  // write the output skim tree
  // ----------------------------------------------------------------

  outfile->cd();
  h_entries->Write();
  h_sumW->Write();
  h_selection->Write();
  h_selection_unwgt->Write();
  outtree->Write();

  // now delete (close) everything
  delete intree;
  delete infile;
  delete outtree;
  delete outfile;
}
