import numpy, ROOT

indir  = ''
outdir = ''
fin    = ROOT.TFile.Open(indir+'MVALearningOutput_batch.root')
fout   = ROOT.TFile.Open(outdir+'ROCcurve.root','RECREATE')

h_train_ROC = ROOT.TH1D(fin.Get('Method_SVM/SVM/MVA_SVM_trainingRejBvsS'))
h_test_ROC  = ROOT.TH1D(fin.Get('Method_SVM/SVM/MVA_SVM_rejBvsS'))

int_train = h_train_ROC.Integral()
int_test  = h_test_ROC.Integral()
rnd_train = "%3.3f" %int_train
rnd_test  = "%3.3f" %int_test

c = ROOT.TCanvas("c","",600,600)
ROOT.gStyle.SetOptStat(0)
ROOT.gStyle.SetOptTitle(0)
c.cd()
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

c.Print('plot_ROC.png')
