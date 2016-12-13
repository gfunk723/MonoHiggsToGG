#! /bin/sh

path="../macro/data/25ns_v80X_v1/"
sample=$1

echo "Running sample: " ${sample}
root -l -b -q "skim.C("\"${path}\"","\"${sample}\"")"

echo "done with skimming"
