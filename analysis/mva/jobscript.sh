#!/bin/sh

ANA_DIR=/afs/cern.ch/user/m/mzientek/private/MonoHgg_Moriond17/CMSSW_8_0_26_patch1/src/
RUN_DIR=/afs/cern.ch/user/m/mzientek/private/MonoHgg_Moriond17/CMSSW_8_0_26_patch1/src/MonoHiggsToGG/analysis/mva/

cd $ANA_DIR
eval `scram runtime -sh`
cd $RUN_DIR

echo "run job!"
python makeMVAtest.py
echo "done running"

echo "removing potential core dump file!"
rm core.*

echo "all done successfully!"
