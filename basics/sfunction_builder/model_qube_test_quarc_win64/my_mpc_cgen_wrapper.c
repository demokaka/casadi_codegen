#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "my_mpc_cgen_wrapper.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void my_mpc_Outputs_wrapper(const real_T *x0,
  const real_T *xref,
  real_T *u_opt);
void my_mpc_Outputs_wrapper_cgen(const real_T *x0,
  const real_T *xref,
  real_T *u_opt)
{
  my_mpc_Outputs_wrapper(x0,
    xref,
    u_opt);
}

#undef SFB_EXTERN_C
