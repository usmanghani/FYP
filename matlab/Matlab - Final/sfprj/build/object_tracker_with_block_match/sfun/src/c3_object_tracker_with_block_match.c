/* Include files */
#include "object_tracker_with_block_match_sfun.h"
#include "c3_object_tracker_with_block_match.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "object_tracker_with_block_match_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc3_object_tracker_with_block_matchInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c3_object_tracker_with_block_match(void);
static void initialize_params_c3_object_tracker_with_block_match(void);
static void enable_c3_object_tracker_with_block_match(void);
static void disable_c3_object_tracker_with_block_match(void);
static void finalize_c3_object_tracker_with_block_match(void);
static void sf_c3_object_tracker_with_block_match(void);
static real_T *c3_CentroidCol(void);
static real_T *c3_StartCoords(void);
static real_T *c3_DirectionCode(void);
static int32_T *c3_BlobCount(void);
static void init_dsm_address_info(void);
static void sf_save_state_c3_object_tracker_with_block_match(FILE *c3_file);
static void sf_load_state_c3_object_tracker_with_block_match(FILE *c3_file);

/* Function Definitions */
static void initialize_c3_object_tracker_with_block_match(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c3_is_active_c3_object_tracker_with_block_match = 0U;
}

static void initialize_params_c3_object_tracker_with_block_match(void)
{
}

static void enable_c3_object_tracker_with_block_match(void)
{
}

static void disable_c3_object_tracker_with_block_match(void)
{
}

static void finalize_c3_object_tracker_with_block_match(void)
{
}

static void sf_c3_object_tracker_with_block_match(void)
{
  int32_T c3_em_i0;
  uint8_T c3_previousEvent;
  real_T c3_b_CentroidCol;
  int32_T c3_em_i1;
  real_T c3_b_StartCoords[2];
  int32_T c3_b_BlobCount;
  real_T c3_ScreenCenter;
  real_T c3_DIFFTHRESHOLD;
  real_T c3_STOP;
  real_T c3_RIGHT;
  real_T c3_LEFT;
  real_T c3_STRAIGHT;
  real_T c3_b_DirectionCode;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c3_CentroidCol(), 2U);
  for(c3_em_i0 = 0; c3_em_i0 < 2; c3_em_i0 = c3_em_i0 + 1) {
    _SFD_DATA_RANGE_CHECK(c3_StartCoords()[c3_em_i0], 3U);
  }
  _SFD_DATA_RANGE_CHECK(*c3_DirectionCode(), 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_BlobCount(), 1U);
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  c3_b_CentroidCol = *c3_CentroidCol();
  for(c3_em_i1 = 0; c3_em_i1 < 2; c3_em_i1 = c3_em_i1 + 1) {
    c3_b_StartCoords[c3_em_i1] = c3_StartCoords()[c3_em_i1];
  }
  c3_b_BlobCount = *c3_BlobCount();
  sf_debug_push_symbol_scope(10U, 0U);
  sf_debug_symbol_scope_add_symbol("ScreenCenter", 0, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c3_ScreenCenter, 0);
  sf_debug_symbol_scope_add_symbol("DIFFTHRESHOLD", 0, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c3_DIFFTHRESHOLD, 0);
  sf_debug_symbol_scope_add_symbol("STOP", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c3_STOP, 0);
  sf_debug_symbol_scope_add_symbol("RIGHT", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c3_RIGHT, 0);
  sf_debug_symbol_scope_add_symbol("LEFT", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 0, &c3_LEFT, 0);
  sf_debug_symbol_scope_add_symbol("STRAIGHT", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c3_STRAIGHT, 0);
  sf_debug_symbol_scope_add_symbol("DirectionCode", 0, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c3_b_DirectionCode, 0);
  sf_debug_symbol_scope_add_symbol("BlobCount", 6, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c3_b_BlobCount, 0);
  sf_debug_symbol_scope_add_symbol("StartCoords", 0, 1U, 2U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 1, &c3_b_StartCoords, 0);
  sf_debug_symbol_scope_add_symbol("CentroidCol", 0, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c3_b_CentroidCol, 0);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,3);
  c3_STRAIGHT = 1.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c3_LEFT = 2.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  c3_RIGHT = 3.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c3_STOP = 4.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
  c3_DIFFTHRESHOLD = 20.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
  c3_ScreenCenter = c3_b_StartCoords[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  if(CV_EML_IF(0, 0, (real_T)c3_b_BlobCount == 0.0)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
    c3_b_DirectionCode = c3_STOP;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
    if(CV_EML_IF(0, 1, c3_b_CentroidCol < c3_ScreenCenter - c3_DIFFTHRESHOLD)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
      c3_b_DirectionCode = c3_LEFT;
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
      if(CV_EML_IF(0, 2, c3_b_CentroidCol > c3_ScreenCenter + c3_DIFFTHRESHOLD))
      {
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
        c3_b_DirectionCode = c3_RIGHT;
      } else {
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
        c3_b_DirectionCode = c3_STRAIGHT;
      }
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-18);
  sf_debug_pop_symbol_scope();
  *c3_DirectionCode() = c3_b_DirectionCode;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_object_tracker_with_block_matchMachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static real_T *c3_CentroidCol(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c3_StartCoords(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c3_DirectionCode(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static int32_T *c3_BlobCount(void)
{
  return (int32_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c3_object_tracker_with_block_match(FILE *c3_file)
{
  fwrite(&chartInstance.c3_is_active_c3_object_tracker_with_block_match, 1,
   sizeof(chartInstance.
    c3_is_active_c3_object_tracker_with_block_match), c3_file);
}

static void sf_load_state_c3_object_tracker_with_block_match(FILE *c3_file)
{
  fread(&chartInstance.c3_is_active_c3_object_tracker_with_block_match, 1,
   sizeof(chartInstance.
    c3_is_active_c3_object_tracker_with_block_match), c3_file);
}

/* SFunction Glue Code */
void sf_c3_object_tracker_with_block_match_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3636088381U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1964474506U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3217454801U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3320097623U);
}

mxArray *sf_c3_object_tracker_with_block_match_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2271125333U);
    pr[1] = (double)(1295485013U);
    pr[2] = (double)(3727338554U);
    pr[3] = (double)(3350600569U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
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
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(6));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
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
         3,
         1,
         1,
         4,
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

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"CentroidCol",0);
          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"StartCoords",0);
          }
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"DirectionCode",0);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,"BlobCount",0);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,421);
        _SFD_CV_INIT_EML_IF(0,0,175,193,219,410);
        _SFD_CV_INIT_EML_IF(0,1,219,269,295,410);
        _SFD_CV_INIT_EML_IF(0,2,295,345,372,410);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(2U, c3_CentroidCol());
        _SFD_SET_DATA_VALUE_PTR(3U, c3_StartCoords());
        _SFD_SET_DATA_VALUE_PTR(0U, c3_DirectionCode());
        _SFD_SET_DATA_VALUE_PTR(1U, c3_BlobCount());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_object_tracker_with_block_matchMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c3_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c3_object_tracker_with_block_match();
  initialize_c3_object_tracker_with_block_match();
}

static void sf_opaque_enable_c3_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  enable_c3_object_tracker_with_block_match();
}

static void sf_opaque_disable_c3_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  disable_c3_object_tracker_with_block_match();
}

static void sf_opaque_gateway_c3_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  sf_c3_object_tracker_with_block_match();
}

static void sf_opaque_terminate_c3_object_tracker_with_block_match(void
 *chartInstanceVar)
{
  finalize_c3_object_tracker_with_block_match();
}

static void mdlProcessParameters_c3_object_tracker_with_block_match(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c3_object_tracker_with_block_match();
}

static void mdlSetWorkWidths_c3_object_tracker_with_block_match(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("object_tracker_with_block_match",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("object_tracker_with_block_match",3,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"object_tracker_with_block_match",3,3);
      sf_mark_chart_reusable_outputs(S,"object_tracker_with_block_match",3,1);
    }
    if
    (!sf_is_chart_instance_optimized_out("object_tracker_with_block_match",3)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("object_tracker_with_block_match",3);
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

  ssSetChecksum0(S,(3799158563U));
  ssSetChecksum1(S,(2414731018U));
  ssSetChecksum2(S,(3293601605U));
  ssSetChecksum3(S,(3955538007U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_object_tracker_with_block_match(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "object_tracker_with_block_match", 3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void
sf_save_debug_c3_object_tracker_with_block_match(SFc3_object_tracker_with_block_matchInstanceStruct*
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
sf_load_debug_c3_object_tracker_with_block_match(SFc3_object_tracker_with_block_matchInstanceStruct*
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
static void sf_c3_object_tracker_with_block_match_sim_ctx_io(SimStruct* S, const
 char io, FILE* file)
{
  if(io == 'r') {
    sf_load_state_c3_object_tracker_with_block_match(file);
    sf_load_debug_c3_object_tracker_with_block_match(&chartInstance, file);
  } else {
    sf_save_state_c3_object_tracker_with_block_match(file);
    sf_save_debug_c3_object_tracker_with_block_match(&chartInstance, file);
  }
}
static void mdlStart_c3_object_tracker_with_block_match(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.mdlStart = mdlStart_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_object_tracker_with_block_match;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S,
   sf_c3_object_tracker_with_block_match_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c3_object_tracker_with_block_match_method_dispatcher(SimStruct *S, int_T
 method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_object_tracker_with_block_match(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_object_tracker_with_block_match(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_object_tracker_with_block_match(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c3_object_tracker_with_block_match_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

