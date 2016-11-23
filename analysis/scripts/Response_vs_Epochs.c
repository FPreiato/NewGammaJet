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

  TFile f1("../tuples/2016-09-06_21730pb/EraB/AlphaCut030/PhotonJetPlots_SinglePhoton__Run2016B-2016-09-06_alphacut030_vs_GJet-2016-09-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraB;
  TGraphErrors *resp_mpfRatio_EraB;
  TGraphErrors *resp_balancingRatio_Extrap_EraB;
  TGraphErrors *resp_mpfRatio_Extrap_EraB;

  TFile f2("../tuples/2016-09-06_21730pb/EraC/AlphaCut030/PhotonJetPlots_SinglePhoton__Run2016C-2016-09-06_alphacut030_vs_GJet-2016-09-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraC;
  TGraphErrors *resp_mpfRatio_EraC;
  TGraphErrors *resp_balancingRatio_Extrap_EraC;
  TGraphErrors *resp_mpfRatio_Extrap_EraC;

  TFile f3("../tuples/2016-09-06_21730pb/EraD/AlphaCut030/PhotonJetPlots_SinglePhoton__Run2016D-2016-09-06_alphacut030_vs_GJet-2016-09-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraD;
  TGraphErrors *resp_mpfRatio_EraD;
  TGraphErrors *resp_balancingRatio_Extrap_EraD;
  TGraphErrors *resp_mpfRatio_Extrap_EraD;

  TFile f4("../tuples/2016-09-06_21730pb/EraE/AlphaCut030/PhotonJetPlots_SinglePhoton__Run2016E-2016-09-06_alphacut030_vs_GJet-2016-09-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraE;
  TGraphErrors *resp_mpfRatio_EraE;
  TGraphErrors *resp_balancingRatio_Extrap_EraE;
  TGraphErrors *resp_mpfRatio_Extrap_EraE;
  
  TFile f5("../tuples/2016-09-06_21730pb/EraF/AlphaCut030/PhotonJetPlots_SinglePhoton__Run2016F-2016-09-06_alphacut030_vs_GJet-2016-09-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraF;
  TGraphErrors *resp_mpfRatio_EraF;
  TGraphErrors *resp_balancingRatio_Extrap_EraF;
  TGraphErrors *resp_mpfRatio_Extrap_EraF;

  TFile f6("../tuples/2016-09-06_21730pb/EraG_NewData/AlphaCut030/PhotonJetPlots_SinglePhoton_2016-09-14_alphacut030_vs_GJet_2016-09-14_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TGraphErrors *resp_balancingRatio_EraG;
  TGraphErrors *resp_mpfRatio_EraG;
  TGraphErrors *resp_balancingRatio_Extrap_EraG;
  TGraphErrors *resp_mpfRatio_Extrap_EraG;

  TLegend* legend = new TLegend(0.70, 0.68, 0.90, 0.88);                                                                                                                      
  legend->SetTextFont(42);                                                                                                                                                    
  legend->SetBorderSize(0);                                                                                                                                                   
  legend->SetFillColor(kWhite);                                                                                                                                               
  legend->SetFillStyle(0);                                                                                                                                                    
  legend->SetTextSize(0.036);                                                                                                                                                 
  legend->SetHeader("Epoch: ");                                                                                                                                  

  gStyle -> SetOptStat(kFALSE); 
  TH2* h2_axes_lo_resp = NULL;
  h2_axes_lo_resp = new TH2D("axes_lo_resp", "", 10, 40, 2000 , 10, 0.86, 1.14);

  for( int ii =0 ; ii<2 ; ii++){  
    for( int jj =0 ; jj<5 ; jj++){  

      std::cout<< ii << " "<< jj << std::endl; 

      if(ii == 0){
	if(jj ==0 ){
	  resp_balancingRatio_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_a30_eta00_13");
	}else if( jj == 1){
	  resp_balancingRatio_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta13_19");
	  resp_balancingRatio_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta13_19");
	  resp_balancingRatio_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta13_19");
	  resp_balancingRatio_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta13_19");
	  resp_balancingRatio_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_a30_eta13_19");
	  resp_balancingRatio_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_a30_eta13_19");
	}else if(jj == 2){
	  resp_balancingRatio_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta19_25");
	  resp_balancingRatio_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta19_25");
	  resp_balancingRatio_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta19_25");
	  resp_balancingRatio_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta19_25");
	  resp_balancingRatio_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_a30_eta19_25");
	  resp_balancingRatio_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_a30_eta19_25");
	}else if(jj == 3){
	  resp_balancingRatio_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta25_30");
	  resp_balancingRatio_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta25_30");
	  resp_balancingRatio_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta25_30");
	  resp_balancingRatio_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta25_30");
	  resp_balancingRatio_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_a30_eta25_30");
	  resp_balancingRatio_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_a30_eta25_30");
	}else if(jj == 4){
	  resp_balancingRatio_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta30_32");
	  resp_balancingRatio_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta30_32");
	  resp_balancingRatio_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta30_32");
	  resp_balancingRatio_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta30_32");
	  resp_balancingRatio_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_a30_eta30_32");
	  resp_balancingRatio_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_a30_eta30_32");
	}else if(jj == 5){
	  resp_balancingRatio_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta32_52");
	  resp_balancingRatio_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta32_52");
	  resp_balancingRatio_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_a30_eta32_52");
	  resp_balancingRatio_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_a30_eta32_52");
	  resp_balancingRatio_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_a30_eta32_52");
	  resp_balancingRatio_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_a30_eta32_52");
	}
      }else if(ii == 1){
	if(jj ==0 ){
	  resp_mpfRatio_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_a30_eta00_13");
	  resp_mpfRatio_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_a30_eta00_13");
	}else if( jj == 1){
	  resp_mpfRatio_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta13_19");
	  resp_mpfRatio_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta13_19");
	  resp_mpfRatio_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta13_19");
	  resp_mpfRatio_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta13_19");
	  resp_mpfRatio_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_a30_eta13_19");
	  resp_mpfRatio_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_a30_eta13_19");
	}else if(jj == 2){
	  resp_mpfRatio_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta19_25");
	  resp_mpfRatio_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta19_25");
	  resp_mpfRatio_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta19_25");
	  resp_mpfRatio_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta19_25");
	  resp_mpfRatio_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_a30_eta19_25");
	  resp_mpfRatio_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_a30_eta19_25");
	}else if(jj == 3){
	  resp_mpfRatio_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta25_30");
	  resp_mpfRatio_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta25_30");
	  resp_mpfRatio_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta25_30");
	  resp_mpfRatio_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta25_30");
	  resp_mpfRatio_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_a30_eta25_30");
	  resp_mpfRatio_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_a30_eta25_30");
	}else if(jj == 4){
	  resp_mpfRatio_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta30_32");
	  resp_mpfRatio_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta30_32");
	  resp_mpfRatio_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta30_32");
	  resp_mpfRatio_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta30_32");
	  resp_mpfRatio_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_a30_eta30_32");
	  resp_mpfRatio_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_a30_eta30_32");
	}else if(jj == 5){
	  resp_mpfRatio_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta32_52");
	  resp_mpfRatio_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta32_52");
	  resp_mpfRatio_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_a30_eta32_52");
	  resp_mpfRatio_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_a30_eta32_52");
	  resp_mpfRatio_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_a30_eta32_52");
	  resp_mpfRatio_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_a30_eta32_52");
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
      resp_balancingRatio_EraB -> SetMarkerColor(1);  
      resp_balancingRatio_EraB -> SetLineColor(1); 
      resp_balancingRatio_EraB -> SetMarkerStyle(20);  
      resp_balancingRatio_EraC -> SetMarkerColor(2);  
      resp_balancingRatio_EraC -> SetLineColor(2); 
      resp_balancingRatio_EraC -> SetMarkerStyle(21);  
      resp_balancingRatio_EraD -> SetMarkerColor(3);  
      resp_balancingRatio_EraD -> SetLineColor(3); 
      resp_balancingRatio_EraD -> SetMarkerStyle(22);  
      resp_balancingRatio_EraE -> SetMarkerColor(4);  
      resp_balancingRatio_EraE -> SetLineColor(4);  
      resp_balancingRatio_EraE -> SetMarkerStyle(23);  
      resp_balancingRatio_EraF -> SetMarkerColor(6);  
      resp_balancingRatio_EraF -> SetLineColor(6);  
      resp_balancingRatio_EraF -> SetMarkerStyle(29);  
      resp_balancingRatio_EraG -> SetMarkerColor(9);  
      resp_balancingRatio_EraG -> SetLineColor(9);  
      resp_balancingRatio_EraG -> SetMarkerStyle(33);  
      resp_balancingRatio_EraB-> Draw("PSAME");
      resp_balancingRatio_EraC-> Draw("PSAME");
      resp_balancingRatio_EraD-> Draw("PSAME");
      resp_balancingRatio_EraE-> Draw("PSAME");
      resp_balancingRatio_EraF-> Draw("PSAME");
      resp_balancingRatio_EraG-> Draw("PSAME");
      }else if(ii == 1){
      resp_mpfRatio_EraB -> SetMarkerColor(1);  
      resp_mpfRatio_EraB -> SetLineColor(1); 
      resp_mpfRatio_EraB -> SetMarkerStyle(20);  
      resp_mpfRatio_EraC -> SetMarkerColor(2);  
      resp_mpfRatio_EraC -> SetLineColor(2); 
      resp_mpfRatio_EraC -> SetMarkerStyle(21);  
      resp_mpfRatio_EraD -> SetMarkerColor(3);  
      resp_mpfRatio_EraD -> SetLineColor(3); 
      resp_mpfRatio_EraD -> SetMarkerStyle(22);  
      resp_mpfRatio_EraE -> SetMarkerColor(4);  
      resp_mpfRatio_EraE -> SetLineColor(4);  
      resp_mpfRatio_EraE -> SetMarkerStyle(23);  
      resp_mpfRatio_EraF -> SetMarkerColor(6);  
      resp_mpfRatio_EraF -> SetLineColor(6);  
      resp_mpfRatio_EraF -> SetMarkerStyle(29);  
      resp_mpfRatio_EraG -> SetMarkerColor(9);  
      resp_mpfRatio_EraG -> SetLineColor(9);  
      resp_mpfRatio_EraG -> SetMarkerStyle(33);  
      resp_mpfRatio_EraB-> Draw("PSAME");
      resp_mpfRatio_EraC-> Draw("PSAME");
      resp_mpfRatio_EraD-> Draw("PSAME");
      resp_mpfRatio_EraE-> Draw("PSAME");
      resp_mpfRatio_EraF-> Draw("PSAME");
      resp_mpfRatio_EraG-> Draw("PSAME");
      }
      
      if(ii == 0 && jj ==0){
	legend->AddEntry(resp_balancingRatio_EraB, "B", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_EraC, "C", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_EraD, "D", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_EraE, "E", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_EraF, "F", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_EraG, "G", "PL"); 
      }
      
      legend->Draw();
      
      if(ii ==0){
	if(jj==0){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_vs_Epochs_eta0013.png"); 
	}else if(jj==1){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_vs_Epochs_eta1319.png"); 
	}else if(jj==2){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_vs_Epochs_eta1925.png"); 
	}else if(jj==3){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_vs_Epochs_eta2530.png"); 
	}else if(jj==4){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_vs_Epochs_eta3032.png"); 
	}else if(jj==5){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_vs_Epochs_eta3252.png"); 
	}
      }else if(ii ==1){
	if(jj == 0){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_vs_Epochs_eta0013.png");
	}else if(jj ==1){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_vs_Epochs_eta1319.png");
	}else if(jj ==2){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_vs_Epochs_eta1925.png");
	}else if(jj ==3){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_vs_Epochs_eta2530.png");
	}else if(jj ==4){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_vs_Epochs_eta3032.png");
	}else if(jj ==5){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_vs_Epochs_eta3252.png");
	}
      }
      c1->Destructor();
  
    }
  }


  ////////////////////// EXTRAPOLATED

  for( int ii =0 ; ii<2 ; ii++){  
    for( int jj =0 ; jj<5 ; jj++){  

      std::cout<< ii << " "<< jj << std::endl; 

      if(ii == 0){
	if(jj ==0 ){
	  resp_balancingRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta00_13");	  
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_extrap_a30_eta00_13");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_extrap_a30_eta00_13");
	}else if( jj == 1){
	  resp_balancingRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  resp_balancingRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  resp_balancingRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta13_19");	  
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_extrap_a30_eta13_19");
	}else if(jj == 2){
	  resp_balancingRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  resp_balancingRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  resp_balancingRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta19_25");	  
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_extrap_a30_eta19_25");
	}else if(jj == 3){
	  resp_balancingRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  resp_balancingRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  resp_balancingRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta25_30");	  
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_extrap_a30_eta25_30");
	}else if(jj == 4){
	  resp_balancingRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  resp_balancingRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  resp_balancingRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta30_32");	  
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_extrap_a30_eta30_32");
	}else if(jj == 5){
	  resp_balancingRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  resp_balancingRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  resp_balancingRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  resp_balancingRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_PtBalchs_extrap_a30_eta32_52");	  
	  resp_balancingRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_PtBalchs_extrap_a30_eta32_52");
	}
      }else if(ii == 1){
	if(jj ==0 ){
	  resp_mpfRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta00_13");	  
	  resp_mpfRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta00_13");
	  resp_mpfRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta00_13");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta00_13");	  
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_extrap_a30_eta00_13");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_extrap_a30_eta00_13");
	}else if( jj == 1){
	  resp_mpfRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta13_19");	  
	  resp_mpfRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta13_19");
	  resp_mpfRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta13_19");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta13_19");	  
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_extrap_a30_eta13_19");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_extrap_a30_eta13_19");
	}else if(jj == 2){
	  resp_mpfRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta19_25");	  
	  resp_mpfRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta19_25");
	  resp_mpfRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta19_25");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta19_25");	  
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_extrap_a30_eta19_25");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_extrap_a30_eta19_25");
	}else if(jj == 3){
	  resp_mpfRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta25_30");	  
	  resp_mpfRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta25_30");
	  resp_mpfRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta25_30");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta25_30");	  
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_extrap_a30_eta25_30");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_extrap_a30_eta25_30");
	}else if(jj == 4){
	  resp_mpfRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta30_32");	  
	  resp_mpfRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta30_32");
	  resp_mpfRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta30_32");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta30_32");	  
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_extrap_a30_eta30_32");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_extrap_a30_eta30_32");
	}else if(jj == 5){
	  resp_mpfRatio_Extrap_EraB = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta32_52");	  
	  resp_mpfRatio_Extrap_EraC = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta32_52");
	  resp_mpfRatio_Extrap_EraD = (TGraphErrors*)f3.Get("resp_MPFchs_extrap_a30_eta32_52");
	  resp_mpfRatio_Extrap_EraE = (TGraphErrors*)f4.Get("resp_MPFchs_extrap_a30_eta32_52");	  
	  resp_mpfRatio_Extrap_EraF = (TGraphErrors*)f5.Get("resp_MPFchs_extrap_a30_eta32_52");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f6.Get("resp_MPFchs_extrap_a30_eta32_52");
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
      resp_balancingRatio_Extrap_EraB -> SetMarkerColor(1);  
      resp_balancingRatio_Extrap_EraB -> SetLineColor(1); 
      resp_balancingRatio_Extrap_EraB -> SetMarkerStyle(20);  
      resp_balancingRatio_Extrap_EraC -> SetMarkerColor(2);  
      resp_balancingRatio_Extrap_EraC -> SetLineColor(2); 
      resp_balancingRatio_Extrap_EraC -> SetMarkerStyle(21);  
      resp_balancingRatio_Extrap_EraD -> SetMarkerColor(3);  
      resp_balancingRatio_Extrap_EraD -> SetLineColor(3); 
      resp_balancingRatio_Extrap_EraD -> SetMarkerStyle(22);  
      resp_balancingRatio_Extrap_EraE -> SetMarkerColor(4);  
      resp_balancingRatio_Extrap_EraE -> SetLineColor(4);  
      resp_balancingRatio_Extrap_EraE -> SetMarkerStyle(23);  
      resp_balancingRatio_Extrap_EraF -> SetMarkerColor(6);  
      resp_balancingRatio_Extrap_EraF -> SetLineColor(6);  
      resp_balancingRatio_Extrap_EraF -> SetMarkerStyle(29);  
      resp_balancingRatio_Extrap_EraG -> SetMarkerColor(9);  
      resp_balancingRatio_Extrap_EraG -> SetLineColor(9);  
      resp_balancingRatio_Extrap_EraG -> SetMarkerStyle(33);  
      resp_balancingRatio_Extrap_EraB-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraC-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraD-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraE-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraF-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraG-> Draw("PSAME");
      }else if(ii == 1){
      resp_mpfRatio_Extrap_EraB -> SetMarkerColor(1);  
      resp_mpfRatio_Extrap_EraB -> SetLineColor(1); 
      resp_mpfRatio_Extrap_EraB -> SetMarkerStyle(20);  
      resp_mpfRatio_Extrap_EraC -> SetMarkerColor(2);  
      resp_mpfRatio_Extrap_EraC -> SetLineColor(2); 
      resp_mpfRatio_Extrap_EraC -> SetMarkerStyle(21);  
      resp_mpfRatio_Extrap_EraD -> SetMarkerColor(3);  
      resp_mpfRatio_Extrap_EraD -> SetLineColor(3); 
      resp_mpfRatio_Extrap_EraD -> SetMarkerStyle(22);  
      resp_mpfRatio_Extrap_EraE -> SetMarkerColor(4);  
      resp_mpfRatio_Extrap_EraE -> SetLineColor(4);  
      resp_mpfRatio_Extrap_EraE -> SetMarkerStyle(23);  
      resp_mpfRatio_Extrap_EraF -> SetMarkerColor(6);  
      resp_mpfRatio_Extrap_EraF -> SetLineColor(6);  
      resp_mpfRatio_Extrap_EraF -> SetMarkerStyle(29);  
      resp_mpfRatio_Extrap_EraG -> SetMarkerColor(9);  
      resp_mpfRatio_Extrap_EraG -> SetLineColor(9); 
      resp_mpfRatio_Extrap_EraG -> SetMarkerStyle(33);  
      resp_mpfRatio_Extrap_EraB-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraC-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraD-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraE-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraF-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraG-> Draw("PSAME");
      }
      /*
      if(ii == 0 && jj == 0){
	legend->AddEntry(resp_balancingRatio_Extrap_EraB, "B", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_Extrap_EraC, "C", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_Extrap_EraD, "D", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_Extrap_EraE, "E", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_Extrap_EraF, "F", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_Extrap_EraG, "G", "PL"); 
      }
      */
      legend->Draw();
      
      if(ii ==0){
	if(jj==0){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_Extrap_vs_Epochs_eta0013.png"); 
	}else if(jj==1){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_Extrap_vs_Epochs_eta1319.png"); 
	}else if(jj==2){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_Extrap_vs_Epochs_eta1925.png"); 
	}else if(jj==3){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_Extrap_vs_Epochs_eta2530.png"); 
	}else if(jj==4){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_Extrap_vs_Epochs_eta3032.png"); 
	}else if(jj==5){
	  c1->SaveAs("Response_vs_Epochs/BalancingRatio_Extrap_vs_Epochs_eta3252.png"); 
	}
      }else if(ii ==1){
	if(jj == 0){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_Extrap_vs_Epochs_eta0013.png");
	}else if(jj ==1){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_Extrap_vs_Epochs_eta1319.png");
	}else if(jj ==2){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_Extrap_vs_Epochs_eta1925.png");
	}else if(jj ==3){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_Extrap_vs_Epochs_eta2530.png");
	}else if(jj ==4){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_Extrap_vs_Epochs_eta3032.png");
	}else if(jj ==5){
	  c1->SaveAs("Response_vs_Epochs/MPFRatio_Extrap_vs_Epochs_eta3252.png");
	}
      }
      c1->Destructor();
  
    }
  }
















}//main





