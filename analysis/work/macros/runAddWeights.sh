#! /bin/sh

path="/afs/cern.ch/work/m/mzientek/public/25ns_v80X_v5/"
#path="~/private/MonoHggCMSSW80X/CMSSW_8_0_8_patch1/src/MonoHiggsToGG/analysis/work/macros/"
sample=$1
weight=$2

echo "Adding weight of "${weight}"/pb to: "${sample}
root -l -b -q "../scripts/addWeights.C(${weight},"\"${path}\"","\"${sample}\"")"

echo "Finished adding weights"
