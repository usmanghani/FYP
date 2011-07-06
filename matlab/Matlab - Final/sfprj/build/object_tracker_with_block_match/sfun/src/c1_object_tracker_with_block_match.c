/* Include files */
#include "object_tracker_with_block_match_sfun.h"
#include "c1_object_tracker_with_block_match.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "object_tracker_with_block_match_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_object_tracker_with_block_matchInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_object_tracker_with_block_match(void);
static void initialize_params_c1_object_tracker_with_block_match(void);
static void enable_c1_object_tracker_with_block_match(void);
static void disable_c1_object_tracker_with_block_match(void);
static void finalize_c1_object_tracker_with_block_match(void);
static void sf_c1_object_tracker_with_block_match(void);
static real_T *c1_DirectionCode(void);
static int32_T *c1_BlobCount(void);
static void init_dsm_address_info(void);
static void sf_save_state_c1_object_tracker_with_block_match(FILE *c1_file);
static void sf_load_state_c1_object_tracker_with_block_match(FILE *c1_file);

/* Function Definitions */
static void initialize_c1_object_tracker_with_block_match(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_startflag_not_empty = false;
  chartInstance.c1_brakecount_not_empty = false;
  chartInstance.c1_movecount_not_empty = false;
  chartInstance.c1_is_active_c1_object_tracker_with_block_match = 0U;
}

static void initialize_params_c1_object_tracker_with_block_match(void)
{
}

static void enable_c1_object_tracker_with_block_match(void)
{
}

static void disable_c1_object_tracker_with_block_match(void)
{
}

static void finalize_c1_object_tracker_with_block_match(void)
{
}

static void sf_c1_object_tracker_with_block_match(void)
{
  uint8_T c1_previousEvent;
  real_T c1_b_DirectionCode;
  int32_T c1_b_BlobCount;
  real_T c1_BRAKEDIFF;
  real_T c1_DIFFTHING;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c1_DirectionCode(), 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_BlobCount(), 0U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_b_DirectionCode = *c1_DirectionCode();
  c1_b_BlobCount = *c1_BlobCount();
  sf_debug_push_symbol_scope(7U, 0U);
  sf_debug_symbol_scope_add_symbol("movecount", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &chartInstance.c1_movecount, 0);
  sf_debug_symbol_scope_add_symbol("brakecount", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &chartInstance.c1_brakecount, 0);
  sf_debug_symbol_scope_add_symbol("startflag", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &chartInstance.c1_startflag, 0);
  sf_debug_symbol_scope_add_symbol("BRAKEDIFF", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c1_BRAKEDIFF, 0);
  sf_debug_symbol_scope_add_symbol("DIFFTHING", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c1_DIFFTHING, 0);
  sf_debug_symbol_scope_add_symbol("BlobCount", 6, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c1_b_BlobCount, 0);
  sf_debug_symbol_scope_add_symbol("DirectionCode", 0, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c1_b_DirectionCode, 0);
  CV_EML_FCN(0, 0);
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c1_DIFFTHING = 5.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  c1_BRAKEDIFF = 2.0;
  /* no of frames after which the position of the car is updated. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
  if(CV_EML_IF(0, 0, !chartInstance.c1_startflag_not_empty)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
    chartInstance.c1_startflag = 1.0;
    chartInstance.c1_startflag_not_empty = true;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
    chartInstance.c1_startflag = 0.0;
    chartInstance.c1_startflag_not_empty = true;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
  if(CV_EML_IF(0, 1, !chartInstance.c1_brakecount_not_empty)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
    chartInstance.c1_brakecount = 0.0;
    chartInstance.c1_brakecount_not_empty = true;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,22);
  if(CV_EML_IF(0, 2, !chartInstance.c1_movecount_not_empty)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,23);
    chartInstance.c1_movecount = 0.0;
    chartInstance.c1_movecount_not_empty = true;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,26);
  if(CV_EML_IF(0, 3, (real_T)c1_b_BlobCount == 0.0)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,27);
    chartInstance.c1_movecount = c1_DIFFTHING;
    chartInstance.c1_movecount_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,28);
    chartInstance.c1_brakecount = 0.0;
    chartInstance.c1_brakecount_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
    chartInstance.c1_startflag = 1.0;
    chartInstance.c1_startflag_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,30);
    sf_mex_call("BrakeAll", 0U, 0U);
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,34);
    chartInstance.c1_movecount = chartInstance.c1_movecount + 1.0;
    chartInstance.c1_movecount_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
    chartInstance.c1_brakecount = chartInstance.c1_brakecount + 1.0;
    chartInstance.c1_brakecount_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
    if(CV_EML_IF(0, 4, chartInstance.c1_brakecount >= c1_BRAKEDIFF)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,38);
      sf_mex_call("BrakeAll", 0U, 0U);
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,42);
    if(CV_EML_COND(0, 0, chartInstance.c1_movecount >= c1_DIFFTHING) ||
     CV_EML_COND(0, 1, chartInstance.c1_startflag == 1.0)) {
      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 5, true);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,44);
      if(CV_EML_IF(0, 6, c1_b_DirectionCode == 1.0)) {
        /* Forward */
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,45);
        sf_mex_call("MoveForward", 0U, 1U, 6, 1.0);
      } else {
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,46);
        if(CV_EML_IF(0, 7, c1_b_DirectionCode == 2.0)) {
          /* Left */
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,47);
          sf_mex_call("MoveLeft", 0U, 1U, 6, 1.0);
        } else {
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,48);
          if(CV_EML_IF(0, 8, c1_b_DirectionCode == 3.0)) {
            /* Right */
            _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,49);
            sf_mex_call("MoveRight", 0U, 1U, 6, 1.0);
          }
        }
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,52);
      sf_mex_call("MoveForward", 0U, 1U, 6, 1.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,53);
      chartInstance.c1_movecount = 0.0;
      chartInstance.c1_movecount_not_empty = true;
    } else {
      CV_EML_MCDC(0, 0, false);
      CV_EML_IF(0, 5, false);
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-53);
  sf_debug_pop_symbol_scope();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_object_tracker_with_block_matchMachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static real_T *c1_DirectionCode(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static int32_T *c1_BlobCount(void)
{
  return (int32_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c1_object_tracker_with_block_match(FILE *c1_file)
{
  fwrite(&chartInstance.c1_is_active_c1_object_tracker_with_block_match, 1,
   sizeof(chartInstance.
    c1_is_active_c1_object_tracker_with_block_match), c1_file);
  fwrite(&chartInstance.c1_startflag, 1, sizeof(chartInstance.c1_startflag),
   c1_file);
  fwrite(&chartInstance.c1_startflag_not_empty, 1,
   sizeof(chartInstance.c1_startflag_not_empty), c1_file);
  fwrite(&chartInstance.c1_brakecount, 1, sizeof(chartInstance.c1_brakecount),
   c1_file);
  fwrite(&chartInstance.c1_brakecount_not_empty, 1,
   sizeof(chartInstance.c1_brakecount_not_empty), c1_file);
  fwrite(&chartInstance.c1_movecount, 1, sizeof(chartInstance.c1_movecount),
   c1_file);
  fwrite(&chartInstance.c1_movecount_not_empty, 1,
   sizeof(chartInstance.c1_movecount_not_empty), c1_file);
}

static void sf_load_state_c1_object_tracker_with_block_match(FILE *c1_file)
{
  fread(&chartInstance.c1_is_active_c1_object_tracker_with_block_match, 1,
   sizeof(chartInstance.
    c1_is_active_c1_object_tracker_with_block_match), c1_file);
  fread(&chartInstance.c1_startflag, 1, sizeof(chartInstance.c1_startflag),
   c1_file);
  fread(&chartInstance.c1_startflag_not_empty, 1,
   sizeof(chartInstance.c1_startflag_not_empty), c1_file);
  fread(&chartInstance.c1_brakecount, 1, sizeof(chartInstance.c1_brakecount),
   c1_file);
  fread(&chartInstance.c1_brakecount_not_empty, 1,
   sizeof(chartInstance.c1_brakecount_not_empty), c1_file);
  fread(&chartInstance.c1_movecount, 1, sizeof(chartInstance.c1_movecount),
   c1_file);
  fread(&chartInstance.c1_movecount_not_empty, 1,
   sizeof(chartInstance.c1_movecount_not_empty), c1_file);
}

/* SFunction Glue Code */
void sf_c1_object_tracker_with_block_match_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3247839501U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(57279321U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(277665026U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4283788357U);
}

mxArray *sf_c1_object_tracker_with_block_match_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3059072684U);
    pr[1] = (double)(671039467U);
    pr[2] = (double)(1971152213U);
    pr[3] = (double)(1217469646U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S)
{
  if(ssIsFirstInitCond(S)) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_object_tracker_with_block_matchMachineNumber_,
         1,
         1,
         1,
         2,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting(_object_tracker_with_block_matchMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_object_tracker_with_block_matchMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"DirectionCode",0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,"BlobCount",0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,9,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1004);
        _SFD_CV_INIT_EML_IF(0,0,305,330,350,377);
        _SFD_CV_INIT_EML_IF(0,1,379,405,-1,429);
        _SFD_CV_INIT_EML_IF(0,2,431,457,-1,480);
        _SFD_CV_INIT_EML_IF(0,3,482,500,655,703);
        _SFD_CV_INIT_EML_IF(0,4,655,684,-1,703);
        _SFD_CV_INIT_EML_IF(0,5,710,756,-1,-2);
        _SFD_CV_INIT_EML_IF(0,6,767,790,830,958);
        _SFD_CV_INIT_EML_IF(0,7,830,857,892,958);
        _SFD_CV_INIT_EML_IF(0,8,892,918,-1,-2);
        {
          static int condStart[] = {715,741};
          static int condEnd[] = {737,755};
          static int pfixExpr[] = {0,1,-2};
          _SFD_CV_INIT_EML_MCDC(0,0,715,755,2,0,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(1U, c1_DirectionCode());
        _SFD_SET_DATA_VALUE_PTR(0U, c1_BlobCount());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_object_tracker_with_block_matchMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c1_object_tracker_with_block_match();
  initialize_c1_object_tracker_with_block_match();
}

static void sf_opaque_enable_c1_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  enable_c1_object_tracker_with_block_match();
}

static void sf_opaque_disable_c1_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  disable_c1_object_tracker_with_block_match();
}

static void sf_opaque_gateway_c1_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  sf_c1_object_tracker_with_block_match();
}

static void sf_opaque_terminate_c1_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  finalize_c1_object_tracker_with_block_match();
}

static void mdlProcessParameters_c1_object_tracker_with_block_match(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c1_object_tracker_with_block_match();
}

static void mdlSetWorkWidths_c1_object_tracker_with_block_match(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("object_tracker_with_block_match",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("object_tracker_with_block_match",1,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"object_tracker_with_block_match",1,2);
    }
    if
    (!sf_is_chart_instance_optimized_out("object_tracker_with_block_match",1)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("object_tracker_with_block_match",1);
      dtId = ssRegisterDataType(S, chartInstanceTypedefName);
      if (dtId == INVALID_DTYPE_ID ) return;
      /* Register the size of the udt */
      if (!ssSetDataTypeSize(S, dtId, 8)) return;
      if(!ssSetNumDWork(S,1)) return;
      ssSetDWorkDataType(S, 0, dtId);
      ssSetDWorkWidth(S, 0, 1);
      ssSetDWorkName(S, 0, "ChartInstance"); /*optional name, less than 16 chars*/
      sf_set_rtw_identifier(S);
    }
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3639508767U));
  ssSetChecksum1(S,(264376181U));
  ssSetChecksum2(S,(373266086U));
  ssSetChecksum3(S,(3482687277U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_object_tracker_with_block_match(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "object_tracker_with_block_match", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void
sf_save_debug_c1_object_tracker_with_block_match(SFc1_object_tracker_with_block_matchInstanceStruct*
 chartInstance, FILE* file)
{
  int machineNumber = _object_tracker_with_block_matchMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = sf_debug_get_state_vectors_data_size(machineNumber,
   chartNumber, instanceNumber);
  unsigned char* buffer = (unsigned char*) malloc(bufferSize);
  unsigned int chartActive = sf_debug_get_chart_active(machineNumber,
   chartNumber, instanceNumber);
  fwrite(&chartActive, sizeof(chartActive),1,file);
  sf_debug_get_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  fwrite(&bufferSize, sizeof(bufferSize), 1, file); /* Write number of bytes */
  fwrite(buffer, 1, bufferSize,file);   /* Write buffer */
  free(buffer);
}
static void
sf_load_debug_c1_object_tracker_with_block_match(SFc1_object_tracker_with_block_matchInstanceStruct*
 chartInstance,FILE* file)
{
  int machineNumber = _object_tracker_with_block_matchMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = 0;
  unsigned char* buffer = NULL;
  unsigned int chartActive = 0;
  fread(&chartActive, sizeof(chartActive),1,file);
  sf_debug_set_chart_active(machineNumber, chartNumber, instanceNumber,
   chartActive);
  fread(&bufferSize, sizeof(bufferSize), 1, file);
  buffer = (unsigned char*) malloc(bufferSize);
  fread(buffer, 1, bufferSize, file);
  sf_debug_set_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  free(buffer);
}
static void sf_c1_object_tracker_with_block_match_sim_ctx_io(SimStruct* S, const
 char io, FILE* file)
{
  if(io == 'r') {
    sf_load_state_c1_object_tracker_with_block_match(file);
    sf_load_debug_c1_object_tracker_with_block_match(&chartInstance, file);
  } else {
    sf_save_state_c1_object_tracker_with_block_match(file);
    sf_save_debug_c1_object_tracker_with_block_match(&chartInstance, file);
  }
}
static void mdlStart_c1_object_tracker_with_block_match(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_object_tracker_with_block_match;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S,
   sf_c1_object_tracker_with_block_match_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c1_object_tracker_with_block_match_method_dispatcher(SimStruct *S, int_T
 method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_object_tracker_with_block_match(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_object_tracker_with_block_match(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_object_tracker_with_block_match(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_object_tracker_with_block_match_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

