#! /bin/sh

mA=300
for mZ in {600,800,1000,1200,1400,1700,2000,2500}; do

  ggcard="gg/datacard_ntuples4fit_pho_allMC_woLepVetos_met50_met130_cic_default_shapes_lumi_35.9_MonoHgg_sig_2HDM_mZP${mZ}_mA0${mA}_13TeV.txt"
  ttcard="Zprime${mZ}A${mA}/cmb/${mA}/combined.txt.cmb"
  cbcard="dataCard_comb_2HDM_mZP${mZ}_mA${mA}" 

  #--- combine cards
  combineCards.py ${ggcard} ${ttcard} > "${cbcard}.txt"

  #--- replace mass var in datacard
  python replaceZpNames.py -f "${cbcard}.txt" -m ${mA}

  #--- call combine
  combine -M Asymptotic -m ${mZ} "${cbcard}_new.txt"

done

#--- hadd files
hadd higgsCombine.Asymptotic.mA${mA}.root higgsCombineTest.Asymptotic.mH*.root 
