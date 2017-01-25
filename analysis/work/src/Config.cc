#include "../interface/Config.hh"

namespace Config{

  //------------------------------------------------------------------------
  // Default Config parameters
  //------------------------------------------------------------------------
  TString outdir      = "output";
  Bool_t  useData     = false;
  Bool_t  useAll      = false;
  Bool_t  doMETcor    = false;
  TString outtype     = "png";

  TStrBoolMap SampleMap;      // set in main.cc
  ColorMap    colorMap;       // set in main.cc
  TStrMap     SampleTitleMap; // set in main.cc
  TStrMap     SampleLatexMap; // set in main.cc

}
