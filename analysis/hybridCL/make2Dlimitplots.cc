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
#include <vector>

void makePlots(TString, TString);
void getLimits(TFile*, Double_t &, Double_t); 
void getXsec(TFile*, UInt_t, UInt_t, Double_t &); 

void make2Dlimitplots(){
 
  cout << "Making 2D limit plots" << endl;

  TString inDir = "~soffi/public/4Margaret/2Dinputs/";
  //TString inDir = "~/private/HiggsCombine/CMSSW_7_1_5/src/diphotons/Analysis/macros/";
  TString outDir = "~/www/Plots/25ns_Limits_76X_2DResults/";
  // SPECIFY LUMI in mkPlotsLivia/CMS_lumi.C

  makePlots(inDir, outDir);

}


void makePlots(TString inDir, TString outDir){

  // mZp masses 
  std::vector<UInt_t> mass;
  mass.push_back(600);
  mass.push_back(800);
  mass.push_back(1000);
  mass.push_back(1200);
  mass.push_back(1400);
  mass.push_back(1700);
  mass.push_back(2000);
  mass.push_back(2500);
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
    higgsCombineFiles_MA0300[n] = new TFile(Form("%sMA300/higgsCombineTest.HybridNew.mH%i.root",inDir.Data(),mass[n]));
    higgsCombineFiles_MA0400[n] = new TFile(Form("%sMA400/higgsCombineTest.HybridNew.mH%i.root",inDir.Data(),mass[n]));
    higgsCombineFiles_MA0500[n] = new TFile(Form("%sMA500/higgsCombineTest.HybridNew.mH%i.root",inDir.Data(),mass[n]));
    higgsCombineFiles_MA0600[n] = new TFile(Form("%sMA600/higgsCombineTest.HybridNew.mH%i.root",inDir.Data(),mass[n]));
    higgsCombineFiles_MA0700[n] = new TFile(Form("%sMA700/higgsCombineTest.HybridNew.mH%i.root",inDir.Data(),mass[n]));
    higgsCombineFiles_MA0800[n] = new TFile(Form("%sMA800/higgsCombineTest.HybridNew.mH%i.root",inDir.Data(),mass[n]));
  }

 // pick up theory xsec
 TFile* theory_gz08 = new TFile("ScanPlot_gz08.root");

 // setup output plot
 TH2D * limits = new TH2D("limits","limits",8,0,8,6,0,6);
 limits->GetXaxis()->SetTitle("m_{Z'} [GeV]");
 limits->GetYaxis()->SetTitle("m_{A0} [GeV]");
 limits->SetTitle("");
 limits->SetMaximum(2);
 limits->SetMarkerSize(2);

 // set the lables for the Xaxis (mZp)
 limits->GetXaxis()->SetBinLabel(1,"600");
 limits->GetXaxis()->SetBinLabel(2,"800");
 limits->GetXaxis()->SetBinLabel(3,"1000");
 limits->GetXaxis()->SetBinLabel(4,"1200");
 limits->GetXaxis()->SetBinLabel(5,"1400");
 limits->GetXaxis()->SetBinLabel(6,"1700");
 limits->GetXaxis()->SetBinLabel(7,"2000");
 limits->GetXaxis()->SetBinLabel(8,"2500");

 // set the lables for the Yaxis (mA0)
 limits->GetYaxis()->SetBinLabel(1,"300");
 limits->GetYaxis()->SetBinLabel(2,"400");
 limits->GetYaxis()->SetBinLabel(3,"500");
 limits->GetYaxis()->SetBinLabel(4,"600");
 limits->GetYaxis()->SetBinLabel(5,"700");
 limits->GetYaxis()->SetBinLabel(6,"800");

 // setup output observed plot
 TH2D * obslimits = (TH2D*) limits->Clone();

 // setup canvas
 TCanvas * c = new TCanvas("c","");
 c->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPaintTextFormat("2.4f");

 std::vector< Double_t > limitval300;
 limitval300.resize(nMasses);
 std::vector< Double_t > limitval400;
 limitval400.resize(nMasses);
 std::vector< Double_t > limitval500;
 limitval500.resize(nMasses);
 std::vector< Double_t > limitval600;
 limitval600.resize(nMasses);
 std::vector< Double_t > limitval700;
 limitval700.resize(nMasses);
 std::vector< Double_t > limitval800;
 limitval800.resize(nMasses);

 std::vector< Double_t > limitval300_obs;
 limitval300_obs.resize(nMasses);
 std::vector< Double_t > limitval400_obs;
 limitval400_obs.resize(nMasses);
 std::vector< Double_t > limitval500_obs;
 limitval500_obs.resize(nMasses);
 std::vector< Double_t > limitval600_obs;
 limitval600_obs.resize(nMasses);
 std::vector< Double_t > limitval700_obs;
 limitval700_obs.resize(nMasses);
 std::vector< Double_t > limitval800_obs;
 limitval800_obs.resize(nMasses);

 std::vector< Double_t > xsecA0300;
 xsecA0300.resize(nMasses);
 std::vector< Double_t > xsecA0400;
 xsecA0400.resize(nMasses);
 std::vector< Double_t > xsecA0500;
 xsecA0500.resize(nMasses);
 std::vector< Double_t > xsecA0600;
 xsecA0600.resize(nMasses);
 std::vector< Double_t > xsecA0700;
 xsecA0700.resize(nMasses);
 std::vector< Double_t > xsecA0800;
 xsecA0800.resize(nMasses);


 for (UInt_t n=0; n<nMasses; n++){
   getLimits(higgsCombineFiles_MA0300[n],limitval300[n],0.5); 
   getLimits(higgsCombineFiles_MA0400[n],limitval400[n],0.5); 
   getLimits(higgsCombineFiles_MA0500[n],limitval500[n],0.5); 
   getLimits(higgsCombineFiles_MA0600[n],limitval600[n],0.5); 
   getLimits(higgsCombineFiles_MA0700[n],limitval700[n],0.5); 
   getLimits(higgsCombineFiles_MA0800[n],limitval800[n],0.5); 
   //std::cout<<n<<" "<<limitval300[n]<< " "<<limitval400[n]<<limitval500[n]<< " "<<limitval600[n] <<limitval700[n]<< " "<<limitval800[n]<<std::endl;

   getLimits(higgsCombineFiles_MA0300[n],limitval300_obs[n],-1); 
   getLimits(higgsCombineFiles_MA0400[n],limitval400_obs[n],-1); 
   getLimits(higgsCombineFiles_MA0500[n],limitval500_obs[n],-1); 
   getLimits(higgsCombineFiles_MA0600[n],limitval600_obs[n],-1); 
   getLimits(higgsCombineFiles_MA0700[n],limitval700_obs[n],-1); 
   getLimits(higgsCombineFiles_MA0800[n],limitval800_obs[n],-1); 

   getXsec(theory_gz08,300,mass[n],xsecA0300[n]);
   getXsec(theory_gz08,400,mass[n],xsecA0400[n]);
   getXsec(theory_gz08,500,mass[n],xsecA0500[n]);
   getXsec(theory_gz08,600,mass[n],xsecA0600[n]);
   getXsec(theory_gz08,700,mass[n],xsecA0700[n]);
   getXsec(theory_gz08,800,mass[n],xsecA0800[n]);

   // fill limit plot
   limits->Fill(((Double_t)n+0.5),0.5,limitval300[n]*2*xsecA0300[n]);
   limits->Fill(((Double_t)n+0.5),1.5,limitval400[n]*2*xsecA0400[n]);
   limits->Fill(((Double_t)n+0.5),2.5,limitval500[n]*2*xsecA0500[n]);
   limits->Fill(((Double_t)n+0.5),3.5,limitval600[n]*2*xsecA0600[n]);
   limits->Fill(((Double_t)n+0.5),4.5,limitval700[n]*2*xsecA0700[n]);
   limits->Fill(((Double_t)n+0.5),5.5,limitval800[n]*2*xsecA0800[n]);
   
   obslimits->Fill(((Double_t)n+0.5),0.5,limitval300_obs[n]*2*xsecA0300[n]);
   obslimits->Fill(((Double_t)n+0.5),1.5,limitval400_obs[n]*2*xsecA0400[n]);
   obslimits->Fill(((Double_t)n+0.5),2.5,limitval500_obs[n]*2*xsecA0500[n]);
   obslimits->Fill(((Double_t)n+0.5),3.5,limitval600_obs[n]*2*xsecA0600[n]);
   obslimits->Fill(((Double_t)n+0.5),4.5,limitval700_obs[n]*2*xsecA0700[n]);
   obslimits->Fill(((Double_t)n+0.5),5.5,limitval800_obs[n]*2*xsecA0800[n]);
   
 }

 // draw plot
 limits->Draw("COLZ TEXT"); 

 // save plot
 CMS_lumi(c,false,7);
 c->cd();
 c->SaveAs(Form("%s/limits2D_2HDM_exp.png",outDir.Data()));
 c->SaveAs(Form("%s/limits2D_2HDM_exp.pdf",outDir.Data()));

 obslimits->Draw("COLZ TEXT"); 

 // save plot
 CMS_lumi(c,false,7);
 c->cd();
 c->SaveAs(Form("%s/limits2D_2HDM_obs.png",outDir.Data()));
 c->SaveAs(Form("%s/limits2D_2HDM_obs.pdf",outDir.Data()));

 delete c;

 TCanvas* cboth = new TCanvas("cboth","");
 cboth->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPaintTextFormat("2.4f");

 TPad* p1 = new TPad("p1","",0,0.12,1,0.98);
 p1->Draw();
 p1->cd();

 limits->SetMarkerSize(2);
 limits->Draw("TEXT SAME"); 
 p1->Update();

 Double_t x1,y1,x2,y2;
 p1->GetRange(x1,y1,x2,y2);

 cboth->cd();
 TPad* p2 = new TPad("p2","",0,0.09,1,0.95);
 p2->SetFillStyle(0);
 p2->SetFillColor(0);
 p2->Draw();
 p2->cd();
 p2->Range(x1,y1,x2,y2);

 obslimits->GetXaxis()->SetTitle("");
 obslimits->GetYaxis()->SetTitle("");
 obslimits->SetTitle("");
 obslimits->GetXaxis()->SetBinLabel(1,"");
 obslimits->GetXaxis()->SetBinLabel(2,"");
 obslimits->GetXaxis()->SetBinLabel(3,"");
 obslimits->GetXaxis()->SetBinLabel(4,"");
 obslimits->GetXaxis()->SetBinLabel(5,"");
 obslimits->GetXaxis()->SetBinLabel(6,"");
 obslimits->GetXaxis()->SetBinLabel(7,"");
 obslimits->GetXaxis()->SetBinLabel(8,"");
 obslimits->GetYaxis()->SetBinLabel(1,"");
 obslimits->GetYaxis()->SetBinLabel(2,"");
 obslimits->GetYaxis()->SetBinLabel(3,"");
 obslimits->GetYaxis()->SetBinLabel(4,"");
 obslimits->GetYaxis()->SetBinLabel(5,"");
 obslimits->GetYaxis()->SetBinLabel(6,"");

 obslimits->Draw("TEXT SAME");
 p2->Update();

 CMS_lumi(cboth,false,7);
 cboth->cd();
 c->SaveAs(Form("%s/limits2D_2HDM_ExpAndObs.png",outDir.Data()));
 c->SaveAs(Form("%s/limits2D_2HDM_ExpAndObs.pdf",outDir.Data()));
 delete cboth;

}

void getXsec(TFile* file, UInt_t mA0, UInt_t mZp, Double_t & xsec){

  TH2F* xsecs = (TH2F*)file->Get("xsec1"); 
  if (xsecs!=(TH2F*)NULL){
     Int_t binX = xsecs->GetXaxis()->FindBin(mZp);
     Int_t binY = xsecs->GetYaxis()->FindBin(mA0);
     xsec = xsecs->GetBinContent(binX,binY); 
  }
  else{
   xsec = 1;
   std::cout << "Couldn't find xsec histogram" << std::endl;
  }
} 


void getLimits(TFile* file, Double_t & Limit, Double_t quantile){

  Double_t limit;
  Float_t quantileExpected;

  TBranch *b_limit;
  TBranch *b_quantileExpected;

  TTree* tree = (TTree*)file->Get("limit");
  if (tree!=(TTree*)NULL){
 
    tree->SetBranchAddress("limit", &limit, &b_limit);
    tree->SetBranchAddress("quantileExpected", &quantileExpected, &b_quantileExpected);
 
    Limit = 0;
    UInt_t nentries = tree->GetEntries();
    for (UInt_t entry = 0; entry < nentries; entry++){
      tree->GetEntry(entry);
      //std::cout << "Quantile = " << quantileExpected << std::endl;
      //std::cout << "Limit    = " << limit << std::endl;
      if (quantileExpected==quantile) Limit=limit;
    }

  }// end valid tree
  else Limit = 0;
  //std::cout << "Limit    = " << Limit << std::endl;
  
  delete tree;

}

