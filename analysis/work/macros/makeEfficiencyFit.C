#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>

using namespace std;

void	Get1DEfficiency(TFile*, TString, TFile*, TString, Bool_t, TString);

void makeEfficiencyFit()
{

  // ----------------------------------------------------------------
  // Get input and setup output root file 
  // ----------------------------------------------------------------
  TString indir  = "EffandYieldsTables/";
  TString outdir = "~/www/Plots/13TeV_v80X_moriond17/SignalInterpretation/";
  TFile *infile  = TFile::Open(Form("%sOutput_Eff.root",indir.Data()));
  TFile *outfile = TFile::Open(Form("%sOutput_1DEff.root",outdir.Data()),"RECREATE");

  // ----------------------------------------------------------------
  // Fit w/ deg1 polynomial 
  // ----------------------------------------------------------------
  Get1DEfficiency(infile,outdir,outfile,"BARY",true,"deg1");
  Get1DEfficiency(infile,outdir,outfile,"BARY",false,"deg1");
  Get1DEfficiency(infile,outdir,outfile,"2HDM",true,"deg1"); 
  Get1DEfficiency(infile,outdir,outfile,"2HDM",false,"deg1"); 
  // ----------------------------------------------------------------
  // Fit w/ deg2 polynomial 
  // ----------------------------------------------------------------
  Get1DEfficiency(infile,outdir,outfile,"BARY",true,"deg2");
  Get1DEfficiency(infile,outdir,outfile,"BARY",false,"deg2");
  Get1DEfficiency(infile,outdir,outfile,"2HDM",true,"deg2"); 
  Get1DEfficiency(infile,outdir,outfile,"2HDM",false,"deg2"); 
 
  outfile->Close();
  delete outfile;
}

void Get1DEfficiency(TFile* infile, TString outdir, TFile* outfile, TString sig, Bool_t highMET, TString deg)
{

  // ----------------------------------------------------------------
  // Get the 2D efficiencies 
  // ----------------------------------------------------------------
  TString met = (highMET)? "HighMET":"LowMET";
  TString histoname = Form("h_%s_Eff_%s",sig.Data(),met.Data());
  TH2D* h_eff = (TH2D*)infile->Get(Form("%s",histoname.Data()));
  TH2D* h_err = (TH2D*)infile->Get(Form("%s_err",histoname.Data()));

  // ----------------------------------------------------------------
  // Make 1D efficiencies for mChi or mA0 (Y axis in 2D) 
  // ----------------------------------------------------------------
  std::vector< Double_t > mY = {1, 10, 50, 150, 500, 1000};                     // BARY DM
  if (sig.EqualTo("2HDM",TString::kExact)) mY = {300, 400, 500, 600, 700, 800}; // 2HDM A0
  TString xname = "DM";
  if (sig.EqualTo("2HDM",TString::kExact)) xname = "A";
  Double_t minX = 0;                                                            // BARY min Zp
  Double_t maxX = 2500;                                                         // BARY max Zp
  //Double_t maxX = 10005;                                                        // BARY max Zp
  if (sig.EqualTo("2HDM",TString::kExact)){ minX = 500; maxX = 3000; }          // 2HDM Zp

  // ----------------------------------------------------------------
  // Set up the fit 
  // ----------------------------------------------------------------
  TString eqn = "[0] + [1]*x";
  if (deg.EqualTo("deg2",TString::kExact)) eqn = "[0] + [1]*x + [2]*x^2";
  TF1 *polN = new TF1("polN",Form("%s",eqn.Data()),-20,20);
  TH1D* h_prob = new TH1D("h_prob",Form("h_prob_%s_%s_%s",deg.Data(),sig.Data(),met.Data()),mY.size(),0,mY.size()); // histo w/ prob for each fit

  outfile->cd();
  TCanvas *c = new TCanvas();

  for (UInt_t m=0; m < mY.size(); m++){
    TH1D* h_eff_1D = new TH1D(Form("h_eff_1D_m%1.f",mY[m]),Form("h_eff_1D_%s_%s_%s_m%1.f",deg.Data(),sig.Data(),met.Data(),mY[m]),(maxX-minX),minX,maxX);
    h_eff_1D = h_eff->ProjectionX(Form("h_eff_1D_%s_%s_%s_m%1.f",deg.Data(),sig.Data(),met.Data(),mY[m]),mY[m]-1,mY[m]+1); 
    h_eff_1D->GetXaxis()->SetRange(minX,maxX);

    // ----------------------------------------------------------------
    // Get errors on efficiencies 
    // ----------------------------------------------------------------
    Double_t binY = h_err->GetYaxis()->FindBin(mY[m]);
    for (UInt_t binX=0; binX < h_eff_1D->GetSize(); binX++){
      Double_t errX = h_err->GetBinContent(binX,binY);
      h_eff_1D->SetBinError(binX,errX);
    }

    // ----------------------------------------------------------------
    // Fit efficiencies 
    // ----------------------------------------------------------------
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1);
    h_eff_1D->Fit("polN"); 
    h_prob->Fill(m,polN->GetProb());
    h_prob->GetXaxis()->SetBinLabel(m+1,Form("%1.f",mY[m]));

    // ----------------------------------------------------------------
    // Save & delete histos 
    // ----------------------------------------------------------------
    c->cd();
    h_eff_1D->SetMarkerStyle(20);
    h_eff_1D->SetMarkerSize(0.5);
    h_eff_1D->Draw("PE");
    h_eff_1D->Write();
    gStyle->SetStatX(0.85);
    gStyle->SetStatY(0.5);
    c->SetLogx(0);
    c->SaveAs(Form("%sfit_%s/%s_m%s/h_1Deff_%s_%s_%s_m%1.f_lin.png",outdir.Data(),deg.Data(),sig.Data(),xname.Data(),deg.Data(),sig.Data(),met.Data(),mY[m]));
    c->SaveAs(Form("%sfit_%s/%s_m%s/h_1Deff_%s_%s_%s_m%1.f_lin.pdf",outdir.Data(),deg.Data(),sig.Data(),xname.Data(),deg.Data(),sig.Data(),met.Data(),mY[m]));
    c->SetLogx(1);
    TPaveStats* stat = (TPaveStats*)h_eff_1D->GetListOfFunctions()->FindObject("stats");
    stat->SetX1NDC(0.15);
    stat->SetX2NDC(0.40);
    stat->SetY1NDC(0.80);
    c->Modified();
    c->Update(); 
    c->SaveAs(Form("%sfit_%s/%s_m%s/h_1Deff_%s_%s_%s_m%1.f_log.png",outdir.Data(),deg.Data(),sig.Data(),xname.Data(),deg.Data(),sig.Data(),met.Data(),mY[m]));
    c->SaveAs(Form("%sfit_%s/%s_m%s/h_1Deff_%s_%s_%s_m%1.f_log.pdf",outdir.Data(),deg.Data(),sig.Data(),xname.Data(),deg.Data(),sig.Data(),met.Data(),mY[m]));
    delete h_eff_1D; 
  } 
  
  // ----------------------------------------------------------------
  // Save histo w/ Prob(chi2) for the fit 
  // ----------------------------------------------------------------
  c->cd();
  c->SetLogx(0);
  gStyle->SetOptStat(0);
  h_prob->GetYaxis()->SetTitle("Prob(#chi^{2})");
  h_prob->GetXaxis()->SetTitle("m_{#chi}");
  if (sig.EqualTo("2HDM",TString::kExact)) h_prob->GetXaxis()->SetTitle("m_{A}");
  h_prob->Draw("HIST");
  h_prob->Write();
  c->SaveAs(Form("%sfit_%s/%s_m%s/h_fitprob_%s_%s_%s.png",outdir.Data(),deg.Data(),sig.Data(),xname.Data(),deg.Data(),sig.Data(),met.Data()));
  c->SaveAs(Form("%sfit_%s/%s_m%s/h_fitprob_%s_%s_%s.pdf",outdir.Data(),deg.Data(),sig.Data(),xname.Data(),deg.Data(),sig.Data(),met.Data()));
 
  delete c;

}

