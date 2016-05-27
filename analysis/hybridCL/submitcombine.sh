#! /bin/sh

for mass in 600 800 1000 1200 1400 1700 2000 2500
  do
    echo $mass
    python combine.py -i DataCard_2HDM_mZP${mass}.txt -d /afs/cern.ch/work/m/mzientek/public/HybridNewCL/2HDM_A0300 -q 1nh -M HybridNew --onews --begin ${mass} --end ${mass} -t 1000
  done

