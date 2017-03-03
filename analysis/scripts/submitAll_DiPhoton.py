
# -------------------------------------------------------------------------------

# Scripts to send analyzer to batch jobs

# -------------------------------------------------------------------------------
# -------------------------------------------------------------------------------

# usage: %prog [opts] --cfg cmssw.py dataset doPUreweighting(0/1) sampleIndex PUweightsFile x-section(in pb) kFactor

# Backgrounds: sampleID>0 && sampleID<100
# Signals:     sampleID>100
# Data:        sampleID>10000

##--------------------------------------------------------------------------------
## 2016 Samples
##--------------------------------------------------------------------------------

  ##--------------------------------------------------------------------------------
  ## DATA
  ##--------------------------------------------------------------------------------

#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016B         		0 10002 pippo 1 1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016C         		0 10003 pippo 1 1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016D      	  		0 10004 pippo 1 1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016E         		0 10005 pippo 1 1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016F         		0 10006 pippo 1 1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016G         		0 10007 pippo 1 1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Run2016H         		0 10008 pippo 1 1

  ##--------------------------------------------------------------------------------
  ## SM HIGGS BKGS (use HLT2 instead of HLT) 
  ##--------------------------------------------------------------------------------

#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py GluGluHToGG	 		1 10  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.1001978	1 # POWHEG 
##./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py GluGluHToGG	 		1 10  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.1102766	1 # AMCATNLO
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py VBFHToGG				1 11  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.00858514	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py VHToGG				1 12  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.00512339 	1 
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ttHToGG				1 13  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.001151117	1

  ##--------------------------------------------------------------------------------
  ## NON-RESONANT BKGS 
  ##--------------------------------------------------------------------------------

#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py DYJetsToLL 			1 14  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 6025.2	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py GJet_Pt-20toInf 	      		1 19  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 3216.0	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py GJet_Pt-20to40 	      		1 18  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 220.0		1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py GJet_Pt-40toInf			1 20  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 850.8		1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py DiPhotonJetsBox_M40_80		1 16  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 303.2		1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py DiPhotonJetsBox_MGG-80toInf 	1 17  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 84.0		1 # SHERPA
##./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py DiPhotonJets_MGG-80toInf 	1 17  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 135.1		1 # AMCATNLO
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py QCD_Pt-30to40 			1 15  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 22110.0	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py QCD_Pt-40toInf 			1 22  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 113400.0	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py QCD_Pt-30toInf 			1 21  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 260500.0	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py TTJets 				1 26  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 665.0  	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py TTGJets 				1 25  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 3.819		1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py TTGG_0Jets 			1 24  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.01731	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py TGJets 				1 23  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 2.967		1

#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py WGToLNuG				1 28  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 489.0		1 # AMCATNLO
##./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py WGToLNuG			1 28  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 405.271	1 # MADGRAPH
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py WJetsToLNu 			1 29  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 61526.7 	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py WZTo2L2Q				1 31  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 5.595 	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZGTo2LG				1 32  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 117.864	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZGTo2NuG				1 32  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 28.05 	1
#./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZZTo2L2Q				1 33  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 3.22		1
##./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py TT_				1 27  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root xxxxxx 	1
##./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py WW_ 				1 30  /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root xxxxxx 	1

  ##--------------------------------------------------------------------------------
  ## SIGNAL (xsec*BR = 1pb*0.002)
  ##--------------------------------------------------------------------------------

./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-600_MA0-300 			1 140 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-800_MA0-300 			1 141 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-300 			1 142 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-300 			1 143 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-300 			1 144 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-300 			1 145 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-300 			1 146 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-300 			1 147 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-600_MA0-400 			1 148 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-800_MA0-400 			1 149 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-400 			1 150 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-400 			1 151 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-400 			1 152 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-400 			1 153 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-400 			1 154 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-400 			1 155 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-800_MA0-500 			1 156 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-500 			1 157 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-500 			1 158 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-500 			1 159 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-500 			1 160 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-500 			1 161 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-500 			1 162 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-800_MA0-600 			1 139 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-600 			1 163 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-600 			1 164 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-600 			1 165 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-600 			1 166 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-600 			1 167 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-600 			1 168 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-700 			1 169 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-700 			1 170 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-700 			1 171 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-700 			1 172 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-700 			1 173 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-700 			1 174 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1000_MA0-800 			1 175 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1200_MA0-800 			1 176 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1400_MA0-800 			1 177 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-1700_MA0-800 			1 178 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2000_MA0-800 			1 179 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py 2HDM_MZp-2500_MA0-800 			1 180 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 

./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-1000_MChi-1000_13TeV	1 181 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-1000_MChi-150_13TeV	1 182 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-1000_MChi-1_13TeV		1 183 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-500_MChi-500_13TeV		1 184 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-500_MChi-150_13TeV		1 185 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-500_MChi-1_13TeV		1 186 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-100_MChi-10_13TeV		1 187 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-10_13TeV		1 188 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-1000_13TeV	1 189 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-500_13TeV	1 190 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-50_13TeV	1 191 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-150_13TeV	1 192 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-10_13TeV	1 193 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10000_MChi-1_13TeV		1 194 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-100_MChi-1_13TeV		1 195 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-1000_13TeV		1 196 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-1_13TeV		1 197 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-10_MChi-50_13TeV		1 198 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-15_MChi-10_13TeV		1 199 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-1995_MChi-1000_13TeV	1 200 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-2000_MChi-1_13TeV		1 201 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-2000_MChi-500_13TeV	1 202 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-200_MChi-150_13TeV		1 203 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-200_MChi-50_13TeV		1 204 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-200_MChi-1_13TeV		1 205 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-20_MChi-1_13TeV		1 206 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-295_MChi-150_13TeV    	1 207 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-300_MChi-50_13TeV		1 208 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-50_MChi-10_13TeV		1 209 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-50_MChi-1_13TeV		1 210 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py ZpBaryonic_MZp-995_MChi-500_13TeV		1 211 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002 1 

./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10000_MChi-1000_13TeV		1 212 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10000_MChi-10_13TeV  		1 213 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10000_MChi-150_13TeV 		1 214 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1   
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10000_MChi-1_13TeV   		1 215 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10000_MChi-500_13TeV 		1 216 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1   
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10000_MChi-50_13TeV  		1 217 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-1000_MChi-1000_13TeV 		1 218 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1   
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-1000_MChi-150_13TeV  		1 219 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-1000_MChi-1_13TeV    		1 220 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-100_MChi-10_13TeV    		1 221 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-100_MChi-1_13TeV     		1 222 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10_MChi-1000_13TeV   		1 223 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10_MChi-10_13TeV     		1 224 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10_MChi-150_13TeV    		1 225 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10_MChi-1_13TeV	     	1 226 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10_MChi-500_13TeV    		1 227 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-10_MChi-50_13TeV     		1 228 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-15_MChi-10_13TeV     		1 229 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-200_MChi-150_13TeV   		1 230 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-200_MChi-1_13TeV     		1 231 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-200_MChi-50_13TeV    		1 232 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-20_MChi-1_13TeV	     	1 233 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-295_MChi-150_13TeV   		1 234 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-300_MChi-1_13TeV     		1 235 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-300_MChi-50_13TeV    		1 236 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-500_MChi-150_13TeV   		1 237 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-500_MChi-1_13TeV     		1 238 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-500_MChi-500_13TeV   		1 239 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-50_MChi-10_13TeV     		1 240 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-50_MChi-1_13TeV	     	1 241 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-50_MChi-50_13TeV     		1 242 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-95_MChi-50_13TeV     		1 243 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1
./submitBatchDiPho.py --cfg moriond17diPhoAnaBATCH.py Scalar_MZp-995_MChi-500_13TeV   		1 244 /afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v1.root 0.002	1 


