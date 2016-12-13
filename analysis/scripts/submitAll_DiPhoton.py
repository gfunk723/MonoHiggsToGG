# -------------------------------------------------------------------------------
# -------------------------------------------------------------------------------

# Scripts to send analyzer to batch jobs

# -------------------------------------------------------------------------------
# -------------------------------------------------------------------------------

# usage: %prog [opts] --cfg cmssw.py dataset doPUreweighting(0/1) sampleIndex PUweightsFile x-section(in pb) kFactor

# Backgrounds: sampleID>0 && sampleID<100
# Signals:     sampleID>100
# Data:        sampleID>10000

# -------------------------------------------------------------------------------
# 2016 Samples
# xsec for sig = 1pb*0.002 (H->gg BR)  
# -------------------------------------------------------------------------------

#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-600_MA0-300 			1 140 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800_MA0-300 			1 141 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-300 			1 142 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-300 			1 143 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-300 			1 144 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-300 			1 145 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-300 			1 146 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-300 			1 147 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-600_MA0-400 			1 148 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800_MA0-400 			1 149 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-400 			1 150 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-400 			1 151 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-400 			1 152 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-400 			1 153 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-400 			1 154 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-400 			1 155 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800_MA0-500 			1 156 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-500 			1 157 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-500 			1 158 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-500 			1 159 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-500 			1 160 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-500 			1 161 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-500 			1 162 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-600 			1 163 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-600 			1 164 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-600 			1 165 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-600 			1 166 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-600 			1 167 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-600 			1 168 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-700 			1 169 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-700 			1 170 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-700 			1 171 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-700 			1 172 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-700 			1 173 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-700 			1 174 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-800 			1 175 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-800 			1 176 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-800 			1 177 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-800 			1 178 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-800 			1 179 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-800 			1 180 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-1000_MChi-1000_13TeV 	1 181 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-1000_MChi-150_13TeV 	1 182 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-1000_MChi-1_13TeV	 	1 183 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-500_MChi-500_13TeV		1 184 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-500_MChi-150_13TeV	 	1 185 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-500_MChi-1_13TeV		1 186 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-100_MChi-10_13TeV	 	1 187 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-10_13TeV	 	1 188 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-1000_13TeV 	1 189 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-500_13TeV        1 190 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-50_13TeV   	1 191 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-150_13TeV        1 192 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-10_13TeV   	1 193 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-1_13TeV          1 194 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-100_MChi-1_13TeV      	1 195 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-1000_13TeV    	1 196 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-1_13TeV       	1 197 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-50_13TeV            1 198 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-15_MChi-10_13TeV      	1 199 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-1995_MChi-1000_13TeV        1 200 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-2000_MChi-1_13TeV     	1 201 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-2000_MChi-500_13TeV         1 202 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-200_MChi-150_13TeV    	1 203 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-200_MChi-50_13TeV     	1 204 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-200_MChi-1_13TeV      	1 205 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-20_MChi-1_13TeV             1 206 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-295_MChi-150_13TeV    	1 207 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-300_MChi-50_13TeV           1 208 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-50_MChi-10_13TeV      	1 209 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-50_MChi-1_13TeV             1 210 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZpBaryonic_MZp-995_MChi-500_13TeV    	1 211 /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002 	1 

## these use HLT2 instead of HLT
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GluGluHToGG	 			1 10  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.0952946	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py VBFHToGG					1 11  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.00890975	1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ttHJetToGG				1 13  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.001132049	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py VHToGG					1 12  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.002050718	1

./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DYJetsToLL 				1 14  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 6025.2	1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DYToLL					1 15  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root xxxxxx	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DiPhotonJetsBox_M40_80			1 16  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 299.3	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DiPhotonJetsBox_MGG-80toInf 		1 17  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 84.0	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DiPhotonJets_MGG-80toInf 			1 17  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 135.0	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-20to40 	      			1 18  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 218.6108	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-20toInf 	      			1 19  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 3329.475	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-40toInf				1 20  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 863.1088	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-30toInf 				1 21  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 259296	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-40toInf 				1 22  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 108240	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TGJets 					1 23  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 2.967	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTGG_0Jets 				1 24  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 0.017	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTGJets 					1 25  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 3.697	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTJets 					1 26  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 831.76  	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py WGToLNuG					1 28  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 405.271	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py WJetsToLNu 				1 29  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 61526.7 	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py WZTo2L2Q					1 31  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 5.595 	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZGTo2LG					1 32  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 117.864	1
./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZZTo2L2Q					1 33  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root 3.22	1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TT_					1 27  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root xxxxxx 	1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py WW_ 					1 30  /afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v1.root xxxxxx 	1

#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DoubleEG         		0 10001 pippo 1 1

#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016B         		0 10002 pippo 1 1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016C         		0 10003 pippo 1 1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016D        		0 10004 pippo 1 1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016E         		0 10005 pippo 1 1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016F         		0 10006 pippo 1 1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016G         		0 10007 pippo 1 1
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py Run2016H         		0 10008 pippo 1 1


# -------------------------------------------------------------------------------
# 2015 Samples 
# -------------------------------------------------------------------------------

##./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DoubleEG         		0 10001 pippo 1 1
#
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-100To200		1 30  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 280.5 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-200To400		1 31  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 77.7 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-400To600		1 32  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 10.71 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-600To800		1 33  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 2.562 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-800To1200		1 34  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 1.183 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-1200To2500	1 35  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.286 	1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZJets_HT-2500ToInf		1 36  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.006976 	1 
#
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZZTo2L2Nu			1 28  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.564     1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTGG_0Jets			1 27  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.017     1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TTGJets 			1 23  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 3.697     1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py TGJets			1 24  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 2.967     1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ZGTo2LG			1 25  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 117.864   1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py WGToLNuG			1 26  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 405.271   1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DiPhoton			1 15  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 135.1     1 # <- amcat@nlo # sherpa = 84.0      1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DiPhotonJetSherpa		1 16  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 84.0      1  
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-20to40     	1  1  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 218.6108  1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GJet_Pt-40toInf    	1  2  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 863.1088  1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-30to40      	1  3  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 24300     1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-40toInf     	1  5  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 108240    1 
##./submitBatchDiPho.py --cfg diPhoAnaBATCH.py QCD_Pt-30toInf     	1  4  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 259296    1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py DYJetsToLL			1 12  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 6025.2    1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py GluGluHToGG		1 10  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.0952946   1 # 41.98  pb xsec
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py VH				1 11  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.002050718 1 # 0.9034 pb xsec
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py ttHJetToGG			1 21  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001132049 1 # 0.4987 pb xsec
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py VBFHToGG			1 22  /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.00890975  1 # 3.925  pb xsec
#
#
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP600		1 100 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00009338  1 #46.69fb xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP800		1 101 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00010348  1 #51.74fb xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1000		1 102 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00008394  1 #41.97fb xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1200		1 103 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00006352  1 #31.76fb xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1400		1 104 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00004712  1 #23.56fb xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP1700		1 105 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00003020  1 #15.10fb xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP2000		1 106 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZP2500		1 107 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #0.00000972  1 #4.860fb xsec * 0.002br
#
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-600 		1 108 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #xsec * 0.002br
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800 		1 109 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 #xsec * 0.002br
#
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800_MA0-600 	1 140 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-600 	1 141 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-400 	1 142 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-800_MA0-500 	1 110 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-400 	1 111 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-500 	1 112 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-600 	1 113 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-700 	1 114 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-800 	1 115 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-400 	1 116 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-500 	1 117 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-600 	1 118 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-700 	1 119 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-800 	1 120 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-400 	1 121 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-500 	1 122 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-600 	1 123 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-700 	1 124 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-800 	1 125 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-400 	1 126 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-500 	1 127 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-600 	1 128 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-700 	1 129 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-800 	1 130 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-400 	1 131 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-500 	1 132 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-600 	1 133 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-700 	1 134 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-800 	1 135 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-500 	1 136 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-600 	1 137 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-700 	1 138 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 
#./submitBatchDiPho.py --cfg diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-800 	1 139 /afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root 0.001 1 






