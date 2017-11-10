import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.PythonUtilities.LumiList as LumiList  
import FWCore.ParameterSet.Types as CfgTypes  

######################
# SET THESE BOOLS BEFORE RUNNING:
isMC  = True; 
isSMh = False;
is80X = False;
isMoriond17 = True;
isRunB = False;
isRunH = False;
is76X = False;
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
    if (isMoriond17):
        process.GlobalTag = GlobalTag(process.GlobalTag, '80X_mcRun2_asymptotic_2016_TrancheIV_v6', '') 
        print "80X_mcRun2_asymptotic_2016_TrancheIV_v6"
    elif (is80X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '80X_mcRun2_asymptotic_v14', '')
        print "80X_mcRun2_asymptotic_v14"
    elif (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_mcRun2_asymptotic_v12', '')
        print "76X_mcRun2_asymptotic_v12"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_mcRun2_asymptotic_v2', '')
        print "74X_mcRun2_asymptotic_v2"
     
else:
    if (isMoriond17):
        process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v7', '') 
        print "80X_dataRun2_2016SeptRepro_v7"
    elif (is80X):
	if (isRunB): 
            process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v4', '') 
            print "80X_dataRun2_2016SeptRepro_v4"
	elif (isRunH): #runh
            process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v14', '') 
            print "80X_dataRun2_Prompt_v14"
	else: #runc,d,e,f,g 
            process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v3', '') 
            print "80X_dataRun2_2016SeptRepro_v3"
    elif (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_dataRun2_v15', '')
        print "76X_dataRun2_v15"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v2', '')
        print "74X_dataRun2_Prompt_v2"
#-----------------------------------

#-----------------------------------
# Pick up Trigger Info
if (is80X or isMoriond17):
    if (isSMh):
        bit = 'TriggerResults::HLT2'
        print "Using HLT2"
    else:
        bit = 'TriggerResults::HLT'
        print "Using HLT" 
else:
    bit = 'TriggerResults::HLT'
    print "Using HLT"

if (isMC):
    flag = 'TriggerResults::PAT'
    print "Using TriggerResults::PAT"
else:
    flag = 'TriggerResults::RECO'
    print "Using TriggerResults::RECO"
   
#-----------------------------------


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 50 ) )

process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
	#"file:myMicroAODOutputFile.root"
	# Moriond17
	#"/store/user/soffi/RunIISummer16-2_4_1-25ns_Moriond17_DMHiggs_8026/2_4_1/MonoHaa_Scalar_MZp-10_MChi-1_13TeV-madgraph/RunIISummer16-2_4_1-25ns_Moriond17_DMHiggs_8026-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170211_234728/0000/myMicroAODOutputFile_2.root" 
	"/store/group/phys_higgs/cmshgg/soffi/RunIISummer16-2_4_2-25ns_Moriond17_AdditionalSignals0413/2_4_1/ZprimeToA0hToA0chichihAA_2HDM_MZp-1000_MA0-700_13TeV-madgraph/RunIISummer16-2_4_2-25ns_Moriond17_AdditionalSignals0413-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170413_124341/0000/myMicroAODOutputFile_1.root", 
	#"/store/user/soffi/RunIISummer16-2_4_2-25ns_Moriond17_AdditionalSignals0412/2_4_1/ZprimeToA0hToA0chichihAA_2HDM_MZp-1000_MA0-700_13TeV-madgraph/RunIISummer16-2_4_2-25ns_Moriond17_AdditionalSignals0412-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170412_122508/0000/myMicroAODOutputFile_2.root" 
	#"root://xrootd-cms.infn.it//store/user/soffi/RunIISummer16-2_4_2-25ns_Moriond17_AdditionalSignals0412/2_4_1/ZprimeToA0hToA0chichihAA_2HDM_MZp-1000_MA0-700_13TeV-madgraph/RunIISummer16-2_4_2-25ns_Moriond17_AdditionalSignals0412-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170412_122508/0000/myMicroAODOutputFile_1.root"
	#"/store/user/soffi/RunIISummer16-2_4_2-25ns_Moriond17_DMHiggs_2HDM/2_4_1/ZprimeToA0hToA0chichihAA_2HDM_MZp-1000_MA0-500_13TeV-madgraph/RunIISummer16-2_4_2-25ns_Moriond17_DMHiggs_2HDM-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170207_231248/0000/myMicroAODOutputFile_1.root" 
	#"/store/user/soffi/RunIISummer16-2_4_1-25ns_Moriond17_DMHiggs_8026/2_4_1/MonoHaa_ZpBaryonic_MZp-10_MChi-1_13TeV-madgraph/RunIISummer16-2_4_1-25ns_Moriond17_DMHiggs_8026-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/170212_004634/0000/myMicroAODOutputFile_2.root" 
	#"/store/user/soffi/RunIISummer16-2_4_1-25ns_Moriond17_ReMiniAODForDMHiggs/2_4_1/DoubleEG/RunIISummer16-2_4_1-25ns_Moriond17_ReMiniAODForDMHiggs-2_4_1-v0-Run2016E-03Feb2017-v1/170212_112353/0000/myMicroAODOutputFile_457.root",
	#"/store/user/soffi/RunIISummer16-2_4_1-25ns_Moriond17_ReMiniAODForDMHiggs/2_4_1/DoubleEG/RunIISummer16-2_4_1-25ns_Moriond17_ReMiniAODForDMHiggs-2_4_1-v0-Run2016C-03Feb2017-v1/170212_112044/0000/myMicroAODOutputFile_113.root"
	#"/store/user/soffi/RunIISummer16-2_4_1-25ns_Moriond17_DMHiggs_8026/2_4_1/MonoHaa_Scalar_MZp-10000_MChi-1000_13TeV-madgraph/RunIISummer16-2_4_1-25ns_Moriond17_DMHiggs_8026-2_4_1-v0-RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/170211_232122/0000/myMicroAODOutputFile_1.root"
	# 80X_v1
	#"/store/user/soffi/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco/2_3_0/DoubleEG/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco-2_3_0-v0-Run2016B-23Sep2016-v3/161114_221821/0002/myMicroAODOutputFile_2049.root"
	#"/store/user/soffi/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco/2_3_0/DoubleEG/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco-2_3_0-v0-Run2016D-23Sep2016-v1/161116_135323/0000/myMicroAODOutputFile_727.root"
	#"/store/user/soffi/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco/2_3_0/WGToLNuG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco-2_3_0-v0-RunIISpring16MiniAODv2-PUSpring16_80X_mcRun2_asymptotic_2016_miniAODv2_v0-v1/161120_090522/0000/myMicroAODOutputFile_1.root", 
	#"/store/user/mzientek/flashgg/RunIISpring16DR80X-2_3_0/ZprimeToA0hToA0chichihAA_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/RunIISpring16DR80X-2_3_0/161117_093950/0000/myMicroAODOutputFile_1.root", 
	#"/store/user/soffi/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco/2_3_0/DoubleEG/RunIISpring16DR80X-2_3_0-25ns_PostICHEPReReco-2_3_0-v0-Run2016H-23Sep2016-v1-NewJSON/161123_131657/0000/myMicroAODOutputFile_1.root" 
	#"/store/user/mzientek/flashgg/RunIISpring16DR80X-2_3_0/MonoHaa_ZpBaryonic_MZp-100_MChi-10_13TeV-madgraph/RunIISpring16DR80X-2_3_0/161117_092117/0000/myMicroAODOutputFile_1.root", 
	# 80X_v0
	#"/store/user/mzientek/flashgg/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2/2_2_0/ZprimeToA0hToA0chichihAA_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/RunIISpring16DR80X-2_2_0-25ns_ICHEP16_MiniAODv2-2_2_0-v0-Run2016B-PromptReco-v1/161010_131921/0000/myMicroAODOutputFile_2.root",
      	)
    )

if (isMC==False):
    print "applying 2016 json"                                
    process.source.lumisToProcess = CfgTypes.untracked(CfgTypes.VLuminosityBlockRange())  
    #JSONfile = '/afs/cern.ch/user/m/mzientek/public/processedANDgolden_80X_v1.json'
    JSONfile = '/afs/cern.ch/user/m/mzientek/public/processedANDgolden_moriond17_v0.json'
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
from flashgg.MicroAOD.flashggDiPhotons_cfi import flashggDiPhotonsLite
process.flashggDiPhotonsVtx0 = flashggDiPhotonsLite.clone(VertexSelectorName="FlashggZerothVertexSelector",whichVertex=cms.uint32(0))
#from flashgg.MicroAOD.flashggDiPhotons_cfi import flashggDiPhotons
#process.flashggDiPhotonsVtx0 = flashggDiPhotons.clone(VertexSelectorName="FlashggZerothVertexSelector",whichVertex=cms.uint32(0))
sourcediphotons = "flashggDiPhotonsVtx0"

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
process.content = cms.EDAnalyzer("EventContentAnalyzer")

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
                                  dopureweight 		= cms.untracked.int32(1),
                                  bits         		= cms.InputTag(bit),
                                  flags        		= cms.InputTag(flag),
				  sampleIndex  		= cms.untracked.int32(101),
                                  puWFileName  		= cms.string('/afs/cern.ch/user/m/mzientek/public/pileupWeights_moriond17_v2.root'),
                                  SSRewFileName         = cms.string('/afs/cern.ch/user/s/soffi/public/transformation_Moriond17_AfterPreApr_v1.root'), 
                                  corrFileName		= cms.string('EgammaAnalysis/ElectronTools/data/ScalesSmearings/Moriond17_74x_pho'),
                                  kfac         		= cms.untracked.double(1.),
                                  sumDataset   		= cms.untracked.double(1.0), 
                                  )

process.p = cms.Path( process.content*process.flashggDiPhotonsVtx0*process.flashggUnpackedJets*process.diPhoAna )     
#process.p = cms.Path( process.diPhoAna )     

#if (isMC==True):
#    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSL1FastL2L3Corrector*process.diPhoAna )     
#if (isMC==False):
#    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSResidualCorrector*process.ak4PFCHSL1FastL2L3ResidualCorrector*process.diPhoAna )     
#
