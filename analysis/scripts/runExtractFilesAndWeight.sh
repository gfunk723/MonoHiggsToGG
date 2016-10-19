#! /bin/sh
#run extractJSONS.py for all samples in file

## FLASHgg version 80X for 25ns
python extractFilesAndWeight.py -i lists_25ns_v80X_v0/Data/DoubleEG.json		-o DoubleEG		-d lists_25ns_v80X_v0
python extractFilesAndWeight.py -i lists_25ns_v80X_v0/MC/DiPhoton.json			-o DiPhoton 		-d lists_25ns_v80X_v0
python extractFilesAndWeight.py -i lists_25ns_v80X_v0/MC/GluGluHToGG.json		-o GluGluHToGG 		-d lists_25ns_v80X_v0
python extractFilesAndWeight.py -i lists_25ns_v80X_v0/MC/2HDM_MZp-600_MA0-300.json	-o 2HDM_MZp-600_MA0-300	-d lists_25ns_v80X_v0



## FLASHgg version 76X w/MET syst for 25ns
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/Data/DoubleEG.json		-o DoubleEG		-d lists_25ns_v76X_vtx0
#
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/TTGJets.json			-o TTGJets		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/TTGG_0Jets.json		-o TTGG_0Jets		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/TGJets.json			-o TGJets		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/WGToLNuG.json		-o WGToLNuG		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZGTo2LG.json			-o ZGTo2LG		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/GJet_Pt-20to40.json		-o GJet_Pt-20to40	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/GJet_Pt-40toInf.json		-o GJet_Pt-40toInf	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/VHToGG_M125.json		-o VH			-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/QCD_Pt-30to40.json		-o QCD_Pt-30to40	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/QCD_Pt-40toInf.json		-o QCD_Pt-40toInf	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/DiPhoton.json		-o DiPhoton		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/GluGluHToGG.json		-o GluGluHToGG		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/DYJetsToLL.json		-o DYJetsToLL		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ttHJetToGG.json		-o ttHJetToGG		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/VBFHToGG.json		-o VBFHToGG		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZZTo2L2Nu.json		-o ZZTo2L2Nu		-d lists_25ns_v76X_vtx0
#
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-100To200.json		-o ZJets_HT-100To200	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-200To400.json		-o ZJets_HT-200To400	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-400To600.json		-o ZJets_HT-400To600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-600To800.json		-o ZJets_HT-600To800	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-800To1200.json	-o ZJets_HT-800To1200	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-1200To2500.json	-o ZJets_HT-1200To2500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/ZJetsToNuNu_HT-2500ToInf.json	-o ZJets_HT-2500ToInf	-d lists_25ns_v76X_vtx0
#
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP600.json		-o 2HDM_MZP600		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP800.json		-o 2HDM_MZP800		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP1000.json		-o 2HDM_MZP1000		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP1200.json		-o 2HDM_MZP1200		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP1400.json		-o 2HDM_MZP1400		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP1700.json		-o 2HDM_MZP1700		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP2000.json		-o 2HDM_MZP2000		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZP2500.json		-o 2HDM_MZP2500		-d lists_25ns_v76X_vtx0
#
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-600.json		-o 2HDM_MZp-600		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-800.json		-o 2HDM_MZp-800		-d lists_25ns_v76X_vtx0
#
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-800_MA0-600.json	-o 2HDM_MZp-800_MA0-600		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1200_MA0-600.json	-o 2HDM_MZp-1200_MA0-600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2500_MA0-400.json	-o 2HDM_MZp-2500_MA0-400	-d lists_25ns_v76X_vtx0
#
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-800_MA0-500.json	-o 2HDM_MZp-800_MA0-500		-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1000_MA0-400.json	-o 2HDM_MZp-1000_MA0-400	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1000_MA0-500.json	-o 2HDM_MZp-1000_MA0-500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1000_MA0-600.json	-o 2HDM_MZp-1000_MA0-600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1000_MA0-700.json	-o 2HDM_MZp-1000_MA0-700	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1000_MA0-800.json	-o 2HDM_MZp-1000_MA0-800	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1200_MA0-400.json	-o 2HDM_MZp-1200_MA0-400	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1200_MA0-500.json	-o 2HDM_MZp-1200_MA0-500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1200_MA0-700.json	-o 2HDM_MZp-1200_MA0-700	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1200_MA0-800.json	-o 2HDM_MZp-1200_MA0-800	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1400_MA0-400.json	-o 2HDM_MZp-1400_MA0-400	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1400_MA0-500.json	-o 2HDM_MZp-1400_MA0-500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1400_MA0-600.json	-o 2HDM_MZp-1400_MA0-600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1400_MA0-700.json	-o 2HDM_MZp-1400_MA0-700	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1400_MA0-800.json	-o 2HDM_MZp-1400_MA0-800	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1700_MA0-400.json	-o 2HDM_MZp-1700_MA0-400	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1700_MA0-500.json	-o 2HDM_MZp-1700_MA0-500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1700_MA0-600.json	-o 2HDM_MZp-1700_MA0-600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1700_MA0-700.json	-o 2HDM_MZp-1700_MA0-700	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-1700_MA0-800.json	-o 2HDM_MZp-1700_MA0-800	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2000_MA0-400.json	-o 2HDM_MZp-2000_MA0-400	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2000_MA0-500.json	-o 2HDM_MZp-2000_MA0-500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2000_MA0-600.json	-o 2HDM_MZp-2000_MA0-600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2000_MA0-700.json	-o 2HDM_MZp-2000_MA0-700	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2000_MA0-800.json	-o 2HDM_MZp-2000_MA0-800	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2500_MA0-500.json	-o 2HDM_MZp-2500_MA0-500	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2500_MA0-600.json	-o 2HDM_MZp-2500_MA0-600	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2500_MA0-700.json	-o 2HDM_MZp-2500_MA0-700	-d lists_25ns_v76X_vtx0
#python extractFilesAndWeight.py -i lists_25ns_v76X_vtx0/MC/2HDM_MZp-2500_MA0-800.json	-o 2HDM_MZp-2500_MA0-800	-d lists_25ns_v76X_vtx0
