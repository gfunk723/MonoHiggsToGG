#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1.h>
#include <iostream>

using namespace std;

void    GetEfficiencies(TString, TString, TString, Float_t, Bool_t, Bool_t);
void    GetEfficiency(TString, TString, TString, Float_t, Bool_t, Bool_t, Bool_t, Float_t &, Float_t &);
void    CalculateNumbers(TTree*, TH1D*, Int_t &, Int_t &, Float_t &, Float_t &);
Float_t CalculateEff(Int_t, Float_t, Int_t, Float_t, Float_t &);

void makeEfficiencyList()
{

  TString indir   = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_moriond17_v3/";
  Float_t lumi    = 35821.4; //in pb^-1 (for weighting)

  // ----------------------------------------------------------------
  // which skim to use 
  // ----------------------------------------------------------------
  TString addname="";
  TString skim="skimmedtree"; //default
  if (addname.Contains("optA",TString::kExact)) skim="newskim";
  if (addname.Contains("optB",TString::kExact)) skim="newskimv2";

  // ----------------------------------------------------------------
  // Call function for each category 
  // ----------------------------------------------------------------
  TString outfile;
  cout << "Computing Efficiency highMET region" << endl;
  outfile = Form("PlainEff%s_highMET.tex",addname.Data());
  GetEfficiencies(indir,outfile,skim,lumi,true,false);

  cout << "Computing Efficiency lowMET region" << endl;
  outfile = Form("PlainEff%s_lowMET.tex",addname.Data());
  GetEfficiencies(indir,outfile,skim,lumi,false,false); 

  cout << "Computing Yields highMET region" << endl;
  outfile = Form("Yields%s_highMET.tex",addname.Data());
  GetEfficiencies(indir,outfile,skim,lumi,true,true);

  cout << "Computing Yields lowMET region" << endl;
  outfile = Form("Yields%s_lowMET.tex",addname.Data());
  GetEfficiencies(indir,outfile,skim,lumi,false,true);

}

void GetEfficiencies(TString indir, TString outfile, TString skim, Float_t lumi, Bool_t hiMETeff, Bool_t yields)
{

  // ----------------------------------------------------------------
  // samples to use 
  // ----------------------------------------------------------------
  vector< TString > Samples;

  Samples.push_back("2HDM_mZP600_mA0300" );
  Samples.push_back("2HDM_mZP800_mA0300" );
  Samples.push_back("2HDM_mZP1000_mA0300"); 
  Samples.push_back("2HDM_mZP1200_mA0300"); 
  Samples.push_back("2HDM_mZP1400_mA0300"); 
  Samples.push_back("2HDM_mZP1700_mA0300"); 
  Samples.push_back("2HDM_mZP2000_mA0300"); 
  Samples.push_back("2HDM_mZP2500_mA0300"); 
  Samples.push_back("2HDM_mZP600_mA0400" );
  Samples.push_back("2HDM_mZP800_mA0400" );
  Samples.push_back("2HDM_mZP1000_mA0400"); 
  Samples.push_back("2HDM_mZP1200_mA0400"); 
  Samples.push_back("2HDM_mZP1400_mA0400"); 
  Samples.push_back("2HDM_mZP1700_mA0400"); 
  Samples.push_back("2HDM_mZP2000_mA0400"); 
  Samples.push_back("2HDM_mZP2500_mA0400"); 
  Samples.push_back("2HDM_mZP800_mA0500" );
  Samples.push_back("2HDM_mZP1000_mA0500"); 
  Samples.push_back("2HDM_mZP1200_mA0500"); 
  Samples.push_back("2HDM_mZP1400_mA0500"); 
  Samples.push_back("2HDM_mZP1700_mA0500"); 
  Samples.push_back("2HDM_mZP2000_mA0500"); 
  Samples.push_back("2HDM_mZP2500_mA0500"); 
  Samples.push_back("2HDM_mZP800_mA0600" );
  Samples.push_back("2HDM_mZP1000_mA0600"); 
  Samples.push_back("2HDM_mZP1200_mA0600"); 
  Samples.push_back("2HDM_mZP1400_mA0600"); 
  Samples.push_back("2HDM_mZP1700_mA0600"); 
  Samples.push_back("2HDM_mZP2000_mA0600"); 
  Samples.push_back("2HDM_mZP2500_mA0600"); 
  Samples.push_back("2HDM_mZP1000_mA0700"); 
  Samples.push_back("2HDM_mZP1200_mA0700"); 
  Samples.push_back("2HDM_mZP1400_mA0700"); 
  Samples.push_back("2HDM_mZP1700_mA0700"); 
  Samples.push_back("2HDM_mZP2000_mA0700"); 
  Samples.push_back("2HDM_mZP2500_mA0700"); 
  Samples.push_back("2HDM_mZP1000_mA0800"); 
  Samples.push_back("2HDM_mZP1200_mA0800"); 
  Samples.push_back("2HDM_mZP1400_mA0800"); 
  Samples.push_back("2HDM_mZP1700_mA0800"); 
  Samples.push_back("2HDM_mZP2000_mA0800"); 
  Samples.push_back("2HDM_mZP2500_mA0800"); 

  Samples.push_back("BaryonicZp_mZP10000_mChi1000");
  Samples.push_back("BaryonicZp_mZP10000_mChi10"  );
  Samples.push_back("BaryonicZp_mZP10000_mChi150" );
  Samples.push_back("BaryonicZp_mZP10000_mChi1"   );
  Samples.push_back("BaryonicZp_mZP10000_mChi500" );
  Samples.push_back("BaryonicZp_mZP10000_mChi50"  );
  Samples.push_back("BaryonicZp_mZP1000_mChi1000" );
  Samples.push_back("BaryonicZp_mZP1000_mChi150"  );
  Samples.push_back("BaryonicZp_mZP1000_mChi1"    );
  Samples.push_back("BaryonicZp_mZP100_mChi10"    );
  Samples.push_back("BaryonicZp_mZP100_mChi1"     );
  Samples.push_back("BaryonicZp_mZP10_mChi1000"   );
  Samples.push_back("BaryonicZp_mZP10_mChi10"     );
  Samples.push_back("BaryonicZp_mZP10_mChi1"      );
  Samples.push_back("BaryonicZp_mZP10_mChi50"     );
  //Samples.push_back("BaryonicZp_mZP15_mChi10"   );
  Samples.push_back("BaryonicZp_mZP1995_mChi1000" );
  Samples.push_back("BaryonicZp_mZP2000_mChi1"    );
  Samples.push_back("BaryonicZp_mZP2000_mChi500"  );
  Samples.push_back("BaryonicZp_mZP200_mChi150"   );
  Samples.push_back("BaryonicZp_mZP200_mChi1"     );
  Samples.push_back("BaryonicZp_mZP200_mChi50"    );
  Samples.push_back("BaryonicZp_mZP20_mChi1"      );
  Samples.push_back("BaryonicZp_mZP295_mChi150"   );
  Samples.push_back("BaryonicZp_mZP300_mChi50"    );
  Samples.push_back("BaryonicZp_mZP500_mChi150"   );
  Samples.push_back("BaryonicZp_mZP500_mChi1"     );
  Samples.push_back("BaryonicZp_mZP500_mChi500"   );
  Samples.push_back("BaryonicZp_mZP50_mChi10"     );
  Samples.push_back("BaryonicZp_mZP50_mChi1"      );
  Samples.push_back("BaryonicZp_mZP995_mChi500"   );

  Samples.push_back("ScalarZp_mZP10000_mChi1"   );
  Samples.push_back("ScalarZp_mZP10000_mChi10"  );
  Samples.push_back("ScalarZp_mZP10000_mChi1000");
  Samples.push_back("ScalarZp_mZP10000_mChi150" );
  Samples.push_back("ScalarZp_mZP10000_mChi50"  );
  Samples.push_back("ScalarZp_mZP10000_mChi500" );
  Samples.push_back("ScalarZp_mZP1000_mChi1000" );
  Samples.push_back("ScalarZp_mZP1000_mChi1"    );
  Samples.push_back("ScalarZp_mZP1000_mChi150"  );
  Samples.push_back("ScalarZp_mZP100_mChi1"     );
  Samples.push_back("ScalarZp_mZP100_mChi10"    );
  Samples.push_back("ScalarZp_mZP10_mChi1"      );
  Samples.push_back("ScalarZp_mZP10_mChi10"     );
  Samples.push_back("ScalarZp_mZP10_mChi150"    );
  Samples.push_back("ScalarZp_mZP10_mChi50"     );
  Samples.push_back("ScalarZp_mZP10_mChi1000"   );
  Samples.push_back("ScalarZp_mZP10_mChi500"    );
  Samples.push_back("ScalarZp_mZP200_mChi1"     );
  Samples.push_back("ScalarZp_mZP200_mChi150"   );
  Samples.push_back("ScalarZp_mZP200_mChi50"    );
  Samples.push_back("ScalarZp_mZP20_mChi1"      );
  Samples.push_back("ScalarZp_mZP295_mChi150"   );
  Samples.push_back("ScalarZp_mZP300_mChi1"     );
  Samples.push_back("ScalarZp_mZP300_mChi50"    );
  Samples.push_back("ScalarZp_mZP500_mChi1"     );
  Samples.push_back("ScalarZp_mZP500_mChi150"   );
  Samples.push_back("ScalarZp_mZP500_mChi500"   );
  Samples.push_back("ScalarZp_mZP50_mChi1"      );
  Samples.push_back("ScalarZp_mZP50_mChi10"     );
  Samples.push_back("ScalarZp_mZP50_mChi50"     );
  Samples.push_back("ScalarZp_mZP95_mChi50"     );
  Samples.push_back("ScalarZp_mZP995_mChi500"   );
  Samples.push_back("ScalarZp_mZP15_mChi10"     );


  UInt_t nSamples = Samples.size();
  vector< Float_t > Eff;  Eff.resize(nSamples);
  vector< Float_t > Err;  Err.resize(nSamples);

  // ----------------------------------------------------------------
  // setup latex doc
  // ----------------------------------------------------------------
  if (yields) cout << "Writing yields to: " << outfile << endl;
  else        cout << "Writing efficiencies to: " << outfile << endl;
  std::ofstream outResults;
  outResults.open(outfile);
  if (outResults.is_open()){
    outResults << "\\documentclass[a4paper,landscape]{article}" << std::endl;
    outResults << "\\usepackage[paperheight=15.0in,paperwidth=6.0in,margin=1.0in,headheight=0.0in,footskip=0.5in,includehead,includefoot]{geometry}" << std::endl;
    outResults << "\\begin{document}" << std::endl;
    if (yields) outResults << "\% Yields listed for each signal" << std::endl; 
    else        outResults << "\% Efficiencies listed for each signal" << std::endl;
    outResults << "\\begin{table}[bthp]" <<std::endl;
    outResults << "\\begin{tabular}{|l|r|}" <<std::endl;
    outResults << "\\hline " <<std::endl;

    // ----------------------------------------------------------------
    // get efficiency for each sample & write to table 
    // ----------------------------------------------------------------
    for (UInt_t n=0; n < nSamples; n++){
      GetEfficiency(indir,Samples[n],skim,lumi,true,hiMETeff,yields,Eff[n],Err[n]);
      if (yields && hiMETeff) outResults << Samples[n] << " & " << Form("%1.1f",Eff[n]) << " $ \\pm $ " << Form("%1.1f",Err[n]) << " \\\\" << endl;
      else if (yields)        outResults << Samples[n] << " & " << Form("%1.2f",Eff[n]) << " $ \\pm $ " << Form("%1.2f",Err[n]) << " \\\\" << endl;
      else                    outResults << Samples[n] << " & " << Form("%1.3f",Eff[n]) << " $ \\pm $ " << Form("%1.3f",Err[n]) << " \\\\" << endl;
    }

    // ----------------------------------------------------------------
    // finish latex doc 
    // ----------------------------------------------------------------
    outResults << "\\hline" <<std::endl;
    outResults << "\\end{tabular}" <<std::endl;
    outResults << "\\end{table}" <<std::endl;
    outResults << "\\end{document}" <<std::endl;
  }
  else cout << "Error with output file..." << endl; 

}

Float_t CalculateEff(Int_t iden, Float_t fden, Int_t inum, Float_t fnum, Float_t & err)
{
   Float_t eff  = fnum/fden;
   err = eff*(1.0-eff)/fden;

   Float_t ieff = (Float_t)inum/(Float_t)iden;
   Float_t ierr = ieff*(1.0-ieff)/(Double_t)iden;
   cout << "den = " << iden << " OR " << fden << endl;
   cout << "num = " << inum << " OR " << fnum << endl;
   cout << "Eff = " << ieff << " OR " << eff << endl; 
   cout << "Err = " << ierr << " OR " << err << endl;
 
   return eff;
}

void GetEfficiency(TString indir, TString name, TString skim, Float_t lumi, Bool_t totEff, Bool_t hiMETeff, Bool_t yields, Float_t & Eff, Float_t & Err)
{

  cout << " Working on Sample: " << name << endl;
  // ----------------------------------------------------------------
  // get file, tree, h_selection histos 
  // ----------------------------------------------------------------
  TFile *file = TFile::Open(Form("%s%s_%s.root",indir.Data(),name.Data(),skim.Data()));
  if (!file){ cout << "Sample does not exist! Exiting..." << endl; return;} 
  TTree *tree = (TTree*)file->Get("DiPhotonTree");
  if (!tree){ cout << "Tree does not exist! Exiting..." << endl; return;} 
  TH1D *fSel_wgt   = (TH1D*)file->Get("h_selection");
  TH1D *fSel_unwgt = (TH1D*)file->Get("h_selection_unwgt");  
  TH1D *fNum       = (TH1D*)file->Get("h_numbers"); 
  if (!fSel_wgt || !fSel_unwgt || !fNum){ cout << "Histo does not exist! Exiting..." << endl; return;}
 
  // ----------------------------------------------------------------
  // Calculate all numbers needed for efficiency 
  // ----------------------------------------------------------------
  Int_t   i_anlyz = fSel_unwgt->GetBinContent(1);
  Float_t f_anlyz = fSel_wgt->GetBinContent(1);//*lumi; // NOT WEIGHTED BY PU or SF
  Int_t   i_begin = fNum->GetBinContent(1);
  Float_t f_begin = fNum->GetBinContent(2);
  Int_t   i_loMET = 0;
  Int_t   i_hiMET = 0;
  Float_t f_loMET = 0;
  Float_t f_hiMET = 0;
  CalculateNumbers(tree,fNum,i_loMET,i_hiMET,f_loMET,f_hiMET);

  // ----------------------------------------------------------------
  // Calculate yields or efficiency 
  // ----------------------------------------------------------------
  if ( yields ){ // yields
    if (hiMETeff) Eff = f_hiMET;
    else          Eff = f_loMET;
    Err = TMath::Sqrt(Eff);
  }
  else{ // calculate efficiencies 
    if ( totEff  && hiMETeff  ) Eff = CalculateEff(i_anlyz,f_anlyz,i_hiMET,f_hiMET,Err);
    if ( totEff  && !hiMETeff ) Eff = CalculateEff(i_anlyz,f_anlyz,i_loMET,f_loMET,Err);
    if ( !totEff && hiMETeff  ) Eff = CalculateEff(i_begin,f_begin,i_hiMET,f_hiMET,Err);
    if ( !totEff && !hiMETeff ) Eff = CalculateEff(i_begin,f_begin,i_loMET,f_loMET,Err);
  }
 
}


void CalculateNumbers(TTree* tree, TH1D* hNum, Int_t & numi_loMET, Int_t & numi_hiMET, Float_t & numf_loMET, Float_t & numf_hiMET)
{

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

    // ----------------------------------------------------------------
    // apply the cuts 
    // ----------------------------------------------------------------
    if (dphiggmet < 2.1)        continue;
    if (mindphijmet < 0.5)      continue;
    if (mgg < 115 || mgg > 135) continue; 

    // ----------------------------------------------------------------
    // store the final number of events 
    // ----------------------------------------------------------------
    if (t1pfmetCorr <= 130){ numi_loMET++; numf_loMET+=weight; }
    if (t1pfmetCorr >  130){ numi_hiMET++; numf_hiMET+=weight; }
  }
}


