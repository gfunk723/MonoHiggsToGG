#! /bin/sh 
# this scripts creates a merged root file in the self-created mergedFinal

#mkdir -p data/mergedFinal

hadd data/25ns_v76X_v2/GJets.root	data/25ns_v76X_v2/GJet_Pt-20to40.root	data/25ns_v76X_v2/GJet_Pt-40toInf.root 
hadd data/25ns_v76X_v2/QCD.root		data/25ns_v76X_v2/QCD_Pt-30to40.root	data/25ns_v76X_v2/QCD_Pt-40toInf.root	#data/25ns_v76X_v2/QCD_Pt-30toInf.root

