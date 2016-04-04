#!/bin/bash

sel="Sel1"

pathdir="/afs/cern.ch/user/m/mzientek/private/MonoHggCMSSW/CMSSW_7_6_3_patch2/src/MonoHiggsToGG/analysis/macro/diPhoPlots"
indir1="25ns_v76X_v2_Opt"

mkdir -p Opt${sel}

if [$sel="Sel1"]; then
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP600_${sel}_1_met105.txt  76X_Opt${sel}/DataCard_2HDM_mZP600.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP800_${sel}_2_met165.txt  76X_Opt${sel}/DataCard_2HDM_mZP800.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1000_${sel}_3_met220.txt 76X_Opt${sel}/DataCard_2HDM_mZP1000.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1200_${sel}_4_met245.txt 76X_Opt${sel}/DataCard_2HDM_mZP1200.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1400_${sel}_5_met255.txt 76X_Opt${sel}/DataCard_2HDM_mZP1400.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1700_${sel}_6_met285.txt 76X_Opt${sel}/DataCard_2HDM_mZP1700.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP2000_${sel}_7_met285.txt 76X_Opt${sel}/DataCard_2HDM_mZP2000.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP2500_${sel}_7_met285.txt 76X_Opt${sel}/DataCard_2HDM_mZP2500.txt
else 
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP600_${sel}_1_met95.txt   76X_Opt${sel}/DataCard_2HDM_mZP600.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP800_${sel}_2_met170.txt  76X_Opt${sel}/DataCard_2HDM_mZP800.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1000_${sel}_3_met170.txt 76X_Opt${sel}/DataCard_2HDM_mZP1000.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1200_${sel}_4_met230.txt 76X_Opt${sel}/DataCard_2HDM_mZP1200.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1400_${sel}_5_met255.txt 76X_Opt${sel}/DataCard_2HDM_mZP1400.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP1700_${sel}_6_met285.txt 76X_Opt${sel}/DataCard_2HDM_mZP1700.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP2000_${sel}_7_met285.txt 76X_Opt${sel}/DataCard_2HDM_mZP2000.txt
  cp $pathdir/$indir1$sel/ABCD/DataCard_2HDM_mZP2500_${sel}_7_met285.txt 76X_Opt${sel}/DataCard_2HDM_mZP2500.txt
fi

for mass in 600 800 1000 1200 1400 1700 2500 #1 10 100 1000
  do
    echo $mass 
    combine Opt${sel}/DataCard_2HDM_mZP${mass}.txt -M Asymptotic -m ${mass} --run=blind    
  done
