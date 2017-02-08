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
 
}

void StackPlots::DoStack()
{

}

StackPlots::~StackPlots()
{
  //------------------------------------------------------------------------
  // Finish by deleting everything
  //------------------------------------------------------------------------

}


