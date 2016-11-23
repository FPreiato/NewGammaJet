#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include "TVirtualFitter.h"
#include "TGraphErrors.h"
#include "TChain.h"
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TAxis.h>
#include <TF1.h>
#include <TMath.h>
#include <TStyle.h>
#include "TPaveText.h"
#include "etaBinning.h"

#define LIGHT_RED TColor::GetColor(0xcf, 0xa0, 0xa1)

using namespace std;

// to be run after drawPhotonJet_2bkg

int main(int argc, char* argv[]) {

  TString dataFileName_RunRange1;
  dataFileName_RunRange1 = TString::Format("PhotonJetGraphs_SinglePhoton_2016-06-21-Run_273158_274315_vs_GJet_Pythia_2016-06-21_PFlowAK4chs_LUMI.root");
  TFile* dataFile_RunRange1 = TFile::Open(dataFileName_RunRange1);
  if (dataFile_RunRange1) {
    std::cout << "Opened data file '" << dataFileName_RunRange1 << "'." << std::endl;
  }

  TString dataFileName_RunRange2;
  dataFileName_RunRange2 = TString::Format("PhotonJetGraphs_SinglePhoton_2016-06-21-Run_274316_Inf_vs_GJet_Pythia_2016-06-21_PFlowAK4chs_LUMI.root");
  TFile* dataFile_RunRange2 = TFile::Open(dataFileName_RunRange2);
  if (dataFile_RunRange2) {
    std::cout << "Opened data file '" << dataFileName_RunRange2 << "'." << std::endl;
  }


  EtaBinning mEtaBinning;
  size_t etaBinningSize = mEtaBinning.size();  
  cout<< etaBinningSize << endl;

  for(int kk = 0; kk<2; kk++){  
    std::string response;
    response = (kk==0 ) ? "balancing" : "mpf";
    double ymin;
    ymin = (response == "balancing" ) ? 0.5 : 0.8;
    for (size_t ii = 0; ii < etaBinningSize; ii++) {

	std::string etaName = mEtaBinning.getBinName(ii);

	// data      
	std::string DataName = TString::Format("resp_%s_%s_data_vs_pt", response.c_str(), etaName.c_str() ).Data(); 
	cout<< DataName.c_str() << endl;
	//mc
	//ratio
	std::string RatioName = TString::Format("resp_%s_%s_ratio_vs_pt", response.c_str(), etaName.c_str() ).Data();       
	cout<< RatioName.c_str() << endl;

	TGraphErrors *gr_data_runRange1 = (TGraphErrors*)dataFile_RunRange1->Get( DataName.c_str() );
	TGraphErrors *gr_data_runRange2 = (TGraphErrors*)dataFile_RunRange2->Get( DataName.c_str() );
	TGraphErrors *gr_ratio_runRange1 = (TGraphErrors*)dataFile_RunRange1->Get( RatioName.c_str() );
	TGraphErrors *gr_ratio_runRange2 = (TGraphErrors*)dataFile_RunRange2->Get( RatioName.c_str() );

	TLegend* legend = new TLegend(0.6, 0.6, 0.9, 0.9);
	legend->SetTextFont(42);
	legend->SetBorderSize(0);
	legend->SetFillColor(kWhite);
	legend->SetFillStyle(0);
	//	legend->SetTextSize(legendTextSize_);
	legend->SetHeader("Run range:");
	legend->AddEntry(gr_data_runRange1, "273158 - 274315", "P");
	legend->AddEntry(gr_data_runRange2, "> 274315", "P");

	TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);
	gPad->SetLogx();
	gr_data_runRange1 -> SetTitle("");
	gr_data_runRange1 -> GetXaxis()-> SetTitle("p_{T} (#gamma) [GeV]");
	gr_data_runRange1 -> GetYaxis()-> SetTitle(TString::Format("%s response", response.c_str() ));
	gr_data_runRange1 -> GetYaxis()-> SetTitleOffset(1.4);
	gr_data_runRange1 -> GetYaxis()->SetRangeUser(ymin, 1.2);
	gr_data_runRange1 -> GetXaxis()->SetMoreLogLabels();
	gr_data_runRange1 -> GetXaxis()->SetNoExponent();

	gr_data_runRange1 -> SetMarkerStyle(20);
	gr_data_runRange1 -> SetMarkerSize(1.5);
	gr_data_runRange1 -> SetMarkerColor(kRed);
	gr_data_runRange2 -> SetMarkerStyle(22);
	gr_data_runRange2 -> SetMarkerSize(1.5);
	gr_data_runRange2 -> SetMarkerColor(kBlue);

	gr_data_runRange1 -> Draw("ZAP");
	gr_data_runRange2 -> Draw("Psame");
	legend->Draw();
	c1->SaveAs( Form("Plot_vs_run/%s.png", DataName.c_str() ) );
	c1->Destructor();       

	TCanvas *c2 = new TCanvas("c2", "c2", 800, 800);
	gPad->SetLogx();
	gr_ratio_runRange1 -> SetTitle("");
	gr_ratio_runRange1 -> GetXaxis()-> SetTitle("p_{T} (#gamma) [GeV]");
	gr_ratio_runRange1 -> GetYaxis()-> SetTitle("Data/MC");
	gr_ratio_runRange1 -> GetYaxis()-> SetTitleOffset(1.4);
	gr_ratio_runRange1 -> GetYaxis()->SetRangeUser(0.8, 1.2);
	gr_ratio_runRange1 -> GetXaxis()->SetMoreLogLabels();
	gr_ratio_runRange1 -> GetXaxis()->SetNoExponent();

	gr_ratio_runRange1 -> SetMarkerStyle(20);
	gr_ratio_runRange1 -> SetMarkerSize(1.5);
	gr_ratio_runRange1 -> SetMarkerColor(kRed);
	gr_ratio_runRange2 -> SetMarkerStyle(22);
	gr_ratio_runRange2 -> SetMarkerSize(1.5);
	gr_ratio_runRange2 -> SetMarkerColor(kBlue);

	gr_ratio_runRange1 -> Draw("ZAP");
	gr_ratio_runRange2 -> Draw("Psame");
	legend->Draw();
	c2->SaveAs( Form("Plot_vs_run/%s.png", RatioName.c_str() ) );
	c2->Destructor();       


    }//eta
    //special case
    std::string etaName = "eta0013";
    
    // data      
    std::string DataName = TString::Format("resp_%s_%s_data_vs_pt", response.c_str(), etaName.c_str() ).Data(); 
    cout<< DataName.c_str() << endl;
    //mc
    //ratio
    std::string RatioName = TString::Format("resp_%s_%s_ratio_vs_pt", response.c_str(), etaName.c_str() ).Data();       
    cout<< RatioName.c_str() << endl;

    TGraphErrors *gr_data_runRange1 = (TGraphErrors*)dataFile_RunRange1->Get( DataName.c_str() );
    TGraphErrors *gr_data_runRange2 = (TGraphErrors*)dataFile_RunRange2->Get( DataName.c_str() );
    TGraphErrors *gr_ratio_runRange1 = (TGraphErrors*)dataFile_RunRange1->Get( RatioName.c_str() );
    TGraphErrors *gr_ratio_runRange2 = (TGraphErrors*)dataFile_RunRange2->Get( RatioName.c_str() );

    TLegend* legend = new TLegend(0.6, 0.6, 0.9, 0.9);
    legend->SetTextFont(42);
    legend->SetBorderSize(0);
    legend->SetFillColor(kWhite);
    legend->SetFillStyle(0);
    //	legend->SetTextSize(legendTextSize_);
    legend->SetHeader("Run range:");
    legend->AddEntry(gr_data_runRange1, "273158 - 274315", "P");
    legend->AddEntry(gr_data_runRange2, "> 274315", "P");



    TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);
    gPad->SetLogx();
    gr_data_runRange1 -> SetTitle("");
    gr_data_runRange1 -> GetXaxis()-> SetTitle("p_{T} (#gamma) [GeV]");
    gr_data_runRange1 -> GetYaxis()-> SetTitle(TString::Format("%s response", response.c_str() ));
    gr_data_runRange1 -> GetYaxis()-> SetTitleOffset(1.4);
    gr_data_runRange1 -> GetYaxis()->SetRangeUser(ymin, 1.2);
    gr_data_runRange1 -> GetXaxis()->SetMoreLogLabels();
    gr_data_runRange1 -> GetXaxis()->SetNoExponent();

    gr_data_runRange1 -> SetMarkerStyle(20);
    gr_data_runRange1 -> SetMarkerSize(1.5);
    gr_data_runRange1 -> SetMarkerColor(kRed);
    gr_data_runRange2 -> SetMarkerStyle(22);
    gr_data_runRange2 -> SetMarkerSize(1.5);
    gr_data_runRange2 -> SetMarkerColor(kBlue);

    gr_data_runRange1 -> Draw("ZAP");
    gr_data_runRange2 -> Draw("Psame");
    legend->Draw();
    c1->SaveAs( Form("Plot_vs_run/%s.png", DataName.c_str() ) );
    c1->Destructor();       

    TCanvas *c2 = new TCanvas("c2", "c2", 800, 800);
    gPad->SetLogx();
    gr_ratio_runRange1 -> SetTitle("");
    gr_ratio_runRange1 -> GetXaxis()-> SetTitle("p_{T} (#gamma) [GeV]");
    gr_ratio_runRange1 -> GetYaxis()-> SetTitle("Data/MC");
    gr_ratio_runRange1 -> GetYaxis()-> SetTitleOffset(1.4);
    gr_ratio_runRange1 -> GetYaxis()->SetRangeUser(0.8, 1.2);
    gr_ratio_runRange1 -> GetXaxis()->SetMoreLogLabels();
    gr_ratio_runRange1 -> GetXaxis()->SetNoExponent();

    gr_ratio_runRange1 -> SetMarkerStyle(20);
    gr_ratio_runRange1 -> SetMarkerSize(1.5);
    gr_ratio_runRange1 -> SetMarkerColor(kRed);
    gr_ratio_runRange2 -> SetMarkerStyle(22);
    gr_ratio_runRange2 -> SetMarkerSize(1.5);
    gr_ratio_runRange2 -> SetMarkerColor(kBlue);

    gr_ratio_runRange1 -> Draw("ZAP");
    gr_ratio_runRange2 -> Draw("Psame");
    legend->Draw();
    c2->SaveAs( Form("Plot_vs_run/%s.png", RatioName.c_str() ) );
    c2->Destructor();       
	

  }
  







 

}//main





