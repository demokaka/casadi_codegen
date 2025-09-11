
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#include "my_solver.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 2
#define u_1_width 12
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void my_mpc_Outputs_wrapper(const real_T *x0,
			const real_T *xref,
			real_T *u_opt);

void my_mpc_Outputs_wrapper(const real_T *x0,
			const real_T *xref,
			real_T *u_opt)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
    
    // const casadi_real *arg[my_solver_SZ_ARG];
    // casadi_real *res[my_solver_SZ_RES];

    static casadi_real          w_buf[my_solver_SZ_W];
    static casadi_int           iw_buf[my_solver_SZ_IW];
    static const casadi_real    *arg[my_solver_SZ_ARG];
    static casadi_real          *res[my_solver_SZ_RES];

    arg[0] = (const casadi_real*)x0;      /* size 2 */
    arg[1] = (const casadi_real*)xref;    /* size 12 (2x6 flatten) */

    res[0] = (casadi_real*)u_opt;         /* size 1 */

    int status = my_solver(
        (const casadi_real**)arg,
        (casadi_real**)res,
        (casadi_int*)iw_buf,
        (casadi_real*)w_buf,
        /*mem*/ 0
    );
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


