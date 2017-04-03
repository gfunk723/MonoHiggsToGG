#include "../interface/Optimization.hh"

Optimization::Optimization(TString inName)
{
  //------------------------------------------------------------------------
  // Setup variables from inputs
  //------------------------------------------------------------------------
  name = inName;

  //------------------------------------------------------------------------
  // Setup samples
  //------------------------------------------------------------------------
  for (TStrBoolMapIter iter = Config::SampleMap.begin(); iter != Config::SampleMap.end(); ++iter) {
    if (!(*iter).second && !((*iter).first).Contains("mZP",TString::kExact)) { // Bkg
      fBkgNames.push_back((*iter).first);
    }
  }
  fNBkg  = fBkgNames.size();
  std::cout << " BkgSize = " << fNBkg << std::endl;

  //------------------------------------------------------------------------
  // Setup signal samples
  //------------------------------------------------------------------------
  fSigNames.push_back("2HDM_mZP600_mA0300");
  fNSig  = fSigNames.size();

  //------------------------------------------------------------------------
  // Setup output
  //------------------------------------------------------------------------
  fOutDir = Form("%s/optimize",Config::outdir.Data()); // where to put output stack plots 
  MakeOutDir(fOutDir); // make output directory 
  fOutFile = new TFile(Form("%s/optplots_canv.root",fOutDir.Data()),"RECREATE"); // ouput tfile to store canvases here for quick editting

  //------------------------------------------------------------------------
  // Initialize objects
  //------------------------------------------------------------------------
  MakeSubDirs(fTH1FSubDMap,fOutDir);       // setup output subdir
  Optimization::OpenInputFiles();          // open the input files
  Optimization::OpenTTrees();              // open the input ttrees
  Optimization::SetBranchAddresses();      // setup branches for trees

}


void Optimization::RunOptimization()
{


}

void Optimization::OpenInputFiles()
{

  //------------------------------------------------------------------------
  // Get input files 
  //------------------------------------------------------------------------
  fBkgFiles.resize(fNBkg);
  for (Int_t mc = 0; mc < fNBkg; mc++) {
    TString mcfile = Form("%s%s.root",name.Data(),fBkgNames[mc].Data());
    fBkgFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fBkgFiles[mc],mcfile);
  }
  fSigFiles.resize(fNSig);
  for (Int_t mc = 0; mc < fNSig; mc++) {
    TString mcfile = Form("%s%s.root",name.Data(),fSigNames[mc].Data());
    fSigFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fSigFiles[mc],mcfile);
  }
}

void Optimization::OpenTTrees()
{

  //------------------------------------------------------------------------
  // Get input trees 
  //------------------------------------------------------------------------
  fBkgTrees.resize(fNBkg);
  for (Int_t mc = 0; mc < fNBkg; mc++){
    fBkgTrees[mc] = (TTree*)fBkgFiles[mc]->Get("DiPhotonTree");
    CheckValidTree(fBkgTrees[mc],"DiPhotonTree",Form("%s%s.root",name.Data(),fBkgNames[mc].Data()));
  }
  fSigTrees.resize(fNSig);
  for (Int_t mc = 0; mc < fNSig; mc++){
    fSigTrees[mc] = (TTree*)fSigFiles[mc]->Get("DiPhotonTree");
    CheckValidTree(fSigTrees[mc],"DiPhotonTree",Form("%s%s.root",name.Data(),fSigNames[mc].Data()));
  }

}

void Optimization::SetBranchAddresses()
{

  //------------------------------------------------------------------------
  // Set branch addresses and branch pointers  
  //------------------------------------------------------------------------



}

Optimization::~Optimization()
{

  //------------------------------------------------------------------------
  // Finish by deleting everything
  //------------------------------------------------------------------------
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgTrees[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigTrees[mc]; }
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgFiles[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigFiles[mc]; }

  delete fOutFile;
}
