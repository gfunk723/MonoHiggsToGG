#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"

#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#include "TMVA/DataLoader.h"
#include "TMVA/TMVAGui.h"

void makeDNNtest()
{

  TMVA::Tools::Instance();
  TString path  = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/";
  //TString sign  = "2HDM_mZP600_mA0300";
  TString sign  = "BaryonicZp_mZP10_mChi1";
  TString skim  = "_skim_woVetos.root";

  TFile *sig_in = TFile::Open( TString::Format("%s%s%s",path.Data(),sign.Data(),skim.Data()));
  TFile *bkg1_in = TFile::Open( TString::Format("%sDiPhoton%s", path.Data(),skim.Data()));
  TFile *bkg2_in = TFile::Open( TString::Format("%sEWKBkg%s", path.Data(),skim.Data()));
  TFile *bkg3_in = TFile::Open( TString::Format("%sGluGluHToGG%s", path.Data(),skim.Data()));
  TFile *bkg4_in = TFile::Open( TString::Format("%sVHToGG%s", path.Data(),skim.Data()));
  TFile *bkg5_in = TFile::Open( TString::Format("%sttHJetToGG%s", path.Data(),skim.Data()));
  TFile *bkg6_in = TFile::Open( TString::Format("%sVBFHToGG%s", path.Data(),skim.Data()));
 
  TMVA::DataLoader *loader = new TMVA::DataLoader("dataset");
 
  // --- Register training and testing trees
  TTree *sig  = (TTree*)sig_in->Get("DiPhotonTree");
  TTree *bkg1 = (TTree*)bkg1_in->Get("DiPhotonTree");
  TTree *bkg2 = (TTree*)bkg2_in->Get("DiPhotonTree");
  TTree *bkg3 = (TTree*)bkg3_in->Get("DiPhotonTree");
  TTree *bkg4 = (TTree*)bkg4_in->Get("DiPhotonTree");
  TTree *bkg5 = (TTree*)bkg5_in->Get("DiPhotonTree");
  TTree *bkg6 = (TTree*)bkg6_in->Get("DiPhotonTree");
  
  // --- Create output root file
  TString outfileName = "TMVA_DNN.root";
  TFile* outputFile = TFile::Open( outfileName, "RECREATE");

  TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile, "!V:!Silent:Color:DrawProgressBar:AnalysisType=Classification" );

  loader->AddVariable("ptgg",'F');
  loader->AddVariable("t1pfmetCorr",'F');
  loader->AddVariable("dphiggmet",'F');
  loader->AddVariable("dphig1met",'F');
  loader->AddVariable("dphig2met",'F');
  loader->AddVariable("detag1g2",'F');

  // --- Global event weights
  Double_t sigWeight = 1.0;
  Double_t bkgWeight = 1.0;

  // --- Add arbitrary number of signal or background trees
  loader->AddSignalTree    ( sig, sigWeight );
  loader->AddBackgroundTree( bkg1, bkgWeight );
  loader->AddBackgroundTree( bkg2, bkgWeight );
  loader->AddBackgroundTree( bkg3, bkgWeight );
  loader->AddBackgroundTree( bkg4, bkgWeight );
  loader->AddBackgroundTree( bkg5, bkgWeight );
  loader->AddBackgroundTree( bkg6, bkgWeight );

  // --- Apply additional cuts
  TCut mycutsig = "";
  TCut mycutbkg = "";

  // --- Split sample into training and testing
  loader->PrepareTrainingAndTestTree( mycutsig, mycutbkg, "nTrain_Signal=10000:nTrain_Background=10000:nTest_Signal=10000:nTest_Background=10000:SplitMode=Random:NormMode=NumEvents:!V" );

  // --- Improved neural network implementation
  TString layoutString = "Layout=TANH|100,TANH|50,TANH|10,LINEAR";
  TString training0 ("LearningRate=le-l,Momentum=0.0,Repetitions=1,ConvergenceSteps=300,BatchSize=20,TestRepetitions=15,WeightDecay=0.001,Regularization=NONE,DropConfig=0.0+0.5+0.5+0.5,DropRepetitions=1,Multithreading=True");
  TString training1 ("LearningRate=1e-2,Momentum=0.5,Repetitions=1,ConvergenceSteps=300,BatchSize=30,TestRepetitions=7,WeightDecay=0.001,Regularization=L2,Multithreading=True,DropConfig=0.0+0.1+0.1+0.1,DropRepetitions=1");
  TString training2 ("LearningRate=1e-2,Momentum=0.3,Repetitions=1,ConvergenceSteps=300,BatchSize=40,TestRepetitions=7,WeightDecay=0.0001,Regularization=L2,Multithreading=True");
  TString training3 ("LearningRate=1e-3,Momentum=0.1,Repetitions=1,ConvergenceSteps=200,BatchSize=70,TestRepetitions=7,WeightDecay=0.0001,Regularization=NONE,Multithreading=True");

  TString trainingStrategyString("TrainingStrategy=");
  trainingStrategyString += training0 + "|" + training1 + "|" + training2 + "|" + training3;
 
  TString nnOptions ("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=G:WeightInitialization=XAVIERUNIFORM");
  nnOptions.Append(":");
  nnOptions.Append(layoutString);
  nnOptions.Append(":");
  nnOptions.Append(trainingStrategyString);

  factory->BookMethod(loader,TMVA::Types::kDNN,"DNN",nnOptions); 
  // --- Training
  factory->TrainAllMethods();
  // --- Testing
  factory->TestAllMethods();
  // --- Evaluate and compare
  factory->EvaluateAllMethods();

  // --- Save outputs
  outputFile->Close();
  std::cout << "---> Wrote root file: " << outputFile->GetName() << std::endl;
  std::cout << "---> TMVAClassification is done!" << std::endl;
 
  delete factory;
  delete loader;
  
  // --- Launch GUI
  if (!gROOT->IsBatch()) TMVA::TMVAGui( outfileName ); 

}
