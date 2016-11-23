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

  //  TFile f1("../tuples/2016-09-06_21730pb/EraG_NewData/AlphaCut030/PhotonJetPlots_SinglePhoton_2016-09-14_alphacut030_vs_GJet_2016-09-14_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TFile f1("../tuples/2016-09-06_21730pb/EraEF/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016EF-2016-09-08_alphacut030_vs_GJet-2016-09-08_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root");
  // TFile f1("../tuples/2016-09-06_21730pb/EraBCD/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016BCD-2016-09-06_alphacut030_vs_GJet-2016-09-06_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root");

  TGraphErrors *resp_balancingRatio_EraG;
  TGraphErrors *resp_mpfRatio_EraG;
  TGraphErrors *resp_balancingRatio_Extrap_EraG;
  TGraphErrors *resp_mpfRatio_Extrap_EraG;

  //  TFile f2("../tuples/2016-09-22_21730pb_CorrectingPhoton_EoverP/EraG/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016G-2016-09-29_alphacut030_vs_GJet-2016-09-29_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  TFile f2("../tuples/2016-09-22_21730pb_CorrectingPhoton_EoverP/EraEF/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016EF_2016-09-29_alphacut030_vs_GJet_2016-09-29_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 
  // TFile f2("../tuples/2016-09-22_21730pb_CorrectingPhoton_EoverP/EraBCD/AlphaCut030/PhotonJetPlots_SinglePhoton_Run2016BCD_2016-09-29_alphacut030_vs_GJet_2016-09-29_alphacut030_PFlowAK4chs_LUMI_vs_pt/plots.root"); 

  TGraphErrors *resp_balancingRatio_EraG_Corr;
  TGraphErrors *resp_mpfRatio_EraG_Corr;
  TGraphErrors *resp_balancingRatio_Extrap_EraG_Corr;
  TGraphErrors *resp_mpfRatio_Extrap_EraG_Corr;

  TLegend* legend = new TLegend(0.50, 0.70, 0.80, 0.90);                                                                                                                      
  legend->SetTextFont(42);                                                                                                                                                    
  legend->SetBorderSize(0);                                                                                                                                                   
  legend->SetFillColor(kWhite);                                                                                                                                               
  legend->SetFillStyle(0);                                                                                                                                                    
  legend->SetTextSize(0.036);                                                                                                                                                 
  legend->SetHeader("Run2016EF: ");                                                                                                                                  

  gStyle -> SetOptStat(kFALSE); 
  TH2* h2_axes_lo_resp = NULL;
  h2_axes_lo_resp = new TH2D("axes_lo_resp", "", 10, 40, 2000 , 10, 0.86, 1.14);

  for( int ii =0 ; ii<2 ; ii++){  
    for( int jj =0 ; jj<5 ; jj++){  

      std::cout<< ii << " "<< jj << std::endl; 

      if(ii == 0){
	if(jj ==0 ){
	  resp_balancingRatio_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta00_13");
	  resp_balancingRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta00_13");
       	}else if( jj == 1){
	  resp_balancingRatio_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta13_19");
	  resp_balancingRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta13_19");
	}else if(jj == 2){
	  resp_balancingRatio_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta19_25");
	  resp_balancingRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta19_25");
	}else if(jj == 3){
	  resp_balancingRatio_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta25_30");
	  resp_balancingRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta25_30");
	}else if(jj == 4){
	  resp_balancingRatio_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta30_32");
	  resp_balancingRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta30_32");
	}else if(jj == 5){
	  resp_balancingRatio_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_a30_eta32_52");
	  resp_balancingRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_PtBalchs_a30_eta32_52");
	}
      }else if(ii == 1){
	if(jj ==0 ){
	  resp_mpfRatio_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta00_08");
	  resp_mpfRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta00_08");
       	}else if( jj == 1){
	  resp_mpfRatio_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta13_19");
	  resp_mpfRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta13_19");
	}else if(jj == 2){
	  resp_mpfRatio_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta19_25");	  
	  resp_mpfRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta19_25");
	}else if(jj == 3){
	  resp_mpfRatio_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta25_30");
	  resp_mpfRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta25_30");
	}else if(jj == 4){
	  resp_mpfRatio_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta30_32");
	  resp_mpfRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta30_32");
	}else if(jj == 5){
	  resp_mpfRatio_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_a30_eta32_52");
	  resp_mpfRatio_EraG_Corr = (TGraphErrors*)f2.Get("resp_MPFchs_a30_eta32_52");
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
      resp_balancingRatio_EraG -> SetMarkerColor(kRed);  
      resp_balancingRatio_EraG -> SetLineColor(kRed);
      resp_balancingRatio_EraG -> SetMarkerStyle(20);  
      resp_balancingRatio_EraG_Corr -> SetMarkerColor(kBlue);  
      resp_balancingRatio_EraG_Corr -> SetLineColor(kBlue);  
      resp_balancingRatio_EraG_Corr -> SetMarkerStyle(21);  
      resp_balancingRatio_EraG-> Draw("PSAME");
      resp_balancingRatio_EraG_Corr-> Draw("PSAME");
      }else if(ii == 1){
      resp_mpfRatio_EraG -> SetMarkerColor(kRed);  
      resp_mpfRatio_EraG -> SetLineColor(kRed); 
      resp_mpfRatio_EraG -> SetMarkerStyle(20);  
      resp_mpfRatio_EraG_Corr -> SetMarkerColor(kBlue);  
      resp_mpfRatio_EraG_Corr -> SetLineColor(kBlue);  
      resp_mpfRatio_EraG_Corr -> SetMarkerStyle(21);  
      resp_mpfRatio_EraG-> Draw("PSAME");
      resp_mpfRatio_EraG_Corr-> Draw("PSAME");
      }
      
      if(ii == 0 && jj == 0){
	legend->AddEntry(resp_balancingRatio_EraG, "No photon scale Corr.", "PL");                                                                                                                                        
	legend->AddEntry(resp_balancingRatio_EraG_Corr, "Photon scale correction", "PL");                                                                                                                                        
      }
      
      legend->Draw();
      
      if(ii ==0){
	if(jj==0){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_EraEF_eta0013.png"); 
       	}else if(jj==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_EraEF_eta1319.png"); 
	}else if(jj==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_EraEF_eta1925.png"); 
	}else if(jj==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_EraEF_eta2530.png"); 
	}else if(jj==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_EraEF_eta3032.png"); 
	}else if(jj==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_vs_EraEF_eta3252.png"); 
	}
      }else if(ii ==1){
	if(jj == 0){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_EraEF_eta0013.png");
       	}else if(jj ==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_EraEF_eta1319.png");
	}else if(jj ==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_EraEF_eta1925.png");
	}else if(jj ==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_EraEF_eta2530.png");
	}else if(jj ==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_EraEF_eta3032.png");
	}else if(jj ==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_vs_EraEF_eta3252.png");
	}
      }
      c1->Destructor();
  
    }
  }

  /*
  ////////////////////// EXTRAPOLATED

  for( int ii =0 ; ii<2 ; ii++){  
    for( int jj =0 ; jj<6 ; jj++){  

      std::cout<< ii << " "<< jj << std::endl; 

      if(ii == 0){
	if(jj ==0 ){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta00_08");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta00_08");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta00_08");
	}else if( jj == 1){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta08_13");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta08_13");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta08_13");
	}else if( jj == 2){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta13_19");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta13_19");
	}else if(jj == 3){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta19_25");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta19_25");
	}else if(jj == 4){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta25_30");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta25_30");
	}else if(jj == 5){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta30_32");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta30_32");
	}else if(jj == 6){
	  resp_balancingRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  resp_balancingRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_PtBalchs_extrap_a30_eta32_52");
	  resp_balancingRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_PtBalchs_extrap_a30_eta32_52");
	}
      }else if(ii == 1){
	if(jj ==0 ){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta00_08");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta00_08");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta00_08");
	}else if( jj == 1){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta08_13");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta08_13");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta08_13");
	}else if( jj == 2){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta13_19");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta13_19");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta13_19");
	}else if(jj == 3){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta19_25");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta19_25");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta19_25");
	}else if(jj == 4){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta25_30");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta25_30");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta25_30");
	}else if(jj == 5){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta30_32");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta30_32");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta30_32");
	}else if(jj == 6){
	  resp_mpfRatio_Extrap_EraBCD = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta32_52");
	  resp_mpfRatio_Extrap_EraEF = (TGraphErrors*)f2.Get("resp_MPFchs_extrap_a30_eta32_52");
	  resp_mpfRatio_Extrap_EraG = (TGraphErrors*)f1.Get("resp_MPFchs_extrap_a30_eta32_52");
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
      resp_balancingRatio_Extrap_EraEF -> SetMarkerColor(kBlue);  
      resp_balancingRatio_Extrap_EraEF -> SetLineColor(kBlue);  
      resp_balancingRatio_Extrap_EraEF -> SetMarkerStyle(21);  
      resp_balancingRatio_Extrap_EraG -> SetMarkerColor(kGreen);  
      resp_balancingRatio_Extrap_EraG -> SetLineColor(kGreen);  
      resp_balancingRatio_Extrap_EraG -> SetMarkerStyle(22);  
      resp_balancingRatio_Extrap_EraBCD-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraEF-> Draw("PSAME");
      resp_balancingRatio_Extrap_EraG-> Draw("PSAME");
      }else if(ii == 1){
      resp_mpfRatio_Extrap_EraBCD -> SetMarkerColor(kRed);  
      resp_mpfRatio_Extrap_EraBCD -> SetLineColor(kRed); 
      resp_mpfRatio_Extrap_EraBCD -> SetMarkerStyle(20);  
      resp_mpfRatio_Extrap_EraEF -> SetMarkerColor(kBlue);  
      resp_mpfRatio_Extrap_EraEF -> SetLineColor(kBlue);  
      resp_mpfRatio_Extrap_EraEF -> SetMarkerStyle(21);  
      resp_mpfRatio_Extrap_EraG -> SetMarkerColor(kGreen);  
      resp_mpfRatio_Extrap_EraG -> SetLineColor(kGreen); 
      resp_mpfRatio_Extrap_EraG -> SetMarkerStyle(22);  
      resp_mpfRatio_Extrap_EraBCD-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraEF-> Draw("PSAME");
      resp_mpfRatio_Extrap_EraG-> Draw("PSAME");
      }

     // if(ii == 0 && jj ==0){
     //	legend->AddEntry(resp_balancingRatio_Extrap_EraBCD, "B+C+D", "PL");                                                                                                                                        
     //	legend->AddEntry(resp_balancingRatio_Extrap_EraEF, "E+F", "PL");                                                                                                                                        
     //	legend->AddEntry(resp_balancingRatio_Extrap_EraG, "G", "PL"); 
     //   }

      legend->Draw();
      
      if(ii ==0){
	if(jj==0){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta0008.png"); 
	}else if(jj==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta0813.png"); 
	}else if(jj==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta1319.png"); 
	}else if(jj==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta1925.png"); 
	}else if(jj==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta2530.png"); 
	}else if(jj==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta3032.png"); 
	}else if(jj==6){
	  c1->SaveAs("Response_vs_Epochs_Merged/BalancingRatio_Extrap_vs_EraEF_eta3252.png"); 
	}
      }else if(ii ==1){
	if(jj == 0){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta0008.png");
	}else if(jj ==1){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta0813.png");
	}else if(jj ==2){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta1319.png");
	}else if(jj ==3){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta1925.png");
	}else if(jj ==4){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta2530.png");
	}else if(jj ==5){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta3032.png");
	}else if(jj ==6){
	  c1->SaveAs("Response_vs_Epochs_Merged/MPFRatio_Extrap_vs_EraEF_eta3252.png");
	}
      }
      c1->Destructor();
  
    }
}
*/




}//main





