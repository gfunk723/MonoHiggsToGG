#! /bin/sh

opt=3
suffix="_AllBkgs"
path="/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/"

root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"DoubleEG\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"DiPhoton\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"NonResBkg\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"EwkBkg\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"VHToGG\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"GluGluHToGG\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"ttHJetToGG\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"VBFHToGG\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP10_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP20_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP50_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP100_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP200_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP300_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP500_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP1000_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP2000_mChi1\"")"
root -l -b -q "applyMVA.C("\"${path}\"","\"${suffix}\"",$opt,"\"BaryonicZp_mZP10000_mChi1\"")"
