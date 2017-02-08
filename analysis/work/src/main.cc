//------------------------------------------------------------------------
// To clean:   make clean
// To compile: make
// To call:    ./main --help (gives config options)
//------------------------------------------------------------------------

#include "../interface/CommonTypes.hh"
#include "../interface/Common.hh"
#include "../interface/Config.hh"
#include "../interface/Analysis.hh"
#include "../interface/StackPlots.hh"
#include "../interface/METcorr.hh"

#include "TROOT.h"
#include <iostream>

void InitializeMain(std::ofstream &yields, TStyle *& tdrStyle)
{

  //------------------------------------------------------------------------
  // Set TDR style 
  //------------------------------------------------------------------------
  tdrStyle = new TStyle("tdrStyle","Style for P-TDR");
  SetTDRStyle(tdrStyle);
  gROOT->ForceStyle();

  //------------------------------------------------------------------------
  // Make output dir 
  //------------------------------------------------------------------------
  MakeOutDir(Config::outdir);

  //------------------------------------------------------------------------
  // Set sample map 
  //------------------------------------------------------------------------
  if (Config::useData) Config::SampleMap["DoubleEG"] = true;  // isData
  if (Config::doAnalysis || Config::doStack)
  {
    Config::SampleMap["DiPhoton"]		= false; // !isData 
    Config::SampleMap["QCD"]			= false; // !isData
    Config::SampleMap["2HDM_mZP600_mA0300"]	= false; // !isData 
  }

  //------------------------------------------------------------------------
  // Make a yields table to sort samples 
  //------------------------------------------------------------------------
  yields.open(Form("%s/yields.txt",Config::outdir.Data()),std::ios_base::app);

  //------------------------------------------------------------------------
  // Set color map 
  //------------------------------------------------------------------------
  Config::colorMap["DoubleEG"]		   = kBlack;
  Config::colorMap["DiPhoton"]		   = kTeal-1;
  Config::colorMap["SMHiggs"]		   = kOrange-2;
  Config::colorMap["EWK1pho"]		   = kAzure+8;
  Config::colorMap["EWK2pho"]		   = kAzure+2;
  Config::colorMap["Jetspho"]		   = kGreen-9;
  Config::colorMap["QCD"] 		   = kYellow+8;
  Config::colorMap["GJets"] 		   = kGreen-9;
  Config::colorMap["DYJetsToLL"]	   = kTeal-7;
  Config::colorMap["VHToGG"]		   = kOrange-3;
  Config::colorMap["GluGluHToGG"]	   = kOrange-2;
  Config::colorMap["ttHJetToGG"]	   = kOrange-4;
  Config::colorMap["VBFHToGG"]		   = kYellow-7;
  Config::colorMap["TGJets"]		   = kAzure+3;
  Config::colorMap["TTGJets"]		   = kAzure+2;
  Config::colorMap["TTGG_0Jets"]	   = kBlue-9;
  Config::colorMap["TTJets"]		   = kBlue-7;
  Config::colorMap["ZJets"]		   = kBlue;
  Config::colorMap["ZGTo2LG"]		   = kCyan;
  Config::colorMap["WZTo2L2Nu"]		   = kTeal;
  Config::colorMap["WJetsToLNu"]	   = kBlue+5;
  Config::colorMap["ZZTo2L2Nu"]		   = kTeal+1;
  Config::colorMap["ZZTo2L2Q"]		   = kTeal+5;
  Config::colorMap["WGToLNuG"]		   = kAzure+8;
  Config::colorMap["2HDM_mZP600_mA0300"]   = kPink-2;
  Config::colorMap["2HDM_mZP800_mA0300"]   = kMagenta+2;
  Config::colorMap["2HDM_mZP1000_mA0300"]  = kMagenta;

}// end initializing

void DestroyMain(std::ofstream & yields, TStyle *& tdrStyle) 
{
  yields.close();
  delete tdrStyle;
}


int main(int argc, const char* argv[])
{

  //------------------------------------------------------------------------
  // Read in command line options 
  //------------------------------------------------------------------------
  lStr_t mArgs; 
  for (int i = 1; i < argc; ++i) { mArgs.push_back(argv[i]); }
  lStr_i i  = mArgs.begin();
  while (i != mArgs.end()) 
  {
    lStr_i start = i;
    if (*i == "-h" || *i == "-help" || *i == "--help") 
    {
      printf(
        "Usage: %s [options]\n"
        "Options:\n"
	"  --outdir        <string>      name of ouput directory (def: %s)\n"
        "  --unblind       <bool>        unblind the data (def: %s)\n"
        "  --do-analysis   <bool>        run analysis cuts (def: %s)\n"
        "  --do-stack      <bool>        run stacking for plots (def: %s)\n"
        "  --plotnames     <string>      list of plots to stack (def: %s)\n"
        "  --which-sel     <int>         choose which selection to apply (def: %s)\n"
        "  --do-standard   <bool>        make standard plots (def: %s)\n"
        "  --do-nminus1    <bool>        make n minus 1 plots (def: %s)\n"
	"  --do-metcor     <bool>        calculate MET-phi corr (def: %s)\n"
        "  --use-Data      <bool>        use DoubleEG data (def: %s)\n"
        "  --out-image     <string>      extension of file to save plots (def: %s)\n"
        ,
        argv[0],
        Config::outdir.Data(),
        (Config::doBlind    ? "false" : "true"),
        (Config::doAnalysis ? "true" : "false"),
        (Config::doStack    ? "true" : "false"),
        Config::plotnames.Data(),
        Config::whichSel,
        (Config::doStandard ? "true" : "false"),
        (Config::doNminus1  ? "true" : "false"),
	(Config::useData    ? "true" : "false"),
	(Config::doMETcor   ? "true" : "false"),
        Config::outtype.Data()
      );
      exit(0);
    }
    else if (*i == "--outdir")      { next_arg_or_die(mArgs, i); Config::outdir = i->c_str(); }
    else if (*i == "--unblind")     { Config::doBlind      = false; }
    else if (*i == "--do-analysis") { Config::doAnalysis   = true; }
    else if (*i == "--do-stack")    { Config::doStack      = true; }
    else if (*i == "--plotnames")   { next_arg_or_die(mArgs, i); Config::plotnames = std::atoi(i->c_str()); }
    else if (*i == "--which-sel")   { next_arg_or_die(mArgs, i); Config::whichSel = std::atoi(i->c_str()); }
    else if (*i == "--do-standard") { Config::doStandard   = true; }
    else if (*i == "--do-nminus1")  { Config::doNminus1    = true; }
    else if (*i == "--use-Data")    { Config::useData      = true; }
    else if (*i == "--do-metcor")   { Config::doMETcor     = true; }
    else if (*i == "--out-image")   { next_arg_or_die(mArgs, i); Config::outtype  = i->c_str(); }
    else    { std::cerr << "Error: Unknown option/argument: " << i->c_str() << " ...exiting..." << std::endl; exit(1); }
    mArgs.erase(start, ++i);
  }

  //------------------------------------------------------------------------
  // Initialization
  //------------------------------------------------------------------------
  TString inDir = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_v5/";
  std::ofstream yields; TStyle * tdrStyle; 
  InitializeMain(yields, tdrStyle);

  //------------------------------------------------------------------------
  // Blinding
  //------------------------------------------------------------------------
  std::string input;
  if (Config::doBlind) std::cout << "Blinding data" << std::endl;
  else
  {
    std::cout << "Unblinding data!" << std::endl;
    std::cout << "Do you want to proceed? (yn) " << std::endl;
    std::cin >> input;
    if (input == "y") std::cout << "Proceeding" << std::endl;
    else{ std::cout << "Please do not use flag: --unblind ... exiting..." << std::endl; exit(1); }
  }

  //------------------------------------------------------------------------
  // Get the MET correction
  //------------------------------------------------------------------------
  DblVec metCorrMC;
  DblVec metCorrData;

  if (Config::doMETcor)
  {
    std::cout << "Get MET-phi Correction MC" << std::endl;
    METcorr * metcorrMC = new METcorr(0,inDir,"DiPhoton");
    metCorrMC = metcorrMC->Loop(inDir, "MC");    
    delete metcorrMC;
    
    std::cout << "Get MET-phi Correction Data" << std::endl;
    METcorr * metcorrData = new METcorr(0,inDir,"DoubleEG");
    metCorrData = metcorrData->Loop(inDir, "Data");    
    delete metcorrData;    
  }
  else
  {
    std::cout << "Skipping MET-phi calculation, just pickup correction" << std::endl; 
    // pick up MC metCorr
    TString metStudyMC = Form("%smetCorr_MC.root",inDir.Data());
    TFile *fmetCorrMC = TFile::Open(metStudyMC.Data());
    CheckValidFile(fmetCorrMC,metStudyMC);
    TH1D *MCmet = (TH1D*)fmetCorrMC->Get("metCorr");  
    CheckValidTH1D(MCmet,"",metStudyMC);

    // pick up Data metCorr
    TString metStudyData = Form("%smetCorr_Data.root",inDir.Data());
    TFile *fmetCorrDATA = TFile::Open(metStudyData.Data());
    CheckValidFile(fmetCorrDATA,metStudyData);
    TH1D *DATAmet = (TH1D*)fmetCorrDATA->Get("metCorr");  
    CheckValidTH1D(DATAmet,"",metStudyData);
     
    for (UInt_t i=0; i<4; i++){
      metCorrMC.push_back(MCmet->GetBinContent(i+1));
      metCorrData.push_back(DATAmet->GetBinContent(i+1));
    }
  }

  //------------------------------------------------------------------------
  // Do analysis
  //------------------------------------------------------------------------
  if (Config::doAnalysis)
  {
    Int_t prompt = 0; //Do prompt removal
    for (TStrBoolMapIter iter = Config::SampleMap.begin(); iter != Config::SampleMap.end(); ++iter){
      std::cout << "Working on " << (*iter).first << " sample" << std::endl;
      if ( (*iter).first=="GJets") prompt==1;
      if ( (*iter).first=="QCD")   prompt==2;
      // input arguments: inputdir,outputdir,sample,lumi,isData,doBlind,png/pdf,metCorr,whichSel
      Analysis * plot = new Analysis(inDir,Config::outdir,(*iter).first,Config::lumi,(*iter).second,Config::doBlind,Config::outtype,metCorrMC,Config::whichSel);
      plot->DoPlots(prompt);
      delete plot;
      std::cout << "Finished " << (*iter).first << " sample" << std::endl;
    }
    std::cout << "Finished running analysis" << std::endl;
  }
  else std::cout << "Skipping running analysis" << std::endl;  

  //------------------------------------------------------------------------
  // Make stack plots 
  //------------------------------------------------------------------------
  if (Config::doStack)  
  {
    StackPlots * stack = new StackPlots();
    stack->DoStack();
    delete stack;    
  }

  DestroyMain(yields,tdrStyle);
}// end main
