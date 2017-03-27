#! /bin/bash

DIR=$1
NAME=$2

FILES=$DIR/$NAME/logOld/*

rm test

for i in $FILES 
do
  number=$(ls $i | cut -d/ -f4 | cut -d_ -f2 | cut -d. -f1)
  echo $number >> test
done

python whichFilesMissing.py
