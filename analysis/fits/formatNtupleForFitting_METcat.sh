#! /bin/sh

#############################################
#
# fitterFormatting_METcat input arguements:
#   1st: input directory
#   2nd: output directory
#   3rd: type (sig, bkg, data)
#   4th: prompt (for duplicate removal)
#   5th: input filename 
#   6th: sample name
#
# final files used for the fit are:
#   outdir/Output_MC.root
#   outdir/Output_Data.root
#
#############################################


indir="/afs/cern.ch/work/m/mzientek/public/25ns_v80X_v3/"
#indir="../macro/data/25ns_v80X_v2/"
metcut=$1
outdir="ntuples4fit_pho_met"${metcut}

mkdir -p $outdir

# Sidenote: Safely ignore warning message "tab completion not implemented for this context" 
# This comes from the tabs included for making the inputs to fitterFormatting easier to read below 

root -l -b << EOF
.L fitterFormatting_METcat.cc++


fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP600_mA0300_skimmedtree.root",		"sig_2HDM_mZP600_mA0300")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP800_mA0300_skimmedtree.root",		"sig_2HDM_mZP800_mA0300")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1000_mA0300_skimmedtree.root",	"sig_2HDM_mZP1000_mA0300")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1200_mA0300_skimmedtree.root",	"sig_2HDM_mZP1200_mA0300")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1400_mA0300_skimmedtree.root",	"sig_2HDM_mZP1400_mA0300")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1700_mA0300_skimmedtree.root",	"sig_2HDM_mZP1700_mA0300")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP2500_mA0300_skimmedtree.root",	"sig_2HDM_mZP2500_mA0300")

fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP600_mA0400_skimmedtree.root",		"sig_2HDM_mZP600_mA0400")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP800_mA0400_skimmedtree.root",		"sig_2HDM_mZP800_mA0400")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1000_mA0400_skimmedtree.root",	"sig_2HDM_mZP1000_mA0400")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1200_mA0400_skimmedtree.root",	"sig_2HDM_mZP1200_mA0400")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1400_mA0400_skimmedtree.root",	"sig_2HDM_mZP1400_mA0400")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1700_mA0400_skimmedtree.root",	"sig_2HDM_mZP1700_mA0400")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP2500_mA0400_skimmedtree.root",	"sig_2HDM_mZP2500_mA0400")

fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP600_mA0500_skimmedtree.root",		"sig_2HDM_mZP600_mA0500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP800_mA0500_skimmedtree.root",		"sig_2HDM_mZP800_mA0500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1000_mA0500_skimmedtree.root",	"sig_2HDM_mZP1000_mA0500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1200_mA0500_skimmedtree.root",	"sig_2HDM_mZP1200_mA0500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1400_mA0500_skimmedtree.root",	"sig_2HDM_mZP1400_mA0500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1700_mA0500_skimmedtree.root",	"sig_2HDM_mZP1700_mA0500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP2500_mA0500_skimmedtree.root",	"sig_2HDM_mZP2500_mA0500")

fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP600_mA0600_skimmedtree.root",		"sig_2HDM_mZP600_mA0600")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP800_mA0600_skimmedtree.root",		"sig_2HDM_mZP800_mA0600")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1000_mA0600_skimmedtree.root",	"sig_2HDM_mZP1000_mA0600")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1200_mA0600_skimmedtree.root",	"sig_2HDM_mZP1200_mA0600")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1400_mA0600_skimmedtree.root",	"sig_2HDM_mZP1400_mA0600")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1700_mA0600_skimmedtree.root",	"sig_2HDM_mZP1700_mA0600")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP2500_mA0600_skimmedtree.root",	"sig_2HDM_mZP2500_mA0600")

fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1000_mA0700_skimmedtree.root",	"sig_2HDM_mZP1000_mA0700")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1200_mA0700_skimmedtree.root",	"sig_2HDM_mZP1200_mA0700")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1400_mA0700_skimmedtree.root",	"sig_2HDM_mZP1400_mA0700")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1700_mA0700_skimmedtree.root",	"sig_2HDM_mZP1700_mA0700")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP2500_mA0700_skimmedtree.root",	"sig_2HDM_mZP2500_mA0700")

fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1000_mA0800_skimmedtree.root",	"sig_2HDM_mZP1000_mA0800")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1200_mA0800_skimmedtree.root",	"sig_2HDM_mZP1200_mA0800")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1400_mA0800_skimmedtree.root",	"sig_2HDM_mZP1400_mA0800")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP1700_mA0800_skimmedtree.root",	"sig_2HDM_mZP1700_mA0800")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "2HDM_mZP2500_mA0800_skimmedtree.root",	"sig_2HDM_mZP2500_mA0800")

fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi1000_skimmedtree.root", "sig_ZpBaryonic_mZP10000_mChi1000")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi10_skimmedtree.root"  , "sig_ZpBaryonic_mZP10000_mChi10")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi150_skimmedtree.root" , "sig_ZpBaryonic_mZP10000_mChi150")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi1_skimmedtree.root"   , "sig_ZpBaryonic_mZP10000_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi500_skimmedtree.root" , "sig_ZpBaryonic_mZP10000_mChi500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi50_skimmedtree.root"  , "sig_ZpBaryonic_mZP10000_mChi50")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP1000_mChi1000_skimmedtree.root" , "sig_ZpBaryonic_mZP1000_mChi1000")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP1000_mChi150_skimmedtree.root"  , "sig_ZpBaryonic_mZP1000_mChi150")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP1000_mChi1_skimmedtree.root"    , "sig_ZpBaryonic_mZP1000_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP100_mChi10_skimmedtree.root"    , "sig_ZpBaryonic_mZP100_mChi10")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP100_mChi1_skimmedtree.root"     , "sig_ZpBaryonic_mZP100_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi1000_skimmedtree.root"   , "sig_ZpBaryonic_mZP10_mChi1000")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi10_skimmedtree.root"     , "sig_ZpBaryonic_mZP10_mChi10")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi1_skimmedtree.root"      , "sig_ZpBaryonic_mZP10_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi50_skimmedtree.root"     , "sig_ZpBaryonic_mZP10_mChi50")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP15_mChi10_skimmedtree.root"     , "sig_ZpBaryonic_mZP15_mChi10")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP1995_mChi1000_skimmedtree.root" , "sig_ZpBaryonic_mZP1995_mChi1000")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP2000_mChi1_skimmedtree.root"    , "sig_ZpBaryonic_mZP2000_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP2000_mChi500_skimmedtree.root"  , "sig_ZpBaryonic_mZP2000_mChi500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP200_mChi150_skimmedtree.root"   , "sig_ZpBaryonic_mZP200_mChi150")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP200_mChi1_skimmedtree.root"     , "sig_ZpBaryonic_mZP200_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP200_mChi50_skimmedtree.root"    , "sig_ZpBaryonic_mZP200_mChi50")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP20_mChi1_skimmedtree.root"      , "sig_ZpBaryonic_mZP20_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP295_mChi150_skimmedtree.root"   , "sig_ZpBaryonic_mZP295_mChi150")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP300_mChi50_skimmedtree.root"    , "sig_ZpBaryonic_mZP300_mChi50")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP500_mChi150_skimmedtree.root"   , "sig_ZpBaryonic_mZP500_mChi150")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP500_mChi1_skimmedtree.root"     , "sig_ZpBaryonic_mZP500_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP500_mChi500_skimmedtree.root"   , "sig_ZpBaryonic_mZP500_mChi500")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP50_mChi10_skimmedtree.root"     , "sig_ZpBaryonic_mZP50_mChi10")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP50_mChi1_skimmedtree.root"      , "sig_ZpBaryonic_mZP50_mChi1")
fitterFormatting($metcut,"$indir","$outdir","sig",0, "BaryonicZp_mZP995_mChi500_skimmedtree.root"   , "sig_ZpBaryonic_mZP995_mChi500")


fitterFormatting($metcut,"$indir","$outdir","bkg",0, "VHToGG_skimmedtree.root",			"VHToGG")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "VBFHToGG_skimmedtree.root",			"VBFHToGG")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "ttHJetToGG_skimmedtree.root",			"ttHJetToGG")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "GluGluHToGG_skimmedtree.root",		"GluGluHToGG")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "DiPhoton_skimmedtree.root",			"DiPhoton")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "QCD_skimmedtree.root",			"QCD")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "GJets_skimmedtree.root",			"GJets")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "DYJetsToLL_skimmedtree.root",			"DYJetsToLL")
fitterFormatting($metcut,"$indir","$outdir","bkg",0, "NonResBkg_skimmedtree.root",			"NonResBkg")

fitterFormatting($metcut,"$indir","$outdir","data",0,"DoubleEG_skimmedtree.root",			"DoubleEG")


.q

EOF
echo "Done"

echo "Adding MC Files Together"
hadd $outdir/Output_MC.root $outdir/sig* $outdir/GluGluHToGG* $outdir/DiPhoton* $outdir/V* $outdir/ttH* $outdir/QCD* $outdir/DY* $outdir/GJets* $outdir/NonResBkg*  
