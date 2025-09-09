#define S_FUNCTION_NAME mpc_wrapper
#define S_FUNCTION_LEVEL 2
#define MDL_RTW

#include "simstruc.h"
#include "mpc_solver.h"
#include <stdio.h>
#include <time.h> 
static casadi_int iw[mpc_solver_SZ_IW];
static casadi_real w[mpc_solver_SZ_W];
static int mem = 0;

static void mdlInitializeSizes(SimStruct *S) {
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    // inputs
    ssSetNumInputPorts(S, 2);
    ssSetInputPortWidth(S, 0, 2); // x0
    ssSetInputPortWidth(S, 1, 42); // xref
    
    // output
    ssSetNumOutputPorts(S, 1);
    ssSetOutputPortWidth(S, 0, 1);
    
    ssSetNumSampleTimes(S, 1);
    
    // input properties
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortRequiredContiguous(S, 0, 1);
    ssSetInputPortRequiredContiguous(S, 1, 1);
}

static void mdlInitializeSampleTimes(SimStruct *S) {
    // same sample time as QUARC plant
    ssSetSampleTime(S, 0, 0.02);  // 2ms sample time
    ssSetOffsetTime(S, 0, 0.0);
}

static void mdlStart(SimStruct *S) {
    // allocate CasADi memory
    mem = mpc_solver_alloc_mem();
    if (!mem) {
        ssSetErrorStatus(S, "Failed to allocate MPC solver memory");
        return;
    }
    
    int ret = mpc_solver_init_mem(mem);
    if (ret != 0) {
        ssSetErrorStatus(S, "Failed to initialize MPC solver memory");
        return;
    }
    
    printf("MPC S-Function initialized successfully (Ts=0.002)\n");
}

static void mdlOutputs(SimStruct *S, int_T tid) {
    // get inputs
    const real_T *x0 = (const real_T*) ssGetInputPortSignal(S, 0);
    const real_T *xref_vector = (const real_T*) ssGetInputPortSignal(S, 1);
    real_T *u_opt = ssGetOutputPortSignal(S, 0);
    
    // safety check
    if (!x0 || !xref_vector || !u_opt) {
        ssSetErrorStatus(S, "Null input/output pointers");
        return;
    }
    
    clock_t start_time = clock();

    static casadi_real xref_casadi[42];
    for (int k = 0; k < 21; k++) {
        xref_casadi[k] = xref_vector[2*k]; // position references
        xref_casadi[21 + k] = xref_vector[2*k + 1];  // velocity references
    }
    
    // prepare CasADi call
    const casadi_real *arg[mpc_solver_SZ_ARG];
    casadi_real *res[mpc_solver_SZ_RES];
    
    // initialize to NULL
    for (int i = 0; i < mpc_solver_SZ_ARG; i++) arg[i] = NULL;
    for (int i = 0; i < mpc_solver_SZ_RES; i++) res[i] = NULL;
    
    // set arguments
    arg[0] = x0; // initial state
    arg[1] = xref_casadi;  // reference trajectory
    
    // set results
    res[0] = u_opt; // optimal control output
    
    // debug first few calls
    static int call_count = 0;
    if (call_count < 3) {
        printf("MPC Call %d (Ts=0.002): x0=[%.3f,%.3f], xref_0=[%.3f,%.3f]\n", 
               call_count, x0[0], x0[1], xref_vector[0], xref_vector[1]);
        call_count++;
    }
    
    // call MPC solver
    int ret = mpc_solver(arg, res, iw, w, mem);

    clock_t end_time = clock();
    double execution_time_ms = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;

    // Report timing every 50 calls to avoid spam
    static int timing_counter = 0;
    if (timing_counter % 50 == 0) {
        printf("MPC execution time: %.2f ms\n", execution_time_ms);
        if (execution_time_ms > 20.0) {
            printf("WARNING: Execution time exceeds 20ms.\n");
        }
    }
    timing_counter++;
    
    if (ret != 0) {
        // solver failed - use safe output
        printf("MPC solver failed with code %d\n", ret);
        u_opt[0] = 0.0;
        // continue with zero output
    } else {
        // success
        if (call_count <= 3) {
            printf("MPC success: u_opt = %.6f\n", u_opt[0]);
        }
    }
}

static void mdlTerminate(SimStruct *S) {
    if (mem) {
        mpc_solver_free_mem(mem);
        mem = 0;
    }
    printf("MPC S-Function terminated\n");
}

#ifdef MDL_RTW
static void mdlRTW(SimStruct *S) {
}
#endif

#ifdef MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif