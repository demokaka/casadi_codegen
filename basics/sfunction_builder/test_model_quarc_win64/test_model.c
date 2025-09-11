/*
 * test_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test_model".
 *
 * Model version              : 19.1
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Thu Sep 11 18:36:12 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_model.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "test_model_private.h"
#include <string.h>
#include "test_model_dt.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function5' */
#define test_model_CALL_EVENT          (-1)

/* Block signals (default storage) */
B_test_model_T test_model_B;

/* Block states (default storage) */
DW_test_model_T test_model_DW;

/* Real-time model */
static RT_MODEL_test_model_T test_model_M_;
RT_MODEL_test_model_T *const test_model_M = &test_model_M_;

/* Model output function */
void test_model_output(void)
{
  real_T rtb_DelayLine11[6];
  real_T q;
  real_T rtb_HILReadEncoder;
  real_T tmp;
  real_T x_tmp;
  real_T *lastU;
  int32_T k;

  /* MATLAB Function: '<Root>/MATLAB Function5' */
  test_model_DW.sfEvent = test_model_CALL_EVENT;

  /* Clock: '<Root>/Clock5' incorporates:
   *  Derivative: '<Root>/Derivative'
   */
  /* MATLAB Function 'MATLAB Function5': '<S1>:1' */
  /* '<S1>:1:2' */
  /* '<S1>:1:3' */
  /* '<S1>:1:4' */
  x_tmp = test_model_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function5' incorporates:
   *  Clock: '<Root>/Clock5'
   */
  tmp = 3.1415926535897931 * x_tmp;
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = (rtNaN);
  } else {
    q = fabs(tmp / 6.2831853071795862);
    if (fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q) {
      tmp = fmod(tmp, 6.2831853071795862);
    } else {
      tmp = 0.0;
    }

    if (tmp == 0.0) {
      tmp = 0.0;
    } else if (tmp < 0.0) {
      tmp += 6.2831853071795862;
    }
  }

  /* '<S1>:1:5' */
  /* '<S1>:1:6' */
  test_model_B.ref[0] = ((real_T)(tmp < 3.1415926535897931) * 2.0 - 1.0) *
    -0.78539816339744828;
  test_model_B.ref[1] = 0.0;

  /* ZeroOrderHold: '<Root>/Zero-Order Hold5' */
  test_model_B.ZeroOrderHold5[0] = test_model_B.ref[0];
  test_model_B.ZeroOrderHold5[1] = test_model_B.ref[1];

  /* S-Function (sdspsreg2): '<Root>/Delay Line10' */
  for (k = 0; k < 6 - test_model_DW.DelayLine10_BUFF_OFFSET; k++) {
    test_model_B.DelayLine10[k] =
      test_model_DW.DelayLine10_Buff[test_model_DW.DelayLine10_BUFF_OFFSET + k];
  }

  for (k = 0; k < test_model_DW.DelayLine10_BUFF_OFFSET; k++) {
    test_model_B.DelayLine10[(k - test_model_DW.DelayLine10_BUFF_OFFSET) + 6] =
      test_model_DW.DelayLine10_Buff[k];
  }

  /* End of S-Function (sdspsreg2): '<Root>/Delay Line10' */

  /* S-Function (sdspsreg2): '<Root>/Delay Line11' */
  for (k = 0; k < 6 - test_model_DW.DelayLine11_BUFF_OFFSET; k++) {
    rtb_DelayLine11[k] =
      test_model_DW.DelayLine11_Buff[test_model_DW.DelayLine11_BUFF_OFFSET + k];
  }

  for (k = 0; k < test_model_DW.DelayLine11_BUFF_OFFSET; k++) {
    rtb_DelayLine11[(k - test_model_DW.DelayLine11_BUFF_OFFSET) + 6] =
      test_model_DW.DelayLine11_Buff[k];
  }

  /* End of S-Function (sdspsreg2): '<Root>/Delay Line11' */
  for (k = 0; k < 6; k++) {
    /* Reshape: '<Root>/Reshape5' */
    test_model_B.xref[k] = test_model_B.DelayLine10[k];
    test_model_B.xref[k + 6] = rtb_DelayLine11[k];
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: test_model/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(test_model_DW.HILInitialize_Card,
      &test_model_P.HILReadEncoder_channels, 1,
      &test_model_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(test_model_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder = test_model_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/counts to rad' */
  test_model_B.thetarad = test_model_P.countstorad_Gain * rtb_HILReadEncoder;

  /* Derivative: '<Root>/Derivative' */
  if ((test_model_DW.TimeStampA >= x_tmp) && (test_model_DW.TimeStampB >= x_tmp))
  {
    /* Derivative: '<Root>/Derivative' */
    test_model_B.omegaradsec = 0.0;
  } else {
    rtb_HILReadEncoder = test_model_DW.TimeStampA;
    lastU = &test_model_DW.LastUAtTimeA;
    if (test_model_DW.TimeStampA < test_model_DW.TimeStampB) {
      if (test_model_DW.TimeStampB < x_tmp) {
        rtb_HILReadEncoder = test_model_DW.TimeStampB;
        lastU = &test_model_DW.LastUAtTimeB;
      }
    } else if (test_model_DW.TimeStampA >= x_tmp) {
      rtb_HILReadEncoder = test_model_DW.TimeStampB;
      lastU = &test_model_DW.LastUAtTimeB;
    }

    /* Derivative: '<Root>/Derivative' */
    test_model_B.omegaradsec = (test_model_B.thetarad - *lastU) / (x_tmp -
      rtb_HILReadEncoder);
  }
}

/* Model update function */
void test_model_update(void)
{
  real_T *lastU;

  /* Update for S-Function (sdspsreg2): '<Root>/Delay Line10' */
  test_model_DW.DelayLine10_Buff[test_model_DW.DelayLine10_BUFF_OFFSET] =
    test_model_B.ZeroOrderHold5[0];
  test_model_DW.DelayLine10_BUFF_OFFSET++;
  while (test_model_DW.DelayLine10_BUFF_OFFSET >= 6) {
    test_model_DW.DelayLine10_BUFF_OFFSET -= 6;
  }

  /* End of Update for S-Function (sdspsreg2): '<Root>/Delay Line10' */

  /* Update for S-Function (sdspsreg2): '<Root>/Delay Line11' */
  test_model_DW.DelayLine11_Buff[test_model_DW.DelayLine11_BUFF_OFFSET] =
    test_model_B.ZeroOrderHold5[1];
  test_model_DW.DelayLine11_BUFF_OFFSET++;
  while (test_model_DW.DelayLine11_BUFF_OFFSET >= 6) {
    test_model_DW.DelayLine11_BUFF_OFFSET -= 6;
  }

  /* End of Update for S-Function (sdspsreg2): '<Root>/Delay Line11' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (test_model_DW.TimeStampA == (rtInf)) {
    test_model_DW.TimeStampA = test_model_M->Timing.t[0];
    lastU = &test_model_DW.LastUAtTimeA;
  } else if (test_model_DW.TimeStampB == (rtInf)) {
    test_model_DW.TimeStampB = test_model_M->Timing.t[0];
    lastU = &test_model_DW.LastUAtTimeB;
  } else if (test_model_DW.TimeStampA < test_model_DW.TimeStampB) {
    test_model_DW.TimeStampA = test_model_M->Timing.t[0];
    lastU = &test_model_DW.LastUAtTimeA;
  } else {
    test_model_DW.TimeStampB = test_model_M->Timing.t[0];
    lastU = &test_model_DW.LastUAtTimeB;
  }

  *lastU = test_model_B.thetarad;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test_model_M->Timing.clockTick0)) {
    ++test_model_M->Timing.clockTickH0;
  }

  test_model_M->Timing.t[0] = test_model_M->Timing.clockTick0 *
    test_model_M->Timing.stepSize0 + test_model_M->Timing.clockTickH0 *
    test_model_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++test_model_M->Timing.clockTick1)) {
      ++test_model_M->Timing.clockTickH1;
    }

    test_model_M->Timing.t[1] = test_model_M->Timing.clockTick1 *
      test_model_M->Timing.stepSize1 + test_model_M->Timing.clockTickH1 *
      test_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void test_model_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: test_model/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0@tcpip://localhost:18922",
                      &test_model_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(test_model_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(test_model_DW.HILInitialize_Card,
      "deadband_compensation=0.3;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;min_diode_compensation=0.3;max_diode_compensation=1.5",
      125);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(test_model_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(test_model_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(test_model_M, _rt_error_message);
      return;
    }

    if ((test_model_P.HILInitialize_AIPStart && !is_switching) ||
        (test_model_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(test_model_DW.HILInitialize_Card,
        &test_model_P.HILInitialize_AIChannels, 1U,
        &test_model_P.HILInitialize_AILow, &test_model_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if ((test_model_P.HILInitialize_AOPStart && !is_switching) ||
        (test_model_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(test_model_DW.HILInitialize_Card,
        &test_model_P.HILInitialize_AOChannels, 1U,
        &test_model_P.HILInitialize_AOLow, &test_model_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if ((test_model_P.HILInitialize_AOStart && !is_switching) ||
        (test_model_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(test_model_DW.HILInitialize_Card,
        &test_model_P.HILInitialize_AOChannels, 1U,
        &test_model_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if (test_model_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (test_model_DW.HILInitialize_Card,
         &test_model_P.HILInitialize_AOChannels, 1U,
         &test_model_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(test_model_DW.HILInitialize_Card, NULL,
      0U, &test_model_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(test_model_M, _rt_error_message);
      return;
    }

    if ((test_model_P.HILInitialize_DOStart && !is_switching) ||
        (test_model_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(test_model_DW.HILInitialize_Card,
        &test_model_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &test_model_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if (test_model_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (test_model_DW.HILInitialize_Card,
         &test_model_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &test_model_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if ((test_model_P.HILInitialize_EIPStart && !is_switching) ||
        (test_model_P.HILInitialize_EIPEnter && is_switching)) {
      test_model_DW.HILInitialize_QuadratureModes[0] =
        test_model_P.HILInitialize_EIQuadrature;
      test_model_DW.HILInitialize_QuadratureModes[1] =
        test_model_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(test_model_DW.HILInitialize_Card,
        test_model_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &test_model_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if ((test_model_P.HILInitialize_EIStart && !is_switching) ||
        (test_model_P.HILInitialize_EIEnter && is_switching)) {
      test_model_DW.HILInitialize_InitialEICounts[0] =
        test_model_P.HILInitialize_EIInitial;
      test_model_DW.HILInitialize_InitialEICounts[1] =
        test_model_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(test_model_DW.HILInitialize_Card,
        test_model_P.HILInitialize_EIChannels, 2U,
        &test_model_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if ((test_model_P.HILInitialize_OOStart && !is_switching) ||
        (test_model_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(test_model_DW.HILInitialize_Card,
        test_model_P.HILInitialize_OOChannels, 3U,
        test_model_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }

    if (test_model_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (test_model_DW.HILInitialize_Card, test_model_P.HILInitialize_OOChannels,
         3U, test_model_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(test_model_M, _rt_error_message);
        return;
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line10' */
    test_model_DW.DelayLine10_BUFF_OFFSET = 0;
    for (i = 0; i < 6; i++) {
      test_model_DW.DelayLine10_Buff[i] = 0.0;

      /* InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line11' */
      test_model_DW.DelayLine11_Buff[i] = 0.0;
    }

    /* End of InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line10' */

    /* InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line11' */
    test_model_DW.DelayLine11_BUFF_OFFSET = 0;

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    test_model_DW.TimeStampA = (rtInf);
    test_model_DW.TimeStampB = (rtInf);

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5' */
    test_model_DW.sfEvent = test_model_CALL_EVENT;
  }
}

/* Model terminate function */
void test_model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: test_model/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(test_model_DW.HILInitialize_Card);
    hil_monitor_stop_all(test_model_DW.HILInitialize_Card);
    is_switching = false;
    if ((test_model_P.HILInitialize_AOTerminate && !is_switching) ||
        (test_model_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((test_model_P.HILInitialize_DOTerminate && !is_switching) ||
        (test_model_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((test_model_P.HILInitialize_OOTerminate && !is_switching) ||
        (test_model_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(test_model_DW.HILInitialize_Card
                         , &test_model_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &test_model_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , test_model_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &test_model_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &test_model_P.HILInitialize_DOFinal
                         , test_model_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(test_model_DW.HILInitialize_Card,
            &test_model_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &test_model_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(test_model_DW.HILInitialize_Card,
            &test_model_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &test_model_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(test_model_DW.HILInitialize_Card,
            test_model_P.HILInitialize_OOChannels, num_final_other_outputs,
            test_model_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(test_model_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(test_model_DW.HILInitialize_Card);
    hil_monitor_delete_all(test_model_DW.HILInitialize_Card);
    hil_close(test_model_DW.HILInitialize_Card);
    test_model_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  test_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  test_model_update();
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
  test_model_initialize();
}

void MdlTerminate(void)
{
  test_model_terminate();
}

/* Registration function */
RT_MODEL_test_model_T *test_model(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_model_M, 0,
                sizeof(RT_MODEL_test_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test_model_M->solverInfo,
                          &test_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&test_model_M->solverInfo, &rtmGetTPtr(test_model_M));
    rtsiSetStepSizePtr(&test_model_M->solverInfo,
                       &test_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test_model_M->solverInfo, (&rtmGetErrorStatus
      (test_model_M)));
    rtsiSetRTModelPtr(&test_model_M->solverInfo, test_model_M);
  }

  rtsiSetSimTimeStep(&test_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&test_model_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&test_model_M->solverInfo, false);
  rtsiSetSolverName(&test_model_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = test_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    test_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    test_model_M->Timing.sampleTimes = (&test_model_M->Timing.sampleTimesArray[0]);
    test_model_M->Timing.offsetTimes = (&test_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    test_model_M->Timing.sampleTimes[0] = (0.0);
    test_model_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    test_model_M->Timing.offsetTimes[0] = (0.0);
    test_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(test_model_M, &test_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = test_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    test_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(test_model_M, -1);
  test_model_M->Timing.stepSize0 = 0.02;
  test_model_M->Timing.stepSize1 = 0.02;

  /* External mode info */
  test_model_M->Sizes.checksums[0] = (3618668605U);
  test_model_M->Sizes.checksums[1] = (4037207676U);
  test_model_M->Sizes.checksums[2] = (317429123U);
  test_model_M->Sizes.checksums[3] = (3588167149U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    test_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_model_M->extModeInfo,
      &test_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_model_M->extModeInfo, test_model_M->Sizes.checksums);
    rteiSetTPtr(test_model_M->extModeInfo, rtmGetTPtr(test_model_M));
  }

  test_model_M->solverInfoPtr = (&test_model_M->solverInfo);
  test_model_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&test_model_M->solverInfo, 0.02);
  rtsiSetSolverMode(&test_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  test_model_M->blockIO = ((void *) &test_model_B);
  (void) memset(((void *) &test_model_B), 0,
                sizeof(B_test_model_T));

  /* parameters */
  test_model_M->defaultParam = ((real_T *)&test_model_P);

  /* states (dwork) */
  test_model_M->dwork = ((void *) &test_model_DW);
  (void) memset((void *)&test_model_DW, 0,
                sizeof(DW_test_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  test_model_M->Sizes.numContStates = (0);/* Number of continuous states */
  test_model_M->Sizes.numY = (0);      /* Number of model outputs */
  test_model_M->Sizes.numU = (0);      /* Number of model inputs */
  test_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  test_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  test_model_M->Sizes.numBlocks = (17);/* Number of blocks */
  test_model_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  test_model_M->Sizes.numBlockPrms = (79);/* Sum of parameter "widths" */
  return test_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
