#include <TFile.h>
#include <TTree.h>
#include <TString.h>
#include <TH1.h>

#include <vector>
#include <iostream>

Float_t Bwgt;		
Float_t Bmgg;		
Float_t Bpt1;		
Float_t Bpt2;		
Float_t Bptgg;	
Float_t Bmet;		
Float_t Bdphigg;	
Float_t Bdphij;	
Int_t   Bnjet;	
Int_t   Bnmu;		
Int_t   Bnel;		
                      
Float_t Swgt;		
Float_t Smgg;		
Float_t Spt1;		
Float_t Spt2;		
Float_t Sptgg;	
Float_t Smet;		
Float_t Sdphigg;	
Float_t Sdphij;	
Int_t   Snjet;	
Int_t   Snmu;		
Int_t   Snel;		

void    RunSample(TString, TString, std::vector<Float_t>);
Float_t OptimizeSigma(TTree*, TTree*, TString, int, double);

void optimization(){
  TString path = "/afs/cern.ch/work/m/mzientek/public/25ns_v80X_moriond17_v3/";
  std::vector< TString > samples;
  samples.push_back("ScalarZp_mZP10_mChi1");
  samples.push_back("ScalarZp_mZP100_mChi1");
  samples.push_back("ScalarZp_mZP500_mChi1");
  samples.push_back("ScalarZp_mZP1000_mChi1");
  UInt_t nsamples = samples.size();

  std::vector< std::vector<Float_t> > cutvec;
  cutvec.resize(nsamples); 
 
  for (UInt_t mc = 0; mc < nsamples; mc++){
    RunSample(path,samples[mc],cutvec[mc]);
  }

}

void RunSample(TString path, TString signal, std::vector<Float_t> cutvec){
 
  // ----------------------------------------------------------------
  // get input files 
  // ----------------------------------------------------------------
  TFile *fsig = TFile::Open(Form("%s%s_rawskim.root",path.Data(),signal.Data()),"READ");
  if (fsig == NULL){ cout << "Signal file not found, exiting..." << endl; }

  std::vector<TString> BkgNames;
  BkgNames.push_back("DiPhoton");
  BkgNames.push_back("GJets");
  BkgNames.push_back("QCD");
  BkgNames.push_back("DYJetsToLL"); 
  UInt_t fNBkg = BkgNames.size();

  // ----------------------------------------------------------------
  // get input trees 
  // ----------------------------------------------------------------
  TTree *sig = (TTree*)fsig->Get("DiPhotonTree");
  if (sig == NULL){ cout << "Signal tree not found, exiting..." << endl; }
  
  TChain *bkg = new TChain();
  for (UInt_t mc = 0; mc < fNBkg; mc++){
    bkg->Add(Form("%s%s_rawskim.root/DiPhotonTree",path.Data(),BkgNames[mc].Data()));
  }

  // ----------------------------------------------------------------
  // set up branches 
  // ----------------------------------------------------------------
  bkg->SetBranchAddress("weight",&Bwgt);
  bkg->SetBranchAddress("mgg",&Bmgg);
  bkg->SetBranchAddress("pt1",&Bpt1);
  bkg->SetBranchAddress("pt2",&Bpt2);
  bkg->SetBranchAddress("ptgg",&Bptgg);
  bkg->SetBranchAddress("t1pfmetCorr",&Bmet);
  bkg->SetBranchAddress("dphiggmet",&Bdphigg);
  bkg->SetBranchAddress("mindphijmet",&Bdphij); 
  bkg->SetBranchAddress("nJets30",&Bnjet);
  bkg->SetBranchAddress("nMuons",&Bnmu);
  bkg->SetBranchAddress("nEle",&Bnel);

  sig->SetBranchAddress("weight",&Swgt);
  sig->SetBranchAddress("mgg",&Smgg);
  sig->SetBranchAddress("pt1",&Spt1);
  sig->SetBranchAddress("pt2",&Spt2);
  sig->SetBranchAddress("ptgg",&Sptgg);
  sig->SetBranchAddress("t1pfmetCorr",&Smet);
  sig->SetBranchAddress("dphiggmet",&Sdphigg);
  sig->SetBranchAddress("mindphijmet",&Sdphij); 
  sig->SetBranchAddress("nJets30",&Snjet);
  sig->SetBranchAddress("nMuons",&Snmu);
  sig->SetBranchAddress("nEle",&Snel);

  // ----------------------------------------------------------------
  // call optimization for each variable 
  // ----------------------------------------------------------------
  Float_t ptggcut = 0;
  Float_t pt1cut  = 0;
  Float_t pt2cut  = 0;
  Float_t metcut  = 0;
  Float_t jetcut  = 0;
  Float_t nelcut  = 0;
  Float_t nmucut  = 0;
  Float_t phigcut = 0;
  Float_t phijcut = 0;

  ptggcut = OptimizeSigma(sig, bkg, "ptgg", 10, 30.0); 
  pt1cut  = OptimizeSigma(sig, bkg, "pt1",  10, 0.30);
  pt2cut  = OptimizeSigma(sig, bkg, "pt2",  10, 0.25);
  metcut  = OptimizeSigma(sig, bkg, "met",  10, 30.0);
  jetcut  = OptimizeSigma(sig, bkg, "njet",  4,  0.0);
  nelcut  = OptimizeSigma(sig, bkg, "nel",   3,  0.0);
  nmucut  = OptimizeSigma(sig, bkg, "nmu",   3,  0.0);
  phigcut = OptimizeSigma(sig, bkg, "phig", 10,  1.8);
  phijcut = OptimizeSigma(sig, bkg, "phij", 10,  0.0);

  std::cout << "--------- Optimal cuts ------------" << std::endl;
  std::cout << "   ptgg : " << ptggcut << std::endl; 
  std::cout << "   pt1  : " << pt1cut  << std::endl; 
  std::cout << "   pt2  : " << pt2cut  << std::endl;
  std::cout << "   met  : " << metcut  << std::endl;
  std::cout << "   njet : " << jetcut  << std::endl;
  std::cout << "   nel  : " << nelcut  << std::endl;
  std::cout << "   mmu  : " << nmucut  << std::endl;
  std::cout << "   phig : " << phigcut << std::endl;
  std::cout << "   phij : " << phijcut << std::endl; 
  std::cout << "-----------------------------------" << std::endl;

  cutvec.push_back(pt1cut);
  cutvec.push_back(pt2cut);
  cutvec.push_back(ptggcut);
  cutvec.push_back(metcut);

  delete sig;
  delete bkg;
  delete fsig; 

}

Float_t OptimizeSigma(TTree* sig, TTree* bkg, TString var, int nstp, double cutstart){
  Float_t cut = 0; 
  Int_t nsteps = nstp; 

  TH1F* sighiststart = new TH1F("sigstart","",38,105,181);
  std::vector< TH1F* > sighisto; 
  std::vector< TH1F* > bkghisto; 
  sighisto.resize(nsteps);
  bkghisto.resize(nsteps);
  for (UInt_t n = 0; n < nsteps; n++){
    sighisto[n] = new TH1F(Form("sig%d",n),"",38,105,181);
    bkghisto[n] = new TH1F(Form("bkg%d",n),"",38,105,181);
  }

  // ----------------------------------------------------------------
  // starting points for cuts 
  // ----------------------------------------------------------------
  Float_t cut_pt1   = 0.3;
  Float_t cut_pt2   = 0.25;
  Float_t cut_ptgg  = 30;
  Float_t cut_met   = 30;
  Float_t cut_dphi1 = 2.1;
  Float_t cut_dphi2 = 0.5;
  Int_t   cut_njet  = 2;
  Int_t   cut_nel   = 0;
  Int_t   cut_nmu   = 0;

  Float_t variable = 0;
  std::vector<Float_t> cutval;
  cutval.resize(nsteps);
  for (UInt_t n = 0; n < nsteps; n++){
    if (var=="pt1" || var=="pt2" || var=="phig" || var=="phij") cutval[n] = cutstart + 0.05*n;
    else if (var=="njet" || var=="nel" || var=="nmu")           cutval[n] = cutstart + n;
    else                                                        cutval[n] = cutstart + 5*n;  
  }

  // ----------------------------------------------------------------
  // run over bkgs 
  // ----------------------------------------------------------------
  for (UInt_t entry = 0; entry < bkg->GetEntries(); entry++){
    bkg->GetEntry(entry);

    if (var=="pt1")  variable = Bpt1/Bmgg;
    if (var=="pt2")  variable = Bpt2/Bmgg;
    if (var=="ptgg") variable = Bptgg; 
    if (var=="met")  variable = Bmet;
    if (var=="phig") variable = Bdphigg;
    if (var=="phij") variable = Bdphij;
    if (var=="njet") variable = Bnjet;
    if (var=="nel")  variable = Bnel;
    if (var=="nmu")  variable = Bnmu;
 
    if (Bpt1  < cut_pt1*Bmgg) continue;
    if (Bpt2  < cut_pt2*Bmgg) continue;
    if (Bptgg < cut_ptgg)     continue;
    if (Bmet  < cut_met)      continue;
    if (Bnel  > cut_nel)      continue;
    if (Bnmu  > cut_nmu)      continue;  
    if (Bnjet > cut_njet)     continue;  

    for (UInt_t n = 0; n < nsteps; n++){
      if (var=="njet" || var=="nel" || var=="nmu"){
        if (variable > cutval[n]) continue;
      }
      else{ 
        if (variable < cutval[n]) continue;
      }
      bkghisto[n]->Fill(Bmgg,Bwgt);
    }

  }
   
  // ----------------------------------------------------------------
  // run over sigs 
  // ----------------------------------------------------------------
  for (UInt_t entry = 0; entry < sig->GetEntries(); entry++){
    sig->GetEntry(entry);

    if (var=="pt1")  variable = Spt1/Smgg;
    if (var=="pt2")  variable = Spt2/Smgg;
    if (var=="ptgg") variable = Sptgg; 
    if (var=="met")  variable = Smet;
    if (var=="phig") variable = Sdphigg;
    if (var=="phij") variable = Sdphij;
    if (var=="njet") variable = Snjet;
    if (var=="nel")  variable = Snel;
    if (var=="nmu")  variable = Snmu;
 
    sighiststart->Fill(Smgg,Swgt);
    
    if (Spt1  < cut_pt1*Smgg) continue;
    if (Spt2  < cut_pt2*Smgg) continue;
    if (Sptgg < cut_ptgg)     continue;
    if (Smet  < cut_met)      continue;
    if (Snel  > cut_nel)      continue;
    if (Snmu  > cut_nmu)      continue; 
    if (Snjet > cut_njet)     continue; 

    for (UInt_t n = 0; n < nsteps; n++){
      if (var=="njet" || var=="nel" || var=="nmu"){
        if (variable > cutval[n]) continue;
      }
      else{ 
        if (variable < cutval[n]) continue;
      }
      sighisto[n]->Fill(Smgg,Swgt);
    }

  }

  Float_t Byield = 0;
  Float_t Berror = 0;
  Float_t Syield = 0;
  Float_t Sstart = 0;
  Float_t Seff   = 0;
  Float_t efferr = 0; 
  std::vector<Float_t> Sigma;
  Sigma.resize(nsteps);
  std::vector<Float_t> Err;
  Err.resize(nsteps);
  Float_t tmpSig = 0;

  for (UInt_t n = 0; n < nsteps; n++){
    Sigma[n] = 0;
    Err[n] = 0;
    Sstart = sighiststart->Integral(); 
    Byield = bkghisto[n]->Integral();
    Berror = sqrt(Byield); 
    if (Byield < 0) Byield = 0.0;
    Syield = sighisto[n]->Integral();
    Seff   = Syield/Sstart;
    efferr = Seff*(1.0-Seff)/Sstart;
    Sigma[n] = Seff/(2.5+sqrt(Byield)); 
    Err[n]   = efferr/(2.5+sqrt(Byield)) - Seff*Berror/(sqrt(Byield)*(2.5+sqrt(Byield))*(2.5+sqrt(Byield))); 
 
    std::cout << var << " cut at " << cutval[n] << " : sigma = " << Sigma[n]  << "+/-" << Err[n] << endl;
   
    tmpSig = 0;
    if (Sigma[n] > tmpSig){ 
      tmpSig = Sigma[n];
      cut = cutval[n];
    }

  }

  std::cout << "made it here" << std::endl;

  delete sighiststart;
  for (UInt_t n = 0; n < nsteps; n++){
    delete bkghisto[n];
    delete sighisto[n];
  }

  return cut; 
} 




