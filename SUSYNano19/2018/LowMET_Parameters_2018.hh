#ifndef ESTTOOLS_LMPARAMETERS_HH_
#define ESTTOOLS_LMPARAMETERS_HH_

#include "../../utils/EstHelper.hh"

namespace EstTools{

const TString inputdir = "root://cmseos.fnal.gov//store/user/mkilpatr/13TeV/";
const TString inputdir_2016 = "nanoaod_all_skim_2016_120419_limits/";
const TString inputdir_2017 = "nanoaod_all_skim_2017_120419_limits/";
const TString inputdir_2018 = "nanoaod_all_skim_2018_120419_limits/";
const TString inputdir_sig  = "nanoaod_SBv3_2016_081219/";

const TString outputdir = "LowMET";

const TString datadir = "nanoaod_data_all_skim_120419_limits/";

const TString lumistr = "136.722688";
const TString lumistr_2016 = "35.815165"; //Units are in pb
const TString lumistr_2017RunBtoE = "27.987721";
const TString lumistr_2017RunF    = "13.220313";
const TString lumistr_2018PreHEM  = "21.068576";
const TString lumistr_2018PostHEM = "38.630913";

TString getLumi(){return lumistr(TRegexp("[0-9]+.[0-9]"));}

// lumi and base weight
const TString wgtvar = lumistr_2016+"*1000*Stop0l_evtWeight*puWeight*BTagWeight*PrefireWeight*WtagSF*TopSF*SoftBSF*restopSF";// //2016
const TString wgtvar_RunBtoE = lumistr_2017RunBtoE+"*1000*Stop0l_evtWeight*17BtoEpuWeight*BTagWeight*PrefireWeight*WtagSF*TopSF*SoftBSF*restopSF";// //2017
const TString wgtvar_RunF = lumistr_2017RunF+"*1000*Stop0l_evtWeight*17FpuWeight*BTagWeight*PrefireWeight*WtagSF*TopSF*SoftBSF*restopSF";// //2017
const TString wgtvar_preHEM = lumistr_2018PreHEM+"*1000*Stop0l_evtWeight*puWeight*BTagWeight*WtagSF*TopSF*SoftBSF*restopSF";// //2018
const TString wgtvar_postHEM = lumistr_2018PostHEM+"*1000*Stop0l_evtWeight*puWeight*BTagWeight*WtagSF*TopSF*SoftBSF*restopSF";// //2018

// photon trigger eff.
const TString phowgt = wgtvar;
//const TString phowgt = wgtvar + "*qcdRespTailWeight";

// No Lepton SF
//const TString lepvetowgt = wgtvar;
//const TString lepselwgt  = wgtvar;
//const TString vetoes = " && nvetolep==0 && nvetotau==0";

// Tag-and-Probe Lepton SF
const TString lepvetowgt =      	wgtvar		+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseSRSF*ElectronVetoSRSF*TauSRSF";
const TString lepselwgt  =      	wgtvar		+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseCRSF*ElectronVetoCRSF";
const TString lepvetowgt_RunBtoE =      wgtvar_RunBtoE	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseSRSF*ElectronVetoSRSF*TauSRSF";
const TString lepselwgt_RunBtoE  =      wgtvar_RunBtoE	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseCRSF*ElectronVetoCRSF";
const TString lepvetowgt_RunF =         wgtvar_RunF	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseSRSF*ElectronVetoSRSF*TauSRSF";
const TString lepselwgt_RunF  =         wgtvar_RunF	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseCRSF*ElectronVetoCRSF";
const TString lepvetowgt_preHEM =       wgtvar_preHEM	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseSRSF*ElectronVetoSRSF*TauSRSF";
const TString lepselwgt_preHEM  =       wgtvar_preHEM	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseCRSF*ElectronVetoCRSF";
const TString lepvetowgt_postHEM =      wgtvar_postHEM	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseSRSF*ElectronVetoSRSF*TauSRSF";
const TString lepselwgt_postHEM  =      wgtvar_postHEM	+ "*Stop0l_trigger_eff_MET_loose_baseline*MuonLooseCRSF*ElectronVetoCRSF";
const TString vetoes = " && Pass_LeptonVeto";

// 1LCR Lepton SF
//const TString lepvetowgt = wgtvar + "*lepvetoweight";
//const TString lepselwgt  = wgtvar + "*lepselweight";
//const TString vetoes = " && ((nvetolep==0 && nvetotau==0) || (ismc && (ngoodgenele>0 || ngoodgenmu>0 || npromptgentau>0)))";

// sr weight w/o top/W SF
const TString lepvetowgt_no_wtopsf = lumistr_2016+"*1000*Stop0l_evtWeight*Stop0l_trigger_eff_MET_loose_baseline*puWeight*BTagWeight*ISRWeight*PrefireWeight";
const TString lepvetowgt_no_wtopsf_RunBtoE = lumistr_2017RunBtoE+"*1000*Stop0l_evtWeight*Stop0l_trigger_eff_MET_loose_baseline*17BtoEpuWeight*BTagWeight*PrefireWeight";
const TString lepvetowgt_no_wtopsf_RunF = lumistr_2017RunF+"*1000*Stop0l_evtWeight*Stop0l_trigger_eff_MET_loose_baseline*17FpuWeight*BTagWeight*PrefireWeight";
const TString lepvetowgt_no_wtopsf_preHEM = lumistr_2018PreHEM+"*1000*Stop0l_evtWeight*Stop0l_trigger_eff_MET_loose_baseline*puWeight*BTagWeight";
const TString lepvetowgt_no_wtopsf_postHEM = lumistr_2018PostHEM+"*1000*Stop0l_evtWeight*Stop0l_trigger_eff_MET_loose_baseline*puWeight*BTagWeight";

// 1Lep LLB method
bool ADD_LEP_TO_MET = false;
bool ICHEPCR = false;

bool SPLITTF = true; // split TF to CR-SR and SR-extrapolation
const TString revert_vetoes = " && Stop0l_nVetoElecMuon == 1 && Stop0l_MtLepMET < 100  && Pass_exHEMVetoElec30";

// MET+LEP LL method
//bool ADD_LEP_TO_MET = true;
const TString lepcrsel = " && Stop0l_nVetoElecMuon == 1 && Stop0l_MtLepMET < 100  && Pass_exHEMVetoElec30 && MET_pt>100";


// lepton trigger eff.
//const TString trigLepCR = " && (passtrige || passtrigmu)";
//const TString onelepcrwgt  = lepselwgt + "*trigEleWeight*trigMuWeight";

const TString trigLepCR = "";
const TString onelepcrwgt  = lepselwgt;

// qcd weights
const TString qcdwgt         = wgtvar + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline_QCD";
const TString qcdwgt_RunBtoE = wgtvar_RunBtoE + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline_QCD";
const TString qcdwgt_RunF    = wgtvar_RunF + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline_QCD";
const TString qcdwgt_preHEM  = wgtvar_preHEM + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline_QCD";
const TString qcdwgt_postHEM = wgtvar_postHEM + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline_QCD";
const TString qcdvetowgt         = lepvetowgt + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline";
const TString qcdvetowgt_RunBtoE = lepvetowgt_RunBtoE + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline";
const TString qcdvetowgt_RunF    = lepvetowgt_RunF + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline";
const TString qcdvetowgt_preHEM  = lepvetowgt_preHEM + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline";
const TString qcdvetowgt_postHEM = lepvetowgt_postHEM + "*qcdRespTailWeight*Stop0l_trigger_eff_MET_loose_baseline";


// signal weights
//const TString sigwgt = lepvetowgt + "*btagFastSimWeight*isrWeightTight*(0.85*(Stop0l_nSoftb>=1) + 1.0*(Stop0l_nSoftb==0))";
const TString sigwgt = lepvetowgt;

// triggers
const TString trigSR = " && Pass_trigger_MET";
const TString trigPhoCR = " && passtrigphoOR && origmet<200";
const TString phoBadEventRemoval = " && (!(lumi==189375 && event==430170481) && !(lumi==163479 && event==319690728) && !(lumi==24214 && event==55002562) && !(lumi==12510 && event==28415512) && !(lumi==16662 && event==32583938) && !(lumi==115657 && event==226172626) && !(lumi==149227 && event==431689582) && !(lumi==203626 && event==398201606))";
const TString trigDiLepCR = " && passtrigdilepOR && dileppt>200";
const TString datasel = " && Pass_EventFilter && Pass_HT && Pass_JetID && Pass_CaloMETRatio && (run < 319077 || (run >= 319077 && Pass_exHEMVeto30))";
const TString dataselHEM = " && Pass_EventFilter && Pass_HT && Pass_JetID && Pass_CaloMETRatio && (run >= 319077 || run == 1) && Pass_exHEMVeto30";
const TString qcdSpikeRemovals = "";
const TString dphi_invert = " && Pass_dPhiQCD";
const TString dphi_cut =   " && ( ((Stop0l_Mtb<175 && Stop0l_nTop==0 && Stop0l_nW==0 && Stop0l_nResolved==0) && Pass_dPhiMETLowDM) || (!(Stop0l_Mtb<175 && Stop0l_nTop==0 && Stop0l_nW==0 && Stop0l_nResolved==0) && Pass_dPhiMETHighDM) || ((Stop0l_Mtb<175 && Stop0l_nTop==0 && Stop0l_nW==0 && Stop0l_nResolved==0) && (Pass_dPhiMETMedDM)) )"; // ( ((passLM) && dPhiLM) || ((!passLM) && dPhiHM) )

// ------------------------------------------------------------------------
// search regions and control regions


const TString baseline = "Pass_MET && Pass_NJets30";

std::map<TString, TString> cutMap = []{
    // Underscore "_" not allowed in the names!!!
    std::map<TString, TString> cmap = {
	{"lmNoDPhi",  "Stop0l_ISRJetPt>=200 && Stop0l_nTop==0 && Stop0l_nW==0 && Stop0l_nResolved==0 && Stop0l_METSig>=10"},
        {"dPhiLM",    "Pass_dPhiMETLowDM"},
        {"hmNoDPhi",  "Stop0l_nJets>=5 && Stop0l_nbtags>=1"},
        {"dPhiHM",    "Pass_dPhiMETHighDM"},
        {"invertDPhi","Pass_dPhiQCD"},
        {"dPhiMedLM", "Pass_dPhiMETMedDM"},
	{"dPhiMedHM", "Pass_dPhiMET && !Pass_dPhiMETHighDM"},

        {"nb0",       "Stop0l_nbtags==0"},
        {"nb1",       "Stop0l_nbtags==1"},
        {"nbgeq1",    "Stop0l_nbtags>=1"},
        {"nb2",       "Stop0l_nbtags>=2"},
        {"nbeq2",     "Stop0l_nbtags==2"},
        {"nb3",       "Stop0l_nbtags>=3"},
        {"nivf0",     "Stop0l_nSoftb==0"},
        {"nivf1",     "Stop0l_nSoftb>=1"},
        {"lowptisr",  "Stop0l_ISRJetPt>=300 && Stop0l_ISRJetPt<500"},
        {"medptisr",  "Stop0l_ISRJetPt>=300"},
        {"highptisr", "Stop0l_ISRJetPt>=500"},
        {"nj2to5",    "Stop0l_nJets>=2 && Stop0l_nJets<=5"},
        {"nj5",       "Stop0l_nJets>=5"},
        {"nj6",       "Stop0l_nJets>=6"},
        {"nj7",       "Stop0l_nJets>=7"},
        {"lowmtb",    "Stop0l_Mtb<175"},
        {"highmtb",   "Stop0l_Mtb>=175"},
        {"lowptb",    "Stop0l_Ptb<40"},
        {"medptb",    "Stop0l_Ptb>=40 && Stop0l_Ptb<70"},
        {"highptb",   "Stop0l_Ptb>=70"},
        {"lowptb12",  "Stop0l_Ptb<80"},
        {"medptb12",  "Stop0l_Ptb>=80 && Stop0l_Ptb<140"},
        {"highptb12", "Stop0l_Ptb>=140"},
        {"nt0",       "Stop0l_nTop==0"},
        {"nt1",       "Stop0l_nTop==1"},
        {"nt2",       "Stop0l_nTop==2"},
        {"ntgeq1",    "Stop0l_nTop>=1"},
        {"nw0",       "Stop0l_nW==0"},
        {"nw1",       "Stop0l_nW==1"},
        {"nw2",       "Stop0l_nW==2"},
        {"nwgeq1",    "Stop0l_nW>=1"},
        {"nrt0",      "Stop0l_nResolved==0"},
        {"nrt1",      "Stop0l_nResolved==1"},
        {"nrt2",      "Stop0l_nResolved==2"},
        {"nrtgeq1",   "Stop0l_nResolved>=1"},
	{"nrtntnwgeq2", "(Stop0l_nTop+Stop0l_nResolved+Stop0l_nW) >= 2"},
	{"nrtntnwgeq3", "(Stop0l_nTop+Stop0l_nResolved+Stop0l_nW) >= 3"},
	{"met400",	"MET_pt < 400"},
	{"met300",	"MET_pt < 300"},
    };

    cmap["lm"] = createCutString("lmNoDPhi_dPhiLM", cmap);
    cmap["hm"] = createCutString("hmNoDPhi_dPhiHM", cmap);
    cmap["lmVal"] = createCutString("lmNoDPhi_dPhiMedLM", cmap);
    cmap["hmVal"] = createCutString("hmNoDPhi_dPhiMedHM", cmap);
    return cmap;
}();


std::vector<TString> srbins{
//---------- low deltaM ----------
  // 0b, 0 or >=1 ivf
  "lm_nb0_nivf0_highptisr_nj2to5_met400",
  "lm_nb0_nivf0_highptisr_nj6_met400",
  "lm_nb0_nivf1_highptisr_nj2to5_met400",
  "lm_nb0_nivf1_highptisr_nj6_met400",

  // 1b, 0 or >=1 ivf
  "lm_nb1_nivf0_lowmtb_lowptisr_lowptb_met300",
  "lm_nb1_nivf0_lowmtb_lowptisr_medptb_met300",
  "lm_nb1_nivf0_lowmtb_highptisr_lowptb_met400",
  "lm_nb1_nivf0_lowmtb_highptisr_medptb_met400",
  // ---
  "lm_nb1_nivf1_lowmtb_medptisr_lowptb_met300",

  // 2b
  "lm_nb2_lowmtb_lowptisr_lowptb12_met300",
  "lm_nb2_lowmtb_lowptisr_medptb12_met300",
  "lm_nb2_lowmtb_lowptisr_highptb12_nj7_met300",
  "lm_nb2_lowmtb_highptisr_lowptb12_met400",
  "lm_nb2_lowmtb_highptisr_medptb12_met400",
  "lm_nb2_lowmtb_highptisr_highptb12_nj7_met400",

  // Additional from Hui
  // 0b
  "lmVal_nb0_lowmtb_nivf0",
  "lmVal_nb0_lowmtb_nivf1",
  "lmVal_nbgeq1_lowmtb_nivf0",
  "lmVal_nbgeq1_lowmtb_nivf1",
  //---------- low deltaM ----------


  //---------- high deltaM ----------
  // low mtb
  "hmVal_nb1_lowmtb_nj7_nrtgeq1",
  "hmVal_nb2_lowmtb_nj7_nrtgeq1",

  // high mtb
  // 0 taggged
  "hmVal_nb1_highmtb_nj5_nt0_nrt0_nw0",
  "hmVal_nb2_highmtb_nj5_nt0_nrt0_nw0",

	// nb1
  // 1 tagged
  "hmVal_nb1_highmtb_nt1_nrt0_nw0",
  "hmVal_nb1_highmtb_nt0_nrt0_nw1",
  "hmVal_nb1_highmtb_nt0_nrt1_nw0",

  // 1+1
  "hmVal_nb1_highmtb_nrtntnwgeq2",

	// nb2
  // 1 tagged
  "hmVal_nb2_highmtb_nt1_nrt0_nw0",
  "hmVal_nb2_highmtb_nt0_nrt0_nw1",
  "hmVal_nb2_highmtb_nt0_nrt1_nw0",

  // 1+1
  "hmVal_nb2_highmtb_nrtntnwgeq2",
  
  //---------- high deltaM ----------
};

std::map<TString, TString> srcuts = []{
    std::map<TString, TString> cuts;
    for (auto name : srbins)
      cuts[name] = createCutString(name, cutMap);
    return cuts;
}();

std::map<TString, TString> srlabels=srcuts;// FIXME

std::map<TString, std::vector<int>> srMETbins{
//---------- low deltaM ----------
  // 0b, 0 or >=1 ivf
  {"lm_nb0_nivf0_highptisr_nj2to5_met400", 		{250, 400}},
  {"lm_nb0_nivf0_highptisr_nj6_met400", 		{250, 400}},
  {"lm_nb0_nivf1_highptisr_nj2to5_met400", 		{250, 400}},
  {"lm_nb0_nivf1_highptisr_nj6_met400", 		{250, 400}},

  // 1b, 0 or >=1 ivf
  {"lm_nb1_nivf0_lowmtb_lowptisr_lowptb_met300", 	{250, 300}},
  {"lm_nb1_nivf0_lowmtb_lowptisr_medptb_met300", 	{250, 300}},
  {"lm_nb1_nivf0_lowmtb_highptisr_lowptb_met400", 	{250, 400}},
  {"lm_nb1_nivf0_lowmtb_highptisr_medptb_met400", 	{250, 400}},
  // ---
  {"lm_nb1_nivf1_lowmtb_medptisr_lowptb_met300", 	{250, 300}},

  // 2b
  {"lm_nb2_lowmtb_lowptisr_lowptb12_met300", 		{250, 300}},
  {"lm_nb2_lowmtb_lowptisr_medptb12_met300", 		{250, 300}},
  {"lm_nb2_lowmtb_lowptisr_highptb12_nj7_met300", 	{250, 300}},
  {"lm_nb2_lowmtb_highptisr_lowptb12_met400", 		{250, 400}},
  {"lm_nb2_lowmtb_highptisr_medptb12_met400", 		{250, 400}},
  {"lm_nb2_lowmtb_highptisr_highptb12_nj7_met400", 	{250, 400}},

  // Additional from Hui
  // 0b
  {"lmVal_nb0_lowmtb_nivf0", 		{250, 1000}},
  {"lmVal_nb0_lowmtb_nivf1", 		{250, 1000}},
  {"lmVal_nbgeq1_lowmtb_nivf0", 	{250, 1000}},
  {"lmVal_nbgeq1_lowmtb_nivf1", 	{250, 1000}},
  //---------- low deltaM ----------


  //---------- high deltaM ----------
  // low mtb
  {"hmVal_nb1_lowmtb_nj7_nrtgeq1", 		{250, 400, 1000}},
  {"hmVal_nb2_lowmtb_nj7_nrtgeq1", 		{250, 400, 1000}},

  // high mtb
  // 0 taggged
  {"hmVal_nb1_highmtb_nj5_nt0_nrt0_nw0", 		{250, 400, 1000}},
  {"hmVal_nb2_highmtb_nj5_nt0_nrt0_nw0", 		{250, 400, 1000}},

	// nb1
  // 1 tagged
  {"hmVal_nb1_highmtb_nt1_nrt0_nw0", 		{250, 400, 1000}},
  {"hmVal_nb1_highmtb_nt0_nrt0_nw1", 		{250, 400, 1000}},
  {"hmVal_nb1_highmtb_nt0_nrt1_nw0", 		{250, 400, 1000}},

  // 1+1
  {"hmVal_nb1_highmtb_nrtntnwgeq2", 		{250, 400, 1000}},

	// nb2
  // 1 tagged
  {"hmVal_nb2_highmtb_nt1_nrt0_nw0", 		{250, 400, 1000}},
  {"hmVal_nb2_highmtb_nt0_nrt0_nw1", 		{250, 400, 1000}},
  {"hmVal_nb2_highmtb_nt0_nrt1_nw0", 		{250, 400, 1000}},

  // 1+1
  {"hmVal_nb2_highmtb_nrtntnwgeq2", 		{250, 400, 1000}},
  
  //---------- high deltaM ----------

};

// normalization cuts for Rz
std::map<TString, TString> normMap{
  {"lm_nb0_nivf0", createCutString("lmNoDPhi_nb0_nivf0", cutMap)},
  {"lm_nb0_nivf1", createCutString("lmNoDPhi_nb0_nivf1", cutMap)},
  {"lm_nb1_nivf0", createCutString("lmNoDPhi_nb1_nivf0", cutMap)},
  {"lm_nb1_nivf1", createCutString("lmNoDPhi_nb1_nivf1", cutMap)},
  {"lm_nb2",       createCutString("lmNoDPhi_nb2", cutMap)},

  {"hm_nb1",       createCutString("hmNoDPhi_nb1", cutMap)},
  {"hm_nb2",       createCutString("hmNoDPhi_nb2", cutMap)},
  {"hm_nbgeq1",    createCutString("hmNoDPhi_nbgeq1", cutMap)},
};

// normalize photon to Data after baseline+this cut to calc Sgamma
std::map<TString, TString> phoNormMap = []{
  if (ICHEPCR) return normMap;
  else return std::map<TString, TString>{
    {"lm_nb0", createCutString("lmNoDPhi_nb0", cutMap)},
    {"lm_nb1", createCutString("lmNoDPhi_nb1", cutMap)},
    {"lm_nb2", createCutString("lmNoDPhi_nb2", cutMap)},

    {"hm_nb1", createCutString("hmNoDPhi_nb1", cutMap)},
    {"hm_nb2", createCutString("hmNoDPhi_nb2", cutMap)},
    {"hm_nbgeq1",createCutString("hmNoDPhi_nbgeq1", cutMap)},
  };
}();

//std::map<TString, TString> phoNormMap = normMap;

std::map<TString, TString> phocrMapping{
//---------- low deltaM ----------
  // 0b, 0 or >=1 ivf
  {"lm_nb0_nivf0_highptisr_nj2to5_met400",        "lm_nb0_nivf0_highptisr_nj2to5_met400"},
  {"lm_nb0_nivf0_highptisr_nj6_met400",           "lm_nb0_nivf0_highptisr_nj6_met400"},
  {"lm_nb0_nivf1_highptisr_nj2to5_met400",        "lm_nb0_nivf1_highptisr_nj2to5_met400"},
  {"lm_nb0_nivf1_highptisr_nj6_met400",           "lm_nb0_nivf1_highptisr_nj6_met400"},
                                            
  // 1b, 0 or >=1 ivf                     
  {"lm_nb1_nivf0_lowmtb_lowptisr_lowptb_met300",  "lm_nb1_nivf0_lowmtb_lowptisr_lowptb_met300"},
  {"lm_nb1_nivf0_lowmtb_lowptisr_medptb_met300",  "lm_nb1_nivf0_lowmtb_lowptisr_medptb_met300"},
  {"lm_nb1_nivf0_lowmtb_highptisr_lowptb_met400", "lm_nb1_nivf0_lowmtb_highptisr_lowptb_met400"},
  {"lm_nb1_nivf0_lowmtb_highptisr_medptb_met400", "lm_nb1_nivf0_lowmtb_highptisr_medptb_met400"},
  // ---                                 
  {"lm_nb1_nivf1_lowmtb_medptisr_lowptb_met300",  "lm_nb1_nivf1_lowmtb_medptisr_lowptb_met300"},
                                            
  // 2b                                 
  {"lm_nb2_lowmtb_lowptisr_lowptb12_met300",      "lm_nb2_lowmtb_lowptisr_lowptb12_met300"},
  {"lm_nb2_lowmtb_lowptisr_medptb12_met300",      "lm_nb2_lowmtb_lowptisr_medptb12_met300"},
  {"lm_nb2_lowmtb_lowptisr_highptb12_nj7_met300", "lm_nb2_lowmtb_lowptisr_highptb12_nj7_met300"},
  {"lm_nb2_lowmtb_highptisr_lowptb12_met400",     "lm_nb2_lowmtb_highptisr_lowptb12_met400"},
  {"lm_nb2_lowmtb_highptisr_medptb12_met400",     "lm_nb2_lowmtb_highptisr_medptb12_met400"},
  {"lm_nb2_lowmtb_highptisr_highptb12_nj7_met400","lm_nb2_lowmtb_highptisr_highptb12_nj7_met400"},
                                            
  // Additional from Hui               
  // 0b                               
  {"lmVal_nb0_lowmtb_nivf0",     "lmVal_nb0_lowmtb_nivf0"},
  {"lmVal_nb0_lowmtb_nivf1",     "lmVal_nb0_lowmtb_nivf1"},
  {"lmVal_nbgeq1_lowmtb_nivf0",   "lmVal_nbgeq1_lowmtb_nivf0"},
  {"lmVal_nbgeq1_lowmtb_nivf1",   "lmVal_nbgeq1_lowmtb_nivf1"},
  //---------- low deltaM ---------- 
                                            
                                            
  //---------- high deltaM ---------- 
  // low mtb                         
  {"hmVal_nb1_lowmtb_nj7_nrtgeq1",            "hmVal_nb1_lowmtb_nj7_nrtgeq1"},
  {"hmVal_nb2_lowmtb_nj7_nrtgeq1",            "hmVal_nb2_lowmtb_nj7_nrtgeq1"},
                                            
  // high mtb                       
  // 0 taggged                     
  {"hmVal_nb1_highmtb_nj5_nt0_nrt0_nw0",      "hmVal_nb1_highmtb_nj5_nt0_nrt0_nw0"},
  {"hmVal_nb2_highmtb_nj5_nt0_nrt0_nw0",      "hmVal_nb2_highmtb_nj5_nt0_nrt0_nw0"},
                                            
        // nb1                    
  // 1 tagged                    
  {"hmVal_nb1_highmtb_nt1_nrt0_nw0",          "hmVal_nb1_highmtb_nt1_nrt0_nw0"},
  {"hmVal_nb1_highmtb_nt0_nrt0_nw1",          "hmVal_nb1_highmtb_nt0_nrt0_nw1"},
  {"hmVal_nb1_highmtb_nt0_nrt1_nw0",          "hmVal_nb1_highmtb_nt0_nrt1_nw0"},
                                            
  // 1+1                        
  {"hmVal_nb1_highmtb_nrtntnwgeq2",           "hmVal_nb1_highmtb_nrtntnwgeq2"},
                                            
        // nb2                 
  // 1 tagged                 
  {"hmVal_nb2_highmtb_nt1_nrt0_nw0",          "hmVal_nb2_highmtb_nt1_nrt0_nw0"},
  {"hmVal_nb2_highmtb_nt0_nrt0_nw1",          "hmVal_nb2_highmtb_nt0_nrt0_nw1"},
  {"hmVal_nb2_highmtb_nt0_nrt1_nw0",          "hmVal_nb2_highmtb_nt0_nrt1_nw0"},
                                            
  // 1+1                     
  {"hmVal_nb2_highmtb_nrtntnwgeq2",           "hmVal_nb2_highmtb_nrtntnwgeq2"},         
  
  //---------- high deltaM ----------
};


std::map<TString, TString> phocrCuts = []{
    std::map<TString, TString> cuts;
    for (auto sr2cr : phocrMapping)
      cuts[sr2cr.first] = createCutString(sr2cr.second, cutMap);
    return cuts;
}();

std::map<TString, TString> phocrlabels = phocrMapping;

std::map<TString, std::vector<int>> phocrMETbins = srMETbins;


std::map<TString, TString> lepcrMapping {
//---------- low deltaM ----------
  // 0b, 0 or >=1 ivf
  {"lm_nb0_nivf0_highptisr_nj2to5_met400",        "lm_nb0_nivf0_highptisr_nj2to5_met400"},
  {"lm_nb0_nivf0_highptisr_nj6_met400",           "lm_nb0_nivf0_highptisr_nj6_met400"},
  {"lm_nb0_nivf1_highptisr_nj2to5_met400",        "lm_nb0_nivf1_highptisr_nj2to5_met400"},
  {"lm_nb0_nivf1_highptisr_nj6_met400",           "lm_nb0_nivf1_highptisr_nj6_met400"},
                                            
  // 1b, 0 or >=1 ivf                     
  {"lm_nb1_nivf0_lowmtb_lowptisr_lowptb_met300",  "lm_nb1_nivf0_lowmtb_lowptisr_lowptb_met300"},
  {"lm_nb1_nivf0_lowmtb_lowptisr_medptb_met300",  "lm_nb1_nivf0_lowmtb_lowptisr_medptb_met300"},
  {"lm_nb1_nivf0_lowmtb_highptisr_lowptb_met400", "lm_nb1_nivf0_lowmtb_highptisr_lowptb_met400"},
  {"lm_nb1_nivf0_lowmtb_highptisr_medptb_met400", "lm_nb1_nivf0_lowmtb_highptisr_medptb_met400"},
  // ---                                 
  {"lm_nb1_nivf1_lowmtb_medptisr_lowptb_met300",  "lm_nb1_nivf1_lowmtb_medptisr_lowptb_met300"},
                                            
  // 2b                                 
  {"lm_nb2_lowmtb_lowptisr_lowptb12_met300",      "lm_nb2_lowmtb_lowptisr_lowptb12_met300"},
  {"lm_nb2_lowmtb_lowptisr_medptb12_met300",      "lm_nb2_lowmtb_lowptisr_medptb12_met300"},
  {"lm_nb2_lowmtb_lowptisr_highptb12_nj7_met300", "lm_nb2_lowmtb_lowptisr_highptb12_nj7_met300"},
  {"lm_nb2_lowmtb_highptisr_lowptb12_met400",     "lm_nb2_lowmtb_highptisr_lowptb12_met400"},
  {"lm_nb2_lowmtb_highptisr_medptb12_met400",     "lm_nb2_lowmtb_highptisr_medptb12_met400"},
  {"lm_nb2_lowmtb_highptisr_highptb12_nj7_met400","lm_nb2_lowmtb_highptisr_highptb12_nj7_met400"},
                                            
  // Additional from Hui               
  // 0b                               
  {"lmVal_nb0_lowmtb_nivf0",     "lmVal_nb0_lowmtb_nivf0"},
  {"lmVal_nb0_lowmtb_nivf1",     "lmVal_nb0_lowmtb_nivf1"},
  {"lmVal_nbgeq1_lowmtb_nivf0",   "lmVal_nbgeq1_lowmtb_nivf0"},
  {"lmVal_nbgeq1_lowmtb_nivf1",   "lmVal_nbgeq1_lowmtb_nivf1"},
  //---------- low deltaM ---------- 
                                            
                                            
  //---------- high deltaM ---------- 
  // low mtb                         
  {"hmVal_nb1_lowmtb_nj7_nrtgeq1",            "hmVal_nb1_lowmtb_nj7"},
  {"hmVal_nb2_lowmtb_nj7_nrtgeq1",            "hmVal_nb2_lowmtb_nj7"},
                                            
  // high mtb                       
  // 0 taggged                     
  {"hmVal_nb1_highmtb_nj5_nt0_nrt0_nw0",      "hmVal_nb1_highmtb_nj5"},
  {"hmVal_nb2_highmtb_nj5_nt0_nrt0_nw0",      "hmVal_nb2_highmtb_nj5"},
                                            
        // nb1                    
  // 1 tagged                    
  {"hmVal_nb1_highmtb_nt1_nrt0_nw0",          "hmVal_nb1_highmtb"},
  {"hmVal_nb1_highmtb_nt0_nrt0_nw1",          "hmVal_nb1_highmtb"},
  {"hmVal_nb1_highmtb_nt0_nrt1_nw0",          "hmVal_nb1_highmtb"},
                                            
  // 1+1                        
  {"hmVal_nb1_highmtb_nrtntnwgeq2",           "hmVal_nb1_highmtb"},
                                            
        // nb2                 
  // 1 tagged                 
  {"hmVal_nb2_highmtb_nt1_nrt0_nw0",          "hmVal_nb2_highmtb"},
  {"hmVal_nb2_highmtb_nt0_nrt0_nw1",          "hmVal_nb2_highmtb"},
  {"hmVal_nb2_highmtb_nt0_nrt1_nw0",          "hmVal_nb2_highmtb"},
                                            
  // 1+1                     
  {"hmVal_nb2_highmtb_nrtntnwgeq2",           "hmVal_nb2_highmtb"},         
  
  //---------- high deltaM ----------
};


std::map<TString, TString> lepcrCuts = []{
    std::map<TString, TString> cuts;
    for (auto sr2cr : lepcrMapping)
      cuts[sr2cr.first] = createCutString(sr2cr.second, cutMap);
    return cuts;
}();

std::map<TString, TString> lepcrlabels = lepcrMapping;
std::map<TString, std::vector<int>> lepcrMETbins = srMETbins;

// qcd-cr: inverted dPhi cut applied on CR samples now
std::map<TString, TString> qcdcrMapping =[]{
  auto crmap = lepcrMapping;
  for (auto &s : crmap){
    s.second.ReplaceAll("lm_", "lmNoDPhi_");
    s.second.ReplaceAll("lmVal_", "lmNoDPhi_");
    s.second.ReplaceAll("hm_", "hmNoDPhi_");
    s.second.ReplaceAll("hmVal_", "hmNoDPhi_");
  }
  return crmap;
}();
std::map<TString, TString> qcdcrCuts = []{
    std::map<TString, TString> cuts;
    for (auto sr2cr : qcdcrMapping)
      cuts[sr2cr.first] = createCutString(sr2cr.second, cutMap);
    return cuts;
}();
std::map<TString, TString> qcd1to1crCuts = []{
    std::map<TString, TString> cuts;
    for (auto name : srbins){
      TString crname = name;
      crname.ReplaceAll("lm_", "lmNoDPhi_");
      crname.ReplaceAll("lmVal_", "lmNoDPhi_");
      crname.ReplaceAll("hm_", "hmNoDPhi_");
      crname.ReplaceAll("hmVal_", "hmNoDPhi_");
      cuts[name] = createCutString(crname, cutMap);
    }
    return cuts;
}();
std::map<TString, TString> qcdcrlabels = lepcrlabels;
std::map<TString, std::vector<int>> qcdcrMETbins = srMETbins;


map<TString, Category> srCatMap(){
  map<TString, Category> cmap;
  for (auto &name : srbins){
    cmap[name] = Category(name, srcuts.at(name), srlabels.at(name), BinInfo("MET_pt", "#slash{E}_{T}", srMETbins.at(name), "GeV"));
  }
  return cmap;
}

map<TString, Category> phoCatMap(){
  map<TString, Category> cmap;
  const auto &cuts = ICHEPCR ? srcuts: phocrCuts;
  const auto &labels = ICHEPCR ? srlabels: phocrlabels;
  for (auto &name : srbins){
    cmap[name] = Category(name, cuts.at(name), labels.at(name), BinInfo("MET_pt", "#slash{E}_{T}^{#gamma}", phocrMETbins.at(name), "GeV"));
  }
  return cmap;
}

map<TString, Category> lepCatMap(){
  TString varlabel = ADD_LEP_TO_MET ? "p_{T}^{W}" : "#slash{E}_{T}";
  map<TString, Category> cmap;
  const auto &cuts = ICHEPCR ? srcuts: lepcrCuts;
  const auto &labels = ICHEPCR ? srlabels: lepcrlabels;
  for (auto &name : srbins){
    cmap[name] = Category(name, cuts.at(name), labels.at(name), BinInfo("MET_pt", varlabel, lepcrMETbins.at(name), "GeV"));
  }
  return cmap;
}

map<TString, Category> qcdCatMap(){
  map<TString, Category> cmap;
  const auto &cuts = ICHEPCR ? qcd1to1crCuts: qcdcrCuts;
  const auto &labels = ICHEPCR ? srlabels: qcdcrlabels;
  for (auto &name : srbins){
    cmap[name] = Category(name, cuts.at(name), labels.at(name), BinInfo("MET_pt", "#slash{E}_{T}", qcdcrMETbins.at(name), "GeV"));
  }
  return cmap;
}

map<TString, Category> zllCatMap{
  {"on-z",  Category("on-z",  "dilepmass > 80 && dilepmass < 100",                      "on Z",   BinInfo("MET_pt", "#slash{E}_{T}^{ll}", vector<double>{200, 1000}, "GeV"))},
  {"off-z", Category("off-z", "dilepmass > 50 && (dilepmass < 80 || dilepmass > 100)",  "off Z",  BinInfo("MET_pt", "#slash{E}_{T}^{ll}", vector<double>{200, 1000}, "GeV"))}
};


// ------------------------------------------------------------------------
// samples

BaseConfig phoConfig(){
  BaseConfig     config;

  config.inputdir = inputdir;
  config.outputdir = outputdir+"/znunu";
  config.header = "#sqrt{s} = 13 TeV, "+lumistr+" fb^{-1}";

  config.addSample("singlepho",   "Data",           datadir+"/photoncr/singlepho",  "1.0",  datasel + trigPhoCR);

  config.addSample("photon",      "Photon",         "photoncr/photon",     phowgt, datasel + trigPhoCR + phoBadEventRemoval);
//  config.addSample("photon",      "Photon",         "photoncr/gjets",      phowgt, datasel + trigPhoCR);
  config.addSample("znunu-sr",    "Z#rightarrow#nu#nu",   "sr/znunu",      lepvetowgt, datasel + trigSR + vetoes);

  config.sel = baseline;
  config.categories = srbins;
  config.catMaps = srCatMap();
  config.crCatMaps = phoCatMap();

  return config;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BaseConfig zllConfig(){
  BaseConfig     config;

  config.inputdir = inputdir;
  config.outputdir = outputdir+"/zllcr";
  config.header = "#sqrt{s} = 13 TeV, "+lumistr+" fb^{-1}";

  config.addSample("dyll",      "Z#rightarrowll+jets",    "zllcr/z-soup",                    lepselwgt, datasel + trigDiLepCR);
  config.addSample("ttbar",     "t#bar{t}",               "zllcr/t-soup",                    lepselwgt, datasel + trigDiLepCR);
  config.addSample("doublelep", "Data",                   datadir+"/zllcr/doublelep",       "1.0",     datasel + trigDiLepCR);

  config.sel = baseline;
  config.catMaps = zllCatMap;
  for (auto &c : zllCatMap) config.categories.push_back(c.first);

  return config;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BaseConfig lepConfig(){
  BaseConfig     config;

  config.inputdir = inputdir;
  config.outputdir = outputdir+"/LLB";
  config.header = "#sqrt{s} = 13 TeV, "+lumistr+" fb^{-1}";

  // samples for cr categories
  config.addSample("singlelep",   	 	 "Data",     	  inputdir_2018+"met",              "1.0",          datasel + trigSR + revert_vetoes);
  config.addSample("ttbar-2018preHEM",         "t#bar{t}",      inputdir_2018+"ttbar",           lepselwgt_preHEM,      datasel + revert_vetoes);
  config.addSample("wjets-2018preHEM",         "W+jets",        inputdir_2018+"wjets",           lepselwgt_preHEM,      datasel + revert_vetoes);
  config.addSample("tW-2018preHEM",            "tW",            inputdir_2018+"tW",              lepselwgt_preHEM,      datasel + revert_vetoes);
  config.addSample("ttW-2018preHEM",           "ttW",           inputdir_2018+"ttW",             lepselwgt_preHEM,      datasel + revert_vetoes);
  config.addSample("ttbar-2018postHEM",        "t#bar{t}",      inputdir_2018+"ttbar",           lepselwgt_postHEM,      dataselHEM + revert_vetoes);
  config.addSample("wjets-2018postHEM",        "W+jets",        inputdir_2018+"wjets",           lepselwgt_postHEM,      dataselHEM + revert_vetoes);
  config.addSample("tW-2018postHEM",           "tW",            inputdir_2018+"tW",              lepselwgt_postHEM,      dataselHEM + revert_vetoes);
  config.addSample("ttW-2018postHEM",          "ttW",           inputdir_2018+"ttW",             lepselwgt_postHEM,      dataselHEM + revert_vetoes);

  // samples for sr categories
  config.addSample("ttbar-2018preHEM-sr",    "t#bar{t}",      inputdir_2018+"ttbar",             lepvetowgt_preHEM, datasel + vetoes);
  config.addSample("wjets-2018preHEM-sr",    "W+jets",        inputdir_2018+"wjets",             lepvetowgt_preHEM, datasel + vetoes);
  config.addSample("tW-2018preHEM-sr",       "tW",            inputdir_2018+"tW",                lepvetowgt_preHEM, datasel + vetoes);
  config.addSample("ttW-2018preHEM-sr",      "ttW",           inputdir_2018+"ttW",               lepvetowgt_preHEM, datasel + vetoes);
  config.addSample("ttZ-2018preHEM-sr",      "ttZ",           inputdir_2018+"ttZ",               lepvetowgt_preHEM, datasel + vetoes);
  config.addSample("diboson-2018preHEM-sr",  "Diboson",       inputdir_2018+"diboson",           lepvetowgt_preHEM, datasel + vetoes);
  config.addSample("ttbar-2018postHEM-sr",   "t#bar{t}",      inputdir_2018+"ttbar",             lepvetowgt_postHEM, dataselHEM + vetoes);
  config.addSample("wjets-2018postHEM-sr",   "W+jets",        inputdir_2018+"wjets",             lepvetowgt_postHEM, dataselHEM + vetoes);
  config.addSample("tW-2018postHEM-sr",      "tW",            inputdir_2018+"tW",                lepvetowgt_postHEM, dataselHEM + vetoes);
  config.addSample("ttW-2018postHEM-sr",     "ttW",           inputdir_2018+"ttW",               lepvetowgt_postHEM, dataselHEM + vetoes);
  config.addSample("ttZ-2018postHEM-sr",     "ttZ",           inputdir_2018+"ttZ",               lepvetowgt_postHEM, dataselHEM + vetoes);
  config.addSample("diboson-2018postHEM-sr", "Diboson",       inputdir_2018+"diboson",           lepvetowgt_postHEM, dataselHEM + vetoes);

  config.sel = baseline;
  config.categories = srbins;
  config.catMaps = srCatMap();
  config.crCatMaps = lepCatMap();

  return config;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BaseConfig srConfig(){
  BaseConfig     config;

  config.inputdir = inputdir+"/sr";
  config.outputdir = outputdir+"/testSR";
  config.header = "#sqrt{s} = 13 TeV, "+lumistr+" fb^{-1}";

  config.addSample("ttbar",       "t#bar{t}",      "ttbar",        lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("wjets",       "W+jets",        "wjets",        lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("znunu",       "Z#rightarrow#nu#nu", "znunu",   lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("qcd",         "QCD",           "qcd",       lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("tW",          "tW",            "tW",           lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("ttW",         "ttW",           "ttW",          lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("ttZ",         "ttZ",           "ttZ",          lepvetowgt, datasel + trigSR + vetoes);
  config.addSample("diboson",     "Diboson",       "diboson",      lepvetowgt, datasel + trigSR + vetoes);

//  config.addSample("T2fbd_500_420", "T2fbd(500,420)", "T2fbd_500_420",  sigwgt, datasel + trigSR + vetoes);
  config.addSample("T2fbd_500_450", "T2fbd(500,450)", "T2fbd_500_450",  sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2fbd_500_480", "T2fbd(500,480)", "T2fbd_500_480",  sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2cc_500_490",  "T2cc(500,490)",  "T2cc_500_490",   sigwgt, datasel + trigSR + vetoes);

//  config.addSample("T2tt_450_250",  "T2tt(450,250)",  "T2tt_450_250",   sigwgt, datasel + trigSR + vetoes);
  config.addSample("T2tt_400_300",  "T2tt(400,300)",  "T2tt_400_300",   sigwgt, datasel + trigSR + vetoes);
  config.addSample("T2tt_700_400",  "T2tt(700,400)",  "T2tt_700_400",   sigwgt, datasel + trigSR + vetoes);
  config.addSample("T2tt_1000_1",   "T2tt(1000,1)",   "T2tt_1000_1",    sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2tt_1100_1",   "T2tt(1100,1)",   "T2tt_1100_1",    sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2bW_850_1",    "T2bW(850,1)",    "T2bW_850_1",     sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2bW_550_350",  "T2bW(550,350)",  "T2bW_550_350",   sigwgt, datasel + trigSR + vetoes);


  COLOR_MAP["T2fbd_500_420"] = kRed;
  COLOR_MAP["T2fbd_500_450"] = kBlue;
  COLOR_MAP["T2fbd_500_480"] = kBlack;
  COLOR_MAP["T2cc_500_490"]  = kMagenta;

  COLOR_MAP["T2tt_450_250"]  = kOrange;
  COLOR_MAP["T2tt_700_400"]  = kCyan+2;
  COLOR_MAP["T2tt_1000_1"]   = kViolet+2;
  COLOR_MAP["T2bW_550_350"]  = kSpring-9;
  COLOR_MAP["T2bW_850_1"]    = kPink+2;

  config.sel = baseline;
  config.categories = srbins;
  config.catMaps = srCatMap();

  return config;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BaseConfig qcdConfig(){
  BaseConfig     config;

  config.inputdir = inputdir;
  config.outputdir = outputdir+"/QCD";
  config.header = "#sqrt{s} = 13 TeV, "+lumistr+" fb^{-1}";

  // qcdcr
  config.addSample("data-cr",     "Data",             datadir+"met",  "1.0",      datasel + trigSR + vetoes + dphi_invert);
  
  config.addSample("qcd-2016-cr",      "QCD",              inputdir_2016+"qcd_smear",       qcdwgt,      datasel + dphi_invert);
  config.addSample("qcd-2016-withveto-cr",  "QCD",         inputdir_2016+"qcd_smear",       qcdvetowgt,  datasel + vetoes + dphi_invert);
  config.addSample("qcd-2016-withveto-sr",  "QCD",         inputdir_2016+"qcd_smear",       qcdvetowgt,  datasel + vetoes);

  config.addSample("qcd-2017RunBtoE-cr",      "QCD",       inputdir_2017+"qcd_smear",       qcdwgt_RunBtoE,      datasel + dphi_invert);
  config.addSample("qcd-2017RunBtoE-withveto-cr",  "QCD",  inputdir_2017+"qcd_smear",       qcdvetowgt_RunBtoE,  datasel + vetoes + dphi_invert);
  config.addSample("qcd-2017RunBtoE-withveto-sr",  "QCD",  inputdir_2017+"qcd_smear",       qcdvetowgt_RunBtoE,  datasel + vetoes);
  config.addSample("qcd-2017RunF-cr",      "QCD",          inputdir_2017+"qcd_smear",       qcdwgt_RunF,         datasel + dphi_invert);
  config.addSample("qcd-2017RunF-withveto-cr",  "QCD",     inputdir_2017+"qcd_smear",       qcdvetowgt_RunF,     datasel + vetoes + dphi_invert);
  config.addSample("qcd-2017RunF-withveto-sr",  "QCD",     inputdir_2017+"qcd_smear",       qcdvetowgt_RunF,     datasel + vetoes);

  config.addSample("qcd-2018preHEM-cr",      "QCD",        inputdir_2018+"qcd_smear",       qcdwgt_preHEM,       datasel + dphi_invert);
  config.addSample("qcd-2018preHEM-withveto-cr",  "QCD",   inputdir_2018+"qcd_smear",       qcdvetowgt_preHEM,   datasel + vetoes + dphi_invert);
  config.addSample("qcd-2018preHEM-withveto-sr",  "QCD",   inputdir_2018+"qcd_smear",       qcdvetowgt_preHEM,   datasel + vetoes);
  config.addSample("qcd-2018postHEM-cr",      "QCD",       inputdir_2018+"qcd_smear",       qcdwgt_postHEM,      dataselHEM + dphi_invert);
  config.addSample("qcd-2018postHEM-withveto-cr",  "QCD",  inputdir_2018+"qcd_smear",       qcdvetowgt_postHEM,  dataselHEM + vetoes + dphi_invert);
  config.addSample("qcd-2018postHEM-withveto-sr",  "QCD",  inputdir_2018+"qcd_smear",       qcdvetowgt_postHEM,  dataselHEM + vetoes);

  // qcdcr: other bkg subtraction
  config.addSample("ttbar-2016-cr",       "t#bar{t}",      inputdir_2016+"ttbar",        lepvetowgt,  datasel + vetoes + dphi_invert);
  config.addSample("wjets-2016-cr",       "W+jets",        inputdir_2016+"wjets",        lepvetowgt,  datasel + vetoes + dphi_invert);
  config.addSample("tW-2016-cr",          "tW",            inputdir_2016+"tW",           lepvetowgt,  datasel + vetoes + dphi_invert);
  config.addSample("ttW-2016-cr",         "ttW",           inputdir_2016+"ttW",          lepvetowgt,  datasel + vetoes + dphi_invert);
  config.addSample("znunu-2016-cr",       "Znunu",         inputdir_2016+"znunu",        lepvetowgt,  datasel + vetoes + dphi_invert);

  config.addSample("ttbar-2017RunBtoE-cr",       "t#bar{t}",      inputdir_2017+"ttbar",        lepvetowgt_RunBtoE,  datasel + vetoes + dphi_invert);
  config.addSample("wjets-2017RunBtoE-cr",       "W+jets",        inputdir_2017+"wjets",        lepvetowgt_RunBtoE,  datasel + vetoes + dphi_invert);
  config.addSample("tW-2017RunBtoE-cr",          "tW",            inputdir_2017+"tW",           lepvetowgt_RunBtoE,  datasel + vetoes + dphi_invert);
  config.addSample("ttW-2017RunBtoE-cr",         "ttW",           inputdir_2017+"ttW",          lepvetowgt_RunBtoE,  datasel + vetoes + dphi_invert);
  config.addSample("znunu-2017RunBtoE-cr",       "Znunu",         inputdir_2017+"znunu",        lepvetowgt_RunBtoE,  datasel + vetoes + dphi_invert);
  config.addSample("ttbar-2017RunF-cr",          "t#bar{t}",      inputdir_2017+"ttbar",           lepvetowgt_RunF,     datasel + vetoes + dphi_invert);
  config.addSample("wjets-2017RunF-cr",          "W+jets",        inputdir_2017+"wjets",           lepvetowgt_RunF,     datasel + vetoes + dphi_invert);
  config.addSample("tW-2017RunF-cr",             "tW",            inputdir_2017+"tW",              lepvetowgt_RunF,     datasel + vetoes + dphi_invert);
  config.addSample("ttW-2017RunF-cr",            "ttW",           inputdir_2017+"ttW",             lepvetowgt_RunF,     datasel + vetoes + dphi_invert);
  config.addSample("znunu-2017RunF-cr",          "Znunu",         inputdir_2017+"znunu",           lepvetowgt_RunF,     datasel + vetoes + dphi_invert);

  config.addSample("ttbar-2018preHEM-cr",        "t#bar{t}",      inputdir_2018+"ttbar",        lepvetowgt_preHEM,  datasel + vetoes + dphi_invert);
  config.addSample("wjets-2018preHEM-cr",        "W+jets",        inputdir_2018+"wjets",        lepvetowgt_preHEM,  datasel + vetoes + dphi_invert);
  config.addSample("tW-2018preHEM-cr",           "tW",            inputdir_2018+"tW",           lepvetowgt_preHEM,  datasel + vetoes + dphi_invert);
  config.addSample("ttW-2018preHEM-cr",          "ttW",           inputdir_2018+"ttW",          lepvetowgt_preHEM,  datasel + vetoes + dphi_invert);
  config.addSample("znunu-2018preHEM-cr",        "Znunu",         inputdir_2018+"znunu",        lepvetowgt_preHEM,  datasel + vetoes + dphi_invert);
  config.addSample("ttbar-2018postHEM-cr",       "t#bar{t}",      inputdir_2018+"ttbar",       lepvetowgt_postHEM, dataselHEM + vetoes + dphi_invert);
  config.addSample("wjets-2018postHEM-cr",       "W+jets",        inputdir_2018+"wjets",       lepvetowgt_postHEM, dataselHEM + vetoes + dphi_invert);
  config.addSample("tW-2018postHEM-cr",          "tW",            inputdir_2018+"tW",          lepvetowgt_postHEM, dataselHEM + vetoes + dphi_invert);
  config.addSample("ttW-2018postHEM-cr",         "ttW",           inputdir_2018+"ttW",         lepvetowgt_postHEM, dataselHEM + vetoes + dphi_invert);
  config.addSample("znunu-2018postHEM-cr",       "Znunu",         inputdir_2018+"znunu",       lepvetowgt_postHEM, dataselHEM + vetoes + dphi_invert);

  // onelepcr: norm correction for other bkg subtraction
  config.addSample("data-norm",           "Data",          datadir+"met", "1.0",      datasel + trigSR + revert_vetoes + dphi_cut);
  config.addSample("ttbar-2016-norm",     "t#bar{t}",      inputdir_2016+"ttbar",     lepselwgt,   datasel + revert_vetoes + dphi_cut);
  config.addSample("wjets-2016-norm",     "W+jets",        inputdir_2016+"wjets",     lepselwgt,   datasel + revert_vetoes + dphi_cut);
  config.addSample("tW-2016-norm",        "tW",            inputdir_2016+"tW",        lepselwgt,   datasel + revert_vetoes + dphi_cut);
  config.addSample("ttW-2016-norm",       "ttW",           inputdir_2016+"ttW",       lepselwgt,   datasel + revert_vetoes + dphi_cut);
  config.addSample("qcd-2016-norm",       "QCD",           inputdir_2016+"qcd_smear",       lepselwgt,   datasel + revert_vetoes + dphi_cut);

  config.addSample("ttbar-2017RunBtoE-norm",     "t#bar{t}",      inputdir_2017+"ttbar",     lepselwgt_RunBtoE,   datasel + revert_vetoes + dphi_cut);
  config.addSample("wjets-2017RunBtoE-norm",     "W+jets",        inputdir_2017+"wjets",     lepselwgt_RunBtoE,   datasel + revert_vetoes + dphi_cut);
  config.addSample("tW-2017RunBtoE-norm",        "tW",            inputdir_2017+"tW",        lepselwgt_RunBtoE,   datasel + revert_vetoes + dphi_cut);
  config.addSample("ttW-2017RunBtoE-norm",       "ttW",           inputdir_2017+"ttW",       lepselwgt_RunBtoE,   datasel + revert_vetoes + dphi_cut);
  config.addSample("qcd-2017RunBtoE-norm",       "QCD",           inputdir_2017+"qcd_smear",       lepselwgt_RunBtoE,   datasel + revert_vetoes + dphi_cut);
  config.addSample("ttbar-2017RunF-norm",        "t#bar{t}",      inputdir_2017+"ttbar",     lepselwgt_RunF,      datasel + revert_vetoes + dphi_cut);
  config.addSample("wjets-2017RunF-norm",        "W+jets",        inputdir_2017+"wjets",     lepselwgt_RunF,      datasel + revert_vetoes + dphi_cut);
  config.addSample("tW-2017RunF-norm",           "tW",            inputdir_2017+"tW",        lepselwgt_RunF,      datasel + revert_vetoes + dphi_cut);
  config.addSample("ttW-2017RunF-norm",          "ttW",           inputdir_2017+"ttW",       lepselwgt_RunF,      datasel + revert_vetoes + dphi_cut);
  config.addSample("qcd-2017RunF-norm",          "QCD",           inputdir_2017+"qcd_smear",       lepselwgt_RunF,      datasel + revert_vetoes + dphi_cut);

  config.addSample("ttbar-2018preHEM-norm",     "t#bar{t}",      inputdir_2018+"ttbar",     lepselwgt_preHEM,   datasel + revert_vetoes + dphi_cut);
  config.addSample("wjets-2018preHEM-norm",     "W+jets",        inputdir_2018+"wjets",     lepselwgt_preHEM,   datasel + revert_vetoes + dphi_cut);
  config.addSample("tW-2018preHEM-norm",        "tW",            inputdir_2018+"tW",        lepselwgt_preHEM,   datasel + revert_vetoes + dphi_cut);
  config.addSample("ttW-2018preHEM-norm",       "ttW",           inputdir_2018+"ttW",       lepselwgt_preHEM,   datasel + revert_vetoes + dphi_cut);
  config.addSample("qcd-2018preHEM-norm",       "QCD",           inputdir_2018+"qcd_smear",       lepselwgt_preHEM,   datasel + revert_vetoes + dphi_cut);
  config.addSample("ttbar-2018postHEM-norm",    "t#bar{t}",      inputdir_2018+"ttbar",     lepselwgt_postHEM,  dataselHEM + revert_vetoes + dphi_cut);
  config.addSample("wjets-2018postHEM-norm",    "W+jets",        inputdir_2018+"wjets",     lepselwgt_postHEM,  dataselHEM + revert_vetoes + dphi_cut);
  config.addSample("tW-2018postHEM-norm",       "tW",            inputdir_2018+"tW",        lepselwgt_postHEM,  dataselHEM + revert_vetoes + dphi_cut);
  config.addSample("ttW-2018postHEM-norm",      "ttW",           inputdir_2018+"ttW",       lepselwgt_postHEM,  dataselHEM + revert_vetoes + dphi_cut);
  config.addSample("qcd-2018postHEM-norm",      "QCD",           inputdir_2018+"qcd_smear",       lepselwgt_postHEM,  dataselHEM + revert_vetoes + dphi_cut);

  // qcdsr
  config.addSample("qcd-2016-sr",         "QCD",           inputdir_2016+"qcd_smear",       qcdwgt,           datasel);
  config.addSample("qcd-2017RunBtoE-sr",  "QCD",           inputdir_2017+"qcd_smear",       qcdwgt_RunBtoE,   datasel);
  config.addSample("qcd-2017RunF-sr",     "QCD",           inputdir_2017+"qcd_smear",       qcdwgt_RunF,      datasel);
  config.addSample("qcd-2018preHEM-sr",   "QCD",           inputdir_2018+"qcd_smear",       qcdwgt_preHEM,    datasel);
  config.addSample("qcd-2018postHEM-sr",  "QCD",           inputdir_2018+"qcd_smear",       qcdwgt_postHEM,   dataselHEM);


  config.sel = baseline;
  config.categories = srbins;
  config.catMaps = srCatMap();    // sr DPhi cut applied
  config.crCatMaps = qcdCatMap(); // no DPhi cut in category def

  return config;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BaseConfig sigConfig(){
  BaseConfig     config;

  config.inputdir = inputdir;
  config.outputdir = outputdir+"/sig";
  config.header = "#sqrt{s} = 13 TeV, "+lumistr+" fb^{-1}";

  config.addSample("data-sr",   "Data",      inputdir_2018+"met",                    "1.0",  datasel + trigSR + vetoes);

  // raw MC w/o top/W SF
  //config.addSample("znunu-2016-raw-sr",                 "Z#rightarrow#nu#nu", inputdir_2016+"znunu",           lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //config.addSample("ttbar-2016-raw-sr",                 "t#bar{t}",           inputdir_2016+"ttbar",           lepvetowgt_no_wtopsf+"*ISRWeight",    datasel + vetoes);
  //config.addSample("wjets-2016-raw-sr",                 "W+jets",             inputdir_2016+"wjets",           lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //config.addSample("tW-2016-raw-sr",                    "tW",                 inputdir_2016+"tW",              lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //config.addSample("ttW-2016-raw-sr",                   "ttW",                inputdir_2016+"ttW",             lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //config.addSample("ttZ-2016-raw-sr",                   "ttZ",                inputdir_2016+"ttZ",             lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //config.addSample("diboson-2016-raw-sr",               "Diboson",            inputdir_2016+"diboson",         lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //config.addSample("qcd-2016-raw-sr",                   "QCD",                inputdir_2016+"qcd_smear",             lepvetowgt_no_wtopsf,                 datasel + vetoes);
  //
  //config.addSample("znunu-2017RunBtoE-raw-sr",          "Z#rightarrow#nu#nu", inputdir_2017+"znunu",           lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("ttbar-2017RunBtoE-raw-sr",          "t#bar{t}",           inputdir_2017+"ttbar",           lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("wjets-2017RunBtoE-raw-sr",          "W+jets",             inputdir_2017+"wjets",           lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("tW-2017RunBtoE-raw-sr",             "tW",                 inputdir_2017+"tW",              lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("ttW-2017RunBtoE-raw-sr",            "ttW",                inputdir_2017+"ttW",             lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("ttZ-2017RunBtoE-raw-sr",            "ttZ",                inputdir_2017+"ttZ",             lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("diboson-2017RunBtoE-raw-sr",        "Diboson",            inputdir_2017+"diboson",         lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("qcd-2017RunBtoE-raw-sr",            "QCD",                inputdir_2017+"qcd_smear",             lepvetowgt_no_wtopsf_RunBtoE,         datasel + vetoes);
  //config.addSample("znunu-2017RunF-raw-sr",             "Z#rightarrow#nu#nu", inputdir_2017+"znunu",           lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("ttbar-2017RunF-raw-sr",             "t#bar{t}",           inputdir_2017+"ttbar",           lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("wjets-2017RunF-raw-sr",             "W+jets",             inputdir_2017+"wjets",           lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("tW-2017RunF-raw-sr",                "tW",                 inputdir_2017+"tW",              lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("ttW-2017RunF-raw-sr",               "ttW",                inputdir_2017+"ttW",             lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("ttZ-2017RunF-raw-sr",               "ttZ",                inputdir_2017+"ttZ",             lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("diboson-2017RunF-raw-sr",           "Diboson",            inputdir_2017+"diboson",         lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //config.addSample("qcd-2017RunF-raw-sr",               "QCD",                inputdir_2017+"qcd_smear",             lepvetowgt_no_wtopsf_RunF,            datasel + vetoes);
  //
  //config.addSample("znunu-2018preHEM-raw-sr",           "Z#rightarrow#nu#nu", inputdir_2018+"znunu",           lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("ttbar-2018preHEM-raw-sr",           "t#bar{t}",           inputdir_2018+"ttbar",           lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("wjets-2018preHEM-raw-sr",           "W+jets",             inputdir_2018+"wjets",           lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("tW-2018preHEM-raw-sr",              "tW",                 inputdir_2018+"tW",              lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("ttW-2018preHEM-raw-sr",             "ttW",                inputdir_2018+"ttW",             lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("ttZ-2018preHEM-raw-sr",             "ttZ",                inputdir_2018+"ttZ",             lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("diboson-2018preHEM-raw-sr",         "Diboson",            inputdir_2018+"diboson",         lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("qcd-2018preHEM-raw-sr",             "QCD",                inputdir_2018+"qcd_smear",             lepvetowgt_no_wtopsf_preHEM,          datasel + vetoes);
  //config.addSample("znunu-2018postHEM-raw-sr",          "Z#rightarrow#nu#nu", inputdir_2018+"znunu",           lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("ttbar-2018postHEM-raw-sr",          "t#bar{t}",           inputdir_2018+"ttbar",           lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("wjets-2018postHEM-raw-sr",          "W+jets",             inputdir_2018+"wjets",           lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("tW-2018postHEM-raw-sr",             "tW",                 inputdir_2018+"tW",              lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("ttW-2018postHEM-raw-sr",            "ttW",                inputdir_2018+"ttW",             lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("ttZ-2018postHEM-raw-sr",            "ttZ",                inputdir_2018+"ttZ",             lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("diboson-2018postHEM-raw-sr",        "Diboson",            inputdir_2018+"diboson",         lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);
  //config.addSample("qcd-2018postHEM-raw-sr",            "QCD",                inputdir_2018+"qcd_smear",             lepvetowgt_no_wtopsf_postHEM,         dataselHEM + vetoes);

//  config.addSample("T2fbd_375_355",  "T2-4bd(375,355)",  "sig/T2fbd_375_355",  sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2fbd_375_325",  "T2-4bd(375,325)",  "sig/T2fbd_375_325",  sigwgt, datasel + trigSR + vetoes);
//  config.addSample("T2fbd_375_295",  "T2-4bd(375,295)",  "sig/T2fbd_375_295",  sigwgt, datasel + trigSR + vetoes);
//
  config.sel = baseline;
  config.categories = srbins;
  config.catMaps = srCatMap();

  return config;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

map<TString, BinInfo> varDict {
  {"norm",      BinInfo("MET_pt", "#slash{E}_{T}", vector<int>{0, 1000}, "GeV")},
  {"met",       BinInfo("MET_pt", "#slash{E}_{T}", vector<int>{250, 350, 450, 550, 650, 750, 1000}, "GeV")},
  {"metgx",       BinInfo("MET_pt", "#slash{E}_{T}^{(#gamma)}", vector<int>{250, 350, 450, 550, 650, 850}, "GeV")},
  {"metzg",       BinInfo("MET_pt", "#slash{E}_{T}^{#gamma/ll}", vector<int>{250, 350, 450, 550, 650, 850}, "GeV")},
  {"origmet",   BinInfo("MET_pt", "Original #slash{E}_{T}", 20, 0, 500, "GeV")},
  {"njets",     BinInfo("Stop0l_nJets", "N_{j}", 8, -0.5, 7.5)},
  {"njl",       BinInfo("njl", "N_{j}^{ISR}", 4, 0.5, 4.5)},
  {"nlbjets",   BinInfo("nlbjets", "N_{B}^{loose}", 5, -0.5, 4.5)},
  {"nbjets",    BinInfo("Stop0l_nbtags",  "N_{B}^{medium}", 5, -0.5, 4.5)},
  {"dphij1met", BinInfo("Jet_dPhiMET[0]", "#Delta#phi(j_{1},#slash{E}_{T})", 30, 0, 3)},
  {"dphij2met", BinInfo("Jet_dPhiMET[1]", "#Delta#phi(j_{2},#slash{E}_{T})", 30, 0, 3)},
  {"metovsqrtht",BinInfo("Stop0l_METSig", "#slash{E}_{T}/#sqrt{H_{T}}", 10, 0, 20)},
  {"dphiisrmet",BinInfo("dphiisrmet", "#Delta#phi(j_{1}^{ISR},#slash{E}_{T})", vector<double>{0, 2, 3})},
  {"dphiisrmet_fine",BinInfo("dphiisrmet", "#Delta#phi(j_{1}^{ISR},#slash{E}_{T})", 12, 0, 3)},
  {"mtcsv12met",BinInfo("mtcsv12met", "min(m_{T}(b_{1},#slash{E}_{T}),m_{T}(b_{2},#slash{E}_{T}))", 6, 0, 300)},
  {"leptonpt",  BinInfo("leptonpt", "p_{T}^{lep} [GeV]", 12, 0, 600)},
  {"leptonptovermet",  BinInfo("leptonpt/met", "p_{T}^{lep}/#slash{E}_{T}", 20, 0, 1.)},
  {"ak8isrpt",  BinInfo("ak8isrpt", "p_{T}(ISR) [GeV]",  6, 200, 800)},
  {"csvj1pt",   BinInfo("csvj1pt", "p_{T}(b_{1}) [GeV]", 8, 20, 100)},
  {"ptb12",     BinInfo("csvj1pt+csvj2pt", "p_{T}(b_{1})+p_{T}(b_{2}) [GeV]", 8, 40, 200)},
  {"dphilepisr",  BinInfo("dphilepisr", "#Delta#phi(lep, j_{1}^{ISR})", 30, 0, 3)},
  {"drlepisr",  BinInfo("drlepisr", "#DeltaR(lep, j_{1}^{ISR})", 25, 0, 5)},
};

}
#endif /* ESTTOOLS_LMPARAMETERS_HH_ */
