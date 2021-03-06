#include <stdlib.h>

#include "drawBase.h"
#include "TParameter.h"
#include "TError.h"
#include "fitTools.h"
#include "TH1D.h"
#include "TH1F.h"
#include "TAxis.h"
#include <TColor.h>
#include "etaBinning.h"
#include "ptBinning.h"

bool OUTPUT_GRAPHS = true;
bool RAW = false;

int main(int argc, char* argv[]) {

  if (argc != 7) {
    std::cout << "USAGE: ./drawPhotonJet [data_dataset] [mc_SIGNAL_dataset] [mc_BG_dataset] [recoType] [jetAlgo] [norm ('LUMI' or 'SHAPE')]" << std::endl;
    exit(23);
  }

  std::string data_dataset(argv[1]);
  std::string mc_photonjet(argv[2]);
  std::string mc_QCD(argv[3]);
  std::string recoType(argv[4]);
  std::string jetAlgo(argv[5]);
  std::string norm(argv[6]);
  if (norm != "LUMI" && norm != "SHAPE") {
    std::cout << "'" << norm << "' normalization not implemented yet." << std::endl;
    std::cout << "Only 'LUMI' and 'SHAPE' currently supported." << std::endl;
    std::cout << "Exiting." << std::endl;
    exit(9811);
  }
  
  recoType = (recoType == "pf") ? "PFlow" : "PUPPI";
  jetAlgo = (jetAlgo == "ak4") ? "AK4" : "AK8";
  std::string postFix = recoType + jetAlgo;  
  if(recoType == "PFlow") postFix += "chs";
  
  drawBase* db = new drawBase("PhotonJet", recoType, jetAlgo, OUTPUT_GRAPHS);
  // federico -- true/false plots in pdf
  db->set_pdf_aussi((bool)true);
  db->set_isCMSArticle(false);

  TString dataFileName;
  dataFileName = TString::Format("PhotonJet_%s_%s.root", data_dataset.c_str(), postFix.c_str());
  TFile* dataFile = TFile::Open(dataFileName);

  if (dataFile) {
    std::cout << "Opened data file '" << dataFileName << "'." << std::endl;
    db->add_dataFile(dataFile, data_dataset);
  }else{
    std::cout << "Impossible open data file '" << dataFileName << "'." << std::endl;
    std::cout << "Exiting." << std::endl;
    exit(9811);
  }

  TString mc1FileName;
  mc1FileName = TString::Format("PhotonJet_%s_%s.root", mc_photonjet.c_str(), postFix.c_str());
  TFile* mcPhotonJetFile = TFile::Open(mc1FileName);

  if (mcPhotonJetFile) {
    std::cout << "Opened GJet file '" << mc1FileName << "'." << std::endl;
    db->add_mcFile(mcPhotonJetFile, mc_photonjet, "#gamma+jet MC", TColor::GetColor(192, 41, 66));
  }else{
    std::cout << "Impossible open GJet file '" << mc1FileName << "'." << std::endl;
    std::cout << "Exiting." << std::endl;
    exit(9811);
  }

  if (mc_QCD != mc_photonjet){ 
    TString mc2FileName;
    mc2FileName = TString::Format("PhotonJet_%s_%s.root", mc_QCD.c_str(), postFix.c_str());
    TFile* mcQCDFile = TFile::Open(mc2FileName);
 
    if (mcQCDFile) {
      std::cout << "Opened mc QCD file '" << mc2FileName << "'." << std::endl;
      db->add_mcFile(mcQCDFile, mc_QCD, "QCD MC", TColor::GetColor("#ECD078"));
    }else{
      std::cout << "Impossible open QCD file '" << mc2FileName << "'." << std::endl;
      std::cout << "Exiting." << std::endl;
      exit(9811);
    }   
  }else{
    std::cout<<"Not passed any QCD file "<<std::endl;
  }
  
  // MC should already be normalized to a lumi of 1 pb-1
  // Read luminosity
  double dLumi=1;
  TParameter<double>* lumi = static_cast<TParameter<double>*>(dataFile->Get("analysis/luminosity"));
  dLumi = lumi->GetVal();   
  std::cout<< "Lumi "<< dLumi << std::endl;  
  db->set_lumi(dLumi);
  
  if (norm == "LUMI") {
    db->set_lumiNormalization();
  } else {
    db->set_shapeNormalization();
  }
  
  bool log = true;
  gErrorIgnoreLevel = kWarning;  
  db->setFolder("analysis");
  db->set_outputdir();
  db->setOutputGraphs(true);
  db->set_rebin(1);

  // Data/MC comparison
 
  db->drawHisto("ptPhoton_NoCut", "Photon Transverse Momentum", "GeV", "Events", log, 1, "", false, 50);
  db->drawHisto("ptPhoton", "Photon Transverse Momentum", "GeV", "Events", log, 1, "", false, 50);
  db->drawHisto("EtaPhoton", "Photon Eta", " ", "Events" , log);
  db->drawHisto("PhiPhoton", "Photon Phi", " ", "Events" , false);
  db->drawHisto("ptFirstJet", "Jet Transverse Momentum", "GeV", "Events", log);
  db->drawHisto("EtaFirstJet", "FirstJet Eta", " ", "Events" , log);
  db->drawHisto("PhiFirstJet", "FirstJet Phi", " ", "Events" , false);
  db->drawHisto("ptSecondJet", "2nd Jet Transverse Momentum", "GeV", "Events", log);
  db->drawHisto("EtaSecondJet", "2nd Jet Eta", "", "Events" , log);
  db->drawHisto("PhiSecondJet", "2nd Jet Phi", " ", "Events" , false);
  db->drawHisto("MET", "Missing E_{T}", "GeV", "Events", log);
  db->drawHisto("alpha", "#alpha", "", "Events", log);
  db->drawHisto("deltaPhi_NoCut", "#Delta#phi", "", "Events", log);

  db->drawHisto("ptPhoton_passedID", "Photon Transverse Momentum", "GeV", "Events", log, 1, "", false, 50);
  db->drawHisto("EtaPhoton_passedID", "Photon Eta", " ", "Events" , log);
  db->drawHisto("PhiPhoton_passedID", "Photon Phi", " ", "Events" , false);
  db->drawHisto("ptFirstJet_passedID", "Jet Transverse Momentum", "GeV", "Events", log);
  db->drawHisto("EtaFirstJet_passedID", "FirstJet Eta", " ", "Events" , log);
  db->drawHisto("PhiFirstJet_passedID", "FirstJet Phi", " ", "Events" , false);
  db->drawHisto("ptSecondJet_passedID", "2nd Jet Transverse Momentum", "GeV", "Events", log);
  db->drawHisto("EtaSecondJet_passedID", "2nd Jet Eta", " ", "Events" , log);
  db->drawHisto("PhiSecondJet_passedID", "2nd Jet Phi", " ", "Events" , false); 
  db->drawHisto("ptSecondJet_2ndJetOK", "2nd Jet Transverse Momentum", "GeV", "Events", log);
  db->drawHisto("EtaSecondJet_2ndJetOK", "2nd Jet Eta", " ", "Events" , log);
  db->drawHisto("PhiSecondJet_2ndJetOK", "2nd Jet Phi", " ", "Events" , false);
  db->drawHisto("MET_passedID", "Missing E_{T}", "GeV", "Events", log);
  db->drawHisto("alpha_passedID", "#alpha", "", "Events", log);
  //  db->set_rebin(1);
  db->drawHisto("nvertex", "Number of Reconstructed Vertices", "", "Events", log);
  db->drawHisto("nvertex_reweighted", "Number of Reconstructed Vertices (after reweighting)", "", "Events", log);
  //  db->set_rebin(2);
  db->drawHisto("deltaPhi_passedID", "#Delta #varphi", "", "Events", log);  
  db->drawHisto("hadTowOverEm", "H/E", "", "Events", log);
  db->drawHisto("sigmaIetaIeta", "#sigma_{i#eta i#eta}", "", "Events", log);
  db->drawHisto("rho", "#rho", "", "Events", log); 
  db->drawHisto("chargedHadronsIsolation", "Charged hadrons isolation", "", "Events", log);
  db->drawHisto("neutralHadronsIsolation", "Neutral hadrons isolation", "", "Events", log);
  db->drawHisto("photonIsolation", "Photon isolation", "", "Events", log);
  db->drawHisto("R9", "R9", "", "Events", log);
  db->drawHisto("hadTowOverEm_passedID", "H/E", "", "Events", log);
  db->drawHisto("sigmaIetaIeta_passedID", "#sigma_{i#eta i#eta}", "", "Events", log);
  db->drawHisto("rho_passedID", "#rho", "", "Events", log);
  db->drawHisto("chargedHadronsIsolation_passedID", "Charged hadrons isolation", "", "Events", log);
  db->drawHisto("neutralHadronsIsolation_passedID", "Neutral hadrons isolation", "", "Events", log);
  db->drawHisto("photonIsolation_passedID", "Photon isolation", "", "Events", log);
  db->drawHisto("R9_passedID", "R9", "", "Events", log);

  db->drawProfile("PhotSCPt", "Pt", "p_{T} [GeV]", "p_{T}(SC) [GeV]", log, 0);
  db->drawHisto2D("PhotonSCPt_vs_Pt", "p_{T} [GeV]", "p_{T}(SC) [GeV]","", log);
  
  db->drawProfile("CorrOverRaw", "RawPt_eta0013", "Raw p_{T} [GeV]", "Corr/Raw", log, 0);
  db->drawProfile("CorrOverRaw", "CorrPt_eta0013", "p_{T} [GeV]", "Corr/Raw", log, 0);

  db->set_rebin(5);
  db->setOutputGraphs(OUTPUT_GRAPHS);

  TH1D *ptPhot = (TH1D*)dataFile->Get("analysis/ptPhoton_passedID");
  PtBinning ptBinning;
  size_t ptBinningSize = ptBinning.size();
  std::vector<std::pair<float, float> > ptBins = ptBinning.getBinning();
  std::vector<float> ptMean;
  for( size_t i = 0 ; i< ptBinningSize ; i++){ 
    std::pair<float, float> currentBin = ptBinning.getBinValue(i);
    ptPhot ->GetXaxis()->SetRangeUser(currentBin.first, currentBin.second);
    double Mean = ptPhot->GetMean();
    std::cout<< "Bin " << currentBin.first<< "-"<<currentBin.second<<" -> Mean  "<< Mean << std::endl; 
    ptMean.push_back(Mean);
  }

  EtaBinning etaBinning;
  size_t etaBinningSize = etaBinning.size();
  
  // Balancing
  db->setFolder("analysis/balancing");
  db->drawProfile("Bal", "Pt", "p_{T} [GeV]", "Balancing Response", log, 0);
  db->drawProfile("Bal", "Eta", "#eta", "Balancing Response", false, 0); 
  db->drawProfile("Bal", "Nvtx", "N_{vertex}", "Balancing Response", false, 0);
  
  for (size_t i = 0; i < etaBinningSize; i++) {
    db->set_legendTitle(etaBinning.getBinTitle(i));
    
    TString responseName = TString::Format("resp_balancing_%s", etaBinning.getBinName(i).c_str());
    db->drawHisto_vs_pt(ptBins, ptMean, responseName.Data(), "Balancing Response", "", "Events", false);
    if(RAW){ // Raw jets
      responseName = TString::Format("resp_balancing_raw_%s", etaBinning.getBinName(i).c_str());
      db->drawHisto_vs_pt(ptBins, ptMean, responseName.Data(), "Balancing Response (raw jets)", "", "Events", false);
    }
  }
  db->set_legendTitle("|#eta| < 1.3");
  db->drawHisto_vs_pt(ptBins, ptMean, "resp_balancing_eta0013", "Balancing Response", "", "Events", false);
  if(RAW) db->drawHisto_vs_pt(ptBins, ptMean, "resp_balancing_raw_eta0013", "Balancing Response (raw jets)", "", "Events", false);


  db->set_legendTitle("|#eta| < 2.4");
  db->drawHisto_vs_pt(ptBins, ptMean, "resp_balancing_eta0024", "Balancing Response", "", "Events", false);
  if(RAW) db->drawHisto_vs_pt(ptBins, ptMean, "resp_balancing_raw_eta0024", "Balancing Response (raw jets)", "", "Events", false);

  
  // MPF
  db->setFolder("analysis/mpf");
  db->drawProfile("MPF", "Pt", "p_{T} [GeV]", "MPF Response", log, 0);
  db->drawProfile("MPF", "Eta", "#eta", "MPF Response", false, 0);
  db->drawProfile("MPF", "Nvtx", "N_{vertex}", "MPF Response", false, 0); 

  for (size_t i = 0; i < etaBinningSize; i++) {
    db->set_legendTitle(etaBinning.getBinTitle(i));
   
    TString responseName = TString::Format("resp_mpf_%s", etaBinning.getBinName(i).c_str());
    db->drawHisto_vs_pt(ptBins, ptMean, responseName.Data(), "MPF Response", "", "Events", false);
    if(RAW){ // Raw jets
      responseName = TString::Format("resp_mpf_raw_%s", etaBinning.getBinName(i).c_str());
      db->drawHisto_vs_pt(ptBins, ptMean, responseName.Data(), "MPF Response (raw MET)", "", "Events", false);
    }
  }
  db->set_legendTitle("|#eta| < 1.3");
  db->drawHisto_vs_pt(ptBins, ptMean, "resp_mpf_eta0013", "MPF Response", "", "Events", false);
  if(RAW) db->drawHisto_vs_pt(ptBins, ptMean, "resp_mpf_raw_eta0013", "MPF Response (raw MET)", "", "Events", false);

  db->set_legendTitle("|#eta| < 2.4");
  db->drawHisto_vs_pt(ptBins, ptMean, "resp_mpf_eta0024", "MPF Response", "", "Events", false);
  if(RAW) db->drawHisto_vs_pt(ptBins, ptMean, "resp_mpf_raw_eta0024", "MPF Response (raw MET)", "", "Events", false);


  delete db;
  db = NULL;

  return 0;

}
