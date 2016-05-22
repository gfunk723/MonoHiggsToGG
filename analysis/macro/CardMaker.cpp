#include "CardMaker.hh"
#include "../../../DataFormats/Math/interface/deltaPhi.h"

CardMaker::CardMaker(const Double_t scalefactor, const Double_t inLumi, const DblVec puweights, const TString indir, const TString outdir, const Bool_t Blind, const TString type){

  // Load RooFit
  gSystem->Load("libRooFit");

  // Store input variables
  alpha = scalefactor;
  fType = type;
  flumi = inLumi;
  fInDir = indir;
  fOutDir = outdir;
  doBlind = Blind;
  fOut = "cards"; 
  fPUWeights = puweights;

  mainCut = "(mgg >= 100 && mgg <= 300)";// not used 

  // Make output datacard files
  MakeOutDirectory(Form("%s%s",fOutDir.Data(),fOut.Data()));


  // Set up sampleID matches
  // resonant bkgs
  Samples.push_back(SamplePair("GluGluHToGG",0)); 
  Samples.push_back(SamplePair("VBFHToGG",0)); 
  Samples.push_back(SamplePair("VH",0));
  Samples.push_back(SamplePair("ttHJetToGG",0)); 
  // non-resonant bkgs
  Samples.push_back(SamplePair("DYJetsToLL",1));
  Samples.push_back(SamplePair("DiPhoton",1));
  Samples.push_back(SamplePair("GJets",1)); 
  Samples.push_back(SamplePair("QCD",1));
  Samples.push_back(SamplePair("WGToLNuG",1));
  Samples.push_back(SamplePair("ZZTo2L2Nu",1));
  Samples.push_back(SamplePair("ZGTo2LG",1));
  Samples.push_back(SamplePair("TTGG_0Jets",1));
  Samples.push_back(SamplePair("TGJets",1));
  Samples.push_back(SamplePair("TTGJets",1));
  // data 
  Samples.push_back(SamplePair("DoubleEG",2)); 

  // signals
  Samples.push_back(SamplePair("2HDM_mZP600",100)); //mA0_300 
  Samples.push_back(SamplePair("2HDM_mZP800",101)); //mA0_300 
  Samples.push_back(SamplePair("2HDM_mZP1000",102));//mA0_300 
  Samples.push_back(SamplePair("2HDM_mZP1200",103));//mA0_300 
  Samples.push_back(SamplePair("2HDM_mZP1400",104));//mA0_300 
  Samples.push_back(SamplePair("2HDM_mZP1700",105));//mA0_300 
  Samples.push_back(SamplePair("2HDM_mZP2000",106));//mA0_300  
  Samples.push_back(SamplePair("2HDM_mZP2500",107));//mA0_300  
  Samples.push_back(SamplePair("2HDM_mZP600_mA0400",108)); 
  Samples.push_back(SamplePair("2HDM_mZP800_mA0400",109)); 
  //Samples.push_back(SamplePair("2HDM_mZP1000_mA0400",110)); 
  //Samples.push_back(SamplePair("2HDM_mZP1200_mA0400",111)); 
  //Samples.push_back(SamplePair("2HDM_mZP1400_mA0400",112)); 
  //Samples.push_back(SamplePair("2HDM_mZP1700_mA0400",113)); 
  //Samples.push_back(SamplePair("2HDM_mZP2000_mA0400",114));  
  ////Samples.push_back(SamplePair("2HDM_mZP2500_mA0400",115));  
  ////Samples.push_back(SamplePair("2HDM_mZP600_mA0500",116)); 
  //Samples.push_back(SamplePair("2HDM_mZP800_mA0500",117)); 
  //Samples.push_back(SamplePair("2HDM_mZP1000_mA0500",118)); 
  //Samples.push_back(SamplePair("2HDM_mZP1200_mA0500",119)); 
  //Samples.push_back(SamplePair("2HDM_mZP1400_mA0500",120)); 
  //Samples.push_back(SamplePair("2HDM_mZP1700_mA0500",121)); 
  //Samples.push_back(SamplePair("2HDM_mZP2000_mA0500",122));  
  //Samples.push_back(SamplePair("2HDM_mZP2500_mA0500",123));  
  ////Samples.push_back(SamplePair("2HDM_mZP600_mA0600",124)); 
  //Samples.push_back(SamplePair("2HDM_mZP800_mA0600",125)); 
  //Samples.push_back(SamplePair("2HDM_mZP1000_mA0600",126)); 
  ////Samples.push_back(SamplePair("2HDM_mZP1200_mA0600",127)); 
  //Samples.push_back(SamplePair("2HDM_mZP1400_mA0600",128)); 
  //Samples.push_back(SamplePair("2HDM_mZP1700_mA0600",129)); 
  //Samples.push_back(SamplePair("2HDM_mZP2000_mA0600",130));  
  //Samples.push_back(SamplePair("2HDM_mZP2500_mA0600",131));  
  ////Samples.push_back(SamplePair("2HDM_mZP600_mA0700",132)); 
  ////Samples.push_back(SamplePair("2HDM_mZP800_mA0700",133)); 
  //Samples.push_back(SamplePair("2HDM_mZP1000_mA0700",134)); 
  //Samples.push_back(SamplePair("2HDM_mZP1200_mA0700",135)); 
  //Samples.push_back(SamplePair("2HDM_mZP1400_mA0700",136)); 
  //Samples.push_back(SamplePair("2HDM_mZP1700_mA0700",137)); 
  //Samples.push_back(SamplePair("2HDM_mZP2000_mA0700",138));  
  //Samples.push_back(SamplePair("2HDM_mZP2500_mA0700",139));  
  ////Samples.push_back(SamplePair("2HDM_mZP600_mA0800",140)); 
  ////Samples.push_back(SamplePair("2HDM_mZP800_mA0800",141)); 
  //Samples.push_back(SamplePair("2HDM_mZP1000_mA0800",141)); 
  //Samples.push_back(SamplePair("2HDM_mZP1200_mA0800",142)); 
  //Samples.push_back(SamplePair("2HDM_mZP1400_mA0800",143)); 
  //Samples.push_back(SamplePair("2HDM_mZP1700_mA0800",144)); 
  //Samples.push_back(SamplePair("2HDM_mZP2000_mA0800",145));  
  //Samples.push_back(SamplePair("2HDM_mZP2500_mA0800",146));  
  //Samples.push_back(SamplePair("DMHtoGG_M1",0)); 
  //Samples.push_back(SamplePair("DMHtoGG_M10",0)); 
  //Samples.push_back(SamplePair("DMHtoGG_M100",0)); 
  //Samples.push_back(SamplePair("DMHtoGG_M1000",0)); 


  // Read sample names
  for (SamplePairVecIter iter = Samples.begin(); iter != Samples.end(); ++iter){
    if ( (*iter).second == 1 )      {fBkgNames.push_back((*iter).first);}  // non-res background
    else if ( (*iter).second == 0 ) {fResNames.push_back((*iter).first);}  // resonant background
    else if ( (*iter).second == 2 ) {fDataNames.push_back((*iter).first);} // data
    else			    {fSigNames.push_back((*iter).first);}  // signal
  }

  fNData = fDataNames.size();
  fNBkg = fBkgNames.size();
  fNRes = fResNames.size();
  fNSig = fSigNames.size();
  fNSamples = fNData+fNBkg+fNRes+fNSig;

}// end CardMaker::CardMaker

CardMaker::~CardMaker(){
  std::cout << "Finished & Deleting" << std::endl;
 
}// end CardMaker::~CardMaker

void CardMaker::MakeCards(){

  // set up vectors storing cuts to apply
  CardMaker::SetupCutsToApply();

  // set up vectors to store results
  Int_Results_NA.resize(fNSamples);
  Int_Results_ND.resize(fNSamples); 
  Dbl_Results_NA.resize(fNSamples);
  Dbl_Results_ND.resize(fNSamples);
  for (UInt_t iter = 0; iter < fNSamples; ++iter){ 
    Int_Results_NA[iter].resize(fNSig);
    Int_Results_ND[iter].resize(fNSig); 
    Dbl_Results_NA[iter].resize(fNSig);
    Dbl_Results_ND[iter].resize(fNSig);
    for (UInt_t n = 0; n < fNSig; n++){
      Int_Results_NA[iter][n] = 0;
      Int_Results_ND[iter][n] = 0; 
      Dbl_Results_NA[iter][n] = 0;
      Dbl_Results_ND[iter][n] = 0;
    } 
  }

  UInt_t SampleNumber=0;
  DblVecVec Dbl_Results_ND_Sig;
  DblVecVec Dbl_Results_ND_Res; 
  DblVecVec Dbl_Results_ND_Data;
  DblVec    Dbl_Results_NA_Bkg;
  IntVec    Int_Results_NA_Bkg;

  Dbl_Results_NA_Bkg.resize(fNSig);// one entry for each cut (because one cut for each signal)
  for (UInt_t n=0; n<fNSig; n++) Dbl_Results_NA_Bkg[n]=0; 
  Int_Results_NA_Bkg.resize(fNSig);// one entry for each cut (because one cut for each signal)
  for (UInt_t n=0; n<fNSig; n++) Int_Results_NA_Bkg[n]=0; 
  Dbl_Results_ND_Res.resize(fNSig);// one entry for each cut (because one cut for each signal)
  for (UInt_t n=0; n<fNSig; n++){
    Dbl_Results_ND_Res[n].resize(fNRes);//values for each resonant bkg;
    for (UInt_t mc=0; mc<fNRes; mc++) Dbl_Results_ND_Res[n][mc]=0; 
  }

  // open the file for each sample, open the tree for that file and then 
  // apply the common selection to each sample
  for (SamplePairVecIter iter = Samples.begin(); iter != Samples.end(); ++iter){
    CardMaker::ApplyCommonSelection( (*iter).first, (*iter).second, SampleNumber);
    // regroup to be more convenient for datacard writing
    if ((*iter).second==0){
      for (UInt_t n=0; n<fNSig; n++){
	for (UInt_t mc=0; mc<fNRes; mc++){
	  Dbl_Results_ND_Res[n][mc] = Dbl_Results_ND[SampleNumber][n];
	}
      }
      //Dbl_Results_ND_Res.push_back(Dbl_Results_ND[SampleNumber]);
    }
    else if ((*iter).second==2) Dbl_Results_ND_Data.push_back(Dbl_Results_ND[SampleNumber]);
    else if ((*iter).second==1){
      for (UInt_t n=0; n<fNSig; n++){ 
        Dbl_Results_NA_Bkg[n]+=Dbl_Results_NA[SampleNumber][n];
        Int_Results_NA_Bkg[n]+=Int_Results_NA[SampleNumber][n];
      }
    }
    else  Dbl_Results_ND_Sig.push_back(Dbl_Results_ND[SampleNumber]);
    SampleNumber++;
  }

  // Write out the datacard (one for each signal sample)
  for (UInt_t mc=0; mc < fNSig; mc++){
    CardMaker::WriteDataCard( fSigNames[mc] , Dbl_Results_ND_Sig[mc][mc], Int_Results_NA_Bkg[mc], Dbl_Results_NA_Bkg[mc], Dbl_Results_ND_Data[0][mc], Dbl_Results_ND_Res[mc]);
  } 

}// end CardMaker::MakeCards


void CardMaker::ApplyCommonSelection( const TString fSample, const UInt_t sampleID , const UInt_t sampleNumber){

  // open each file
  TFile *fileOrig = 0;
  TString fileName = Form("%s%s.root",fInDir.Data(),fSample.Data());
  fileOrig = TFile::Open(fileName.Data());
  CheckValidFile(fileOrig,fileName);

  // open the tree
  TTree *treeOrig = 0;
  fileOrig->cd();
  TString treeName = "DiPhotonTree";
  treeOrig = (TTree*)fileOrig->Get(treeName);
  CheckValidTree(treeOrig,treeName,fileName); 

  // Initialize variables for the tree
  CardMaker::SetBranchAddresses( treeOrig );

  std::cout << "Pickup MET Phi Correction" << std::endl; 
  std::vector< Double_t > fMETCorrMC;
  std::vector< Double_t > fMETCorrData;
  // pick up MC metCorr
  TString metStudyMC = Form("%s/metCorr_MC.root",fInDir.Data());
  TFile *fmetCorrMC = TFile::Open(metStudyMC.Data());
  TH1D *MCmet = (TH1D*)fmetCorrMC->Get("metCorr");  
  // pick up Data metCorr
  TString metStudyData = Form("%s/metCorr_Data.root",fInDir.Data());
  TFile *fmetCorrDATA = TFile::Open(metStudyData.Data());
  TH1D *DATAmet = (TH1D*)fmetCorrDATA->Get("metCorr");  
  for (UInt_t i=0; i<4; i++){
    fMETCorrMC.push_back(MCmet->GetBinContent(i+1));
    fMETCorrData.push_back(DATAmet->GetBinContent(i+1));
  }

  TLorentzVector fLorenzVecPho1;
  TLorentzVector fLorenzVecPho2;
  TLorentzVector fLorenzVecGG;
  TLorentzVector fLorenzVecJet1;
  TLorentzVector fLorenzVecJet2;
  TLorentzVector fLorenzVecJet3;
  TLorentzVector fLorenzVecJet4;
  TLorentzVector correctedMet;

  // loop over tree entries and apply selection
  UInt_t nentriesOrig = treeOrig->GetEntries();
  for (UInt_t i=0; i<nentriesOrig; i++){
    treeOrig->GetEntry(i);

    // fill the Lorentz Vectors
    fLorenzVecPho1.SetPtEtaPhiM(pt1,eta1,phi1,0.);
    fLorenzVecPho2.SetPtEtaPhiM(pt2,eta2,phi2,0.);
    fLorenzVecGG = fLorenzVecPho1 + fLorenzVecPho2;
    fLorenzVecJet1.SetPtEtaPhiM(ptJetLead,etaJetLead,phiJetLead,massJetLead);
    fLorenzVecJet2.SetPtEtaPhiM(ptJetSubLead,etaJetSubLead,phiJetSubLead,massJetSubLead);
    fLorenzVecJet3.SetPtEtaPhiM(ptJet3,etaJet3,phiJet3,massJet3);
    fLorenzVecJet4.SetPtEtaPhiM(ptJet4,etaJet4,phiJet4,massJet4);

    // met-phi correction
    Double_t t1pfmetCorrX, t1pfmetCorrY, t1pfmetCorrE, t1pfmetCorr;

    if (sampleID==2){// data 
      t1pfmetCorrX = t1pfmet*cos(t1pfmetPhi) - (fMETCorrData[0] + fMETCorrData[1]*t1pfmetSumEt);
      t1pfmetCorrY = t1pfmet*sin(t1pfmetPhi) - (fMETCorrData[2] + fMETCorrData[3]*t1pfmetSumEt);
    }
    else{// mc
      t1pfmetCorrX = t1pfmet*cos(t1pfmetPhi) - (fMETCorrMC[0] + fMETCorrMC[1]*t1pfmetSumEt);
      t1pfmetCorrY = t1pfmet*sin(t1pfmetPhi) - (fMETCorrMC[2] + fMETCorrMC[3]*t1pfmetSumEt);
    }
    t1pfmetCorrE = sqrt(t1pfmetCorrX*t1pfmetCorrX + t1pfmetCorrY*t1pfmetCorrY);
    correctedMet.SetPxPyPzE(t1pfmetCorrX,t1pfmetCorrY,0,t1pfmetCorrE);
    t1pfmetCorr = correctedMet.Pt();

    // calculate the weight
    Double_t Weight = (weight)*fPUWeights[nvtx];// PURW[0] corresponds to bin1=0vtx

    // check that data passes METfilters
    if (sampleID==2 && (metF_GV!=1 || metF_HBHENoise!=1 || metF_HBHENoiseIso!=1 || metF_CSC!=1 || metF_eeBadSC!=1)) continue; //|| metF_MuonBadTrack!=1 || metF_HadronTrackRes!=1)) continue; 

    // check that passes trigger
    if (sampleID==2 && hltDiphoton30Mass95==0) continue;

    // remove duplicate events
    if (fSample=="GJets" && (genmatch1==1 && genmatch2==1)) continue;   // only PF and FF for gjets  
    if (fSample=="QCD" && (genmatch1==1 && genmatch2==1)) continue;   // only PF and FF for gjets  

    // check if passing deltaPhi(gg,MET) cut
    Double_t dphi_ggMET = TMath::Abs(deltaPhi(fLorenzVecGG.Phi(),correctedMet.Phi()));
    if (dphi_ggMET < 2.1) continue;

    // look at deltaPhi(jet,MET)
    Double_t min_dphi_JetMET = 10.;
    Double_t max_dphi_JetMET = 0.;

    if (nJets > 0){
      Double_t dphiJet1METmin = 10;
      Double_t dphiJet2METmin = 10;
      Double_t dphiJet3METmin = 10;
      Double_t dphiJet4METmin = 10;
      Double_t dphiJet1METmax = 0;
      Double_t dphiJet2METmax = 0;
      Double_t dphiJet3METmax = 0;
      Double_t dphiJet4METmax = 0;
      if ( ptJetLead > 50 ){
        dphiJet1METmin = TMath::Abs(deltaPhi(fLorenzVecJet1.Phi(),correctedMet.Phi()));
        dphiJet1METmax = TMath::Abs(deltaPhi(fLorenzVecJet1.Phi(),correctedMet.Phi()));
      }
      if ( ptJetSubLead > 50 ){
        dphiJet2METmin = TMath::Abs(deltaPhi(fLorenzVecJet2.Phi(),correctedMet.Phi()));
        dphiJet2METmax = TMath::Abs(deltaPhi(fLorenzVecJet2.Phi(),correctedMet.Phi()));
      }
      if ( ptJet3 > 50 ){
        dphiJet3METmin = TMath::Abs(deltaPhi(fLorenzVecJet3.Phi(),correctedMet.Phi()));
        dphiJet3METmax = TMath::Abs(deltaPhi(fLorenzVecJet3.Phi(),correctedMet.Phi()));
      }
      if ( ptJet4 > 50 ){
        dphiJet4METmin = TMath::Abs(deltaPhi(fLorenzVecJet4.Phi(),correctedMet.Phi()));
        dphiJet4METmax = TMath::Abs(deltaPhi(fLorenzVecJet4.Phi(),correctedMet.Phi()));
      }

      // find the min_dphi_JetMET 
      if (dphiJet1METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet1METmin;	   
      if (dphiJet2METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet2METmin;	   
      if (dphiJet3METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet3METmin;	   
      if (dphiJet4METmin < min_dphi_JetMET) min_dphi_JetMET = dphiJet4METmin;	   

      // find the max_dphi_JetMET 
      if (dphiJet1METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet1METmax;	   
      if (dphiJet2METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet2METmax;	   
      if (dphiJet3METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet3METmax;	   
      if (dphiJet4METmax > max_dphi_JetMET) max_dphi_JetMET = dphiJet4METmax;	   
    }
    if (min_dphi_JetMET < 0.5 || max_dphi_JetMET > 2.7) continue; 

    if (nMuons > 0 || nEle > 1) continue;

    // any events that make it to this point have passed all the common selection
    for (UInt_t cut=0; cut < fNSig; cut++){
      if (pt1/mgg > Cut_pt1mgg[cut] && pt2/mgg > Cut_pt2mgg[cut] && ptgg > Cut_ptgg[cut]){
        if (t1pfmetCorr > Cut_met[cut]){
	  if (mgg > 120 && mgg < 130){
	    Int_Results_ND[sampleNumber][cut]++;
            Dbl_Results_ND[sampleNumber][cut]+=Weight;
	  }
	  else{
	    Int_Results_NA[sampleNumber][cut]++;
            Dbl_Results_NA[sampleNumber][cut]+=Weight;
	  }
	}// met cut
      }// pt1/mgg, pt2/mgg, ptgg cuts
    }// loop over the cuts (one for each signal sample)

 
  }// loop over entries in treeOrig

  delete treeOrig;
  delete fileOrig;

}// end CardMaker::ApplyCommonSelection





void  CardMaker::WriteDataCard(const TString fSigName, const Double_t ND_Sig, const UInt_t Int_NA_Bkg, const Double_t NA_Bkg, const Double_t ND_Data, const DblVec ND_Res){

  //final calculation: bkg rate = (Int)NA * Weight * alpha
  Double_t predBkg = NA_Bkg*alpha;
  Double_t gmNscale = predBkg/(Double_t)Int_NA_Bkg;

  TString DataCardName = Form("%s/%s/DataCard_%s.txt",fOutDir.Data(),fOut.Data(),fSigName.Data());
  std::cout << "Writing data card in: " << DataCardName.Data() << std::endl;
  fOutTxtFile.open(DataCardName); 
  if (fOutTxtFile.is_open()){
    fOutTxtFile << Form("#MonoHgg Datacard for C&C Limit Setting, %f fb-1 ",flumi) << std::endl;
    fOutTxtFile << "#Run with:combine -M Asymptotic cardname.txt --run blind " << std::endl;
    fOutTxtFile << Form("# Lumi =  %f fb-1",flumi) << std::endl;
    fOutTxtFile << "imax 1 " << std::endl;
    fOutTxtFile << "jmax * " << std::endl;
    fOutTxtFile << "kmax * " << std::endl;
    fOutTxtFile << "------------------------------------" << std::endl;
    fOutTxtFile << "bin 1" << std::endl;
    if (doBlind) fOutTxtFile << "observation 0" << std::endl;
    else fOutTxtFile << Form("observation %f",ND_Data) << std::endl;
    fOutTxtFile << "------------------------------------" << std::endl;
    fOutTxtFile << "bin	    1	1	1	1	1	1" << std::endl;
    fOutTxtFile << "process	   s	b	hgg	vbf	vh	tth" << std::endl;
    fOutTxtFile << "process	   0	1	2	3	4	5" << std::endl;
    fOutTxtFile << Form("rate	   %f	%f	%f	%f	%f	%f",ND_Sig,predBkg,ND_Res[0],ND_Res[1],ND_Res[2],ND_Res[3]) << std::endl;
    fOutTxtFile << " " << std::endl;
    fOutTxtFile << "------------------------------------" << std::endl;
    fOutTxtFile << "#MC related" << std::endl;
    fOutTxtFile << "lumi	    lnN	1.023	-	1.023	1.023	1.023	1.023" << std::endl;
    fOutTxtFile << "eff	    lnN	1.030   -       1.030   1.030   1.030   1.030" << std::endl;
    fOutTxtFile << "higg_BR     lnN	0.953/1.050	-	0.953/1.050	0.953/1.050	0.953/1.050	0.953/1.050" << std::endl;
    fOutTxtFile << "higg_alphas lnN 0.940/0.965	-	0.940/0.965	0.940/0.965	0.940/0.965	0.940/0.965" << std::endl;
    fOutTxtFile << "PDFs        lnN 1.05		-	1.05		1.05		1.05		1.05" << std::endl;
    fOutTxtFile << "JetEnUp     lnN 1.005           -       -		-		1.005		-" << std::endl;
    fOutTxtFile << "JetEnDown   lnN 1.005           -       -		-		1.005		-" << std::endl;
    fOutTxtFile << "PhoEnUp     lnN 1.005           -       -		-		1.005		-" << std::endl;
    fOutTxtFile << "PhoEnDown   lnN 1.005           -       -		-		1.005		-" << std::endl;
    fOutTxtFile << "UnclEnUp    lnN 1.005           -       -               -               1.005           -" << std::endl;
    fOutTxtFile << "UnclEnDown  lnN 1.005           -       -               -               1.005           -" << std::endl;
    fOutTxtFile << "FakeMet     lnN -               0.6/1.4	0.6/1.4         0.6/1.4		-		0.6/1.4 " << std::endl;
    fOutTxtFile << "------------------------------------" << std::endl;
    fOutTxtFile << "#background related " << std::endl;
    fOutTxtFile << Form("bg_lept	    gmN	%i	-	%f	-	-	-	-",Int_NA_Bkg,gmNscale) << std::endl;
    fOutTxtFile << "alpha lnN - 1.2 - - - -" << std::endl;
  
  }// fOutTxtFile is_open
  else std::cout << "Unable to open DataCard Output File" << std::endl;
  fOutTxtFile.close();
  std::cout << "Finished Writing DataCard" << std::endl;



}// end CardMaker::WriteDataCard



void CardMaker::SetupCutsToApply(){

  /////////////////////////////////////////////////////////  
  // Setup cuts for pt1/mgg for each signal sample
  Cut_pt1mgg.push_back(0.50); // mZp600, mA0300
  Cut_pt1mgg.push_back(0.80); // mZp800, mA0300
  Cut_pt1mgg.push_back(0.85); // mZp1000, mA0300
  Cut_pt1mgg.push_back(1.20); // mZp1200, mA0300
  Cut_pt1mgg.push_back(1.40); // mZp1400, mA0300
  Cut_pt1mgg.push_back(1.40); // mZp1700, mA0300
  Cut_pt1mgg.push_back(1.40); // mZp2000, mA0300
  Cut_pt1mgg.push_back(1.40); // mZp2500, mA0300

  Cut_pt1mgg.push_back(Cut_pt1mgg[0]); // mZp600, mA0400
  Cut_pt1mgg.push_back(Cut_pt1mgg[1]); // mZp800, mA0400
  Cut_pt1mgg.push_back(Cut_pt1mgg[2]); // mZp1000, mA0400
  Cut_pt1mgg.push_back(Cut_pt1mgg[3]); // mZp1200, mA0400
  Cut_pt1mgg.push_back(Cut_pt1mgg[4]); // mZp1400, mA0400
  Cut_pt1mgg.push_back(Cut_pt1mgg[5]); // mZp1700, mA0400
  Cut_pt1mgg.push_back(Cut_pt1mgg[6]); // mZp2000, mA0400
  //Cut_pt1mgg.push_back(Cut_pt1mgg[7]); // mZp2500, mA0400

  //Cut_pt1mgg.push_back(Cut_pt1mgg[0]); // mZp600, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[1]); // mZp800, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[2]); // mZp1000, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[3]); // mZp1200, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[4]); // mZp1400, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[5]); // mZp1700, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[6]); // mZp2000, mA0500
  Cut_pt1mgg.push_back(Cut_pt1mgg[7]); // mZp2500, mA0500
   
  //Cut_pt1mgg.push_back(Cut_pt1mgg[0]); // mZp600, mA0600
  Cut_pt1mgg.push_back(Cut_pt1mgg[1]); // mZp800, mA0600
  Cut_pt1mgg.push_back(Cut_pt1mgg[2]); // mZp1000, mA0600
  //Cut_pt1mgg.push_back(Cut_pt1mgg[3]); // mZp1200, mA0600
  Cut_pt1mgg.push_back(Cut_pt1mgg[4]); // mZp1400, mA0600
  Cut_pt1mgg.push_back(Cut_pt1mgg[5]); // mZp1700, mA0600
  Cut_pt1mgg.push_back(Cut_pt1mgg[6]); // mZp2000, mA0600
  Cut_pt1mgg.push_back(Cut_pt1mgg[7]); // mZp2500, mA0600
   
  //Cut_pt1mgg.push_back(Cut_pt1mgg[0]); // mZp600, mA0700
  //Cut_pt1mgg.push_back(Cut_pt1mgg[1]); // mZp800, mA0700
  Cut_pt1mgg.push_back(Cut_pt1mgg[2]); // mZp1000, mA0700
  Cut_pt1mgg.push_back(Cut_pt1mgg[3]); // mZp1200, mA0700
  Cut_pt1mgg.push_back(Cut_pt1mgg[4]); // mZp1400, mA0700
  Cut_pt1mgg.push_back(Cut_pt1mgg[5]); // mZp1700, mA0700
  Cut_pt1mgg.push_back(Cut_pt1mgg[6]); // mZp2000, mA0700
  Cut_pt1mgg.push_back(Cut_pt1mgg[7]); // mZp2500, mA0700
   
  //Cut_pt1mgg.push_back(Cut_pt1mgg[0]); // mZp600, mA0800
  //Cut_pt1mgg.push_back(Cut_pt1mgg[1]); // mZp800, mA0800
  Cut_pt1mgg.push_back(Cut_pt1mgg[2]); // mZp1000, mA0800
  Cut_pt1mgg.push_back(Cut_pt1mgg[3]); // mZp1200, mA0800
  Cut_pt1mgg.push_back(Cut_pt1mgg[4]); // mZp1400, mA0800
  Cut_pt1mgg.push_back(Cut_pt1mgg[5]); // mZp1700, mA0800
  Cut_pt1mgg.push_back(Cut_pt1mgg[6]); // mZp2000, mA0800
  Cut_pt1mgg.push_back(Cut_pt1mgg[7]); // mZp2500, mA0800
  

 
  /////////////////////////////////////////////////////////  
  // Setup cuts for pt2/mgg for each signal sample
  Cut_pt2mgg.push_back(0.25); // mZp600, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp800, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp1000, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp1200, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp1400, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp1700, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp2000, mA0300
  Cut_pt2mgg.push_back(0.25); // mZp2500, mA0300

  Cut_pt2mgg.push_back(Cut_pt2mgg[0]); // mZp600, mA0400
  Cut_pt2mgg.push_back(Cut_pt2mgg[1]); // mZp800, mA0400
  Cut_pt2mgg.push_back(Cut_pt2mgg[2]); // mZp1000, mA0400
  Cut_pt2mgg.push_back(Cut_pt2mgg[3]); // mZp1200, mA0400
  Cut_pt2mgg.push_back(Cut_pt2mgg[4]); // mZp1400, mA0400
  Cut_pt2mgg.push_back(Cut_pt2mgg[5]); // mZp1700, mA0400
  Cut_pt2mgg.push_back(Cut_pt2mgg[6]); // mZp2000, mA0400
  //Cut_pt2mgg.push_back(Cut_pt2mgg[7]); // mZp2500, mA0400

  //Cut_pt2mgg.push_back(Cut_pt2mgg[0]); // mZp600, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[1]); // mZp800, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[2]); // mZp1000, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[3]); // mZp1200, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[4]); // mZp1400, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[5]); // mZp1700, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[6]); // mZp2000, mA0500
  Cut_pt2mgg.push_back(Cut_pt2mgg[7]); // mZp2500, mA0500
   
  //Cut_pt2mgg.push_back(Cut_pt2mgg[0]); // mZp600, mA0600
  Cut_pt2mgg.push_back(Cut_pt2mgg[1]); // mZp800, mA0600
  Cut_pt2mgg.push_back(Cut_pt2mgg[2]); // mZp1000, mA0600
  //Cut_pt2mgg.push_back(Cut_pt2mgg[3]); // mZp1200, mA0600
  Cut_pt2mgg.push_back(Cut_pt2mgg[4]); // mZp1400, mA0600
  Cut_pt2mgg.push_back(Cut_pt2mgg[5]); // mZp1700, mA0600
  Cut_pt2mgg.push_back(Cut_pt2mgg[6]); // mZp2000, mA0600
  Cut_pt2mgg.push_back(Cut_pt2mgg[7]); // mZp2500, mA0600
   
  //Cut_pt2mgg.push_back(Cut_pt2mgg[0]); // mZp600, mA0700
  //Cut_pt2mgg.push_back(Cut_pt2mgg[1]); // mZp800, mA0700
  Cut_pt2mgg.push_back(Cut_pt2mgg[2]); // mZp1000, mA0700
  Cut_pt2mgg.push_back(Cut_pt2mgg[3]); // mZp1200, mA0700
  Cut_pt2mgg.push_back(Cut_pt2mgg[4]); // mZp1400, mA0700
  Cut_pt2mgg.push_back(Cut_pt2mgg[5]); // mZp1700, mA0700
  Cut_pt2mgg.push_back(Cut_pt2mgg[6]); // mZp2000, mA0700
  Cut_pt2mgg.push_back(Cut_pt2mgg[7]); // mZp2500, mA0700
   
  //Cut_pt2mgg.push_back(Cut_pt2mgg[0]); // mZp600, mA0800
  //Cut_pt2mgg.push_back(Cut_pt2mgg[1]); // mZp800, mA0800
  Cut_pt2mgg.push_back(Cut_pt2mgg[2]); // mZp1000, mA0800
  Cut_pt2mgg.push_back(Cut_pt2mgg[3]); // mZp1200, mA0800
  Cut_pt2mgg.push_back(Cut_pt2mgg[4]); // mZp1400, mA0800
  Cut_pt2mgg.push_back(Cut_pt2mgg[5]); // mZp1700, mA0800
  Cut_pt2mgg.push_back(Cut_pt2mgg[6]); // mZp2000, mA0800
  Cut_pt2mgg.push_back(Cut_pt2mgg[7]); // mZp2500, mA0800
  

  
  /////////////////////////////////////////////////////////  
  // Setup cuts for ptgg for each signal sample
  Cut_ptgg.push_back(90);  // mZp600, mA0300
  Cut_ptgg.push_back(135); // mZp800, mA0300
  Cut_ptgg.push_back(170); // mZp1000, mA0300
  Cut_ptgg.push_back(250); // mZp1200, mA0300
  Cut_ptgg.push_back(260); // mZp1400, mA0300
  Cut_ptgg.push_back(315); // mZp1700, mA0300
  Cut_ptgg.push_back(315); // mZp2000, mA0300
  Cut_ptgg.push_back(315); // mZp2500, mA0300

  Cut_ptgg.push_back(Cut_ptgg[0]); // mZp600, mA0400
  Cut_ptgg.push_back(Cut_ptgg[1]); // mZp800, mA0400
  Cut_ptgg.push_back(Cut_ptgg[2]); // mZp1000, mA0400
  Cut_ptgg.push_back(Cut_ptgg[3]); // mZp1200, mA0400
  Cut_ptgg.push_back(Cut_ptgg[4]); // mZp1400, mA0400
  Cut_ptgg.push_back(Cut_ptgg[5]); // mZp1700, mA0400
  Cut_ptgg.push_back(Cut_ptgg[6]); // mZp2000, mA0400
  //Cut_ptgg.push_back(Cut_ptgg[7]); // mZp2500, mA0400

  //Cut_ptgg.push_back(Cut_ptgg[0]); // mZp600, mA0500
  Cut_ptgg.push_back(Cut_ptgg[1]); // mZp800, mA0500
  Cut_ptgg.push_back(Cut_ptgg[2]); // mZp1000, mA0500
  Cut_ptgg.push_back(Cut_ptgg[3]); // mZp1200, mA0500
  Cut_ptgg.push_back(Cut_ptgg[4]); // mZp1400, mA0500
  Cut_ptgg.push_back(Cut_ptgg[5]); // mZp1700, mA0500
  Cut_ptgg.push_back(Cut_ptgg[6]); // mZp2000, mA0500
  Cut_ptgg.push_back(Cut_ptgg[7]); // mZp2500, mA0500
   
  //Cut_ptgg.push_back(Cut_ptgg[0]); // mZp600, mA0600
  Cut_ptgg.push_back(Cut_ptgg[1]); // mZp800, mA0600
  Cut_ptgg.push_back(Cut_ptgg[2]); // mZp1000, mA0600
  //Cut_ptgg.push_back(Cut_ptgg[3]); // mZp1200, mA0600
  Cut_ptgg.push_back(Cut_ptgg[4]); // mZp1400, mA0600
  Cut_ptgg.push_back(Cut_ptgg[5]); // mZp1700, mA0600
  Cut_ptgg.push_back(Cut_ptgg[6]); // mZp2000, mA0600
  Cut_ptgg.push_back(Cut_ptgg[7]); // mZp2500, mA0600
   
  //Cut_ptgg.push_back(Cut_ptgg[0]); // mZp600, mA0700
  //Cut_ptgg.push_back(Cut_ptgg[1]); // mZp800, mA0700
  Cut_ptgg.push_back(Cut_ptgg[2]); // mZp1000, mA0700
  Cut_ptgg.push_back(Cut_ptgg[3]); // mZp1200, mA0700
  Cut_ptgg.push_back(Cut_ptgg[4]); // mZp1400, mA0700
  Cut_ptgg.push_back(Cut_ptgg[5]); // mZp1700, mA0700
  Cut_ptgg.push_back(Cut_ptgg[6]); // mZp2000, mA0700
  Cut_ptgg.push_back(Cut_ptgg[7]); // mZp2500, mA0700
   
  //Cut_ptgg.push_back(Cut_ptgg[0]); // mZp600, mA0800
  //Cut_ptgg.push_back(Cut_ptgg[1]); // mZp800, mA0800
  Cut_ptgg.push_back(Cut_ptgg[2]); // mZp1000, mA0800
  Cut_ptgg.push_back(Cut_ptgg[3]); // mZp1200, mA0800
  Cut_ptgg.push_back(Cut_ptgg[4]); // mZp1400, mA0800
  Cut_ptgg.push_back(Cut_ptgg[5]); // mZp1700, mA0800
  Cut_ptgg.push_back(Cut_ptgg[6]); // mZp2000, mA0800
  Cut_ptgg.push_back(Cut_ptgg[7]); // mZp2500, mA0800
   

  
  /////////////////////////////////////////////////////////  
  // Setup cuts for MET for each signal sample
  Cut_met.push_back(105); // mZp600, mA0300
  Cut_met.push_back(165); // mZp800, mA0300
  Cut_met.push_back(220); // mZp1000, mA0300
  Cut_met.push_back(245); // mZp1200, mA0300
  Cut_met.push_back(255); // mZp1400, mA0300
  Cut_met.push_back(285); // mZp1700, mA0300
  Cut_met.push_back(285); // mZp2000, mA0300
  Cut_met.push_back(285); // mZp2500, mA0300

  Cut_met.push_back(Cut_met[0]); // mZp600, mA0400
  Cut_met.push_back(Cut_met[1]); // mZp800, mA0400
  Cut_met.push_back(Cut_met[2]); // mZp1000, mA0400
  Cut_met.push_back(Cut_met[3]); // mZp1200, mA0400
  Cut_met.push_back(Cut_met[4]); // mZp1400, mA0400
  Cut_met.push_back(Cut_met[5]); // mZp1700, mA0400
  Cut_met.push_back(Cut_met[6]); // mZp2000, mA0400
  //Cut_met.push_back(Cut_met[7]); // mZp2500, mA0400

  //Cut_met.push_back(Cut_met[0]); // mZp600, mA0500
  Cut_met.push_back(Cut_met[1]); // mZp800, mA0500
  Cut_met.push_back(Cut_met[2]); // mZp1000, mA0500
  Cut_met.push_back(Cut_met[3]); // mZp1200, mA0500
  Cut_met.push_back(Cut_met[4]); // mZp1400, mA0500
  Cut_met.push_back(Cut_met[5]); // mZp1700, mA0500
  Cut_met.push_back(Cut_met[6]); // mZp2000, mA0500
  Cut_met.push_back(Cut_met[7]); // mZp2500, mA0500
   
  //Cut_met.push_back(Cut_met[0]); // mZp600, mA0600
  Cut_met.push_back(Cut_met[1]); // mZp800, mA0600
  Cut_met.push_back(Cut_met[2]); // mZp1000, mA0600
  //Cut_met.push_back(Cut_met[3]); // mZp1200, mA0600
  Cut_met.push_back(Cut_met[4]); // mZp1400, mA0600
  Cut_met.push_back(Cut_met[5]); // mZp1700, mA0600
  Cut_met.push_back(Cut_met[6]); // mZp2000, mA0600
  Cut_met.push_back(Cut_met[7]); // mZp2500, mA0600
   
  //Cut_met.push_back(Cut_met[0]); // mZp600, mA0700
  //Cut_met.push_back(Cut_met[1]); // mZp800, mA0700
  Cut_met.push_back(Cut_met[2]); // mZp1000, mA0700
  Cut_met.push_back(Cut_met[3]); // mZp1200, mA0700
  Cut_met.push_back(Cut_met[4]); // mZp1400, mA0700
  Cut_met.push_back(Cut_met[5]); // mZp1700, mA0700
  Cut_met.push_back(Cut_met[6]); // mZp2000, mA0700
  Cut_met.push_back(Cut_met[7]); // mZp2500, mA0700
   
  //Cut_met.push_back(Cut_met[0]); // mZp600, mA0800
  //Cut_met.push_back(Cut_met[1]); // mZp800, mA0800
  Cut_met.push_back(Cut_met[2]); // mZp1000, mA0800
  Cut_met.push_back(Cut_met[3]); // mZp1200, mA0800
  Cut_met.push_back(Cut_met[4]); // mZp1400, mA0800
  Cut_met.push_back(Cut_met[5]); // mZp1700, mA0800
  Cut_met.push_back(Cut_met[6]); // mZp2000, mA0800
  Cut_met.push_back(Cut_met[7]); // mZp2500, mA0800
   

}// end CardMaker::SetupCutsToApply



void CardMaker::SetBranchAddresses( TTree * treeIn){
  treeIn->SetBranchAddress("run", &run, &b_run);
  treeIn->SetBranchAddress("event", &event, &b_event);
  treeIn->SetBranchAddress("lumi", &lumi, &b_lumi);
  treeIn->SetBranchAddress("rho", &rho, &b_rho);
  treeIn->SetBranchAddress("sampleID", &sampleID, &b_sampleID);
  treeIn->SetBranchAddress("weight", &weight,  &b_weight);
  treeIn->SetBranchAddress("nvtx",   &nvtx,    &b_nvtx);
  treeIn->SetBranchAddress("mgg",    &mgg,     &b_mgg);
  treeIn->SetBranchAddress("ptgg",   &ptgg,    &b_ptgg);
  treeIn->SetBranchAddress("t1pfmet", &t1pfmet, &b_t1pfmet);   
  treeIn->SetBranchAddress("t1p2pfmet", &t1p2pfmet, &b_t1p2pfmet);
  treeIn->SetBranchAddress("t1pfmetJetEnUp", &t1pfmetJetEnUp, &b_t1pfmetJetEnUp);
  treeIn->SetBranchAddress("t1pfmetJetEnDown", &t1pfmetJetEnDown, &b_t1pfmetJetEnDown);
  treeIn->SetBranchAddress("t1pfmetJetResUp", &t1pfmetJetResUp, &b_t1pfmetJetResUp);
  treeIn->SetBranchAddress("t1pfmetJetResDown", &t1pfmetJetResDown, &b_t1pfmetJetResDown);
  treeIn->SetBranchAddress("t1pfmetMuonEnUp", &t1pfmetMuonEnUp, &b_t1pfmetMuonEnUp);
  treeIn->SetBranchAddress("t1pfmetMuonEnDown", &t1pfmetMuonEnDown, &b_t1pfmetMuonEnDown);
  treeIn->SetBranchAddress("t1pfmetElectronEnUp", &t1pfmetElectronEnUp, &b_t1pfmetElectronEnUp);
  treeIn->SetBranchAddress("t1pfmetElectronEnDown", &t1pfmetElectronEnDown, &b_t1pfmetElectronEnDown);
  treeIn->SetBranchAddress("t1pfmetTauEnUp", &t1pfmetTauEnUp, &b_t1pfmetTauEnUp);
  treeIn->SetBranchAddress("t1pfmetTauEnDown", &t1pfmetTauEnDown, &b_t1pfmetTauEnDown);
  treeIn->SetBranchAddress("t1pfmetPhotonEnUp", &t1pfmetPhotonEnUp, &b_t1pfmetPhotonEnUp);
  treeIn->SetBranchAddress("t1pfmetPhotonEnDown", &t1pfmetPhotonEnDown, &b_t1pfmetPhotonEnDown);
  treeIn->SetBranchAddress("t1pfmetUnclusteredEnUp", &t1pfmetUnclusteredEnUp, &b_t1pfmetUnclusteredEnUp);
  treeIn->SetBranchAddress("t1pfmetUnclusteredEnDown", &t1pfmetUnclusteredEnDown, &b_t1pfmetUnclusteredEnDown);
  treeIn->SetBranchAddress("t1pfmetPhi", &t1pfmetPhi, &b_t1pfmetPhi);
  treeIn->SetBranchAddress("t1pfmetSumEt", &t1pfmetSumEt, &b_t1pfmetSumEt);   
  treeIn->SetBranchAddress("pfmet", &pfmet, &b_pfmet);   
  treeIn->SetBranchAddress("pfmetPhi", &pfmetphi, &b_pfmetPhi);   
  treeIn->SetBranchAddress("pfmetSumEt", &pfmetSumEt, &b_pfmetSumEt);   
  treeIn->SetBranchAddress("calomet", &calomet, &b_calomet);   
  treeIn->SetBranchAddress("calometPhi", &calometphi, &b_calometPhi);   
  treeIn->SetBranchAddress("calometSumEt", &calometSumEt, &b_calometSumEt);   
  treeIn->SetBranchAddress("genmatch1", &genmatch1, &b_genmatch1);  
  treeIn->SetBranchAddress("genmatch2", &genmatch2, &b_genmatch2);   
  treeIn->SetBranchAddress("pt1", &pt1, &b_pt1);   
  treeIn->SetBranchAddress("pt2", &pt2, &b_pt2);   
  treeIn->SetBranchAddress("chiso1", &chiso1, &b_chiso1);   
  treeIn->SetBranchAddress("chiso2", &chiso2, &b_chiso2);   
  treeIn->SetBranchAddress("neuiso1", &neuiso1, &b_neuiso1);   
  treeIn->SetBranchAddress("neuiso2", &neuiso2, &b_neuiso2);   
  treeIn->SetBranchAddress("phoiso1", &phoiso1, &b_phoiso1);   
  treeIn->SetBranchAddress("phoiso2", &phoiso2, &b_phoiso2);   
  treeIn->SetBranchAddress("sieie1", &sieie1, &b_sieie1);   
  treeIn->SetBranchAddress("sieie2", &sieie2, &b_sieie2);   
  treeIn->SetBranchAddress("hoe1", &hoe1, &b_hoe1);   
  treeIn->SetBranchAddress("hoe2", &hoe2, &b_hoe2);   
  treeIn->SetBranchAddress("r91", &r91, &b_r91);   
  treeIn->SetBranchAddress("r92", &r92, &b_r92);   
  treeIn->SetBranchAddress("phi1", &phi1, &b_phi1);   
  treeIn->SetBranchAddress("phi2", &phi2, &b_phi2);   
  treeIn->SetBranchAddress("eta1", &eta1, &b_eta1);   
  treeIn->SetBranchAddress("eta2", &eta2, &b_eta2);   
  treeIn->SetBranchAddress("eleveto1", &eleveto1, &b_eleveto1);   
  treeIn->SetBranchAddress("eleveto2", &eleveto2, &b_eleveto2);  
  treeIn->SetBranchAddress("presel1", &presel1, &b_presel1); 
  treeIn->SetBranchAddress("presel2", &presel2, &b_presel2); 
  treeIn->SetBranchAddress("sel1", &sel1, &b_sel1); 
  treeIn->SetBranchAddress("sel2", &sel2, &b_sel2); 
  treeIn->SetBranchAddress("passCHiso1", &passCHiso1, &b_passCHiso1);   
  treeIn->SetBranchAddress("passCHiso2", &passCHiso2, &b_passCHiso2);   
  treeIn->SetBranchAddress("passNHiso1", &passNHiso1, &b_passNHiso1);   
  treeIn->SetBranchAddress("passNHiso2", &passNHiso2, &b_passNHiso2);   
  treeIn->SetBranchAddress("passPHiso1", &passPHiso1, &b_passNHiso1);   
  treeIn->SetBranchAddress("passPHiso2", &passPHiso2, &b_passNHiso2);   
  treeIn->SetBranchAddress("passSieie1", &passSieie1, &b_passSieie1);
  treeIn->SetBranchAddress("passSieie2", &passSieie2, &b_passSieie2);
  treeIn->SetBranchAddress("passHoe1", &passHoe1, &b_passHoe1);
  treeIn->SetBranchAddress("passHoe2", &passHoe2, &b_passHoe2);
  treeIn->SetBranchAddress("passLooseCHiso1", &passLooseCHiso1, &b_passLooseCHiso1);
  treeIn->SetBranchAddress("passLooseCHiso2", &passLooseCHiso2, &b_passLooseCHiso2);
  treeIn->SetBranchAddress("passLooseNHiso1", &passLooseNHiso1, &b_passLooseNHiso1);
  treeIn->SetBranchAddress("passLooseNHiso2", &passLooseNHiso2, &b_passLooseNHiso2);
  treeIn->SetBranchAddress("passLoosePHiso1", &passLoosePHiso1, &b_passLoosePHiso1);
  treeIn->SetBranchAddress("passLoosePHiso2", &passLoosePHiso2, &b_passLoosePHiso2);
  treeIn->SetBranchAddress("passLooseSieie1", &passLooseSieie1, &b_passLooseSieie1);
  treeIn->SetBranchAddress("passLooseSieie2", &passLooseSieie2, &b_passLooseSieie2);
  treeIn->SetBranchAddress("passLooseHoe1", &passLooseHoe1, &b_passLooseHoe1);
  treeIn->SetBranchAddress("passLooseHoe2", &passLooseHoe2, &b_passLooseHoe2);
  treeIn->SetBranchAddress("passTightCHiso1", &passTightCHiso1, &b_passTightCHiso1);
  treeIn->SetBranchAddress("passTightCHiso2", &passTightCHiso2, &b_passTightCHiso2);
  treeIn->SetBranchAddress("passTightNHiso1", &passTightNHiso1, &b_passTightNHiso1);
  treeIn->SetBranchAddress("passTightNHiso2", &passTightNHiso2, &b_passTightNHiso2);
  treeIn->SetBranchAddress("passTightPHiso1", &passTightPHiso1, &b_passTightPHiso1);
  treeIn->SetBranchAddress("passTightPHiso2", &passTightPHiso2, &b_passTightPHiso2);
  treeIn->SetBranchAddress("passTightSieie1", &passTightSieie1, &b_passTightSieie1);
  treeIn->SetBranchAddress("passTightSieie2", &passTightSieie2, &b_passTightSieie2);
  treeIn->SetBranchAddress("passTightHoe1", &passTightHoe1, &b_passTightHoe1);
  treeIn->SetBranchAddress("passTightHoe2", &passTightHoe2, &b_passTightHoe2);
  treeIn->SetBranchAddress("hltPhoton26Photon16Mass60", &hltPhoton26Photon16Mass60, &b_hltPhoton26Photon16Mass60);
  treeIn->SetBranchAddress("hltPhoton36Photon22Mass15", &hltPhoton36Photon22Mass15, &b_hltPhoton36Photon22Mass15);
  treeIn->SetBranchAddress("hltPhoton42Photon25Mass15", &hltPhoton42Photon25Mass15, &b_hltPhoton42Photon25Mass15);
  treeIn->SetBranchAddress("hltDiphoton30Mass95", &hltDiphoton30Mass95, &b_hltDiphoton30Mass95);
  treeIn->SetBranchAddress("hltDiphoton30Mass70", &hltDiphoton30Mass70, &b_hltDiphoton30Mass70);
  treeIn->SetBranchAddress("hltDiphoton30Mass55", &hltDiphoton30Mass55, &b_hltDiphoton30Mass55);
  treeIn->SetBranchAddress("hltDiphoton30Mass55PV", &hltDiphoton30Mass55PV, &b_hltDiphoton30Mass55PV);
  treeIn->SetBranchAddress("hltDiphoton30Mass55EB", &hltDiphoton30Mass55EB, &b_hltDiphoton30Mass55EB);
  treeIn->SetBranchAddress("nEle", &nEle, &b_nEle);
  treeIn->SetBranchAddress("nMuons", &nMuons, &b_nMuons);
  treeIn->SetBranchAddress("nJets", &nJets, &b_nJets);
  treeIn->SetBranchAddress("nLooseBjets", &nLooseBjets, &b_nLooseBjets);
  treeIn->SetBranchAddress("nMediumBjets", &nMediumBjets, &b_nMediumBjets);
  treeIn->SetBranchAddress("ptJetLead", &ptJetLead, &b_ptJetLead);
  treeIn->SetBranchAddress("etaJetLead", &etaJetLead, &b_etaJetLead);
  treeIn->SetBranchAddress("phiJetLead", &phiJetLead, &b_phiJetLead);
  treeIn->SetBranchAddress("massJetLead", &massJetLead, &b_massJetLead);
  treeIn->SetBranchAddress("indexJetLead", &indexJetLead, &b_indexJetLead);
  treeIn->SetBranchAddress("NEMfracJet1", &NEMfracJet1, &b_NEMfracJet1);
  treeIn->SetBranchAddress("CEMfracJet1", &CEMfracJet1, &b_CEMfracJet1);
  treeIn->SetBranchAddress("ELfracJet1", &ELfracJet1, &b_ELfracJet1);
  treeIn->SetBranchAddress("CHfracJet1", &CHfracJet1, &b_CHfracJet1);
  treeIn->SetBranchAddress("NHfracJet1", &NHfracJet1, &b_NHfracJet1);
  treeIn->SetBranchAddress("PHfracJet1", &PHfracJet1, &b_PHfracJet1);
  treeIn->SetBranchAddress("MUfracJet1", &MUfracJet1, &b_MUfracJet1);
  treeIn->SetBranchAddress("CHmultJet1", &CHmultJet1, &b_CHmultJet1);
  treeIn->SetBranchAddress("NEmultJet1", &NEmultJet1, &b_NEmultJet1);
  treeIn->SetBranchAddress("ptJetSubLead", &ptJetSubLead, &b_ptJetSubLead);
  treeIn->SetBranchAddress("etaJetSubLead", &etaJetSubLead, &b_etaJetSubLead);
  treeIn->SetBranchAddress("phiJetSubLead", &phiJetSubLead, &b_phiJetSubLead);
  treeIn->SetBranchAddress("massJetSubLead", &massJetSubLead, &b_massJetSubLead);
  treeIn->SetBranchAddress("indexJetSubLead", &indexJetSubLead, &b_indexJetSubLead);
  treeIn->SetBranchAddress("NEMfracJet2", &NEMfracJet2, &b_NEMfracJet2);
  treeIn->SetBranchAddress("CEMfracJet2", &CEMfracJet2, &b_CEMfracJet2);
  treeIn->SetBranchAddress("ELfracJet2", &ELfracJet2, &b_ELfracJet2);
  treeIn->SetBranchAddress("CHfracJet2", &CHfracJet2, &b_CHfracJet2);
  treeIn->SetBranchAddress("NHfracJet2", &NHfracJet2, &b_NHfracJet2);
  treeIn->SetBranchAddress("PHfracJet2", &PHfracJet2, &b_PHfracJet2);
  treeIn->SetBranchAddress("MUfracJet2", &MUfracJet2, &b_MUfracJet2);
  treeIn->SetBranchAddress("CHmultJet2", &CHmultJet2, &b_CHmultJet2);
  treeIn->SetBranchAddress("NEmultJet2", &NEmultJet2, &b_NEmultJet2);
  treeIn->SetBranchAddress("ptJet3", &ptJet3, &b_ptJet3);
  treeIn->SetBranchAddress("etaJet3", &etaJet3, &b_etaJet3);
  treeIn->SetBranchAddress("phiJet3", &phiJet3, &b_phiJet3);
  treeIn->SetBranchAddress("massJet3", &massJet3, &b_massJet3);
  treeIn->SetBranchAddress("indexJet3", &indexJet3, &b_indexJet3);
  treeIn->SetBranchAddress("NEMfracJet3", &NEMfracJet3, &b_NEMfracJet3);
  treeIn->SetBranchAddress("CEMfracJet3", &CEMfracJet3, &b_CEMfracJet3);
  treeIn->SetBranchAddress("ELfracJet3", &ELfracJet3, &b_ELfracJet3);
  treeIn->SetBranchAddress("CHfracJet3", &CHfracJet3, &b_CHfracJet3);
  treeIn->SetBranchAddress("NHfracJet3", &NHfracJet3, &b_NHfracJet3);
  treeIn->SetBranchAddress("PHfracJet3", &PHfracJet3, &b_PHfracJet3);
  treeIn->SetBranchAddress("MUfracJet3", &MUfracJet3, &b_MUfracJet3);
  treeIn->SetBranchAddress("CHmultJet3", &CHmultJet3, &b_CHmultJet3);
  treeIn->SetBranchAddress("NEmultJet3", &NEmultJet3, &b_NEmultJet3);
  treeIn->SetBranchAddress("ptJet4", &ptJet4, &b_ptJet4);
  treeIn->SetBranchAddress("etaJet4", &etaJet4, &b_etaJet4);
  treeIn->SetBranchAddress("phiJet4", &phiJet4, &b_phiJet4);
  treeIn->SetBranchAddress("massJet4", &massJet4, &b_massJet4);
  treeIn->SetBranchAddress("indexJet4", &indexJet4, &b_indexJet4);
  treeIn->SetBranchAddress("NEMfracJet4", &NEMfracJet4, &b_NEMfracJet4);
  treeIn->SetBranchAddress("CEMfracJet4", &CEMfracJet4, &b_CEMfracJet4);
  treeIn->SetBranchAddress("ELfracJet4", &ELfracJet4, &b_ELfracJet4);
  treeIn->SetBranchAddress("CHfracJet4", &CHfracJet4, &b_CHfracJet4);
  treeIn->SetBranchAddress("NHfracJet4", &NHfracJet4, &b_NHfracJet4);
  treeIn->SetBranchAddress("PHfracJet4", &PHfracJet4, &b_PHfracJet4);
  treeIn->SetBranchAddress("MUfracJet4", &MUfracJet4, &b_MUfracJet4);
  treeIn->SetBranchAddress("CHmultJet4", &CHmultJet4, &b_CHmultJet4);
  treeIn->SetBranchAddress("NEmultJet4", &NEmultJet4, &b_NEmultJet4);
  treeIn->SetBranchAddress("vhtruth", &vhtruth, &b_vhtruth);
  treeIn->SetBranchAddress("metF_GV", &metF_GV, &b_metF_GV);
  treeIn->SetBranchAddress("metF_HBHENoise", &metF_HBHENoise, &b_metF_HBHENoise);
  treeIn->SetBranchAddress("metF_HBHENoiseIso", &metF_HBHENoiseIso, &b_metF_HBHENoiseIso);
  treeIn->SetBranchAddress("metF_CSC", &metF_CSC, &b_metF_CSC);
  treeIn->SetBranchAddress("metF_eeBadSC", &metF_eeBadSC, &b_metF_eeBadSC);
  treeIn->SetBranchAddress("metF_MuonBadTrack", &metF_MuonBadTrack, &b_metF_MuonBadTrack);
  treeIn->SetBranchAddress("metF_HadronTrackRes", &metF_HadronTrackRes, &b_metF_HadronTrackRes);
  treeIn->SetBranchAddress("higgsVtxX", &higgsVtxX, &b_higgsVtxX);
  treeIn->SetBranchAddress("higgsVtxY", &higgsVtxY, &b_higgsVtxY);
  treeIn->SetBranchAddress("higgsVtxZ", &higgsVtxZ, &b_higgsVtxZ);
  treeIn->SetBranchAddress("vtxIndex", &vtxIndex, &b_vtxIndex);
  treeIn->SetBranchAddress("vtxX", &vtxX, &b_vtxX);
  treeIn->SetBranchAddress("vtxY", &vtxY, &b_vtxY);
  treeIn->SetBranchAddress("vtxZ", &vtxZ, &b_vtxZ);
  treeIn->SetBranchAddress("vtx0Z", &vtx0Z, &b_vtx0Z);
  treeIn->SetBranchAddress("genVtxX", &genVtxX, &b_genVtxX);
  treeIn->SetBranchAddress("genVtxY", &genVtxY, &b_genVtxY);
  treeIn->SetBranchAddress("genVtxZ", &genVtxZ, &b_genVtxZ);
  treeIn->SetBranchAddress("massCorrSmear", &massCorrSmear, &b_massCorrSmear);
  treeIn->SetBranchAddress("massCorrSmearUp", &massCorrSmearUp, &b_massCorrSmearUp);
  treeIn->SetBranchAddress("massCorrSmearDown", &massCorrSmearDown, &b_massCorrSmearDown);
  treeIn->SetBranchAddress("massCorrScale", &massCorrScale, &b_massCorrScale);
  treeIn->SetBranchAddress("massCorrScaleUp", &massCorrScaleUp, &b_massCorrScaleUp);
  treeIn->SetBranchAddress("massCorrScaleDown", &massCorrScaleDown, &b_massCorrScaleDown);
  treeIn->SetBranchAddress("massRaw", &massRaw, &b_massRaw);
  treeIn->SetBranchAddress("mva1", &mva1, &b_mva1);
  treeIn->SetBranchAddress("mva2", &mva2, &b_mva2);
  treeIn->SetBranchAddress("genZ", &genZ, &b_genZ);
  treeIn->SetBranchAddress("ptZ",  &ptZ,  &b_ptZ);
  treeIn->SetBranchAddress("etaZ", &etaZ, &b_etaZ);
  treeIn->SetBranchAddress("phiZ", &phiZ, &b_phiZ);
  treeIn->SetBranchAddress("BDTptgg", &BDTptgg, &b_BDTptgg);
  treeIn->SetBranchAddress("BDTmassRaw", &BDTmassRaw, &b_BDTmassRaw);
  treeIn->SetBranchAddress("BDTr91", &BDTr91, &b_BDTr91);
  treeIn->SetBranchAddress("BDTr92", &BDTr92, &b_BDTr92);
  treeIn->SetBranchAddress("BDTvtxZ", &BDTvtxZ, &b_BDTvtxZ);
  treeIn->SetBranchAddress("BDTindex", &BDTindex, &b_BDTindex);


};// end CardMaker::SetBranchAddresses

