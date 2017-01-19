import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
import FWCore.PythonUtilities.LumiList as LumiList  
import FWCore.ParameterSet.Types as CfgTypes  

######################
# SET THESE BOOLS BEFORE RUNNING:
isMC  = False;
isSMh = False;
is80X = True;
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
#process.GlobalTag.globaltag = 'POSTLS170_V5::All' 	#Phys14
#process.GlobalTag.globaltag = 'MCRUN2_74_V9A' 		#50ns


#-----------------------------------
# Pick up GlobalTag
if (isMC):
    if (is80X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '80X_mcRun2_asymptotic_v14', '') 
        print "80X_mcRun2_asymptotic_v14"
    elif (is76X):
        process.GlobalTag = GlobalTag(process.GlobalTag, '76X_mcRun2_asymptotic_v12', '') 
        print "76X_mcRun2_asymptotic_v12"
    else:
        process.GlobalTag = GlobalTag(process.GlobalTag, '74X_mcRun2_asymptotic_v2', '') 
        print "74X_mcRun2_asymptotic_v2"
    
else:
    if (is80X):
	if (isRunB): 
            process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v4', '') 
            print "80X_dataRun2_2016SeptRepro_v4"
	elif (isRunH): #RunH
            process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v14', '') 
            print "80X_dataRun2_Prompt_v14"
	else: #RunC,D,E,F,G 
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
if (is80X and isSMh):
    bit = 'TriggerResults::HLT2'
    print "Using HLT2"
else:
    bit = 'TriggerResults::HLT'
    print "Using HLT"

if (isMC):
    flag = 'TriggerResults::PAT'
    print "Using name PAT"
else:
    flag = 'TriggerResults::RECO'
    print "Using name RECO"
#-----------------------------------

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( -1 ) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('/store/group/phys_higgs/cmshgg/musella/flashgg/ExoPhys14_v2/diphotonsPhys14V2/RSGravToGG_kMpl001_M_5000_Tune4C_13TeV_pythia8/ExoPhys14_v2-diphotonsPhys14V2-v0-Phys14DR-PU20bx25_PHYS14_25_V1-v1/150128_133931/0000/myOutputFile_1.root'
                           )                                   

if (isMC==False):
    print "applying 2016D json"                                
    process.source.lumisToProcess = CfgTypes.untracked(CfgTypes.VLuminosityBlockRange())  
    JSONfile = '/afs/cern.ch/user/m/mzientek/public/processedANDgolden_80X_v1.json'
    myLumis = LumiList.LumiList(filename = JSONfile).getCMSSWString().split(',')  
    process.source.lumisToProcess.extend(myLumis)  

process.load("flashgg/MicroAOD/flashggPhotons_cfi")
process.load("flashgg/MicroAOD/flashggDiPhotons_cfi")

process.TFileService = cms.Service("TFileService",fileName = cms.string("OUTPUT"))

process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound')
)

# to make jets   
##================================ Get the most recent JEC ==================================================================#
#    # Setup the private SQLite -- Ripped from PhysicsTools/PatAlgos/test/corMETFromMiniAOD.py
#usePrivateSQlite=True
#applyL2L3Residuals = True
#
#if usePrivateSQlite:
#    from CondCore.DBCommon.CondDBSetup_cfi import *
#    import os
#
#    era = "Spring16_25nsV6"
#    if isMC : 
#        era += "_MC"
#    else :
#        era += "_DATA"
#    #dBFile = os.path.expandvars(era+".db")
#    dBFile = os.path.expandvars("/afs/cern.ch/user/m/mzientek/public/"+era+".db") 
#
#    if usePrivateSQlite:
#        process.jec = cms.ESSource("PoolDBESSource",
#                                   CondDBSetup,
#                                   connect = cms.string("sqlite_file:"+dBFile),
#                                   toGet =  cms.VPSet(
#                cms.PSet(
#                    record = cms.string("JetCorrectionsRecord"),
#                    tag = cms.string("JetCorrectorParametersCollection_"+era+"_AK4PF"),
#                    label= cms.untracked.string("AK4PF")
#                    ),
#                cms.PSet(
#                        record = cms.string("JetCorrectionsRecord"),
#                        tag = cms.string("JetCorrectorParametersCollection_"+era+"_AK4PFchs"),
#                        label= cms.untracked.string("AK4PFchs")
#                        ),
#                )
#                                   )
#        process.es_prefer_jec = cms.ESPrefer("PoolDBESSource",'jec')
##===========================================================================================================================#
#
##============================================Re do jets + JEC===================================================================#
#
from flashgg.MicroAOD.flashggJets_cfi import flashggBTag, maxJetCollections
process.flashggUnpackedJets = cms.EDProducer("FlashggVectorVectorJetUnpacker",  
                                             JetsTag = cms.InputTag("flashggFinalJets"),          
                                             NCollections = cms.uint32(maxJetCollections) 
                                             )               
#
#process.load('JetMETCorrections.Configuration.JetCorrectors_cff')
#
#process.ak4PFCHSL1FastjetCorrector = cms.EDProducer(
#    'L1FastjetCorrectorProducer',
#    level       = cms.string('L1FastJet'),
#    algorithm   = cms.string('AK4PFchs'),
#    srcRho      = cms.InputTag( 'fixedGridRhoFastjetAll' )
#    )
#process.ak4PFCHSL2RelativeCorrector = cms.EDProducer(
#    'LXXXCorrectorProducer',
#    level     = cms.string('L2Relative'),
#    algorithm = cms.string('AK4PFchs')
#    )
#process.ak4PFCHSL3AbsoluteCorrector = cms.EDProducer(
#    'LXXXCorrectorProducer',
#    level     = cms.string('L3Absolute'),
#    algorithm = cms.string('AK4PFchs')
#    )
#process.ak4PFCHSL1FastL2L3Corrector = cms.EDProducer(
#    'ChainedJetCorrectorProducer',
#    correctors = cms.VInputTag('ak4PFCHSL1FastjetCorrector','ak4PFCHSL2RelativeCorrector','ak4PFCHSL3AbsoluteCorrector')
#    )
#
#process.ak4PFCHSResidualCorrector = cms.EDProducer(
#    'LXXXCorrectorProducer',
#    level     = cms.string('L2L3Residual'),
#    algorithm = cms.string('AK4PFchs')
#    )
#process.ak4PFCHSL1FastL2L3ResidualCorrector = cms.EDProducer(
#    'ChainedJetCorrectorProducer',
#    correctors = cms.VInputTag('ak4PFCHSL1FastjetCorrector','ak4PFCHSL2RelativeCorrector','ak4PFCHSL3AbsoluteCorrector','ak4PFCHSResidualCorrector')
#    )
UnpackedJetCollectionVInputTag = cms.VInputTag()       
for i in range(0,maxJetCollections):    
    UnpackedJetCollectionVInputTag.append(cms.InputTag('flashggUnpackedJets',str(i)))  
##===========================================================================================================================#


process.diPhoAna = cms.EDAnalyzer('NewDiPhoAnalyzer', ## important -- have to keep format xx = xx (no tabs) for reading in batchjobs
                                  VertexTag = cms.untracked.InputTag('offlineSlimmedPrimaryVertices'),
				  METTag = cms.untracked.InputTag('flashggMets::FLASHggMicroAOD'),
				  pfcands = cms.InputTag("packedPFCandidates"),
                                  #JetCorrectorTag = cms.InputTag("ak4PFCHSL1FastjetCorrector"),
                                  inputTagJets = UnpackedJetCollectionVInputTag,  
                                  ElectronTag = cms.InputTag('flashggSelectedElectrons'),
                                  MuonTag = cms.InputTag('flashggSelectedMuons'), 
                                  bTag = cms.untracked.string(flashggBTag),      
				  RhoTag = cms.InputTag('fixedGridRhoAll'),
                                  genPhotonExtraTag = cms.InputTag("flashggGenPhotonsExtra"),   
                                  DiPhotonTag = cms.untracked.InputTag('flashggDiPhotons0vtx'),
                                  DiPhotonBDTVtxTag = cms.untracked.InputTag('flashggDiPhotons'),
                                  PileUpTag = cms.untracked.InputTag('slimmedAddPileupInfo'),
                                  generatorInfo = cms.InputTag('generator'),
				  bits = cms.InputTag(bit),
                                  flags = cms.InputTag(flag),
                                  dopureweight = PU, 
                                  sampleIndex = SI,
                                  puWFileName = weights,
                                  xsec = XS,
                                  kfac = KF,
                                  sumDataset = SDS,
                                  )

process.p = cms.Path(process.flashggUnpackedJets*process.diPhoAna)

#if (isMC==True):
#    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSL1FastL2L3Corrector*process.diPhoAna )     
#if (isMC==False):
#    process.p = cms.Path(process.flashggUnpackedJets*process.ak4PFCHSL1FastjetCorrector*process.ak4PFCHSL2RelativeCorrector*process.ak4PFCHSL3AbsoluteCorrector*process.ak4PFCHSResidualCorrector*process.ak4PFCHSL1FastL2L3ResidualCorrector*process.diPhoAna )     
#
