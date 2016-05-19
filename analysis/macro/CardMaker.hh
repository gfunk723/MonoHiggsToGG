#ifndef _comparertools_
#define _comparertools_

#include "Style.hh"

#include "TFile.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TString.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TROOT.h"
#include "TMath.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TDirectory.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TLatex.h"
#include "THStack.h"
#include "TLine.h"
#include "TChain.h"

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooWorkspace.h"
#include "RooPlot.h"
#include "RooFormula.h"
#include "RooGaussian.h"

#include <iostream>
#include <cmath>

using namespace RooFit;

typedef std::vector<TFile*>   TFileVec;
typedef std::vector<TH1D*>    TH1DVec;
typedef std::vector<TH1DVec>  TH1DVecVec;
typedef std::vector<THStack*> THStackVec;
typedef std::vector<TPad*>    TPadVec;
typedef std::vector<TLegend*> TLegVec;
typedef std::vector<TCanvas*> TCanvVec;
typedef std::vector<TLine*>   TLineVec;
typedef std::vector<Double_t> DblVec;
typedef std::vector<TTree*>   TTreeVec;
typedef std::vector<TTreeVec>		TTreeVecVec;
typedef std::vector<TTreeVecVec>	TTreeVecVecVec;

typedef std::vector<RooDataSet*> 	RooDataSetVec;
typedef std::vector<RooRealVar*> 	RooRealVarVec;
typedef std::vector<RooDataSetVec>	RooDataSetVecVec;
typedef std::vector<RooDataSetVecVec>	RooDataSetVecVecVec;



class CardMaker{
public:
  CardMaker(const SamplePairVec Samples, const ColorMap colorMap, const Double_t inLumi, const DblVec puweights, const TString inname, const TString outname, const Bool_t Blind, const TString type);
  void MakeCards();
  void GetInFilesAndMakeTChain();
  void SetTChainBranchAddresses(); 
  void ApplyCommonSelection(const TString sampleName);


  void DoComparison();

  void AddRooWorkspace(RooWorkspace* w, const TString sampleName);
  RooArgSet * DefineVariables();
  ~CardMaker();

private:
  Double_t	lumi;
  TString	fType;
  Bool_t	doBlind;
  DblVec	fPUWeights;

  TStrMap	fSampleTitleMap;
  ColorMap	fColorMap;

  RooWorkspace* fRooWorkspace;
  RooArgSet*	fNtupleVars;
  RooDataSetVec	fSigSet;
  RooDataSetVec	fDataSet;
  RooDataSetVec	fBkgSet;
  RooRealVarVec	fInvMass;	

  RooDataSetVecVecVec	fSigSetInCat;
  TTreeVecVecVec	fSigChain;

  SamplePairVec	Samples;

  TString	mainCut;
  UInt_t	nMetCat;
  TStrVec	MetCat;
  UInt_t	nPhoCat;
  TStrVec	PhoCat;
  UInt_t 	nTotCat;

  TString	fInDir;
  TString	fOutDir;
  TString	fOutName;
  TFile *	fOutFile;

  TFileVec	fDataFiles;
  TFileVec	fBkgFiles;
  TFileVec	fResFiles;
  TFileVec	fSigFiles;

  TStrVec	fDataNames;
  TStrVec	fBkgNames;
  TStrVec	fResNames;
  TStrVec	fSigNames;
  UInt_t	fNData;
  UInt_t	fNSig;
  UInt_t	fNBkg;
  UInt_t	fNRes;

  TTreeVec	fDataTrees;
  TTreeVec	fBkgTrees;
  TTreeVec	fSigTrees;
  TChain * 	fAllChain;
  UInt_t	nentries;

  TStrVec	fTH1DNames;
  UInt_t	fNTH1D;



  // Variables for the Trees:
  // Declaration of leaf types
  Float_t         xsecWeight;
  Float_t         weight;
  Float_t         mggNominal;
  Float_t         mggGen;
  Int_t           run;
  Int_t           event;
  Int_t           nvtx;
  Float_t         rho;
  Int_t           sampleID;
  Float_t         totXsec;
  Float_t         pu_weight;
  Float_t         pu_n;
  Float_t         sumDataset;
  Float_t         perEveW;
  Float_t         pfmet;
  Float_t         pfmetPhi;
  Float_t         pfmetSumEt;
  Float_t         t1pfmet;
  Float_t         t1pfmetPhi;
  Float_t         t1pfmetSumEt;
  Float_t         calomet;
  Float_t         calometPhi;
  Float_t         calometSumEt;
  Float_t         ptgg;
  Float_t         mgg;
  Int_t           eventClass;
  Float_t         pt1;
  Float_t         ptOverM1;
  Float_t         eta1;
  Float_t         phi1;
  Float_t         sceta1;
  Float_t         r91;
  Float_t         sieie1;
  Float_t         hoe1;
  Float_t         scRawEne1;
  Float_t         chiso1;
  Float_t         phoiso1;
  Float_t         neuiso1;
  Float_t         pt2;
  Float_t         ptOverM2;
  Float_t         eta2;
  Float_t         phi2;
  Float_t         sceta2;
  Float_t         r92;
  Float_t         sieie2;
  Float_t         hoe2;
  Float_t         scRawEne2;
  Float_t         chiso2;
  Float_t         phoiso2;
  Float_t         neuiso2;
  Int_t           eleveto1;
  Int_t           eleveto2;
  Int_t           presel1;
  Int_t           presel2;
  Int_t           sel1;
  Int_t           sel2;
  Int_t           tightsel1;
  Int_t           tightsel2;
  Int_t           genmatch1;
  Int_t           genmatch2;
  Float_t         geniso1;
  Float_t         geniso2;
  Int_t           vtxIndex;
  Float_t         vtxX;
  Float_t         vtxY;
  Float_t         vtxZ;
  Float_t         genVtxX;
  Float_t         genVtxY;
  Float_t         genVtxZ;
  Int_t           passCHiso1;
  Int_t           passCHiso2;
  Int_t           passNHiso1;
  Int_t           passNHiso2;
  Int_t           passPHiso1;
  Int_t           passPHiso2;
  Int_t           passSieie1;
  Int_t           passSieie2;
  Int_t           passHoe1;
  Int_t           passHoe2;
  Int_t           passTightCHiso1;
  Int_t           passTightCHiso2;
  Int_t           passTightNHiso1;
  Int_t           passTightNHiso2;
  Int_t           passTightPHiso1;
  Int_t           passTightPHiso2;
  Int_t           passTightSieie1;
  Int_t           passTightSieie2;
  Int_t           passTightHoe1;
  Int_t           passTightHoe2;
  Int_t           hltPhoton26Photon16Mass60;
  Int_t           hltPhoton36Photon22Mass15;
  Int_t           hltPhoton42Photon25Mass15;
  Int_t           hltDiphoton30Mass95;
  Int_t           hltDiphoton30Mass70;
  Int_t           hltDiphoton30Mass55;
  Int_t           hltDiphoton30Mass55PV;
  Int_t           hltDiphoton30Mass55EB;

  // List of branches
  TBranch        *b_xsecWeight;   //!
  TBranch        *b_weight;   //!
  TBranch        *b_mggNominal;   //!
  TBranch        *b_mggGen;   //!
  TBranch        *b_run;   //!
  TBranch        *b_event;   //!
  TBranch        *b_nvtx;   //!
  TBranch        *b_rho;   //!
  TBranch        *b_sampleID;   //!
  TBranch        *b_totXsec;   //!
  TBranch        *b_pu_weight;   //!
  TBranch        *b_pu_n;   //!
  TBranch        *b_sumDataset;   //!
  TBranch        *b_perEveW;   //!
  TBranch        *b_pfmet;   //!
  TBranch        *b_pfmetPhi;   //!
  TBranch        *b_pfmetSumEt;   //!
  TBranch        *b_t1pfmet;   //!
  TBranch        *b_t1pfmetPhi;   //!
  TBranch        *b_t1pfmetSumEt;   //!
  TBranch        *b_calomet;   //!
  TBranch        *b_calometPhi;   //!
  TBranch        *b_calometSumEt;   //!
  TBranch        *b_ptgg;   //!
  TBranch        *b_mgg;   //!
  TBranch        *b_eventClass;   //!
  TBranch        *b_pt1;   //!
  TBranch        *b_ptOverM1;   //!
  TBranch        *b_eta1;   //!
  TBranch        *b_phi1;   //!
  TBranch        *b_sceta1;   //!
  TBranch        *b_r91;   //!
  TBranch        *b_sieie1;   //!
  TBranch        *b_hoe1;   //!
  TBranch        *b_scRawEne1;   //!
  TBranch        *b_chiso1;   //!
  TBranch        *b_phoiso1;   //!
  TBranch        *b_neuiso1;   //!
  TBranch        *b_pt2;   //!
  TBranch        *b_ptOverM2;   //!
  TBranch        *b_eta2;   //!
  TBranch        *b_phi2;   //!
  TBranch        *b_sceta2;   //!
  TBranch        *b_r92;   //!
  TBranch        *b_sieie2;   //!
  TBranch        *b_hoe2;   //!
  TBranch        *b_scRawEne2;   //!
  TBranch        *b_chiso2;   //!
  TBranch        *b_phoiso2;   //!
  TBranch        *b_neuiso2;   //!
  TBranch        *b_eleveto1;   //!
  TBranch        *b_eleveto2;   //!
  TBranch        *b_presel1;   //!
  TBranch        *b_presel2;   //!
  TBranch        *b_sel1;   //!
  TBranch        *b_sel2;   //!
  TBranch        *b_tightsel1;   //!
  TBranch        *b_tightsel2;   //!
  TBranch        *b_genmatch1;   //!
  TBranch        *b_genmatch2;   //!
  TBranch        *b_geniso1;   //!
  TBranch        *b_geniso2;   //!
  TBranch        *b_vtxIndex;   //!
  TBranch        *b_vtxX;   //!
  TBranch        *b_vtxY;   //!
  TBranch        *b_vtxZ;   //!
  TBranch        *b_genVtxX;   //!
  TBranch        *b_genVtxY;   //!
  TBranch        *b_genVtxZ;   //!
  TBranch        *b_passCHiso1;   //!
  TBranch        *b_passCHiso2;   //!
  TBranch        *b_passNHiso1;   //!
  TBranch        *b_passNHiso2;   //!
  TBranch        *b_passPHiso1;   //!
  TBranch        *b_passPHiso2;   //!
  TBranch        *b_passSieie1;   //!
  TBranch        *b_passSieie2;   //!
  TBranch        *b_passHoe1;   //!
  TBranch        *b_passHoe2;   //!
  TBranch        *b_passTightCHiso1;   //!
  TBranch        *b_passTightCHiso2;   //!
  TBranch        *b_passTightNHiso1;   //!
  TBranch        *b_passTightNHiso2;   //!
  TBranch        *b_passTightPHiso1;   //!
  TBranch        *b_passTightPHiso2;   //!
  TBranch        *b_passTightSieie1;   //!
  TBranch        *b_passTightSieie2;   //!
  TBranch        *b_passTightHoe1;   //!
  TBranch        *b_passTightHoe2;   //!
  TBranch        *b_hltPhoton26Photon16Mass60;   //!
  TBranch        *b_hltPhoton36Photon22Mass15;   //!
  TBranch        *b_hltPhoton42Photon25Mass15;   //!
  TBranch        *b_hltDiphoton30Mass95;   //!
  TBranch        *b_hltDiphoton30Mass70;   //!
  TBranch        *b_hltDiphoton30Mass55;   //!
  TBranch        *b_hltDiphoton30Mass55PV;   //!
  TBranch        *b_hltDiphoton30Mass55EB;   //!

};
#endif
