import sys, numpy, ROOT
from ROOT import TH2F

# input file
indir = '/afs/cern.ch/work/m/mzientek/private/forXSec/genproductions/bin/MadGraph5_aMCatNLO/interactive/interactive_gridpack/work/MG5_aMC_v2_4_2/'
infile = 'crossSection_default_ZpBaryonic'
fin = open(indir+infile+".txt","r")

# output file
fout = ROOT.TFile("Output_XsecBARY.root","RECREATE")

# output histo
hist = ROOT.TH2F('h2_BARY_XSEC_pb','h2_BARY_XSEC_pb',1000,0,1000,1000,0,1000)

m_Zp = 1.0 
m_DM = 1.0
xsec = 1.0

# read in values
for line in fin:
  line = line.rstrip('\n')
  line = line.split(' ')
  m_Zp = float(line[0])
  m_DM = float(line[1])
  xsec = float(line[2])
  print m_Zp+" "+m_DM+" "+xsec 
  
  # fill histo
  hist.Fill(m_Zp,m_DM,xsec)
  hist.SetMarkerStyle(7)

# save histo
hist.Write()
fout.Close() 
