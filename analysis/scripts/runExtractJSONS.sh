#! /bin/sh
#run extractJSONS.py for all samples in file

# FLASHgg version 76X w/MET syst for 25ns: 
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o DoubleEG 		-d lists_25ns_v76X/Data

python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o TTGG_0Jets  		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o TTGJets  		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o TGJets 		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o WGToLNuG 		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o ZGTo2LG   		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o ttHJetToGG		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o VBFHToGG		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o DiPhoton		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o DYJetsToLL		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o QCD_Pt-30to40	-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o QCD_Pt-40toInf	-d lists_25ns_v76X/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o QCD_Pt-30toInf	-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o GJet_Pt-20to40	-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o GJet_Pt-40toInf	-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o GluGluHToGG		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o VHToGG_M125		-d lists_25ns_v76X/MC
python extractJSONS.py -i datasets/datasets_76X_ZZTo2L2Nu.json	-o ZZTo2L2Nu		-d lists_25ns_v76X/MC

#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP600		-d lists_25ns_v1_1_0_wMETsys/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP800		-d lists_25ns_v1_1_0_wMETsys/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP1000		-d lists_25ns_v1_1_0_wMETsys/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP1200		-d lists_25ns_v1_1_0_wMETsys/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP1400		-d lists_25ns_v1_1_0_wMETsys/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP1700		-d lists_25ns_v1_1_0_wMETsys/MC
#python extractJSONS.py -i datasets/datasets_76X_fromLivia.json	-o 2HDM_MZP2500		-d lists_25ns_v1_1_0_wMETsys/MC
