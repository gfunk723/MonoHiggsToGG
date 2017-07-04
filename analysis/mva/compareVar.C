#include <TFile.h>
#include <TH1.h>

void  runVar(string, int, float, float);
TH1F* prepTree(TString, string, int, float, float, TString);

void compareVar(){
 
  runVar("mgg",		26, 99, 151);
  runVar("t1pfmetCorr",	90, 0,  900);
  runVar("ptgg",	60, 0,  600);
  runVar("pt1",		30, 0,  300);
  runVar("pt2",		30, 0,  300);
  runVar("eta1",	20, -4, 4);
  runVar("eta2",	20, -4, 4);
  runVar("nJets30",	10, 0,  10);
  runVar("nEle",	5,  0,  5);
  runVar("nMuons",	5,  0,  5);
  runVar("dphiggmet",	20, 0,  4);
  runVar("mindphijmet",	20, 0,  4);
  
}

void runVar(string VAR, int BIN, float MIN, float MAX){
 
  std::cout << "Comparing variable " << VAR << std::endl;
  TString indir  = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_moriond17_v3/";
  TString outdir = "~/www/Plots/MonoHgg2017/VariableShapes/"; 
  TString skim  = "_rawskim"; 

  TFile* fout = new TFile("OutputVarComparison.root","UPDATE");
  TCanvas* c = new TCanvas("","",800,800);
  TLegend* l = new TLegend(0.5,0.70,0.85,0.88,"","brNDC");// x1,y1,x2,y2
  TPad* p = new TPad("","",0.01,0.01,0.99,0.99); 
  l->SetBorderSize(0); 

  TH1F* sig1 = prepTree(indir+"2HDM_mZP600_mA0300"+skim,     VAR,BIN,MIN,MAX,"");
  TH1F* sig2 = prepTree(indir+"BaryonicZp_mZP10_mChi1"+skim, VAR,BIN,MIN,MAX,"");
  TH1F* bkg1 = prepTree(indir+"DiPhoton"+skim,               VAR,BIN,MIN,MAX,"");
  TH1F* bkg2 = prepTree(indir+"VHToGG"+skim,                 VAR,BIN,MIN,MAX,"");
  TH1F* bkg3 = prepTree(indir+"WGToLNuG"+skim,               VAR,BIN,MIN,MAX,"");

  float max1 = sig1->GetMaximum();
  float max2 = (max1 > sig2->GetMaximum())? max1:sig2->GetMaximum();
  float max3 = (max2 > bkg1->GetMaximum())? max2:bkg1->GetMaximum();
  float max4 = (max3 > bkg2->GetMaximum())? max3:bkg2->GetMaximum();
  float max  = (max4 > bkg3->GetMaximum())? max4:bkg3->GetMaximum();
   
  sig1->SetMaximum(max*2);
  sig1->SetMinimum(0.0001); 
  sig1->GetYaxis()->SetTitle("A.U.");
  TString varname = "";
  if (VAR=="mgg") 		varname = "m_{#gamma#gamma} [GeV]";
  else if (VAR=="t1pfmetCorr")	varname = "p_{T}^{miss} [GeV]";
  else if (VAR=="ptgg")		varname = "p_{T,#gamma#gamma} [GeV]";
  else if (VAR=="pt1") 		varname = "p_{T,1} [GeV]";
  else if (VAR=="pt2") 		varname = "p_{T,2} [GeV]";
  else if (VAR=="eta1")		varname = "#eta_{1}";
  else if (VAR=="eta2")		varname = "#eta_{2}";
  else if (VAR=="dphiggmet")	varname = "|#Delta#phi(#gamma#gamma,p_{T}^{miss})|";
  else if (VAR=="mindphijmet")  varname = "|#Delta#phi(j,p_{T}^{miss})|";
  else if (VAR=="nJets30")	varname = "Num. jets";
  else if (VAR=="nEle")		varname = "Num. electrons";
  else if (VAR=="nMuons")	varname = "Num. muons";
  else varname = VAR;
  std::cout << "Variable name: " << varname << std::endl;
  sig1->GetXaxis()->SetTitle(varname);


  c->cd(); p->Draw(); p->cd();
  gStyle->SetOptStat(0);
  sig1->SetLineWidth(2);
  sig2->SetLineWidth(2);
  sig1->SetLineColor(kRed);
  sig2->SetLineColor(kMagenta);
  bkg1->SetLineColor(kBlack);
  bkg1->SetFillColor(kBlack);
  bkg1->SetFillStyle(3003);
  bkg2->SetLineColor(kGreen);
  bkg3->SetLineColor(kTeal);
  
  l->AddEntry(sig1,"2HDM: m_{Z'} = 600 GeV, m_{A} = 300 GeV","L");
  l->AddEntry(sig2,"BARY: m_{Z'} = 10 GeV, m_{#chi} = 1 GeV","L");
  l->AddEntry(bkg1,"#gamma#gamma","LF");
  l->AddEntry(bkg2,"V+H","L");
  l->AddEntry(bkg3,"W(l#nu)+#gamma","L");
   
  sig1->Draw("HIST");
  bkg1->Draw("HIST SAME");
  bkg2->Draw("HIST SAME");
  bkg3->Draw("HIST SAME");
  sig1->Draw("HIST SAME");
  sig2->Draw("HIST SAME");

  l->Draw("SAME");
  p->SetLogy(0);
  c->SaveAs(Form("%scompare_%s_lin.png",outdir.Data(),VAR.c_str())); 
  c->SaveAs(Form("%scompare_%s_lin.pdf",outdir.Data(),VAR.c_str()));
  p->SetLogy(1); 
  c->SaveAs(Form("%scompare_%s_log.png",outdir.Data(),VAR.c_str())); 
  c->SaveAs(Form("%scompare_%s_log.pdf",outdir.Data(),VAR.c_str())); 

  delete c; 
}

TH1F* prepTree(TString fin, string VAR, int BIN, float MIN, float MAX, TString cut=""){
  TFile* f = new TFile(fin+".root");
  TTree* t = (TTree*)f->Get("DiPhotonTree");
  TH1F*  h = new TH1F("h","",BIN,MIN,MAX); 
  TString cutstr = ""; 
  if (cut!="") cutstr = "("+cut+")*";
  cutstr += "weight"; 
  t->Draw((VAR+">>h").c_str(),cutstr);
  float totint = h->Integral();
  h->Scale(1/totint);
  return h; 
}
