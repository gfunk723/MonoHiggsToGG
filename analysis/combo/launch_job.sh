#!/bin/bash

mass=$1
echo "Mass ${mass}"
python createjob.py $mass 

chmod 755 submitjob${mass}.tmpl

echo "bsub -q 1nd submitjob${mass}.tmpl"
bsub -q 1nd submitjob${mass}.tmpl
