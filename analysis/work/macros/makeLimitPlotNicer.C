#include "TROOT.h"
#include "TFile.h"
#include "TString.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH2.h"
#include "TStyle.h"
#include "TGraph2D.h"
#include <iostream>

void run(TString, TString, int);
void getXsec2HDM(TFile*, int, int, Double_t &);
void getXsecBary(TFile*, int, int, Double_t &);
void getLimitVal(TFile*, Double_t, Double_t &);
void getMassPoints( std::vector<TString> &);
void getInterpolation(TGraph*, bool, Double_t &); // not used
void getIntMasses(TString, int, int &, int &);
void getHCombFile(TString, TString, int, TFile* &);
void getContours(int, TGraph2D*, TGraph* &);
void setStyle(TCanvas*, TPad*);
void setCMSLabels(TLatex* &, TLatex* &, TLatex* &, TLatex* &, int);

void makeLimitPlotNicer(){
  std::cout << "Making 2D limit plot" << std::endl;
  
  TString inDir  = "ntuples4fit";
  TString outDir = "~/www/Plots/13TeV_v80X_moriond17/ContourPlots_mine/";

  run(inDir,outDir,0); // run for baryonic
  //run(inDir,outDir,1); // run for 2hdm

}

void run(TString inDir, TString outDir, int type){

  // Theory xsec root file
  TFile* xsecFile;
  if (type==0) xsecFile = new TFile("theory_ZPBaryonic.root");
  //if (type==0) xsecFile = new TFile("Output_XsecBARY.root");
  //if (type==1) xsecFile = new TFile("");


  // Setup which samples to run
  std::vector<TString> sampleNames; 
  getMassPoints( sampleNames );
  UInt_t nSig = sampleNames.size();

  int m1;
  int m2;
  std::map<TString,Double_t> xsecMap;

  std::map<TString,TFile* >  hcombMap;
  std::map<TString,Double_t> expLimitMap;
  std::map<TString,Double_t> obsLimitMap;
  std::map<TString,Double_t> p1sLimitMap;
  std::map<TString,Double_t> n1sLimitMap;
  std::map<TString,Double_t> expMuMap;
  std::map<TString,Double_t> obsMuMap;
  std::map<TString,Double_t> p1sMuMap;
  std::map<TString,Double_t> n1sMuMap;

  TGraph2D* g2d_exp = new TGraph2D();
  TGraph2D* g2d_obs = new TGraph2D();
  TGraph2D* g2d_p1s = new TGraph2D();
  TGraph2D* g2d_n1s = new TGraph2D();

  for (UInt_t i=0; i < nSig; i++){
    // prep everything
    getIntMasses(sampleNames[i],type,m1,m2);                          // get int values of masses
    getXsecBary(xsecFile,m1,m2,xsecMap[sampleNames[i]]);              // get xsecs
    getHCombFile(inDir,sampleNames[i],type,hcombMap[sampleNames[i]]); // open higgs combine files
    // get limit values
    getLimitVal(hcombMap[sampleNames[i]],0.50,expLimitMap[sampleNames[i]]); // exp limit 
    getLimitVal(hcombMap[sampleNames[i]],-1.0,obsLimitMap[sampleNames[i]]); // obs limit 
    getLimitVal(hcombMap[sampleNames[i]],0.84,p1sLimitMap[sampleNames[i]]); // p1sig limit 
    getLimitVal(hcombMap[sampleNames[i]],0.16,n1sLimitMap[sampleNames[i]]); // n1sig limit
    expMuMap[sampleNames[i]] = expLimitMap[sampleNames[i]]/xsecMap[sampleNames[i]]; // exp signal significance 
    obsMuMap[sampleNames[i]] = obsLimitMap[sampleNames[i]]/xsecMap[sampleNames[i]]; // obs signal significance 
    p1sMuMap[sampleNames[i]] = p1sLimitMap[sampleNames[i]]/xsecMap[sampleNames[i]]; // p1sig signal significance 
    n1sMuMap[sampleNames[i]] = n1sLimitMap[sampleNames[i]]/xsecMap[sampleNames[i]]; // n1sig signal significance
    // setup 2D graphs
    g2d_exp->SetPoint(i,m1,m2,expMuMap[sampleNames[i]]); 
    g2d_obs->SetPoint(i,m1,m2,obsMuMap[sampleNames[i]]);
    g2d_p1s->SetPoint(i,m1,m2,p1sMuMap[sampleNames[i]]);
    g2d_n1s->SetPoint(i,m1,m2,n1sMuMap[sampleNames[i]]);
  }

  // convert tgraph to histo
  TH2D* h2_exp = new TH2D("h2_exp","h2_exp",990,10,1000,499,1,500);
  TH2D* h2_obs = new TH2D("h2_obs","h2_obs",990,10,1000,499,1,500);
  TH2D* h2_p1s = new TH2D("h2_p1s","h2_p1s",990,10,1000,499,1,500);
  TH2D* h2_n1s = new TH2D("h2_n1s","h2_n1s",990,10,1000,499,1,500);
  g2d_exp->SetHistogram(h2_exp);
  g2d_obs->SetHistogram(h2_obs);
  g2d_p1s->SetHistogram(h2_p1s);
  g2d_n1s->SetHistogram(h2_n1s);

  // get contours for each
  TGraph* gc_exp = NULL;
  TGraph* gc_obs = NULL;
  TGraph* gc_p1s = NULL;
  TGraph* gc_n1s = NULL;
  getContours(0, g2d_exp, gc_exp);
  getContours(1, g2d_obs, gc_obs); 
  getContours(2, g2d_p1s, gc_p1s); 
  getContours(3, g2d_n1s, gc_n1s);
 
  gStyle->SetPadRightMargin(0.109);
  gStyle->SetPadLeftMargin(0.13);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetNumberContours(505);

  // setup canvas and pad
  TCanvas *c_copy = new TCanvas("c_copy","c_copy",525,1113,800,795);
  TPad *p         = new TPad("p","",0.01,0.03,0.98,1.00);
  c_copy->cd();
  p->cd();
  setStyle(c_copy,p);
  c_copy->Update();

  // draw histos
  h2_obs->GetYaxis()->SetRangeUser(5,500);
  h2_obs->Draw("COLZ");
  h2_obs->SetMinimum(0.1);
  h2_obs->SetMaximum(50);
  g2d_obs->Draw("COLZ SAME");

  // setup axis labels
  TLatex *lxex = new TLatex(0.5363409,0.1963589,"m_{Z'} [GeV]"); 
  TLatex *lyex = new TLatex(0.03,0.77,"m_{#chi} [GeV]");
  TLatex *lzex = new TLatex(0.8859649,0.9440832,"Observed #mu 95% CL");
  lxex->SetTextSize(0.054);     
  lxex->SetTextAlign(12);
  lxex->SetNDC(kTRUE);  
  lxex->SetTextFont(42);
  lxex->Draw("same"); 
  lyex->SetTextSize(0.054);
  lyex->SetTextAlign(12);
  lyex->SetTextAngle(90);
  lyex->SetNDC(kTRUE);
  lyex->SetTextFont(42);
  lyex->Draw("same"); 
  lzex->SetTextSize(0.054);
  lzex->SetTextAlign(12);
  lzex->SetTextAngle(270);
  lzex->SetNDC(kTRUE);
  lzex->SetTextFont(42);
  lzex->Draw("same"); 

  // style for contours
  c_copy->RedrawAxis();
  gc_exp->SetLineColor(kBlack);
  gc_exp->SetLineStyle(1);
  gc_exp->SetLineWidth(2);
  gc_obs->SetLineColor(kRed);
  gc_obs->SetLineStyle(1);
  gc_obs->SetLineWidth(2);
  gc_p1s->SetLineStyle(0);
  gc_n1s->SetLineStyle(0);
  gc_p1s->SetFillStyle(0);
  gc_n1s->SetFillStyle(0);

  // draw contours
  gc_obs->Draw("Csame");
  gc_exp->Draw("Csame");
  gc_p1s->Draw("Csame");
  gc_n1s->Draw("Csame");

  // setup legend
  TLegend* cleg = new TLegend(0.19,0.80,0.45,0.88,NULL,"brNDC"); // (x1,y1,x2,y2)
  cleg->SetBorderSize(0);
  cleg->SetLineColor(1);
  cleg->SetLineWidth(1);
  cleg->SetLineStyle(1);
  cleg->SetTextFont(62);
  cleg->AddEntry(gc_obs,"Observed 95\% CL","L");
  cleg->AddEntry(gc_exp,"Median Expected 95\% CL","L");
  cleg->AddEntry(gc_p1s,"Expected #pm 1#sigma_{experiment}","L");
  cleg->Draw("same");

  // save plot
  c_copy->cd();
  c_copy->SetLogz();
  TLatex *l1; TLatex *l2; TLatex *l3; TLatex *l4;
  setCMSLabels(l1,l2,l3,l4,type); // add CMS labels
  l1->Draw("same");
  l2->Draw("same");
  l3->Draw("same");
  //l4->Draw("same");
  c_copy->SaveAs(TString::Format("%sTEST_ZpBaryContour.png",outDir.Data())); 
  c_copy->SaveAs(TString::Format("%sTEST_ZpBaryContour.pdf",outDir.Data())); 

}

void setCMSLabels(TLatex* & l1, TLatex* & l2, TLatex* & l3, TLatex* & l4, int type){

  TString latexCMSname = "#bf{CMS} #it{Preliminary}";
  l1 = new TLatex(0.16,0.97,latexCMSname);
  l1->SetTextSize(0.036);
  l1->SetTextAlign(12);
  l1->SetNDC(kTRUE);
  l1->SetTextFont(42);

  TString latexlumi = "35.9 fb^{-1}";
  TString latexenergy = " (13 TeV)";
  TString latexname = latexlumi+latexenergy;
  l2 = new TLatex(0.505,.97,latexname);
  l2->SetTextSize(0.033);
  l2->SetTextAlign(12);
  l2->SetNDC(kTRUE);
  l2->SetTextFont(42);
 
  TString thestring = "Z'#rightarrow DM+h(#gamma#gamma)";
  TString addmodel  = ""; 
  if (type==0) addmodel = "(Baryonic)";
  if (type==1) addmodel = "(2HDM)"; 

  l3 = new TLatex(0.20,0.90,thestring);
  l3->SetTextSize(0.033);
  l3->SetTextAlign(12);
  l3->SetNDC(kTRUE);
  l3->SetTextFont(42);
  l4 = new TLatex(0.20,0.87,addmodel);
  l4->SetTextSize(0.031);
  l4->SetTextAlign(12);
  l4->SetNDC(kTRUE);
  l4->SetTextFont(42);

}

void setStyle(TCanvas* c, TPad* p){

  c->Range(-261.1739,-215.1203,1456.261,537.1745);
  c->SetFillColor(0);
  c->SetBorderMode(0);
  c->SetBorderSize(2);
  c->SetTickx(1);
  c->SetTicky(1);
  c->SetLeftMargin(0.1578947);
  c->SetRightMargin(0.2656642);
  c->SetTopMargin(0.04941482);
  c->SetBottomMargin(0.2925878);
  c->SetFrameFillStyle(0);
  c->SetFrameLineWidth(3);
  c->SetFrameBorderMode(0);
  c->SetFrameFillStyle(0);
  c->SetFrameLineWidth(3);
  c->SetFrameBorderMode(0);

  p->SetLogz();
  c->cd();

}

void getInterpolation(TGraph* gc, bool isFirst, Double_t & xobs){

  double* xvals=gc->GetX();
  double* yvals=gc->GetY();
  double deltaylow=999999999;
  double deltayup=999999999;
  double yobs=1.;
  double yup=999.;
  double xup=999.;
  double ylow=999.;
  double xlow=999.; 

  int binmin=13;
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
    for(int i=binmin;i<gc->GetN(); i++){
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

  double m=(yup-ylow)/(xup-xlow);
  xobs=(1-ylow+m*xlow)/m; //output
}

void getContours(int j, TGraph2D* g, TGraph* & gc){
  TCanvas* c = new TCanvas(TString::Format("c%d",j),"",800,800); 
  c->cd();
  TH2D* h = new TH2D(TString::Format("h%d",j),"",990,10,1000,499,1,500);
  h = g->GetHistogram();
   
  Double_t contours[1];
  contours[0] = 1.;
  
  h->SetContour(1,contours);
  h->Draw("CONT Z LIST");
  c->Update();

  // Get contours
  TObjArray *conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TList* contLevel = NULL;
  TGraph* curv     = NULL;
  //TGraph* gc       = NULL;

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
  for(int i = 0; i < TotalConts; i++){ // loop over each contour 
    contLevel = (TList*)conts->At(i);

    // Get first graph from list on curves on this level 
    curv = (TGraph*)contLevel->First();
    for(int j = 0; j < 1; j++){// for each, get each curve 
      curv->GetPoint(0, x0, y0);
      nGraphs ++;
      printf("\tGraph: %d  -- %d Elements\n", nGraphs,curv->GetN());
      // Draw clones of the graphs to avoid deletions in case the 1st pad is redrawn. 
      gc = (TGraph*)curv->Clone();
      // gc->Draw("Csame");
      mgg->Add(gc);
      curv = (TGraph*)contLevel->After(curv); // get next graph    

    }
  }
  delete h;
  delete c;
}

void getLimitVal(TFile* file, Double_t quantile, Double_t & Limit){
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
      //std::cout << "Quantile = " << quantileExpected << std::endl;
      //std::cout << "Limit    = " << limit << std::endl;
      if (quantileExpected==quantile) Limit=limit;
      if (quantileExpected>quantile-0.01 && quantileExpected<quantile+0.01) Limit=limit;
    }    
  }// end valid tree
  else Limit = 0;
  delete tree;

}

void getHCombFile(TString inDir, TString name, int type, TFile* & higgsCombineFile){
  int m1, m2;
  getIntMasses(name,type,m1,m2);
  higgsCombineFile = new TFile(TString::Format("%s/higgsCombineMonoHgg_sig_%s.Asymptotic.mH%d.root",inDir.Data(),name.Data(),m1));
}

void getIntMasses(TString name, int type, int & m1, int & m2){
  //pick out mZP mass 
  string sname = name.Data(); 
  string delimiterM1 = "_mZP";
  string delimiterM2 = "_mChi";
  if (type==1) delimiterM2 = "_mA0";
  size_t posM1 = sname.find(delimiterM1);
  size_t posM2 = sname.find(delimiterM2);
  string smass1 = sname.substr(posM1+delimiterM1.length(),posM2-posM1-delimiterM1.length());
  string smass2 = sname.substr(posM2+delimiterM2.length(),sname.length());
  const char * mass1 = smass1.c_str();
  const char * mass2 = smass2.c_str(); 
  m1 = std::atoi(mass1);
  m2 = std::atoi(mass2); 
  //std::cout << " Mass 1 = " << mass1 << " , Mass 2 = " << mass2 << std::endl;
}

void getXsecBary(TFile* file, int mZp, int mchi, Double_t & xsec){
  TH2F* xsecs = (TH2F*)file->Get("h2_BARY_XSEC_pb"); 
  if (xsecs!=(TH2F*)NULL){
    xsec = xsecs->Interpolate(mZp, mchi);
    //xsec = xsecs->GetBinContent(xsecs->GetXaxis()->FindBin(mZp),xsecs->GetYaxis()->FindBin(mchi));
    //std::cout<<" mZp: "<<mZp<< " mCHI: "<<mchi<< " XSEC: "<<xsec<<std::endl;
  }
  else{
   xsec = 1;
   std::cout << "Couldn't find xsec histogram" << std::endl;
  }
} 

void getXsec2HDM(TFile* file, int mA0, int mZp, Double_t & xsec){
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

void getMassPoints( std::vector<TString> & names ){

  int mZp[25] = {10,20,30,50,75,100,150,200,250,300,400,500,600,700,900,1200,1500,2000,2500,3000,4000,5000,6000,8000,10000}; 
  //int mDM[28] = {5,10,20,40,50,60,75,100,125,150,175,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000};
  int mDM[21] = {5,10,20,40,60,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000};
  for (int m1 = 0; m1 < 25; m1++){
    for (int m2 = 0; m2 < 21; m2++){
      names.push_back(TString::Format("ZpBaryonic_mZP%i_mChi%i",mZp[m1],mDM[m2]));
    }
  } 

  //names.push_back("ZpBaryonic_mZP10000_mChi1");
  //names.push_back("ZpBaryonic_mZP10000_mChi10");
  //names.push_back("ZpBaryonic_mZP10000_mChi100");
  //names.push_back("ZpBaryonic_mZP10000_mChi1000");
  //names.push_back("ZpBaryonic_mZP10000_mChi125");
  //names.push_back("ZpBaryonic_mZP10000_mChi150");
  //names.push_back("ZpBaryonic_mZP10000_mChi175");
  //names.push_back("ZpBaryonic_mZP10000_mChi20");
  //names.push_back("ZpBaryonic_mZP10000_mChi200");
  //names.push_back("ZpBaryonic_mZP10000_mChi250");
  //names.push_back("ZpBaryonic_mZP10000_mChi300");
  //names.push_back("ZpBaryonic_mZP10000_mChi350");
  //names.push_back("ZpBaryonic_mZP10000_mChi40");
  //names.push_back("ZpBaryonic_mZP10000_mChi400");
  //names.push_back("ZpBaryonic_mZP10000_mChi450");
  //names.push_back("ZpBaryonic_mZP10000_mChi5");
  //names.push_back("ZpBaryonic_mZP10000_mChi50");
  //names.push_back("ZpBaryonic_mZP10000_mChi500");
  //names.push_back("ZpBaryonic_mZP10000_mChi60");
  //names.push_back("ZpBaryonic_mZP10000_mChi600");
  //names.push_back("ZpBaryonic_mZP10000_mChi700");
  //names.push_back("ZpBaryonic_mZP10000_mChi800");
  //names.push_back("ZpBaryonic_mZP10000_mChi900");
  //names.push_back("ZpBaryonic_mZP1000_mChi1");
  //names.push_back("ZpBaryonic_mZP1000_mChi10");
  //names.push_back("ZpBaryonic_mZP1000_mChi1000");
  //names.push_back("ZpBaryonic_mZP1000_mChi150");
  //names.push_back("ZpBaryonic_mZP1000_mChi50");
  //names.push_back("ZpBaryonic_mZP1000_mChi500");
  //names.push_back("ZpBaryonic_mZP100_mChi1");
  //names.push_back("ZpBaryonic_mZP100_mChi10");
  //names.push_back("ZpBaryonic_mZP100_mChi100");
  //names.push_back("ZpBaryonic_mZP100_mChi1000");
  //names.push_back("ZpBaryonic_mZP100_mChi125");
  //names.push_back("ZpBaryonic_mZP100_mChi150");
  //names.push_back("ZpBaryonic_mZP100_mChi175");
  //names.push_back("ZpBaryonic_mZP100_mChi20");
  //names.push_back("ZpBaryonic_mZP100_mChi200");
  //names.push_back("ZpBaryonic_mZP100_mChi250");
  //names.push_back("ZpBaryonic_mZP100_mChi300");
  //names.push_back("ZpBaryonic_mZP100_mChi350");
  //names.push_back("ZpBaryonic_mZP100_mChi40");
  //names.push_back("ZpBaryonic_mZP100_mChi400");
  //names.push_back("ZpBaryonic_mZP100_mChi450");
  //names.push_back("ZpBaryonic_mZP100_mChi5");
  //names.push_back("ZpBaryonic_mZP100_mChi50");
  //names.push_back("ZpBaryonic_mZP100_mChi500");
  //names.push_back("ZpBaryonic_mZP100_mChi60");
  //names.push_back("ZpBaryonic_mZP100_mChi600");
  //names.push_back("ZpBaryonic_mZP100_mChi700");
  //names.push_back("ZpBaryonic_mZP100_mChi800");
  //names.push_back("ZpBaryonic_mZP100_mChi900");
  //names.push_back("ZpBaryonic_mZP10_mChi1");
  //names.push_back("ZpBaryonic_mZP10_mChi10");
  //names.push_back("ZpBaryonic_mZP10_mChi100");
  //names.push_back("ZpBaryonic_mZP10_mChi1000");
  //names.push_back("ZpBaryonic_mZP10_mChi125");
  //names.push_back("ZpBaryonic_mZP10_mChi150");
  //names.push_back("ZpBaryonic_mZP10_mChi175");
  //names.push_back("ZpBaryonic_mZP10_mChi20");
  //names.push_back("ZpBaryonic_mZP10_mChi200");
  //names.push_back("ZpBaryonic_mZP10_mChi250");
  //names.push_back("ZpBaryonic_mZP10_mChi300");
  //names.push_back("ZpBaryonic_mZP10_mChi350");
  //names.push_back("ZpBaryonic_mZP10_mChi40");
  //names.push_back("ZpBaryonic_mZP10_mChi400");
  //names.push_back("ZpBaryonic_mZP10_mChi450");
  //names.push_back("ZpBaryonic_mZP10_mChi5");
  //names.push_back("ZpBaryonic_mZP10_mChi50");
  //names.push_back("ZpBaryonic_mZP10_mChi500");
  //names.push_back("ZpBaryonic_mZP10_mChi60");
  //names.push_back("ZpBaryonic_mZP10_mChi600");
  //names.push_back("ZpBaryonic_mZP10_mChi700");
  //names.push_back("ZpBaryonic_mZP10_mChi800");
  //names.push_back("ZpBaryonic_mZP10_mChi900");
  //names.push_back("ZpBaryonic_mZP1200_mChi10");
  //names.push_back("ZpBaryonic_mZP1200_mChi100");
  //names.push_back("ZpBaryonic_mZP1200_mChi1000");
  //names.push_back("ZpBaryonic_mZP1200_mChi125");
  //names.push_back("ZpBaryonic_mZP1200_mChi150");
  //names.push_back("ZpBaryonic_mZP1200_mChi175");
  //names.push_back("ZpBaryonic_mZP1200_mChi20");
  //names.push_back("ZpBaryonic_mZP1200_mChi200");
  //names.push_back("ZpBaryonic_mZP1200_mChi250");
  //names.push_back("ZpBaryonic_mZP1200_mChi300");
  //names.push_back("ZpBaryonic_mZP1200_mChi350");
  //names.push_back("ZpBaryonic_mZP1200_mChi40");
  //names.push_back("ZpBaryonic_mZP1200_mChi400");
  //names.push_back("ZpBaryonic_mZP1200_mChi450");
  //names.push_back("ZpBaryonic_mZP1200_mChi5");
  //names.push_back("ZpBaryonic_mZP1200_mChi500");
  //names.push_back("ZpBaryonic_mZP1200_mChi60");
  //names.push_back("ZpBaryonic_mZP1200_mChi600");
  //names.push_back("ZpBaryonic_mZP1200_mChi700");
  //names.push_back("ZpBaryonic_mZP1200_mChi800");
  //names.push_back("ZpBaryonic_mZP1200_mChi900");
  //names.push_back("ZpBaryonic_mZP1500_mChi10");
  //names.push_back("ZpBaryonic_mZP1500_mChi100");
  //names.push_back("ZpBaryonic_mZP1500_mChi1000");
  //names.push_back("ZpBaryonic_mZP1500_mChi125");
  //names.push_back("ZpBaryonic_mZP1500_mChi150");
  //names.push_back("ZpBaryonic_mZP1500_mChi175");
  //names.push_back("ZpBaryonic_mZP1500_mChi20");
  //names.push_back("ZpBaryonic_mZP1500_mChi200");
  //names.push_back("ZpBaryonic_mZP1500_mChi250");
  //names.push_back("ZpBaryonic_mZP1500_mChi300");
  //names.push_back("ZpBaryonic_mZP1500_mChi350");
  //names.push_back("ZpBaryonic_mZP1500_mChi40");
  //names.push_back("ZpBaryonic_mZP1500_mChi400");
  //names.push_back("ZpBaryonic_mZP1500_mChi450");
  //names.push_back("ZpBaryonic_mZP1500_mChi5");
  //names.push_back("ZpBaryonic_mZP1500_mChi500");
  //names.push_back("ZpBaryonic_mZP1500_mChi60");
  //names.push_back("ZpBaryonic_mZP1500_mChi600");
  //names.push_back("ZpBaryonic_mZP1500_mChi700");
  //names.push_back("ZpBaryonic_mZP1500_mChi800");
  //names.push_back("ZpBaryonic_mZP1500_mChi900");
  //names.push_back("ZpBaryonic_mZP150_mChi10");
  //names.push_back("ZpBaryonic_mZP150_mChi100");
  //names.push_back("ZpBaryonic_mZP150_mChi1000");
  //names.push_back("ZpBaryonic_mZP150_mChi125");
  //names.push_back("ZpBaryonic_mZP150_mChi150");
  //names.push_back("ZpBaryonic_mZP150_mChi175");
  //names.push_back("ZpBaryonic_mZP150_mChi20");
  //names.push_back("ZpBaryonic_mZP150_mChi200");
  //names.push_back("ZpBaryonic_mZP150_mChi250");
  //names.push_back("ZpBaryonic_mZP150_mChi300");
  //names.push_back("ZpBaryonic_mZP150_mChi350");
  //names.push_back("ZpBaryonic_mZP150_mChi40");
  //names.push_back("ZpBaryonic_mZP150_mChi400");
  //names.push_back("ZpBaryonic_mZP150_mChi450");
  //names.push_back("ZpBaryonic_mZP150_mChi5");
  //names.push_back("ZpBaryonic_mZP150_mChi500");
  //names.push_back("ZpBaryonic_mZP150_mChi60");
  //names.push_back("ZpBaryonic_mZP150_mChi600");
  //names.push_back("ZpBaryonic_mZP150_mChi700");
  //names.push_back("ZpBaryonic_mZP150_mChi800");
  //names.push_back("ZpBaryonic_mZP150_mChi900");
  //names.push_back("ZpBaryonic_mZP15_mChi1");
  //names.push_back("ZpBaryonic_mZP15_mChi10");
  //names.push_back("ZpBaryonic_mZP15_mChi1000");
  //names.push_back("ZpBaryonic_mZP15_mChi150");
  //names.push_back("ZpBaryonic_mZP15_mChi50");
  //names.push_back("ZpBaryonic_mZP15_mChi500");
  //names.push_back("ZpBaryonic_mZP1995_mChi1");
  //names.push_back("ZpBaryonic_mZP1995_mChi10");
  //names.push_back("ZpBaryonic_mZP1995_mChi1000");
  //names.push_back("ZpBaryonic_mZP1995_mChi150");
  //names.push_back("ZpBaryonic_mZP1995_mChi50");
  //names.push_back("ZpBaryonic_mZP1995_mChi500");
  //names.push_back("ZpBaryonic_mZP2000_mChi1");
  //names.push_back("ZpBaryonic_mZP2000_mChi10");
  //names.push_back("ZpBaryonic_mZP2000_mChi100");
  //names.push_back("ZpBaryonic_mZP2000_mChi1000");
  //names.push_back("ZpBaryonic_mZP2000_mChi125");
  //names.push_back("ZpBaryonic_mZP2000_mChi150");
  //names.push_back("ZpBaryonic_mZP2000_mChi175");
  //names.push_back("ZpBaryonic_mZP2000_mChi20");
  //names.push_back("ZpBaryonic_mZP2000_mChi200");
  //names.push_back("ZpBaryonic_mZP2000_mChi250");
  //names.push_back("ZpBaryonic_mZP2000_mChi300");
  //names.push_back("ZpBaryonic_mZP2000_mChi350");
  //names.push_back("ZpBaryonic_mZP2000_mChi40");
  //names.push_back("ZpBaryonic_mZP2000_mChi400");
  //names.push_back("ZpBaryonic_mZP2000_mChi450");
  //names.push_back("ZpBaryonic_mZP2000_mChi5");
  //names.push_back("ZpBaryonic_mZP2000_mChi50");
  //names.push_back("ZpBaryonic_mZP2000_mChi500");
  //names.push_back("ZpBaryonic_mZP2000_mChi60");
  //names.push_back("ZpBaryonic_mZP2000_mChi600");
  //names.push_back("ZpBaryonic_mZP2000_mChi700");
  //names.push_back("ZpBaryonic_mZP2000_mChi800");
  //names.push_back("ZpBaryonic_mZP2000_mChi900");
  //names.push_back("ZpBaryonic_mZP200_mChi1");
  //names.push_back("ZpBaryonic_mZP200_mChi10");
  //names.push_back("ZpBaryonic_mZP200_mChi100");
  //names.push_back("ZpBaryonic_mZP200_mChi1000");
  //names.push_back("ZpBaryonic_mZP200_mChi125");
  //names.push_back("ZpBaryonic_mZP200_mChi150");
  //names.push_back("ZpBaryonic_mZP200_mChi175");
  //names.push_back("ZpBaryonic_mZP200_mChi20");
  //names.push_back("ZpBaryonic_mZP200_mChi200");
  //names.push_back("ZpBaryonic_mZP200_mChi250");
  //names.push_back("ZpBaryonic_mZP200_mChi300");
  //names.push_back("ZpBaryonic_mZP200_mChi350");
  //names.push_back("ZpBaryonic_mZP200_mChi40");
  //names.push_back("ZpBaryonic_mZP200_mChi400");
  //names.push_back("ZpBaryonic_mZP200_mChi450");
  //names.push_back("ZpBaryonic_mZP200_mChi5");
  //names.push_back("ZpBaryonic_mZP200_mChi50");
  //names.push_back("ZpBaryonic_mZP200_mChi500");
  //names.push_back("ZpBaryonic_mZP200_mChi60");
  //names.push_back("ZpBaryonic_mZP200_mChi600");
  //names.push_back("ZpBaryonic_mZP200_mChi700");
  //names.push_back("ZpBaryonic_mZP200_mChi800");
  //names.push_back("ZpBaryonic_mZP200_mChi900");
  //names.push_back("ZpBaryonic_mZP20_mChi1");
  //names.push_back("ZpBaryonic_mZP20_mChi10");
  //names.push_back("ZpBaryonic_mZP20_mChi100");
  //names.push_back("ZpBaryonic_mZP20_mChi1000");
  //names.push_back("ZpBaryonic_mZP20_mChi125");
  //names.push_back("ZpBaryonic_mZP20_mChi150");
  //names.push_back("ZpBaryonic_mZP20_mChi175");
  //names.push_back("ZpBaryonic_mZP20_mChi20");
  //names.push_back("ZpBaryonic_mZP20_mChi200");
  //names.push_back("ZpBaryonic_mZP20_mChi250");
  //names.push_back("ZpBaryonic_mZP20_mChi300");
  //names.push_back("ZpBaryonic_mZP20_mChi350");
  //names.push_back("ZpBaryonic_mZP20_mChi40");
  //names.push_back("ZpBaryonic_mZP20_mChi400");
  //names.push_back("ZpBaryonic_mZP20_mChi450");
  //names.push_back("ZpBaryonic_mZP20_mChi5");
  //names.push_back("ZpBaryonic_mZP20_mChi50");
  //names.push_back("ZpBaryonic_mZP20_mChi500");
  //names.push_back("ZpBaryonic_mZP20_mChi60");
  //names.push_back("ZpBaryonic_mZP20_mChi600");
  //names.push_back("ZpBaryonic_mZP20_mChi700");
  //names.push_back("ZpBaryonic_mZP20_mChi800");
  //names.push_back("ZpBaryonic_mZP20_mChi900");
  //names.push_back("ZpBaryonic_mZP2500_mChi10");
  //names.push_back("ZpBaryonic_mZP2500_mChi100");
  //names.push_back("ZpBaryonic_mZP2500_mChi1000");
  //names.push_back("ZpBaryonic_mZP2500_mChi125");
  //names.push_back("ZpBaryonic_mZP2500_mChi150");
  //names.push_back("ZpBaryonic_mZP2500_mChi175");
  //names.push_back("ZpBaryonic_mZP2500_mChi20");
  //names.push_back("ZpBaryonic_mZP2500_mChi200");
  //names.push_back("ZpBaryonic_mZP2500_mChi250");
  //names.push_back("ZpBaryonic_mZP2500_mChi300");
  //names.push_back("ZpBaryonic_mZP2500_mChi350");
  //names.push_back("ZpBaryonic_mZP2500_mChi40");
  //names.push_back("ZpBaryonic_mZP2500_mChi400");
  //names.push_back("ZpBaryonic_mZP2500_mChi450");
  //names.push_back("ZpBaryonic_mZP2500_mChi5");
  //names.push_back("ZpBaryonic_mZP2500_mChi500");
  //names.push_back("ZpBaryonic_mZP2500_mChi60");
  //names.push_back("ZpBaryonic_mZP2500_mChi600");
  //names.push_back("ZpBaryonic_mZP2500_mChi700");
  //names.push_back("ZpBaryonic_mZP2500_mChi800");
  //names.push_back("ZpBaryonic_mZP2500_mChi900");
  //names.push_back("ZpBaryonic_mZP250_mChi10");
  //names.push_back("ZpBaryonic_mZP250_mChi100");
  //names.push_back("ZpBaryonic_mZP250_mChi1000");
  //names.push_back("ZpBaryonic_mZP250_mChi125");
  //names.push_back("ZpBaryonic_mZP250_mChi150");
  //names.push_back("ZpBaryonic_mZP250_mChi175");
  //names.push_back("ZpBaryonic_mZP250_mChi20");
  //names.push_back("ZpBaryonic_mZP250_mChi200");
  //names.push_back("ZpBaryonic_mZP250_mChi250");
  //names.push_back("ZpBaryonic_mZP250_mChi300");
  //names.push_back("ZpBaryonic_mZP250_mChi350");
  //names.push_back("ZpBaryonic_mZP250_mChi40");
  //names.push_back("ZpBaryonic_mZP250_mChi400");
  //names.push_back("ZpBaryonic_mZP250_mChi450");
  //names.push_back("ZpBaryonic_mZP250_mChi5");
  //names.push_back("ZpBaryonic_mZP250_mChi500");
  //names.push_back("ZpBaryonic_mZP250_mChi60");
  //names.push_back("ZpBaryonic_mZP250_mChi600");
  //names.push_back("ZpBaryonic_mZP250_mChi700");
  //names.push_back("ZpBaryonic_mZP250_mChi800");
  //names.push_back("ZpBaryonic_mZP250_mChi900");
  //names.push_back("ZpBaryonic_mZP295_mChi1");
  //names.push_back("ZpBaryonic_mZP295_mChi10");
  //names.push_back("ZpBaryonic_mZP295_mChi1000");
  //names.push_back("ZpBaryonic_mZP295_mChi150");
  //names.push_back("ZpBaryonic_mZP295_mChi50");
  //names.push_back("ZpBaryonic_mZP295_mChi500");
  //names.push_back("ZpBaryonic_mZP3000_mChi10");
  //names.push_back("ZpBaryonic_mZP3000_mChi100");
  //names.push_back("ZpBaryonic_mZP3000_mChi1000");
  //names.push_back("ZpBaryonic_mZP3000_mChi125");
  //names.push_back("ZpBaryonic_mZP3000_mChi150");
  //names.push_back("ZpBaryonic_mZP3000_mChi175");
  //names.push_back("ZpBaryonic_mZP3000_mChi20");
  //names.push_back("ZpBaryonic_mZP3000_mChi200");
  //names.push_back("ZpBaryonic_mZP3000_mChi250");
  //names.push_back("ZpBaryonic_mZP3000_mChi300");
  //names.push_back("ZpBaryonic_mZP3000_mChi350");
  //names.push_back("ZpBaryonic_mZP3000_mChi40");
  //names.push_back("ZpBaryonic_mZP3000_mChi400");
  //names.push_back("ZpBaryonic_mZP3000_mChi450");
  //names.push_back("ZpBaryonic_mZP3000_mChi5");
  //names.push_back("ZpBaryonic_mZP3000_mChi500");
  //names.push_back("ZpBaryonic_mZP3000_mChi60");
  //names.push_back("ZpBaryonic_mZP3000_mChi600");
  //names.push_back("ZpBaryonic_mZP3000_mChi700");
  //names.push_back("ZpBaryonic_mZP3000_mChi800");
  //names.push_back("ZpBaryonic_mZP3000_mChi900");
  //names.push_back("ZpBaryonic_mZP300_mChi1");
  //names.push_back("ZpBaryonic_mZP300_mChi10");
  //names.push_back("ZpBaryonic_mZP300_mChi100");
  //names.push_back("ZpBaryonic_mZP300_mChi1000");
  //names.push_back("ZpBaryonic_mZP300_mChi125");
  //names.push_back("ZpBaryonic_mZP300_mChi150");
  //names.push_back("ZpBaryonic_mZP300_mChi175");
  //names.push_back("ZpBaryonic_mZP300_mChi20");
  //names.push_back("ZpBaryonic_mZP300_mChi200");
  //names.push_back("ZpBaryonic_mZP300_mChi250");
  //names.push_back("ZpBaryonic_mZP300_mChi300");
  //names.push_back("ZpBaryonic_mZP300_mChi350");
  //names.push_back("ZpBaryonic_mZP300_mChi40");
  //names.push_back("ZpBaryonic_mZP300_mChi400");
  //names.push_back("ZpBaryonic_mZP300_mChi450");
  //names.push_back("ZpBaryonic_mZP300_mChi5");
  //names.push_back("ZpBaryonic_mZP300_mChi50");
  //names.push_back("ZpBaryonic_mZP300_mChi500");
  //names.push_back("ZpBaryonic_mZP300_mChi60");
  //names.push_back("ZpBaryonic_mZP300_mChi600");
  //names.push_back("ZpBaryonic_mZP300_mChi700");
  //names.push_back("ZpBaryonic_mZP300_mChi800");
  //names.push_back("ZpBaryonic_mZP300_mChi900");
  //names.push_back("ZpBaryonic_mZP30_mChi10");
  //names.push_back("ZpBaryonic_mZP30_mChi100");
  //names.push_back("ZpBaryonic_mZP30_mChi1000");
  //names.push_back("ZpBaryonic_mZP30_mChi125");
  //names.push_back("ZpBaryonic_mZP30_mChi150");
  //names.push_back("ZpBaryonic_mZP30_mChi175");
  //names.push_back("ZpBaryonic_mZP30_mChi20");
  //names.push_back("ZpBaryonic_mZP30_mChi200");
  //names.push_back("ZpBaryonic_mZP30_mChi250");
  //names.push_back("ZpBaryonic_mZP30_mChi300");
  //names.push_back("ZpBaryonic_mZP30_mChi350");
  //names.push_back("ZpBaryonic_mZP30_mChi40");
  //names.push_back("ZpBaryonic_mZP30_mChi400");
  //names.push_back("ZpBaryonic_mZP30_mChi450");
  //names.push_back("ZpBaryonic_mZP30_mChi5");
  //names.push_back("ZpBaryonic_mZP30_mChi500");
  //names.push_back("ZpBaryonic_mZP30_mChi60");
  //names.push_back("ZpBaryonic_mZP30_mChi600");
  //names.push_back("ZpBaryonic_mZP30_mChi700");
  //names.push_back("ZpBaryonic_mZP30_mChi800");
  //names.push_back("ZpBaryonic_mZP30_mChi900");
  //names.push_back("ZpBaryonic_mZP4000_mChi10");
  //names.push_back("ZpBaryonic_mZP4000_mChi100");
  //names.push_back("ZpBaryonic_mZP4000_mChi1000");
  //names.push_back("ZpBaryonic_mZP4000_mChi125");
  //names.push_back("ZpBaryonic_mZP4000_mChi150");
  //names.push_back("ZpBaryonic_mZP4000_mChi175");
  //names.push_back("ZpBaryonic_mZP4000_mChi20");
  //names.push_back("ZpBaryonic_mZP4000_mChi200");
  //names.push_back("ZpBaryonic_mZP4000_mChi250");
  //names.push_back("ZpBaryonic_mZP4000_mChi300");
  //names.push_back("ZpBaryonic_mZP4000_mChi350");
  //names.push_back("ZpBaryonic_mZP4000_mChi40");
  //names.push_back("ZpBaryonic_mZP4000_mChi400");
  //names.push_back("ZpBaryonic_mZP4000_mChi450");
  //names.push_back("ZpBaryonic_mZP4000_mChi5");
  //names.push_back("ZpBaryonic_mZP4000_mChi500");
  //names.push_back("ZpBaryonic_mZP4000_mChi60");
  //names.push_back("ZpBaryonic_mZP4000_mChi600");
  //names.push_back("ZpBaryonic_mZP4000_mChi700");
  //names.push_back("ZpBaryonic_mZP4000_mChi800");
  //names.push_back("ZpBaryonic_mZP4000_mChi900");
  //names.push_back("ZpBaryonic_mZP400_mChi10");
  //names.push_back("ZpBaryonic_mZP400_mChi100");
  //names.push_back("ZpBaryonic_mZP400_mChi1000");
  //names.push_back("ZpBaryonic_mZP400_mChi125");
  //names.push_back("ZpBaryonic_mZP400_mChi150");
  //names.push_back("ZpBaryonic_mZP400_mChi175");
  //names.push_back("ZpBaryonic_mZP400_mChi20");
  //names.push_back("ZpBaryonic_mZP400_mChi200");
  //names.push_back("ZpBaryonic_mZP400_mChi250");
  //names.push_back("ZpBaryonic_mZP400_mChi300");
  //names.push_back("ZpBaryonic_mZP400_mChi350");
  //names.push_back("ZpBaryonic_mZP400_mChi40");
  //names.push_back("ZpBaryonic_mZP400_mChi400");
  //names.push_back("ZpBaryonic_mZP400_mChi450");
  //names.push_back("ZpBaryonic_mZP400_mChi5");
  //names.push_back("ZpBaryonic_mZP400_mChi500");
  //names.push_back("ZpBaryonic_mZP400_mChi60");
  //names.push_back("ZpBaryonic_mZP400_mChi600");
  //names.push_back("ZpBaryonic_mZP400_mChi700");
  //names.push_back("ZpBaryonic_mZP400_mChi800");
  //names.push_back("ZpBaryonic_mZP400_mChi900");
  //names.push_back("ZpBaryonic_mZP5000_mChi10");
  //names.push_back("ZpBaryonic_mZP5000_mChi100");
  //names.push_back("ZpBaryonic_mZP5000_mChi1000");
  //names.push_back("ZpBaryonic_mZP5000_mChi125");
  //names.push_back("ZpBaryonic_mZP5000_mChi150");
  //names.push_back("ZpBaryonic_mZP5000_mChi175");
  //names.push_back("ZpBaryonic_mZP5000_mChi20");
  //names.push_back("ZpBaryonic_mZP5000_mChi200");
  //names.push_back("ZpBaryonic_mZP5000_mChi250");
  //names.push_back("ZpBaryonic_mZP5000_mChi300");
  //names.push_back("ZpBaryonic_mZP5000_mChi350");
  //names.push_back("ZpBaryonic_mZP5000_mChi40");
  //names.push_back("ZpBaryonic_mZP5000_mChi400");
  //names.push_back("ZpBaryonic_mZP5000_mChi450");
  //names.push_back("ZpBaryonic_mZP5000_mChi5");
  //names.push_back("ZpBaryonic_mZP5000_mChi500");
  //names.push_back("ZpBaryonic_mZP5000_mChi60");
  //names.push_back("ZpBaryonic_mZP5000_mChi600");
  //names.push_back("ZpBaryonic_mZP5000_mChi700");
  //names.push_back("ZpBaryonic_mZP5000_mChi800");
  //names.push_back("ZpBaryonic_mZP5000_mChi900");
  //names.push_back("ZpBaryonic_mZP500_mChi1");
  //names.push_back("ZpBaryonic_mZP500_mChi10");
  //names.push_back("ZpBaryonic_mZP500_mChi100");
  //names.push_back("ZpBaryonic_mZP500_mChi1000");
  //names.push_back("ZpBaryonic_mZP500_mChi125");
  //names.push_back("ZpBaryonic_mZP500_mChi150");
  //names.push_back("ZpBaryonic_mZP500_mChi175");
  //names.push_back("ZpBaryonic_mZP500_mChi20");
  //names.push_back("ZpBaryonic_mZP500_mChi200");
  //names.push_back("ZpBaryonic_mZP500_mChi250");
  //names.push_back("ZpBaryonic_mZP500_mChi300");
  //names.push_back("ZpBaryonic_mZP500_mChi350");
  //names.push_back("ZpBaryonic_mZP500_mChi40");
  //names.push_back("ZpBaryonic_mZP500_mChi400");
  //names.push_back("ZpBaryonic_mZP500_mChi450");
  //names.push_back("ZpBaryonic_mZP500_mChi5");
  //names.push_back("ZpBaryonic_mZP500_mChi50");
  //names.push_back("ZpBaryonic_mZP500_mChi500");
  //names.push_back("ZpBaryonic_mZP500_mChi60");
  //names.push_back("ZpBaryonic_mZP500_mChi600");
  //names.push_back("ZpBaryonic_mZP500_mChi700");
  //names.push_back("ZpBaryonic_mZP500_mChi800");
  //names.push_back("ZpBaryonic_mZP500_mChi900");
  //names.push_back("ZpBaryonic_mZP50_mChi1");
  //names.push_back("ZpBaryonic_mZP50_mChi10");
  //names.push_back("ZpBaryonic_mZP50_mChi100");
  //names.push_back("ZpBaryonic_mZP50_mChi1000");
  //names.push_back("ZpBaryonic_mZP50_mChi125");
  //names.push_back("ZpBaryonic_mZP50_mChi150");
  //names.push_back("ZpBaryonic_mZP50_mChi175");
  //names.push_back("ZpBaryonic_mZP50_mChi20");
  //names.push_back("ZpBaryonic_mZP50_mChi200");
  //names.push_back("ZpBaryonic_mZP50_mChi250");
  //names.push_back("ZpBaryonic_mZP50_mChi300");
  //names.push_back("ZpBaryonic_mZP50_mChi350");
  //names.push_back("ZpBaryonic_mZP50_mChi40");
  //names.push_back("ZpBaryonic_mZP50_mChi400");
  //names.push_back("ZpBaryonic_mZP50_mChi450");
  //names.push_back("ZpBaryonic_mZP50_mChi5");
  //names.push_back("ZpBaryonic_mZP50_mChi50");
  //names.push_back("ZpBaryonic_mZP50_mChi500");
  //names.push_back("ZpBaryonic_mZP50_mChi60");
  //names.push_back("ZpBaryonic_mZP50_mChi600");
  //names.push_back("ZpBaryonic_mZP50_mChi700");
  //names.push_back("ZpBaryonic_mZP50_mChi800");
  //names.push_back("ZpBaryonic_mZP50_mChi900");
  //names.push_back("ZpBaryonic_mZP6000_mChi10");
  //names.push_back("ZpBaryonic_mZP6000_mChi100");
  //names.push_back("ZpBaryonic_mZP6000_mChi1000");
  //names.push_back("ZpBaryonic_mZP6000_mChi125");
  //names.push_back("ZpBaryonic_mZP6000_mChi150");
  //names.push_back("ZpBaryonic_mZP6000_mChi175");
  //names.push_back("ZpBaryonic_mZP6000_mChi20");
  //names.push_back("ZpBaryonic_mZP6000_mChi200");
  //names.push_back("ZpBaryonic_mZP6000_mChi250");
  //names.push_back("ZpBaryonic_mZP6000_mChi300");
  //names.push_back("ZpBaryonic_mZP6000_mChi350");
  //names.push_back("ZpBaryonic_mZP6000_mChi40");
  //names.push_back("ZpBaryonic_mZP6000_mChi400");
  //names.push_back("ZpBaryonic_mZP6000_mChi450");
  //names.push_back("ZpBaryonic_mZP6000_mChi5");
  //names.push_back("ZpBaryonic_mZP6000_mChi500");
  //names.push_back("ZpBaryonic_mZP6000_mChi60");
  //names.push_back("ZpBaryonic_mZP6000_mChi600");
  //names.push_back("ZpBaryonic_mZP6000_mChi700");
  //names.push_back("ZpBaryonic_mZP6000_mChi800");
  //names.push_back("ZpBaryonic_mZP6000_mChi900");
  //names.push_back("ZpBaryonic_mZP600_mChi10");
  //names.push_back("ZpBaryonic_mZP600_mChi100");
  //names.push_back("ZpBaryonic_mZP600_mChi1000");
  //names.push_back("ZpBaryonic_mZP600_mChi125");
  //names.push_back("ZpBaryonic_mZP600_mChi150");
  //names.push_back("ZpBaryonic_mZP600_mChi175");
  //names.push_back("ZpBaryonic_mZP600_mChi20");
  //names.push_back("ZpBaryonic_mZP600_mChi200");
  //names.push_back("ZpBaryonic_mZP600_mChi250");
  //names.push_back("ZpBaryonic_mZP600_mChi300");
  //names.push_back("ZpBaryonic_mZP600_mChi350");
  //names.push_back("ZpBaryonic_mZP600_mChi40");
  //names.push_back("ZpBaryonic_mZP600_mChi400");
  //names.push_back("ZpBaryonic_mZP600_mChi450");
  //names.push_back("ZpBaryonic_mZP600_mChi5");
  //names.push_back("ZpBaryonic_mZP600_mChi500");
  //names.push_back("ZpBaryonic_mZP600_mChi60");
  //names.push_back("ZpBaryonic_mZP600_mChi600");
  //names.push_back("ZpBaryonic_mZP600_mChi700");
  //names.push_back("ZpBaryonic_mZP600_mChi800");
  //names.push_back("ZpBaryonic_mZP600_mChi900");
  //names.push_back("ZpBaryonic_mZP700_mChi10");
  //names.push_back("ZpBaryonic_mZP700_mChi100");
  //names.push_back("ZpBaryonic_mZP700_mChi1000");
  //names.push_back("ZpBaryonic_mZP700_mChi125");
  //names.push_back("ZpBaryonic_mZP700_mChi150");
  //names.push_back("ZpBaryonic_mZP700_mChi175");
  //names.push_back("ZpBaryonic_mZP700_mChi20");
  //names.push_back("ZpBaryonic_mZP700_mChi200");
  //names.push_back("ZpBaryonic_mZP700_mChi250");
  //names.push_back("ZpBaryonic_mZP700_mChi300");
  //names.push_back("ZpBaryonic_mZP700_mChi350");
  //names.push_back("ZpBaryonic_mZP700_mChi40");
  //names.push_back("ZpBaryonic_mZP700_mChi400");
  //names.push_back("ZpBaryonic_mZP700_mChi450");
  //names.push_back("ZpBaryonic_mZP700_mChi5");
  //names.push_back("ZpBaryonic_mZP700_mChi500");
  //names.push_back("ZpBaryonic_mZP700_mChi60");
  //names.push_back("ZpBaryonic_mZP700_mChi600");
  //names.push_back("ZpBaryonic_mZP700_mChi700");
  //names.push_back("ZpBaryonic_mZP700_mChi800");
  //names.push_back("ZpBaryonic_mZP700_mChi900");
  //names.push_back("ZpBaryonic_mZP75_mChi10");
  //names.push_back("ZpBaryonic_mZP75_mChi100");
  //names.push_back("ZpBaryonic_mZP75_mChi1000");
  //names.push_back("ZpBaryonic_mZP75_mChi125");
  //names.push_back("ZpBaryonic_mZP75_mChi150");
  //names.push_back("ZpBaryonic_mZP75_mChi175");
  //names.push_back("ZpBaryonic_mZP75_mChi20");
  //names.push_back("ZpBaryonic_mZP75_mChi200");
  //names.push_back("ZpBaryonic_mZP75_mChi250");
  //names.push_back("ZpBaryonic_mZP75_mChi300");
  //names.push_back("ZpBaryonic_mZP75_mChi350");
  //names.push_back("ZpBaryonic_mZP75_mChi40");
  //names.push_back("ZpBaryonic_mZP75_mChi400");
  //names.push_back("ZpBaryonic_mZP75_mChi450");
  //names.push_back("ZpBaryonic_mZP75_mChi5");
  //names.push_back("ZpBaryonic_mZP75_mChi500");
  //names.push_back("ZpBaryonic_mZP75_mChi60");
  //names.push_back("ZpBaryonic_mZP75_mChi600");
  //names.push_back("ZpBaryonic_mZP75_mChi700");
  //names.push_back("ZpBaryonic_mZP75_mChi800");
  //names.push_back("ZpBaryonic_mZP75_mChi900");
  //names.push_back("ZpBaryonic_mZP8000_mChi10");
  //names.push_back("ZpBaryonic_mZP8000_mChi100");
  //names.push_back("ZpBaryonic_mZP8000_mChi1000");
  //names.push_back("ZpBaryonic_mZP8000_mChi125");
  //names.push_back("ZpBaryonic_mZP8000_mChi150");
  //names.push_back("ZpBaryonic_mZP8000_mChi175");
  //names.push_back("ZpBaryonic_mZP8000_mChi20");
  //names.push_back("ZpBaryonic_mZP8000_mChi200");
  //names.push_back("ZpBaryonic_mZP8000_mChi250");
  //names.push_back("ZpBaryonic_mZP8000_mChi300");
  //names.push_back("ZpBaryonic_mZP8000_mChi350");
  //names.push_back("ZpBaryonic_mZP8000_mChi40");
  //names.push_back("ZpBaryonic_mZP8000_mChi400");
  //names.push_back("ZpBaryonic_mZP8000_mChi450");
  //names.push_back("ZpBaryonic_mZP8000_mChi5");
  //names.push_back("ZpBaryonic_mZP8000_mChi500");
  //names.push_back("ZpBaryonic_mZP8000_mChi60");
  //names.push_back("ZpBaryonic_mZP8000_mChi600");
  //names.push_back("ZpBaryonic_mZP8000_mChi700");
  //names.push_back("ZpBaryonic_mZP8000_mChi800");
  //names.push_back("ZpBaryonic_mZP8000_mChi900");
  //names.push_back("ZpBaryonic_mZP900_mChi10");
  //names.push_back("ZpBaryonic_mZP900_mChi100");
  //names.push_back("ZpBaryonic_mZP900_mChi1000");
  //names.push_back("ZpBaryonic_mZP900_mChi125");
  //names.push_back("ZpBaryonic_mZP900_mChi150");
  //names.push_back("ZpBaryonic_mZP900_mChi175");
  //names.push_back("ZpBaryonic_mZP900_mChi20");
  //names.push_back("ZpBaryonic_mZP900_mChi200");
  //names.push_back("ZpBaryonic_mZP900_mChi250");
  //names.push_back("ZpBaryonic_mZP900_mChi300");
  //names.push_back("ZpBaryonic_mZP900_mChi350");
  //names.push_back("ZpBaryonic_mZP900_mChi40");
  //names.push_back("ZpBaryonic_mZP900_mChi400");
  //names.push_back("ZpBaryonic_mZP900_mChi450");
  //names.push_back("ZpBaryonic_mZP900_mChi5");
  //names.push_back("ZpBaryonic_mZP900_mChi500");
  //names.push_back("ZpBaryonic_mZP900_mChi60");
  //names.push_back("ZpBaryonic_mZP900_mChi600");
  //names.push_back("ZpBaryonic_mZP900_mChi700");
  //names.push_back("ZpBaryonic_mZP900_mChi800");
  //names.push_back("ZpBaryonic_mZP900_mChi900");

}
