# import needed
import random
import numpy 
import ROOT

# Input file
#root_in_sig  = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/2HDM_mZP600_mA0300_skim_woVetos.root")
root_in_sig  = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/BaryonicZp_mZP10_mChi1_skim_woVetos.root")
root_in_bkg1 = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/DiPhoton_skim_woVetos.root")
root_in_bkg2 = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/EWKBkg_skim_woVetos.root")
root_in_bkg3 = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/GluGluHToGG_skim_woVetos.root")
root_in_bkg4 = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/VHToGG_skim_woVetos.root")
root_in_bkg5 = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/ttHJetToGG_skim_woVetos.root")
root_in_bkg6 = ROOT.TFile.Open("/afs/cern.ch/work/m/mzientek/public/25ns_v80X_MVA/VBFHToGG_skim_woVetos.root")
tree_in_sig  = root_in_sig.Get('DiPhotonTree')
tree_in_bkg1 = root_in_bkg1.Get('DiPhotonTree')
tree_in_bkg2 = root_in_bkg2.Get('DiPhotonTree')
tree_in_bkg3 = root_in_bkg3.Get('DiPhotonTree')
tree_in_bkg4 = root_in_bkg4.Get('DiPhotonTree')
tree_in_bkg5 = root_in_bkg5.Get('DiPhotonTree')
tree_in_bkg6 = root_in_bkg6.Get('DiPhotonTree')

# Ouput file
root_out = ROOT.TFile("TMVA_SVM.root","RECREATE")

# Create TMVA factory
ROOT.TMVA.Tools.Instance()
factory = ROOT.TMVA.Factory("TMVAClassification", root_out, "AnalysisType=Classification")

# Add the variables to the TMVA factory as floats
for x in ['ptgg','t1pfmetCorr','dphiggmet','dphig1met','dphig2met','detag1g2']:
  factory.AddVariable(x,"F")

# Link signal and background to root ntuple
factory.AddSignalTree(tree_in_sig)
factory.AddBackgroundTree(tree_in_bkg1)
factory.AddBackgroundTree(tree_in_bkg2)
factory.AddBackgroundTree(tree_in_bkg3)
factory.AddBackgroundTree(tree_in_bkg4)
factory.AddBackgroundTree(tree_in_bkg5)
factory.AddBackgroundTree(tree_in_bkg6)

# Cuts defining the signal and background sample
#sigCut = ROOT.TCut("truth > 0.5")
#bkgCut = ROOT.TCut("truth <= 0.5")
sigCut = ROOT.TCut("sampleID > 100")
bkgCut = ROOT.TCut("sampleID <= 100")
cut = ROOT.TCut("")
# Prepare the training/testing signal/background
#factory.PrepareTrainingAndTestTree(sigCut,bkgCut,"SplitMode=Random:NormMode=NumEvents:!V") 
factory.PrepareTrainingAndTestTree(cut,10000,50000,10000,50000,"SplitMode=Random:!V") 

# Book the SVM method and train/test
method = factory.BookMethod( ROOT.TMVA.Types.kSVM, "SVM", "C=1.0:Gamma=0.005:Tol=0.001:VarTransform=None")
factory.TrainAllMethods()
factory.TestAllMethods()
factory.EvaluateAllMethods()

## Histogram results
#Histo_training_S = ROOT.TH1D('Histo_training_S','S (Train)',40,0.0,1.0)
#Histo_training_B = ROOT.TH1D('Histo_training_B','B (Train)',40,0.0,1.0)
#Histo_testing_S = ROOT.TH1D('Histo_testing_S','S (Test)',40,0.0,1.0)
#Histo_testing_B = ROOT.TH1D('Histo_testing_B','B (Test)',40,0.0,1.0)
#
## Fetch the trees of events from the root file
#TrainTree = root_out.Get("TrainTree")
#TestTree = root_out.Get("TestTree")
#
## Cutting on these objects in the trees will allow to separate true S/B
#BCut_Tree = 'classID<0.5'
#SCut_Tree = 'classID>0.5'
#
## Now lets project the tree information into those histograms
#TrainTree.Project("Histo_training_S","SVM",SCut_Tree)
#TrainTree.Project("Histo_training_B","SVM",BCut_Tree)
#TestTree.Project("Histo_testing_S","SVM",SCut_Tree)
#TestTree.Project("Histo_testing_B","SVM",BCut_Tree)
# 
## Create the color styles
#Histo_training_S.SetLineColor(2)
#Histo_training_S.SetMarkerColor(2)
#Histo_training_S.SetFillColor(2)
#Histo_testing_S.SetLineColor(2)
#Histo_testing_S.SetMarkerColor(2)
#Histo_testing_S.SetFillColor(2)
# 
#Histo_training_B.SetLineColor(4)
#Histo_training_B.SetMarkerColor(4)
#Histo_training_B.SetFillColor(4)
#Histo_testing_B.SetLineColor(4)
#Histo_testing_B.SetMarkerColor(4)
#Histo_testing_B.SetFillColor(4)
# 
## Histogram fill styles
#Histo_training_S.SetFillStyle(3001)
#Histo_training_B.SetFillStyle(3001)
#Histo_testing_S.SetFillStyle(0)
#Histo_testing_B.SetFillStyle(0)
# 
## Histogram marker styles
#Histo_testing_S.SetMarkerStyle(20)
#Histo_testing_B.SetMarkerStyle(20)
# 
## Set titles
#Histo_training_S.GetXaxis().SetTitle("Classifier, SVM [rbf kernel, C=1, gamma=0.005]")
#Histo_training_S.GetYaxis().SetTitle("Counts/Bin")
# 
## Draw the objects
#c1 = ROOT.TCanvas("c1","",800,600)
#ROOT.gStyle.SetOptStat(0)
#ROOT.gStyle.SetOptTitle(0)
#Histo_training_S.Draw("HIST")
#Histo_training_B.Draw("HISTSAME")
#Histo_testing_S.Draw("EPSAME")
#Histo_testing_B.Draw("EPSAME")
# 
## Reset the y-max of the plot
#ymax = max([h.GetMaximum() for h in [Histo_training_S,Histo_training_B,Histo_testing_S,Histo_testing_B] ])
#ymax *=1.2
#Histo_training_S.SetMaximum(ymax)
# 
## Create Legend
#c1.cd(1).BuildLegend( 0.42,  0.72,  0.57,  0.88).SetFillColor(0)
# 
## Add custom title
#l1=ROOT.TLatex()
#l1.SetNDC();
#l1.DrawLatex(0.26,0.93,"Classification with TMVA (ROOT)")
# 
## Finally, draw the figure
#c1.Print('ROOT_example.png')
