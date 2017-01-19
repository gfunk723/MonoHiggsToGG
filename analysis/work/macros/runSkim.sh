#! /bin/sh

path="~/private/MonoHggCMSSW80X/CMSSW_8_0_8_patch1/src/MonoHiggsToGG/analysis/work/macros/"
sample=$1

echo "Running sample: " ${sample}
root -l -b -q "../scripts/skim.C("\"${path}\"","\"${sample}\"")"

echo "done with skimming"
