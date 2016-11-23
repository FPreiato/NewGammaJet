from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.transferLogs = True
config.General.workArea = 'WORKINGAREA'
config.General.requestName = 'WORKINGDIR'
config.section_('JobType')
config.JobType.psetName = 'CMSSWCFG'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['OUTFILENAME']
config.section_('Data')
config.Data.inputDataset = 'INPUTDATASET'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = LUMISPERJOB #without '' since it must be an int
#config.Data.lumiMask = '/cmshome/fpreiato/Test_NewGammaJet/CMSSW_8_0_8_patch1/src/JetMETCorrections/GammaJetFilter/json/Cert_271036-283685_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt' # For BCD, E
#config.Data.lumiMask = '/cmshome/fpreiato/Test_NewGammaJet/CMSSW_8_0_8_patch1/src/JetMETCorrections/GammaJetFilter/json/Cert_Until278802.json'  # For F
config.Data.lumiMask = '/cmshome/fpreiato/Test_NewGammaJet/CMSSW_8_0_8_patch1/src/JetMETCorrections/GammaJetFilter/json/Cert_From278802.json' # For LateFGH
#config.Data.runRange = '251244-251252' # '193093-194075'
config.Data.ignoreLocality = True
config.Data.publication = False
config.Data.outLFNDirBase = '/store/user/fpreiato/JetMET2016/data/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_IT_Rome'
