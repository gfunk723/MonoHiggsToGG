#! /bin/sh

dir="ntuples4fit_new/"

for mZp in "10"
  do 
  for mDM in "10" "25" "50" "75" "100" "125" "150" "175" "200" "225" "250" "275" "300" "350" "400" "450" "500" "550" "600" "650" "700" "750" "800" "850" "900" "950" "1000" "1050" "1100"
    do 
    python makeGenericDataCard.py $mZp $mDM ${dir} 
    done
  done


