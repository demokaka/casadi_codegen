/* self-written basic c-mex s-function timestwo.c */
#define S_FUNCTION_NAME timestwo_m
#define S_FUNCTION_LEVEL 2

#include "simstruct.h"

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumFcnParams(S, 0);
    if (ssGetNumFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        return; // parameter mismatch will be reported by Simulink
    }

    if (!ssSetNumInputPorts(S,1)) return;
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, DYNAMICALLY_SIZED);

    ssSetNumSampleTimes(S, 1);
    
    /* Take care when specifying exception free code - see sfuntmpl.doc */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S) 
{  
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME); 
    ssSetOffsetTime(S, 0, 0.0); 
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    int_T               i;
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    real_T *y = ssGetOutputPortRealSignal(S,0);
    int_T width = ssGetOutputPortWidth(S,0);

    for (i=0; i<width; i++)
    {
        *y++ = 2.0 * (*uPtrs[i]);
    }
}

static void mdlTerminate(SimStruct *S){}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */ 
#include "simulink.c" /* MEX-file interface mechanism */ 
#else #include "cg_sfun.h" /* Code generation registration function */ 
#endif