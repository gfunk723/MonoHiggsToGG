#! /bin/sh

path=""
sample=$1
weight=$2

echo "Adding weight of "${weight}"/pb to: "${sample}
root -l -b -q "addWeights.C("\"${path}\"","\"${sample}\"",${weight})"

echo "Finished adding weights"
