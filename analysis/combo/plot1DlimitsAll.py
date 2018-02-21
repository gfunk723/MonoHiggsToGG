import os
import sys
import ROOT
from array import array
import numpy as np
import json
from CMS_lumi import CMS_lumi
import plotting_interp as plot
ROOT.gROOT.SetBatch(ROOT.kTRUE)
plot.ModTDRStyle()

def run(model,m1):
 
  outdir = '~/www/Plots/13TeV_v80X_moriond17/PaperPlots/'

  channels = []
  channels.append('gg') # gamgam
  channels.append('tt') # tautau
  channels.append('cm') # combine

  filepath = {}
  filepath['gg'] = '/eos/cms/store/group/phys_exotica/MonoHgg/MonoH-COMBO-2016/'+model+'_jsons/gg_'+model+'_results/'
  filepath['tt'] = '/eos/cms/store/group/phys_exotica/MonoHgg/MonoH-COMBO-2016/'+model+'_jsons/tt_'+model+'_results/'
  filepath['cm'] = '/eos/cms/store/group/phys_exotica/MonoHgg/MonoH-COMBO-2016/'+model+'_jsons/combo_'+model+'_results/'

  text = {}
  text['gg'] = 'h(#gamma#gamma)'
  text['tt'] = 'h(#tau#tau)'
  text['cm'] = 'h(#gamma#gamma + #tau#tau)'

  color = {}
  color['gg'] = ROOT.kOrange+7
  color['tt'] = ROOT.kAzure-1
  color['cm'] = ROOT.kSpring-8

  wgt = {}
  wgt['gg'] = 1.0 
  wgt['tt'] = 1.0 
  wgt['cm'] = 1.0 

  if (model=="2HDM"): m2 = [450,500,550,600,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1400,1450,1500,1600,1650,1700,1750,1800,1850,1900,1950]
  if (model=="BARY"): m2 = [10,20,30,40,50,75,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000]

  # read in theoretical xsec
  if (model=="2HDM"): xsecfile = open('crosssectionZp2HDM.txt','r')
  if (model=="BARY"): xsecfile = open('crosssectionZpBaryonic.txt','r') 
  mZ = []
  mA = []
  mstr = []
  xsecs = {} 
  xsec = []
  for line in xsecfile:
    line = line.rstrip('\n')
    line = line.split(' ')
    mZ.append(line[0])
    mA.append(line[1])
    massstr = line[0]+'_'+line[1]
    mstr.append(massstr)
    xsecs[massstr] = float(line[2])

  # graphs for each channel
  tgraphs_the = {}
  tgraphs_exp = {}
  tgraphs_obs = {}
  tgraphs_1si = {}
  tgraphs_2si = {}
  for c in channels:
    tgraphs_the[c] = ROOT.TGraph() 
    tgraphs_exp[c] = ROOT.TGraph() 
    tgraphs_obs[c] = ROOT.TGraph() 
    tgraphs_1si[c] = ROOT.TGraph() 
    tgraphs_2si[c] = ROOT.TGraph() 
    
    # read in jsons and setup graphs 
    tgraphs_the[c],tgraphs_exp[c],tgraphs_obs[c],tgraphs_1si[c],tgraphs_2si[c] = setupGraph(c,model,m1,m2,mstr,xsecs,wgt[c],filepath[c])
    # axis names
    tgraphs_the[c].SetTitle("")
    tgraphs_the[c].GetXaxis().SetTitle("M_{Z'} [GeV]")
    if (model=="2HDM"): tgraphs_the[c].GetYaxis().SetTitle("#sigma_{95% CL}(pp #rightarrow Z' #rightarrow Ah) [pb]")
    if (model=="BARY"): tgraphs_the[c].GetYaxis().SetTitle("#sigma_{95% CL}(pp #rightarrow Z' #rightarrow #chi#chi h) [pb]")
    #tgraphs_the[c].GetYaxis().SetTitleOffset(0.9)

    # style
    # theory curve 
    tgraphs_the[c].SetLineWidth(3)
    # expected
    tgraphs_exp[c].SetLineColor(color[c])
    tgraphs_exp[c].SetLineStyle(7)
    tgraphs_exp[c].SetLineWidth(3)
    tgraphs_exp[c].SetFillColor(0)
    # observed
    tgraphs_obs[c].SetLineWidth(3)
    tgraphs_obs[c].SetMarkerStyle(33)
    tgraphs_obs[c].SetMarkerColor(color[c])
    tgraphs_obs[c].SetLineColor(color[c])
    # 1 sigma 
    tgraphs_1si[c].SetLineColor(color[c])
    tgraphs_1si[c].SetLineWidth(0)
    tgraphs_1si[c].SetFillColor(color[c])
    tgraphs_1si[c].SetFillStyle(3013)
    # 2 sigma
    tgraphs_2si[c].SetFillColor(8)
    tgraphs_2si[c].SetFillStyle(3013)
  
  # plot   
  ROOT.gStyle.SetOptStat(0)
  c = ROOT.TCanvas('','')
  c.SetLeftMargin(0.15)
  c.SetLogx(1)
  c.SetLogy(1)
  #c.SetGrid()

  # draw graphs
  # theory
  tgraphs_the[channels[0]].SetMaximum(15)
  tgraphs_the[channels[0]].SetMinimum(0.01)
  if (model=="2HDM"): tgraphs_the[channels[0]].GetXaxis().SetRangeUser(450,2000)
  tgraphs_the[channels[0]].Draw("AC")
  # cmb
  if ('cm' in channels):
    tgraphs_exp['cm'].Draw("C  SAME")
    tgraphs_obs['cm'].Draw("CP SAME")
    tgraphs_1si['cm'].Draw("F  SAME")
  if ('gg' in channels): tgraphs_exp['gg'].Draw("C SAME")
  if ('tt' in channels): tgraphs_exp['tt'].Draw("C SAME")
  tgraphs_the[channels[0]].Draw("C SAME")

  # legend
  if (model=="2HDM"): leg = ROOT.TLegend(0.5, 0.6, 0.8, 0.9)
  if (model=="BARY"): leg = ROOT.TLegend(0.2, 0.2, 0.5, 0.5)
  leg.SetFillColor(0)
  for chan in channels:
    leg.AddEntry(tgraphs_exp[chan],text[chan]+' median expected', 'LF')
    if (chan=='cm'): leg.AddEntry(tgraphs_1si[chan],text[chan]+' 68% expected', 'F')
    if (chan=='cm'): leg.AddEntry(tgraphs_obs[chan],text[chan]+' observed', 'L')
  leg.AddEntry(tgraphs_the['gg'],"#sigma_{th}", "L")

  # latex label
  if (model=="2HDM"): text = "#bf{Z'-2HDM, m_{A} = 300 GeV}"
  if (model=="BARY"): text = "#bf{Baryonic Z', m_{#chi} = 1 GeV}"
  latex = ROOT.TLatex(0.18,0.84,text)
  latex.SetNDC();
  latex.SetTextAlign(12); # align left
  latex.SetTextSize(0.03);
  latex.Draw("SAME") 

  # save plot
  leg.Draw("SAME")
  CMS_lumi(c,4,10)
  c.RedrawAxis() 
  c.Print(outdir+"limits1D_"+model+".pdf")
  c.Print(outdir+"limits1D_"+model+".png")

def scaleBR(val,wgt):
   scaledval = array('d')
   for v in val:
     newv = v*wgt
     scaledval.append(newv) 
   return scaledval
  
def setupGraph(chan,model,m1,m2,mstr,xsecs,wgt,filepath):

  xsec = array( 'd' )
  mass = array( 'd' )
  exp_raw = array( 'd' ) 
  obs_raw = array( 'd' ) 
  up1_raw = array( 'd' )
  do1_raw = array( 'd' )
  up2_raw = array( 'd' )
  do2_raw = array( 'd' )

  # pick up jsons with limits
  for m in m2:
    newmassstr = str(m)+'_'+m1
    if newmassstr not in mstr: continue
    if (model=="BARY") and (newmassstr=='30_1' or newmassstr == '40_1' or newmassstr =='75_1' 
       or newmassstr == '850_1' or newmassstr == '150_1' or newmassstr == '400_1'
       or newmassstr == '700_1' or newmassstr == '750_1' or newmassstr == '800_1'): continue

    # make correct array of xsecs
    mass.append(m)
    xsec.append(xsecs[str(m)+'_'+m1])   
    if (model=="BARY" and chan=="gg"): filename=filepath+'Zprime'+str(m)+'DM'+m1+'.json'
    else:                              filename=filepath+'Zprime'+str(m)+'A'+m1+'.json'

    if os.path.isfile(filename):
      with open(filename) as jsonfile:
        data = json.load(jsonfile)
        for key in data: 
          exp_raw.append(data[key][u'exp0'])
          obs_raw.append(data[key][u'obs'])
          up1_raw.append(data[key][u'exp+1'])
          do1_raw.append(data[key][u'exp-1'])
          up2_raw.append(data[key][u'exp+2'])
          do2_raw.append(data[key][u'exp-2'])
    else:  print 'File '+filename+' NOT found'

  exp = scaleBR(exp_raw,wgt) 
  obs = scaleBR(obs_raw,wgt)
  up1 = scaleBR(up1_raw,wgt)
  do1 = scaleBR(do1_raw,wgt)
  up2 = scaleBR(up2_raw,wgt)
  do2 = scaleBR(do2_raw,wgt)

  numpts = len(mass)         
  limitPlotExp  = ROOT.TGraph(numpts,mass,exp)
  limitPlotObs  = ROOT.TGraph(numpts,mass,obs)
  limitPlotXsc  = ROOT.TGraph(numpts,mass,xsec)
  limitPlot1sig = ROOT.TGraph(2*numpts)
  limitPlot2sig = ROOT.TGraph(2*numpts)
  for i in range(0,numpts):
    limitPlot1sig.SetPoint(i,mass[i],up1[i])
    limitPlot1sig.SetPoint(numpts+i,mass[numpts-i-1],do1[numpts-i-1])
    limitPlot2sig.SetPoint(i,mass[i],up2[i])
    limitPlot2sig.SetPoint(numpts+i,mass[numpts-i-1],do2[numpts-i-1])

  return limitPlotXsc, limitPlotExp, limitPlotObs, limitPlot1sig, limitPlot2sig

if __name__=="__main__":
  model = sys.argv[1]
  m1    = sys.argv[2]
  run(model,m1)
