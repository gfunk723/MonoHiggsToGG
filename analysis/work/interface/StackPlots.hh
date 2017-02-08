#ifndef _stackplots_
#define _stackplots_

#include "CommonTypes.hh"
#include "Common.hh"
#include "Config.hh"

#include "TCanvas.h"
#include "TPad.h"
#include "THStack.h"
#include "TLegend.h"
#include "TLine.h"
#include "TLatex.h"

typedef std::vector<TFile*>	TFileVec;
typedef std::vector<TH1F*>	TH1FVec;
typedef std::vector<TH1FVec>	TH1FVecVec;
typedef std::vector<THStack*>	THStackVec;
typedef std::vector<TLegend*>	TLegVec;
typedef std::vector<TLine*>	TLineVec;
typedef std::vector<TCanvas*>	TCanvVec;
typedef std::vector<TPad*>	TPadVec;

class StackPlots{
public:
  StackPlots();
  void DoStack();
  void OpenInputFiles();
  void InitTH1FNamesAndSubDNames();
  void InitInputPlots();

  ~StackPlots();

private:
  TString	fOutDir;
  TStrMap	fTH1FSubDMap;
  TFile*	fOutFile;
  TStrVec	fTH1FNames;
  UInt_t	fNTH1F;
  TH1FVecVec	fInDataTH1FHists;
  TH1FVecVec 	fInBkgTH1FHists;
  TH1FVecVec 	fInSigTH1FHists;

  TStrVec	fDataNames;
  TStrVec	fBkgNames;
  TStrVec	fSigNames;
  Int_t		fNData;
  Int_t		fNBkg;
  Int_t		fNSig;

  TFileVec	fDataFiles;
  TFileVec	fBkgFiles;
  TFileVec	fSigFiles;

};

#endif 
