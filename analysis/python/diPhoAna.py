import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.PythonUtilities.LumiList as LumiList  
import FWCore.ParameterSet.Types as CfgTypes  
import FWCore.ParameterSet.VarParsing as VarParsing

process = cms.Process("diPhoAna")
process.load("FWCore.MessageService.MessageLogger_cfi")

# Setup input variables
options = VarParsing.VarParsing('analysis')
options.register ('isMC',
                  False, # default value
                  VarParsing.VarParsing.multiplicity.singleton, # singleton or list
                  VarParsing.VarParsing.varType.bool,           # string, int, float, bool
                  "Bool isMC")
options.register ('useVtx0',
                  True, # default value
                  VarParsing.VarParsing.multiplicity.singleton, # singleton or list
                  VarParsing.VarParsing.varType.bool,           # string, int, float, bool
                  "Bool useVtx0")
options.parseArguments()

if options.isMC: print'Sample is MC'
else:            print'Sample is Data'

# Pick up the GlobalTag
from Configuration.AlCa.GlobalTag import GlobalTag
process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
from Configuration.AlCa.autoCond import autoCond
if options.isMC:
   process.GlobalTag = GlobalTag(process.GlobalTag, autoCond['run2_mc'].replace("::All","") )
else:
   process.GlobalTag = GlobalTag(process.GlobalTag, autoCond['run2_data'].replace("::All","") )

# Do pileup reweighting
if options.isMC: do_pu = 1
else:            do_pu = 0

# Set sample index (testing only)
if options.isMC: index = 101
else:            index = 10001

# Pick up trigger info
if options.isMC: 
   bit  = 'TriggerResults::HLT'
   flag = 'TriggerResults::PAT'
else:
   bit  = 'TriggerResults::HLT'
   flag = 'TriggerResults::RECO' 

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 10 ) )

process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
	#"file:myMicroAODOutputFile.root"
        # 2017 test
        "/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIIFall17-2_7_5/2_7_5/DoubleEG/RunIIFall17-2_7_5-2_7_5-v0-Run2017C-PromptReco-v1/171030_113309/0000/myMicroAODOutputFile_1.root",
      	)
    )

if (isMC==False):
    print "applying 2017 json"                                
    process.source.lumisToProcess = CfgTypes.untracked(CfgTypes.VLuminosityBlockRange()) 
    JSONfile = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/PromptReco/Cert_294927-305636_13TeV_PromptReco_Collisions17_JSON.txt' 
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

# get vtx0 diphoton collection
if options.useVtx0:
    from flashgg.MicroAOD.flashggDiPhotons_cfi import flashggDiPhotonsLite
    process.flashggDiPhotonsVtx0 = flashggDiPhotonsLite.clone(VertexSelectorName="FlashggZerothVertexSelector",whichVertex=cms.uint32(0))
    sourcediphotons = "flashggDiPhotonsVtx0"
else: sourcediphotons = "flashggDiPhotons" # BDT photons

# to make jets
from flashgg.MicroAOD.flashggJets_cfi import flashggBTag, maxJetCollections
process.flashggUnpackedJets = cms.EDProducer("FlashggVectorVectorJetUnpacker",  
                                             JetsTag = cms.InputTag("flashggFinalJets"),          
                                             NCollections = cms.uint32(maxJetCollections) 
                                             )               

UnpackedJetCollectionVInputTag = cms.VInputTag()       
for i in range(0,maxJetCollections):    
    UnpackedJetCollectionVInputTag.append(cms.InputTag('flashggUnpackedJets',str(i)))  

## check the event content 
#process.content = cms.EDAnalyzer("EventContentAnalyzer")

process.diPhoAna = cms.EDAnalyzer('DiPhoAnalyzer_Moriond17',
                                  VertexTag 		= cms.untracked.InputTag('offlineSlimmedPrimaryVertices'),
				  METTag		= cms.untracked.InputTag('flashggMets::FLASHggMicroAOD'),#
				  pfcands		= cms.InputTag("packedPFCandidates"),
                                  inputTagJets		= UnpackedJetCollectionVInputTag,            
                                  ElectronTag		= cms.InputTag('flashggSelectedElectrons'),    
                                  MuonTag		= cms.InputTag('flashggSelectedMuons'),            
                                  bTag 			= cms.untracked.string(flashggBTag),                
				  RhoTag		= cms.InputTag('fixedGridRhoAll'),
                                  genPhotonExtraTag 	= cms.InputTag("flashggGenPhotonsExtra"),    
                                  DiPhotonTag 		= cms.untracked.InputTag(sourcediphotons),
                                  DiPhotonBDTVtxTag     = cms.untracked.InputTag('flashggDiPhotons'),
                                  PileUpTag 		= cms.untracked.InputTag('slimmedAddPileupInfo'),
                                  generatorInfo 	= cms.InputTag('generator'),
                                  dopureweight 		= cms.untracked.int32(do_pu),
                                  bits         		= cms.InputTag(bit),
                                  flags        		= cms.InputTag(flag),
				  sampleIndex  		= cms.untracked.int32(index),
                                  puWFileName  		= cms.string('/afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v2.root'),
                                  SSRewFileName         = cms.string('/afs/cern.ch/user/s/soffi/public/transformation_Moriond17_AfterPreApr_v1.root'), 
                                  corrFileName		= cms.string('EgammaAnalysis/ElectronTools/data/Moriond17_74x_pho'),
                                  kfac         		= cms.untracked.double(1.),
                                  sumDataset   		= cms.untracked.double(1.0), 
                                  )

if options.useVtx0: process.p = cms.Path( process.flashggDiPhotonsVtx0*process.flashggUnpackedJets*process.diPhoAna )    
else:               process.p = cms.Path( process.flashggUnpackedJets*process.diPhoAna )   
 
