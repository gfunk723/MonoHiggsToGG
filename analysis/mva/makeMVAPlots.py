#!/bin/env python

from utils.pyapp import * 
from optparse import OptionParser, make_option

# ----------------------------------------------------------------
# --- Setup main options
# ----------------------------------------------------------------
class PlotMaker(pyapp):

  def __init__(self):
    # --- Additional options
    super(PlotMaker,self).__init__(option_list=[
      make_option("--mva",action="store",dest="mvatype",type="string",
                  default="SVM",help="Input type of MVA [default = %default]"),
      make_option("-i",action="store",dest="infile",type="string",
                  default="",help="Input file [default = %default]"),
      make_option("--suffix",action="store",dest="suffix",type="string",
                  default="",help="Additional suffix [default = %default]"),
      ])
       
    global ROOT
    import sys, os, numpy, ROOT
    from optparse import OptionParser
    ROOT.gStyle.SetOptStat(0)
    ROOT.gStyle.SetOptTitle(0)

  def __call__(self,options,args):
    print("Making plots for : %s" %options.mvatype)
    fin     = ROOT.TFile.Open(options.infile)
    fout    = ROOT.TFile.Open(options.outdir+'plotsMVAstudies_'+options.mvatype+''+options.suffix+'.root','RECREATE')

    addtree = ''
    if self.options.mvatype == 'DNN':
      addtree = 'dataset/'
  
    # --- Pick out different trees
    MVATree   = addtree+'Method_'+options.mvatype+'/'+options.mvatype+'/'
    TestTree  = fin.Get(addtree+'TestTree')
    TrainTree = fin.Get(addtree+'TrainTree')
  
    # --- Pick out the histograms 
    h_corr_sig  = ROOT.TH2F(fin.Get(addtree+'CorrelationMatrixS'))
    h_corr_bkg  = ROOT.TH2F(fin.Get(addtree+'CorrelationMatrixB'))
    h_train_ROC = ROOT.TH1D(fin.Get(MVATree+'MVA_'+options.mvatype+'_trainingRejBvsS'))
    h_test_ROC  = ROOT.TH1D(fin.Get(MVATree+'MVA_'+options.mvatype+'_rejBvsS'))
    # --- Make classifier histograms
    h_train_S   = ROOT.TH1D('h_train_S','S (Train)',40,0.0,1.0)
    h_train_B   = ROOT.TH1D('h_train_B','B (Train)',40,0.0,1.0)
    h_test_S    = ROOT.TH1D('h_test_S','S (Test)',40,0.0,1.0)
    h_test_B    = ROOT.TH1D('h_test_B','B (Test)',40,0.0,1.0)
    scut = 'classID>0.5'
    bcut = 'classID<0.5'
    TrainTree.Project("h_train_S",options.mvatype,scut)
    TrainTree.Project("h_train_B",options.mvatype,bcut)
    TrainTree.Project("h_test_S",options.mvatype,scut)
    TrainTree.Project("h_test_B",options.mvatype,bcut)  
  
    # --- Draw each plot with right styling 
    self.plotROCcurve(options,h_train_ROC,h_test_ROC)                  # ROC 
    self.plotCorrelations(options,h_corr_sig,'S')                      # CorrS
    self.plotCorrelations(options,h_corr_bkg,'B')                      # CorrB
    self.plotClassifier(options,h_train_S,h_train_B,h_test_S,h_test_B) # Classifier 


  def plotROCcurve(self,options,h_train_ROC,h_test_ROC):
    c1 = ROOT.TCanvas("c1","",600,600)
    c1.cd()
  
    int_train = h_train_ROC.Integral()
    int_test  = h_test_ROC.Integral()
    rnd_train = "%3.3f" %int_train
    rnd_test  = "%3.3f" %int_test
  
    h_train_ROC.SetLineColor(2)
    h_train_ROC.SetLineStyle(2)
    h_test_ROC.SetLineColor(2)
    h_test_ROC.SetLineStyle(1)
    
    h_train_ROC.GetXaxis().SetTitle('Signal Efficiency')
    h_train_ROC.GetYaxis().SetTitle('Background Rejection (1-Eff)')
    h_train_ROC.SetMaximum(1.1)
    h_train_ROC.SetMinimum(0.0)
    h_train_ROC.GetXaxis().SetRangeUser(0.0,1.1)
    
    h_train_ROC.Draw('HIST')
    h_test_ROC.Draw('HIST SAME')
    l = ROOT.TLegend(0.2,0.2,0.6,0.32,"","brNDC")
    l.SetBorderSize(0)
    l.AddEntry(h_train_ROC,"Train Sample, AUC = "+str(rnd_train),"L")
    l.AddEntry(h_test_ROC,"Test Sample, AUC = "+str(rnd_test),"L")
    l.Draw('SAME')
    
    c1.Print(options.outdir+'plot_ROC_'+options.mvatype+''+options.suffix+'.png')
    c1.Print(options.outdir+'plot_ROC_'+options.mvatype+''+options.suffix+'.pdf')
    h_train_ROC.Write()
    h_test_ROC.Write()

  def plotCorrelations(self,options,h_corr,which):
    c2 = ROOT.TCanvas("c2"+which,"",600,600)
    c2.cd()
    
    h_corr.Draw("COLZ")
    c2.Print(options.outdir+'plot_Corr'+which+'_'+options.mvatype+''+options.suffix+'.png') 
    c2.Print(options.outdir+'plot_Corr'+which+'_'+options.mvatype+''+options.suffix+'.pdf') 
    h_corr.Write()
   
  def plotClassifier(self,options,h_train_S,h_train_B,h_test_S,h_test_B):
    c3 = ROOT.TCanvas("c3","",600,600)
    c3.cd()
  
    h_train_S.SetLineColor(2)
    h_train_S.SetMarkerColor(2)
    h_train_S.SetFillColor(2)
    h_train_S.SetFillStyle(3001)
    h_test_S.SetLineColor(2)
    h_test_S.SetMarkerColor(2)
    h_test_S.SetMarkerStyle(20)
  
    h_train_B.SetLineColor(4)
    h_train_B.SetMarkerColor(4)
    h_train_B.SetFillColor(4)
    h_train_B.SetFillStyle(3001) 
    h_test_B.SetLineColor(4)
    h_test_B.SetMarkerColor(4)
    h_test_B.SetMarkerStyle(20)
    
    h_train_S.GetXaxis().SetTitle('Classifier, '+options.mvatype)
    h_train_S.GetYaxis().SetTitle('Counts/Bin')
    ymax = max([h.GetMaximum() for h in [h_train_S,h_train_B,h_test_S,h_test_B] ])
    ymax *=1.2
    h_train_S.SetMaximum(ymax)
  
    l3 = ROOT.TLegend(0.42,0.72,0.57,0.88,"","brNDC")
    l3.SetBorderSize(0)
    l3.AddEntry(h_train_S,"S (Train)","LF")
    l3.AddEntry(h_train_B,"B (Train)","LF")
    l3.AddEntry(h_test_S,"S (Test)","EPL")
    l3.AddEntry(h_test_B,"B (Test)","EPL")
  
    h_train_S.Draw('HIST')
    h_train_B.Draw('HIST SAME')
    h_test_S.Draw('EP SAME')
    h_test_B.Draw('EP SAME')
    l3.Draw('SAME')
    c3.Print(options.outdir+'plot_Classifier_'+options.mvatype+''+options.suffix+'.png')
    c3.Print(options.outdir+'plot_Classifier_'+options.mvatype+''+options.suffix+'.pdf')
    h_train_S.Write()
    h_train_B.Write()
    h_test_S.Write()
    h_test_B.Write()


if __name__ == "__main__": 
  app = PlotMaker()
  app.run()

