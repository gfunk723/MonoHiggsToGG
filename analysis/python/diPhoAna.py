import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.PythonUtilities.LumiList as LumiList  
import FWCore.ParameterSet.Types as CfgTypes  

######################
# SET THESE BOOLS BEFORE RUNNING:
isMC  = True; 
isSMh = False;
is80X = True;
is76X = False;
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

#-----------------------------------
# Pick up GlobalTag
if (isMC):
    if (is80X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '80X_mcRun2_asymptotic_2016_v3', '')
        print "80X_mcRun2_asymptotic_2016_v3"
    elif (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_mcRun2_asymptotic_v12', '')
        print "76X_mcRun2_asymptotic_v12"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_mcRun2_asymptotic_v2', '')
        print "74X_mcRun2_asymptotic_v2"
     
else:
    if (is80X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v8', '')
        print "80X_dataRun2_Prompt_v8"
    elif (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_dataRun2_v15', '')
        print "76X_dataRun2_v15"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v2', '')
        print "74X_dataRun2_Prompt_v2"
#-----------------------------------

#-----------------------------------
# Pick up Trigger Info
if (is80X):
    if (isSMh):
        bit = 'TriggerResults::HLT2'
        print "Using HLT2"
    else:
        bit = 'TriggerResults::HLT'
        print "Using HLT" 
else:
    bit = 'TriggerResults::HLT'
    print "Using HLT"


if (isMC and isFLASHgg_1_1_0):
    flag = 'TriggerResults::PAT'
    print "Using name PAT"
else: 
    flag = 'TriggerResults::RECO'
    print "Using name RECO"
#-----------------------------------


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 100 ) )

process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
	#"file:myMicroAODOutputFile.root"

	# 80X
	#"/store/user/mzientek/flashgg/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2/2_2_0/GluGluHToGG_M-125_13TeV_powheg_pythia8/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2-2_2_0-v0-RunIISpring16MiniAODv2-PUSpring16RAWAODSIM_reHLT_80X_mcRun2_asymptotic_v14-v1/161010_141021/0000/myMicroAODOutputFile_1.root"
	"/store/user/mzientek/flashgg/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2/2_2_0/ZprimeToA0hToA0chichihAA_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2-2_2_0-v0-Run2016B-PromptReco-v1/161010_131921/0000/myMicroAODOutputFile_2.root",
	#"/store/user/soffi/flashgg/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2/2_2_0/DoubleEG/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2-2_2_0-v0-Run2016E-PromptReco-v2/161014_134303/0000/myMicroAODOutputFile_1.root",
      	)
    )

if (isMC==False):
    print "applying 2016 json"                                
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

    era = "Spring16_25nsV6"
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
                                  VertexTag 		= cms.untracked.InputTag('offlineSlimmedPrimaryVertices'),
				  METTag		= cms.untracked.InputTag('flashggMets::FLASHggMicroAOD'),#
				  pfcands		= cms.InputTag("packedPFCandidates"),
                                  JetCorrectorTag	= cms.InputTag("ak4PFCHSL1FastjetCorrector"),
                                  inputTagJets		= UnpackedJetCollectionVInputTag,            
                                  ElectronTag		= cms.InputTag('flashggSelectedElectrons'),    
                                  MuonTag		= cms.InputTag('flashggSelectedMuons'),            
                                  bTag 			= cms.untracked.string(flashggBTag),                
				  RhoTag		= cms.InputTag('fixedGridRhoAll'),
                                  genPhotonExtraTag 	= cms.InputTag("flashggGenPhotonsExtra"),    
                                  DiPhotonTag 		= cms.untracked.InputTag('flashggDiPhotons0vtx'),
                                  #DiPhotonTag 		= cms.untracked.InputTag('flashggDiPhotons'),
                                  DiPhotonBDTVtxTag 	= cms.untracked.InputTag('flashggDiPhotons'),
                                  PileUpTag 		= cms.untracked.InputTag('slimmedAddPileupInfo'),
                                  generatorInfo 	= cms.InputTag('generator'),
                                  dopureweight 		= cms.untracked.int32(1),
                                  bits         		= cms.InputTag(bit),
                                  flags        		= cms.InputTag(flag),
				  sampleIndex  		= cms.untracked.int32(100),
                                  puWFileName  		= cms.string('/afs/cern.ch/user/m/mzientek/public/pileupWeights_80X_v0.root'),  
                                  xsec         		= cms.untracked.double(1), #pb
                                  kfac         		= cms.untracked.double(1.),
                                  sumDataset   		= cms.untracked.double(1.0),   # chiara
                                  )

#process.p = cms.Path( process.diPhoAna )     
if (isMC==True):
    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSL1FastL2L3Corrector*process.diPhoAna )     
if (isMC==False):
    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSResidualCorrector*process.ak4PFCHSL1FastL2L3ResidualCorrector*process.diPhoAna )     

