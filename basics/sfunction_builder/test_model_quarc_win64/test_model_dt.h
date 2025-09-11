/*
 * test_model_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&test_model_B.ZeroOrderHold5[0]), 0, 0, 24 }
  ,

  { (char_T *)(&test_model_DW.DelayLine10_Buff[0]), 0, 0, 18 },

  { (char_T *)(&test_model_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&test_model_DW.Scope57_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&test_model_DW.DelayLine10_BUFF_OFFSET), 6, 0, 10 },

  { (char_T *)(&test_model_DW.doneDoubleBufferReInit), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&test_model_P.HILReadEncoder_channels), 7, 0, 1 },

  { (char_T *)(&test_model_P.HILInitialize_OOTerminate), 0, 0, 26 },

  { (char_T *)(&test_model_P.HILInitialize_CKChannels), 6, 0, 7 },

  { (char_T *)(&test_model_P.HILInitialize_AIChannels), 7, 0, 9 },

  { (char_T *)(&test_model_P.HILInitialize_Active), 8, 0, 36 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] test_model_dt.h */
