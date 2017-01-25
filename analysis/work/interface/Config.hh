#ifndef _config_
#define _config_

#include "CommonTypes.hh"

namespace Config{
 
  //------------------------------------------------------------------------
  // General configuration
  //------------------------------------------------------------------------

  constexpr    Float_t lumi = 34.7; // fb^-1
  static const TString extraText = "Preliminary";

  //------------------------------------------------------------------------
  // TDRStyle Config --> needed by stacker
  //------------------------------------------------------------------------
  constexpr    Float_t  TitleSize    = 0.035;
  constexpr    Float_t  TitleXOffset = 1.1;
  constexpr    Float_t  TitleYOffset = 1.1;

  constexpr    Float_t  LabelOffset = 0.007;
  constexpr    Float_t  LabelSize   = 0.03;

  constexpr    Float_t  TickLength  = 0.03;

  constexpr    Float_t  TitleFF     = 1.4; // offset fudge factor   

  //------------------------------------------------------------------------
  // METcorr configuration
  //------------------------------------------------------------------------

  

  //------------------------------------------------------------------------
  // Objects set at command line and in main 
  //------------------------------------------------------------------------

  extern TString      outdir;
  extern Bool_t       useData;
  extern Bool_t       useAll;
  extern Bool_t       doMETcor;
  extern TString      outtype;

  extern TStrBoolMap  SampleMap;
  extern ColorMap     colorMap;
  extern TStrMap      SampleTitleMap;
  extern TStrMap      SampleLatexMap;
 
};

#endif

