import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.PythonUtilities.LumiList as LumiList  
import FWCore.ParameterSet.Types as CfgTypes  

######################
# SET THESE BOOLS BEFORE RUNNING:
isMC = True; 
is76X = True;
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


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 5000 ) )

process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
	#"file:myMicroAODOutputFile.root"
	# 76X
	# vtx0:
	"/store/user/mzientek/flashgg/RunIIFall15DR76-1_3_0-25ns_PrivSig/1_3_0/MonoHgg_Zp2HDM_MZP1000_13TeV_76X/RunIIFall15DR76-1_3_0-25ns_MZp-1000_MA0-300/160331_204112/0000/myMicroAODOutputFile_1.root", 
	#"/store/user/mzientek/flashgg/RunIIFall15DR76-1_3_0-25ns_Sig/1_3_0/ZprimeToA0hToA0chichihAA_2HDM_MZp-1200_MA0-300_13TeV-madgraph/RunIIFall15DR76-1_3_0-25ns_MZp-1200_MA0-300_v2/160401_091523/0000/myMicroAODOutputFile_2.root"
	#"/store/user/soffi/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_0/GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_0-v0-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/160225_095156/0000/myMicroAODOutputFile_1.root",
	#"/store/user/soffi/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_0/DiPhotonJets_MGG-80toInf_13TeV_amcatnloFXFX_pythia8/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_0-v0-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/160225_094833/0000/myMicroAODOutputFile_1.root", 
	# 74X sample for comparison
	# vtx0:
	#"/store/user/mzientek/flashgg/vtx0-RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_1/DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa/vtx0-RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_1-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160314_221441/0000/myMicroAODOutputFile_116.root",
	#"/store/user/soffi/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns_vtx0_MC/1_1_0/DoubleEG/RunIISpring15-ReMiniAOD-1_1_0-25ns_vtx0_MC-1_1_0-v0-Run2015D-04Dec2015-v2/160310_213242/0000/myMicroAODOutputFile_1.root",
	#"/store/user/soffi/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns_vtx0_signal/1_1_0/MonoHgg_2HDM_MZP600_MA0300_13TeV/RunIISpring15-ReMiniAOD-1_1_0-25ns_vtx0_signal-1_1_0-v0-soffi-2HDM_MZP600_A0300_Hgg_miniAODv2/160310_222132/0000/myMicroAODOutputFile_1.root",
	#"/store/user/mzientek/flashgg/vtx0-RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_1/GluGluHToGG_M-125_13TeV_powheg_pythia8/vtx0-RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_1-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160314_221930/0000/myMicroAODOutputFile_1.root",
	#"/store/user/soffi/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns_vtx0_signal/1_1_0/MonoHgg_2HDM_MZP600_MA0300_13TeV/RunIISpring15-ReMiniAOD-1_1_0-25ns_vtx0_signal-1_1_0-v0-soffi-2HDM_MZP600_A0300_Hgg_miniAODv2/160310_222132/0000/myMicroAODOutputFile_1.root",
 	#metSyst: 
	#"/store/group/soffi/DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162339/0000/myMicroAODOutputFile_1.root",
	#"/store/group/soffi/QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_163000/0000/myMicroAODOutputFile_1.root", 
	#"/store/group/soffi/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160211_162546/0000/myMicroAODOutputFile_1.root", 
      )
                            )
if (isMC==False):
    print "applying 2015D json"                                
    process.source.lumisToProcess = CfgTypes.untracked(CfgTypes.VLuminosityBlockRange())  
    JSONfile = '/afs/cern.ch/user/m/mzientek/public/processedANDgolden_76X_vtx0.json'
    myLumis = LumiList.LumiList(filename = JSONfile).getCMSSWString().split(',')  
    process.source.lumisToProcess.extend(myLumis)                              
    print myLumis 

process.load("flashgg/MicroAOD/flashggPhotons_cfi")
process.load("flashgg/MicroAOD/flashggDiPhotons_cfi")

process.TFileService = cms.Service("TFileService",fileName = cms.string("diPhotons.root"))

process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound')
)

process.MessageLogger.categories.extend(["GetManyWithoutRegistration","GetByLabelWithoutRegistration"])
_messageSettings = cms.untracked.PSet(
                reportEvery = cms.untracked.int32(1),
                            optionalPSet = cms.untracked.bool(True),
                            limit = cms.untracked.int32(10000000)
                        )

process.MessageLogger.cerr.GetManyWithoutRegistration = _messageSettings
process.MessageLogger.cerr.GetByLabelWithoutRegistration = _messageSettings

# to make jets
#================================ Get the most recent JEC ==================================================================#
    # Setup the private SQLite -- Ripped from PhysicsTools/PatAlgos/test/corMETFromMiniAOD.py
usePrivateSQlite=True
applyL2L3Residuals = True

if usePrivateSQlite:
    from CondCore.DBCommon.CondDBSetup_cfi import *
    import os

    era = "Fall15_25nsV2"
    if isMC : 
        era += "_MC"
    else :
        era += "_DATA"
    #dBFile = os.path.expandvars(era+".db")
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

process.ak4PFCHSL1FastjetCorrector = cms.EDProducer(
    'L1FastjetCorrectorProducer',
    level       = cms.string('L1FastJet'),
    algorithm   = cms.string('AK4PFchs'),
    srcRho      = cms.InputTag( 'fixedGridRhoFastjetAll' )
    )
process.ak4PFCHSL2RelativeCorrector = cms.EDProducer(
    'LXXXCorrectorProducer',
    level     = cms.string('L2Relative'),
    algorithm = cms.string('AK4PFchs')
    )
process.ak4PFCHSL3AbsoluteCorrector = cms.EDProducer(
    'LXXXCorrectorProducer',
    level     = cms.string('L3Absolute'),
    algorithm = cms.string('AK4PFchs')
    )
process.ak4PFCHSL1FastL2L3Corrector = cms.EDProducer(
    'ChainedJetCorrectorProducer',
    correctors = cms.VInputTag('ak4PFCHSL1FastjetCorrector','ak4PFCHSL2RelativeCorrector','ak4PFCHSL3AbsoluteCorrector')
    )

process.ak4PFCHSResidualCorrector = cms.EDProducer(
    'LXXXCorrectorProducer',
    level     = cms.string('L2L3Residual'),
    algorithm = cms.string('AK4PFchs')
    )
process.ak4PFCHSL1FastL2L3ResidualCorrector = cms.EDProducer(
    'ChainedJetCorrectorProducer',
    correctors = cms.VInputTag('ak4PFCHSL1FastjetCorrector','ak4PFCHSL2RelativeCorrector','ak4PFCHSL3AbsoluteCorrector','ak4PFCHSResidualCorrector')
    )
UnpackedJetCollectionVInputTag = cms.VInputTag()       
for i in range(0,maxJetCollections):    
    UnpackedJetCollectionVInputTag.append(cms.InputTag('flashggUnpackedJets',str(i)))  
#===========================================================================================================================#


process.diPhoAna = cms.EDAnalyzer('NewDiPhoAnalyzer',
                                  VertexTag = cms.untracked.InputTag('offlineSlimmedPrimaryVertices'),
				  METTag=cms.untracked.InputTag('slimmedMETs::FLASHggMicroAOD'),#
                                  JetCorrectorTag = cms.InputTag("ak4PFCHSL1FastjetCorrector"),
                                  inputTagJets= UnpackedJetCollectionVInputTag,            
                                  ElectronTag=cms.InputTag('flashggSelectedElectrons'),    
                                  MuonTag=cms.InputTag('flashggSelectedMuons'),            
                                  bTag = cms.untracked.string(flashggBTag),                
				  RhoTag = cms.InputTag('fixedGridRhoAll'),
                                  genPhotonExtraTag = cms.InputTag("flashggGenPhotonsExtra"),    
                                  DiPhotonTag = cms.untracked.InputTag('flashggDiPhotons0vtx'),
                                  #DiPhotonTag = cms.untracked.InputTag('flashggDiPhotons'),
                                  DiPhotonBDTVtxTag = cms.untracked.InputTag('flashggDiPhotons'),
                                  PileUpTag = cms.untracked.InputTag('slimmedAddPileupInfo'),
                                  generatorInfo = cms.InputTag('generator'),
                                  dopureweight = cms.untracked.int32(1),
                                  bits         = cms.InputTag('TriggerResults::HLT'),
                                  flags        = cms.InputTag(flag),
				  sampleIndex  = cms.untracked.int32(100),
                                  puWFileName  = cms.string('/afs/cern.ch/user/m/mzientek/public/pileupWeights_76X_vtx0.root'),  
                                  xsec         = cms.untracked.double(1), #pb
                                  kfac         = cms.untracked.double(1.),
                                  sumDataset   = cms.untracked.double(1.0),   # chiara
                                  )

#process.p = cms.Path( process.diPhoAna )     
if (isMC==True):
    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSL1FastL2L3Corrector*process.diPhoAna )     
if (isMC==False):
    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSResidualCorrector*process.ak4PFCHSL1FastL2L3ResidualCorrector*process.diPhoAna )     

