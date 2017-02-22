#!/bin/bash

# ---------------------------------------------------------
# Run by caling:
# ./resubmit.sh job_XXXXXXX_XX SampleName
# ---------------------------------------------------------

DIR=$1
NAME=$2

mkdir -p $DIR/$NAME/logOld
mv $DIR/$NAME/log/* $DIR/$NAME/logOld/

FILES=$DIR/$NAME/logOld/*
COUNTER=0
log="logOld"
logg="log"
src="src"
for i in $FILES
do
    if grep -ir FallbackFileOpenError >/dev/null $i
	then
	logfile=$i
	srcfile=$(echo $i | sed "s/$log/$src/g")
	srcfile=$(echo $srcfile | sed "s/"$NAME"_/submit_/g")
	srcfile=$(echo $srcfile | sed "s/$logg/$src/g")
	logfile=$(echo $logfile | sed "s/logOld/log/g")
	echo bsub -q 8nh -o $logfile source /afs/cern.ch/user/m/mzientek/private/MonoHggCMSSW80X/CMSSW_8_0_8_patch1/src/MonoHiggsToGG/analysis/scripts/$srcfile 
	bsub -q 8nh -o $logfile source /afs/cern.ch/user/m/mzientek/private/MonoHggCMSSW80Xwork/CMSSW_8_0_8_patch1/src/MonoHiggsToGG/analysis/scripts/$srcfile 
	let COUNTER=COUNTER+1 
    fi
#, for src in list: system(bsub %s -q 2nd, src.replace(log,src)”
done

echo $COUNTER
