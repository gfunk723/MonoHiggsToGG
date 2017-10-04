import os
from ROOT import *
from dep.pyapp import *
from dep.util  import *
from optparse import OptionParser, make_option

class PlotMaker(pyapp):
 
  def __init__(self):
    super(PlotMaker,self).__init__(option_list =[
      make_option("--noext",action="store_false",dest="do_ext",
                  default=True,help="Extend plot to lowest mDM on plot [default = %default]"),
      make_option("--exp",action="store_true",dest="do_exp",
                  default=False,help="Plot expected limits as well [default = %default]"),
      make_option("--gg",action="store_true",dest="do_gg",
                  default=False,help="Add gg plot [default = %default]"),
      make_option("--bb",action="store_true",dest="do_bb",
                  default=False,help="Add bb plot [default = %default]"),
      make_option("--tt",action="store_true",dest="do_tt",
                  default=False,help="Add tautau plot [default = %default]"),
      make_option("--zz",action="store_true",dest="do_zz",
                  default=False,help="Add zz plot [default = %default]"),
      make_option("--ww",action="store_true",dest="do_ww",
                  default=False,help="Add ww plot [default = %default]"),
      make_option("--suffix",action="store",dest="suffix",type="string",
                  default="",help="Additional suffix [default = %default]"),
      ])

  def __extrapolate__(self,gin,channels,mlow):
    gout     = {}
    num_extr = 100
    for channel in channels: 
      gout[channel] = TGraph()
      mDM_ref  = Double(0)
      xsec_ref = Double(0)
      gin[channel].GetPoint(0,mDM_ref,xsec_ref)
      mR_ref = 0.939*mDM_ref/(0.939+mDM_ref)
      for i in range(0, num_extr):
        mDM_i  = mlow + i*(mDM_ref-mlow)/num_extr
        mR_i   = 0.939*mDM_i/(0.939+mDM_i)
        xsec_i = xsec_ref*(mR_i*mR_i)/(mR_ref*mR_ref)
        gout[channel].SetPoint(i,mDM_i,xsec_i)
        for i in range(0,gin[channel].GetN()):
          mDM  = Double(0)
          xsec = Double(0)
          gin[channel].GetPoint(i,mDM,xsec)
          gout[channel].SetPoint(i+num_extr,mDM,xsec)
    gin[channel] = gout[channel] 

  def __convert__(self,gin,gout): 
    c_SI = 6.9e-41*1e12
    for i in range(0,gin.GetN()): 
      mMed = Double(0)
      mDM  = Double(0)
      gin.GetPoint(i,mMed,mDM)
      mR   = Double(0.939*mDM)/(0.939+mDM)
      xsec = Double(c_SI*(mR*mR)/(mMed*mMed*mMed*mMed))
      gout.SetPoint(i,mDM,xsec)
 
  def __call__(self,options,args):

    # setup which channels to run   
    channels = [] 
    if options.do_gg: channels.append("gg")
    if options.do_bb: channels.append("bb")
    if options.do_tt: channels.append("tt")
    if options.do_zz: channels.append("zz")
    if options.do_ww: channels.append("ww") 
    print("Make plot for channels: %s" %channels)

    # path to input files
    filepath   = {}
    filepath["gg"] = "~/www/Plots/13TeV_v80X_moriond17/ContourPlots_mine/ContourPlot_OutputFile_BARY.root";
    filepath["bb"] = "";
    filepath["tt"] = "";
    filepath["zz"] = "";
    filepath["ww"] = ""; 

    # style plots
    color = {}
    text  = {}
    color["gg"] = kMagenta-7
    color["bb"] = kOrange+3 
    color["tt"] = kRed+2
    color["zz"] = kOrange+9
    color["ww"] = kViolet+1

    text["gg"]  = "DM + H_{#gamma#gamma}"
    text["bb"]  = "DM + H_{bb}"
    text["tt"]  = "DM + H_{#tau#tau}"
    text["zz"]  = "DM + H_{ZZ}"
    text["ww"]  = "DM + H_{WW}"

    # pick up graphs
    tgraph_obs = {}
    tgraph_exp = {}
    for channel in channels:
      tgraph_obs[channel] = TFile(filepath[channel]).Get("observed_baryonic")
      tgraph_exp[channel] = TFile(filepath[channel]).Get("expected_baryonic")

    # convert to mDM-xsec plane
    tgraph_obs_new = {}
    tgraph_exp_new = {}
    for channel in channels:
      tgraph_obs_new[channel] = TGraph()
      tgraph_exp_new[channel] = TGraph()
      self.__convert__(tgraph_obs[channel],tgraph_obs_new[channel])
      self.__convert__(tgraph_exp[channel],tgraph_exp_new[channel])

    # extrapolate
    if options.do_ext:
      self.__extrapolate__(tgraph_obs_new, channels, 1)
      self.__extrapolate__(tgraph_exp_new, channels, 1)

    # canvas
    C = TCanvas("C","C",1000,600)
    C.Divide(2)
    C.cd(1).SetPad(0.0,0,0.75,1.0)
    C.cd(1).SetLeftMargin(0.15)
    C.cd(1).SetLogx()
    C.cd(1).SetLogy()
    frame = C.cd(1).DrawFrame(1,1e-44,2000,2*1e-35)
    C.cd(1).SetTickx()
    C.cd(1).SetTicky()
    frame.SetXTitle("Dark matter mass m_{DM} [GeV]")
    frame.SetYTitle("#sigma^{SI}_{DM-nucleon} [cm^{2}]")
    frame.GetXaxis().SetTitleSize(0.045)
    frame.GetYaxis().SetTitleSize(0.045)
    frame.GetXaxis().SetTitleOffset(1.0)
    frame.GetYaxis().SetTitleOffset(1.5)
    
    # legends
    texts = []
    texts.append(add_text(0.15,0.4,0.89,0.99,"#bf{CMS} Preliminary"))

    leg1 = C.BuildLegend(0.7,0.4,0.95,0.95)
    leg1.SetBorderSize(0)
    leg1.SetTextFont(42)
    leg1.SetTextSize(0.025)
    leg1.SetTextAlign(12)
    leg1.Clear()
    if options.do_exp: 
      leg1.SetHeader("#splitline{#bf{CMS exclusion 90% CL}}{Vector med., Dirac DM; g_{ q} = 0.25, g_{ DM} = 1.0}")
    else:  
      leg1.SetHeader("#splitline{#bf{CMS observed exclusion 90% CL}}{Vector med., Dirac DM; g_{ q} = 0.25, g_{ DM} = 1.0}") 
    for channel in channels:
      if options.do_exp: 
        leg1.AddEntry(tgraph_obs_new[channel],text[channel]+" (Observed)","FL")
        leg1.AddEntry(tgraph_exp_new[channel],text[channel]+" (Expected)","L")
      else:  
        leg1.AddEntry(tgraph_obs_new[channel],text[channel],"L")

    # draw
    C.cd(2).SetPad(0.75,0.0,1.0,1.0)
    C.Update()
    C.cd(1)
    C.Update()

    gStyle.SetHatchesLineWidth(2)
    for channel in channels:
      tgraph_obs_new[channel].SetLineColor(color[channel])
      tgraph_obs_new[channel].SetFillColor(color[channel])
      tgraph_obs_new[channel].SetMarkerColor(color[channel])
      tgraph_obs_new[channel].SetFillStyle(3005)
      tgraph_obs_new[channel].SetLineWidth(203)
      tgraph_obs_new[channel].SetLineStyle(kSolid)
      tgraph_obs_new[channel].SetMarkerSize(0.1)
      tgraph_obs_new[channel].Draw("same")
    
      tgraph_exp_new[channel].SetLineColor(color[channel])
      tgraph_exp_new[channel].SetFillColor(color[channel])
      tgraph_exp_new[channel].SetMarkerColor(color[channel])
      tgraph_exp_new[channel].SetFillStyle(0)
      tgraph_exp_new[channel].SetLineWidth(4)
      tgraph_exp_new[channel].SetLineStyle(kDashed)
      if options.do_exp : tgraph_exp_new[channel].Draw("same")   

    C.cd(1).RedrawAxis()
    whichChannels = ""
    for channel in channels: 
      whichChannels += "_"
      whichChannels += channel 
    C.SaveAs(options.outdir+"SpinIndepend_MonoH"+whichChannels+"_Summary.pdf")
    C.SaveAs(options.outdir+"SpinIndepend_MonoH"+whichChannels+"_Summary.png")

# --- Call
if __name__ == "__main__":
  app = PlotMaker()
  app.run()
