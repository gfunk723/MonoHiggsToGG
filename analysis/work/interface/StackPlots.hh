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

  ~StackPlots();


private:

  TStrVec	fDataNames;
  TStrVec	fBkgNames;
  TStrVec	fSigNames;

  Int_t		fNData;
  Int_t		fNBkg;
  Int_t		fNSig;

};

#endif 
