#! /bin/sh
#run extractJSONS.py for all samples in file

# FLASHgg version 76X w/MET syst for 25ns: 
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o DoubleEG 		-d lists_25ns_v76X_vtx0/Data

python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o TTGG_0Jets  		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o TTGJets  		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o TGJets 		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o WGToLNuG 		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o ZGTo2LG   		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o ttHJetToGG		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o VBFHToGG		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o DiPhoton		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o DYJetsToLL		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o QCD_Pt-30to40	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o QCD_Pt-40toInf	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o GJet_Pt-20to40	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o GJet_Pt-40toInf	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o GluGluHToGG		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o VHToGG_M125		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_bkg_data_vtx0.json	-o ZZTo2L2Nu		-d lists_25ns_v76X_vtx0/MC

python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-100To200	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-200To400	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-400To600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-600To800	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-800To1200	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-1200To2500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_ZJetsToNuNu.json	-o ZJetsToNuNu_HT-2500ToInf	-d lists_25ns_v76X_vtx0/MC

python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP600		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP800		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP1000		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP1200		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP1400		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP1700		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP2000		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZP2500		-d lists_25ns_v76X_vtx0/MC

python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZp-600		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_sig_vtx0.json		-o 2HDM_MZp-800		-d lists_25ns_v76X_vtx0/MC

python extractJSONS.py -i datasets/datasets_76X_officialsig2.json	-o 2HDM_MZp-800_MA0-600		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig2.json	-o 2HDM_MZp-1200_MA0-600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig2.json	-o 2HDM_MZp-2500_MA0-400	-d lists_25ns_v76X_vtx0/MC

python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-800_MA0-500		-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1000_MA0-400	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1000_MA0-500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1000_MA0-600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1000_MA0-700	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1000_MA0-800	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1200_MA0-400	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1200_MA0-500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1200_MA0-700	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1200_MA0-800	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1400_MA0-400	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1400_MA0-500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1400_MA0-600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1400_MA0-700	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1400_MA0-800	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1700_MA0-400	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1700_MA0-500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1700_MA0-600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1700_MA0-700	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-1700_MA0-800	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2000_MA0-400	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2000_MA0-500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2000_MA0-600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2000_MA0-700	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2000_MA0-800	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2500_MA0-500	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2500_MA0-600	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2500_MA0-700	-d lists_25ns_v76X_vtx0/MC
python extractJSONS.py -i datasets/datasets_76X_officialsig.json	-o 2HDM_MZp-2500_MA0-800	-d lists_25ns_v76X_vtx0/MC

