#! /bin/sh
#run extractJSONS.py for all samples in file


# FLASHgg version 80X: 
python extractJSONS.py -i datasets/datasets_moriond17_runB_v0.json		-o Run2016B 				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runC_v0.json		-o Run2016C				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runDH_v0.json		-o Run2016D				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runDH_v0.json		-o Run2016E				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runDH_v0.json		-o Run2016F				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runDH_v0.json		-o Run2016G				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runDH_v0.json		-o Run2016H				-d lists_25ns_v80X_v2/Data
python extractJSONS.py -i datasets/datasets_moriond17_runHv2_v1.json		-o Run2016H				-d lists_25ns_v80X_v3/Data

python extractJSONS.py -i datasets/datasets_moriond17_addbkg_v0.json		-o GluGluHToGG				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o VBFHToGG				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o VHToGG				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o ttHToGG				-d lists_25ns_v80X_v2/MC

python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnlo		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM	-d lists_25ns_v80X_v2/MC

python extractJSONS.py -i datasets/datasets_moriond17_dipho_v0.json		-o DiPhotonJetsBox_M40_80 		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_dipho_v0.json		-o DiPhotonJetsBox_MGG-80toInf 		-d lists_25ns_v80X_v2/MC
#python extractJSONS.py -i datasets/datasets_moriond17_dipho_v0.json		-o DiPhotonJets_MGG-80toInf 		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o GJet_Pt-20to40 			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o GJet_Pt-20toInf 			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_addbkg_v0.json		-o GJet_Pt-40toInf			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o QCD_Pt-30to40 			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o QCD_Pt-30toInf 			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o QCD_Pt-40toInf 			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o TGJets 				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o TTGG_0Jets 				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o TTGJets 				-d lists_25ns_v80X_v2/MC
#python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o TT_					-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o WGToLNuG				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o WJetsToLNu 				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o WW_ 					-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_addbkg2_v0.json		-o QCD_Pt-30to40 			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_addbkg2_v0.json		-o TTJets 				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_addbkg2_v0.json		-o WZTo2L2Q				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o ZGTo2LG				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o ZGTo2NuG				-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bkg_v0.json		-o ZZTo2L2Q				-d lists_25ns_v80X_v2/MC

python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-600_MA0-300			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-800_MA0-300			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-1000_MA0-300		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-1200_MA0-300		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-1400_MA0-300		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-1700_MA0-300		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-2000_MA0-300		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm_v0.json		-o 2HDM_MZp-2500_MA0-300		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-600_MA0-400			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-800_MA0-400			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1000_MA0-400		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1200_MA0-400		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1400_MA0-400		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1700_MA0-400		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2000_MA0-400		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-2500_MA0-400		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-800_MA0-500			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1000_MA0-500		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1200_MA0-500		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1400_MA0-500		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1700_MA0-500		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2000_MA0-500		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-2500_MA0-500		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-800_MA0-600			-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1000_MA0-600		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-1200_MA0-600		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-1400_MA0-600		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1700_MA0-600		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2000_MA0-600		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-2500_MA0-600		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1000_MA0-700		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1200_MA0-700		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-1400_MA0-700		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1700_MA0-700		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2000_MA0-700		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2500_MA0-700		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1000_MA0-800		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-1200_MA0-800		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_add2hdm2_v0.json		-o 2HDM_MZp-1400_MA0-800		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-1700_MA0-800		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2000_MA0-800		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_2hdm_v0.json		-o 2HDM_MZp-2500_MA0-800		-d lists_25ns_v80X_v2/MC

python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10000_MChi-1000_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10000_MChi-10_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10000_MChi-150_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10000_MChi-1_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10000_MChi-500_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10000_MChi-50_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-1000_MChi-150_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-1000_MChi-1_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_scal_v0.json		-o Scalar_MZp-1000_MChi-1000_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-100_MChi-10_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-100_MChi-1_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10_MChi-1000_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10_MChi-10_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10_MChi-1_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-10_MChi-500_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_scal_v0.json		-o Scalar_MZp-10_MChi-150_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_scal_v0.json		-o Scalar_MZp-10_MChi-50_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_scal_v0.json		-o Scalar_MZp-15_MChi-10_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-200_MChi-150_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-200_MChi-1_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-200_MChi-50_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-20_MChi-1_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-295_MChi-150_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-300_MChi-1_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-300_MChi-50_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-500_MChi-150_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-500_MChi-1_13TeV		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-500_MChi-500_13TeV 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-50_MChi-10_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-50_MChi-1_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-50_MChi-50_13TeV	 	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-95_MChi-50_13TeV		-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o Scalar_MZp-995_MChi-500_13TeV 	-d lists_25ns_v80X_v2/MC

python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-1000_MChi-1000_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-1000_MChi-150_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-1000_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bary_v0.json		-o ZpBaryonic_MZp-500_MChi-500_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bary_v0.json		-o ZpBaryonic_MZp-500_MChi-150_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-500_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-100_MChi-10_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10_MChi-10_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10000_MChi-1000_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10000_MChi-500_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10000_MChi-50_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10000_MChi-150_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10000_MChi-10_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10000_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-100_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10_MChi-1000_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-10_MChi-50_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-15_MChi-10_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-1995_MChi-1000_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bary_v0.json		-o ZpBaryonic_MZp-2000_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bary_v0.json		-o ZpBaryonic_MZp-2000_MChi-500_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bary_v0.json		-o ZpBaryonic_MZp-200_MChi-150_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-200_MChi-50_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-200_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-20_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-295_MChi-150_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-300_MChi-50_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-50_MChi-10_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_bary_v0.json		-o ZpBaryonic_MZp-50_MChi-1_13TeV	-d lists_25ns_v80X_v2/MC
python extractJSONS.py -i datasets/datasets_moriond17_sig_v0.json		-o ZpBaryonic_MZp-995_MChi-500_13TeV	-d lists_25ns_v80X_v2/MC

