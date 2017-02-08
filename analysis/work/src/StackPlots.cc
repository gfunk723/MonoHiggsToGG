#include "../interface/StackPlots.hh"

StackPlots::StackPlots()
{

  //------------------------------------------------------------------------
  // Setup samples
  //------------------------------------------------------------------------
  for (TStrBoolMapIter iter = Config::SampleMap.begin(); iter != Config::SampleMap.end(); ++iter) {
    if ((*iter).second) { // Data
      fDataNames.push_back((*iter).first);
    }
    else { // MC
      if (((*iter).first).Contains("mZP",TString::kExact)) fSigNames.push_back((*iter).first);
      else fBkgNames.push_back((*iter).first);
    }
  }
  fNData = fDataNames.size();
  fNBkg  = fBkgNames.size();
  fNSig  = fSigNames.size();
  std::cout << "DataSize = " << fNData << " BkgSize = " << fNBkg << " SigSize = " << fNSig << std::endl;

  //------------------------------------------------------------------------
  // Setup output
  //------------------------------------------------------------------------
  fOutDir = Form("%s/stacks",Config::outdir.Data()); // where to put output stack plots 
  MakeOutDir(fOutDir); // make output directory 
  fOutFile = new TFile(Form("%s/stackplots_canv.root",fOutDir.Data()),"RECREATE"); // ouput tfile to store canvases here for quick editting

  //------------------------------------------------------------------------
  // Initialize objects
  //------------------------------------------------------------------------
  StackPlots::OpenInputFiles();
 
}

void StackPlots::DoStack()
{

}

void StackPlots::OpenInputFiles()
{

  //------------------------------------------------------------------------
  // Get input files 
  //------------------------------------------------------------------------
  fDataFiles.resize(fNData);
  for (Int_t data = 0; data < fNData; data++) {
    TString datafile = Form("%s/%s/plots_%s.root",Config::outdir.Data(),fDataNames[data].Data(),fDataNames[data].Data());
    fDataFiles[data] = TFile::Open(datafile.Data());
    CheckValidFile(fDataFiles[data],datafile);
  }
  fBkgFiles.resize(fNBkg);
  for (Int_t mc = 0; mc < fNBkg; mc++) {
    TString mcfile = Form("%s/%s/plots_%s.root",Config::outdir.Data(),fBkgNames[mc].Data(),fBkgNames[mc].Data());
    fBkgFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fBkgFiles[mc],mcfile);
  }
  fSigFiles.resize(fNSig);
  for (Int_t mc = 0; mc < fNSig; mc++) {
    TString mcfile = Form("%s/%s/plots_%s.root",Config::outdir.Data(),fSigNames[mc].Data(),fSigNames[mc].Data());
    fSigFiles[mc] = TFile::Open(mcfile.Data());
    CheckValidFile(fSigFiles[mc],mcfile);
  }

}


StackPlots::~StackPlots()
{

  //------------------------------------------------------------------------
  // Finish by deleting everything
  //------------------------------------------------------------------------
  for (Int_t data = 0; data < fNData; data++) { delete fDataFiles[data]; }
  for (Int_t mc = 0; mc < fNBkg; mc++)        { delete fBkgFiles[mc]; }
  for (Int_t mc = 0; mc < fNSig; mc++)        { delete fSigFiles[mc]; }

  delete fOutFile;

}


