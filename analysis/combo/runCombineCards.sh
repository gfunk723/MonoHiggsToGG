#! /bin/sh

mass=$1
dir="combo_m${mass}"

mkdir $dir
cp combineCards.sh   "${dir}/"
cp combineTool.py    "${dir}/"
cp replaceZpNames.py "${dir}/"

cd $dir
./combineCards.sh $mass
