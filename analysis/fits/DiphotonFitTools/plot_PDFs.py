import os
import numpy
import ROOT
from ROOT import *
from ROOT import TObject 
from ROOT import RooWorkspace
from ROOT import RooRealVar
from ROOT import RooArgList
from ROOT import RooArgSet
from ROOT import RooDataSet
from ROOT import RooDataHist
from ROOT import RooAbsReal
from optparse import OptionParser, make_option

def comparePDF():

  # option list
  parser = OptionParser("usage: %prog [options]")
  parser.add_option("--lowMET",action="store_true",dest="doLowMET",
          default=False,help="Run lowMET"),
  parser.add_option("--signame",action="store",dest="signame",type="string",
          default="ZpBaryonic_mZP10_mChi1",help="Sig name"),
  parser.add_option("--dir1",action="store",type="string",
          default="/afs/cern.ch/work/m/mzientek/private/FitDirectory/CMSSW_8_0_28/src/diphotons/Analysis/macros/ntuples4fit_cic_default_shapes_lumi_35.9/",
          help="Path to dir1 to compare"),
  parser.add_option("--dir2",action="store",type="string",
          default="~soffi/public/4Margaret/ntuples4fit_pho_allMC_woLepVetos_met50_met130_cic_default_shapes_lumi_35.9_PARAMETRIC/",
          help="Path to dir2 to compare"),
  parser.add_option("-O",action="store",dest="outdir",type="string",
          default="~/www/Plots/13TeV_v80X_moriond17/FitResults/ntuples4fit/ntuples4fit_cic_default_shapes_lumi_35.9/",
          help="Outdir default = %default"),
  parser.add_option("--bkg",action="store_true",dest="do_bkg",
          default=True,help="Compare bkg"),
  parser.add_option("--sig",action="store_true",dest="do_sig",
          default=True,help="Compare sig"),
  parser.add_option("--ggh",action="store_true",dest="do_ggh",
          default=False,help="Compare ggh"),
  parser.add_option("--vbf",action="store_true",dest="do_vbf",
          default=False,help="Compare vbf"),
  parser.add_option("--tth",action="store_true",dest="do_tth",
          default=False,help="Compare tth"),
  parser.add_option("--vh",action="store_true",dest="do_vh",
          default=False,help="Compare vh"),

  # end option list 
  (options, args) = parser.parse_args()

  # which PDFs to compare
  items = []
  if options.do_bkg: items.append("bkg")
  if options.do_sig: items.append("sig")
  if options.do_ggh: items.append("ggh")
  if options.do_vbf: items.append("vbf")
  if options.do_tth: items.append("tth")
  if options.do_vh : items.append("vh")

  # setup files
  path1 = options.dir1 
  path2 = options.dir2
  filename = {} 
  bkgname1 = "ntuples4fit_cic_default_shapes_lumi_35.9_MonoHgg"
  bkgname2 = "ntuples4fit_pho_allMC_woLepVetos_met50_met130_cic_default_shapes_lumi_35.9_MonoHgg"
  filename["bkg"] = bkgname1
  filename["sig"] = "sig_"+options.signame+"_13TeV"
  filename["ggh"] = "GluGluHToGG_13TeV"
  filename["vbf"] = "VBFHToGG_13TeV"
  filename["tth"] = "ttHJetToGG_13TeV"
  filename["vh"]  = "VHToGG_13TeV"
  files1 = {}
  files2 = {}
  for item in items:
    if item=="bkg": 
      fname1 = path1+bkgname1+".root"
      fname2 = path2+bkgname2+".root"
    else: 
      fname1 = path1+filename[item]+".root"
      fname2 = path2+filename[item]+".root"
    #print("fname1: %s"%fname1)
    #print("fname2: %s"%fname2)
    files1[item] = ROOT.TFile(fname1)
    files2[item] = ROOT.TFile(fname2)

  # get workspaces
  workspaces1 = {}
  workspaces2 = {}
  for item in items:
    workspaces1[item] = ROOT.RooWorkspace(files1[item].wtemplates)
    workspaces2[item] = ROOT.RooWorkspace(files2[item].wtemplates)
  
  # get pdfs
  pdfnames = {}
  pdfnames["bkg"] = "model_bkg"
  pdfnames["sig"] = "model_signal_"+filename["sig"]
  pdfnames["ggh"] = "model_higgs_"+filename["ggh"]
  pdfnames["vbf"] = "model_higgs_"+filename["vbf"]
  pdfnames["tth"] = "model_higgs_"+filename["tth"]
  pdfnames["vh"]  = "model_higgs_"+filename["vh"]
  pdfs1 = {}
  pdfs2 = {}
  norm1 = {}
  norm2 = {}
  cat = "_met130"
  if options.doLowMET: cat = "_met0-130"
  for item in items:
    pdfs1[item] = workspaces1[item].pdf(pdfnames[item]+cat)
    pdfs2[item] = workspaces2[item].pdf(pdfnames[item]+cat)
    norm1[item] = workspaces1[item].var(pdfnames[item]+cat+"_norm").getValV()
    norm2[item] = workspaces2[item].var(pdfnames[item]+cat+"_norm").getValV()
    print(item+" -------- norm (new): "+str(norm1[item])+"\t v. norm (old): "+str(norm2[item]))
 
  # canvas & frames
  c = {}
  f = {}
  l = {}
  for item in items:
    c[item] = TCanvas("c_"+item,"c_"+item,600,600)
    c[item].cd()
    f[item] = ROOT.RooPlot(workspaces1[item].var('mgg'),105,181,38)
    l[item] = TLegend(0.7,0.7,0.85,0.85)
    curve1opts = [RooFit.LineColor(ROOT.kBlue),RooFit.Normalization(norm1[item],ROOT.RooAbsReal.NumEvent)]
    curve2opts = [RooFit.LineColor(ROOT.kBlue),RooFit.Normalization(norm2[item],ROOT.RooAbsReal.NumEvent)]
    styleopts  = [RooFit.LineColor(ROOT.kBlue),RooFit.FillColor(ROOT.kBlue),RooFit.FillStyle(1001)]
    pdfs2[item].plotOn(f[item],*(curve2opts+styleopts))                      # old pdf
    pdfs1[item].plotOn(f[item],*(curve1opts+[RooFit.LineColor(ROOT.kRed)]))  # new pdf
    l[item].AddEntry(pdfs1[item],"New fit","l")
    l[item].AddEntry(pdfs2[item],"Old fit","l")
    f[item].Draw() 
    l[item].Draw("same")
    print("Outfile: %scomparePDFs_%s%s.png"%(options.outdir,item,cat))
    c[item].SaveAs(options.outdir+"comparePDFs_"+item+cat+".png")
    c[item].SaveAs(options.outdir+"comparePDFs_"+item+cat+".pdf")

if __name__ == "__main__":
  print("Running...")
  comparePDF()
  print("Done")
