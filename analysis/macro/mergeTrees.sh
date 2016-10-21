#! /bin/sh 
# this scripts creates a merged root file in the self-created merged

mkdir -p data/25ns_v80X_v0/
mkdir -p /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/

hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/DoubleEG.root  			 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161020_12/DoubleEG/DoubleEG*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/DiPhoton.root			 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161019_17/DiPhoton/DiPhoton*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/GluGluHToGG.root			 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161019_17/GluGluHToGG/GluGluHToGG*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP600_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161019_17/2HDM_MZp-600_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP800_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-800_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP1000_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-1000_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP1200_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-1200_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP1400_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-1400_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP1700_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-1700_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP2000_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-2000_MA0-300/2HDM_MZp*.root
hadd /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/2HDM_mZP2500_mA0300.root		 /afs/cern.ch/work/m/mzientek/private/25ns_v80X_v0/job_20161021_10/2HDM_MZp-2500_MA0-300/2HDM_MZp*.root



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

