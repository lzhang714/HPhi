/* HPhi  -  Quantum Lattice Model Simulator */
/* Copyright (C) 2015 The University of Tokyo */
/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/**@file
@brief Function for Hubbard Hamitonian
<ul>
<li>mltplyHubbard(): Main routine of hubbard hamiltonian (canonical).</li>
<li>mltplyHubbardGC(): Main routine of hubbard hamiltonian (grandcanonical).</li>
</ul>
<table>
  <tr>
  <td></td>
    <td>Canonical</td>
    <td>Canonical</td>
    <td>Grand Canonical</td>
    <td>Grand Canonical</td>
  </tr>
  <tr>
    <td></td>
    <td>Intra Process</td>
    <td>Inter Process</td>
    <td>Intra Process</td>
    <td>Inter Process</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger@f$</td>
    <td>::Cis, ::X_Cis</td>
    <td>::Cis_MPI, ::X_Cis_MPI</td>
    <td>::GC_Cis, ::X_GC_Cis</td>
    <td>::GC_Cis_MPI, ::X_GC_Cis_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{j t}@f$</td>
    <td>::Ajt, ::X_Ajt</td>
    <td>::Ajt_MPI, ::X_Ajt_MPI</td>
    <td>::GC_Ajt, ::X_GC_Ajt</td>
    <td>::GC_Ajt_MPI, ::X_GC_Ajt_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{i s}@f$</td>
    <td>::CisAis, ::X_CisAis</td>
    <td>::child_CisAis_Hubbard_MPI, ::X_child_CisAis_Hubbard_MPI</td>
    <td>::GC_CisAis, ::X_CisAis</td>
    <td>::GC_child_CisAis_Hubbard_MPI, ::X_GC_child_CisAis_Hubbard_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{j t}@f$</td>
    <td>::CisAjt, ::X_CisAjt</td>
    <td>::child_CisAjt_MPIsingle, ::child_CisAjt_MPIdouble, 
    ::X_child_CisAjt_MPIsingle, ::X_child_CisAjt_MPIdouble</td>
    <td>::GC_CisAjt, ::X_GC_CisAjt</td>
    <td>::GC_child_CisAjt_Hubbard_MPI, ::X_GC_child_CisAjt_Hubbard_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{i s} c_{i s}^\dagger c_{i s}@f$</td>
    <td>::child_CisAisCisAis_element</td>
    <td>::X_child_CisAisCisAis_Hubbard_MPI</td>
    <td>::GC_child_CisAisCisAis_element</td>
    <td>::X_GC_child_CisAisCisAis_Hubbard_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{i s} c_{j t}^\dagger c_{j t}@f$</td>
    <td>::child_CisAisCjtAjt_element</td>
    <td>::X_child_CisAisCjtAjt_Hubbard_MPI</td>
    <td>::GC_child_CisAisCjtAjt_element</td>
    <td>::X_GC_child_CisAisCjtAjt_Hubbard_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{i s} c_{j t}^\dagger c_{k u}@f$</td>
    <td>::child_CisAisCjtAku_element</td>
    <td>::X_child_CisAisCjtAku_Hubbard_MPI</td>
    <td>::GC_child_CisAisCjtAku_element</td>
    <td>::X_GC_child_CisAisCjtAku_Hubbard_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{j t} c_{k u}^\dagger c_{k u}@f$</td>
    <td>::child_CisAjtCkuAku_element</td>
    <td>::X_child_CisAjtCkuAku_Hubbard_MPI</td>
    <td>::GC_child_CisAjtCkuAku_element</td>
    <td>::X_GC_child_CisAjtCkuAku_Hubbard_MPI</td>
  </tr>
  <tr>
    <td>@f$c_{i s}^\dagger c_{j t} c_{k u}^\dagger c_{l v}@f$</td>
    <td>::child_CisAjtCkuAlv_element</td>
    <td>::X_child_CisAjtCkuAlv_Hubbard_MPI</td>
    <td>::GC_child_CisAjtCkuAlv_element</td>
    <td>::X_GC_child_CisAjtCkuAlv_Hubbard_MPI</td>
  </tr>
</table>
Other
<table>
  <tr>
    <td></td>
    <td>Get info</td>
    <td>Canonical</td>
    <td>Grandcanonical</td>
  </tr>
  <tr>
    <td>Exchange</td>
    <td>::child_exchange_GetInfo</td>
    <td>::child_exchange, ::child_exchange_element</td>
    <td>::GC_child_exchange, ::GC_child_exchange_element</td>
  </tr>
  <tr>
    <td>Pair hop</td>
    <td>::child_pairhopp_GetInfo</td>
    <td>::child_pairhopp, ::child_pairhopp_element</td>
    <td>::GC_child_pairhopp, ::GC_child_pairhopp_element</td>
  </tr>
  <tr>
    <td>General int.</td>
    <td>::child_general_int_GetInfo</td>
    <td>::child_general_int</td>
    <td>::GC_child_general_int</td>
  </tr>
  <tr>
    <td>General hop</td>
    <td>::child_general_hopp_GetInfo</td>
    <td>::child_general_hopp, ::child_general_hopp_MPIsingle, 
    ::child_general_hopp_MPIdouble</td>
    <td>::GC_child_general_hopp, ::GC_child_general_hopp_MPIsingle, 
    ::GC_child_general_hopp_MPIdouble</td>
  </tr>
</table>
*/
#include <bitcalc.h>
#include "mltplyCommon.h"
#include "mltplyHubbard.h"
#include "mltplyMPIHubbard.h"
#include "CalcTime.h"
#include "mltplyHubbardCore.h"
#include "mltplyMPIHubbardCore.h"
/**
@brief perform Hamiltonian vector product for (extended) Hubbard type model.
@f${\bf v}_0 = {\hat H}{\bf v}_1@f$
@return errorcode. 0 for normal, other error
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
int mltplyHubbard(
  struct BindStruct *X,//!<[inout]
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1//!<[in] Input producted vector
){
  long unsigned int i;
  long unsigned int isite1, isite2, sigma1, sigma2;
  long unsigned int isite3, isite4, sigma3, sigma4;
  long unsigned int ibitsite1, ibitsite2, ibitsite3, ibitsite4;

  double complex tmp_trans;
  /*[s] For InterAll */
  double complex tmp_V;
  /*[e] For InterAll */

  int ihermite=0;
  int idx=0;

  StartTimer(300);
  /**
  Transfer
  */
  StartTimer(310);
  for (i = 0; i < X->Def.EDNTransfer; i+=2) {
    if (X->Def.EDGeneralTransfer[i][0] + 1 > X->Def.Nsite &&
        X->Def.EDGeneralTransfer[i][2] + 1 > X->Def.Nsite) {
      StartTimer(311);
      child_general_hopp_MPIdouble(i, X, nstate, tmp_v0, tmp_v1);
      StopTimer(311);
    }
    else if (X->Def.EDGeneralTransfer[i][2] + 1 > X->Def.Nsite) {
      StartTimer(312);
      child_general_hopp_MPIsingle(i, X, nstate, tmp_v0, tmp_v1);
      StopTimer(312);
    }
    else if (X->Def.EDGeneralTransfer[i][0] + 1 > X->Def.Nsite) {
      StartTimer(312);
      child_general_hopp_MPIsingle(i + 1, X, nstate, tmp_v0, tmp_v1);
      StopTimer(312);
    }
    else {
      StartTimer(313);
      for (ihermite = 0; ihermite<2; ihermite++) {
        idx = i + ihermite;
        isite1 = X->Def.EDGeneralTransfer[idx][0] + 1;
        isite2 = X->Def.EDGeneralTransfer[idx][2] + 1;
        sigma1 = X->Def.EDGeneralTransfer[idx][1];
        sigma2 = X->Def.EDGeneralTransfer[idx][3];
        if (child_general_hopp_GetInfo(X, isite1, isite2, sigma1, sigma2) != 0) {
          return -1;
        }
        tmp_trans = -X->Def.EDParaGeneralTransfer[idx];
        X->Large.tmp_trans = tmp_trans;
        child_general_hopp(nstate, tmp_v0, tmp_v1, X, tmp_trans);
      }
      StopTimer(313);
    }
  }/*for (i = 0; i < X->Def.EDNTransfer; i+=2)*/
  StopTimer(310);
  /**
  InterAll
  */
  StartTimer(320);
  for (i = 0; i < X->Def.NInterAll_OffDiagonal; i+=2) {
        
    isite1 = X->Def.InterAll_OffDiagonal[i][0] + 1;
    isite2 = X->Def.InterAll_OffDiagonal[i][2] + 1;
    isite3 = X->Def.InterAll_OffDiagonal[i][4] + 1;
    isite4 = X->Def.InterAll_OffDiagonal[i][6] + 1;
    sigma1 = X->Def.InterAll_OffDiagonal[i][1];
    sigma2 = X->Def.InterAll_OffDiagonal[i][3];
    sigma3 = X->Def.InterAll_OffDiagonal[i][5];
    sigma4 = X->Def.InterAll_OffDiagonal[i][7];
    tmp_V = X->Def.ParaInterAll_OffDiagonal[i];

    if (CheckPE(isite1 - 1, X) == TRUE || CheckPE(isite2 - 1, X) == TRUE ||
        CheckPE(isite3 - 1, X) == TRUE || CheckPE(isite4 - 1, X) == TRUE) {
      StartTimer(321);
      ibitsite1 = X->Def.OrgTpow[2*isite1-2+sigma1] ;
      ibitsite2 = X->Def.OrgTpow[2 * isite2 - 2 + sigma2];
      ibitsite3 = X->Def.OrgTpow[2 * isite3 - 2 + sigma3];
      ibitsite4 = X->Def.OrgTpow[2 * isite4 - 2 + sigma4];
      if (ibitsite1 == ibitsite2 && ibitsite3 == ibitsite4) {
        X_child_CisAisCjtAjt_Hubbard_MPI(isite1 - 1, sigma1,
          isite3 - 1, sigma3,
          tmp_V, X, nstate, tmp_v0, tmp_v1);
      }
      else if (ibitsite1 == ibitsite2 && ibitsite3 != ibitsite4) {
        X_child_CisAisCjtAku_Hubbard_MPI(isite1 - 1, sigma1,
          isite3 - 1, sigma3, isite4 - 1, sigma4,
          tmp_V, X, nstate, tmp_v0, tmp_v1);
      }
      else if (ibitsite1 != ibitsite2 && ibitsite3 == ibitsite4) {
        X_child_CisAjtCkuAku_Hubbard_MPI(isite1 - 1, sigma1, isite2 - 1, sigma2,
          isite3 - 1, sigma3, tmp_V, X, nstate, tmp_v0, tmp_v1);
      }
      else if (ibitsite1 != ibitsite2 && ibitsite3 != ibitsite4) {
        X_child_CisAjtCkuAlv_Hubbard_MPI(isite1 - 1, sigma1, isite2 - 1, sigma2,
          isite3 - 1, sigma3, isite4 - 1, sigma4, tmp_V, X, nstate, tmp_v0, tmp_v1);
      }
      StopTimer(321);
    }
    else {
      StartTimer(322);
      for (ihermite = 0; ihermite < 2; ihermite++) {
        idx = i + ihermite;
        isite1 = X->Def.InterAll_OffDiagonal[idx][0] + 1;
        isite2 = X->Def.InterAll_OffDiagonal[idx][2] + 1;
        isite3 = X->Def.InterAll_OffDiagonal[idx][4] + 1;
        isite4 = X->Def.InterAll_OffDiagonal[idx][6] + 1;
        sigma1 = X->Def.InterAll_OffDiagonal[idx][1];
        sigma2 = X->Def.InterAll_OffDiagonal[idx][3];
        sigma3 = X->Def.InterAll_OffDiagonal[idx][5];
        sigma4 = X->Def.InterAll_OffDiagonal[idx][7];
        tmp_V = X->Def.ParaInterAll_OffDiagonal[idx];

        child_general_int_GetInfo(i, X, isite1, isite2, isite3, isite4, 
          sigma1, sigma2, sigma3, sigma4, tmp_V);

        child_general_int(nstate, tmp_v0, tmp_v1, X);
      }/*for (ihermite = 0; ihermite < 2; ihermite++)*/
      StopTimer(322);
    }
  }/*for (i = 0; i < X->Def.NInterAll_OffDiagonal; i+=2)*/
  StopTimer(320);
  /**
  Pair hopping
  */
  StartTimer(330);
  for (i = 0; i < X->Def.NPairHopping; i +=2) {
    sigma1=0;
    sigma2=1;
        
    if ( X->Def.PairHopping[i][0] + 1 > X->Def.Nsite 
      || X->Def.PairHopping[i][1] + 1 > X->Def.Nsite)
    {
      StartTimer(331);
      X_child_CisAjtCkuAlv_Hubbard_MPI(
        X->Def.PairHopping[i][0], sigma1, X->Def.PairHopping[i][1], sigma1, 
        X->Def.PairHopping[i][0], sigma2, X->Def.PairHopping[i][1], sigma2, 
        X->Def.ParaPairHopping[i], X, nstate, tmp_v0, tmp_v1);
        StopTimer(331);
    }
    else {
      StartTimer(332);
      for (ihermite = 0; ihermite<2; ihermite++) {
        idx = i + ihermite;
        child_pairhopp_GetInfo(idx, X);
        child_pairhopp(nstate, tmp_v0, tmp_v1, X);            
      }/*for (ihermite = 0; ihermite<2; ihermite++)*/
      StopTimer(332);
    }
  }/*for (i = 0; i < X->Def.NPairHopping; i += 2)*/
  StopTimer(330);  
  /**
  Exchange
  */
  StartTimer(340);
  for (i = 0; i < X->Def.NExchangeCoupling; i ++) {
    sigma1 = 0;
    sigma2 = 1;
    if (X->Def.ExchangeCoupling[i][0] + 1 > X->Def.Nsite ||
        X->Def.ExchangeCoupling[i][1] + 1 > X->Def.Nsite) 
    {
      StartTimer(341);
      X_child_CisAjtCkuAlv_Hubbard_MPI(
        X->Def.ExchangeCoupling[i][0], sigma1, X->Def.ExchangeCoupling[i][1], sigma1,
        X->Def.ExchangeCoupling[i][1], sigma2, X->Def.ExchangeCoupling[i][0], sigma2,
        X->Def.ParaExchangeCoupling[i], X, nstate, tmp_v0, tmp_v1);
      StopTimer(341);
    }
    else {
      StartTimer(342);
      child_exchange_GetInfo(i, X);
      child_exchange(nstate, tmp_v0, tmp_v1, X);
      StopTimer(342);
    }
  }/*for (i = 0; i < X->Def.NExchangeCoupling; i ++)*/
  StopTimer(340);

  StopTimer(300);
  return 0;
}/*int mltplyHubbard*/
/**
@brief perform Hamiltonian vector product for (extended) Hubbard type model
(Grandcanonical).
@f${\bf v}_0 = {\hat H}{\bf v}_1@f$
@return errorcode. 0 for normal, other error
*/
int mltplyHubbardGC(
  struct BindStruct *X,//!<[inout]
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1//!<[in] Input producted vector
){
  long unsigned int i;
  long unsigned int isite1, isite2, sigma1, sigma2;
  long unsigned int isite3, isite4, sigma3, sigma4;
  long unsigned int ibitsite1, ibitsite2, ibitsite3, ibitsite4;

  double complex tmp_trans;
  /*[s] For InterAll */
  double complex tmp_V;
  /*[e] For InterAll */

  int ihermite=0;
  int idx=0;

  StartTimer(200);
  /**
  Transfer
  */
  StartTimer(210);
  for (i = 0; i < X->Def.EDNTransfer; i += 2) {
    if (X->Def.EDGeneralTransfer[i][0] + 1 > X->Def.Nsite &&
        X->Def.EDGeneralTransfer[i][2] + 1 > X->Def.Nsite) {
      StartTimer(211);
      GC_child_general_hopp_MPIdouble(i, X, nstate, tmp_v0, tmp_v1);
      StopTimer(211);
    }
    else if (X->Def.EDGeneralTransfer[i][2] + 1 > X->Def.Nsite){
      StartTimer(212);
      GC_child_general_hopp_MPIsingle(i, X, nstate, tmp_v0, tmp_v1);
      StopTimer(212);
    }
    else if (X->Def.EDGeneralTransfer[i][0] + 1 > X->Def.Nsite) {
      StartTimer(212);
      GC_child_general_hopp_MPIsingle(i+1, X, nstate, tmp_v0, tmp_v1);
      StopTimer(212);
    }
    else {
      StartTimer(213);
      for (ihermite = 0; ihermite<2; ihermite++) {
        idx = i + ihermite;
        isite1 = X->Def.EDGeneralTransfer[idx][0] + 1;
        isite2 = X->Def.EDGeneralTransfer[idx][2] + 1;
        sigma1 = X->Def.EDGeneralTransfer[idx][1];
        sigma2 = X->Def.EDGeneralTransfer[idx][3];
        if (child_general_hopp_GetInfo(X, isite1, isite2, sigma1, sigma2) != 0) {
          return -1;
        }
        tmp_trans = -X->Def.EDParaGeneralTransfer[idx];
        GC_child_general_hopp(nstate, tmp_v0, tmp_v1, X, tmp_trans);
      }
      StopTimer(213);
    }
  }/*for (i = 0; i < X->Def.EDNTransfer; i += 2)*/
  StopTimer(210);
  /**
  Inter All
  */
  StartTimer(220);
  for (i = 0; i < X->Def.NInterAll_OffDiagonal; i+=2) {
    isite1 = X->Def.InterAll_OffDiagonal[i][0] + 1;
    isite2 = X->Def.InterAll_OffDiagonal[i][2] + 1;
    isite3 = X->Def.InterAll_OffDiagonal[i][4] + 1;
    isite4 = X->Def.InterAll_OffDiagonal[i][6] + 1;
    sigma1 = X->Def.InterAll_OffDiagonal[i][1];
    sigma2 = X->Def.InterAll_OffDiagonal[i][3];
    sigma3 = X->Def.InterAll_OffDiagonal[i][5];
    sigma4 = X->Def.InterAll_OffDiagonal[i][7];
    tmp_V = X->Def.ParaInterAll_OffDiagonal[i];

    if ( CheckPE(isite1 - 1, X) == TRUE || CheckPE(isite2 - 1, X) == TRUE
      || CheckPE(isite3 - 1, X) == TRUE || CheckPE(isite4 - 1, X) == TRUE) 
    {
      StartTimer(221);
      ibitsite1 = X->Def.OrgTpow[2 * isite1 - 2 + sigma1];
      ibitsite2 = X->Def.OrgTpow[2 * isite2 - 2 + sigma2];
      ibitsite3 = X->Def.OrgTpow[2 * isite3 - 2 + sigma3];
      ibitsite4 = X->Def.OrgTpow[2 * isite4 - 2 + sigma4];
      if (ibitsite1 == ibitsite2 && ibitsite3 == ibitsite4) 
        X_GC_child_CisAisCjtAjt_Hubbard_MPI(
          isite1 - 1, sigma1, isite3 - 1, sigma3, tmp_V, X, nstate, tmp_v0, tmp_v1);
      else if (ibitsite1 == ibitsite2 && ibitsite3 != ibitsite4) 
        X_GC_child_CisAisCjtAku_Hubbard_MPI(
          isite1 - 1, sigma1, isite3 - 1, sigma3, isite4 - 1, sigma4, tmp_V, X, nstate, tmp_v0, tmp_v1);
      else if (ibitsite1 != ibitsite2 && ibitsite3 == ibitsite4) 
        X_GC_child_CisAjtCkuAku_Hubbard_MPI(
          isite1 - 1, sigma1, isite2 - 1, sigma2, isite3 - 1, sigma3, tmp_V, X, nstate, tmp_v0, tmp_v1);
      else if (ibitsite1 != ibitsite2 && ibitsite3 != ibitsite4) 
        X_GC_child_CisAjtCkuAlv_Hubbard_MPI(
          isite1 - 1, sigma1, isite2 - 1, sigma2, isite3 - 1, sigma3, isite4 - 1, sigma4, tmp_V, X, nstate, tmp_v0, tmp_v1);
      StopTimer(221);
    }//InterPE
    else{
      StartTimer(222);
      for(ihermite=0; ihermite<2; ihermite++){
        idx=i+ihermite;
        isite1 = X->Def.InterAll_OffDiagonal[idx][0] + 1;
        isite2 = X->Def.InterAll_OffDiagonal[idx][2] + 1;
        isite3 = X->Def.InterAll_OffDiagonal[idx][4] + 1;
        isite4 = X->Def.InterAll_OffDiagonal[idx][6] + 1;
        sigma1 = X->Def.InterAll_OffDiagonal[idx][1];
        sigma2 = X->Def.InterAll_OffDiagonal[idx][3];
        sigma3 = X->Def.InterAll_OffDiagonal[idx][5];
        sigma4 = X->Def.InterAll_OffDiagonal[idx][7];
        tmp_V = X->Def.ParaInterAll_OffDiagonal[idx];
          
        child_general_int_GetInfo(i, X, isite1, isite2, isite3, isite4, 
                                        sigma1, sigma2, sigma3, sigma4, tmp_V); 
        GC_child_general_int(nstate, tmp_v0, tmp_v1, X);
      }/*for(ihermite=0; ihermite<2; ihermite++)*/
      StopTimer(222);
    }
  }/*for (i = 0; i < X->Def.NInterAll_OffDiagonal; i+=2)*/
  StopTimer(220);
  /**
  Pair hopping
  */
  StartTimer(230);
  for (i = 0; i < X->Def.NPairHopping; i +=2) {
    sigma1 = 0;
    sigma2 = 1;
    if ( X->Def.PairHopping[i][0] + 1 > X->Def.Nsite
      || X->Def.PairHopping[i][1] + 1 > X->Def.Nsite) 
    {
      StartTimer(231);
      X_GC_child_CisAjtCkuAlv_Hubbard_MPI(
        X->Def.PairHopping[i][0], sigma1, X->Def.PairHopping[i][1], sigma1,
        X->Def.PairHopping[i][0], sigma2, X->Def.PairHopping[i][1], sigma2,
        X->Def.ParaPairHopping[i], X, nstate, tmp_v0, tmp_v1);
      StopTimer(231);
    }
    else {
      StartTimer(232);
      for (ihermite = 0; ihermite<2; ihermite++) {
        idx = i + ihermite;
        child_pairhopp_GetInfo(idx, X);
        GC_child_pairhopp(nstate, tmp_v0, tmp_v1, X);
      }/*for (ihermite = 0; ihermite<2; ihermite++)*/
      StopTimer(232);
    }
  }/*for (i = 0; i < X->Def.NPairHopping; i += 2)*/
  StopTimer(230);
  /**
  Exchange
  */
  StartTimer(240);
  for (i = 0; i < X->Def.NExchangeCoupling; i++) {
    sigma1=0;
    sigma2=1;
    if ( X->Def.ExchangeCoupling[i][0] + 1 > X->Def.Nsite
      || X->Def.ExchangeCoupling[i][1] + 1 > X->Def.Nsite) 
    {
      StartTimer(241);
      X_GC_child_CisAjtCkuAlv_Hubbard_MPI(
        X->Def.ExchangeCoupling[i][0], sigma1, X->Def.ExchangeCoupling[i][1], sigma1,
        X->Def.ExchangeCoupling[i][1], sigma2, X->Def.ExchangeCoupling[i][0], sigma2,
        X->Def.ParaExchangeCoupling[i], X, nstate, tmp_v0, tmp_v1);
      StopTimer(241);
    }
    else {
      StartTimer(242);
      child_exchange_GetInfo(i, X);
      GC_child_exchange(nstate, tmp_v0, tmp_v1, X);
      StopTimer(242);
    }
  }/*for (i = 0; i < X->Def.NExchangeCoupling; i++)*/
  StopTimer(240);

  StopTimer(200);
  return 0;
}/*int mltplyHubbardGC*/

/******************************************************************************/
//[s] child functions
/******************************************************************************/

/**
@brief Compute pairhopp term (canonical)
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void child_pairhopp(
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X//!<[inout]
) {
  long int j;
  long unsigned int i_max = X->Large.i_max;
  long unsigned int off = 0;

#pragma omp parallel for default(none)  firstprivate(i_max, X,off) private(j) shared(tmp_v0, tmp_v1)
  for (j = 1; j <= i_max; j++) 
    child_pairhopp_element(j, nstate, tmp_v0, tmp_v1, X, &off);
  return;
}/*double complex child_pairhopp*/
/**
@brief Compute Exchange term (canonical) in single process
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void child_exchange(
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X//!<[inout]
) {
  long int j;
  long unsigned int i_max = X->Large.i_max;
  long unsigned int off = 0;

#pragma omp parallel for default(none)  firstprivate(i_max, X,off) private(j) shared(tmp_v0, tmp_v1)
  for (j = 1; j <= i_max; j++) 
    child_exchange_element(j, nstate, tmp_v0, tmp_v1, X, &off);
  return;
}/*double complex child_exchange*/
/**
@brief Compute hopping (canonical)
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void child_general_hopp(
  int nstate,
  double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X,//!<[inout]
  double complex trans//!<[in] Hopping integral
) {
  long unsigned int j, isite1, isite2, Asum, Adiff;
  long unsigned int i_max = X->Large.i_max;

  isite1 = X->Large.is1_spin;
  isite2 = X->Large.is2_spin;
  Asum = X->Large.isA_spin;
  Adiff = X->Large.A_spin;
  //fprintf(stdout, "DEBUG, isite1=%ld, isite2=%ld, Asum=%ld, Adiff=%ld \n", isite1, isite2, Asum, Adiff);
#pragma omp parallel for default(none)  \
firstprivate(i_max,X,Asum,Adiff,isite1,isite2,trans) private(j) shared(tmp_v0, tmp_v1)
  for (j = 1; j <= i_max; j++)
    CisAjt(j, nstate, tmp_v0, tmp_v1, X, isite1, isite2, Asum, Adiff, trans) * trans;
  return;
}/*double complex child_general_hopp*/
/**
@brief Commpute hopping term (grandcanonical)
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void GC_child_general_hopp(
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X,//!<[inout]
  double complex trans//!<[in] Hopping integral
) {
  long unsigned int j, isite1, isite2, Asum, Adiff;
  long unsigned int tmp_off;
  long unsigned int i_max = X->Large.i_max;

  isite1 = X->Large.is1_spin;
  isite2 = X->Large.is2_spin;
  Asum = X->Large.isA_spin;
  Adiff = X->Large.A_spin;

  if (isite1 == isite2) {
#pragma omp parallel for default(none)  \
private(j) firstprivate(i_max,X,isite1, trans) shared(tmp_v0, tmp_v1)
    for (j = 1; j <= i_max; j++)
      GC_CisAis(j, nstate, tmp_v0, tmp_v1, X, isite1, trans) * trans;
  }/*if (isite1 == isite2)*/
  else {
#pragma omp parallel for default(none)  \
firstprivate(i_max,X,Asum,Adiff,isite1,isite2,trans) private(j,tmp_off) shared(tmp_v0, tmp_v1)
    for (j = 1; j <= i_max; j++) 
      GC_CisAjt(j, nstate, tmp_v0, tmp_v1, X, isite1, isite2, Asum, Adiff, trans, &tmp_off) * trans;
  }
  return;
}/*double complex GC_child_general_hopp*/
/**
@brief Compute inter-all term (canonical)
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void child_general_int(
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X//!<[inout]
) {
  double complex tmp_V;
  long unsigned int j, i_max;
  long unsigned int isite1, isite2, isite3, isite4;
  long unsigned int Asum, Bsum, Adiff, Bdiff;
  long unsigned int tmp_off = 0;
  long unsigned int tmp_off_2 = 0;

  //note: this site is labeled for not only site but site with spin.
  i_max = X->Large.i_max;
  isite1 = X->Large.is1_spin;
  isite2 = X->Large.is2_spin;
  Asum = X->Large.isA_spin;
  Adiff = X->Large.A_spin;

  isite3 = X->Large.is3_spin;
  isite4 = X->Large.is4_spin;
  Bsum = X->Large.isB_spin;
  Bdiff = X->Large.B_spin;

  tmp_V = X->Large.tmp_V;

#pragma omp parallel default(none)  \
private(j, tmp_off, tmp_off_2) \
firstprivate(i_max, X, isite1, isite2, isite3, isite4, Asum, Bsum, Adiff, Bdiff, tmp_V) \
shared(tmp_v0, tmp_v1)
  {
    if (isite1 == isite2 && isite3 == isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        child_CisAisCisAis_element(j, isite1, isite3, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off);
    }/*if (isite1 == isite2 && isite3 == isite4)*/
    else if (isite1 == isite2 && isite3 != isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        child_CisAisCjtAku_element(
          j, isite1, isite3, isite4, Bsum, Bdiff, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off);
    }/*if (isite1 == isite2 && isite3 != isite4)*/
    else if (isite1 != isite2 && isite3 == isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        child_CisAjtCkuAku_element(j, isite1, isite2, isite3, Asum, Adiff, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off);
    }/*if (isite1 != isite2 && isite3 == isite4)*/
    else if (isite1 != isite2 && isite3 != isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        child_CisAjtCkuAlv_element(
          j, isite1, isite2, isite3, isite4, Asum, Adiff, Bsum, Bdiff, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off_2);
    }/*if (isite1 != isite2 && isite3 != isite4)*/
  }/*End of parallel region*/
  return;
}/*double complex child_general_int*/
/**
@brief Compute inter-all term (canonical)
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void GC_child_general_int(
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X//!<[inout]
) {
  double complex tmp_V;
  long unsigned int j, i_max;
  long unsigned int isite1, isite2, isite3, isite4;
  long unsigned int Asum, Bsum, Adiff, Bdiff;
  long unsigned int tmp_off = 0;
  long unsigned int tmp_off_2 = 0;

  i_max = X->Large.i_max;
  isite1 = X->Large.is1_spin;
  isite2 = X->Large.is2_spin;
  Asum = X->Large.isA_spin;
  Adiff = X->Large.A_spin;

  isite3 = X->Large.is3_spin;
  isite4 = X->Large.is4_spin;
  Bsum = X->Large.isB_spin;
  Bdiff = X->Large.B_spin;

  tmp_V = X->Large.tmp_V;

#pragma omp parallel default(none)  private(j) \
firstprivate(i_max, X, isite1, isite2, isite4, isite3, Asum, Bsum, Adiff, Bdiff, tmp_off, tmp_off_2, tmp_V) \
shared(tmp_v0, tmp_v1)
  {
    if (isite1 == isite2 && isite3 == isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        GC_child_CisAisCisAis_element(j, isite1, isite3, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off);
    }/*if (isite1 == isite2 && isite3 == isite4)*/
    else if (isite1 == isite2 && isite3 != isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        GC_child_CisAisCjtAku_element(j, isite1, isite3, isite4, Bsum, Bdiff, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off);
    }/*if (isite1 == isite2 && isite3 != isite4)*/
    else if (isite1 != isite2 && isite3 == isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        GC_child_CisAjtCkuAku_element(
          j, isite1, isite2, isite3, Asum, Adiff, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off);
    }/*if (isite1 != isite2 && isite3 == isite4)*/
    else if (isite1 != isite2 && isite3 != isite4) {
#pragma omp for
      for (j = 1; j <= i_max; j++)
        GC_child_CisAjtCkuAlv_element(
          j, isite1, isite2, isite3, isite4, Asum, Adiff, Bsum, Bdiff, tmp_V, nstate, tmp_v0, tmp_v1, X, &tmp_off_2);
    }/*if (isite1 != isite2 && isite3 != isite4)*/
  }/*End of parallel region*/
  return;
}/*double complex GC_child_general_int*/
/**
@brief Compute pairhopp term (grandcanonical)
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void GC_child_pairhopp(
  int nstate, double complex **tmp_v0,//!<[inout] Result vector
  double complex **tmp_v1,//!<[in] Input producted vector
  struct BindStruct *X//!<[inout]
) {
  long int j;
  long unsigned int i_max = X->Large.i_max;
  long unsigned int off = 0;

#pragma omp parallel for default(none)  firstprivate(i_max,X,off) private(j) shared(tmp_v0, tmp_v1)
  for (j = 1; j <= i_max; j++) 
    GC_child_pairhopp_element(j, nstate, tmp_v0, tmp_v1, X, &off);

  return;
}/*double complex GC_child_pairhopp*/
/**
@brief Compute Exchange term (grandcanonical) in single process
@author Takahiro Misawa (The University of Tokyo)
@author Kazuyoshi Yoshimi (The University of Tokyo)
*/
void GC_child_exchange(
  int nstate, double complex **tmp_v0,
  double complex **tmp_v1,
  struct BindStruct *X
) {
  long int j;
  long unsigned int i_max = X->Large.i_max;
  long unsigned int off = 0;

#pragma omp parallel for default(none) \
 firstprivate(i_max, X,off) private(j) shared(tmp_v0, tmp_v1)
  for (j = 1; j <= i_max; j++) 
    GC_child_exchange_element(j, nstate, tmp_v0, tmp_v1, X, &off);
  return;
}/*double complex GC_child_exchange*/
/******************************************************************************/
//[e] child functions
/******************************************************************************/
