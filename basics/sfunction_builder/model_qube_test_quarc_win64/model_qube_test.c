/*
 * model_qube_test.c
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

#include "model_qube_test.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "model_qube_test_private.h"
#include <string.h>
#include "model_qube_test_dt.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function5' */
#define model_qube_test_CALL_EVENT     (-1)

/* Block signals (default storage) */
B_model_qube_test_T model_qube_test_B;

/* Block states (default storage) */
DW_model_qube_test_T model_qube_test_DW;

/* Real-time model */
static RT_MODEL_model_qube_test_T model_qube_test_M_;
RT_MODEL_model_qube_test_T *const model_qube_test_M = &model_qube_test_M_;

/* Model output function */
void model_qube_test_output(void)
{
  real_T rtb_DelayLine11[6];
  real_T q;
  real_T rtb_HILReadEncoder;
  real_T *lastU;
  int32_T k;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: model_qube_test/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(model_qube_test_DW.HILInitialize_Card,
      &model_qube_test_P.HILReadEncoder_channels, 1,
      &model_qube_test_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder = model_qube_test_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/counts to rad' */
  model_qube_test_B.thetarad = model_qube_test_P.countstorad_Gain *
    rtb_HILReadEncoder;

  /* Derivative: '<Root>/Derivative' incorporates:
   *  Clock: '<Root>/Clock5'
   */
  rtb_HILReadEncoder = model_qube_test_M->Timing.t[0];
  if ((model_qube_test_DW.TimeStampA >= rtb_HILReadEncoder) &&
      (model_qube_test_DW.TimeStampB >= rtb_HILReadEncoder)) {
    /* Derivative: '<Root>/Derivative' */
    model_qube_test_B.omegaradsec = 0.0;
  } else {
    q = model_qube_test_DW.TimeStampA;
    lastU = &model_qube_test_DW.LastUAtTimeA;
    if (model_qube_test_DW.TimeStampA < model_qube_test_DW.TimeStampB) {
      if (model_qube_test_DW.TimeStampB < rtb_HILReadEncoder) {
        q = model_qube_test_DW.TimeStampB;
        lastU = &model_qube_test_DW.LastUAtTimeB;
      }
    } else if (model_qube_test_DW.TimeStampA >= rtb_HILReadEncoder) {
      q = model_qube_test_DW.TimeStampB;
      lastU = &model_qube_test_DW.LastUAtTimeB;
    }

    /* Derivative: '<Root>/Derivative' */
    model_qube_test_B.omegaradsec = (model_qube_test_B.thetarad - *lastU) /
      (rtb_HILReadEncoder - q);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* SignalConversion generated from: '<Root>/S-Function' */
  model_qube_test_B.TmpSignalConversionAtSFunctionI[0] =
    model_qube_test_B.thetarad;
  model_qube_test_B.TmpSignalConversionAtSFunctionI[1] =
    model_qube_test_B.omegaradsec;

  /* S-Function (sdspsreg2): '<Root>/Delay Line10' */
  for (k = 0; k < 6 - model_qube_test_DW.DelayLine10_BUFF_OFFSET; k++) {
    model_qube_test_B.DelayLine10[k] =
      model_qube_test_DW.DelayLine10_Buff[model_qube_test_DW.DelayLine10_BUFF_OFFSET
      + k];
  }

  for (k = 0; k < model_qube_test_DW.DelayLine10_BUFF_OFFSET; k++) {
    model_qube_test_B.DelayLine10[(k -
      model_qube_test_DW.DelayLine10_BUFF_OFFSET) + 6] =
      model_qube_test_DW.DelayLine10_Buff[k];
  }

  /* End of S-Function (sdspsreg2): '<Root>/Delay Line10' */

  /* S-Function (sdspsreg2): '<Root>/Delay Line11' */
  for (k = 0; k < 6 - model_qube_test_DW.DelayLine11_BUFF_OFFSET; k++) {
    rtb_DelayLine11[k] =
      model_qube_test_DW.DelayLine11_Buff[model_qube_test_DW.DelayLine11_BUFF_OFFSET
      + k];
  }

  for (k = 0; k < model_qube_test_DW.DelayLine11_BUFF_OFFSET; k++) {
    rtb_DelayLine11[(k - model_qube_test_DW.DelayLine11_BUFF_OFFSET) + 6] =
      model_qube_test_DW.DelayLine11_Buff[k];
  }

  /* End of S-Function (sdspsreg2): '<Root>/Delay Line11' */
  for (k = 0; k < 6; k++) {
    /* Reshape: '<Root>/Reshape5' */
    model_qube_test_B.xref[k] = model_qube_test_B.DelayLine10[k];
    model_qube_test_B.xref[k + 6] = rtb_DelayLine11[k];
  }

  /* S-Function (my_mpc): '<Root>/S-Function' */
  my_mpc_Outputs_wrapper_cgen
    (&model_qube_test_B.TmpSignalConversionAtSFunctionI[0],
     &model_qube_test_B.xref[0], &model_qube_test_B.uV);

  /* Saturate: '<Root>/Saturation1' */
  if (model_qube_test_B.uV > model_qube_test_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    model_qube_test_B.uV_k = model_qube_test_P.Saturation1_UpperSat;
  } else if (model_qube_test_B.uV < model_qube_test_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    model_qube_test_B.uV_k = model_qube_test_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    model_qube_test_B.uV_k = model_qube_test_B.uV;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog1' */

  /* S-Function Block: model_qube_test/HIL Write Analog1 (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(model_qube_test_DW.HILInitialize_Card,
      &model_qube_test_P.HILWriteAnalog1_channels, 1, &model_qube_test_B.uV_k);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function5' */
  model_qube_test_DW.sfEvent = model_qube_test_CALL_EVENT;

  /* MATLAB Function 'MATLAB Function5': '<S1>:1' */
  /* '<S1>:1:2' */
  /* '<S1>:1:3' */
  /* '<S1>:1:4' */
  rtb_HILReadEncoder *= 3.1415926535897931;
  if (rtIsNaN(rtb_HILReadEncoder) || rtIsInf(rtb_HILReadEncoder)) {
    rtb_HILReadEncoder = (rtNaN);
  } else {
    q = fabs(rtb_HILReadEncoder / 6.2831853071795862);
    if (fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q) {
      rtb_HILReadEncoder = fmod(rtb_HILReadEncoder, 6.2831853071795862);
    } else {
      rtb_HILReadEncoder = 0.0;
    }

    if (rtb_HILReadEncoder == 0.0) {
      rtb_HILReadEncoder = 0.0;
    } else if (rtb_HILReadEncoder < 0.0) {
      rtb_HILReadEncoder += 6.2831853071795862;
    }
  }

  /* '<S1>:1:5' */
  /* '<S1>:1:6' */
  model_qube_test_B.ref[0] = ((real_T)(rtb_HILReadEncoder < 3.1415926535897931) *
    2.0 - 1.0) * -0.78539816339744828;
  model_qube_test_B.ref[1] = 0.0;

  /* End of MATLAB Function: '<Root>/MATLAB Function5' */
  /* ZeroOrderHold: '<Root>/Zero-Order Hold5' */
  model_qube_test_B.ZeroOrderHold5[0] = model_qube_test_B.ref[0];
  model_qube_test_B.ZeroOrderHold5[1] = model_qube_test_B.ref[1];
}

/* Model update function */
void model_qube_test_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (model_qube_test_DW.TimeStampA == (rtInf)) {
    model_qube_test_DW.TimeStampA = model_qube_test_M->Timing.t[0];
    lastU = &model_qube_test_DW.LastUAtTimeA;
  } else if (model_qube_test_DW.TimeStampB == (rtInf)) {
    model_qube_test_DW.TimeStampB = model_qube_test_M->Timing.t[0];
    lastU = &model_qube_test_DW.LastUAtTimeB;
  } else if (model_qube_test_DW.TimeStampA < model_qube_test_DW.TimeStampB) {
    model_qube_test_DW.TimeStampA = model_qube_test_M->Timing.t[0];
    lastU = &model_qube_test_DW.LastUAtTimeA;
  } else {
    model_qube_test_DW.TimeStampB = model_qube_test_M->Timing.t[0];
    lastU = &model_qube_test_DW.LastUAtTimeB;
  }

  *lastU = model_qube_test_B.thetarad;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for S-Function (sdspsreg2): '<Root>/Delay Line10' */
  model_qube_test_DW.DelayLine10_Buff[model_qube_test_DW.DelayLine10_BUFF_OFFSET]
    = model_qube_test_B.ZeroOrderHold5[0];
  model_qube_test_DW.DelayLine10_BUFF_OFFSET++;
  while (model_qube_test_DW.DelayLine10_BUFF_OFFSET >= 6) {
    model_qube_test_DW.DelayLine10_BUFF_OFFSET -= 6;
  }

  /* End of Update for S-Function (sdspsreg2): '<Root>/Delay Line10' */

  /* Update for S-Function (sdspsreg2): '<Root>/Delay Line11' */
  model_qube_test_DW.DelayLine11_Buff[model_qube_test_DW.DelayLine11_BUFF_OFFSET]
    = model_qube_test_B.ZeroOrderHold5[1];
  model_qube_test_DW.DelayLine11_BUFF_OFFSET++;
  while (model_qube_test_DW.DelayLine11_BUFF_OFFSET >= 6) {
    model_qube_test_DW.DelayLine11_BUFF_OFFSET -= 6;
  }

  /* End of Update for S-Function (sdspsreg2): '<Root>/Delay Line11' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++model_qube_test_M->Timing.clockTick0)) {
    ++model_qube_test_M->Timing.clockTickH0;
  }

  model_qube_test_M->Timing.t[0] = model_qube_test_M->Timing.clockTick0 *
    model_qube_test_M->Timing.stepSize0 + model_qube_test_M->Timing.clockTickH0 *
    model_qube_test_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++model_qube_test_M->Timing.clockTick1)) {
      ++model_qube_test_M->Timing.clockTickH1;
    }

    model_qube_test_M->Timing.t[1] = model_qube_test_M->Timing.clockTick1 *
      model_qube_test_M->Timing.stepSize1 +
      model_qube_test_M->Timing.clockTickH1 *
      model_qube_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void model_qube_test_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: model_qube_test/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0@tcpip://localhost:18922",
                      &model_qube_test_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(model_qube_test_DW.HILInitialize_Card,
      "deadband_compensation=0.3;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;min_diode_compensation=0.3;max_diode_compensation=1.5",
      125);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(model_qube_test_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
      return;
    }

    if ((model_qube_test_P.HILInitialize_AIPStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(model_qube_test_DW.HILInitialize_Card,
        &model_qube_test_P.HILInitialize_AIChannels, 1U,
        &model_qube_test_P.HILInitialize_AILow,
        &model_qube_test_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if ((model_qube_test_P.HILInitialize_AOPStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (model_qube_test_DW.HILInitialize_Card,
         &model_qube_test_P.HILInitialize_AOChannels, 1U,
         &model_qube_test_P.HILInitialize_AOLow,
         &model_qube_test_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if ((model_qube_test_P.HILInitialize_AOStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(model_qube_test_DW.HILInitialize_Card,
        &model_qube_test_P.HILInitialize_AOChannels, 1U,
        &model_qube_test_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if (model_qube_test_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (model_qube_test_DW.HILInitialize_Card,
         &model_qube_test_P.HILInitialize_AOChannels, 1U,
         &model_qube_test_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(model_qube_test_DW.HILInitialize_Card,
      NULL, 0U, &model_qube_test_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
      return;
    }

    if ((model_qube_test_P.HILInitialize_DOStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(model_qube_test_DW.HILInitialize_Card,
        &model_qube_test_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &model_qube_test_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if (model_qube_test_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (model_qube_test_DW.HILInitialize_Card,
         &model_qube_test_P.HILInitialize_DOChannels, 1U, (const t_digital_state
          *) &model_qube_test_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if ((model_qube_test_P.HILInitialize_EIPStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_EIPEnter && is_switching)) {
      model_qube_test_DW.HILInitialize_QuadratureModes[0] =
        model_qube_test_P.HILInitialize_EIQuadrature;
      model_qube_test_DW.HILInitialize_QuadratureModes[1] =
        model_qube_test_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (model_qube_test_DW.HILInitialize_Card,
         model_qube_test_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &model_qube_test_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if ((model_qube_test_P.HILInitialize_EIStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_EIEnter && is_switching)) {
      model_qube_test_DW.HILInitialize_InitialEICounts[0] =
        model_qube_test_P.HILInitialize_EIInitial;
      model_qube_test_DW.HILInitialize_InitialEICounts[1] =
        model_qube_test_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(model_qube_test_DW.HILInitialize_Card,
        model_qube_test_P.HILInitialize_EIChannels, 2U,
        &model_qube_test_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if ((model_qube_test_P.HILInitialize_OOStart && !is_switching) ||
        (model_qube_test_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(model_qube_test_DW.HILInitialize_Card,
        model_qube_test_P.HILInitialize_OOChannels, 3U,
        model_qube_test_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }

    if (model_qube_test_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (model_qube_test_DW.HILInitialize_Card,
         model_qube_test_P.HILInitialize_OOChannels, 3U,
         model_qube_test_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        return;
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    model_qube_test_DW.TimeStampA = (rtInf);
    model_qube_test_DW.TimeStampB = (rtInf);

    /* InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line10' */
    model_qube_test_DW.DelayLine10_BUFF_OFFSET = 0;
    for (i = 0; i < 6; i++) {
      model_qube_test_DW.DelayLine10_Buff[i] = 0.0;

      /* InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line11' */
      model_qube_test_DW.DelayLine11_Buff[i] = 0.0;
    }

    /* End of InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line10' */

    /* InitializeConditions for S-Function (sdspsreg2): '<Root>/Delay Line11' */
    model_qube_test_DW.DelayLine11_BUFF_OFFSET = 0;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5' */
    model_qube_test_DW.sfEvent = model_qube_test_CALL_EVENT;
  }
}

/* Model terminate function */
void model_qube_test_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: model_qube_test/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(model_qube_test_DW.HILInitialize_Card);
    hil_monitor_stop_all(model_qube_test_DW.HILInitialize_Card);
    is_switching = false;
    if ((model_qube_test_P.HILInitialize_AOTerminate && !is_switching) ||
        (model_qube_test_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((model_qube_test_P.HILInitialize_DOTerminate && !is_switching) ||
        (model_qube_test_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((model_qube_test_P.HILInitialize_OOTerminate && !is_switching) ||
        (model_qube_test_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(model_qube_test_DW.HILInitialize_Card
                         , &model_qube_test_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &model_qube_test_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , model_qube_test_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &model_qube_test_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &model_qube_test_P.HILInitialize_DOFinal
                         , model_qube_test_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(model_qube_test_DW.HILInitialize_Card,
            &model_qube_test_P.HILInitialize_AOChannels,
            num_final_analog_outputs, &model_qube_test_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(model_qube_test_DW.HILInitialize_Card,
            &model_qube_test_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &model_qube_test_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(model_qube_test_DW.HILInitialize_Card,
            model_qube_test_P.HILInitialize_OOChannels, num_final_other_outputs,
            model_qube_test_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(model_qube_test_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(model_qube_test_DW.HILInitialize_Card);
    hil_monitor_delete_all(model_qube_test_DW.HILInitialize_Card);
    hil_close(model_qube_test_DW.HILInitialize_Card);
    model_qube_test_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  model_qube_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model_qube_test_update();
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
  model_qube_test_initialize();
}

void MdlTerminate(void)
{
  model_qube_test_terminate();
}

/* Registration function */
RT_MODEL_model_qube_test_T *model_qube_test(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)model_qube_test_M, 0,
                sizeof(RT_MODEL_model_qube_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model_qube_test_M->solverInfo,
                          &model_qube_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&model_qube_test_M->solverInfo, &rtmGetTPtr(model_qube_test_M));
    rtsiSetStepSizePtr(&model_qube_test_M->solverInfo,
                       &model_qube_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&model_qube_test_M->solverInfo, (&rtmGetErrorStatus
      (model_qube_test_M)));
    rtsiSetRTModelPtr(&model_qube_test_M->solverInfo, model_qube_test_M);
  }

  rtsiSetSimTimeStep(&model_qube_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&model_qube_test_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&model_qube_test_M->solverInfo, false);
  rtsiSetSolverName(&model_qube_test_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model_qube_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    model_qube_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model_qube_test_M->Timing.sampleTimes =
      (&model_qube_test_M->Timing.sampleTimesArray[0]);
    model_qube_test_M->Timing.offsetTimes =
      (&model_qube_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model_qube_test_M->Timing.sampleTimes[0] = (0.0);
    model_qube_test_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    model_qube_test_M->Timing.offsetTimes[0] = (0.0);
    model_qube_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(model_qube_test_M, &model_qube_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model_qube_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    model_qube_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model_qube_test_M, -1);
  model_qube_test_M->Timing.stepSize0 = 0.02;
  model_qube_test_M->Timing.stepSize1 = 0.02;

  /* External mode info */
  model_qube_test_M->Sizes.checksums[0] = (3921348262U);
  model_qube_test_M->Sizes.checksums[1] = (625670917U);
  model_qube_test_M->Sizes.checksums[2] = (3702007910U);
  model_qube_test_M->Sizes.checksums[3] = (8140573U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    model_qube_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model_qube_test_M->extModeInfo,
      &model_qube_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model_qube_test_M->extModeInfo,
                        model_qube_test_M->Sizes.checksums);
    rteiSetTPtr(model_qube_test_M->extModeInfo, rtmGetTPtr(model_qube_test_M));
  }

  model_qube_test_M->solverInfoPtr = (&model_qube_test_M->solverInfo);
  model_qube_test_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&model_qube_test_M->solverInfo, 0.02);
  rtsiSetSolverMode(&model_qube_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model_qube_test_M->blockIO = ((void *) &model_qube_test_B);
  (void) memset(((void *) &model_qube_test_B), 0,
                sizeof(B_model_qube_test_T));

  /* parameters */
  model_qube_test_M->defaultParam = ((real_T *)&model_qube_test_P);

  /* states (dwork) */
  model_qube_test_M->dwork = ((void *) &model_qube_test_DW);
  (void) memset((void *)&model_qube_test_DW, 0,
                sizeof(DW_model_qube_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model_qube_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model_qube_test_M->Sizes.numContStates = (0);/* Number of continuous states */
  model_qube_test_M->Sizes.numY = (0); /* Number of model outputs */
  model_qube_test_M->Sizes.numU = (0); /* Number of model inputs */
  model_qube_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  model_qube_test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  model_qube_test_M->Sizes.numBlocks = (23);/* Number of blocks */
  model_qube_test_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  model_qube_test_M->Sizes.numBlockPrms = (83);/* Sum of parameter "widths" */
  return model_qube_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
