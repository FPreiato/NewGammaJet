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

#define LIGHT_RED TColor::GetColor(0xcf, 0xa0, 0xa1)

using namespace std;

int main(int argc, char* argv[]) {

  // PFlow --> PUPPI

  TFile f1("../tuples/2016-11-06_Spring16_25nsV8_ClosureTest/EraBCD/PFlowJets/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016BCD_2016-11-06_alphacut030_vs_GJet_2016-11-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraBCD;
  TGraphErrors *resp_mpfRatio_EraBCD;
  TGraphErrors *resp_balancingRatio_Extrap_EraBCD;
  TGraphErrors *resp_mpfRatio_Extrap_EraBCD;

  TFile f2("../tuples/2016-11-06_Spring16_25nsV8_ClosureTest/EraE/PFlowJets/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016E_2016-11-06_alphacut030_vs_GJet_2016-11-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraE;
  TGraphErrors *resp_mpfRatio_EraE;
  TGraphErrors *resp_balancingRatio_Extrap_EraE;
  TGraphErrors *resp_mpfRatio_Extrap_EraE;

  TFile f3("../tuples/2016-11-06_Spring16_25nsV8_ClosureTest/EraF_Until278802/PFlowJets/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016F_Until278802_2016-11-06_alphacut030_vs_GJet_2016-11-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraF;
  TGraphErrors *resp_mpfRatio_EraF;
  TGraphErrors *resp_balancingRatio_Extrap_EraF;
  TGraphErrors *resp_mpfRatio_Extrap_EraF;

  TFile f4("../tuples/2016-11-06_Spring16_25nsV8_ClosureTest/EraLateFGH/PFlowJets/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016LateFGH_2016-11-06_alphacut030_vs_GJet_2016-11-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraG;
  TGraphErrors *resp_mpfRatio_EraG;
  TGraphErrors *resp_balancingRatio_Extrap_EraG;
  TGraphErrors *resp_mpfRatio_Extrap_EraG;

  TLegend* legend = new TLegend(0.60, 0.70, 0.80, 0.90);                                                                                                                      
  legend->SetTextFont(42);                                                                                                                                                    
  legend->SetBorderSize(0);                                                                                                                                                   
  legend->SetFillColor(kWhite);                                                                                                                                               
  legend->SetFillStyle(0);                                                                                                                                                    
  legend->SetTextSize(0.036);                                                                                                                                                 
  legend->SetHeader("Epoch: ");                                                                                                                                  

  gStyle -> SetOptStat(kFALSE); 
  TH2* h2_axes_lo_resp = NULL;
  h2_axes_lo_resp = new TH2D("axes_lo_resp", "", 10, 40, 2000 , 10, 0.86, 1.14);

  //  for( int ii =0 ; ii<2 ; ii++){  
  //    for( int jj =0 ; jj<6 ; jj++){  
  for( int ii =0 ; ii<2 ; ii++){  
    for( int jj =0 ; jj<1 ; jj++){  

      std::cout<< ii << " "<< jj << std::endl; 
      
      if(ii == 0){
	if(jj ==0 ){
	  resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraE      = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraF      = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraG      = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta00_13");
	}else if( jj == 1){
	  //resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta08_13");
	  //resp_balancingRatio_EraE = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta08_13");
	  //resp_balancingRatio_EraF = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta08_13");
	  //resp_balancingRatio_EraG = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta08_13");
	}else if( jj == 2){
	  //resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta13_19");
	  //resp_balancingRatio_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta13_19");
	  //resp_balancingRatio_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta13_19");
	}else if(jj == 3){
	  //resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta19_25");
	  //resp_balancingRatio_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta19_25");
	  //resp_balancingRatio_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta19_25");
	}else if(jj == 4){
	  //resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta25_30");
	  //resp_balancingRatio_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta25_30");
	  //resp_balancingRatio_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta25_30");
	}else if(jj == 5){
	  //resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta30_32");
	  //resp_balancingRatio_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta30_32");
	  //resp_balancingRatio_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta30_32");
	}else if(jj == 6){
	  //resp_balancingRatio_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta32_52");
	  //resp_balancingRatio_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta32_52");
	  //resp_balancingRatio_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta32_52");
	}
      }else if(ii == 1){
	if(jj ==0 ){
	  resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraE = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraF = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraG = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta00_13");
	}else if( jj == 1){
	  //resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta08_13");
	  //resp_mpfRatio_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta08_13");
	  //resp_mpfRatio_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta08_13");
	}else if( jj == 2){
	  //resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta13_19");
	  //resp_mpfRatio_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta13_19");
	  //resp_mpfRatio_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta13_19");
	}else if(jj == 3){
	  //resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta19_25");
	  //resp_mpfRatio_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta19_25");
	  //resp_mpfRatio_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta19_25");
	}else if(jj == 4){
	  //resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta25_30");
	  //resp_mpfRatio_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta25_30");
	  //resp_mpfRatio_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta25_30");
	}else if(jj == 5){
	  //resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta30_32");
	  //resp_mpfRatio_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta30_32");
	  //resp_mpfRatio_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta30_32");
	}else if(jj == 6){
	  //resp_mpfRatio_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta32_52");
	  //resp_mpfRatio_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta32_52");
	  //resp_mpfRatio_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta32_52");
	}
      }

      std::cout<<"OK"<< std::endl; 

      TCanvas *c1 = new TCanvas("c1","c1",800,800);
      c1-> SetLogx();
      h2_axes_lo_resp->SetTitle("");
      h2_axes_lo_resp->SetXTitle("p_{T}(#gamma) [GeV/c]");
      if(ii ==0)  h2_axes_lo_resp->SetYTitle("(pTBal) Data/MC");
      if(ii ==1)  h2_axes_lo_resp->SetYTitle("(MPF) Data/MC");
      h2_axes_lo_resp->GetYaxis()->SetTitleOffset(1.4);
      h2_axes_lo_resp->GetYaxis()->SetRangeUser(0.9, 1.1);
      h2_axes_lo_resp->GetXaxis()->SetMoreLogLabels();
      h2_axes_lo_resp->GetXaxis()->SetNoExponent();
      h2_axes_lo_resp->Draw("");

      if(ii == 0){
      resp_balancingRatio_EraBCD -> SetMarkerColor(kRed);  
      resp_balancingRatio_EraBCD -> SetLineColor(kRed);
      resp_balancingRatio_EraBCD -> SetMarkerStyle(20);  

      resp_balancingRatio_EraE -> SetMarkerColor(kBlue);  
      resp_balancingRatio_EraE -> SetLineColor(kBlue);  
      resp_balancingRatio_EraE -> SetMarkerStyle(21);  

      resp_balancingRatio_EraF -> SetMarkerColor(kBlack);  
      resp_balancingRatio_EraF -> SetLineColor(kBlue);  
      resp_balancingRatio_EraF -> SetMarkerStyle(22);  

      resp_balancingRatio_EraG -> SetMarkerColor(kGreen);  
      resp_balancingRatio_EraG -> SetLineColor(kGreen);  
      resp_balancingRatio_EraG -> SetMarkerStyle(23);  

      resp_balancingRatio_EraBCD-> Draw("PSAME");
      resp_balancingRatio_EraE-> Draw("PSAME");
      resp_balancingRatio_EraF-> Draw("PSAME");
      resp_balancingRatio_EraG-> Draw("PSAME");
      }else if(ii == 1){
      resp_mpfRatio_EraBCD -> SetMarkerColor(kRed);  
      resp_mpfRatio_EraBCD -> SetLineColor(kRed); 
      resp_mpfRatio_EraBCD -> SetMarkerStyle(20);  

      resp_mpfRatio_EraE -> SetMarkerColor(kBlue);  
      resp_mpfRatio_EraE -> SetLineColor(kBlue);  
      resp_mpfRatio_EraE -> SetMarkerStyle(21);  

      resp_mpfRatio_EraF -> SetMarkerColor(kBlack);  
      resp_mpfRatio_EraF -> SetLineColor(kBlack);  
      resp_mpfRatio_EraF -> SetMarkerStyle(22);  

      resp_mpfRatio_EraG -> SetMarkerColor(kGreen);  
      resp_mpfRatio_EraG -> SetLineColor(kGreen);  
      resp_mpfRatio_EraG -> SetMarkerStyle(23);  

      resp_mpfRatio_EraBCD-> Draw("PSAME");
      resp_mpfRatio_EraE-> Draw("PSAME");
      resp_mpfRatio_EraF-> Draw("PSAME");
      resp_mpfRatio_EraG-> Draw("PSAME");
      }
      
 if(ii == 0 && jj == 0){
	legend->AddEntry(resp_balancingRatio_EraBCD, "B+C+D", "PL"); 
	legend->AddEntry(resp_balancingRatio_EraE, "E", "PL"); 
	legend->AddEntry(resp_balancingRatio_EraF, "F (278801)", "PL"); 
	legend->AddEntry(resp_balancingRatio_EraG, "LateF+G+H", "PL"); 
 }
 
 legend->Draw();
 
 if(ii ==0){
	if(jj==0){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta0013.png"); 
	}else if(jj==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta0813.png"); 
	}else if(jj==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta1319.png"); 
	}else if(jj==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta1925.png"); 
	}else if(jj==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta2530.png"); 
	}else if(jj==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta3032.png"); 
	}else if(jj==6){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_Epochs_eta3252.png"); 
	}
 }else if(ii ==1){
	if(jj == 0){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta0013.png");
	}else if(jj ==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta0813.png");
	}else if(jj ==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta1319.png");
	}else if(jj ==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta1925.png");
	}else if(jj ==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta2530.png");
	}else if(jj ==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta3032.png");
	}else if(jj ==6){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_Epochs_eta3252.png");
	}
 }
 c1->Destructor();
  
    }
  }


  ////////////////////// EXTRAPOLATED

  for( int ii =0 ; ii<2 ; ii++){  
    for( int jj =0 ; jj<1 ; jj++){  

      std::cout<< ii << " "<< jj << std::endl; 

      if(ii == 0){
	if(jj ==0 ){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta00_13");
	}else if( jj == 1){
	  //resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta08_13");
	  //resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta08_13");
	  //resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta08_13");
	}else if( jj == 2){
	  //resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  //resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  //resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta13_19");
	}else if(jj == 3){
	  //resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  //resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  //resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta19_25");
	}else if(jj == 4){
	  //resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  //resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  //resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta25_30");
	}else if(jj == 5){
	  //resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  //resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  //resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta30_32");
	}else if(jj == 6){
	  //resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  //resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  //resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta32_52");
	}
      }else if(ii == 1){
	if(jj ==0 ){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta00_13");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta00_13");
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta00_13");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta00_13");
	}else if( jj == 1){
	  //resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta08_13");
	  //resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta08_13");
	  //resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta08_13");
	}else if( jj == 2){
	  //resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta13_19");
	  //resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta13_19");
	  //resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta13_19");
	}else if(jj == 3){
	  //resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta19_25");
	  //resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta19_25");
	  //resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta19_25");
	}else if(jj == 4){
	  //resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta25_30");
	  //resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta25_30");
	  //resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta25_30");
	}else if(jj == 5){
	  //resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta30_32");
	  //resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta30_32");
	  //resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta30_32");
	}else if(jj == 6){
	  //resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta32_52");
	  //resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta32_52");
	  //resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta32_52");
	}
      }

      std::cout<<"OK"<< std::endl; 

      TCanvas *c1 = new TCanvas("c1","c1",800,800);
      c1-> SetLogx();
      h2_axes_lo_resp->SetTitle("");
      h2_axes_lo_resp->SetXTitle("p_{T}(#gamma) [GeV/c]");
      if(ii ==0)  h2_axes_lo_resp->SetYTitle("(pTBal) Data/MC");
      if(ii ==1)  h2_axes_lo_resp->SetYTitle("(MPF) Data/MC");
      h2_axes_lo_resp->GetYaxis()->SetTitleOffset(1.4);
      h2_axes_lo_resp->GetYaxis()->SetRangeUser(0.9, 1.1);
      h2_axes_lo_resp->GetXaxis()->SetMoreLogLabels();
      h2_axes_lo_resp->GetXaxis()->SetNoExponent();
      h2_axes_lo_resp->Draw("");

      if(ii == 0){
	resp_balancingRatio_Extrap_EraBCD -> SetMarkerColor(kRed);  
	resp_balancingRatio_Extrap_EraBCD -> SetLineColor(kRed); 
	resp_balancingRatio_Extrap_EraBCD -> SetMarkerStyle(20);  

	resp_balancingRatio_Extrap_EraE -> SetMarkerColor(kBlue);  
	resp_balancingRatio_Extrap_EraE -> SetLineColor(kBlue);  
	resp_balancingRatio_Extrap_EraE -> SetMarkerStyle(21);  

	resp_balancingRatio_Extrap_EraF -> SetMarkerColor(kBlack);  
	resp_balancingRatio_Extrap_EraF -> SetLineColor(kBlack);  
	resp_balancingRatio_Extrap_EraF -> SetMarkerStyle(22);  

	resp_balancingRatio_Extrap_EraG -> SetMarkerColor(kGreen);  
	resp_balancingRatio_Extrap_EraG -> SetLineColor(kGreen);  
	resp_balancingRatio_Extrap_EraG -> SetMarkerStyle(23);  

	resp_balancingRatio_Extrap_EraBCD-> Draw("PSAME");
	resp_balancingRatio_Extrap_EraE-> Draw("PSAME");
	resp_balancingRatio_Extrap_EraF-> Draw("PSAME");
	resp_balancingRatio_Extrap_EraG-> Draw("PSAME");
      }else if(ii == 1){
	resp_mpfRatio_Extrap_EraBCD -> SetMarkerColor(kRed);  
	resp_mpfRatio_Extrap_EraBCD -> SetLineColor(kRed); 
	resp_mpfRatio_Extrap_EraBCD -> SetMarkerStyle(20);  

	resp_mpfRatio_Extrap_EraE -> SetMarkerColor(kBlue);  
	resp_mpfRatio_Extrap_EraE -> SetLineColor(kBlue);  
	resp_mpfRatio_Extrap_EraE -> SetMarkerStyle(21);  

	resp_mpfRatio_Extrap_EraF -> SetMarkerColor(kBlack);  
	resp_mpfRatio_Extrap_EraF -> SetLineColor(kBlack);  
	resp_mpfRatio_Extrap_EraF -> SetMarkerStyle(22);  

	resp_mpfRatio_Extrap_EraG -> SetMarkerColor(kGreen);  
	resp_mpfRatio_Extrap_EraG -> SetLineColor(kGreen); 
	resp_mpfRatio_Extrap_EraG -> SetMarkerStyle(23);  

	resp_mpfRatio_Extrap_EraBCD-> Draw("PSAME");
	resp_mpfRatio_Extrap_EraE-> Draw("PSAME");
	resp_mpfRatio_Extrap_EraF-> Draw("PSAME");
	resp_mpfRatio_Extrap_EraG-> Draw("PSAME");
      }
      /*      
	      if(ii == 0 && jj ==0){
	      legend->AddEntry(resp_balancingRatio_Extrap_EraBCD, "B+C+D", "PL");                                                                                                                                        
	      legend->AddEntry(resp_balancingRatio_Extrap_EraEF, "E+F", "PL");                                                                                                                                        
	      legend->AddEntry(resp_balancingRatio_Extrap_EraG, "G", "PL"); 
	      }
      */
      legend->Draw();
      
      if(ii ==0){
	if(jj==0){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta0013.png"); 
	}else if(jj==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta0813.png"); 
	}else if(jj==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta1319.png"); 
	}else if(jj==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta1925.png"); 
	}else if(jj==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta2530.png"); 
	}else if(jj==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta3032.png"); 
	}else if(jj==6){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_Epochs_eta3252.png"); 
	}
      }else if(ii ==1){
	if(jj == 0){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta0013.png");
	}else if(jj ==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta0813.png");
	}else if(jj ==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta1319.png");
	}else if(jj ==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta1925.png");
	}else if(jj ==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta2530.png");
	}else if(jj ==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta3032.png");
	}else if(jj ==6){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_Epochs_eta3252.png");
	}
      }
      c1->Destructor();
  
    }
  }





}//main





