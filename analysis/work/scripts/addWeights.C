#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TDirectory.h"
#include "TString.h"
#include "TBranch.h"
#include <iostream>

using namespace std;

void addWeights(float lumiForWgt, TString path, TString sample){

   // ----------------------------------------------------------------  
   // get input from trees
   // ----------------------------------------------------------------  

   cout << "Running sample: " << sample << endl;
   TString filename = Form("%s%s.root",path.Data(),sample.Data());
   TFile* infile = TFile::Open(filename.Data());
   TTree* intree = 0; 
   TH1F *h_entries = 0;
   TH1F *h_sumW = 0;
   TH1F *h_selection = 0;
   TH1F *h_selection_unwgt = 0;

   if (infile){
     intree      = (TTree*)infile->Get("diPhoAna/DiPhotonTree");
     if (!intree){
       cout << "Tree diPhoAna/DiPhotonTree does not exist! Exiting..." << endl;
       exit(1);
     }
     h_entries         = (TH1F*)infile->Get("diPhoAna/h_entries");
     h_sumW            = (TH1F*)infile->Get("diPhoAna/h_sumW");
     h_selection       = (TH1F*)infile->Get("diPhoAna/h_selection");
     // save copy of h_selection without weighting 
     h_selection_unwgt = (TH1F*)h_selection->Clone();
     h_selection_unwgt->SetName("h_selection_unwgt");

 
     // ----------------------------------------------------------------  
     // set branch addresses of items needed to do weighting 
     // ----------------------------------------------------------------  

     int sampleID;		intree->SetBranchAddress("sampleID",&sampleID);
     float totXsec;		intree->SetBranchAddress("totXsec",&totXsec);
     float perEveW;		intree->SetBranchAddress("perEveW",&perEveW);
     float pu_weight;		intree->SetBranchAddress("pu_weight",&pu_weight);
     float SF1;			intree->SetBranchAddress("SF1",&SF1);
     float SF2;			intree->SetBranchAddress("SF2",&SF2);

     // ----------------------------------------------------------------  
     // other info needed to do weights 
     // ----------------------------------------------------------------  

     float sampleSumWgt = (float)h_sumW->Integral(); // sum of wgts in dataset
     int   nentries     = intree->GetEntries();      // number of entries 
     float xsecToWeight = 0.;

     // ----------------------------------------------------------------  
     // setup output file 
     // ----------------------------------------------------------------  

     TFile *outfile = TFile::Open(filename,"recreate");
     // clone structure of input tree, but storing no events
     TTree *outtree = (TTree*)infile->Get("diPhoAna/DiPhotonTree");
     outtree = intree->CloneTree(0); 

     // ----------------------------------------------------------------  
     // new branch to be added
     // ----------------------------------------------------------------  

     float xsecWeight;	outtree->Branch("xsecWeight",&xsecWeight, "xsecWeight/F");
     float weight;	outtree->Branch("weight",&weight, "weight/F");

     // ----------------------------------------------------------------  
     // loop over output tree 
     // ----------------------------------------------------------------  
     
     for (UInt_t entry = 0; entry < intree->GetEntries(); entry++){

        if (entry%10000 == 0) cout << "Weighting event # " << entry << " / " << nentries << " entries" << endl; 
        intree->GetEntry(entry);

        // ----------------------------------------------------------------  
        // apply weighting 
        // ----------------------------------------------------------------  

        if (entry==0) xsecToWeight = totXsec;// pick up total xsec 
        if (sampleID>0 && sampleID<10000){// MC
          xsecWeight = SF1 * SF2 * perEveW * lumiForWgt * totXsec / sampleSumWgt;
          weight     = xsecWeight * pu_weight;
        }
        else{// Data
          if (entry%10000 == 0 && sampleID >= 10000) cout << "No weighting for data" << endl;
          xsecWeight = 1.;
          weight     = 1.;
        }

        outtree->Fill();// fill output tree

     }// finish event loop

     // weight h_selection
     h_selection->Scale( xsecToWeight / sampleSumWgt);

     // ----------------------------------------------------------------  
     // write the output tree 
     // ----------------------------------------------------------------  

     outfile->cd();
     h_entries->Write();
     h_sumW->Write();
     h_selection->Write();
     h_selection_unwgt->Write();
     outtree->Write();

     // now delete (close) everything
     delete intree;
     delete infile;
     delete outtree;
     delete outfile;

   }
   else cout << "File " << sample << " does not exist!" << endl;
 
}// END







