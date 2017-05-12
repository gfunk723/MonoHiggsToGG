#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>

using namespace std;

void	Get1DEfficiency(TFile*, TString, TFile*, TString, Bool_t);

void makeEfficiencyFit()
{

  // ----------------------------------------------------------------
  // Get input and setup output root file 
  // ----------------------------------------------------------------
  TString indir = "EffandYieldsTables/";
  TString outdir = indir;
  TFile *infile  = TFile::Open(Form("%sOutput_Eff.root",indir.Data()));
  TFile *outfile = TFile::Open(Form("%sOutput_1DEff.root",outdir.Data()),"RECREATE");

  Get1DEfficiency(infile,outdir,outfile,"BARY",true);
  
  outfile->Close();
  delete outfile;
}

void Get1DEfficiency(TFile* infile, TString outdir, TFile* outfile, TString sig, Bool_t highMET)
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
  Double_t minX = 0;                                                            // BARY min Zp
  Double_t maxX = 2500;                                                         // BARY max Zp
  if (sig.EqualTo("2HDM",TString::kExact)){ minX = 500; maxX = 3000; }          // 2HDM Zp

  TF1 *polN = new TF1("polN","[0] + [1]*x + [2]*x^2",0,10);
  outfile->cd();
  TCanvas *c = new TCanvas();

  for (UInt_t m=0; m < mY.size(); m++){
    TH1D* h_eff_1D = new TH1D(Form("h_eff_1D_m%1.f",mY[m]),Form("h_eff_1D_m%1.f",mY[m]),2500,minX,maxX);
    h_eff_1D = h_eff->ProjectionX(Form("h_eff_1D_m%1.f",mY[m]),mY[m]-1,mY[m]+1); 

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
    gStyle->SetOptFit(1);
    gStyle->SetStatX(0.85);
    gStyle->SetStatY(0.5);
    h_eff_1D->Fit("polN"); 

    // ----------------------------------------------------------------
    // Save & delete histos 
    // ----------------------------------------------------------------
    c->cd();
    h_eff_1D->Draw("PE");
    h_eff_1D->Write();
    c->SaveAs(Form("%sh_1Deff_%s_%s_m%1.f.png",outdir.Data(),sig.Data(),met.Data(),mY[m]));
    c->SaveAs(Form("%sh_1Deff_%s_%s_m%1.f.pdf",outdir.Data(),sig.Data(),met.Data(),mY[m]));
    delete h_eff_1D; 
  } 
  
  delete c;

}

