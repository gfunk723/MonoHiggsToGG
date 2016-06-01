#include <TFile.h>
#include <TLine.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TMath.h>
#include "../macro/mkPlotsLivia/CMS_lumi.C"
#include <iostream>

using namespace std;

void makePlots(TString, TString, UInt_t);
void getLimits(TTree* &, Double_t &, std::string); 

void make2Dlimitplots(){
 
  cout << "Making 2D limit plots" << endl;

  TString inDir = "~/private/HiggsCombine/CMSSW_7_1_5/src/diphotons/Analysis/macros/";
  TString outDir = "~/www/Plots/25ns_Limits_76X/";
  // SPECIFY LUMI in mkPlotsLivia/CMS_lumi.C

  // type of limit plot to make (expected or observed limits)
  UInt_t type = 0; // 0=Exp,1=Obs

  makePlots(inDir, outDir, type);

}


void makePlots(TString inDir, TString outDir, UInt_t type){

  // mZp masses 
  std::vector<UInt_t> mass;
  mass.push_back(600);
  mass.push_back(800);
  mass.push_back(1000);
  //mass.push_back(1200);
  //mass.push_back(1400);
  //mass.push_back(1700);
  //mass.push_back(2000);
  //mass.push_back(2500);
  UInt_t nMasses = mass.size();

  // pick up the higgsCombine files for each A0 mass
  std::vector<TFile* > higgsCombineFiles_MA0300;
  std::vector<TFile* > higgsCombineFiles_MA0400;
  std::vector<TFile* > higgsCombineFiles_MA0500;
  std::vector<TFile* > higgsCombineFiles_MA0600;
  std::vector<TFile* > higgsCombineFiles_MA0700;
  std::vector<TFile* > higgsCombineFiles_MA0800;

  higgsCombineFiles_MA0300.resize(nMasses);
  higgsCombineFiles_MA0400.resize(nMasses);
  higgsCombineFiles_MA0500.resize(nMasses);
  higgsCombineFiles_MA0600.resize(nMasses);
  higgsCombineFiles_MA0700.resize(nMasses);
  higgsCombineFiles_MA0800.resize(nMasses);

  for (UInt_t n=0; n<nMasses; n++){
    higgsCombineFiles_MA0300[n] = new TFile(Form("%sCards_2HDM_76X_A0300/higgsCombineTest.HybridNew.mH%i.mA0300.root",inDir.Data(),mass[n]));
    //higgsCombineFiles_MA0400[n] = new TFile(Form("%sCards_2HDM_76X_A0400/higgsCombineTest.HybridNew.mH%i.mA0400.root",inDir.Data(),mass[n]));
    //higgsCombineFiles_MA0500[n] = new TFile(Form("%sCards_2HDM_76X_A0500/higgsCombineTest.HybridNew.mH%i.mA0500.root",inDir.Data(),mass[n]));
    //higgsCombineFiles_MA0600[n] = new TFile(Form("%sCards_2HDM_76X_A0600/higgsCombineTest.HybridNew.mH%i.mA0600.root",inDir.Data(),mass[n]));
    //higgsCombineFiles_MA0700[n] = new TFile(Form("%sCards_2HDM_76X_A0700/higgsCombineTest.HybridNew.mH%i.mA0700.root",inDir.Data(),mass[n]));
    //higgsCombineFiles_MA0800[n] = new TFile(Form("%sCards_2HDM_76X_A0800/higgsCombineTest.HybridNew.mH%i.mA0800.root",inDir.Data(),mass[n]));
  }

 // load the trees
 std::vector<TTree* > trees_MA0300;  
 std::vector<TTree* > trees_MA0400;  
 std::vector<TTree* > trees_MA0500;  
 std::vector<TTree* > trees_MA0600;  
 std::vector<TTree* > trees_MA0700;  
 std::vector<TTree* > trees_MA0800;  
 
 trees_MA0300.resize(nMasses);  
 trees_MA0400.resize(nMasses);  
 trees_MA0500.resize(nMasses);  
 trees_MA0600.resize(nMasses);  
 trees_MA0700.resize(nMasses);  
 trees_MA0800.resize(nMasses);  
 
 for (UInt_t n=0; n<nMasses; n++){
   trees_MA0300[n] = (TTree*)higgsCombineFiles_MA0300[n]->Get("limits");
   //trees_MA0400[n] = (TTree*)higgsCombineFiles_MA0400[n]->Get("limits");
   //trees_MA0500[n] = (TTree*)higgsCombineFiles_MA0500[n]->Get("limits");
   //trees_MA0600[n] = (TTree*)higgsCombineFiles_MA0600[n]->Get("limits");
   //trees_MA0700[n] = (TTree*)higgsCombineFiles_MA0700[n]->Get("limits");
   //trees_MA0800[n] = (TTree*)higgsCombineFiles_MA0800[n]->Get("limits");
 }

 // setup output plot
 TH2D * limits = new TH2D("limits","limits",8,0,8,6,0,6);
 limits->GetXaxis()->SetTitle("m_{Z'} [GeV]");
 limits->GetYaxis()->SetTitle("m_{A0} [GeV]");
 limits->SetTitle("");

 //limits->SetBinLabel(1,1,"600");

 // setup canvas
 TCanvas * c = new TCanvas("c","");
 c->cd();
 gStyle->SetOptStat(0);

 std::string quantile="0";
 if (type==0) quantile="0.5";
 if (type==1) quantile="-1";

 std::vector< Double_t > limitval300;
 limitval300.resize(nMasses);

 for (UInt_t n=0; n<nMasses; n++){
   getLimits(trees_MA0300[n],limitval300[n],quantile); 
   delete trees_MA0300[n];
 }

 // draw plot
 limits->Draw("COLZ TEXT"); 

 // save plot
 CMS_lumi(c,false,8);
 c->cd();
 c->SaveAs(Form("%s/limits2D_2HDM.png",outDir.Data()));

}

void getLimits(TTree* & tree, Double_t & Limit, std::string quantile){

  Double_t limit;
  Double_t quantileExpected;

  TBranch *b_limit;
  TBranch *b_quantileExpected;

  tree->SetBranchAddress("limit",&limit,&b_limit);
  tree->SetBranchAddress("quantileExpected",&quantileExpected,&b_quantileExpected);
 
  Limit = 0;

  //UInt_t nentries = tree->GetEntries();
  //for (UInt_t entry = 0; entry < nentries; entry++){
  //  tree->GetEntry();
  //  if (quantileExpected==quantile) Limit=limit;
  //}  
  
  //delete tree;


}

