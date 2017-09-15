Directions for Setting up & Running Fit
=======

Setup CMSSW, get FLASHgg, Fit dir., HiggsCombine:

 ```
 cmsrel CMSSW_8_0_28
 cd CMSSW_8_0_28/src
 cmsenv
 git cms-init
 cd $CMSSW_BASE/src 
 
 # get FLASHgg first
 git clone https://github.com/cms-analysis/flashgg flashgg
 source flashgg/setup.sh
 
 # get diphotons analysis dir
 cd ${CMSSW_BASE}/src
 git clone https://github.com/musella/diphotons.git
 
 # get HiggsCombine dir
 cd ${CMSSW_BASE}/src
 git clone https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
 cd HiggsAnalysis/CombinedLimit

 ```

N.B. Versions I used: 
- FLASHgg: 
- diphotons: 
- HiggsCombine: 

Hand modify a few files: 
- $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit/test/plotting/bandUtils.cxx
  - Line #20: bool use_precomputed_quantiles = false -> true
- $CMSSW_BASE/src/diphotons/RooUtils/src/classes.h 
  - Line #6: dictionary -> roodictionary

Copy all of the files in this directory to diphotons/Analysis/macros/

Compile everything: 
```
cd $CMSSW_BASE/src
SCRAM_IGNORE_PACKAGES="flashgg/Validation" scram b -j 10
```


