#! /bin/sh
#run extractJSONS.py for all samples in file

# FLASHgg version 76X w/MET syst for 25ns
python extractFilesAndWeight.py -i lists_25ns_v76X/Data/DoubleEG.json		-o DoubleEG		-d lists_25ns_v76X

python extractFilesAndWeight.py -i lists_25ns_v76X/MC/TTGJets.json		-o TTGJets		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/TTGG_0Jets.json		-o TTGG_0Jets		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/TGJets.json		-o TGJets		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/WGToLNuG.json		-o WGToLNuG		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/ZGTo2LG.json		-o ZGTo2LG		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/GJet_Pt-20to40.json	-o GJet_Pt-20to40	-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/GJet_Pt-40toInf.json	-o GJet_Pt-40toInf	-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/VHToGG_M125.json		-o VH			-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/QCD_Pt-30to40.json	-o QCD_Pt-30to40	-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/QCD_Pt-40toInf.json	-o QCD_Pt-40toInf	-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/QCD_Pt-30toInf.json	-o QCD_Pt-30toInf	-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/DiPhoton.json		-o DiPhoton		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/GluGluHToGG.json		-o GluGluHToGG		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/DYJetsToLL.json		-o DYJetsToLL		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/ttHJetToGG_M125.json	-o ttHJetToGG		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/VBFHToGG.json		-o VBFHToGG		-d lists_25ns_v76X
python extractFilesAndWeight.py -i lists_25ns_v76X/MC/ZZTo2L2Nu.json		-o ZZTo2L2Nu		-d lists_25ns_v76X

#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP600.json		-o 2HDM_MZP600		-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP800.json		-o 2HDM_MZP800		-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP1000.json	-o 2HDM_MZP1000		-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP1200.json	-o 2HDM_MZP1200		-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP1400.json	-o 2HDM_MZP1400		-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP1700.json	-o 2HDM_MZP1700		-d lists_25ns_v76X
#python extractFilesAndWeight.py -i lists_25ns_v76X/MC/2HDM_MZP2500.json	-o 2HDM_MZP2500		-d lists_25ns_v76X

