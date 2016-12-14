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


indir="../macro/data/25ns_v80X_v2/"
outdir="ntuples4fit_pho_met105"

mkdir -p $outdir

# Sidenote: Safely ignore warning message "tab completion not implemented for this context" 
# This comes from the tabs included for making the inputs to fitterFormatting easier to read below 

root -l -b << EOF
.L fitterFormatting_METcat.cc++


fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP600_mA0300.root",		"sig_2HDM_mZP600_mA0300")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP800_mA0300.root",		"sig_2HDM_mZP800_mA0300")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1000_mA0300.root",	"sig_2HDM_mZP1000_mA0300")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1200_mA0300.root",	"sig_2HDM_mZP1200_mA0300")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1400_mA0300.root",	"sig_2HDM_mZP1400_mA0300")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1700_mA0300.root",	"sig_2HDM_mZP1700_mA0300")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP2500_mA0300.root",	"sig_2HDM_mZP2500_mA0300")
                                                                 
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP600_mA0400.root",		"sig_2HDM_mZP600_mA0400")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP800_mA0400.root",		"sig_2HDM_mZP800_mA0400")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1000_mA0400.root",	"sig_2HDM_mZP1000_mA0400")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1200_mA0400.root",	"sig_2HDM_mZP1200_mA0400")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1400_mA0400.root",	"sig_2HDM_mZP1400_mA0400")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1700_mA0400.root",	"sig_2HDM_mZP1700_mA0400")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP2500_mA0400.root",	"sig_2HDM_mZP2500_mA0400")

fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP600_mA0500.root",		"sig_2HDM_mZP600_mA0500")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP800_mA0500.root",		"sig_2HDM_mZP800_mA0500")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1000_mA0500.root",	"sig_2HDM_mZP1000_mA0500")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1200_mA0500.root",	"sig_2HDM_mZP1200_mA0500")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1400_mA0500.root",	"sig_2HDM_mZP1400_mA0500")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1700_mA0500.root",	"sig_2HDM_mZP1700_mA0500")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP2500_mA0500.root",	"sig_2HDM_mZP2500_mA0500")

fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP600_mA0600.root",		"sig_2HDM_mZP600_mA0600")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP800_mA0600.root",		"sig_2HDM_mZP800_mA0600")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1000_mA0600.root",	"sig_2HDM_mZP1000_mA0600")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1200_mA0600.root",	"sig_2HDM_mZP1200_mA0600")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1400_mA0600.root",	"sig_2HDM_mZP1400_mA0600")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1700_mA0600.root",	"sig_2HDM_mZP1700_mA0600")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP2500_mA0600.root",	"sig_2HDM_mZP2500_mA0600")

fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1000_mA0700.root",	"sig_2HDM_mZP1000_mA0700")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1200_mA0700.root",	"sig_2HDM_mZP1200_mA0700")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1400_mA0700.root",	"sig_2HDM_mZP1400_mA0700")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1700_mA0700.root",	"sig_2HDM_mZP1700_mA0700")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP2500_mA0700.root",	"sig_2HDM_mZP2500_mA0700")

fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1000_mA0800.root",	"sig_2HDM_mZP1000_mA0800")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1200_mA0800.root",	"sig_2HDM_mZP1200_mA0800")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1400_mA0800.root",	"sig_2HDM_mZP1400_mA0800")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP1700_mA0800.root",	"sig_2HDM_mZP1700_mA0800")
fitterFormatting("$indir","$outdir","sig",0, "2HDM_mZP2500_mA0800.root",	"sig_2HDM_mZP2500_mA0800")

fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi1000.root", "sig_ZpBaryonic_mZP10000_mChi1000")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi10.root"  , "sig_ZpBaryonic_mZP10000_mChi10")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi150.root" , "sig_ZpBaryonic_mZP10000_mChi150")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi1.root"   , "sig_ZpBaryonic_mZP10000_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi500.root" , "sig_ZpBaryonic_mZP10000_mChi500")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10000_mChi50.root", , "sig_ZpBaryonic_mZP10000_mChi50")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP1000_mChi1000.root" , "sig_ZpBaryonic_mZP1000_mChi1000")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP1000_mChi150.root"  , "sig_ZpBaryonic_mZP1000_mChi150")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP1000_mChi1.root"    , "sig_ZpBaryonic_mZP1000_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP100_mChi10.root"    , "sig_ZpBaryonic_mZP100_mChi10")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP100_mChi1.root"     , "sig_ZpBaryonic_mZP100_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi1000.root"   , "sig_ZpBaryonic_mZP10_mChi1000")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi10.root"     , "sig_ZpBaryonic_mZP10_mChi10")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi1.root"      , "sig_ZpBaryonic_mZP10_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP10_mChi50.root"     , "sig_ZpBaryonic_mZP10_mChi50")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP15_mChi10.root"     , "sig_ZpBaryonic_mZP15_mChi10")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP1995_mChi1000.root" , "sig_ZpBaryonic_mZP1995_mChi1000")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP2000_mChi1.root"    , "sig_ZpBaryonic_mZP2000_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP2000_mChi500.root"  , "sig_ZpBaryonic_mZP2000_mChi500")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP200_mChi150.root"   , "sig_ZpBaryonic_mZP200_mChi150")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP200_mChi1.root"     , "sig_ZpBaryonic_mZP200_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP200_mChi50.root"    , "sig_ZpBaryonic_mZP200_mChi50")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP20_mChi1.root"      , "sig_ZpBaryonic_mZP20_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP295_mChi150.root"   , "sig_ZpBaryonic_mZP295_mChi150")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP300_mChi50.root"    , "sig_ZpBaryonic_mZP300_mChi50")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP500_mChi150.root"   , "sig_ZpBaryonic_mZP500_mChi150")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP500_mChi1.root"     , "sig_ZpBaryonic_mZP500_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP500_mChi500.root"   , "sig_ZpBaryonic_mZP500_mChi500")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP50_mChi10.root"     , "sig_ZpBaryonic_mZP50_mChi10")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP50_mChi1.root"      , "sig_ZpBaryonic_mZP50_mChi1")
fitterFormatting("$indir","$outdir","sig",0, "BaryonicZp_mZP995_mChi500.root"   , "sig_ZpBaryonic_mZP995_mChi500")


fitterFormatting("$indir","$outdir","bkg",0, "VHToGG.root",			"VHToGG")
fitterFormatting("$indir","$outdir","bkg",0, "VBFHToGG.root",			"VBFHToGG")
fitterFormatting("$indir","$outdir","bkg",0, "ttHJetToGG.root",			"ttHJetToGG")
fitterFormatting("$indir","$outdir","bkg",0, "GluGluHToGG.root",		"GluGluHToGG")
fitterFormatting("$indir","$outdir","bkg",0, "DiPhoton.root",			"DiPhoton")
fitterFormatting("$indir","$outdir","bkg",0, "QCD.root",			"QCD")
fitterFormatting("$indir","$outdir","bkg",0, "GJets.root",			"GJets")
fitterFormatting("$indir","$outdir","bkg",0, "DYJetsToLL.root",			"DYJetsToLL")
fitterFormatting("$indir","$outdir","bkg",0, "NonResBkg.root",			"NonResBkg")

fitterFormatting("$indir","$outdir","data",0,"DoubleEG.root",			"DoubleEG")


.q

EOF
echo "Done"

echo "Adding MC Files Together"

hadd $outdir/Output_MC.root $outdir/sig* $outdir/GluGluHToGG* $outdir/DiPhoton* $outdir/V* $outdir/ttH* $outdir/QCD* $outdir/DY* $outdir/GJets* $outdir/NonResBkg*  
