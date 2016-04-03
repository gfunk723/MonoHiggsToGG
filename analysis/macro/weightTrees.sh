#! /bin/sh                                                                                                    

lumi=$1      # in pb
echo "Adding weights for " $lumi " pb-1..."

root -l -b <<EOF
.L addWeightsToTree.cc++  
 
addWeights("data/25ns_v76X_v2/GJet_Pt-20to40.root", $lumi);
addWeights("data/25ns_v76X_v2/GJet_Pt-40toInf.root", $lumi);
addWeights("data/25ns_v76X_v2/QCD_Pt-30to40.root", $lumi);
addWeights("data/25ns_v76X_v2/QCD_Pt-30toInf.root", $lumi);
addWeights("data/25ns_v76X_v2/QCD_Pt-40toInf.root", $lumi);
addWeights("data/25ns_v76X_v2/GluGluHToGG.root", $lumi);
addWeights("data/25ns_v76X_v2/DiPhoton.root", $lumi);
addWeights("data/25ns_v76X_v2/VH.root", $lumi);
addWeights("data/25ns_v76X_v2/DYJetsToLL.root", $lumi);
addWeights("data/25ns_v76X_v2/ttHJetToGG.root", $lumi);
addWeights("data/25ns_v76X_v2/VBFHToGG.root", $lumi);
addWeights("data/25ns_v76X_v2/TTGJets.root", $lumi);
addWeights("data/25ns_v76X_v2/TGJets.root", $lumi);
addWeights("data/25ns_v76X_v2/TTGG_0Jets.root", $lumi);
addWeights("data/25ns_v76X_v2/WGToLNuG.root", $lumi);
addWeights("data/25ns_v76X_v2/ZGTo2LG.root", $lumi);
addWeights("data/25ns_v76X_v2/ZZTo2L2Nu.root", $lumi);

addWeights("data/25ns_v76X_v2/2HDM_mZP600.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP800.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP1000.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP1200.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP1400.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP1700.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP2000.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP2500.root", $lumi);

addWeights("data/25ns_v76X_v2/2HDM_mZP600_mA0400.root", $lumi);
addWeights("data/25ns_v76X_v2/2HDM_mZP800_mA0400.root", $lumi);

addWeights("data/25ns_v76X_v2/DoubleEG.root", $lumi);
.q

EOF

echo "done weighting."

