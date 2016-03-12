#! /bin/sh

inputDir="data/25ns_v1-1-0_ReReco_wAllJetInfo/"
outputDir="diPhoPlots/25ns_v1-1-0_ReReco_wAllJetInfo/Eff/"

mkdir -p $outputDir

root -l -b <<EOF
.L makeEffPlots.cc++

doEff("$inputDir","$outputDir",2.2);

.q

EOF
