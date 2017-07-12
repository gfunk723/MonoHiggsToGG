import sys, os, numpy, ROOT
from ROOT import TObjString
from ROOT import RooWorkspace
from ROOT import TProcessID
from ROOT import RooRealVar
from ROOT import RooArgList
from ROOT import RooArgSet
from ROOT import RooDataSet
from ROOT import RooDataHist
from ROOT import RooAbsReal

def getEff(cat,mZp,mDM):
  eff = 1.0
  if cat==1: #highMET
    eff=(0.00474*mZp+0.0397*mDM-1.4e-07*mZp*mZp-1.19e-05*mDM*mDM-2.95e-06*mZp*mDM+6.1583)
  if cat==0: #lowMET
    eff=(-3e-04*mZp-4e-03*mDM-1.3e-08*mZp*mZp-4.4e-07*mDM*mDM-3.8e-07*mZp*mDM+6.5448)
  return eff

def makeCard(mZp,mChi):

  # Setup input and output files
  indir = ""
  old_str = "sig_ZpBaryonic_mZP10_mChi1"
  new_str = "sig_ZpBaryonic_mZP"+mZp+"_mChi"+mChi
  fin  = open(indir+"dataCard_"+old_str+"_13TeV.txt","r")
  fout = open(indir+"dataCard_"+new_str+"_13TeV.txt","w") 
  rin  = ROOT.TFile(indir+old_str+"_13TeV.root") 
  rout = ROOT.TFile(indir+new_str+"_13TeV.root","RECREATE")

  # Copy the datacard for new mass point
  for line in fin:
    if old_str in line:
      line = line.replace(old_str,new_str)
    fout.write(line) 

  # Get the old and new eff
  mZ  = float(mZp)
  mDM = float(mChi)
  old_efflowMET  = getEff(0,10,1)
  old_effhighMET = getEff(1,10,1)
  new_efflowMET  = getEff(0,mZ,mDM)
  new_effhighMET = getEff(1,mZ,mDM)
  scale_lowMET   = new_efflowMET/old_efflowMET
  scale_highMET  = new_effhighMET/old_effhighMET
  #print("Old eff: low = %f, high = %f" %(old_efflowMET,old_effhighMET)) 
  #print("New eff: low = %f, high = %f" %(new_efflowMET,new_effhighMET))
  #print("Scale:   low = %f, high = %f" %(scale_lowMET,scale_highMET)) 

  # Copy the input file
  in_TObjString    = TObjString(rin.cfg)
  out_TObjString   = in_TObjString.Clone()
  in_RooWorkspace  = RooWorkspace(rin.wtemplates)

  w1 = ROOT.RooWorkspace("wtemplates")
  w1.rooImport = getattr(w1,'import')
  var1 = in_RooWorkspace.var('mgg')
  var2 = in_RooWorkspace.var('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met0-130_norm')
  var3 = in_RooWorkspace.var('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met130_norm')
  valnorm_lowMET  = scale_lowMET*var2.getValV()
  valnorm_highMET = scale_highMET*var3.getValV()
  norm1 = RooRealVar("model_signal"+new_str+"_13TeV_met0-130_norm","model_signal"+new_str+"13TeV_met0-130_norm",valnorm_lowMET)
  norm2 = RooRealVar("model_signal"+new_str+"_13TeV_met130_norm","model_signal"+new_str+"13TeV_met130_norm",valnorm_highMET)
  varlist = ROOT.RooArgList(var1,norm1,norm2)
  #print("%f * %f" %(scale_lowMET,var2.getValV()))
  #print("%f" %valnorm_lowMET)
  #print("%f" %norm1.getValV())

  pdf1 = in_RooWorkspace.pdf('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met0-130')
  pdf2 = in_RooWorkspace.pdf('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met0-130_energyScalemet0-130Down')
  pdf3 = in_RooWorkspace.pdf('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met0-130_energyScalemet0-130Up')
  pdf4 = in_RooWorkspace.pdf('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met130')
  pdf5 = in_RooWorkspace.pdf('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met130_energyScalemet130Down')
  pdf6 = in_RooWorkspace.pdf('model_signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met130_energyScalemet130Up')

  dat1 = in_RooWorkspace.data('signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met130')
  dat2 = in_RooWorkspace.data('signalforPdf_sig_ZpBaryonic_mZP10_mChi1_13TeV_met130')
  dat3 = in_RooWorkspace.data('signal_sig_ZpBaryonic_mZP10_mChi1_13TeV_met0-130')
  dat4 = in_RooWorkspace.data('signalforPdf_sig_ZpBaryonic_mZP10_mChi1_13TeV_met0-130')
  #print("%f" %dat1.sumEntries())

  #dat = ROOT.RooDataSet('test','test',RooArgSet(var2,var3),var1) 

  # Write to output file
  out_TObjString.Write()
  w1.rooImport(var1)
  w1.rooImport(norm1)
  w1.rooImport(norm2)

  #w1.rooImport(dat1)
  #dat.Write()

  w1.rooImport(pdf1)
  w1.rooImport(pdf2)
  w1.rooImport(pdf3)
  w1.rooImport(pdf4)
  w1.rooImport(pdf5)
  w1.rooImport(pdf6)

  w1.Print()
  w1.Write()
  rout.Close()

if __name__ == "__main__":
  filename = ""

  if len(sys.argv) < 3: 
    print("Invalid usage! Correct usage is: python makeGenericDataCard.py [mZp] [mChi]")
    sys.exit()
  else:
    MZP = sys.argv[1]
    MCHI = sys.argv[2]
  if MZP=="10" and MCHI=="1": 
    print("Can't use mZp = 10 and mChi = 1. That is the input! Can't be the output!")
    sys.exit()
  
  print("Making datacard for mZp = %s , mChi = %s" %(MZP, MCHI))
  makeCard(MZP,MCHI)
  print("Finished")
