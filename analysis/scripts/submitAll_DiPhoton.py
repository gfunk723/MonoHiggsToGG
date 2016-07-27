#
# usage: %prog [opts] --cfg cmssw.py dataset doPUreweighting(0/1) sampleIndex PUweightsFile x-section(in pb) kFactor
#
# Backgrounds: sampleID>0 && sampleID<100
# Signals:     sampleID>100
# Data:        sampleID=0


## 25ns samples from FLASHgg
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DoubleEG         		0 10001 pippo 1 1

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-100To200		1 30  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 280.5 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-200To400		1 31  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 77.7 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-400To600		1 32  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 10.71 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-600To800		1 33  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 2.562 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-800To1200		1 34  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 1.183 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-1200To2500	1 35  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.286 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-2500ToInf		1 36  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.006976 	1 

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZZTo2L2Nu			1 28  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.564     1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTGG_0Jets			1 27  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.017     1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTGJets 			1 23  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 3.697     1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TGJets			1 24  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 2.967     1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZGTo2LG			1 25  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 117.864   1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py WGToLNuG			1 26  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 405.271   1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DiPhoton			1 15  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 135.1     1 # <- amcat@nlo # sherpa = 84.0      1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-20to40     	1  1  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 218.6108  1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-40toInf    	1  2  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 863.1088  1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-30to40      	1  3  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 24300     1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-40toInf     	1  5  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 108240    1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-30toInf     	1  4  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 259296    1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DYJetsToLL			1 12  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 6025.2    1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GluGluHToGG		1 10  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.0952946   1 # 41.98  pb xsec
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py VH				1 11  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.002050718 1 # 0.9034 pb xsec
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ttHJetToGG			1 21  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001132049 1 # 0.4987 pb xsec
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py VBFHToGG			1 22  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.00890975  1 # 3.925  pb xsec


./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP600		1 100 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00009338  1 #46.69fb xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP800		1 101 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00010348  1 #51.74fb xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1000		1 102 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00008394  1 #41.97fb xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1200		1 103 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00006352  1 #31.76fb xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1400		1 104 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00004712  1 #23.56fb xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1700		1 105 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00003020  1 #15.10fb xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP2000		1 106 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP2500		1 107 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00000972  1 #4.860fb xsec * 0.002br

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-600 		1 108 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #xsec * 0.002br
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800 		1 109 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #xsec * 0.002br

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800_MA0-500 	1 110 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-400 	1 111 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-500 	1 112 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-600 	1 113 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-700 	1 114 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-800 	1 115 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-400 	1 116 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-500 	1 117 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-600 	1 118 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-700 	1 119 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-800 	1 120 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-400 	1 121 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-500 	1 122 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-600 	1 123 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-700 	1 124 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-800 	1 125 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-400 	1 126 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-500 	1 127 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-600 	1 128 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-700 	1 129 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-800 	1 130 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-400 	1 131 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-500 	1 132 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-600 	1 133 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-700 	1 134 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-800 	1 135 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-500 	1 136 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-600 	1 137 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-700 	1 138 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-800 	1 139 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 






