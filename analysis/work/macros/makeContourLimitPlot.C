
#include "TROOT.h"
#include <TFile.h>
#include <TLine.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH2.h>
#include <TF2.h>
#include <TMultiGraph.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TLegend.h>
#include <TMath.h>
#include <TGraph.h>
#include <TGraph2D.h>
#include <TFrame.h>
#include <TLatex.h>
//#include "../macro/mkPlotsLivia/CMS_lumi.C"
#include <iostream>
#include <vector>

double makeInterpolation(TGraph* g, bool isFirst);
void makePlots2D(TString, TString);
void getLimits(TFile*, Double_t &, Double_t); 
void getXsec(TFile*, int, int, Double_t &); 
void getXsecBaryo(TFile*, int, int, Double_t &); 
void getXsecScalar(TFile*, int, int, Double_t &); 
void getEff(TFile*, int, int, Double_t &, Double_t &); 
void make2Dlimitplots_76X();
void makeEffParametrization();

void makeContourLimitPlot(){
 
  cout << "Making 2D limit plots" << endl;

  //TString inDir	= "~soffi/public/4Margaret/2Dinputs/";
  TString inDir		= "~soffi/public/4Margaret/ntuples4fit_pho_allMC_woLepVetos_met50_met130_cic_default_shapes_lumi_35.9_PARAMETRIC"; //ntuples4fit_pho_allMC_woLepVetos_met50_met130_cic_default_shapes_lumi_35.9/";
  TString outDir	= "~/www/Plots/13TeV_v80X_moriond17/ContourPlots/";
  // SPECIFY LUMI in mkPlotsLivia/CMS_lumi.C

  //  makePlotsScalar(inDir, outDir);
  // makePlotsBaryo(inDir, outDir);
  makePlots2D(inDir, outDir);
  //  makeEffParametrization();
}








void makeEffParametrization(){

  TCanvas* c = new TCanvas("c","c",1);
  TFile* fin = TFile::Open("Output_Eff.root", "READ"); 
  TH2D* h2_high=  (TH2D*) fin->Get("var_BARY_Eff_HighMET");
  TF2 *f2_high = new TF2("f2_high","x*[0]+y*[1]+x*x*[2]+y*y*[3]+x*y*[4]+[5]", 10, 10000, 1, 1000);
  h2_high->Fit("f2_high");
  //  h2->Draw("LEGO");
  f2_high->Draw("SURF");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_HighMET.png");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_HighMET.pdf");

  f2_high->Draw("COLZ");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_COLZ_HighMET.png");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_COLZ_HighMET.pdf");

  TH2D* h2_low=  (TH2D*) fin->Get("var_BARY_Eff_LowMET");
  TF2 *f2_low = new TF2("f2_low","x*[0]+y*[1]+x*x*[2]+y*y*[3]+x*y*[4]+[5]", 10, 10000, 1, 1000);
  h2_low->Fit("f2_low");
  //  h2->Draw("LEGO");
  f2_low->Draw("SURF");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_LowMET.png");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_LowMET.pdf");

  f2_low->Draw("COLZ");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_COLZ_LowMET.png");
  c->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/Baryonic_EffParametrization_COLZ_LowMET.pdf");

  
}





double makeInterpolation(TGraph* g, bool isFirst, double mass){

  double*  xvals=g->GetX();
  double*  yvals=g->GetY();

  double    deltaylow=99999999;
  double   deltayup=99999999;
  double yobs=1.;
  
  double yup=999.;
  double xup=999.;
  double ylow=999.;
  double xlow=999.;
  /*  int binmin=2;
  if(mass==10) binmin=2;
  if(mass==50) binmin=3;
  if(mass==150) binmin=3;
  */
  int  binmin=13;
  if(isFirst){
    for(int i=0;i<binmin; i++){
    //std::cout<<yvals[i]<<" "<<xvals[i]<<std::endl;
    double deltay=yvals[i]-yobs;
    if(deltay>=0 && deltay<deltayup){
      deltayup=deltay;
      yup=yvals[i];
      xup=xvals[i];
    }else if(deltay<0 && abs(deltay)<abs(deltaylow)){
      deltaylow=deltay;
      xlow=xvals[i];
      ylow=yvals[i];
      
    }
  }
  }else{
    for(int i=binmin;i<g->GetN(); i++){
    //std::cout<<yvals[i]<<" "<<xvals[i]<<std::endl;
    double deltay=yvals[i]-yobs;
    if(deltay>=0 && deltay<deltayup){
      deltayup=deltay;
      yup=yvals[i];
      xup=xvals[i];
    }else if(deltay<0 && abs(deltay)<abs(deltaylow)){
      deltaylow=deltay;
      xlow=xvals[i];
      ylow=yvals[i];
      
    }
  }

  }
  //  std::cout<<deltayup<<" "<<deltaylow<<" "<<xlow<<" "<<xup<<" "<<ylow<<" "<<yup<<std::endl;
  double m=(yup-ylow)/(xup-xlow);
  //  std::cout<<" m: "<< m << std::endl;
  double    xobs=(1-ylow+m*xlow)/m;
  
  return xobs;

}




void makePlots2D(TString inDir, TString outDir){

  // lumi
  Float_t lumi = 35.9;

  // mZp masses 
  Double_t mass[25] = {10,20,30,50,75,100,150,200,250,300,400,500,600,700,900,1200,1500,2000,2500,3000,4000,5000,6000,8000,10000};
  Int_t nMasses = 25;
  double x[26]={1,15,25,50,70,85,125,175,225,275,350,450,550,650,800,1050,1350,1750,2250,2750,3500,4500,5500,7000,9000,12000};

  // pick up the higgsCombine files for each A0 mass
  std::vector<TFile* > higgsCombineFiles_Mchi5;
  std::vector<TFile* > higgsCombineFiles_Mchi10;
  std::vector<TFile* > higgsCombineFiles_Mchi20;
  std::vector<TFile* > higgsCombineFiles_Mchi40;
  std::vector<TFile* > higgsCombineFiles_Mchi60;
  std::vector<TFile* > higgsCombineFiles_Mchi100;
  std::vector<TFile* > higgsCombineFiles_Mchi125;
  std::vector<TFile* > higgsCombineFiles_Mchi150;
  std::vector<TFile* > higgsCombineFiles_Mchi175;
  std::vector<TFile* > higgsCombineFiles_Mchi200;
  std::vector<TFile* > higgsCombineFiles_Mchi250;
  std::vector<TFile* > higgsCombineFiles_Mchi300;
  std::vector<TFile* > higgsCombineFiles_Mchi350;
  std::vector<TFile* > higgsCombineFiles_Mchi400;
  std::vector<TFile* > higgsCombineFiles_Mchi450;
  std::vector<TFile* > higgsCombineFiles_Mchi500;
  std::vector<TFile* > higgsCombineFiles_Mchi600;
  std::vector<TFile* > higgsCombineFiles_Mchi700;
  std::vector<TFile* > higgsCombineFiles_Mchi800;
  std::vector<TFile* > higgsCombineFiles_Mchi900;
  std::vector<TFile* > higgsCombineFiles_Mchi1000;



  higgsCombineFiles_Mchi5.resize(nMasses);
  higgsCombineFiles_Mchi10.resize(nMasses);
  higgsCombineFiles_Mchi20.resize(nMasses);
  higgsCombineFiles_Mchi40.resize(nMasses);
  higgsCombineFiles_Mchi60.resize(nMasses);
  higgsCombineFiles_Mchi100.resize(nMasses);
  higgsCombineFiles_Mchi125.resize(nMasses);
  higgsCombineFiles_Mchi150.resize(nMasses);
  higgsCombineFiles_Mchi175.resize(nMasses);
  higgsCombineFiles_Mchi200.resize(nMasses);
  higgsCombineFiles_Mchi250.resize(nMasses);
  higgsCombineFiles_Mchi300.resize(nMasses);
  higgsCombineFiles_Mchi350.resize(nMasses);
  higgsCombineFiles_Mchi400.resize(nMasses);
  higgsCombineFiles_Mchi450.resize(nMasses);
  higgsCombineFiles_Mchi500.resize(nMasses);
  higgsCombineFiles_Mchi600.resize(nMasses);
  higgsCombineFiles_Mchi700.resize(nMasses);
  higgsCombineFiles_Mchi800.resize(nMasses);
  higgsCombineFiles_Mchi900.resize(nMasses);
  higgsCombineFiles_Mchi1000.resize(nMasses);


  double y[21]={1,7.5,15,30,50,80,112.5,162.5,182.5,225,275,325,375,425,475,550,650,750,850,950,1050};

  for (int n=0; n<nMasses; n++){  
    higgsCombineFiles_Mchi5[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi5.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi10[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi10.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi20[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi20.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi40[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi40.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi60[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi60.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi100[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi100.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi125[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi125.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi150[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi150.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi175[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi175.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi200[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi200.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi250[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi250.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi300[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi300.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi350[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi350.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi400[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi400.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi450[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi450.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi500[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi500.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi600[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi600.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi700[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi700.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi800[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi800.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi900[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi900.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
    higgsCombineFiles_Mchi1000[n] = new TFile(Form("%s/higgsCombineMonoHgg_sig_ZpBaryonic_mZP%d_mChi1000.Asymptotic.mH%d.root",inDir.Data(),(Int_t)mass[n],(Int_t)mass[n]));
  }

 // pick up theory xsec
 TFile* theory = new TFile("theory_ZPBaryonic.root");

 // pick up efficiencies 
 // std::cout<<"debug1"<<std::endl;

 // make TLatex label
 TString latexCMSname = "#bf{CMS} #it{Preliminary}";
 TLatex *l1 = new TLatex(0.12,0.99,latexCMSname);
 l1->SetTextSize(0.036);
 l1->SetTextAlign(12);
 l1->SetNDC(kTRUE);
 l1->SetTextFont(42);
 TLatex *l1b = new TLatex(0.13,1.01,latexCMSname);
 l1b->SetTextSize(0.040);
 l1b->SetTextAlign(12);
 l1b->SetNDC(kTRUE);
 l1b->SetTextFont(42);

 TString latexlumi = Form("%1.1f fb^{-1}",lumi);
 TString latexenergy = " (13 TeV)";
 TString latexname = latexlumi+latexenergy;
 TLatex *l2 = new TLatex(0.65,0.99,latexname);
 l2->SetTextSize(0.034);
 l2->SetTextAlign(12);
 l2->SetNDC(kTRUE);
 l2->SetTextFont(42);
 //TLatex *l2b = new TLatex(0.74,0.90,latexname);
 //TLatex *l2b = new TLatex(0.725,0.95,latexname);
 TLatex *l2b = new TLatex(0.72,1.01,latexname);
 l2b->SetTextSize(0.034);
 l2b->SetTextAlign(12);
 l2b->SetNDC(kTRUE);
 l2b->SetTextFont(42);

 TString thestring = "Z'#rightarrow DM+h(#gamma#gamma)";
 TString add2hdm   = "(Baryonic)";
 //latex.SetTextSize(0.036);
 //latex.SetTextAlign(12); // centered
 //const char *thestring = "Z'#rightarrow DM+H(#gamma#gamma)";
 TLatex *l3 = new TLatex(0.11,0.82,thestring);
 l3->SetTextSize(0.036);
 l3->SetTextAlign(12);
 l3->SetNDC(kTRUE);
 l3->SetTextFont(42);
 TLatex *l3b = new TLatex(0.11,0.86,thestring);
 l3b->SetTextSize(0.031);
 l3b->SetTextAlign(12);
 l3b->SetNDC(kTRUE);
 l3b->SetTextFont(42);
 TLatex *l4 = new TLatex(0.11,0.85,add2hdm);
 l4->SetTextSize(0.036);
 l4->SetTextAlign(12);
 l4->SetNDC(kTRUE);
 l4->SetTextFont(42);
 //TLatex *l4b = new TLatex(0.115,0.73,add2hdm);
 TLatex *l4b = new TLatex(0.11,0.83,add2hdm);
 l4b->SetTextSize(0.031);
 l4b->SetTextAlign(12);
 l4b->SetNDC(kTRUE);
 l4b->SetTextFont(42);


 // setup 1D plots - expected
 TGraph* limit5;
 TGraph* limit10;
 TGraph* limit20;
 TGraph* limit40;
 TGraph* limit60;
 TGraph* limit100;
 TGraph* limit125;
 TGraph* limit150;
 TGraph* limit175;
 TGraph* limit200;
 TGraph* limit250;
 TGraph* limit300;
 TGraph* limit350;
 TGraph* limit400;
 TGraph* limit450;
 TGraph* limit500;
 TGraph* limit600;
 TGraph* limit700;
 TGraph* limit800;
 TGraph* limit900;
 TGraph* limit1000;

 // setup 1D plots - expected -1sig
 TGraph* n1siglimit5;
 TGraph* n1siglimit10;
 TGraph* n1siglimit20;
 TGraph* n1siglimit40;
 TGraph* n1siglimit60;
 TGraph* n1siglimit100;
 TGraph* n1siglimit125;
 TGraph* n1siglimit150;
 TGraph* n1siglimit175;
 TGraph* n1siglimit200;
 TGraph* n1siglimit250;
 TGraph* n1siglimit300;
 TGraph* n1siglimit350;
 TGraph* n1siglimit400;
 TGraph* n1siglimit450;
 TGraph* n1siglimit500;
 TGraph* n1siglimit600;
 TGraph* n1siglimit700;
 TGraph* n1siglimit800;
 TGraph* n1siglimit900;
 TGraph* n1siglimit1000;

 // setup 1D plots - expected +1sig
 TGraph* p1siglimit5;
 TGraph* p1siglimit10;
 TGraph* p1siglimit20;
 TGraph* p1siglimit40;
 TGraph* p1siglimit60;
 TGraph* p1siglimit100;
 TGraph* p1siglimit125;
 TGraph* p1siglimit150;
 TGraph* p1siglimit175;
 TGraph* p1siglimit200;
 TGraph* p1siglimit250;
 TGraph* p1siglimit300;
 TGraph* p1siglimit350;
 TGraph* p1siglimit400;
 TGraph* p1siglimit450;
 TGraph* p1siglimit500;
 TGraph* p1siglimit600;
 TGraph* p1siglimit700;
 TGraph* p1siglimit800;
 TGraph* p1siglimit900;
 TGraph* p1siglimit1000;

 // setup 1D plots - observed
 TGraph* limit5_obs;
 TGraph* limit10_obs;
 TGraph* limit20_obs;
 TGraph* limit40_obs;
 TGraph* limit60_obs;
 TGraph* limit100_obs;
 TGraph* limit125_obs;
 TGraph* limit150_obs;
 TGraph* limit175_obs;
 TGraph* limit200_obs;
 TGraph* limit250_obs;
 TGraph* limit300_obs;
 TGraph* limit350_obs;
 TGraph* limit400_obs;
 TGraph* limit450_obs;
 TGraph* limit500_obs;
 TGraph* limit600_obs;
 TGraph* limit700_obs;
 TGraph* limit800_obs;
 TGraph* limit900_obs;
 TGraph* limit1000_obs;


 // setup output plot
 
 TH2D * limits = new TH2D("limits","limits",25,x,20,y);
 limits->GetXaxis()->SetTitle("m_{Z'} [GeV]");
 limits->GetYaxis()->SetTitle("m_{#chi} [GeV]");
 limits->GetZaxis()->SetTitle("#sigma_{95\% CL} / #sigma_{th}");
 limits->SetTitle("");
 limits->GetZaxis()->SetRangeUser(0.1,1e04);
 limits->SetMarkerSize(1.6);
 //limits->GetZaxis()->SetLimits(0.,10000);
 gStyle->SetHistMinimumZero(kFALSE);

 // limits->GetYaxis()->SetTitleOffset(1.3);
 //limits->GetZaxis()->SetTitleOffset(0.75);
 // size of axis labels
 limits->GetXaxis()->SetTitleSize(0.04);
 limits->GetYaxis()->SetTitleSize(0.04);
 limits->GetZaxis()->SetTitleSize(0.035);
 limits->GetXaxis()->SetLabelSize(0.05);
 limits->GetYaxis()->SetLabelSize(0.05); 
 limits->GetZaxis()->SetLabelSize(0.025);

 // set the lables for the Xaxis (mZp)
 /* limits->GetXaxis()->SetBinLabel(1,"10");
 limits->GetXaxis()->SetBinLabel(2,"50");
 limits->GetXaxis()->SetBinLabel(3,"100");
 limits->GetXaxis()->SetBinLabel(4,"200");
 limits->GetXaxis()->SetBinLabel(5,"500");
 limits->GetXaxis()->SetBinLabel(6,"1000");
 limits->GetXaxis()->SetBinLabel(7,"2000");
 limits->GetXaxis()->SetBinLabel(8,"10000");

 // set the lables for the Yaxis (mA0)
 limits->GetYaxis()->SetBinLabel(1,"1");
 limits->GetYaxis()->SetBinLabel(2,"10");
 limits->GetYaxis()->SetBinLabel(3,"50");
 limits->GetYaxis()->SetBinLabel(4,"150");
 limits->GetYaxis()->SetBinLabel(5,"500");
 limits->GetYaxis()->SetBinLabel(6,"1000");
 */
 // setup output observed plot
 TH2D * obslimits = (TH2D*) limits->Clone();

 // setup canvas
 //TCanvas * c = new TCanvas("c","",889,768);
 TCanvas * c = new TCanvas("c","",1);
 c->cd();
 gStyle->SetOptStat(0);
 //gStyle->SetPaintTextFormat("2.1f");
 // c->SetLeftMargin(0.1);
 c->SetRightMargin(0.11);

 Double_t limitval5[nMasses];
 Double_t limitval10[nMasses];
 Double_t limitval20[nMasses];
 Double_t limitval40[nMasses];
 Double_t limitval60[nMasses];
 Double_t limitval100[nMasses];
 Double_t limitval125[nMasses];
 Double_t limitval150[nMasses];
 Double_t limitval175[nMasses];
 Double_t limitval200[nMasses];
 Double_t limitval250[nMasses];
 Double_t limitval300[nMasses];
 Double_t limitval350[nMasses];
 Double_t limitval400[nMasses];
 Double_t limitval450[nMasses];
 Double_t limitval500[nMasses];
 Double_t limitval600[nMasses];
 Double_t limitval700[nMasses];
 Double_t limitval800[nMasses];
 Double_t limitval900[nMasses];
 Double_t limitval1000[nMasses];

 Double_t limitval5_obs[nMasses];
 Double_t limitval10_obs[nMasses];
 Double_t limitval20_obs[nMasses];
 Double_t limitval40_obs[nMasses];
 Double_t limitval60_obs[nMasses];
 Double_t limitval100_obs[nMasses];
 Double_t limitval125_obs[nMasses];
 Double_t limitval150_obs[nMasses];
 Double_t limitval175_obs[nMasses];
 Double_t limitval200_obs[nMasses];
 Double_t limitval250_obs[nMasses];
 Double_t limitval300_obs[nMasses];
 Double_t limitval350_obs[nMasses];
 Double_t limitval400_obs[nMasses];
 Double_t limitval450_obs[nMasses];
 Double_t limitval500_obs[nMasses];
 Double_t limitval600_obs[nMasses];
 Double_t limitval700_obs[nMasses];
 Double_t limitval800_obs[nMasses];
 Double_t limitval900_obs[nMasses];
 Double_t limitval1000_obs[nMasses];

 Double_t p1siglimitval5[nMasses];
 Double_t p1siglimitval10[nMasses];
 Double_t p1siglimitval20[nMasses];
 Double_t p1siglimitval40[nMasses];
 Double_t p1siglimitval60[nMasses];
 Double_t p1siglimitval100[nMasses];
 Double_t p1siglimitval125[nMasses];
 Double_t p1siglimitval150[nMasses];
 Double_t p1siglimitval175[nMasses];
 Double_t p1siglimitval200[nMasses];
 Double_t p1siglimitval250[nMasses];
 Double_t p1siglimitval300[nMasses];
 Double_t p1siglimitval350[nMasses];
 Double_t p1siglimitval400[nMasses];
 Double_t p1siglimitval450[nMasses];
 Double_t p1siglimitval500[nMasses];
 Double_t p1siglimitval600[nMasses];
 Double_t p1siglimitval700[nMasses];
 Double_t p1siglimitval800[nMasses];
 Double_t p1siglimitval900[nMasses];
 Double_t p1siglimitval1000[nMasses];

 Double_t n1siglimitval5[nMasses];
 Double_t n1siglimitval10[nMasses];
 Double_t n1siglimitval20[nMasses];
 Double_t n1siglimitval40[nMasses];
 Double_t n1siglimitval60[nMasses];
 Double_t n1siglimitval100[nMasses];
 Double_t n1siglimitval125[nMasses];
 Double_t n1siglimitval150[nMasses];
 Double_t n1siglimitval175[nMasses];
 Double_t n1siglimitval200[nMasses];
 Double_t n1siglimitval250[nMasses];
 Double_t n1siglimitval300[nMasses];
 Double_t n1siglimitval350[nMasses];
 Double_t n1siglimitval400[nMasses];
 Double_t n1siglimitval450[nMasses];
 Double_t n1siglimitval500[nMasses];
 Double_t n1siglimitval600[nMasses];
 Double_t n1siglimitval700[nMasses];
 Double_t n1siglimitval800[nMasses];
 Double_t n1siglimitval900[nMasses];
 Double_t n1siglimitval1000[nMasses];

 Double_t xsec5[nMasses];
 Double_t xsec10[nMasses];
 Double_t xsec20[nMasses];
 Double_t xsec40[nMasses];
 Double_t xsec60[nMasses];
 Double_t xsec100[nMasses];
 Double_t xsec125[nMasses];
 Double_t xsec150[nMasses];
 Double_t xsec175[nMasses];
 Double_t xsec200[nMasses];
 Double_t xsec250[nMasses];
 Double_t xsec300[nMasses];
 Double_t xsec350[nMasses];
 Double_t xsec400[nMasses];
 Double_t xsec450[nMasses];
 Double_t xsec500[nMasses];
 Double_t xsec600[nMasses];
 Double_t xsec700[nMasses];
 Double_t xsec800[nMasses];
 Double_t xsec900[nMasses];
 Double_t xsec1000[nMasses]; 

 Double_t p1sigexplimit5[nMasses];
 Double_t p1sigexplimit10[nMasses];
 Double_t p1sigexplimit20[nMasses];
 Double_t p1sigexplimit40[nMasses];
 Double_t p1sigexplimit60[nMasses];
 Double_t p1sigexplimit100[nMasses];
 Double_t p1sigexplimit125[nMasses];
 Double_t p1sigexplimit150[nMasses];
 Double_t p1sigexplimit175[nMasses];
 Double_t p1sigexplimit200[nMasses];
 Double_t p1sigexplimit250[nMasses];
 Double_t p1sigexplimit300[nMasses];
 Double_t p1sigexplimit350[nMasses];
 Double_t p1sigexplimit400[nMasses];
 Double_t p1sigexplimit450[nMasses];
 Double_t p1sigexplimit500[nMasses];
 Double_t p1sigexplimit600[nMasses];
 Double_t p1sigexplimit700[nMasses];
 Double_t p1sigexplimit800[nMasses];
 Double_t p1sigexplimit900[nMasses];
 Double_t p1sigexplimit1000[nMasses]; 

 Double_t n1sigexplimit5[nMasses];
 Double_t n1sigexplimit10[nMasses];
 Double_t n1sigexplimit20[nMasses];
 Double_t n1sigexplimit40[nMasses];
 Double_t n1sigexplimit60[nMasses];
 Double_t n1sigexplimit100[nMasses];
 Double_t n1sigexplimit125[nMasses];
 Double_t n1sigexplimit150[nMasses];
 Double_t n1sigexplimit175[nMasses];
 Double_t n1sigexplimit200[nMasses];
 Double_t n1sigexplimit250[nMasses];
 Double_t n1sigexplimit300[nMasses];
 Double_t n1sigexplimit350[nMasses];
 Double_t n1sigexplimit400[nMasses];
 Double_t n1sigexplimit450[nMasses];
 Double_t n1sigexplimit500[nMasses];
 Double_t n1sigexplimit600[nMasses];
 Double_t n1sigexplimit700[nMasses];
 Double_t n1sigexplimit800[nMasses];
 Double_t n1sigexplimit900[nMasses];
 Double_t n1sigexplimit1000[nMasses]; 

 Double_t explimit5[nMasses];
 Double_t explimit10[nMasses];
 Double_t explimit20[nMasses];
 Double_t explimit40[nMasses];
 Double_t explimit60[nMasses];
 Double_t explimit100[nMasses];
 Double_t explimit125[nMasses];
 Double_t explimit150[nMasses];
 Double_t explimit175[nMasses];
 Double_t explimit200[nMasses];
 Double_t explimit250[nMasses];
 Double_t explimit300[nMasses];
 Double_t explimit350[nMasses];
 Double_t explimit400[nMasses];
 Double_t explimit450[nMasses];
 Double_t explimit500[nMasses];
 Double_t explimit600[nMasses];
 Double_t explimit700[nMasses];
 Double_t explimit800[nMasses];
 Double_t explimit900[nMasses];
 Double_t explimit1000[nMasses]; 

 Double_t obslimit5[nMasses];
 Double_t obslimit10[nMasses];
 Double_t obslimit20[nMasses];
 Double_t obslimit40[nMasses];
 Double_t obslimit60[nMasses];
 Double_t obslimit100[nMasses];
 Double_t obslimit125[nMasses];
 Double_t obslimit150[nMasses];
 Double_t obslimit175[nMasses];
 Double_t obslimit200[nMasses];
 Double_t obslimit250[nMasses];
 Double_t obslimit300[nMasses];
 Double_t obslimit350[nMasses];
 Double_t obslimit400[nMasses];
 Double_t obslimit450[nMasses];
 Double_t obslimit500[nMasses];
 Double_t obslimit600[nMasses];
 Double_t obslimit700[nMasses];
 Double_t obslimit800[nMasses];
 Double_t obslimit900[nMasses];
 Double_t obslimit1000[nMasses]; 

 TGraph2D *g2d = new TGraph2D();
 TGraph2D *g2d_exp = new TGraph2D();
 TGraph2D *g2d_copy = new TGraph2D();
 TGraph2D *g2d_exp_copy = new TGraph2D();
 TGraph2D *g2d_exp_p1sig = new TGraph2D();
 TGraph2D *g2d_exp_n1sig = new TGraph2D();

 // std::cout<<"debug1"<<std::endl;
 for (Int_t n=0; n<nMasses; n++){
   getLimits(higgsCombineFiles_Mchi5[n],p1siglimitval5[n],0.84); 
   getLimits(higgsCombineFiles_Mchi10[n],p1siglimitval10[n],0.84); 
   getLimits(higgsCombineFiles_Mchi20[n],p1siglimitval20[n],0.84); 
   getLimits(higgsCombineFiles_Mchi40[n],p1siglimitval40[n],0.84); 
   getLimits(higgsCombineFiles_Mchi60[n],p1siglimitval60[n],0.84); 
   getLimits(higgsCombineFiles_Mchi100[n],p1siglimitval100[n],0.84); 
   getLimits(higgsCombineFiles_Mchi125[n],p1siglimitval125[n],0.84); 
   getLimits(higgsCombineFiles_Mchi150[n],p1siglimitval150[n],0.84); 
   getLimits(higgsCombineFiles_Mchi175[n],p1siglimitval175[n],0.84); 
   getLimits(higgsCombineFiles_Mchi200[n],p1siglimitval200[n],0.84); 
   getLimits(higgsCombineFiles_Mchi250[n],p1siglimitval250[n],0.84); 
   getLimits(higgsCombineFiles_Mchi300[n],p1siglimitval300[n],0.84); 
   getLimits(higgsCombineFiles_Mchi350[n],p1siglimitval350[n],0.84); 
   getLimits(higgsCombineFiles_Mchi400[n],p1siglimitval400[n],0.84); 
   getLimits(higgsCombineFiles_Mchi450[n],p1siglimitval450[n],0.84); 
   getLimits(higgsCombineFiles_Mchi500[n],p1siglimitval500[n],0.84); 
   getLimits(higgsCombineFiles_Mchi600[n],p1siglimitval600[n],0.84); 
   getLimits(higgsCombineFiles_Mchi700[n],p1siglimitval700[n],0.84); 
   getLimits(higgsCombineFiles_Mchi800[n],p1siglimitval800[n],0.84); 
   getLimits(higgsCombineFiles_Mchi900[n],p1siglimitval900[n],0.84); 
   getLimits(higgsCombineFiles_Mchi1000[n],p1siglimitval1000[n],0.84); 

   getLimits(higgsCombineFiles_Mchi5[n],n1siglimitval5[n],0.16); 
   getLimits(higgsCombineFiles_Mchi10[n],n1siglimitval10[n],0.16); 
   getLimits(higgsCombineFiles_Mchi20[n],n1siglimitval20[n],0.16); 
   getLimits(higgsCombineFiles_Mchi40[n],n1siglimitval40[n],0.16); 
   getLimits(higgsCombineFiles_Mchi60[n],n1siglimitval60[n],0.16); 
   getLimits(higgsCombineFiles_Mchi100[n],n1siglimitval100[n],0.16); 
   getLimits(higgsCombineFiles_Mchi125[n],n1siglimitval125[n],0.16); 
   getLimits(higgsCombineFiles_Mchi150[n],n1siglimitval150[n],0.16); 
   getLimits(higgsCombineFiles_Mchi175[n],n1siglimitval175[n],0.16); 
   getLimits(higgsCombineFiles_Mchi200[n],n1siglimitval200[n],0.16); 
   getLimits(higgsCombineFiles_Mchi250[n],n1siglimitval250[n],0.16); 
   getLimits(higgsCombineFiles_Mchi300[n],n1siglimitval300[n],0.16); 
   getLimits(higgsCombineFiles_Mchi350[n],n1siglimitval350[n],0.16); 
   getLimits(higgsCombineFiles_Mchi400[n],n1siglimitval400[n],0.16); 
   getLimits(higgsCombineFiles_Mchi450[n],n1siglimitval450[n],0.16); 
   getLimits(higgsCombineFiles_Mchi500[n],n1siglimitval500[n],0.16); 
   getLimits(higgsCombineFiles_Mchi600[n],n1siglimitval600[n],0.16); 
   getLimits(higgsCombineFiles_Mchi700[n],n1siglimitval700[n],0.16); 
   getLimits(higgsCombineFiles_Mchi800[n],n1siglimitval800[n],0.16); 
   getLimits(higgsCombineFiles_Mchi900[n],n1siglimitval900[n],0.16); 
   getLimits(higgsCombineFiles_Mchi1000[n],n1siglimitval1000[n],0.16); 

   getLimits(higgsCombineFiles_Mchi5[n],limitval5[n],0.5); 
   getLimits(higgsCombineFiles_Mchi10[n],limitval10[n],0.5); 
   getLimits(higgsCombineFiles_Mchi20[n],limitval20[n],0.5); 
   getLimits(higgsCombineFiles_Mchi40[n],limitval40[n],0.5); 
   getLimits(higgsCombineFiles_Mchi60[n],limitval60[n],0.5); 
   getLimits(higgsCombineFiles_Mchi100[n],limitval100[n],0.5); 
   getLimits(higgsCombineFiles_Mchi125[n],limitval125[n],0.5); 
   getLimits(higgsCombineFiles_Mchi150[n],limitval150[n],0.5); 
   getLimits(higgsCombineFiles_Mchi175[n],limitval175[n],0.5); 
   getLimits(higgsCombineFiles_Mchi200[n],limitval200[n],0.5); 
   getLimits(higgsCombineFiles_Mchi250[n],limitval250[n],0.5); 
   getLimits(higgsCombineFiles_Mchi300[n],limitval300[n],0.5); 
   getLimits(higgsCombineFiles_Mchi350[n],limitval350[n],0.5); 
   getLimits(higgsCombineFiles_Mchi400[n],limitval400[n],0.5); 
   getLimits(higgsCombineFiles_Mchi450[n],limitval450[n],0.5); 
   getLimits(higgsCombineFiles_Mchi500[n],limitval500[n],0.5); 
   getLimits(higgsCombineFiles_Mchi600[n],limitval600[n],0.5); 
   getLimits(higgsCombineFiles_Mchi700[n],limitval700[n],0.5); 
   getLimits(higgsCombineFiles_Mchi800[n],limitval800[n],0.5); 
   getLimits(higgsCombineFiles_Mchi900[n],limitval900[n],0.5); 
   getLimits(higgsCombineFiles_Mchi1000[n],limitval1000[n],0.5); 

   getLimits(higgsCombineFiles_Mchi5[n],limitval5_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi10[n],limitval10_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi20[n],limitval20_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi40[n],limitval40_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi60[n],limitval60_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi100[n],limitval100_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi125[n],limitval125_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi150[n],limitval150_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi175[n],limitval175_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi200[n],limitval200_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi250[n],limitval250_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi300[n],limitval300_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi350[n],limitval350_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi400[n],limitval400_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi450[n],limitval450_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi500[n],limitval500_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi600[n],limitval600_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi700[n],limitval700_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi800[n],limitval800_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi900[n],limitval900_obs[n], -1.); 
   getLimits(higgsCombineFiles_Mchi1000[n],limitval1000_obs[n], -1.); 
  

   //std::cout<<"***********************Printing XSEC*************************"<<std::endl;

   getXsecBaryo(theory,5,(Int_t)mass[n],xsec5[n]);
   getXsecBaryo(theory,10,(Int_t)mass[n],xsec10[n]);
   getXsecBaryo(theory,20,(Int_t)mass[n],xsec20[n]);
   getXsecBaryo(theory,40,(Int_t)mass[n],xsec40[n]);
   getXsecBaryo(theory,60,(Int_t)mass[n],xsec60[n]);
   getXsecBaryo(theory,100,(Int_t)mass[n],xsec100[n]);
   getXsecBaryo(theory,125,(Int_t)mass[n],xsec125[n]);
   getXsecBaryo(theory,150,(Int_t)mass[n],xsec150[n]);
   getXsecBaryo(theory,175,(Int_t)mass[n],xsec175[n]);
   getXsecBaryo(theory,200,(Int_t)mass[n],xsec200[n]);
   getXsecBaryo(theory,250,(Int_t)mass[n],xsec250[n]);
   getXsecBaryo(theory,300,(Int_t)mass[n],xsec300[n]);
   getXsecBaryo(theory,350,(Int_t)mass[n],xsec350[n]);
   getXsecBaryo(theory,400,(Int_t)mass[n],xsec400[n]);
   getXsecBaryo(theory,450,(Int_t)mass[n],xsec450[n]);
   getXsecBaryo(theory,500,(Int_t)mass[n],xsec500[n]);
   getXsecBaryo(theory,600,(Int_t)mass[n],xsec600[n]);
   getXsecBaryo(theory,700,(Int_t)mass[n],xsec700[n]);
   getXsecBaryo(theory,800,(Int_t)mass[n],xsec800[n]);
   getXsecBaryo(theory,900,(Int_t)mass[n],xsec900[n]);
   getXsecBaryo(theory,1000,(Int_t)mass[n],xsec1000[n]);

   p1sigexplimit5[n] = p1siglimitval5[n]/xsec5[n];
   p1sigexplimit10[n] = p1siglimitval10[n]/xsec10[n];
   p1sigexplimit20[n] = p1siglimitval20[n]/xsec20[n];
   p1sigexplimit40[n] = p1siglimitval40[n]/xsec40[n];
   p1sigexplimit60[n] = p1siglimitval60[n]/xsec60[n];
   p1sigexplimit100[n] = p1siglimitval100[n]/xsec100[n];
   p1sigexplimit125[n] = p1siglimitval125[n]/xsec125[n];
   p1sigexplimit150[n] = p1siglimitval150[n]/xsec150[n];
   p1sigexplimit175[n] = p1siglimitval175[n]/xsec175[n];
   p1sigexplimit200[n] = p1siglimitval200[n]/xsec200[n]; 
   p1sigexplimit250[n] = p1siglimitval250[n]/xsec250[n];
   p1sigexplimit300[n] = p1siglimitval300[n]/xsec300[n];
   p1sigexplimit350[n] = p1siglimitval350[n]/xsec350[n];
   p1sigexplimit400[n] = p1siglimitval400[n]/xsec400[n];
   p1sigexplimit450[n] = p1siglimitval450[n]/xsec450[n];
   p1sigexplimit500[n] = p1siglimitval500[n]/xsec500[n];
   p1sigexplimit600[n] = p1siglimitval600[n]/xsec600[n];
   p1sigexplimit700[n] = p1siglimitval700[n]/xsec700[n];
   p1sigexplimit800[n] = p1siglimitval800[n]/xsec800[n];
   p1sigexplimit900[n] = p1siglimitval900[n]/xsec900[n];
   p1sigexplimit1000[n] = p1siglimitval1000[n]/xsec1000[n];

   n1sigexplimit5[n]    = n1siglimitval5[n]/xsec5[n];
   n1sigexplimit10[n]   = n1siglimitval10[n]/xsec10[n];
   n1sigexplimit20[n]   = n1siglimitval20[n]/xsec20[n];
   n1sigexplimit40[n]   = n1siglimitval40[n]/xsec40[n];
   n1sigexplimit60[n]   = n1siglimitval60[n]/xsec60[n];
   n1sigexplimit100[n]  = n1siglimitval100[n]/xsec100[n];
   n1sigexplimit125[n]  = n1siglimitval125[n]/xsec125[n];
   n1sigexplimit150[n]  = n1siglimitval150[n]/xsec150[n];
   n1sigexplimit175[n]  = n1siglimitval175[n]/xsec175[n];
   n1sigexplimit200[n]  = n1siglimitval200[n]/xsec200[n]; 
   n1sigexplimit250[n]  = n1siglimitval250[n]/xsec250[n];
   n1sigexplimit300[n]  = n1siglimitval300[n]/xsec300[n];
   n1sigexplimit350[n]  = n1siglimitval350[n]/xsec350[n];
   n1sigexplimit400[n]  = n1siglimitval400[n]/xsec400[n];
   n1sigexplimit450[n]  = n1siglimitval450[n]/xsec450[n];
   n1sigexplimit500[n]  = n1siglimitval500[n]/xsec500[n];
   n1sigexplimit600[n]  = n1siglimitval600[n]/xsec600[n];
   n1sigexplimit700[n]  = n1siglimitval700[n]/xsec700[n];
   n1sigexplimit800[n]  = n1siglimitval800[n]/xsec800[n];
   n1sigexplimit900[n]  = n1siglimitval900[n]/xsec900[n];
   n1sigexplimit1000[n] = n1siglimitval1000[n]/xsec1000[n];

   explimit5[n]    = limitval5[n]/xsec5[n];
   explimit10[n]   = limitval10[n]/xsec10[n];
   explimit20[n]   = limitval20[n]/xsec20[n];
   explimit40[n]   = limitval40[n]/xsec40[n];
   explimit60[n]   = limitval60[n]/xsec60[n];
   explimit100[n]  = limitval100[n]/xsec100[n];
   explimit125[n]  = limitval125[n]/xsec125[n];
   explimit150[n]  = limitval150[n]/xsec150[n];
   explimit175[n]  = limitval175[n]/xsec175[n];
   explimit200[n]  = limitval200[n]/xsec200[n]; 
   explimit250[n]  = limitval250[n]/xsec250[n];
   explimit300[n]  = limitval300[n]/xsec300[n];
   explimit350[n]  = limitval350[n]/xsec350[n];
   explimit400[n]  = limitval400[n]/xsec400[n];
   explimit450[n]  = limitval450[n]/xsec450[n];
   explimit500[n]  = limitval500[n]/xsec500[n];
   explimit600[n]  = limitval600[n]/xsec600[n];
   explimit700[n]  = limitval700[n]/xsec700[n];
   explimit800[n]  = limitval800[n]/xsec800[n];
   explimit900[n]  = limitval900[n]/xsec900[n];
   explimit1000[n] = limitval1000[n]/xsec1000[n];

   obslimit5[n] = limitval5_obs[n]/xsec5[n];
   obslimit10[n] = limitval10_obs[n]/xsec10[n];
   obslimit20[n] = limitval20_obs[n]/xsec20[n];
   obslimit40[n] = limitval40_obs[n]/xsec40[n];
   obslimit60[n] = limitval60_obs[n]/xsec60[n];
   obslimit100[n] = limitval100_obs[n]/xsec100[n];
   obslimit125[n] = limitval125_obs[n]/xsec125[n];
   obslimit150[n] = limitval150_obs[n]/xsec150[n];
   obslimit175[n] = limitval175_obs[n]/xsec175[n];
   obslimit200[n] = limitval200_obs[n]/xsec200[n]; 
   obslimit250[n] = limitval250_obs[n]/xsec250[n];
   obslimit300[n] = limitval300_obs[n]/xsec300[n];
   obslimit350[n] = limitval350_obs[n]/xsec350[n];
   obslimit400[n] = limitval400_obs[n]/xsec400[n];
   obslimit450[n] = limitval450_obs[n]/xsec450[n];
   obslimit500[n] = limitval500_obs[n]/xsec500[n];
   obslimit600[n] = limitval600_obs[n]/xsec600[n];
   obslimit700[n] = limitval700_obs[n]/xsec700[n];
   obslimit800[n] = limitval800_obs[n]/xsec800[n];
   obslimit900[n] = limitval900_obs[n]/xsec900[n];
   obslimit1000[n] = limitval1000_obs[n]/xsec1000[n];

   /*
   if(limitval1[n]==0) limits->SetBinContent(((Double_t)n+0.5),0.5,0);
   if(limitval1[n]==0) limits->SetBinError(((Double_t)n+0.5),0.5,0);
   if(limitval10[n]==0) limits->SetBinContent(((Double_t)n+0.5),0.5,0);
   if(limitval10[n]==0) limits->SetBinError(((Double_t)n+0.5),0.5,0);
   if(limitval40[n]==0) limits->SetBinContent(((Double_t)n+0.5),0.5,0);
   if(limitval40[n]==0) limits->SetBinError(((Double_t)n+0.5),0.5,0);
   if(limitval150[n]==0) limits->SetBinContent(((Double_t)n+0.5),0.5,0);
   if(limitval150[n]==0) limits->SetBinError(((Double_t)n+0.5),0.5,0);
   if(limitval500[n]==0) limits->SetBinContent(((Double_t)n+0.5),0.5,0);
   if(limitval500[n]==0) limits->SetBinError(((Double_t)n+0.5),0.5,0);
   if(limitval1000[n]==0) limits->SetBinContent(((Double_t)n+0.5),0.5,0);
   if(limitval1000[n]==0) limits->SetBinError(((Double_t)n+0.5),0.5,0);
   */


   // fill limit plot
   limits->Fill(mass[n],5,limitval5[n]/xsec5[n]);
   limits->Fill(mass[n],10,limitval10[n]/xsec10[n]);
   limits->Fill(mass[n],20,limitval20[n]/xsec20[n]);
   limits->Fill(mass[n],40,limitval40[n]/xsec40[n]);
   limits->Fill(mass[n],60,limitval60[n]/xsec60[n]);
   limits->Fill(mass[n],100,limitval100[n]/xsec100[n]);
   limits->Fill(mass[n],125,limitval125[n]/xsec125[n]);
   limits->Fill(mass[n],150,limitval150[n]/xsec150[n]);
   limits->Fill(mass[n],175,limitval175[n]/xsec175[n]);
   limits->Fill(mass[n],200,limitval200[n]/xsec200[n]);
   limits->Fill(mass[n],250,limitval250[n]/xsec250[n]);
   limits->Fill(mass[n],300,limitval300[n]/xsec300[n]);
   limits->Fill(mass[n],350,limitval350[n]/xsec350[n]);
   limits->Fill(mass[n],400,limitval400[n]/xsec400[n]);
   limits->Fill(mass[n],450,limitval450[n]/xsec450[n]);
   limits->Fill(mass[n],500,limitval500[n]/xsec500[n]);
   limits->Fill(mass[n],600,limitval600[n]/xsec600[n]);
   limits->Fill(mass[n],700,limitval700[n]/xsec700[n]);
   limits->Fill(mass[n],800,limitval800[n]/xsec800[n]);
   limits->Fill(mass[n],900,limitval900[n]/xsec900[n]);
   limits->Fill(mass[n],1000,limitval1000[n]/xsec1000[n]);

   obslimits->Fill(mass[n],5,limitval5_obs[n]/xsec5[n]);
   obslimits->Fill(mass[n],10,limitval10_obs[n]/xsec10[n]);
   obslimits->Fill(mass[n],20,limitval20_obs[n]/xsec20[n]);
   obslimits->Fill(mass[n],40,limitval40_obs[n]/xsec40[n]);
   obslimits->Fill(mass[n],60,limitval60_obs[n]/xsec60[n]);
   obslimits->Fill(mass[n],100,limitval100_obs[n]/xsec100[n]);
   obslimits->Fill(mass[n],125,limitval125_obs[n]/xsec125[n]);
   obslimits->Fill(mass[n],150,limitval150_obs[n]/xsec150[n]);
   obslimits->Fill(mass[n],175,limitval175_obs[n]/xsec175[n]);
   obslimits->Fill(mass[n],200,limitval200_obs[n]/xsec200[n]);
   obslimits->Fill(mass[n],250,limitval250_obs[n]/xsec250[n]);
   obslimits->Fill(mass[n],300,limitval300_obs[n]/xsec300[n]);
   obslimits->Fill(mass[n],350,limitval350_obs[n]/xsec350[n]);
   obslimits->Fill(mass[n],400,limitval400_obs[n]/xsec400[n]);
   obslimits->Fill(mass[n],450,limitval450_obs[n]/xsec450[n]);
   obslimits->Fill(mass[n],500,limitval500_obs[n]/xsec500[n]);
   obslimits->Fill(mass[n],600,limitval600_obs[n]/xsec600[n]);
   obslimits->Fill(mass[n],700,limitval700_obs[n]/xsec700[n]);
   obslimits->Fill(mass[n],800,limitval800_obs[n]/xsec800[n]);
   obslimits->Fill(mass[n],900,limitval900_obs[n]/xsec900[n]);
   obslimits->Fill(mass[n],1000,limitval1000_obs[n]/xsec1000[n]);


   g2d->SetPoint(0+21*n,mass[n],5,limitval5_obs[n]/xsec5[n]);
   g2d->SetPoint(1+21*n,mass[n],10,limitval10_obs[n]/xsec10[n]);
   g2d->SetPoint(2+21*n,mass[n],20,limitval20_obs[n]/xsec20[n]);
   g2d->SetPoint(3+21*n,mass[n],40,limitval40_obs[n]/xsec40[n]);
   g2d->SetPoint(4+21*n,mass[n],60,limitval60_obs[n]/xsec60[n]);
   g2d->SetPoint(5+21*n,mass[n],100,limitval100_obs[n]/xsec100[n]);
   g2d->SetPoint(6+21*n,mass[n],125,limitval125_obs[n]/xsec125[n]);
   g2d->SetPoint(7+21*n,mass[n],150,limitval150_obs[n]/xsec150[n]);
   g2d->SetPoint(8+21*n,mass[n],175,limitval175_obs[n]/xsec175[n]);
   g2d->SetPoint(9+21*n,mass[n],200,limitval200_obs[n]/xsec200[n]);
   g2d->SetPoint(10+21*n,mass[n],250,limitval250_obs[n]/xsec250[n]);
   g2d->SetPoint(11+21*n,mass[n],300,limitval300_obs[n]/xsec300[n]);
   g2d->SetPoint(12+21*n,mass[n],350,limitval350_obs[n]/xsec350[n]);
   g2d->SetPoint(13+21*n,mass[n],400,limitval400_obs[n]/xsec400[n]);
   g2d->SetPoint(14+21*n,mass[n],450,limitval450_obs[n]/xsec450[n]);
   g2d->SetPoint(15+21*n,mass[n],500,limitval500_obs[n]/xsec500[n]);
   g2d->SetPoint(16+21*n,mass[n],600,limitval600_obs[n]/xsec600[n]);
   g2d->SetPoint(17+21*n,mass[n],700,limitval700_obs[n]/xsec700[n]);
   g2d->SetPoint(18+21*n,mass[n],800,limitval800_obs[n]/xsec800[n]);
   g2d->SetPoint(19+21*n,mass[n],900,limitval900_obs[n]/xsec900[n]);
   g2d->SetPoint(20+21*n,mass[n],1000,limitval1000_obs[n]/xsec1000[n]);

   g2d_exp->SetPoint(0+21*n,mass[n],5,limitval5[n]/xsec5[n]);
   g2d_exp->SetPoint(1+21*n,mass[n],10,limitval10[n]/xsec10[n]);
   g2d_exp->SetPoint(2+21*n,mass[n],20,limitval20[n]/xsec20[n]);
   g2d_exp->SetPoint(3+21*n,mass[n],40,limitval40[n]/xsec40[n]);
   g2d_exp->SetPoint(4+21*n,mass[n],60,limitval60[n]/xsec60[n]);
   g2d_exp->SetPoint(5+21*n,mass[n],100,limitval100[n]/xsec100[n]);
   g2d_exp->SetPoint(6+21*n,mass[n],125,limitval125[n]/xsec125[n]);
   g2d_exp->SetPoint(7+21*n,mass[n],150,limitval150[n]/xsec150[n]);
   g2d_exp->SetPoint(8+21*n,mass[n],175,limitval175[n]/xsec175[n]);
   g2d_exp->SetPoint(9+21*n,mass[n],200,limitval200[n]/xsec200[n]);
   g2d_exp->SetPoint(10+21*n,mass[n],250,limitval250[n]/xsec250[n]);
   g2d_exp->SetPoint(11+21*n,mass[n],300,limitval300[n]/xsec300[n]);
   g2d_exp->SetPoint(12+21*n,mass[n],350,limitval350[n]/xsec350[n]);
   g2d_exp->SetPoint(13+21*n,mass[n],400,limitval400[n]/xsec400[n]);
   g2d_exp->SetPoint(14+21*n,mass[n],450,limitval450[n]/xsec450[n]);
   g2d_exp->SetPoint(15+21*n,mass[n],500,limitval500[n]/xsec500[n]);
   g2d_exp->SetPoint(16+21*n,mass[n],600,limitval600[n]/xsec600[n]);
   g2d_exp->SetPoint(17+21*n,mass[n],700,limitval700[n]/xsec700[n]);
   g2d_exp->SetPoint(18+21*n,mass[n],800,limitval800[n]/xsec800[n]);
   g2d_exp->SetPoint(19+21*n,mass[n],900,limitval900[n]/xsec900[n]);
   g2d_exp->SetPoint(20+21*n,mass[n],1000,limitval1000[n]/xsec1000[n]);

   g2d_copy->SetPoint(0+21*n,mass[n],5,limitval5_obs[n]/xsec5[n]);
   g2d_copy->SetPoint(1+21*n,mass[n],10,limitval10_obs[n]/xsec10[n]);
   g2d_copy->SetPoint(2+21*n,mass[n],20,limitval20_obs[n]/xsec20[n]);
   g2d_copy->SetPoint(3+21*n,mass[n],40,limitval40_obs[n]/xsec40[n]);
   g2d_copy->SetPoint(4+21*n,mass[n],60,limitval60_obs[n]/xsec60[n]);
   g2d_copy->SetPoint(5+21*n,mass[n],100,limitval100_obs[n]/xsec100[n]);
   g2d_copy->SetPoint(6+21*n,mass[n],125,limitval125_obs[n]/xsec125[n]);
   g2d_copy->SetPoint(7+21*n,mass[n],150,limitval150_obs[n]/xsec150[n]);
   g2d_copy->SetPoint(8+21*n,mass[n],175,limitval175_obs[n]/xsec175[n]);
   g2d_copy->SetPoint(9+21*n,mass[n],200,limitval200_obs[n]/xsec200[n]);
   g2d_copy->SetPoint(10+21*n,mass[n],250,limitval250_obs[n]/xsec250[n]);
   g2d_copy->SetPoint(11+21*n,mass[n],300,limitval300_obs[n]/xsec300[n]);
   g2d_copy->SetPoint(12+21*n,mass[n],350,limitval350_obs[n]/xsec350[n]);
   g2d_copy->SetPoint(13+21*n,mass[n],400,limitval400_obs[n]/xsec400[n]);
   g2d_copy->SetPoint(14+21*n,mass[n],450,limitval450_obs[n]/xsec450[n]);
   g2d_copy->SetPoint(15+21*n,mass[n],500,limitval500_obs[n]/xsec500[n]);
   g2d_copy->SetPoint(16+21*n,mass[n],600,limitval600_obs[n]/xsec600[n]);
   g2d_copy->SetPoint(17+21*n,mass[n],700,limitval700_obs[n]/xsec700[n]);
   g2d_copy->SetPoint(18+21*n,mass[n],800,limitval800_obs[n]/xsec800[n]);
   g2d_copy->SetPoint(19+21*n,mass[n],900,limitval900_obs[n]/xsec900[n]);
   g2d_copy->SetPoint(20+21*n,mass[n],1000,limitval1000_obs[n]/xsec1000[n]);

   g2d_exp_copy->SetPoint(0+21*n,mass[n],5,limitval5[n]/xsec5[n]);
   g2d_exp_copy->SetPoint(1+21*n,mass[n],10,limitval10[n]/xsec10[n]);
   g2d_exp_copy->SetPoint(2+21*n,mass[n],20,limitval20[n]/xsec20[n]);
   g2d_exp_copy->SetPoint(3+21*n,mass[n],40,limitval40[n]/xsec40[n]);
   g2d_exp_copy->SetPoint(4+21*n,mass[n],60,limitval60[n]/xsec60[n]);
   g2d_exp_copy->SetPoint(5+21*n,mass[n],100,limitval100[n]/xsec100[n]);
   g2d_exp_copy->SetPoint(6+21*n,mass[n],125,limitval125[n]/xsec125[n]);
   g2d_exp_copy->SetPoint(7+21*n,mass[n],150,limitval150[n]/xsec150[n]);
   g2d_exp_copy->SetPoint(8+21*n,mass[n],175,limitval175[n]/xsec175[n]);
   g2d_exp_copy->SetPoint(9+21*n,mass[n],200,limitval200[n]/xsec200[n]);
   g2d_exp_copy->SetPoint(10+21*n,mass[n],250,limitval250[n]/xsec250[n]);
   g2d_exp_copy->SetPoint(11+21*n,mass[n],300,limitval300[n]/xsec300[n]);
   g2d_exp_copy->SetPoint(12+21*n,mass[n],350,limitval350[n]/xsec350[n]);
   g2d_exp_copy->SetPoint(13+21*n,mass[n],400,limitval400[n]/xsec400[n]);
   g2d_exp_copy->SetPoint(14+21*n,mass[n],450,limitval450[n]/xsec450[n]);
   g2d_exp_copy->SetPoint(15+21*n,mass[n],500,limitval500[n]/xsec500[n]);
   g2d_exp_copy->SetPoint(16+21*n,mass[n],600,limitval600[n]/xsec600[n]);
   g2d_exp_copy->SetPoint(17+21*n,mass[n],700,limitval700[n]/xsec700[n]);
   g2d_exp_copy->SetPoint(18+21*n,mass[n],800,limitval800[n]/xsec800[n]);
   g2d_exp_copy->SetPoint(19+21*n,mass[n],900,limitval900[n]/xsec900[n]);
   g2d_exp_copy->SetPoint(20+21*n,mass[n],1000,limitval1000[n]/xsec1000[n]);

   g2d_exp_p1sig->SetPoint(0+21*n,mass[n],5,p1siglimitval5[n]/xsec5[n]);
   g2d_exp_p1sig->SetPoint(1+21*n,mass[n],10,p1siglimitval10[n]/xsec10[n]);
   g2d_exp_p1sig->SetPoint(2+21*n,mass[n],20,p1siglimitval20[n]/xsec20[n]);
   g2d_exp_p1sig->SetPoint(3+21*n,mass[n],40,p1siglimitval40[n]/xsec40[n]);
   g2d_exp_p1sig->SetPoint(4+21*n,mass[n],60,p1siglimitval60[n]/xsec60[n]);
   g2d_exp_p1sig->SetPoint(5+21*n,mass[n],100,p1siglimitval100[n]/xsec100[n]);
   g2d_exp_p1sig->SetPoint(6+21*n,mass[n],125,p1siglimitval125[n]/xsec125[n]);
   g2d_exp_p1sig->SetPoint(7+21*n,mass[n],150,p1siglimitval150[n]/xsec150[n]);
   g2d_exp_p1sig->SetPoint(8+21*n,mass[n],175,p1siglimitval175[n]/xsec175[n]);
   g2d_exp_p1sig->SetPoint(9+21*n,mass[n],200,p1siglimitval200[n]/xsec200[n]);
   g2d_exp_p1sig->SetPoint(10+21*n,mass[n],250,p1siglimitval250[n]/xsec250[n]);
   g2d_exp_p1sig->SetPoint(11+21*n,mass[n],300,p1siglimitval300[n]/xsec300[n]);
   g2d_exp_p1sig->SetPoint(12+21*n,mass[n],350,p1siglimitval350[n]/xsec350[n]);
   g2d_exp_p1sig->SetPoint(13+21*n,mass[n],400,p1siglimitval400[n]/xsec400[n]);
   g2d_exp_p1sig->SetPoint(14+21*n,mass[n],450,p1siglimitval450[n]/xsec450[n]);
   g2d_exp_p1sig->SetPoint(15+21*n,mass[n],500,p1siglimitval500[n]/xsec500[n]);
   g2d_exp_p1sig->SetPoint(16+21*n,mass[n],600,p1siglimitval600[n]/xsec600[n]);
   g2d_exp_p1sig->SetPoint(17+21*n,mass[n],700,p1siglimitval700[n]/xsec700[n]);
   g2d_exp_p1sig->SetPoint(18+21*n,mass[n],800,p1siglimitval800[n]/xsec800[n]);
   g2d_exp_p1sig->SetPoint(19+21*n,mass[n],900,p1siglimitval900[n]/xsec900[n]);
   g2d_exp_p1sig->SetPoint(20+21*n,mass[n],1000,p1siglimitval1000[n]/xsec1000[n]);

   g2d_exp_n1sig->SetPoint(0+21*n,mass[n],5,n1siglimitval5[n]/xsec5[n]);
   g2d_exp_n1sig->SetPoint(1+21*n,mass[n],10,n1siglimitval10[n]/xsec10[n]);
   g2d_exp_n1sig->SetPoint(2+21*n,mass[n],20,n1siglimitval20[n]/xsec20[n]);
   g2d_exp_n1sig->SetPoint(3+21*n,mass[n],40,n1siglimitval40[n]/xsec40[n]);
   g2d_exp_n1sig->SetPoint(4+21*n,mass[n],60,n1siglimitval60[n]/xsec60[n]);
   g2d_exp_n1sig->SetPoint(5+21*n,mass[n],100,n1siglimitval100[n]/xsec100[n]);
   g2d_exp_n1sig->SetPoint(6+21*n,mass[n],125,n1siglimitval125[n]/xsec125[n]);
   g2d_exp_n1sig->SetPoint(7+21*n,mass[n],150,n1siglimitval150[n]/xsec150[n]);
   g2d_exp_n1sig->SetPoint(8+21*n,mass[n],175,n1siglimitval175[n]/xsec175[n]);
   g2d_exp_n1sig->SetPoint(9+21*n,mass[n],200,n1siglimitval200[n]/xsec200[n]);
   g2d_exp_n1sig->SetPoint(10+21*n,mass[n],250,n1siglimitval250[n]/xsec250[n]);
   g2d_exp_n1sig->SetPoint(11+21*n,mass[n],300,n1siglimitval300[n]/xsec300[n]);
   g2d_exp_n1sig->SetPoint(12+21*n,mass[n],350,n1siglimitval350[n]/xsec350[n]);
   g2d_exp_n1sig->SetPoint(13+21*n,mass[n],400,n1siglimitval400[n]/xsec400[n]);
   g2d_exp_n1sig->SetPoint(14+21*n,mass[n],450,n1siglimitval450[n]/xsec450[n]);
   g2d_exp_n1sig->SetPoint(15+21*n,mass[n],500,n1siglimitval500[n]/xsec500[n]);
   g2d_exp_n1sig->SetPoint(16+21*n,mass[n],600,n1siglimitval600[n]/xsec600[n]);
   g2d_exp_n1sig->SetPoint(17+21*n,mass[n],700,n1siglimitval700[n]/xsec700[n]);
   g2d_exp_n1sig->SetPoint(18+21*n,mass[n],800,n1siglimitval800[n]/xsec800[n]);
   g2d_exp_n1sig->SetPoint(19+21*n,mass[n],900,n1siglimitval900[n]/xsec900[n]);
   g2d_exp_n1sig->SetPoint(20+21*n,mass[n],1000,n1siglimitval1000[n]/xsec1000[n]);

 }

 
 limit5 = new TGraph(nMasses,mass,explimit5);
 limit10 = new TGraph(25,mass,explimit10);
 limit20 = new TGraph(25,mass,explimit20);
 limit40 = new TGraph(25,mass,explimit40);
 limit60 = new TGraph(25,mass,explimit60);
 limit100 = new TGraph(25,mass,explimit100);
 limit125 = new TGraph(25,mass,explimit125);
 limit150 = new TGraph(25,mass,explimit150);
 limit175 = new TGraph(25,mass,explimit175);
 limit200 = new TGraph(25,mass,explimit200);
 limit250 = new TGraph(25,mass,explimit250);
 limit300 = new TGraph(25,mass,explimit300);
 limit350 = new TGraph(25,mass,explimit350);
 limit400 = new TGraph(25,mass,explimit400);
 limit450 = new TGraph(25,mass,explimit450);
 limit500 = new TGraph(25,mass,explimit500);
 limit600 = new TGraph(25,mass,explimit600);
 limit700 = new TGraph(25,mass,explimit700);
 limit800 = new TGraph(25,mass,explimit800);
 limit900 = new TGraph(25,mass,explimit900);
 limit1000 = new TGraph(25,mass,explimit1000);

 p1siglimit5    = new TGraph(nMasses,mass,p1sigexplimit5);
 p1siglimit10   = new TGraph(25,mass,p1sigexplimit10);
 p1siglimit20   = new TGraph(25,mass,p1sigexplimit20);
 p1siglimit40   = new TGraph(25,mass,p1sigexplimit40);
 p1siglimit60   = new TGraph(25,mass,p1sigexplimit60);
 p1siglimit100  = new TGraph(25,mass,p1sigexplimit100);
 p1siglimit125  = new TGraph(25,mass,p1sigexplimit125);
 p1siglimit150  = new TGraph(25,mass,p1sigexplimit150);
 p1siglimit175  = new TGraph(25,mass,p1sigexplimit175);
 p1siglimit200  = new TGraph(25,mass,p1sigexplimit200);
 p1siglimit250  = new TGraph(25,mass,p1sigexplimit250);
 p1siglimit300  = new TGraph(25,mass,p1sigexplimit300);
 p1siglimit350  = new TGraph(25,mass,p1sigexplimit350);
 p1siglimit400  = new TGraph(25,mass,p1sigexplimit400);
 p1siglimit450  = new TGraph(25,mass,p1sigexplimit450);
 p1siglimit500  = new TGraph(25,mass,p1sigexplimit500);
 p1siglimit600  = new TGraph(25,mass,p1sigexplimit600);
 p1siglimit700  = new TGraph(25,mass,p1sigexplimit700);
 p1siglimit800  = new TGraph(25,mass,p1sigexplimit800);
 p1siglimit900  = new TGraph(25,mass,p1sigexplimit900);
 p1siglimit1000 = new TGraph(25,mass,p1sigexplimit1000);

 n1siglimit5    = new TGraph(nMasses,mass,n1sigexplimit5);
 n1siglimit10   = new TGraph(25,mass,n1sigexplimit10);
 n1siglimit20   = new TGraph(25,mass,n1sigexplimit20);
 n1siglimit40   = new TGraph(25,mass,n1sigexplimit40);
 n1siglimit60   = new TGraph(25,mass,n1sigexplimit60);
 n1siglimit100  = new TGraph(25,mass,n1sigexplimit100);
 n1siglimit125  = new TGraph(25,mass,n1sigexplimit125);
 n1siglimit150  = new TGraph(25,mass,n1sigexplimit150);
 n1siglimit175  = new TGraph(25,mass,n1sigexplimit175);
 n1siglimit200  = new TGraph(25,mass,n1sigexplimit200);
 n1siglimit250  = new TGraph(25,mass,n1sigexplimit250);
 n1siglimit300  = new TGraph(25,mass,n1sigexplimit300);
 n1siglimit350  = new TGraph(25,mass,n1sigexplimit350);
 n1siglimit400  = new TGraph(25,mass,n1sigexplimit400);
 n1siglimit450  = new TGraph(25,mass,n1sigexplimit450);
 n1siglimit500  = new TGraph(25,mass,n1sigexplimit500);
 n1siglimit600  = new TGraph(25,mass,n1sigexplimit600);
 n1siglimit700  = new TGraph(25,mass,n1sigexplimit700);
 n1siglimit800  = new TGraph(25,mass,n1sigexplimit800);
 n1siglimit900  = new TGraph(25,mass,n1sigexplimit900);
 n1siglimit1000 = new TGraph(25,mass,n1sigexplimit1000);

 limit5_obs = new TGraph(nMasses,mass,obslimit5);
 limit10_obs = new TGraph(25,mass,obslimit10);
 limit20_obs = new TGraph(25,mass,obslimit20);
 limit40_obs = new TGraph(25,mass,obslimit40);
 limit60_obs = new TGraph(25,mass,obslimit60);
 limit100_obs = new TGraph(25,mass,obslimit100);
 limit125_obs = new TGraph(25,mass,obslimit125);
 limit150_obs = new TGraph(25,mass,obslimit150);
 limit175_obs = new TGraph(25,mass,obslimit175);
 limit200_obs = new TGraph(25,mass,obslimit200);
 limit250_obs = new TGraph(25,mass,obslimit250);
 limit300_obs = new TGraph(25,mass,obslimit300);
 limit350_obs = new TGraph(25,mass,obslimit350);
 limit400_obs = new TGraph(25,mass,obslimit400);
 limit450_obs = new TGraph(25,mass,obslimit450);
 limit500_obs = new TGraph(25,mass,obslimit500);
 limit600_obs = new TGraph(25,mass,obslimit600);
 limit700_obs = new TGraph(25,mass,obslimit700);
 limit800_obs = new TGraph(25,mass,obslimit800);
 limit900_obs = new TGraph(25,mass,obslimit900);
 limit1000_obs = new TGraph(25,mass,obslimit1000);

 
 //styling
 limit5->GetXaxis()->SetTitle("m_{Z'} [GeV]");
 limit5->GetYaxis()->SetTitle("#sigma_{95\% CL} / #sigma_{th}");
 limit5->SetTitle("");

 // set up colors to match Hbb
 limit5->SetLineColor(kBlack);
 limit10->SetLineColor(kCyan);
 limit20->SetLineColor(kCyan-7);
 limit40->SetLineColor(kOrange+8);
 limit60->SetLineColor(kAzure+10);
 limit100->SetLineColor(kGreen);
 limit125->SetLineColor(kBlue);
 limit150->SetLineColor(kRed);
 limit175->SetLineColor(kViolet);
 limit200->SetLineColor(kPink);
 limit250->SetLineColor(kYellow);
 limit300->SetLineColor(kOrange);
 limit350->SetLineColor(kBlack);
 limit400->SetLineColor(kMagenta);
 limit450->SetLineColor(kSpring);
 limit500->SetLineColor(kAzure);
 limit600->SetLineColor(kRed+7);
 limit700->SetLineColor(kBlue-9);
 limit800->SetLineColor(kBlue+4);
 limit900->SetLineColor(kYellow+8);
 limit1000->SetLineColor(kMagenta+4);


 //styling
 limit5_obs->GetXaxis()->SetTitle("m_{Z'} [GeV]");
 limit5_obs->GetYaxis()->SetTitle("#sigma_{95\% CL} / #sigma_{th}");
 limit5_obs->SetTitle("");
 
 // set up colors to match 
 limit5_obs->SetLineColor(kBlack);
 limit10_obs->SetLineColor(kCyan);
 limit20_obs->SetLineColor(kCyan-7);
 limit40_obs->SetLineColor(kOrange+8);
 limit60_obs->SetLineColor(kAzure+10);
 limit100_obs->SetLineColor(kGreen);
 limit125_obs->SetLineColor(kBlue);
 limit150_obs->SetLineColor(kRed);
 limit175_obs->SetLineColor(kViolet);
 limit200_obs->SetLineColor(kPink);
 limit250_obs->SetLineColor(kYellow);
 limit300_obs->SetLineColor(kOrange);
 limit350_obs->SetLineColor(kBlue-9);
 limit400_obs->SetLineColor(kMagenta);
 limit450_obs->SetLineColor(kSpring);
 limit500_obs->SetLineColor(kAzure);
 limit600_obs->SetLineColor(kRed+7);
 limit700_obs->SetLineColor(kBlue-9);
 limit800_obs->SetLineColor(kBlue+4);
 limit900_obs->SetLineColor(kYellow+8);
 limit1000_obs->SetLineColor(kMagenta+4);


 // draw 2Dexpected limits plot
 gStyle->SetPaintTextFormat("2.1e");
 gStyle->SetPalette(57);
 limits->Draw("COLZ TEXT"); 
 gStyle->SetPaintTextFormat("2.1e");
 c->SaveAs(Form("%s/limits2D_Baryo_exp_PARAMETRIC.png",outDir.Data()));
 c->SaveAs(Form("%s/limits2D_Baryo_exp_PARAMETRIC.pdf",outDir.Data()));

 // draw observed limits plot
 gStyle->SetPaintTextFormat("2.1e");
 gStyle->SetPalette(57);
 obslimits->Draw("COLZ TEXT"); 
 gStyle->SetPaintTextFormat("2.1e");
 c->cd();
 c->SaveAs(Form("%s/limits2D_Baryo_obs_PARAMETRIC.png",outDir.Data()));
 c->SaveAs(Form("%s/limits2D_Baryo_obs_PARAMETRIC.pdf",outDir.Data()));

 TLegend* leg = new TLegend(0.55,0.6,0.85,0.9,NULL,"brNDC"); // (x1,y1,x2,y2)
 leg->SetTextSize(0.046);
 leg->SetBorderSize(0);
 leg->SetLineColor(1);
 leg->SetLineWidth(1);
 leg->SetLineStyle(1);
 leg->SetFillColor(0);
 leg->SetFillStyle(0);
 leg->SetTextFont(62);
 leg->AddEntry(limit5,"m_{#chi} = 1 GeV","pl");
 leg->AddEntry(limit10,"m_{#chi} = 10 GeV","pl");
 leg->AddEntry(limit20,"m_{#chi} = 20 GeV","pl");
 leg->AddEntry(limit40,"m_{#chi} = 40 GeV","pl");
 leg->AddEntry(limit60,"m_{#chi} = 60 GeV","pl");

 leg->AddEntry(limit100,"m_{#chi} =100 GeV","pl");
 leg->AddEntry(limit125,"m_{#chi} =125 GeV","pl");
 leg->AddEntry(limit150,"m_{#chi} =150 GeV","pl");
 leg->AddEntry(limit175,"m_{#chi} =175 GeV","pl");
 leg->AddEntry(limit200,"m_{#chi} =200 GeV","pl");
 leg->AddEntry(limit250,"m_{#chi} =250 GeV","pl");
 leg->AddEntry(limit300,"m_{#chi} =300 GeV","pl");
 leg->AddEntry(limit350,"m_{#chi} =350 GeV","pl");
 leg->AddEntry(limit400,"m_{#chi} =400 GeV","pl");
 leg->AddEntry(limit450,"m_{#chi} =450 GeV","pl");
 /* leg->AddEntry(limit500,"m_{#chi} =500 GeV","pl");
 leg->AddEntry(limit600,"m_{#chi} =600 GeV","pl");
 leg->AddEntry(limit700,"m_{#chi} =700 GeV","pl");
 leg->AddEntry(limit800,"m_{#chi} =800 GeV","pl");
 leg->AddEntry(limit900,"m_{#chi} =900 GeV","pl");
 leg->AddEntry(limit1000,"m_{#chi} = 1000 GeV","pl");
 */leg->SetTextSize(0.03);

 TLine* line1 = new TLine();
 line1->SetX1(limit5->GetXaxis()->GetXmin());
 line1->SetY1(1.0);
 line1->SetX2(10050);
 line1->SetY2(1.0);
 line1->SetLineColor(kRed);
 line1->SetLineWidth(2);

 // draw 1D comparisons --expected
 limit5->GetYaxis()->SetRangeUser(0.1, 1000000000000);
 limit5->GetXaxis()->SetRangeUser(0.1, 10000);
 limit5->Draw("AL");
 // limit1->GetYaxis()->SetRangeUser(0.1, 1000);
 limit10->Draw("PL SAME");
 limit20->Draw("PL SAME");
 limit40->Draw("PL SAME");
 limit60->Draw("PL SAME");

 limit100->Draw("PL SAME");
 limit125->Draw("PL SAME");
 limit150->Draw("PL SAME");
 limit175->Draw("PL SAME");
 limit200->Draw("PL SAME");
 limit250->Draw("PL SAME");
 limit300->Draw("PL SAME");
 limit350->Draw("PL SAME");
 limit400->Draw("PL SAME");
 limit450->Draw("PL SAME");
 limit500->Draw("PL SAME");
  limit600->Draw("PL SAME");
 limit700->Draw("PL SAME");
 limit800->Draw("PL SAME");
 limit900->Draw("PL SAME");
 limit1000->Draw("PL SAME");


 leg->Draw("SAME");
 line1->Draw("SAME");
 //latex.DrawLatex(50,2100,thestring);
 //CMS_lumi(c,false,0);
 //l1->Draw("same");
 //l2->Draw("same");
 // l3->Draw("same");
 //l4->Draw("same");
 // c->cd(); 
 c->SaveAs(Form("%s/limits_comparison_Baryo_exp_PARAMETRIC.png",outDir.Data()));
 c->SaveAs(Form("%s/limits_comparison_Baryo_exp_PARAMETRIC.pdf",outDir.Data()));

 // draw 1D comparisons --observed
 c->Clear();


 limit5_obs->GetYaxis()->SetRangeUser(0.1, 1000000000000);
 limit5_obs->GetXaxis()->SetRangeUser(0.1, 10000);
 limit5_obs->Draw("AL");
 // limit1->GetYaxis()->SetRangeUser(0.1, 1000);
 limit10_obs->Draw("PL SAME");
 limit20_obs->Draw("PL SAME");
 limit40_obs->Draw("PL SAME");
 limit60_obs->Draw("PL SAME");

 limit100_obs->Draw("PL SAME");
 limit125_obs->Draw("PL SAME");
 limit150_obs->Draw("PL SAME");
 limit175_obs->Draw("PL SAME");
 limit200_obs->Draw("PL SAME");
 limit250_obs->Draw("PL SAME");
 limit300_obs->Draw("PL SAME");
 limit350_obs->Draw("PL SAME");
 limit400_obs->Draw("PL SAME");
 limit450_obs->Draw("PL SAME");
 limit500_obs->Draw("PL SAME");
 limit600_obs->Draw("PL SAME");
 limit700_obs->Draw("PL SAME");
 limit800_obs->Draw("PL SAME");
 limit900_obs->Draw("PL SAME");
 limit1000_obs->Draw("PL SAME");


 leg->Draw("SAME");
 line1->Draw("SAME");
 //latex.DrawLatex(50,2100,thestring);
 //CMS_lumi(c,false,0);
 //l1->Draw("same");
 //l2->Draw("same");
 // l3->Draw("same");
 //l4->Draw("same");
 // c->cd(); 
 c->SaveAs(Form("%s/limits_comparison_Baryo_obs_PARAMETRIC.png",outDir.Data()));
 c->SaveAs(Form("%s/limits_comparison_Baryo_obs_PARAMETRIC.pdf",outDir.Data()));



 // draw 1D comparisons --expected & observed
 c->Clear();
 // c->SetLogy(1);
 TMultiGraph* mg= new TMultiGraph();
 /*mg->Add(limit5);
 mg->Add(limit10);
 mg->Add(limit20);
 mg->Add(limit40);
 mg->Add(limit60);

 mg->Add(limit100);
 mg->Add(limit125);
 mg->Add(limit150);
 mg->Add(limit175);
 mg->Add(limit200);
 mg->Add(limit250);
 mg->Add(limit300);
 mg->Add(limit350);
 mg->Add(limit400);
 mg->Add(limit450);
 mg->Add(limit500);
 mg->Add(limit600);
 mg->Add(limit700);
 mg->Add(limit800);
 mg->Add(limit900);

 mg->Add(limit1000);
 */

 mg->Add(limit5_obs);
 mg->Add(limit10_obs);
 mg->Add(limit20_obs);
 mg->Add(limit40_obs);
 mg->Add(limit60_obs);

 mg->Add(limit100_obs);
 mg->Add(limit125_obs);
 mg->Add(limit150_obs);
 mg->Add(limit175_obs);
 mg->Add(limit200_obs);
 mg->Add(limit250_obs);
 mg->Add(limit300_obs);
 mg->Add(limit350_obs);
 mg->Add(limit400_obs);
 mg->Add(limit450_obs);
 mg->Add(limit500_obs);
 /* mg->Add(limit600_obs);
 mg->Add(limit700_obs);
 mg->Add(limit800_obs);
 mg->Add(limit900_obs);

 mg->Add(limit1000_obs);
 */
 mg->Draw("AL");
 mg->GetYaxis()->SetRangeUser(0.1, 10);
 mg->GetXaxis()->SetTitle("m_{Z'} [GeV]");
 mg->GetYaxis()->SetTitle("#sigma_{95\% CL} / #sigma_{th}");


 leg->Draw("SAME");
 line1->Draw("SAME");
 //latex.DrawLatex(50,2100,thestring);
 //CMS_lumi(c,false,0);
 // l1->Draw("same");
 //l2->Draw("same");
 //l3->Draw("same");
 //l4->Draw("same");
 c->cd();
 c->SetLogy();
 c->SetLogx();
 
 TString latexCMSnameex1D = "#bf{CMS} #it{Preliminary}";

 TLatex *l1Dex = new TLatex(0.18,0.97,latexCMSnameex1D);
 l1Dex->SetTextSize(0.036);
 l1Dex->SetTextAlign(12);
 l1Dex->SetNDC(kTRUE);
 l1Dex->SetTextFont(42);

 TString latexlumiex1D = Form("35.9 fb^{-1}");
 TString latexenergyex1D = " (13 TeV)";
 TString latexnameex1D = latexlumiex1D+latexenergyex1D;
 TLatex *l2ex1D = new TLatex(0.68,0.97,latexnameex1D);
 l2ex1D->SetTextSize(0.034);
 l2ex1D->SetTextAlign(12);
 l2ex1D->SetNDC(kTRUE);
 l2ex1D->SetTextFont(42);


 TString thestringex1D = "Z'#rightarrow DM+H(#gamma#gamma)";
 TLatex *l3ex1D = new TLatex(0.21,0.85,thestringex1D);
 l3ex1D->SetTextSize(0.036);
 l3ex1D->SetTextAlign(12);
 l3ex1D->SetNDC(kTRUE);
 l3ex1D->SetTextFont(42);
 l1Dex->Draw("same");
 l2ex1D->Draw("same");
 l3ex1D->Draw("same");


 c->SaveAs(Form("%s/limits_comparison_Baryo_PARAMETRIC.png",outDir.Data()));
 c->SaveAs(Form("%s/limits_comparison_Baryo_PARAMETRIC.pdf",outDir.Data()));


 delete c;


 // make plot with both expected and observed on same graph
 //TCanvas* cboth = new TCanvas("cboth","",889,768);
 TCanvas * cboth = new TCanvas("cboth","",1);
 cboth->cd();
 gStyle->SetOptStat(0);
 gStyle->SetPaintTextFormat("2.1e");
 gStyle->SetPalette(57);
 gStyle->SetFrameLineWidth(3);
 gStyle->SetPadRightMargin(0.109);
 gStyle->SetPadLeftMargin(0.13);
 cboth->SetLeftMargin(0.1);
 cboth->SetRightMargin(0.1);

 gStyle->SetHistMinimumZero(kFALSE);
 Double_t pad1_x1 = 0.01; 
 Double_t pad1_x2 = 0.98;
 Double_t pad1_y1 = 0.03;
 Double_t pad1_y2 = 1.00;
 Double_t pad2_x1 = pad1_x1;
 Double_t pad2_x2 = pad1_x2;
 Double_t pad2_y1 = pad1_y1-0.03;
 Double_t pad2_y2 = pad1_y2-0.03;


 //TPad* p1 = new TPad("p1","",0,0.12,0.95,0.98);
 //TPad* p1 = new TPad("p1","",0,0.09,0.95,0.89); //x1,y1,x2,y2
 //TPad* p1 = new TPad("p1","",0.02,0.03,0.98,0.95); //x1,y1,x2,y2
 TPad* p1 = new TPad("p1","",pad1_x1,pad1_y1,pad1_x2,pad1_y2); //x1,y1,x2,y2
 p1->Draw();
 p1->cd();
 p1->SetLogz();

 gStyle->SetPaintTextFormat("2.1e");
 obslimits->Draw("COLZ"); 
 // obslimits->Draw("TEXT SAME");

 float obscontent; 
 double obsbinX;
 double obsbinY;
 TString obsbincon;
 TLatex *obsbintxt; 
 for (int obsbinx = 1; obsbinx <= obslimits->GetXaxis()->GetNbins(); obsbinx++){
    for (int obsbiny = 1; obsbiny <= obslimits->GetYaxis()->GetNbins(); obsbiny++){
       obscontent   = obslimits->GetBinContent(obsbinx,obsbiny);
       //       if (obsbinx==1 && obsbiny>=3) continue;
       //if (obsbinx==2 && obsbiny>=5) continue;
       if (obscontent > 1000) obsbincon = TString::Format("%2.1e",obscontent);
       else obsbincon = TString::Format("%2.1e",obscontent);
       obsbinX      = obslimits->GetXaxis()->GetBinCenter(obsbinx);
       obsbinY      = obslimits->GetYaxis()->GetBinCenter(obsbiny);
       obsbintxt = new TLatex(obsbinX,obsbinY-0.08,obsbincon);
       obsbintxt->SetTextAlign(21);
       obsbintxt->SetTextSize(0.022);
       //       if(obscontent>0)obsbintxt->Draw("same");
    }
 }
 //latex.DrawLatex(0.08,5.7,thestring);
 p1->Update();

 Double_t x1,y1,x2,y2;
 p1->GetRange(x1,y1,x2,y2);

 cboth->cd();
 /*TPad* p2 = new TPad("p2","",pad2_x1,pad2_y1,pad2_x2,pad2_y2); //x1,y1,x2,y2
 p2->SetFillStyle(0);
 p2->SetFillColor(0);
 p2->Draw();
 p2->cd();
 p2->Range(x1,y1,x2,y2);
 gStyle->SetFrameLineWidth(3);
 TFrame *f = (TFrame*)cboth->FindObject("TFrame");
 Double_t px1 = f->GetX1();
 Double_t px2 = f->GetX2();
 Double_t py1 = f->GetY1()+0.23;
 Double_t py2 = f->GetY2()+0.23;

 limits->SetMarkerSize(1.4);
 limits->GetXaxis()->SetTitle("");
 limits->GetYaxis()->SetTitle("");
 limits->SetTitle(""); 
 float content; 
 double binX;
 double binY;
 TString bincon;
 TLatex *bintxt; 
 for (int binx = 1; binx <= limits->GetXaxis()->GetNbins(); binx++){
    for (int biny = 1; biny <= limits->GetYaxis()->GetNbins(); biny++){
       content   = limits->GetBinContent(binx,biny);
       //       if (binx==1 && biny>=3) continue;
       //if (binx==2 && biny>=5) continue;
       if (binx==limits->GetXaxis()->GetNbins()) bincon = TString::Format("(%2.0f)",content);
       else bincon = TString::Format("(%2.1e)",content);
       binX      = limits->GetXaxis()->GetBinCenter(binx);
       binY      = limits->GetYaxis()->GetBinCenter(biny);
       bintxt = new TLatex(binX,binY-0.08,bincon);
       bintxt->SetTextAlign(21);
       bintxt->SetTextSize(0.022);
       //       if(content>0)bintxt->Draw("same");
    }
 }
 
 //limits->Draw("TEXT SAME"); 
 p1->Update();

 // redraw the frame around the histogram
 TLine l;
 l.SetLineWidth(3);
 l.DrawLine(px1,py2,px2,py2);
 l.DrawLine(px2,py1,px2,py2);
 l.DrawLine(px1,py1,px2,py1);
 l.DrawLine(px1,py1,px1,py2);
*/
 //CMS_lumi(cboth,false,0);
 l1b->Draw("same");
 l2b->Draw("same");
 //l3b->Draw("same");
 //l4b->Draw("same");
 cboth->cd();
 p1->SetLogy();
 p1->SetLogx();
 cboth->SaveAs(Form("%s/limits2D_Baryo_ExpAndObs_PARAMETRIC.png",outDir.Data()));
 cboth->SaveAs(Form("%s/limits2D_Baryo_ExpAndObs_PARAMETRIC.pdf",outDir.Data()));
 delete cboth;


 ///compute interpolating points
 double mZP_mChi5=makeInterpolation(limit5, false,1);
 double mZP_mChi10=makeInterpolation(limit10,false,10);
 double mZP_mChi20=makeInterpolation(limit20,false,20);
 double mZP_mChi40=makeInterpolation(limit40,false,40);
 double mZP_mChi60_first=makeInterpolation(limit60,true,60);
 double mZP_mChi60_2nd=makeInterpolation(limit60,false,60); 
 double mZP_mChi100_first=makeInterpolation(limit100,true,100);
 double mZP_mChi100_2nd=makeInterpolation(limit100,false,100); 
 double mZP_mChi125_first=makeInterpolation(limit125,true,125);
 double mZP_mChi125_2nd=makeInterpolation(limit125,false,125); 
 double mZP_mChi150_first=makeInterpolation(limit150,true,150);
 double mZP_mChi150_2nd=makeInterpolation(limit150,false,150); 
 double mZP_mChi175_first=makeInterpolation(limit175,true,175);
 double mZP_mChi175_2nd=makeInterpolation(limit175,false,175); 
 double mZP_mChi200_first=makeInterpolation(limit200,true,200);
 double mZP_mChi200_2nd=makeInterpolation(limit200,false,200); 
 double mZP_mChi250_first=makeInterpolation(limit250,true,250);
 double mZP_mChi250_2nd=makeInterpolation(limit250,false,250); 
 double mZP_mChi300_first=makeInterpolation(limit300,true,300);
 double mZP_mChi300_2nd=makeInterpolation(limit300,false,300); 
 double mZP_mChi350_first=makeInterpolation(limit350,true,350);
 double mZP_mChi350_2nd=makeInterpolation(limit350,false,350); 
 double mZP_mChi400_first=makeInterpolation(limit400,true,400);
 double mZP_mChi400_2nd=makeInterpolation(limit400,false,400); 
 double mZP_mChi450_first=makeInterpolation(limit450,true,450);
 double mZP_mChi450_2nd=makeInterpolation(limit450,false,450); 

 ///compute interpolating points
 double p1sig_mZP_mChi5         = makeInterpolation(p1siglimit5, false,1);
 double p1sig_mZP_mChi10        = makeInterpolation(p1siglimit10,false,10);
 double p1sig_mZP_mChi20        = makeInterpolation(p1siglimit20,false,20);
 double p1sig_mZP_mChi40        = makeInterpolation(p1siglimit40,false,40);
 double p1sig_mZP_mChi60_first  = makeInterpolation(p1siglimit60,true,60);
 double p1sig_mZP_mChi60_2nd    = makeInterpolation(p1siglimit60,false,60); 
 double p1sig_mZP_mChi100_first = makeInterpolation(p1siglimit100,true,100);
 double p1sig_mZP_mChi100_2nd   = makeInterpolation(p1siglimit100,false,100); 
 double p1sig_mZP_mChi125_first = makeInterpolation(p1siglimit125,true,125);
 double p1sig_mZP_mChi125_2nd   = makeInterpolation(p1siglimit125,false,125); 
 double p1sig_mZP_mChi150_first = makeInterpolation(p1siglimit150,true,150);
 double p1sig_mZP_mChi150_2nd   = makeInterpolation(p1siglimit150,false,150); 
 double p1sig_mZP_mChi175_first = makeInterpolation(p1siglimit175,true,175);
 double p1sig_mZP_mChi175_2nd   = makeInterpolation(p1siglimit175,false,175); 
 double p1sig_mZP_mChi200_first = makeInterpolation(p1siglimit200,true,200);
 double p1sig_mZP_mChi200_2nd   = makeInterpolation(p1siglimit200,false,200); 
 double p1sig_mZP_mChi250_first = makeInterpolation(p1siglimit250,true,250);
 double p1sig_mZP_mChi250_2nd   = makeInterpolation(p1siglimit250,false,250); 
 double p1sig_mZP_mChi300_first = makeInterpolation(p1siglimit300,true,300);
 double p1sig_mZP_mChi300_2nd   = makeInterpolation(p1siglimit300,false,300); 
 double p1sig_mZP_mChi350_first = makeInterpolation(p1siglimit350,true,350);
 double p1sig_mZP_mChi350_2nd   = makeInterpolation(p1siglimit350,false,350); 
 double p1sig_mZP_mChi400_first = makeInterpolation(p1siglimit400,true,400);
 double p1sig_mZP_mChi400_2nd   = makeInterpolation(p1siglimit400,false,400); 
 double p1sig_mZP_mChi450_first = makeInterpolation(p1siglimit450,true,450);
 double p1sig_mZP_mChi450_2nd   = makeInterpolation(p1siglimit450,false,450); 

 ///compute interpolating points
 double n1sig_mZP_mChi5         = makeInterpolation(n1siglimit5, false,1);
 double n1sig_mZP_mChi10        = makeInterpolation(n1siglimit10,false,10);
 double n1sig_mZP_mChi20        = makeInterpolation(n1siglimit20,false,20);
 double n1sig_mZP_mChi40        = makeInterpolation(n1siglimit40,false,40);
 double n1sig_mZP_mChi60_first  = makeInterpolation(n1siglimit60,true,60);
 double n1sig_mZP_mChi60_2nd    = makeInterpolation(n1siglimit60,false,60); 
 double n1sig_mZP_mChi100_first = makeInterpolation(n1siglimit100,true,100);
 double n1sig_mZP_mChi100_2nd   = makeInterpolation(n1siglimit100,false,100); 
 double n1sig_mZP_mChi125_first = makeInterpolation(n1siglimit125,true,125);
 double n1sig_mZP_mChi125_2nd   = makeInterpolation(n1siglimit125,false,125); 
 double n1sig_mZP_mChi150_first = makeInterpolation(n1siglimit150,true,150);
 double n1sig_mZP_mChi150_2nd   = makeInterpolation(n1siglimit150,false,150); 
 double n1sig_mZP_mChi175_first = makeInterpolation(n1siglimit175,true,175);
 double n1sig_mZP_mChi175_2nd   = makeInterpolation(n1siglimit175,false,175); 
 double n1sig_mZP_mChi200_first = makeInterpolation(n1siglimit200,true,200);
 double n1sig_mZP_mChi200_2nd   = makeInterpolation(n1siglimit200,false,200); 
 double n1sig_mZP_mChi250_first = makeInterpolation(n1siglimit250,true,250);
 double n1sig_mZP_mChi250_2nd   = makeInterpolation(n1siglimit250,false,250); 
 double n1sig_mZP_mChi300_first = makeInterpolation(n1siglimit300,true,300);
 double n1sig_mZP_mChi300_2nd   = makeInterpolation(n1siglimit300,false,300); 
 double n1sig_mZP_mChi350_first = makeInterpolation(n1siglimit350,true,350);
 double n1sig_mZP_mChi350_2nd   = makeInterpolation(n1siglimit350,false,350); 
 double n1sig_mZP_mChi400_first = makeInterpolation(n1siglimit400,true,400);
 double n1sig_mZP_mChi400_2nd   = makeInterpolation(n1siglimit400,false,400); 
 double n1sig_mZP_mChi450_first = makeInterpolation(n1siglimit450,true,450);
 double n1sig_mZP_mChi450_2nd   = makeInterpolation(n1siglimit450,false,450); 

 
 ///compute interpolating points
 double exp_mZP_mChi5=makeInterpolation(limit5_obs, false,1);
 double exp_mZP_mChi10=makeInterpolation(limit10_obs,false,10);
 double exp_mZP_mChi20=makeInterpolation(limit20_obs,false,20);
 double exp_mZP_mChi40=makeInterpolation(limit40_obs,false,40);
 double exp_mZP_mChi60_first=makeInterpolation(limit60_obs,true,60);
 double exp_mZP_mChi60_2nd=makeInterpolation(limit60_obs,false,60); 
 double exp_mZP_mChi100_first=makeInterpolation(limit100_obs,true,100);
 double exp_mZP_mChi100_2nd=makeInterpolation(limit100_obs,false,100); 
 double exp_mZP_mChi125_first=makeInterpolation(limit125_obs,true,125);
 double exp_mZP_mChi125_2nd=makeInterpolation(limit125_obs,false,125); 
 double exp_mZP_mChi150_first=makeInterpolation(limit150_obs,true,150);
 double exp_mZP_mChi150_2nd=makeInterpolation(limit150_obs,false,150); 
 double exp_mZP_mChi175_first=makeInterpolation(limit175_obs,true,175);
 double exp_mZP_mChi175_2nd=makeInterpolation(limit175_obs,false,175); 
 double exp_mZP_mChi200_first=makeInterpolation(limit200_obs,true,200);
 double exp_mZP_mChi200_2nd=makeInterpolation(limit200_obs,false,200); 
 double exp_mZP_mChi250_first=makeInterpolation(limit250_obs,true,250);
 double exp_mZP_mChi250_2nd=makeInterpolation(limit250_obs,false,250); 
 double exp_mZP_mChi300_first=makeInterpolation(limit300_obs,true,300);
 double exp_mZP_mChi300_2nd=makeInterpolation(limit300_obs,false,300); 
 double exp_mZP_mChi350_first=makeInterpolation(limit350_obs,true,350);
 double exp_mZP_mChi350_2nd=makeInterpolation(limit350_obs,false,350); 
 double exp_mZP_mChi400_first=makeInterpolation(limit400_obs,true,400);
 double exp_mZP_mChi400_2nd=makeInterpolation(limit400_obs,false,400); 
 double exp_mZP_mChi450_first=makeInterpolation(limit450_obs,true,450);
 double exp_mZP_mChi450_2nd=makeInterpolation(limit450_obs,false,450); 



double mzp_excl[30]={mZP_mChi5,mZP_mChi10,mZP_mChi20,mZP_mChi40,mZP_mChi60_2nd,mZP_mChi100_2nd,mZP_mChi125_2nd,mZP_mChi150_2nd,mZP_mChi175_2nd,mZP_mChi200_2nd,mZP_mChi250_2nd,mZP_mChi300_2nd,mZP_mChi350_2nd,mZP_mChi400_2nd,mZP_mChi450_2nd,mZP_mChi450_first,mZP_mChi400_first,mZP_mChi350_first,mZP_mChi300_first,mZP_mChi250_first,mZP_mChi200_first,mZP_mChi175_first,mZP_mChi150_first,mZP_mChi125_first,mZP_mChi100_first,mZP_mChi60_first,10,10,10,10};

 double mzp_excl_exp[30]={exp_mZP_mChi5,exp_mZP_mChi10,exp_mZP_mChi20,exp_mZP_mChi40,exp_mZP_mChi60_2nd,exp_mZP_mChi100_2nd,exp_mZP_mChi125_2nd,exp_mZP_mChi150_2nd,exp_mZP_mChi175_2nd,exp_mZP_mChi200_2nd,exp_mZP_mChi250_2nd,exp_mZP_mChi300_2nd,exp_mZP_mChi350_2nd,exp_mZP_mChi400_2nd,exp_mZP_mChi450_2nd,exp_mZP_mChi450_first,exp_mZP_mChi400_first,exp_mZP_mChi350_first,exp_mZP_mChi300_first,exp_mZP_mChi250_first,exp_mZP_mChi200_first,exp_mZP_mChi175_first,exp_mZP_mChi150_first,exp_mZP_mChi125_first,exp_mZP_mChi100_first,exp_mZP_mChi60_first,10,10,10,10};
 double mchi_excl_exp[30]={5,10,20,40,60,100,125,150,175,200,250,300,350,400,450,450,400,350,300,250,200,175,150,125,100,60,40,20,10,5};


 TGraph* exp_excluded = new TGraph(30,mzp_excl,mchi_excl_exp);
 TGraph* obs_excluded = new TGraph(30,mzp_excl_exp,mchi_excl_exp);

 // -----------------------------------------------------------------------------
 std::cout << "Getting contours for Expected CL" << std::endl;
 TCanvas* cex_exp = new TCanvas("cex_exp","cex_exp",800,800);
 cex_exp->SetLeftMargin(0.1);
 cex_exp->SetRightMargin(0.1);
 gStyle->SetFrameLineWidth(3);
 gStyle->SetPadRightMargin(0.109);
 gStyle->SetPadLeftMargin(0.13);
 cex_exp->SetLeftMargin(0.1);
 cex_exp->SetRightMargin(0.1);
 gStyle->SetHistMinimumZero(kFALSE);

 TH2D* h_exp = new TH2D("h_exp","h_exp",990,10,1000,500,1,500);
 TH2D* hh_exp = new TH2D("hh_exp","hh_exp",990,10,1000,500,1,500);
 g2d_exp->SetHistogram(hh_exp);
 h_exp=g2d_exp->GetHistogram();
 h_exp->GetZaxis()->SetRangeUser(0.1,2000000);
 h_exp->GetYaxis()->SetRangeUser(1,500);
 h_exp->GetXaxis()->SetRangeUser(10,2000);
 g2d_exp->GetZaxis()->SetRangeUser(0.1,2000000);
 g2d_exp->GetYaxis()->SetRangeUser(5,500);
 g2d_exp->GetXaxis()->SetRangeUser(10,1000);

 Double_t contours_exp[1];
 contours_exp[0]= 1.;

 h_exp->SetContour(1, contours_exp);
 h_exp->Draw("CONT Z LIST ");
 cex_exp->Update();
 // Get Contours                                                                                                                                            
 TObjArray *conts_exp = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
 TList* contLevel_exp = NULL;
 TGraph* curv_exp     = NULL;
 TGraph* gc_exp       = NULL;

 Int_t nGraphs_exp    = 0;
 Int_t TotalConts_exp = 0;

 if (conts_exp == NULL){
   printf("*** No Contours Were Extracted!\n");
   TotalConts_exp = 0;
   //  return;
 } else {
   TotalConts_exp = conts_exp->GetSize();
 }

 printf("TotalConts = %d\n", TotalConts_exp);

 for(int i = 0; i < TotalConts_exp; i++){
   contLevel_exp = (TList*)conts_exp->At(i);
   printf("Contour %d has %d Graphs\n", i, contLevel_exp->GetSize());
   nGraphs_exp += contLevel_exp->GetSize();
 }

 nGraphs_exp = 0;

 Double_t x0_exp, y0_exp, z0_exp;
 char val_exp[20];
 TMultiGraph* mgg_exp = new TMultiGraph();
 for(int i = 0; i < TotalConts_exp; i++){ //loop sui livelli                                                                                                       
   contLevel_exp = (TList*)conts_exp->At(i);

   // Get first graph from list on curves on this level                                                                                                   
   curv_exp = (TGraph*)contLevel_exp->First();
   for(int j = 0; j < 1; j++){//per ogni livello guardo tutte le curve                                                                     
     curv_exp->GetPoint(0, x0_exp, y0_exp);
     nGraphs_exp ++;
     printf("\tGraph: %d  -- %d Elements\n", nGraphs_exp, curv_exp->GetN());
     // Draw clones of the graphs to avoid deletions in case the 1st                                                                                     
     // pad is redrawn.                                                                                                                                  
     gc_exp = (TGraph*)curv_exp->Clone();
     //     gc->Draw("Csame");
     mgg_exp->Add(gc_exp);
     curv_exp = (TGraph*)contLevel_exp->After(curv_exp); // Get Next graph                

   }
   }

 // -----------------------------------------------------------------------------
 std::cout << "Getting contours for Expected p1sig CL" << std::endl;
 TCanvas* cex_exp_p1sig = new TCanvas("cex_exp_p1sig","cex_exp_p1sig",800,800);
 cex_exp_p1sig->SetLeftMargin(0.1);
 cex_exp_p1sig->SetRightMargin(0.1);
 gStyle->SetFrameLineWidth(3);
 gStyle->SetPadRightMargin(0.109);
 gStyle->SetPadLeftMargin(0.13);
 cex_exp_p1sig->SetLeftMargin(0.1);
 cex_exp_p1sig->SetRightMargin(0.1);
 gStyle->SetHistMinimumZero(kFALSE);

 TH2D* h_exp_p1sig  = new TH2D("h_exp_p1sig","h_exp_p1sig",990,10,1000,500,1,500);
 TH2D* hh_exp_p1sig = new TH2D("hh_exp_p1sig","hh_exp_p1sig",990,10,1000,500,1,500);
 g2d_exp_p1sig->SetHistogram(hh_exp_p1sig);
 h_exp_p1sig=g2d_exp_p1sig->GetHistogram();
 h_exp_p1sig->GetZaxis()->SetRangeUser(0.1,2000000);
 h_exp_p1sig->GetYaxis()->SetRangeUser(1,500);
 h_exp_p1sig->GetXaxis()->SetRangeUser(10,2000);
 g2d_exp_p1sig->GetZaxis()->SetRangeUser(0.1,2000000);
 g2d_exp_p1sig->GetYaxis()->SetRangeUser(5,500);
 g2d_exp_p1sig->GetXaxis()->SetRangeUser(10,1000);

 Double_t contours_exp_p1sig[1];
 contours_exp_p1sig[0]= 1.;

 h_exp_p1sig->SetContour(1, contours_exp_p1sig);
 h_exp_p1sig->Draw("CONT Z LIST ");
 cex_exp_p1sig->Update();
 // Get Contours                                                                                                                                            
 TObjArray *conts_exp_p1sig = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
 TList* contLevel_exp_p1sig = NULL;
 TGraph* curv_exp_p1sig     = NULL;
 TGraph* gc_exp_p1sig       = NULL;

 Int_t nGraphs_exp_p1sig    = 0;
 Int_t TotalConts_exp_p1sig = 0;

 if (conts_exp_p1sig == NULL){
   printf("*** No Contours Were Extracted!\n");
   TotalConts_exp_p1sig = 0;
   //  return;
 } else {
   TotalConts_exp_p1sig = conts_exp_p1sig->GetSize();
 }

 printf("TotalConts = %d\n", TotalConts_exp_p1sig);

 for(int i = 0; i < TotalConts_exp_p1sig; i++){
   contLevel_exp_p1sig = (TList*)conts_exp_p1sig->At(i);
   printf("Contour %d has %d Graphs\n", i, contLevel_exp_p1sig->GetSize());
   nGraphs_exp_p1sig += contLevel_exp_p1sig->GetSize();
 }

 nGraphs_exp_p1sig = 0;

 Double_t x0_exp_p1sig, y0_exp_p1sig, z0_exp_p1sig;
 char val_exp_p1sig[20];
 TMultiGraph* mgg_exp_p1sig = new TMultiGraph();
 for(int i = 0; i < TotalConts_exp_p1sig; i++){ //loop sui livelli                                                                                                       
   contLevel_exp_p1sig = (TList*)conts_exp_p1sig->At(i);

   // Get first graph from list on curves on this level                                                                                                   
   curv_exp_p1sig = (TGraph*)contLevel_exp_p1sig->First();
   curv_exp_p1sig->SetLineStyle(2);
   for(int j = 0; j < 1; j++){//per ogni livello guardo tutte le curve                                                                     
     curv_exp_p1sig->GetPoint(0, x0_exp_p1sig, y0_exp_p1sig);
     nGraphs_exp_p1sig ++;
     printf("\tGraph: %d  -- %d Elements\n", nGraphs_exp_p1sig, curv_exp_p1sig->GetN());
     // Draw clones of the graphs to avoid deletions in case the 1st                                                                                     
     // pad is redrawn.                                                                                                                                  
     gc_exp_p1sig = (TGraph*)curv_exp_p1sig->Clone();
     //     gc->Draw("Csame");
     mgg_exp_p1sig->Add(gc_exp_p1sig);
     curv_exp_p1sig = (TGraph*)contLevel_exp_p1sig->After(curv_exp_p1sig); // Get Next graph                

   }
   }

 // -----------------------------------------------------------------------------

 // -----------------------------------------------------------------------------
 std::cout << "Getting contours for Expected n1sig CL" << std::endl;
 TCanvas* cex_exp_n1sig = new TCanvas("cex_exp_n1sig","cex_exp_n1sig",800,800);
 cex_exp_n1sig->SetLeftMargin(0.1);
 cex_exp_n1sig->SetRightMargin(0.1);
 gStyle->SetFrameLineWidth(3);
 gStyle->SetPadRightMargin(0.109);
 gStyle->SetPadLeftMargin(0.13);
 cex_exp_n1sig->SetLeftMargin(0.1);
 cex_exp_n1sig->SetRightMargin(0.1);
 gStyle->SetHistMinimumZero(kFALSE);

 TH2D* h_exp_n1sig  = new TH2D("h_exp_n1sig","h_exp_n1sig",990,10,1000,500,1,500);
 TH2D* hh_exp_n1sig = new TH2D("hh_exp_n1sig","hh_exp_n1sig",990,10,1000,500,1,500);
 g2d_exp_n1sig->SetHistogram(hh_exp_n1sig);
 h_exp_n1sig=g2d_exp_n1sig->GetHistogram();
 h_exp_n1sig->GetZaxis()->SetRangeUser(0.1,2000000);
 h_exp_n1sig->GetYaxis()->SetRangeUser(1,500);
 h_exp_n1sig->GetXaxis()->SetRangeUser(10,2000);
 g2d_exp_n1sig->GetZaxis()->SetRangeUser(0.1,2000000);
 g2d_exp_n1sig->GetYaxis()->SetRangeUser(5,500);
 g2d_exp_n1sig->GetXaxis()->SetRangeUser(10,1000);

 Double_t contours_exp_n1sig[1];
 contours_exp_n1sig[0]= 1.;

 h_exp_n1sig->SetContour(1, contours_exp_n1sig);
 h_exp_n1sig->Draw("CONT Z LIST ");
 cex_exp_n1sig->Update();
 // Get Contours                                                                                                                                            
 TObjArray *conts_exp_n1sig = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
 TList* contLevel_exp_n1sig = NULL;
 TGraph* curv_exp_n1sig     = NULL;
 TGraph* gc_exp_n1sig       = NULL;

 Int_t nGraphs_exp_n1sig    = 0;
 Int_t TotalConts_exp_n1sig = 0;

 if (conts_exp_n1sig == NULL){
   printf("*** No Contours Were Extracted!\n");
   TotalConts_exp_n1sig = 0;
   //  return;
 } else {
   TotalConts_exp_n1sig = conts_exp_n1sig->GetSize();
 }

 printf("TotalConts = %d\n", TotalConts_exp_n1sig);

 for(int i = 0; i < TotalConts_exp_n1sig; i++){
   contLevel_exp_n1sig = (TList*)conts_exp_n1sig->At(i);
   printf("Contour %d has %d Graphs\n", i, contLevel_exp_n1sig->GetSize());
   nGraphs_exp_n1sig += contLevel_exp_n1sig->GetSize();
 }

 nGraphs_exp_n1sig = 0;

 Double_t x0_exp_n1sig, y0_exp_n1sig, z0_exp_n1sig;
 char val_exp_n1sig[20];
 TMultiGraph* mgg_exp_n1sig = new TMultiGraph();
 for(int i = 0; i < TotalConts_exp_n1sig; i++){ //loop sui livelli                                                                                                       
   contLevel_exp_n1sig = (TList*)conts_exp_n1sig->At(i);

   // Get first graph from list on curves on this level                                                                                                   
   curv_exp_n1sig = (TGraph*)contLevel_exp_n1sig->First();
   curv_exp_n1sig->SetLineStyle(2);
   for(int j = 0; j < 1; j++){//per ogni livello guardo tutte le curve                                                                     
     curv_exp_n1sig->GetPoint(0, x0_exp_n1sig, y0_exp_n1sig);
     nGraphs_exp_n1sig ++;
     printf("\tGraph: %d  -- %d Elements\n", nGraphs_exp_n1sig, curv_exp_n1sig->GetN());
     // Draw clones of the graphs to avoid deletions in case the 1st                                                                                     
     // pad is redrawn.                                                                                                                                  
     gc_exp_n1sig = (TGraph*)curv_exp_n1sig->Clone();
     //     gc->Draw("Csame");
     mgg_exp_n1sig->Add(gc_exp_n1sig);
     curv_exp_n1sig = (TGraph*)contLevel_exp_n1sig->After(curv_exp_n1sig); // Get Next graph                

   }
   }

 // -----------------------------------------------------------------------------
 // -----------------------------------------------------------------------------
 std::cout << "Getting contours for Observed CL" << std::endl;
 TCanvas* cex = new TCanvas("cex","cex",800,800);
 cex->SetLeftMargin(0.1);
 cex->SetRightMargin(0.1);
 gStyle->SetFrameLineWidth(3);
 gStyle->SetPadRightMargin(0.109);
 gStyle->SetPadLeftMargin(0.13);
 cex->SetLeftMargin(0.1);
 cex->SetRightMargin(0.1);
 gStyle->SetHistMinimumZero(kFALSE);
 
 //TGraph2D* mu = new TGraph2D(13,massZP,massChi,obs_vec);

 TH2D* h = new TH2D("h","h",990,10,1000,500,1,500);
 TH2D* hh = new TH2D("hh","hh",990,10,1000,500,1,500);
 g2d->SetHistogram(hh);
 h=g2d->GetHistogram();
 h->GetZaxis()->SetRangeUser(0.1,2000000);
 h->GetYaxis()->SetRangeUser(1,500);
 h->GetXaxis()->SetRangeUser(10,2000);
 g2d->GetZaxis()->SetRangeUser(0.1,2000000);
 g2d->GetYaxis()->SetRangeUser(5,500);
 g2d->GetXaxis()->SetRangeUser(10,1000);

 // h->Draw("COLZ");

 Double_t contours[1];
 contours[0]= 1.;

 h->SetContour(1, contours);
 h->Draw("CONT Z LIST ");
 cex->Update();
 // Get Contours                                                                                                                                            
 TObjArray *conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
 TList* contLevel = NULL;
 TGraph* curv     = NULL;
 TGraph* gc       = NULL;

 Int_t nGraphs    = 0;
 Int_t TotalConts = 0;

 if (conts == NULL){
   printf("*** No Contours Were Extracted!\n");
   TotalConts = 0;
   //  return;
 } else {
   TotalConts = conts->GetSize();
 }

 printf("TotalConts = %d\n", TotalConts);

 for(int i = 0; i < TotalConts; i++){
   contLevel = (TList*)conts->At(i);
   printf("Contour %d has %d Graphs\n", i, contLevel->GetSize());
   nGraphs += contLevel->GetSize();
 }

 nGraphs = 0;

 Double_t x0, y0, z0;
 TLatex l;
 l.SetTextSize(0.03);
 char val[20];
 TMultiGraph* mgg = new TMultiGraph();
 for(int i = 0; i < TotalConts; i++){ //loop sui livelli                                                                                                       
   contLevel = (TList*)conts->At(i);

   // Get first graph from list on curves on this level                                                                                                   
   curv = (TGraph*)contLevel->First();
   for(int j = 0; j < 1; j++){//per ogni livello guardo tutte le curve                                                                     
     curv->GetPoint(0, x0, y0);
     nGraphs ++;
     printf("\tGraph: %d  -- %d Elements\n", nGraphs,curv->GetN());
     // Draw clones of the graphs to avoid deletions in case the 1st                                                                                     
     // pad is redrawn.                                                                                                                                  
     gc = (TGraph*)curv->Clone();
     //     gc->Draw("Csame");
     mgg->Add(gc);
     curv = (TGraph*)contLevel->After(curv); // Get Next graph                                                                            
               
   }
   }


 // -----------------------------------------------------------------------------
 // -----------------------------------------------------------------------------

 TCanvas *cex_copy = new TCanvas("cex_copy", "cex_copy",525,1113,800,795);
 cex_copy->cd();
 cex_copy->Update();
 gStyle->SetOptFit(1);
 gStyle->SetOptStat(0);
 gStyle->SetOptTitle(0);
 cex_copy->Range(-261.1739,-215.1203,1456.261,537.1745);
 cex_copy->SetFillColor(0);
 cex_copy->SetBorderMode(0);
 cex_copy->SetBorderSize(2);
 cex_copy->SetLogz();
 cex_copy->SetTickx(1);
 cex_copy->SetTicky(1);
 cex_copy->SetLeftMargin(0.1578947);
 cex_copy->SetRightMargin(0.2656642);
 cex_copy->SetTopMargin(0.04941482);
 cex_copy->SetBottomMargin(0.2925878);
 cex_copy->SetFrameFillStyle(0);
 cex_copy->SetFrameLineWidth(3);
 cex_copy->SetFrameBorderMode(0);
 cex_copy->SetFrameFillStyle(0);
 cex_copy->SetFrameLineWidth(3);
 cex_copy->SetFrameBorderMode(0);

 TH2D* h_copy = new TH2D("h_copy","h_copy",990,10,1000,500,1,500);
 TH2D* hh_copy = new TH2D("hh_copy","hh_copy",990,10,1000,500,1,500);
 TH2D* h_exp_copy = new TH2D("h_exp_copy","h_exp_copy",990,10,1000,500,1,500);
 TH2D* hh_exp_copy = new TH2D("hh_exp_copy","hh_exp_copy",990,10,1000,500,1,500);
 g2d_copy->SetHistogram(hh_copy);
 g2d_exp_copy->SetHistogram(hh_exp_copy);
 h_exp_copy=g2d_exp_copy->GetHistogram();
 h_exp_copy->GetZaxis()->SetRangeUser(0.1,2000000);
 h_exp_copy->GetYaxis()->SetRangeUser(1,500);
 h_exp_copy->GetXaxis()->SetRangeUser(10,2000);
 h_copy=g2d_copy->GetHistogram();
 h_copy->GetZaxis()->SetRangeUser(0.1,2000000);
 h_copy->GetYaxis()->SetRangeUser(1,500);
 h_copy->GetXaxis()->SetRangeUser(10,2000);
 g2d_exp_copy->GetZaxis()->SetRangeUser(0.1,2000000);
 g2d_exp_copy->GetYaxis()->SetRangeUser(5,500);
 g2d_exp_copy->GetXaxis()->SetRangeUser(10,1000);
 g2d_copy->GetZaxis()->SetRangeUser(0.1,2000000);
 g2d_copy->GetYaxis()->SetRangeUser(5,500);
 g2d_copy->GetXaxis()->SetRangeUser(10,1000);

 hh_copy->Draw("COLZ");
 hh_copy->SetMinimum(0.1);
 hh_copy->SetMaximum(50);
 g2d_copy->Draw("COLZsame");

 TLatex *l1ex = new TLatex(0.16,0.97,latexCMSname);
 l1ex->SetTextSize(0.036);
 l1ex->SetTextAlign(12);
 l1ex->SetNDC(kTRUE);
 l1ex->SetTextFont(42);
 l1ex->Draw("same");                                     

 TString latexlumiex = Form("35.9 fb^{-1}");
 TString latexenergyex = " (13 TeV)";
 TString latexnameex = latexlumiex+latexenergyex;
 TLatex *l2ex = new TLatex(0.5,0.9713914,latexnameex); 
 l2ex->SetTextSize(0.034);
 l2ex->SetTextAlign(12); 
 l2ex->SetNDC(kTRUE);
 l2ex->SetTextFont(42);
 l2ex->Draw("same");  
  
 TString thestringex = Form("Z'#rightarrow DM+H(#gamma#gamma)");
 //TLatex *l3ex = new TLatex(0.1842105,0.8829649,thestringex);       
 TLatex *l3ex = new TLatex(0.19,0.9,thestringex);       
 l3ex->SetTextSize(0.036);                               
 l3ex->SetTextAlign(12);                                 
 l3ex->SetNDC(kTRUE);                                    
 l3ex->SetTextFont(42);                                  
 l3ex->Draw("same");   
 
 TLatex *lxex = new TLatex(0.5363409,0.1963589,"m_{Z'} [GeV]"); 
 lxex->SetTextSize(0.054);         
 lxex->SetTextAlign(12);
 lxex->SetNDC(kTRUE);  
 lxex->SetTextFont(42);
 lxex->Draw("same");                                                                                                                                                            
 TLatex *lyex = new TLatex(0.03,0.77,"m_{#chi} [GeV]");
 lyex->SetTextSize(0.054);
 lyex->SetTextAlign(12);
 lyex->SetTextAngle(90);
 lyex->SetNDC(kTRUE);
 lyex->SetTextFont(42);
 lyex->Draw("same");                                                                                                                                                            
 TLatex *lzex = new TLatex(0.8859649,0.9440832,"Observed #mu 95% CL");
 lzex->SetTextSize(0.054);
 lzex->SetTextAlign(12);
 lzex->SetTextAngle(270);
 lzex->SetNDC(kTRUE);
 lzex->SetTextFont(42);
 lzex->Draw("same");

 cex_copy->RedrawAxis();
 // cex_copy->Modified();
 gc_exp->SetLineColor(kBlack);
 gc_exp->SetLineStyle(1);
 gc_exp->SetLineWidth(2);
 gc->SetLineColor(kRed);
 gc->SetLineStyle(1);
 gc->SetLineWidth(2);
 gc_exp_p1sig->SetLineStyle(0);
 gc_exp_n1sig->SetLineStyle(0);
 gc_exp_p1sig->SetFillStyle(0);
 gc_exp_n1sig->SetFillStyle(0);
 gc->Draw("Csame");
 gc_exp->Draw("Csame");
 gc_exp_p1sig->Draw("Csame");
 gc_exp_n1sig->Draw("Csame");

 TLegend* cleg = new TLegend(0.19,0.80,0.45,0.88,NULL,"brNDC"); // (x1,y1,x2,y2)
 //cleg->SetTextSize(0.046);
 cleg->SetBorderSize(0);
 cleg->SetLineColor(1);
 cleg->SetLineWidth(1);
 cleg->SetLineStyle(1);
 //cleg->SetFillColor(0);
 //cleg->SetFillStyle(0);
 cleg->SetTextFont(62);
 cleg->AddEntry(gc,"Observed 95\% CL","L");
 cleg->AddEntry(gc_exp,"Median Expected 95\% CL","L");
 cleg->AddEntry(gc_exp_p1sig,"Expected #pm 1#sigma_{experiment}","L");
 cleg->Draw("same");

 cex_copy->SaveAs(Form("%s2D_ZPBaryonic_PARAMETRIC_C2.png",outDir.Data()));
 cex_copy->SaveAs(Form("%s2D_ZPBaryonic_PARAMETRIC_C2.pdf",outDir.Data()));

 /*

 //h->GetZaxis()->SetLabelOffset(0.5*h->GetZaxis()->GetLabelOffset());
 gStyle->SetPalette(57,0);
 // cex->Update();
 cex->SetLogz();                                                                                                                 // cex->SetLogx();                            
 // cex->SetLogy();                                                                                                                 // cex->SetLogx();                            
 //cex->SetLogx();                                                                                                                 // cex->SetLogx();                            
 g2d->Print("V ALL");
 //g2d->Draw("COLZ");
 g2d->GetZaxis()->SetRangeUser(0.1,50);
 g2d->GetZaxis()->SetLabelOffset(0.5*g2d->GetZaxis()->GetLabelOffset());
 
 TLegend* legex = new TLegend(0.2,0.7, 0.5, 0.9);
 legex->SetFillColor(0);
 //legex->AddEntry(exp_g,"#splitline{Median}{Expected 95% CL}", "L");
 // legex->AddEntry(obs_g,"#splitline{Median}{Observed 95% CL}", "L");
 TString latexCMSnameex = "#bf{CMS} #it{Preliminary}";
 cex->cd();
 TLatex *l1ex = new TLatex(0.13,0.97,latexCMSname);
 l1ex->SetTextSize(0.036);
 l1ex->SetTextAlign(12);
 l1ex->SetNDC(kTRUE);
 l1ex->SetTextFont(42);

 TString latexlumiex = Form("35.9 fb^{-1}");
 TString latexenergyex = " (13 TeV)";
 TString latexnameex = latexlumiex+latexenergyex;
 TLatex *l2ex = new TLatex(0.59,0.97,latexnameex);
 l2ex->SetTextSize(0.034);
 l2ex->SetTextAlign(12);
 l2ex->SetNDC(kTRUE);
 l2ex->SetTextFont(42);


 TString thestringex = "Z'#rightarrow DM+H(#gamma#gamma)";
 TLatex *l3ex = new TLatex(0.21,0.65,thestringex);
 l3ex->SetTextSize(0.036);
 l3ex->SetTextAlign(12);
 l3ex->SetNDC(kTRUE);
 l3ex->SetTextFont(42);
 l1ex->Draw("same");
 l2ex->Draw("same");


 TLatex *lxex = new TLatex(0.7,0.05,"m_{Z'} [GeV]");
 lxex->SetTextSize(0.054);
 lxex->SetTextAlign(12);
 lxex->SetNDC(kTRUE);
 lxex->SetTextFont(42);
 lxex->Draw("same");
 TLatex *lyex = new TLatex(0.03,0.77,"m_{#chi} [GeV]");
 lyex->SetTextSize(0.054);
 lyex->SetTextAlign(12);
 lyex->SetTextAngle(90);
 lyex->SetNDC(kTRUE);
 lyex->SetTextFont(42);
 lyex->Draw("same");
 TLatex *lzex = new TLatex(0.97,0.95,"Observed #mu 95% CL");
 lzex->SetTextSize(0.054);
 lzex->SetTextAlign(12);
 lzex->SetTextAngle(270);
 lzex->SetNDC(kTRUE);
 lzex->SetTextFont(42);
 lzex->Draw("same");
 // legex->Draw("same");
 l3ex->Draw("same");
 cex->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/2D_ZPBaryonic_PARAMETRIC.png");
 cex->SaveAs("~/www/plotsMonoH/FitLimits/PAS-April2017/2D_ZPBaryonic_PARAMETRIC.pdf");

 cex->Clear();
 */
 /*
 TFile* fout=new TFile("input_combo_MonoHgg_25April.root", "RECREATE");
 exp_g->Write();
 obs_g->Write();
 double x[4] ={10,10000,10000,10};
 double y[4]={1,1,50,50};
 TGraph* exp_scalar_MonoHgg= new TGraph(4,x,y);
 TGraph* obs_scalar_MonoHgg= new TGraph(4,x,y);
 exp_scalar_MonoHgg->SetTitle("exp_scalar_MonoHgg");
 exp_scalar_MonoHgg->SetName("exp_scalar_MonoHgg");
 obs_scalar_MonoHgg->SetTitle("obs_scalar_MonoHgg");
 obs_scalar_MonoHgg->SetName("obs_scalar_MonoHgg");
 exp_scalar_MonoHgg->Write();
 obs_scalar_MonoHgg->Write();
 fout->Write();
 fout->Close();
 */
}





void getEff(TFile* file, int mA0, int mZp, Double_t & eff, Double_t & eff_err){
  TH2F* sigeff = (TH2F*)file->Get("effhisto");
  if (sigeff!=(TH2F*)NULL){
    Int_t binX = sigeff->GetXaxis()->FindBin(mZp);
    Int_t binY = sigeff->GetYaxis()->FindBin(mA0);  
    eff = sigeff->GetBinContent(binX,binY);
    eff_err = sigeff->GetBinError(binX,binY);
  }
  else{
    eff = 0;
    eff_err = 0;
    std::cout << " No eff for mA0 = " << mA0 << " and mZp = " << mZp << std::endl;
  }
}


void getXsec(TFile* file, int mA0, int mZp, Double_t & xsec){

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


void getXsecBaryo(TFile* file, int mchi, int mZp, Double_t & xsec){
  //  file->Print("V");
  TH2F* xsecs = (TH2F*)file->Get("h2_BARY_XSEC_pb"); 
  if (xsecs!=(TH2F*)NULL){
    xsec = xsecs->Interpolate(mZp, mchi);//GetBinContent(xsecs->GetXaxis()->FindBin(mZp),xsecs->GetYaxis()->FindBin(mchi));
     //     xsec = xsecs->GetBinContent(binX);
     //std::cout<<" mZp: "<<mZp<< " mCHI: "<<mchi<< " XSEC: "<<xsec<<std::endl;
  }
  else{
   xsec = 1;
   std::cout << "Couldn't find xsec histogram" << std::endl;
  }
} 


void getXsecScalar(TFile* file, int mchi, int mZp, Double_t & xsec){
  //  file->Print("V");
  TGraph* xsecs = (TGraph*)file->Get(Form("zp%d",mZp)); 
  if (xsecs!=(TGraph*)NULL){
     xsec = xsecs->Eval(mchi);
     //     xsec = xsecs->GetBinContent(binX);
     std::cout<<mZp<< " "<<mchi<< " "<<xsec<<std::endl;
  }
  else{
   xsec = 1;
   //   std::cout << "Couldn't find xsec histogram" << std::endl;
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
    int nentries = tree->GetEntries();
    for (int entry = 0; entry < nentries; entry++){
      tree->GetEntry(entry);
      //      std::cout << "Quantile = " << quantileExpected << std::endl;
      //std::cout << "Limit    = " << limit << std::endl;
      if (quantileExpected==quantile) Limit=limit;
      if (quantileExpected>quantile-0.01 && quantileExpected<quantile+0.01) Limit=limit;
    }

  }// end valid tree
  else Limit = 0;
  //std::cout << "Limit    = " << Limit << std::endl;
  
  delete tree;

}

