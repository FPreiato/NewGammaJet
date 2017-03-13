import FWCore.ParameterSet.Config as cms
import os
from CondCore.CondDB.CondDB_cfi  import *

process = cms.Process("GAMMAJET")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = cms.untracked.string('INFO')
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

#--- import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load('RecoJets.JetProducers.QGTagger_cfi')
process.QGTagger.srcJets          = cms.InputTag('slimmedJets')
process.QGTagger.jetsLabel       = cms.string('QGL_AK4PFchs') #see https://twiki.cern.ch/twiki/bin/viewauth/CMS/QGDataBaseVersion

process.GlobalTag.globaltag = cms.string("80X_mcRun2_asymptotic_2016_miniAODv2_v1")

process.load("JetMETCorrections.Configuration.JetCorrectionProducers_cff")
process.load("RecoEgamma/PhotonIdentification/PhotonIDValueMapProducer_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5000) )

process.source = cms.Source (
    "PoolSource", 
    fileNames = cms.untracked.vstring(
        'file:../tuples/GJet_Pythia_Summer16_file1.root'
        )
    )

crossSection = 1

print("Running on sample with:")
print("\tCross-section: %f" % crossSection)

process.gammaJet = cms.EDFilter('GammaJetFilter',
                                isMC = cms.untracked.bool(True),
                                firstJetPtCut = cms.untracked.bool(False),
                                
                                crossSection = cms.double(crossSection),

                                full5x5SigmaIEtaIEtaMap   = cms.InputTag("photonIDValueMapProducer:phoFull5x5SigmaIEtaIEta"),
                                phoChargedIsolation           = cms.InputTag("photonIDValueMapProducer:phoChargedIsolation"),
                                phoNeutralHadronIsolation = cms.InputTag("photonIDValueMapProducer:phoNeutralHadronIsolation"),
                                phoPhotonIsolation             = cms.InputTag("photonIDValueMapProducer:phoPhotonIsolation"), 
                                prescalesTag = cms.InputTag("patTrigger"),  
                                triggerResultsTag = cms.InputTag("TriggerResults", "", "HLT"),  
                                generatorTag = cms.InputTag("generator"),  
                                vertexTag = cms.InputTag("offlineSlimmedPrimaryVertices"),  
                                photonsTag = cms.InputTag("slimmedPhotons"),
                                jetsTag = cms.InputTag("slimmedJets"),
                                jetsAK8Tag = cms.InputTag("slimmedJetsAK8"),
                                jetsPUPPITag = cms.InputTag("slimmedJetsPuppi"),
                                metTag = cms.InputTag("slimmedMETs"),
                                metPUPPITag = cms.InputTag("slimmedMETsPuppi"),
                                electronsTag = cms.InputTag("slimmedElectrons"),
                                muonsTag = cms.InputTag("slimmedMuons"),
                                rhoTag = cms.InputTag("fixedGridRhoFastjetAll"),
                                PUInfoTag = cms.InputTag("slimmedAddPileupInfo"),
                                pfCands = cms.InputTag("packedPFCandidates"),

                                barrelRecHitCollectionTag = cms.InputTag("reducedEgamma","reducedEBRecHits"),

                                runOnPFAK4    = cms.untracked.bool(True),
                                runOnPFAK8    = cms.untracked.bool(False),
                                runOnPUPPIAK4    = cms.untracked.bool(True),
                                
                                # MET
                                redoTypeIMETCorrection = cms.untracked.bool(True),
                                doFootprintMETCorrection = cms.untracked.bool(True),

                                # JEC
                                doJetCorrection = cms.untracked.bool(True),
                                correctJecFromRaw = cms.untracked.bool(True),

                                L1corr_MC = cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L1FastJet_AK4PFchs.txt'),
                                L2corr_MC = cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L2Relative_AK4PFchs.txt'),
                                L3corr_MC = cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L3Absolute_AK4PFchs.txt'),
                                L1RCcorr_MC =cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L1RC_AK4PFchs.txt'),

                                L1PUPPIcorr_MC = cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L1FastJet_AK4PFPuppi.txt'),
                                L2PUPPIcorr_MC = cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L2Relative_AK4PFPuppi.txt'),
                                L3PUPPIcorr_MC = cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L3Absolute_AK4PFPuppi.txt'),
                                L1RCPUPPIcorr_MC =cms.FileInPath('JetMETCorrections/GammaJetFilter/data/Summer16_23Sep2016V1_MC/Summer16_23Sep2016V1_MC_L1FastJet_AK4PFPuppi.txt')
                                
                                )

process.p = cms.Path(
    process.photonIDValueMapProducer *
    process.QGTagger *
    process.gammaJet)

process.out = cms.OutputModule("PoolOutputModule",
      fileName = cms.untracked.string("delete_me.root"),
      SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('p')
        )
                               )

process.out.outputCommands = cms.untracked.vstring('keep *',
#    'drop *_selectedPatJets*_*_*',
#    'keep *_selectedPatJets*_genJets_*',
)

process.TFileService = cms.Service("TFileService",
          fileName = cms.string("output_singleFile_GJet.root")
    )

#process.out.fileName = 'patTuple_cleaned.root'
# set True if you want long output
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))

#process.outpath = cms.EndPath(process.out)
