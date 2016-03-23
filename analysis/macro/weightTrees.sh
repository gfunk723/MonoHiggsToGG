#! /bin/sh                                                                                                    

lumi=$1      # in pb
echo "Adding weights for " $lumi " pb-1..."

root -l -b <<EOF
.L addWeightsToTree.cc++  
 
addWeights("data/25ns_v76X_v1/GJet_Pt-20to40.root", $lumi);
addWeights("data/25ns_v76X_v1/GJet_Pt-40toInf.root", $lumi);
addWeights("data/25ns_v76X_v1/QCD_Pt-30to40.root", $lumi);
addWeights("data/25ns_v76X_v1/QCD_Pt-30toInf.root", $lumi);
addWeights("data/25ns_v76X_v1/QCD_Pt-40toInf.root", $lumi);
addWeights("data/25ns_v76X_v1/GluGluHToGG.root", $lumi);
addWeights("data/25ns_v76X_v1/DiPhoton.root", $lumi);
addWeights("data/25ns_v76X_v1/VH.root", $lumi);
addWeights("data/25ns_v76X_v1/DYJetsToLL.root", $lumi);
addWeights("data/25ns_v76X_v1/ttHJetToGG.root", $lumi);
addWeights("data/25ns_v76X_v1/VBFHToGG.root", $lumi);
addWeights("data/25ns_v76X_v1/TTGJets.root", $lumi);
addWeights("data/25ns_v76X_v1/TGJets.root", $lumi);
addWeights("data/25ns_v76X_v1/TTGG_0Jets.root", $lumi);
addWeights("data/25ns_v76X_v1/WGToLNuG.root", $lumi);
addWeights("data/25ns_v76X_v1/ZGTo2LG.root", $lumi);
addWeights("data/25ns_v76X_v1/ZZTo2L2Nu.root", $lumi);

addWeights("data/25ns_v76X_v1/2HDM_mZP600.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP800.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP1000.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP1200.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP1400.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP1700.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP2000.root", $lumi);
addWeights("data/25ns_v76X_v1/2HDM_mZP2500.root", $lumi);

addWeights("data/25ns_v76X_v1/DoubleEG.root", $lumi);
.q

EOF

echo "done weighting."

