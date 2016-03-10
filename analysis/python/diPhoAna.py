import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.PythonUtilities.LumiList as LumiList  
import FWCore.ParameterSet.Types as CfgTypes  

######################
# SET THESE BOOLS BEFORE RUNNING:
isMC = True; 
is76X = False; #CANNOT RUN ON 76X in 74X
isFLASHgg_1_1_0 = False;
######################

process = cms.Process("diPhoAna")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")

from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag.globaltag = 'POSTLS170_V5::All'     # Phys14 samples
#process.GlobalTag.globaltag = 'MCRUN2_74_V9A'         # 50ns

# Pick up GlobalTag
if (isMC):
    if (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_mcRun2_asymptotic_v12', '') 
        print "76X_mcRun2_asymptotic_v12"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_mcRun2_asymptotic_v2', '') 
        print "74X_mcRun2_asymptotic_v2"
         
else:
    if (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_dataRun2_v15', '') 
        print "76X_dataRun2_v15"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v2', '') 
        print "74X_dataRun2_Prompt_v2"


if (isMC and isFLASHgg_1_1_0):
    flag = 'TriggerResults::PAT'
    print "Using name PAT"
else: 
    flag = 'TriggerResults::RECO'
    print "Using name RECO"


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 2000 ) )

process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
	"/store/group/soffi/DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162339/0000/myMicroAODOutputFile_1.root",
	#"/store/group/soffi/QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_163000/0000/myMicroAODOutputFile_1.root", 
	#"/store/group/soffi/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162546/0000/myMicroAODOutputFile_1.root", 
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_1.root", 
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_10.root",
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_100.root",
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_101.root", 
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_102.root",
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_103.root",
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_104.root",
	#"/store/group/soffi/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160211_153452/0000/myMicroAODOutputFile_105.root",

	#"/store/user/soffi/MonoHgg_2HDM_MZP1000_MA0300_13TeV/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_173214/0000/myMicroAODOutputFile_1.root", 
	#GluGluH
	#"/store/group/soffi/GluGluHToGG_M-125_13TeV_powheg_pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162649/0000/myMicroAODOutputFile_1.root" 
	#"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/GluGluHToGG_M-125_13TeV_powheg_pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223154/0000/myMicroAODOutputFile_5.root",
        #New MET syst livia
	#'/store/group/soffi/GluGluHToGG_M-125_13TeV_powheg_pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162649/0000/myMicroAODOutputFile_1.root'
        #"/store/group/soffi/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162546/0000/myMicroAODOutputFile_1.root"
        #old seth
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_222944/0000/myMicroAODOutputFile_1.root"
        #***************************************************test file synchronyzation***************************************************
        #data
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_1.root" ,
        #QCD 40 inf
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223606/0000/myMicroAODOutputFile_1.root" 
        #QCD 30 inf
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/QCD_Pt-30toInf_DoubleEMEnriched_MGG-40to80_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223522/0000/myMicroAODOutputFile_1.root"
        #QCD30-40
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/QCD_Pt-30to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223444/0000/myMicroAODOutputFile_1.root"
        #gjet 40 inf
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223028/0000/myMicroAODOutputFile_1.root"
        #gjet 20-40
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_222944/0000/myMicroAODOutputFile_1.root"
        #diphoton
        #"/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_222618/0000/myMicroAODOutputFile_1.root"
      )
                            )
if (isMC==False):
    print "applying 2015D json"                                
    process.source.lumisToProcess = CfgTypes.untracked(CfgTypes.VLuminosityBlockRange())  
    JSONfile = '/afs/cern.ch/user/m/mzientek/public/goldenAndProcessed.json'
    myLumis = LumiList.LumiList(filename = JSONfile).getCMSSWString().split(',')  
    process.source.lumisToProcess.extend(myLumis)                              
    print myLumis 

process.load("flashgg/MicroAOD/flashggPhotons_cfi")
process.load("flashgg/MicroAOD/flashggDiPhotons_cfi")

process.TFileService = cms.Service("TFileService",fileName = cms.string("diPhotons.root"))

process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound')
)

# to make jets
#================================ Get the most recent JEC ==================================================================#
    # Setup the private SQLite -- Ripped from PhysicsTools/PatAlgos/test/corMETFromMiniAOD.py
usePrivateSQlite=True
applyL2L3Residuals = True

if usePrivateSQlite:
    from CondCore.DBCommon.CondDBSetup_cfi import *
    import os

    era = "Summer15_25nsV7"
    if isMC : 
        era += "_MC"
    else :
        era += "_DATA"
    dBFile = os.path.expandvars("/afs/cern.ch/user/m/mzientek/public/"+era+".db")

    if usePrivateSQlite:
        process.jec = cms.ESSource("PoolDBESSource",
                                   CondDBSetup,
                                   connect = cms.string("sqlite_file:"+dBFile),
                                   toGet =  cms.VPSet(
                cms.PSet(
                    record = cms.string("JetCorrectionsRecord"),
                    tag = cms.string("JetCorrectorParametersCollection_"+era+"_AK4PF"),
                    label= cms.untracked.string("AK4PF")
                    ),
                cms.PSet(
                        record = cms.string("JetCorrectionsRecord"),
                        tag = cms.string("JetCorrectorParametersCollection_"+era+"_AK4PFchs"),
                        label= cms.untracked.string("AK4PFchs")
                        ),
                )
                                   )
        process.es_prefer_jec = cms.ESPrefer("PoolDBESSource",'jec')
#===========================================================================================================================#

#============================================Re do jets + JEC===================================================================#

from flashgg.MicroAOD.flashggJets_cfi import flashggBTag, maxJetCollections
process.flashggUnpackedJets = cms.EDProducer("FlashggVectorVectorJetUnpacker",  
                                             JetsTag = cms.InputTag("flashggFinalJets"),          
                                             NCollections = cms.uint32(maxJetCollections) 
                                             )               


process.load('JetMETCorrections.Configuration.JetCorrectors_cff')
if isMC:
    JECLevels = ['L1FastJet', 'L2Relative', 'L3Absolute']
else :
    if not applyL2L3Residuals : 
        JECLevels = ['L1FastJet', 'L2Relative', 'L3Absolute']
    else : 
        JECLevels = ['L1FastJet', 'L2Relative', 'L3Absolute', 'L2L3Residual']

from PhysicsTools.PatAlgos.producersLayer1.jetUpdater_cff import patJetCorrFactorsUpdated
process.patJetCorrFactorsReapplyJEC = patJetCorrFactorsUpdated.clone(
    src = cms.InputTag("flashggUnpackedJets"),
    levels = JECLevels,
    payload = 'AK4PFchs' 
)

from PhysicsTools.PatAlgos.producersLayer1.jetUpdater_cff import patJetsUpdated
process.flashggUnpackedJetsRecorrected = patJetsUpdated.clone(
    jetSource = cms.InputTag("flashggUnpackedJets"),
    jetCorrFactorsSource = cms.VInputTag(cms.InputTag("patJetCorrFactorsReapplyJEC"))
)


UnpackedJetCollectionVInputTag = cms.VInputTag()       
for i in range(0,maxJetCollections):    
    UnpackedJetCollectionVInputTag.append(cms.InputTag('flashggUnpackedJetsRecorrected',str(i)))  
#===========================================================================================================================#


process.diPhoAna = cms.EDAnalyzer('NewDiPhoAnalyzer',
                                  VertexTag = cms.untracked.InputTag('offlineSlimmedPrimaryVertices'),
				  METTag=cms.untracked.InputTag('slimmedMETs::FLASHggMicroAOD'),
                                  inputTagJets= UnpackedJetCollectionVInputTag,            
                                  ElectronTag=cms.InputTag('flashggSelectedElectrons'),    
                                  MuonTag=cms.InputTag('flashggSelectedMuons'),            
                                  bTag = cms.untracked.string(flashggBTag),                
                                  genPhotonExtraTag = cms.InputTag("flashggGenPhotonsExtra"),    
                                  DiPhotonTag = cms.untracked.InputTag('flashggDiPhotons'),
                                  PileUpTag = cms.untracked.InputTag('slimmedAddPileupInfo'),
                                  generatorInfo = cms.InputTag("generator"),
                                  dopureweight = cms.untracked.int32(1),
                                  bits         = cms.InputTag('TriggerResults::HLT'),
                                  flags        = cms.InputTag(flag),
				  sampleIndex  = cms.untracked.int32(100),
                                  puWFileName  = cms.string('/afs/cern.ch/user/m/mzientek/public/pileupWeights_fullReReco74X.root'),  
                                  xsec         = cms.untracked.double(1), #pb
                                  kfac         = cms.untracked.double(1.),
                                  sumDataset   = cms.untracked.double(1.0),   # chiara
                                  )

#process.p = cms.Path( process.diPhoAna )     
process.p = cms.Path(process.flashggUnpackedJets*process.diPhoAna )     
