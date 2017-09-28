#! /bin/sh
#run extractFilesAndWeight.py for all samples in file

## FLASHgg version 80X for 25ns
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016B.json		-o Run2016B			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016C.json		-o Run2016C			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016D.json		-o Run2016D			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016E.json		-o Run2016E			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016F.json		-o Run2016F			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016G.json		-o Run2016G			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/Data/Run2016H.json		-o Run2016H			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v3/Data/Run2016H.json		-o Run2016H			-d lists_25ns_v80X_v3

python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/GluGluHToGG.json		-o GluGluHToGG 			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/VBFHToGG.json			-o VBFHToGG			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/VHToGG.json			-o VHToGG			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ttHToGG.json			-o ttHToGG			-d lists_25ns_v80X_v2
                                                                                      
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnlo.json	-o DYJetsToLL 			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM.json	-o DYJetsToLLmadgraph 		-d lists_25ns_v80X_v2

python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DYJetsToLL.json		-o DYJetsToLL 			-d lists_25ns_v80X_v2
#python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DYToLL.json			-o DYToLL			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DiPhotonJetsBox_M40_80.json	-o DiPhotonJetsBox_M40_80 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DiPhotonJetsBox_MGG-80toInf.json -o DiPhotonJetsBox_MGG-80toInf -d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/DiPhotonJets_MGG-80toInf.json	-o DiPhotonJets_MGG-80toInf 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/GJet_Pt-20to40.json		-o GJet_Pt-20to40 		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/GJet_Pt-20toInf.json		-o GJet_Pt-20toInf 		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/GJet_Pt-40toInf.json		-o GJet_Pt-40toInf		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/QCD_Pt-30to40.json		-o QCD_Pt-30to40 		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/QCD_Pt-30toInf.json		-o QCD_Pt-30toInf 		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/QCD_Pt-40toInf.json		-o QCD_Pt-40toInf 		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/TGJets.json			-o TGJets 			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/TTGG_0Jets.json		-o TTGG_0Jets 			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/TTGJets.json			-o TTGJets 			-d lists_25ns_v80X_v2
#python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/TTJets.json			-o TTJets 			-d lists_25ns_v80X_v2
#python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/TT_.json			-o TT_				-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/WGToLNuG.json			-o WGToLNuG			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/WJetsToLNu.json		-o WJetsToLNu 			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/WW_.json			-o WW_ 				-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/WZTo2L2Q.json			-o WZTo2L2Q			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZGTo2LG.json			-o ZGTo2LG			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZGTo2NuG.json			-o ZGTo2NuG			-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZZTo2L2Q.json			-o ZZTo2L2Q			-d lists_25ns_v80X_v2

python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/SMS-T2bH_mSbottom-500_mLSP-1.json	-o SMS-T2bH_mSbottom-500_mLSP-1         -d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/SMS-T2bH_mSbottom-500_mLSP-50.json	-o SMS-T2bH_mSbottom-500_mLSP-50        -d lists_25ns_v80X_v2

python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10000_MChi-1000_13TeV.json	-o Scalar_MZp-10000_MChi-1000_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10000_MChi-10_13TeV.json 	-o Scalar_MZp-10000_MChi-10_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10000_MChi-150_13TeV.json 	-o Scalar_MZp-10000_MChi-150_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10000_MChi-1_13TeV.json	-o Scalar_MZp-10000_MChi-1_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10000_MChi-500_13TeV.json 	-o Scalar_MZp-10000_MChi-500_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10000_MChi-50_13TeV.json 	-o Scalar_MZp-10000_MChi-50_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-1000_MChi-1000_13TeV.json 	-o Scalar_MZp-1000_MChi-1000_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-1000_MChi-150_13TeV.json 	-o Scalar_MZp-1000_MChi-150_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-1000_MChi-1_13TeV.json 	-o Scalar_MZp-1000_MChi-1_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-100_MChi-10_13TeV.json 	-o Scalar_MZp-100_MChi-10_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-100_MChi-1_13TeV.json	-o Scalar_MZp-100_MChi-1_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10_MChi-1000_13TeV.json 	-o Scalar_MZp-10_MChi-1000_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10_MChi-10_13TeV.json	-o Scalar_MZp-10_MChi-10_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10_MChi-150_13TeV.json 	-o Scalar_MZp-10_MChi-150_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10_MChi-1_13TeV.json	-o Scalar_MZp-10_MChi-1_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10_MChi-500_13TeV.json 	-o Scalar_MZp-10_MChi-500_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-10_MChi-50_13TeV.json	-o Scalar_MZp-10_MChi-50_13TeV		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-15_MChi-10_13TeV.json	-o Scalar_MZp-15_MChi-10_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-200_MChi-150_13TeV.json 	-o Scalar_MZp-200_MChi-150_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-200_MChi-1_13TeV.json	-o Scalar_MZp-200_MChi-1_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-200_MChi-50_13TeV.json 	-o Scalar_MZp-200_MChi-50_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-20_MChi-1_13TeV.json	-o Scalar_MZp-20_MChi-1_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-295_MChi-150_13TeV.json 	-o Scalar_MZp-295_MChi-150_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-300_MChi-1_13TeV.json	-o Scalar_MZp-300_MChi-1_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-300_MChi-50_13TeV.json 	-o Scalar_MZp-300_MChi-50_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-500_MChi-150_13TeV.json 	-o Scalar_MZp-500_MChi-150_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-500_MChi-1_13TeV.json	-o Scalar_MZp-500_MChi-1_13TeV		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-500_MChi-500_13TeV.json 	-o Scalar_MZp-500_MChi-500_13TeV 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-50_MChi-10_13TeV.json	-o Scalar_MZp-50_MChi-10_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-50_MChi-1_13TeV.json	-o Scalar_MZp-50_MChi-1_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-50_MChi-50_13TeV.json	-o Scalar_MZp-50_MChi-50_13TeV	 	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-95_MChi-50_13TeV.json	-o Scalar_MZp-95_MChi-50_13TeV		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/Scalar_MZp-995_MChi-500_13TeV.json 	-o Scalar_MZp-995_MChi-500_13TeV 	-d lists_25ns_v80X_v2


python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-600_MA0-300.json	-o 2HDM_MZp-600_MA0-300		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-800_MA0-300.json	-o 2HDM_MZp-800_MA0-300		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1000_MA0-300.json	-o 2HDM_MZp-1000_MA0-300	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1200_MA0-300.json	-o 2HDM_MZp-1200_MA0-300	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1400_MA0-300.json	-o 2HDM_MZp-1400_MA0-300	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1700_MA0-300.json	-o 2HDM_MZp-1700_MA0-300	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2000_MA0-300.json	-o 2HDM_MZp-2000_MA0-300	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2500_MA0-300.json	-o 2HDM_MZp-2500_MA0-300	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-600_MA0-400.json	-o 2HDM_MZp-600_MA0-400		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-800_MA0-400.json	-o 2HDM_MZp-800_MA0-400		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1000_MA0-400.json	-o 2HDM_MZp-1000_MA0-400	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1200_MA0-400.json	-o 2HDM_MZp-1200_MA0-400	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1400_MA0-400.json	-o 2HDM_MZp-1400_MA0-400	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1700_MA0-400.json	-o 2HDM_MZp-1700_MA0-400	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2000_MA0-400.json	-o 2HDM_MZp-2000_MA0-400	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2500_MA0-400.json	-o 2HDM_MZp-2500_MA0-400	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-800_MA0-500.json  	-o 2HDM_MZp-800_MA0-500		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1000_MA0-500.json	-o 2HDM_MZp-1000_MA0-500	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1200_MA0-500.json	-o 2HDM_MZp-1200_MA0-500	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1400_MA0-500.json	-o 2HDM_MZp-1400_MA0-500	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1700_MA0-500.json	-o 2HDM_MZp-1700_MA0-500	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2000_MA0-500.json	-o 2HDM_MZp-2000_MA0-500	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2500_MA0-500.json	-o 2HDM_MZp-2500_MA0-500	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-800_MA0-600.json  	-o 2HDM_MZp-800_MA0-600		-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1000_MA0-600.json	-o 2HDM_MZp-1000_MA0-600	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1200_MA0-600.json	-o 2HDM_MZp-1200_MA0-600	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1400_MA0-600.json	-o 2HDM_MZp-1400_MA0-600	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1700_MA0-600.json	-o 2HDM_MZp-1700_MA0-600	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2000_MA0-600.json	-o 2HDM_MZp-2000_MA0-600	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2500_MA0-600.json	-o 2HDM_MZp-2500_MA0-600	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1000_MA0-700.json	-o 2HDM_MZp-1000_MA0-700	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1200_MA0-700.json	-o 2HDM_MZp-1200_MA0-700	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1400_MA0-700.json	-o 2HDM_MZp-1400_MA0-700	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1700_MA0-700.json	-o 2HDM_MZp-1700_MA0-700	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2000_MA0-700.json	-o 2HDM_MZp-2000_MA0-700	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2500_MA0-700.json	-o 2HDM_MZp-2500_MA0-700	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1000_MA0-800.json	-o 2HDM_MZp-1000_MA0-800	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1200_MA0-800.json	-o 2HDM_MZp-1200_MA0-800	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1400_MA0-800.json	-o 2HDM_MZp-1400_MA0-800	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-1700_MA0-800.json	-o 2HDM_MZp-1700_MA0-800	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2000_MA0-800.json	-o 2HDM_MZp-2000_MA0-800	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/2HDM_MZp-2500_MA0-800.json	-o 2HDM_MZp-2500_MA0-800	-d lists_25ns_v80X_v2

python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-1000_MChi-1000_13TeV.json	-o ZpBaryonic_MZp-1000_MChi-1000_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-1000_MChi-150_13TeV.json	-o ZpBaryonic_MZp-1000_MChi-150_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-1000_MChi-1_13TeV.json 		-o ZpBaryonic_MZp-1000_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-500_MChi-500_13TeV.json		-o ZpBaryonic_MZp-500_MChi-500_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-500_MChi-150_13TeV.json		-o ZpBaryonic_MZp-500_MChi-150_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-500_MChi-1_13TeV.json		-o ZpBaryonic_MZp-500_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-100_MChi-10_13TeV.json		-o ZpBaryonic_MZp-100_MChi-10_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10_MChi-10_13TeV.json		-o ZpBaryonic_MZp-10_MChi-10_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10000_MChi-1000_13TeV.json	-o ZpBaryonic_MZp-10000_MChi-1000_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10000_MChi-500_13TeV.json	-o ZpBaryonic_MZp-10000_MChi-500_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10000_MChi-50_13TeV.json	-o ZpBaryonic_MZp-10000_MChi-50_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10000_MChi-150_13TeV.json  	-o ZpBaryonic_MZp-10000_MChi-150_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10000_MChi-10_13TeV.json   	-o ZpBaryonic_MZp-10000_MChi-10_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10000_MChi-1_13TeV.json    	-o ZpBaryonic_MZp-10000_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-100_MChi-1_13TeV.json      	-o ZpBaryonic_MZp-100_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10_MChi-1000_13TeV.json    	-o ZpBaryonic_MZp-10_MChi-1000_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10_MChi-1_13TeV.json       	-o ZpBaryonic_MZp-10_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10_MChi-50_13TeV.json      	-o ZpBaryonic_MZp-10_MChi-50_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10_MChi-150_13TeV.json       	-o ZpBaryonic_MZp-10_MChi-150_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-10_MChi-500_13TeV.json      	-o ZpBaryonic_MZp-10_MChi-500_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-15_MChi-10_13TeV.json      	-o ZpBaryonic_MZp-15_MChi-10_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-1995_MChi-1000_13TeV.json  	-o ZpBaryonic_MZp-1995_MChi-1000_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-2000_MChi-1_13TeV.json     	-o ZpBaryonic_MZp-2000_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-2000_MChi-500_13TeV.json   	-o ZpBaryonic_MZp-2000_MChi-500_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-200_MChi-150_13TeV.json    	-o ZpBaryonic_MZp-200_MChi-150_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-200_MChi-50_13TeV.json     	-o ZpBaryonic_MZp-200_MChi-50_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-200_MChi-1_13TeV.json      	-o ZpBaryonic_MZp-200_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-20_MChi-1_13TeV.json       	-o ZpBaryonic_MZp-20_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-295_MChi-150_13TeV.json    	-o ZpBaryonic_MZp-295_MChi-150_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-300_MChi-50_13TeV.json     	-o ZpBaryonic_MZp-300_MChi-50_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-300_MChi-1_13TeV.json     	-o ZpBaryonic_MZp-300_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-50_MChi-50_13TeV.json      	-o ZpBaryonic_MZp-50_MChi-50_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-50_MChi-10_13TeV.json      	-o ZpBaryonic_MZp-50_MChi-10_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-50_MChi-1_13TeV.json       	-o ZpBaryonic_MZp-50_MChi-1_13TeV	-d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-95_MChi-50_13TeV.json           -o ZpBaryonic_MZp-95_MChi-50_13TeV      -d lists_25ns_v80X_v2
python extractFilesAndWeight.py -i lists_25ns_v80X_v2/MC/ZpBaryonic_MZp-995_MChi-500_13TeV.json    	-o ZpBaryonic_MZp-995_MChi-500_13TeV	-d lists_25ns_v80X_v2

