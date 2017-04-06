#ifndef _optimize_
#define _optimize_

#include "CommonTypes.hh"
#include "Common.hh"
#include "Config.hh"

#include "TCanvas.h"
#include "TPad.h"
#include "TChain.h"

typedef std::vector<TFile*>	TFileVec;
typedef std::vector<TTree*>	TTreeVec;
typedef std::vector<TCanvas*>	TCanvVec;

class Optimization{
public:
  Optimization(const TString inName);
  void OpenInputFiles();
  void OpenTTrees();
  void SetBranchAddresses(Int_t mc);
  void RunOptimization();

  ~Optimization();

private:
  TString	name;
  TString	fOutDir;
  TStrMap	fTH1FSubDMap;
  TFile*	fOutFile;
  TStrVec	fTH1FNames;
  UInt_t	fNTH1F;

  TFileVec	fBkgFiles;
  TFileVec	fSigFiles;
  TStrVec	fBkgNames;
  TStrVec	fSigNames;
  Int_t		fNBkg;
  Int_t		fNSig;
  TTreeVec	fBkgTrees;
  TTreeVec	fSigTrees; 
  TChain* 	bkgtree;

  //------------------------------------------------------------------------
  // Declaration of leaf types
  //------------------------------------------------------------------------
  Float_t         weight;
  Float_t         ptgg;
  Float_t         mgg;
  Float_t         pt1;
  Float_t         eta1;
  Float_t         phi1;
  Float_t         pt2;
  Float_t         eta2;
  Float_t         phi2;
  Float_t         t1pfmetCorr;
  Float_t         t1pfmetCorrPhi;
  Int_t           sampleID;
  Int_t           genmatch1;
  Int_t           genmatch2;
  Int_t           metF_GV;
  Int_t           metF_EcalDeadCell;
  Int_t           metF_HBHENoise;
  Int_t           metF_HBHENoiseIso;
  Int_t           metF_CSC;
  Int_t           metF_eeBadSC;
  Int_t           metF_HadronTrackRes;
  Int_t           metF_MuonBadTrack;
  Int_t           metF_badMuon;
  Int_t           metF_badChargedHadron;
  Int_t           nEle;
  Int_t           nMuons;
  Int_t           nJets;
  Int_t           metF_globalTightHalo;
  Float_t         ptJetLead;
  Float_t         etaJetLead;
  Float_t         phiJetLead;
  Float_t         massJetLead;
  Float_t         ptJetSubLead;
  Float_t         etaJetSubLead;
  Float_t         phiJetSubLead;
  Float_t         massJetSubLead;
  Float_t         ptJet3;
  Float_t         etaJet3;
  Float_t         phiJet3;
  Float_t         massJet3;
  Float_t         ptJet4;
  Float_t         etaJet4;
  Float_t         phiJet4;
  Float_t         massJet4;

  Float_t         sig_weight;
  Float_t         sig_ptgg;
  Float_t         sig_mgg;
  Float_t         sig_pt1;
  Float_t         sig_eta1;
  Float_t         sig_phi1;
  Float_t         sig_pt2;
  Float_t         sig_eta2;
  Float_t         sig_phi2;
  Float_t         sig_t1pfmetCorr;
  Float_t         sig_t1pfmetCorrPhi;
  Int_t           sig_genmatch1;
  Int_t           sig_genmatch2;
  Int_t           sig_metF_GV;
  Int_t           sig_metF_EcalDeadCell;
  Int_t           sig_metF_HBHENoise;
  Int_t           sig_metF_HBHENoiseIso;
  Int_t           sig_metF_CSC;
  Int_t           sig_metF_eeBadSC;
  Int_t           sig_metF_HadronTrackRes;
  Int_t           sig_metF_MuonBadTrack;
  Int_t           sig_metF_badMuon;
  Int_t           sig_metF_badChargedHadron;
  Int_t           sig_nEle;
  Int_t           sig_nMuons;
  Int_t           sig_nJets;
  Int_t           sig_metF_globalTightHalo;
  Float_t         sig_ptJetLead;
  Float_t         sig_etaJetLead;
  Float_t         sig_phiJetLead;
  Float_t         sig_massJetLead;
  Float_t         sig_ptJetSubLead;
  Float_t         sig_etaJetSubLead;
  Float_t         sig_phiJetSubLead;
  Float_t         sig_massJetSubLead;
  Float_t         sig_ptJet3;
  Float_t         sig_etaJet3;
  Float_t         sig_phiJet3;
  Float_t         sig_massJet3;
  Float_t         sig_ptJet4;
  Float_t         sig_etaJet4;
  Float_t         sig_phiJet4;
  Float_t         sig_massJet4;
};

#endif

