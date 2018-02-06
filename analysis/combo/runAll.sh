#!/bin/bash

vals_mA=($(seq 300 25 700))

for mA in ${vals_mA[@]}; do
  ./launch_job.sh $mA
done 
