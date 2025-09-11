#ifndef _MY_MPC_CGEN_WRAPPER_H_
#define _MY_MPC_CGEN_WRAPPER_H_
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void my_mpc_Outputs_wrapper_cgen(const real_T *x0,
  const real_T *xref,
  real_T *u_opt);

#undef SFB_EXTERN_C
#endif
