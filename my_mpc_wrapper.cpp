
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
#define u_1_width 42
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

    /* Read in CasADi function dimensions */
    // int_T n_in  = my_solver_n_in();
    // int_T n_out = my_solver_n_out();
    // int_T sz_arg, sz_res, sz_iw, sz_w;
    // my_solver_work(&sz_arg, &sz_res, &sz_iw, &sz_w);
    // int_T n_in  = my_solver_n_in();
    // std::cout << n_in << std::endl;
    
    const casadi_real *arg[mpc_solver_SZ_ARG];




/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


