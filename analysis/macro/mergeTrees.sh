#! /bin/sh 
# this scripts creates a merged root file in the self-created merged
maindir="/afs/cern.ch/work/m/mzientek/private/25ns_v80X_v2/"

mkdir -p data/25ns_v80X_v2/
mkdir -p $maindir

### 80X
 
#hadd ${maindir}DoubleEG.root  			 ${maindir}job_2016/DoubleEG/DoubleEG*.root
hadd ${maindir}Run2016B.root  			 ${maindir}job_20161213_17/Run2016B/Run2016*.root
hadd ${maindir}Run2016C.root  			 ${maindir}job_20161213_17/Run2016C/Run2016*.root
hadd ${maindir}Run2016D.root  			 ${maindir}job_20161213_18/Run2016D/Run2016*.root
hadd ${maindir}Run2016E.root  			 ${maindir}job_20161213_18/Run2016E/Run2016*.root
hadd ${maindir}Run2016F.root  			 ${maindir}job_20161213_18/Run2016F/Run2016*.root
hadd ${maindir}Run2016G.root  			 ${maindir}job_20161213_21/Run2016G/Run2016*.root
hadd ${maindir}Run2016H.root  			 ${maindir}job_20161213_16/Run2016H/Run2016*.root

hadd ${maindir}VHToGG.root			 ${maindir}job_20161213_15/VHToGG/VHToGG*.root
hadd ${maindir}VBFHToGG.root			 ${maindir}job_20161213_16/VBFHToGG/VBFHToGG*.root
hadd ${maindir}ttHJetToGG.root			 ${maindir}job_20161214_12/ttHJetToGG/ttHJetToGG*.root
hadd ${maindir}GluGluHToGG.root			 ${maindir}job_20161213_16/GluGluHToGG/GluGluHToGG*.root

#hadd ${maindir}2HDM_mZP600_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-600_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP800_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-800_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1000_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-1000_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1200_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-1200_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1400_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-1400_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP1700_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-1700_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP2000_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-2000_MA0-300/2HDM_MZp*.root
hadd ${maindir}2HDM_mZP2500_mA0300.root		 ${maindir}job_20161213_15/2HDM_MZp-2500_MA0-300/2HDM_MZp*.root

hadd ${maindir}2HDM_mZP600_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-600_MA0-400/2HDM_MZp-600*.root
#hadd ${maindir}2HDM_mZP800_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-800_MA0-400/2HDM_MZp-800*.root
hadd ${maindir}2HDM_mZP1000_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-1000_MA0-400/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-1200_MA0-400/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-1400_MA0-400/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-1700_MA0-400/2HDM_MZp-1700*.root
hadd ${maindir}2HDM_mZP2000_mA0400.root		 ${maindir}job_20161213_15/2HDM_MZp-2000_MA0-400/2HDM_MZp-2000*.root
#hadd ${maindir}2HDM_mZP2500_mA0400.root	 ${maindir}job_20161213_15/2HDM_MZp-2500_MA0-400/2HDM_MZp-2500*.root

#hadd ${maindir}2HDM_mZP600_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-600_MA0-500/2HDM_MZp-600*.root
hadd ${maindir}2HDM_mZP800_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-800_MA0-500/2HDM_MZp-800*.root
#hadd ${maindir}2HDM_mZP1000_mA0500.root	 ${maindir}job_20161213_15/2HDM_MZp-1000_MA0-500/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-1200_MA0-500/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-1400_MA0-500/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-1700_MA0-500/2HDM_MZp-1700*.root
hadd ${maindir}2HDM_mZP2000_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-2000_MA0-500/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0500.root		 ${maindir}job_20161213_15/2HDM_MZp-2500_MA0-500/2HDM_MZp-2500*.root

#hadd ${maindir}2HDM_mZP1000_mA0600.root	 ${maindir}job_20161213_15/2HDM_MZp-1000_MA0-600/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0600.root		 ${maindir}job_20161213_15/2HDM_MZp-1200_MA0-600/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0600.root		 ${maindir}job_20161213_15/2HDM_MZp-1400_MA0-600/2HDM_MZp-1400*.root
#hadd ${maindir}2HDM_mZP1700_mA0600.root	 ${maindir}job_20161213_15/2HDM_MZp-1700_MA0-600/2HDM_MZp-1700*.root
#hadd ${maindir}2HDM_mZP2000_mA0600.root	 ${maindir}job_20161213_15/2HDM_MZp-2000_MA0-600/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0600.root		 ${maindir}job_20161213_15/2HDM_MZp-2500_MA0-600/2HDM_MZp-2500*.root

hadd ${maindir}2HDM_mZP1000_mA0700.root		 ${maindir}job_20161213_15/2HDM_MZp-1000_MA0-700/2HDM_MZp-1000*.root
#hadd ${maindir}2HDM_mZP1200_mA0700.root	 ${maindir}job_20161213_15/2HDM_MZp-1200_MA0-700/2HDM_MZp-1200*.root
hadd ${maindir}2HDM_mZP1400_mA0700.root		 ${maindir}job_20161213_15/2HDM_MZp-1400_MA0-700/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0700.root		 ${maindir}job_20161213_15/2HDM_MZp-1700_MA0-700/2HDM_MZp-1700*.root
#hadd ${maindir}2HDM_mZP2000_mA0700.root	 ${maindir}job_20161213_15/2HDM_MZp-2000_MA0-700/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0700.root		 ${maindir}job_20161213_15/2HDM_MZp-2500_MA0-700/2HDM_MZp-2500*.root

#hadd ${maindir}2HDM_mZP1000_mA0800.root	 ${maindir}job_20161213_15/2HDM_MZp-1000_MA0-800/2HDM_MZp-1000*.root
hadd ${maindir}2HDM_mZP1200_mA0800.root		 ${maindir}job_20161213_15/2HDM_MZp-1200_MA0-800/2HDM_MZp-1200*.root
#hadd ${maindir}2HDM_mZP1400_mA0800.root	 ${maindir}job_20161213_15/2HDM_MZp-1400_MA0-800/2HDM_MZp-1400*.root
hadd ${maindir}2HDM_mZP1700_mA0800.root		 ${maindir}job_20161213_15/2HDM_MZp-1700_MA0-800/2HDM_MZp-1700*.root
hadd ${maindir}2HDM_mZP2000_mA0800.root		 ${maindir}job_20161213_15/2HDM_MZp-2000_MA0-800/2HDM_MZp-2000*.root
hadd ${maindir}2HDM_mZP2500_mA0800.root		 ${maindir}job_20161213_15/2HDM_MZp-2500_MA0-800/2HDM_MZp-2500*.root

hadd ${maindir}BaryonicZp_mZP1000_mChi1000.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-1000_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP1000_mChi150.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-1000_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP1000_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-1000_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP500_mChi500.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-500_MChi-500_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP500_mChi150.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-500_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP500_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-500_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP100_mChi10.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-100_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi10.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10_MChi-10_13TeV/ZpBaryonic_MZp*.root

hadd ${maindir}BaryonicZp_mZP10000_mChi1000.root ${maindir}job_20161213_15/ZpBaryonic_MZp-10000_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi10.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10000_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10000_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi150.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10000_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi500.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10000_MChi-500_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10000_mChi50.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10000_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP100_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-100_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi1000.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP10_mChi50.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-10_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP15_mChi10.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-15_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP1995_mChi1000.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-1995_MChi-1000_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP2000_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-2000_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP2000_mChi500.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-2000_MChi-500_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP200_mChi150.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-200_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP200_mChi50.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-200_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP200_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-200_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP20_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-20_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP295_mChi150.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-295_MChi-150_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP300_mChi50.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-300_MChi-50_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP50_mChi10.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-50_MChi-10_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP50_mChi1.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-50_MChi-1_13TeV/ZpBaryonic_MZp*.root
hadd ${maindir}BaryonicZp_mZP995_mChi500.root	 ${maindir}job_20161213_15/ZpBaryonic_MZp-995_MChi-500_13TeV/ZpBaryonic_MZp*.root

hadd ${maindir}DiPhoton.root			 ${maindir}job_20161213_15/DiPhotonJetsBox_MGG-80toInf/DiPhoton*.root
#hadd ${maindir}DiPhoton.root			 ${maindir}job_20161213_15/DiPhotonJets_MGG-80toInf/DiPhoton*.root
hadd ${maindir}DYJetsToLL.root			 ${maindir}job_20161213_15/DYJetsToLL/DYJetsToLL*.root
hadd ${maindir}WGToLNuG.root			 ${maindir}job_20161213_15/WGToLNuG/WGToLNuG*.root
hadd ${maindir}WJetsToLNu.root			 ${maindir}job_20161213_15/WJetsToLNu/WJetsToLNu*.root
hadd ${maindir}WZTo2L2Q.root			 ${maindir}job_20161213_15/WZTo2L2Q/WZTo2L2Q*.root
hadd ${maindir}ZGTo2LG.root			 ${maindir}job_20161213_16/ZGTo2LG/ZGTo2LG*.root
hadd ${maindir}ZZTo2L2Q.root			 ${maindir}job_20161213_16/ZZTo2L2Q/ZZTo2L2Q*.root
hadd ${maindir}TGJets.root			 ${maindir}job_20161213_15/TGJets/TGJets*.root
hadd ${maindir}TTJets.root			 ${maindir}job_20161213_15/TTJets/TTJets*.root
hadd ${maindir}TTGJets.root			 ${maindir}job_20161213_15/TTGJets/TTGJets*.root
hadd ${maindir}TTGG_0Jets.root			 ${maindir}job_20161213_15/TTGG_0Jets/TTGG_0Jets*.root
hadd ${maindir}GJet_Pt-20to40.root		 ${maindir}job_20161213_15/GJet_Pt-20to40/GJet_Pt-20to40*.root
hadd ${maindir}GJet_Pt-40toInf.root		 ${maindir}job_20161213_15/GJet_Pt-40toInf/GJet_Pt-40toInf*.root
hadd ${maindir}GJet_Pt-20toInf.root		 ${maindir}job_20161213_15/GJet_Pt-20toInf/GJet_Pt-20toInf*.root
#hadd ${maindir}QCD_Pt-30to40.root		 ${maindir}job_20161213_15/QCD_Pt-30to40/QCD_Pt-30to40*.root
hadd ${maindir}QCD_Pt-30toInf.root		 ${maindir}job_20161213_15/QCD_Pt-30toInf/QCD_Pt-30toInf*.root
hadd ${maindir}QCD_Pt-40toInf.root		 ${maindir}job_20161213_15/QCD_Pt-40toInf/QCD_Pt-40toInf*.root







### 76X 

#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/DiPhoton.root			../../output/job_201643_15/DiPhoton/DiPhoton*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/GJet_Pt-20to40.root		../../output/job_201643_15/GJet_Pt-20to40/GJet_Pt-20to40*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/GJet_Pt-40toInf.root		../../output/job_201643_15/GJet_Pt-40toInf/GJet_Pt-40toInf*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/QCD_Pt-30to40.root		../../output/job_201643_15/QCD_Pt-30to40/QCD_Pt-30to40*.root
##hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/QCD_Pt-30toInf.root		../../output/job_201643_15/QCD_Pt-30toInf/QCD_Pt-30toInf*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/QCD_Pt-40toInf.root		../../output/job_201643_15/QCD_Pt-40toInf/QCD_Pt-40toInf*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/GluGluHToGG.root			../../output/job_201643_15/GluGluHToGG/GluGluHToGG*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/VH.root				../../output/job_201643_15/VH/VH*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/DYJetsToLL.root			../../output/job_201643_15/DYJetsToLL/DYJetsToLL*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ttHJetToGG.root			../../output/job_201643_15/ttHJetToGG/ttHJetToGG*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/VBFHToGG.root			../../output/job_201643_15/VBFHToGG/VBFHToGG*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/WGToLNuG.root			../../output/job_201643_15/WGToLNuG/WGToLNuG*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZGTo2LG.root			../../output/job_201643_15/ZGTo2LG/ZGTo2LG*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZZTo2L2Nu.root			../../output/job_201643_15/ZZTo2L2Nu/ZZTo2L2Nu*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/TGJets.root			../../output/job_201643_15/TGJets/TGJets*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/TTGJets.root			../../output/job_201643_15/TTGJets/TTGJets*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/TTGG_0Jets.root			../../output/job_201643_15/TTGG_0Jets/TTGG_0Jets*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/DiPhotonJetsSherpa.root		../../output/job_2016727_17/DiPhotonJetSherpa/DiPhoton*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-100To200.root		../../output/job_2016727_10/ZJets_HT-100To200/ZJets_HT-100To200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-200To400.root		../../output/job_2016727_10/ZJets_HT-200To400/ZJets_HT-200To400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-400To600.root		../../output/job_2016727_10/ZJets_HT-400To600/ZJets_HT-400To600*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-600To800.root		../../output/job_2016727_10/ZJets_HT-600To800/ZJets_HT-600To800*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-800To1200.root		../../output/job_2016727_10/ZJets_HT-800To1200/ZJets_HT-800To1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-1200To2500.root		../../output/job_2016727_10/ZJets_HT-1200To2500/ZJets_HT-1200To2500*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/ZJets_HT-2500ToInf.root		../../output/job_2016727_10/ZJets_HT-2500ToInf/ZJets_HT-2500ToInf*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP600.root			../../output/job_201643_15/2HDM_MZP600/2HDM_MZP600*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP800.root			../../output/job_201643_15/2HDM_MZP800/2HDM_MZP800*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1000.root		../../output/job_201643_15/2HDM_MZP1000/2HDM_MZP1000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1200.root		../../output/job_201643_15/2HDM_MZP1200/2HDM_MZP1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1400.root		../../output/job_201643_15/2HDM_MZP1400/2HDM_MZP1400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1700.root		../../output/job_201643_15/2HDM_MZP1700/2HDM_MZP1700*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2000.root		../../output/job_201643_15/2HDM_MZP2000/2HDM_MZP2000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2500.root		../../output/job_201643_15/2HDM_MZP2500/2HDM_MZP2500*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP600_mA0400.root		../../output/job_201643_17/2HDM_MZp-600/2HDM_MZp-600*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP800_mA0400.root		../../output/job_201643_17/2HDM_MZp-800/2HDM_MZp-800*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP800_mA0600.root		../../output/job_201692_16/2HDM_MZp-800_MA0-600/2HDM_MZp-800*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1200_mA0600.root		../../output/job_201692_16/2HDM_MZp-1200_MA0-600/2HDM_MZp-1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2500_mA0400.root		../../output/job_201692_16/2HDM_MZp-2500_MA0-400/2HDM_MZp-2500*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP800_mA0500.root		../../output/job_2016513_16/2HDM_MZp-800_MA0-500/2HDM_MZp-800*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1000_mA0400.root		../../output/job_2016513_16/2HDM_MZp-1000_MA0-400/2HDM_MZp-1000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1000_mA0500.root		../../output/job_2016513_16/2HDM_MZp-1000_MA0-500/2HDM_MZp-1000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1000_mA0600.root		../../output/job_2016513_16/2HDM_MZp-1000_MA0-600/2HDM_MZp-1000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1000_mA0700.root		../../output/job_2016513_16/2HDM_MZp-1000_MA0-700/2HDM_MZp-1000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1000_mA0800.root		../../output/job_2016513_16/2HDM_MZp-1000_MA0-800/2HDM_MZp-1000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1200_mA0400.root		../../output/job_2016513_16/2HDM_MZp-1200_MA0-400/2HDM_MZp-1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1200_mA0500.root		../../output/job_2016513_16/2HDM_MZp-1200_MA0-500/2HDM_MZp-1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1200_mA0700.root		../../output/job_2016513_16/2HDM_MZp-1200_MA0-700/2HDM_MZp-1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1200_mA0800.root		../../output/job_2016513_16/2HDM_MZp-1200_MA0-800/2HDM_MZp-1200*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1400_mA0400.root		../../output/job_2016513_16/2HDM_MZp-1400_MA0-400/2HDM_MZp-1400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1400_mA0500.root		../../output/job_2016513_16/2HDM_MZp-1400_MA0-500/2HDM_MZp-1400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1400_mA0600.root		../../output/job_2016513_16/2HDM_MZp-1400_MA0-600/2HDM_MZp-1400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1400_mA0700.root		../../output/job_2016513_16/2HDM_MZp-1400_MA0-700/2HDM_MZp-1400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1400_mA0800.root		../../output/job_2016513_16/2HDM_MZp-1400_MA0-800/2HDM_MZp-1400*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1700_mA0400.root		../../output/job_2016513_16/2HDM_MZp-1700_MA0-400/2HDM_MZp-1700*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1700_mA0500.root		../../output/job_2016513_16/2HDM_MZp-1700_MA0-500/2HDM_MZp-1700*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1700_mA0600.root		../../output/job_2016513_16/2HDM_MZp-1700_MA0-600/2HDM_MZp-1700*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1700_mA0700.root		../../output/job_2016513_16/2HDM_MZp-1700_MA0-700/2HDM_MZp-1700*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP1700_mA0800.root		../../output/job_2016513_16/2HDM_MZp-1700_MA0-800/2HDM_MZp-1700*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2000_mA0400.root		../../output/job_2016513_16/2HDM_MZp-2000_MA0-400/2HDM_MZp-2000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2000_mA0500.root		../../output/job_2016513_16/2HDM_MZp-2000_MA0-500/2HDM_MZp-2000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2000_mA0600.root		../../output/job_2016513_16/2HDM_MZp-2000_MA0-600/2HDM_MZp-2000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2000_mA0700.root		../../output/job_2016513_16/2HDM_MZp-2000_MA0-700/2HDM_MZp-2000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2000_mA0800.root		../../output/job_2016513_16/2HDM_MZp-2000_MA0-800/2HDM_MZp-2000*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2500_mA0500.root		../../output/job_2016513_16/2HDM_MZp-2500_MA0-500/2HDM_MZp-2500*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2500_mA0600.root		../../output/job_2016513_16/2HDM_MZp-2500_MA0-600/2HDM_MZp-2500*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2500_mA0700.root		../../output/job_2016513_16/2HDM_MZp-2500_MA0-700/2HDM_MZp-2500*.root
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/2HDM_mZP2500_mA0800.root		../../output/job_2016513_16/2HDM_MZp-2500_MA0-800/2HDM_MZp-2500*.root
#
#hadd /afs/cern.ch/work/m/mzientek/private/25ns_v76X_v2/DoubleEG.root  			../../output/job_201643_15/DoubleEG/DoubleEG*.root

