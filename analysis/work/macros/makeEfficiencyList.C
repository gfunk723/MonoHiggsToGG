#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1.h>
#include <iostream>

using namespace std;

void GetEfficiencies(TString, TString, Float_t);
void CalculateAnalyzerEff();
void CalculateSelectionEff(TTree*);
void CalculateOverallEff(TString, TString, Float_t &, Float_t &);

void makeEfficiencyList(){

  cout << "Computing Efficiency for Samples" << endl;
  TString indir   = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_moriond17_v2/";
  TString outfile = "PlainEff.tex";
  Float_t lumi    = 35.8;

  GetEfficiencies(indir,outfile,lumi);

}

void GetEfficiencies(TString indir, TString outfile, Float_t lumi){

  // ----------------------------------------------------------------
  // What samples to use 
  // ----------------------------------------------------------------
  vector< TString > Samples;
  Samples.push_back("2HDM_mZP600_mA0300"); 
  UInt_t nSamples = Samples.size();

  vector< Float_t > Eff;  Eff.resize(nSamples);
  vector< Float_t > Err;  Err.resize(nSamples);

  // ----------------------------------------------------------------
  // setup latex doc
  // ----------------------------------------------------------------
  cout << "Writing efficiencies to: " << outfile << endl;
  std::ofstream outResults;
  outResults.open(outfile);
  if (outResults.is_open()){
    outResults << "\\documentclass[a4paper,landscape]{article}" << std::endl;
    outResults << "\\usepackage[paperheight=15.0in,paperwidth=6.0in,margin=1.0in,headheight=0.0in,footskip=0.5in,includehead,includefoot]{geometry}" << std::endl;
    outResults << "\\begin{document}" << std::endl;
    outResults << "\% Efficiencies listed for each signal" << std::endl;
    outResults << "\\begin{table}[bthp]" <<std::endl;
    outResults << "\\begin{tabular}{|l|r|}" <<std::endl;
    outResults << "\\hline \\hline" <<std::endl;

    // ----------------------------------------------------------------
    // get efficiency for each sample & write to table 
    // ----------------------------------------------------------------
    for (UInt_t n=0; n < nSamples; n++){
      CalculateOverallEff(indir,Samples[n],Eff[n],Err[n]);
      outResults << Samples[n] << " & " << Form("%1.3f",Eff[n]) << " $ \\pm $ " << Form("%1.3f",Err[n]) << " \\\\" << endl;
    }

    // ----------------------------------------------------------------
    // finish latex doc 
    // ----------------------------------------------------------------
    outResults << "\\hline \\hline" <<std::endl;
    outResults << "\\end{tabular}" <<std::endl;
    outResults << "\\end{table}" <<std::endl;
    outResults << "\\end{document}" <<std::endl;
  }
  else cout << "Error with output file..." << endl; 

}

void CalculateAnalyzerEff(){

}

void CalculateSelectionEff(TTree* tree){

  // ----------------------------------------------------------------
  // set up branches - weight & those needed to apply the selection 
  // ----------------------------------------------------------------
  Float_t weight;		tree->SetBranchAddress("weight",&weight);
  Float_t mgg;			tree->SetBranchAddress("mgg",&mgg);
  Float_t t1pfmetCorr;		tree->SetBranchAddress("t1pfmetCorr",&t1pfmetCorr);
  Float_t dphiggmet;		tree->SetBranchAddress("dphiggmet",&dphiggmet);
  Float_t mindphijmet;		tree->SetBranchAddress("mindphijmet",&mindphijmet);

  // ----------------------------------------------------------------
  // loop over input tree
  // ----------------------------------------------------------------
  for (UInt_t entry = 0; entry < tree->GetEntries(); entry++)
  {
    tree->GetEntry(entry);

  }
}

void CalculateOverallEff(TString indir, TString name, Float_t & Eff, Float_t & Err){
  cout << " Working on Sample: " << name << endl;
  // ----------------------------------------------------------------
  // get file, tree, h_selection histos 
  // ----------------------------------------------------------------
  TFile *file = TFile::Open(Form("%s%s_skimmedtree.root",indir.Data(),name.Data()));
  if (!file){ cout << "Sample does not exist! Exiting..." << endl; return;} 
  TTree *tree = (TTree*)file->Get("DiPhotonTree");
  if (!tree){ cout << "Tree does not exist! Exiting..." << endl; return;} 
  TH1D *fSel_wgt   = (TH1D*)file->Get("h_selection");
  TH1D *fSel_unwgt = (TH1D*)file->Get("h_selection_unwgt");  
  TH1D *fNum       = (TH1D*)file->Get("h_numbers"); 
  if (!fSel_wgt || !fSel_unwgt || !fNum){ cout << "Histo does not exist! Exiting..." << endl; return;}
 
  // ----------------------------------------------------------------
  // Calculate efficiencies 
  // ----------------------------------------------------------------
  CalculateSelectionEff(tree);

 
}




