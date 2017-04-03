#ifndef _optimize_
#define _optimize_

#include "CommonTypes.hh"
#include "Common.hh"
#include "Config.hh"

#include "TCanvas.h"
#include "TPad.h"

typedef std::vector<TFile*>	TFileVec;
typedef std::vector<TTree*>	TTreeVec;
typedef std::vector<TCanvas*>	TCanvVec;

class Optimization{
public:
  Optimization(const TString inName);
  void OpenInputFiles();
  void OpenTTrees();
  void SetBranchAddresses();
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

};

#endif

