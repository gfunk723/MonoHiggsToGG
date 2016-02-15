#define METCorr2016_cxx

#include "METCorr2016.hh"
#include "Style.hh"
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TProfile.h>
#include <TLorentzVector.h>

DblVec METCorr2016::Loop()
{
  DblVec metcorr;
  metcorr.resize(4);
  for (UInt_t i=0; i<metcorr.size(); i++) metcorr[i]=0.0;

  //if (fChain == 0) return;
  
  TFile *temp=new TFile("metstudy.root", "RECREATE");
  TProfile metx("metx","",100,100,2500);
  TProfile mety("mety","",100,100,2500);
  
  TProfile metxnew("metxnew","",100,100,2500);
  TProfile metynew("metynew","",100,100,2500);
  
  TH1D metphi("metphi","",100,-3.14,3.14);
  TH1D metphinew("metphinew","",100,-3.14,3.14);
  
  Long64_t nentries = fChain->GetEntriesFast();
  std::cout << nentries << std::endl;

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if (jentry%100000 == 0) std::cout << "Events " << jentry << "/" << nentries << " processed 1' round" << std::endl;
    
    //if(dipho_BDTOutput<-0.2) continue;  // loose presel already there
    if(pt1<33) continue;
    if(pt2<25) continue;
    
    metphi.Fill(t1pfmetPhi);
    metx.Fill(t1pfmetSumEt,t1pfmet*cos(t1pfmetPhi));
    mety.Fill(t1pfmetSumEt,t1pfmet*sin(t1pfmetPhi));
  }
  
  double px0(0), px1(0), py0(0), py1(0); 
  TF1 line("line","pol1",100,2500);
  
  metx.Fit("line"); 
  px0 = line.GetParameter(0);
  px1 = line.GetParameter(1);
  
  mety.Fit("line"); 
  py0 = line.GetParameter(0);
  py1 = line.GetParameter(1);
  
  nentries = fChain->GetEntriesFast();
  
  nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if (jentry%100000 == 0) std::cout << "Events " << jentry << "/" << nentries << " processed 2' round" << std::endl;
    
    //if(dipho_BDTOutput<-0.2) continue;
    if(pt1<33) continue;
    if(pt2<25) continue;
    
    // correction for METx, METy bias
    double px(0), py(0), e(0);
    px = t1pfmet*cos(t1pfmetPhi) -(px0+px1*t1pfmetSumEt);
    py = t1pfmet*sin(t1pfmetPhi) -(py0+py1*t1pfmetSumEt);
    
    e = sqrt(px*px+py*py);
    
    TLorentzVector correctedMet;
    correctedMet.SetPxPyPzE(px,py,0,e);
    
    metphinew.Fill(correctedMet.Phi());
    metxnew.Fill(t1pfmetSumEt,correctedMet.Px());
    metynew.Fill(t1pfmetSumEt,correctedMet.Py());
    
  }
  
  metx.Write();
  mety.Write();
  
  metxnew.Write();
  metynew.Write();
  
  metphi.Write();
  metphinew.Write();
  
  temp->Write() ;
  temp->Close() ;
  temp->Delete();
  
  std::cout << "px = t1pfmet*cos(t1pfmetPhi) -(" << px0 << " + " << px1 << " * t1pfmetSumEt)" << std::endl;
  std::cout << "py = t1pfmet*sin(t1pfmetPhi) -(" << py0 << " + " << py1 << " * t1pfmetSumEt)" << std::endl;

  
  metcorr[0]=px0;
  metcorr[1]=px1;
  metcorr[2]=py0;
  metcorr[3]=py1;
  return metcorr;
}