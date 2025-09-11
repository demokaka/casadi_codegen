/*
 * model_qube_test_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "model_qube_test".
 *
 * Model version              : 19.2
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Thu Sep 11 17:46:32 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef model_qube_test_private_h_
#define model_qube_test_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "model_qube_test_types.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void my_mpc_Start_wrapper(void);
SFB_EXTERN_C void my_mpc_Outputs_wrapper(const real_T *x0,
  const real_T *xref,
  real_T *u_opt);
SFB_EXTERN_C void my_mpc_Terminate_wrapper(void);

#undef SFB_EXTERN_C

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];

#endif                                 /* model_qube_test_private_h_ */
