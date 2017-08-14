Examples TMVA comes from:
- SVN: https://dbaumgartel.wordpress.com/2014/03/14/machine-learning-examples-scikit-learn-versus-tmva-cern-root/
- DNN: http://oproject.org/DeepLearning

To run the MVAs: 
- `python makeSVNtest.py`       : SVN example
- `root -l -b -q makeDNNtest.C` : DNN example (needs at least CMSSW_92X) 

Run SVN with batch:
`bsub -q 2nw jobscript.sh`

To make plots for the MVA (use makeMVAPlots.py with various options): 
- `python makeMVAPlots.py --mva DNN -i TMVA_DNN_BARY.root -O ~/www/Plots/MonoHgg2017/MVAplots/ --suffix "_BARY" `
