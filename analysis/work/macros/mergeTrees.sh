#! /bin/sh 
# this scripts creates a merged root file in the self-created merged
maindir="/afs/cern.ch/work/m/mzientek/private/25ns_v80X_v3/"
mkdir -p $maindir

### 80X
 
#hadd ${maindir}DoubleEG.root  			 ${maindir}job_2016/DoubleEG/DoubleEG*.root
hadd ${maindir}Run2016B.root  			 ${maindir}job_2017119_16/Run2016B/Run2016*.root
hadd ${maindir}Run2016C.root  			 ${maindir}job_2017119_15/Run2016C/Run2016*.root
hadd ${maindir}Run2016D.root  			 ${maindir}job_2017119_15/Run2016D/Run2016*.root
hadd ${maindir}Run2016E.root  			 ${maindir}job_2017119_15/Run2016E/Run2016*.root
hadd ${maindir}Run2016F.root  			 ${maindir}job_2017119_15/Run2016F/Run2016*.root
hadd ${maindir}Run2016G.root  			 ${maindir}job_2017119_16/Run2016G/Run2016*.root
hadd ${maindir}Run2016H.root  			 ${maindir}job_2017119_15/Run2016H/Run2016*.root

hadd ${maindir}VHToGG.root			 ${maindir}job_2017119_16/VHToGG/VHToGG*.root
hadd ${maindir}VBFHToGG.root			 ${maindir}job_2017119_16/VBFHToGG/VBFHToGG*.root
hadd ${maindir}ttHJetToGG.root			 ${maindir}job_2017119_23/ttHJetToGG/ttHJetToGG*.root
hadd ${maindir}GluGluHToGG.root			 ${maindir}job_2017119_16/GluGluHToGG/GluGluHToGG*.root

hadd ${maindir}2HDM_mZP600_mA0300.root		 ${maindir}job_2017119_17/2HDM_MZp-600_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP800_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-800_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1000_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-1000_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1200_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-1200_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1400_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-1400_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1700_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-1700_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP2000_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-2000_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP2500_mA0300.root		 ${maindir}job_2017119_16/2HDM_MZp-2500_MA0-300/2HDM_MZp*.root

hadd ${maindir}2HDM_mZP600_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-600_MA0-400/2HDM_MZp-600*.root
#hadd ${maindir}2HDM_mZP800_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-800_MA0-400/2HDM_MZp-800*.root
hadd ${maindir}2HDM_mZP1000_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-1000_MA0-400/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-1200_MA0-400/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-1400_MA0-400/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-1700_MA0-400/2HDM_MZp-1700*.root
hadd ${maindir}2HDM_mZP2000_mA0400.root		 ${maindir}job_2017119_16/2HDM_MZp-2000_MA0-400/2HDM_MZp-2000*.root
#hadd ${maindir}2HDM_mZP2500_mA0400.root	 ${maindir}job_2017119_16/2HDM_MZp-2500_MA0-400/2HDM_MZp-2500*.root

#hadd ${maindir}2HDM_mZP600_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-600_MA0-500/2HDM_MZp-600*.root
hadd ${maindir}2HDM_mZP800_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-800_MA0-500/2HDM_MZp-800*.root
#hadd ${maindir}2HDM_mZP1000_mA0500.root	 ${maindir}job_2017119_16/2HDM_MZp-1000_MA0-500/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-1200_MA0-500/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-1400_MA0-500/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-1700_MA0-500/2HDM_MZp-1700*.root
hadd ${maindir}2HDM_mZP2000_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-2000_MA0-500/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0500.root		 ${maindir}job_2017119_16/2HDM_MZp-2500_MA0-500/2HDM_MZp-2500*.root

#hadd ${maindir}2HDM_mZP1000_mA0600.root	 ${maindir}job_2017119_16/2HDM_MZp-1000_MA0-600/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0600.root		 ${maindir}job_2017119_16/2HDM_MZp-1200_MA0-600/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0600.root		 ${maindir}job_2017119_16/2HDM_MZp-1400_MA0-600/2HDM_MZp-1400*.root
#hadd ${maindir}2HDM_mZP1700_mA0600.root	 ${maindir}job_2017119_16/2HDM_MZp-1700_MA0-600/2HDM_MZp-1700*.root
#hadd ${maindir}2HDM_mZP2000_mA0600.root	 ${maindir}job_2017119_16/2HDM_MZp-2000_MA0-600/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0600.root		 ${maindir}job_2017120_12/2HDM_MZp-2500_MA0-600/2HDM_MZp-2500*.root

hadd ${maindir}2HDM_mZP1000_mA0700.root		 ${maindir}job_2017119_16/2HDM_MZp-1000_MA0-700/2HDM_MZp-1000*.root
#hadd ${maindir}2HDM_mZP1200_mA0700.root	 ${maindir}job_2017119_16/2HDM_MZp-1200_MA0-700/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0700.root		 ${maindir}job_2017119_16/2HDM_MZp-1400_MA0-700/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0700.root		 ${maindir}job_2017119_16/2HDM_MZp-1700_MA0-700/2HDM_MZp-1700*.root
#hadd ${maindir}2HDM_mZP2000_mA0700.root	 ${maindir}job_2017119_16/2HDM_MZp-2000_MA0-700/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0700.root		 ${maindir}job_2017119_16/2HDM_MZp-2500_MA0-700/2HDM_MZp-2500*.root

#hadd ${maindir}2HDM_mZP1000_mA0800.root	 ${maindir}job_2017119_16/2HDM_MZp-1000_MA0-800/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0800.root		 ${maindir}job_2017119_16/2HDM_MZp-1200_MA0-800/2HDM_MZp-1200*.root
#hadd ${maindir}2HDM_mZP1400_mA0800.root	 ${maindir}job_2017119_16/2HDM_MZp-1400_MA0-800/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0800.root		 ${maindir}job_2017119_16/2HDM_MZp-1700_MA0-800/2HDM_MZp-1700*.root
hadd ${maindir}2HDM_mZP2000_mA0800.root		 ${maindir}job_2017119_16/2HDM_MZp-2000_MA0-800/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0800.root		 ${maindir}job_2017119_16/2HDM_MZp-2500_MA0-800/2HDM_MZp-2500*.root

hadd ${maindir}BaryonicZp_mZP1000_mChi1000.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-1000_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP1000_mChi150.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-1000_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP1000_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-1000_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP500_mChi500.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-500_MChi-500_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP500_mChi150.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-500_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP500_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-500_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP100_mChi10.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-100_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi10.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi1000.root ${maindir}job_2017120_11/ZpBaryonic_MZp-10000_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi10.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10000_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10000_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi150.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10000_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi500.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10000_MChi-500_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi50.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10000_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP100_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-100_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi1000.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi50.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-10_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP15_mChi10.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-15_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP1995_mChi1000.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-1995_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP2000_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-2000_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP2000_mChi500.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-2000_MChi-500_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP200_mChi150.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-200_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP200_mChi50.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-200_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP200_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-200_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP20_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-20_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP295_mChi150.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-295_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP300_mChi50.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-300_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP50_mChi10.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-50_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP50_mChi1.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-50_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP995_mChi500.root	 ${maindir}job_2017120_11/ZpBaryonic_MZp-995_MChi-500_13TeV/ZpBaryonic_MZp*.root

hadd ${maindir}DiPhoton.root			 ${maindir}job_2017119_16/DiPhotonJetsBox_MGG-80toInf/DiPhoton*.root
#hadd ${maindir}DiPhoton.root			 ${maindir}job_2017119_17/DiPhotonJets_MGG-80toInf/DiPhoton*.root
hadd ${maindir}DYJetsToLL.root			 ${maindir}job_2017119_16/DYJetsToLL/DYJetsToLL*.root
hadd ${maindir}WGToLNuG.root			 ${maindir}job_2017119_17/WGToLNuG/WGToLNuG*.root
hadd ${maindir}WJetsToLNu.root			 ${maindir}job_2017119_17/WJetsToLNu/WJetsToLNu*.root
hadd ${maindir}WZTo2L2Q.root			 ${maindir}job_2017119_17/WZTo2L2Q/WZTo2L2Q*.root
hadd ${maindir}ZGTo2LG.root			 ${maindir}job_2017119_17/ZGTo2LG/ZGTo2LG*.root
hadd ${maindir}ZZTo2L2Q.root			 ${maindir}job_2017119_17/ZZTo2L2Q/ZZTo2L2Q*.root
hadd ${maindir}TGJets.root			 ${maindir}job_2017119_17/TGJets/TGJets*.root
hadd ${maindir}TTJets.root			 ${maindir}job_2017119_17/TTJets/TTJets*.root
hadd ${maindir}TTGJets.root			 ${maindir}job_2017119_17/TTGJets/TTGJets*.root
hadd ${maindir}TTGG_0Jets.root			 ${maindir}job_2017119_17/TTGG_0Jets/TTGG_0Jets*.root
hadd ${maindir}GJet_Pt-20to40.root		 ${maindir}job_2017119_17/GJet_Pt-20to40/GJet_Pt-20to40*.root
hadd ${maindir}GJet_Pt-40toInf.root		 ${maindir}job_2017119_17/GJet_Pt-40toInf/GJet_Pt-40toInf*.root
#hadd ${maindir}GJet_Pt-20toInf.root		 ${maindir}job_2017119_17/GJet_Pt-20toInf/GJet_Pt-20toInf*.root
#hadd ${maindir}QCD_Pt-30to40.root		 ${maindir}job_2017119_17/QCD_Pt-30to40/QCD_Pt-30to40*.root
hadd ${maindir}QCD_Pt-30toInf.root		 ${maindir}job_2017119_17/QCD_Pt-30toInf/QCD_Pt-30toInf*.root
hadd ${maindir}QCD_Pt-40toInf.root		 ${maindir}job_2017119_17/QCD_Pt-40toInf/QCD_Pt-40toInf*.root
