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
#config.Data.lumiMask = '/cmshome/fpreiato/Test_NewGammaJet/CMSSW_8_0_24_patch1/src/JetMETCorrections/GammaJetFilter/json/ReReco/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt' # For BCD, E
#config.Data.lumiMask = '/cmshome/fpreiato/Test_NewGammaJet/CMSSW_8_0_24_patch1/src/JetMETCorrections/GammaJetFilter/json/ReReco/Cert_Until278802.txt'  # For earlyF
config.Data.lumiMask = '/cmshome/fpreiato/Test_NewGammaJet/CMSSW_8_0_24_patch1/src/JetMETCorrections/GammaJetFilter/json/ReReco/Cert_From278802.txt' # For LateFGH (v2 && v3)
#config.Data.runRange = '251244-251252' # '193093-194075'
config.Data.ignoreLocality = True
config.Data.publication = False
config.Data.outLFNDirBase = '/store/user/fpreiato/JetMET2016/data/'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_IT_Rome'
