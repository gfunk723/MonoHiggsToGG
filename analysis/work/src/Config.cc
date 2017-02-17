#include "../interface/Config.hh"

namespace Config{

  //------------------------------------------------------------------------
  // Default Config parameters
  //------------------------------------------------------------------------
  TString outdir      = "diPhoPlots";
  Bool_t  doBlind     = true;
  Bool_t  doAnalysis  = false;
  Bool_t  doStack     = false;
  Bool_t  doComb      = false;
  Bool_t  makeCards   = false;
  TString plotnames   = "plotnames.txt";
  Bool_t  mergeBkgs   = true;
  Bool_t  doQCDrewgt  = true;
  Bool_t  scaleToData = false;
  TString yieldsPlot  = "mgg";
  Int_t   whichSel    = 0;
  Bool_t  doEffPlots  = false;
  Bool_t  doStandard  = false;
  Bool_t  doNminus1   = false;
  Bool_t  useData     = false;
  Bool_t  doMETcor    = false;
  TString outtype     = "png";

  TStrBoolMap SampleMap;      // set in main.cc
  ColorMap    colorMap;       // set in main.cc
  TStrMap     nameMap;        // set in main.cc
  TStrMap     SampleLatexMap; // set in main.cc

}
