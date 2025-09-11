/*
 * approach_01_casadi_sqpmethod.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "approach_01_casadi_sqpmethod".
 *
 * Model version              : 1.1
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Thu Sep 11 20:09:51 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "approach_01_casadi_sqpmethod.h"
#include <string.h>
#include "approach_01_casadi_sqpmethod_private.h"
#include "approach_01_casadi_sqpmethod_dt.h"

/* Block signals (default storage) */
B_approach_01_casadi_sqpmethod_T approach_01_casadi_sqpmethod_B;

/* Block states (default storage) */
DW_approach_01_casadi_sqpmethod_T approach_01_casadi_sqpmethod_DW;

/* Real-time model */
static RT_MODEL_approach_01_casadi_sqpmethod_T approach_01_casadi_sqpmethod_M_;
RT_MODEL_approach_01_casadi_sqpmethod_T *const approach_01_casadi_sqpmethod_M =
  &approach_01_casadi_sqpmethod_M_;

/* Model output function */
void approach_01_casadi_sqpmethod_output(void)
{
  /* SignalConversion generated from: '<Root>/S-Function' */
  approach_01_casadi_sqpmethod_B.TmpSignalConversionAtSFunctionI[0] = 0.0;
  approach_01_casadi_sqpmethod_B.TmpSignalConversionAtSFunctionI[1] = 0.0;

  /* SignalConversion generated from: '<Root>/S-Function' */
  memset(&approach_01_casadi_sqpmethod_B.TmpSignalConversionAtSFunctio_j[0], 0,
         12U * sizeof(real_T));

  /* S-Function (solver_01_wrapper): '<Root>/S-Function' */

  /* Level2 S-Function Block: '<Root>/S-Function' (solver_01_wrapper) */
  {
    SimStruct *rts = approach_01_casadi_sqpmethod_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
void approach_01_casadi_sqpmethod_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++approach_01_casadi_sqpmethod_M->Timing.clockTick0)) {
    ++approach_01_casadi_sqpmethod_M->Timing.clockTickH0;
  }

  approach_01_casadi_sqpmethod_M->Timing.t[0] =
    approach_01_casadi_sqpmethod_M->Timing.clockTick0 *
    approach_01_casadi_sqpmethod_M->Timing.stepSize0 +
    approach_01_casadi_sqpmethod_M->Timing.clockTickH0 *
    approach_01_casadi_sqpmethod_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void approach_01_casadi_sqpmethod_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: approach_01_casadi_sqpmethod/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0@tcpip://localhost:18922",
                      &approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
       "deadband_compensation=0.3;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;min_diode_compensation=0.3;max_diode_compensation=1.5",
       125);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
      return;
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_AIPStart && !is_switching)
        || (approach_01_casadi_sqpmethod_P.HILInitialize_AIPEnter &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AIChannels, 1U,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AILow,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_AOPStart && !is_switching)
        || (approach_01_casadi_sqpmethod_P.HILInitialize_AOPEnter &&
            is_switching)) {
      result = hil_set_analog_output_ranges
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOChannels, 1U,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOLow,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_AOStart && !is_switching) ||
        (approach_01_casadi_sqpmethod_P.HILInitialize_AOEnter && is_switching))
    {
      result = hil_write_analog
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOChannels, 1U,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if (approach_01_casadi_sqpmethod_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOChannels, 1U,
         &approach_01_casadi_sqpmethod_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (approach_01_casadi_sqpmethod_DW.HILInitialize_Card, NULL, 0U,
       &approach_01_casadi_sqpmethod_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
      return;
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_DOStart && !is_switching) ||
        (approach_01_casadi_sqpmethod_P.HILInitialize_DOEnter && is_switching))
    {
      result = hil_write_digital
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         &approach_01_casadi_sqpmethod_P.HILInitialize_DOChannels, 1U,
         (t_boolean *) &approach_01_casadi_sqpmethod_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if (approach_01_casadi_sqpmethod_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         &approach_01_casadi_sqpmethod_P.HILInitialize_DOChannels, 1U, (const
          t_digital_state *)
         &approach_01_casadi_sqpmethod_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_EIPStart && !is_switching)
        || (approach_01_casadi_sqpmethod_P.HILInitialize_EIPEnter &&
            is_switching)) {
      approach_01_casadi_sqpmethod_DW.HILInitialize_QuadratureModes[0] =
        approach_01_casadi_sqpmethod_P.HILInitialize_EIQuadrature;
      approach_01_casadi_sqpmethod_DW.HILInitialize_QuadratureModes[1] =
        approach_01_casadi_sqpmethod_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         approach_01_casadi_sqpmethod_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &approach_01_casadi_sqpmethod_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_EIStart && !is_switching) ||
        (approach_01_casadi_sqpmethod_P.HILInitialize_EIEnter && is_switching))
    {
      approach_01_casadi_sqpmethod_DW.HILInitialize_InitialEICounts[0] =
        approach_01_casadi_sqpmethod_P.HILInitialize_EIInitial;
      approach_01_casadi_sqpmethod_DW.HILInitialize_InitialEICounts[1] =
        approach_01_casadi_sqpmethod_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         approach_01_casadi_sqpmethod_P.HILInitialize_EIChannels, 2U,
         &approach_01_casadi_sqpmethod_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_OOStart && !is_switching) ||
        (approach_01_casadi_sqpmethod_P.HILInitialize_OOEnter && is_switching))
    {
      result = hil_write_other
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         approach_01_casadi_sqpmethod_P.HILInitialize_OOChannels, 3U,
         approach_01_casadi_sqpmethod_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }

    if (approach_01_casadi_sqpmethod_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
         approach_01_casadi_sqpmethod_P.HILInitialize_OOChannels, 3U,
         approach_01_casadi_sqpmethod_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void approach_01_casadi_sqpmethod_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: approach_01_casadi_sqpmethod/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    hil_monitor_stop_all(approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    is_switching = false;
    if ((approach_01_casadi_sqpmethod_P.HILInitialize_AOTerminate &&
         !is_switching) || (approach_01_casadi_sqpmethod_P.HILInitialize_AOExit &&
         is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_DOTerminate &&
         !is_switching) || (approach_01_casadi_sqpmethod_P.HILInitialize_DOExit &&
         is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((approach_01_casadi_sqpmethod_P.HILInitialize_OOTerminate &&
         !is_switching) || (approach_01_casadi_sqpmethod_P.HILInitialize_OOExit &&
         is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(approach_01_casadi_sqpmethod_DW.HILInitialize_Card
                         ,
                         &approach_01_casadi_sqpmethod_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         ,
                         &approach_01_casadi_sqpmethod_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         ,
                         approach_01_casadi_sqpmethod_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &approach_01_casadi_sqpmethod_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &approach_01_casadi_sqpmethod_P.HILInitialize_DOFinal
                         , approach_01_casadi_sqpmethod_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
             &approach_01_casadi_sqpmethod_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &approach_01_casadi_sqpmethod_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
             &approach_01_casadi_sqpmethod_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &approach_01_casadi_sqpmethod_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (approach_01_casadi_sqpmethod_DW.HILInitialize_Card,
             approach_01_casadi_sqpmethod_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             approach_01_casadi_sqpmethod_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(approach_01_casadi_sqpmethod_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    hil_monitor_delete_all(approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    hil_close(approach_01_casadi_sqpmethod_DW.HILInitialize_Card);
    approach_01_casadi_sqpmethod_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (solver_01_wrapper): '<Root>/S-Function' */
  /* Level2 S-Function Block: '<Root>/S-Function' (solver_01_wrapper) */
  {
    SimStruct *rts = approach_01_casadi_sqpmethod_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  approach_01_casadi_sqpmethod_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  approach_01_casadi_sqpmethod_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  approach_01_casadi_sqpmethod_initialize();
}

void MdlTerminate(void)
{
  approach_01_casadi_sqpmethod_terminate();
}

/* Registration function */
RT_MODEL_approach_01_casadi_sqpmethod_T *approach_01_casadi_sqpmethod(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)approach_01_casadi_sqpmethod_M, 0,
                sizeof(RT_MODEL_approach_01_casadi_sqpmethod_T));
  rtsiSetSolverName(&approach_01_casadi_sqpmethod_M->solverInfo,
                    "FixedStepDiscrete");
  approach_01_casadi_sqpmethod_M->solverInfoPtr =
    (&approach_01_casadi_sqpmethod_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      approach_01_casadi_sqpmethod_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    approach_01_casadi_sqpmethod_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    approach_01_casadi_sqpmethod_M->Timing.sampleTimes =
      (&approach_01_casadi_sqpmethod_M->Timing.sampleTimesArray[0]);
    approach_01_casadi_sqpmethod_M->Timing.offsetTimes =
      (&approach_01_casadi_sqpmethod_M->Timing.offsetTimesArray[0]);

    /* task periods */
    approach_01_casadi_sqpmethod_M->Timing.sampleTimes[0] = (0.002);

    /* task offsets */
    approach_01_casadi_sqpmethod_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(approach_01_casadi_sqpmethod_M,
             &approach_01_casadi_sqpmethod_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = approach_01_casadi_sqpmethod_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    approach_01_casadi_sqpmethod_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(approach_01_casadi_sqpmethod_M, -1);
  approach_01_casadi_sqpmethod_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  approach_01_casadi_sqpmethod_M->Sizes.checksums[0] = (1106640545U);
  approach_01_casadi_sqpmethod_M->Sizes.checksums[1] = (752356232U);
  approach_01_casadi_sqpmethod_M->Sizes.checksums[2] = (3181590408U);
  approach_01_casadi_sqpmethod_M->Sizes.checksums[3] = (3238043426U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    approach_01_casadi_sqpmethod_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(approach_01_casadi_sqpmethod_M->extModeInfo,
      &approach_01_casadi_sqpmethod_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(approach_01_casadi_sqpmethod_M->extModeInfo,
                        approach_01_casadi_sqpmethod_M->Sizes.checksums);
    rteiSetTPtr(approach_01_casadi_sqpmethod_M->extModeInfo, rtmGetTPtr
                (approach_01_casadi_sqpmethod_M));
  }

  approach_01_casadi_sqpmethod_M->solverInfoPtr =
    (&approach_01_casadi_sqpmethod_M->solverInfo);
  approach_01_casadi_sqpmethod_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&approach_01_casadi_sqpmethod_M->solverInfo, 0.002);
  rtsiSetSolverMode(&approach_01_casadi_sqpmethod_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  approach_01_casadi_sqpmethod_M->blockIO = ((void *)
    &approach_01_casadi_sqpmethod_B);
  (void) memset(((void *) &approach_01_casadi_sqpmethod_B), 0,
                sizeof(B_approach_01_casadi_sqpmethod_T));

  /* parameters */
  approach_01_casadi_sqpmethod_M->defaultParam = ((real_T *)
    &approach_01_casadi_sqpmethod_P);

  /* states (dwork) */
  approach_01_casadi_sqpmethod_M->dwork = ((void *)
    &approach_01_casadi_sqpmethod_DW);
  (void) memset((void *)&approach_01_casadi_sqpmethod_DW, 0,
                sizeof(DW_approach_01_casadi_sqpmethod_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    approach_01_casadi_sqpmethod_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.sfcnInfo;
    approach_01_casadi_sqpmethod_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (approach_01_casadi_sqpmethod_M)));
    approach_01_casadi_sqpmethod_M->Sizes.numSampTimes = (1);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &approach_01_casadi_sqpmethod_M->Sizes.numSampTimes);
    approach_01_casadi_sqpmethod_M->NonInlinedSFcns.taskTimePtrs[0] =
      (&rtmGetTPtr(approach_01_casadi_sqpmethod_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,
                   approach_01_casadi_sqpmethod_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(approach_01_casadi_sqpmethod_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(approach_01_casadi_sqpmethod_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (approach_01_casadi_sqpmethod_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &approach_01_casadi_sqpmethod_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (approach_01_casadi_sqpmethod_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &approach_01_casadi_sqpmethod_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &approach_01_casadi_sqpmethod_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &approach_01_casadi_sqpmethod_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &approach_01_casadi_sqpmethod_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &approach_01_casadi_sqpmethod_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &approach_01_casadi_sqpmethod_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &approach_01_casadi_sqpmethod_M->solverInfoPtr);
  }

  approach_01_casadi_sqpmethod_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)
                  &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    approach_01_casadi_sqpmethod_M->childSfunctions =
      (&approach_01_casadi_sqpmethod_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    approach_01_casadi_sqpmethod_M->childSfunctions[0] =
      (&approach_01_casadi_sqpmethod_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: approach_01_casadi_sqpmethod/<Root>/S-Function (solver_01_wrapper) */
    {
      SimStruct *rts = approach_01_casadi_sqpmethod_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, approach_01_casadi_sqpmethod_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          int_T *dimensions = (int_T *)
            &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.iDims0;
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               approach_01_casadi_sqpmethod_B.TmpSignalConversionAtSFunctionI);
          dimensions[0] = 2;
          dimensions[1] = 1;
          _ssSetInputPortDimensionsPtrAsInt(rts, 0, dimensions);
          _ssSetInputPortNumDimensions(rts, 0, 2);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          int_T *dimensions = (int_T *)
            &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.iDims1;
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1,
                               approach_01_casadi_sqpmethod_B.TmpSignalConversionAtSFunctio_j);
          dimensions[0] = 2;
          dimensions[1] = 6;
          _ssSetInputPortDimensionsPtrAsInt(rts, 1, dimensions);
          _ssSetInputPortNumDimensions(rts, 1, 2);
          ssSetInputPortWidthAsInt(rts, 1, 12);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &approach_01_casadi_sqpmethod_M->
          NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          int_T *dimensions = (int_T *)
            &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.oDims0;
          dimensions[0] = 1;
          dimensions[1] = 1;
          _ssSetOutputPortDimensionsPtrAsInt(rts, 0, dimensions);
          _ssSetOutputPortNumDimensions(rts, 0, 2);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &approach_01_casadi_sqpmethod_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "approach_01_casadi_sqpmethod/S-Function");
      ssSetRTModel(rts,approach_01_casadi_sqpmethod_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &approach_01_casadi_sqpmethod_DW.SFunction_RWORK[0]);
      ssSetIWork(rts, (int_T *)
                 &approach_01_casadi_sqpmethod_DW.SFunction_IWORK[0]);
      ssSetPWork(rts, (void **)
                 &approach_01_casadi_sqpmethod_DW.SFunction_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &approach_01_casadi_sqpmethod_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 3);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 980);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &approach_01_casadi_sqpmethod_DW.SFunction_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidthAsInt(rts, 1, 18);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &approach_01_casadi_sqpmethod_DW.SFunction_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 2, 55);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &approach_01_casadi_sqpmethod_DW.SFunction_PWORK[0]);
      }

      /* registration */
      solver_01_wrapper(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  approach_01_casadi_sqpmethod_M->Sizes.numContStates = (0);/* Number of continuous states */
  approach_01_casadi_sqpmethod_M->Sizes.numY = (0);/* Number of model outputs */
  approach_01_casadi_sqpmethod_M->Sizes.numU = (0);/* Number of model inputs */
  approach_01_casadi_sqpmethod_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  approach_01_casadi_sqpmethod_M->Sizes.numSampTimes = (1);/* Number of sample times */
  approach_01_casadi_sqpmethod_M->Sizes.numBlocks = (4);/* Number of blocks */
  approach_01_casadi_sqpmethod_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  approach_01_casadi_sqpmethod_M->Sizes.numBlockPrms = (76);/* Sum of parameter "widths" */
  return approach_01_casadi_sqpmethod_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
