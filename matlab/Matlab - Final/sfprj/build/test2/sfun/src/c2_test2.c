/* Include files */
#include "test2_sfun.h"
#include "c2_test2.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "test2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_test2InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_test2(void);
static void initialize_params_c2_test2(void);
static void enable_c2_test2(void);
static void disable_c2_test2(void);
static void finalize_c2_test2(void);
static void sf_c2_test2(void);
static uint8_T *c2_u(void);
static void init_dsm_address_info(void);
static void sf_save_state_c2_test2(FILE *c2_file);
static void sf_load_state_c2_test2(FILE *c2_file);

/* Function Definitions */
static void initialize_c2_test2(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_test2 = 0U;
}

static void initialize_params_c2_test2(void)
{
}

static void enable_c2_test2(void)
{
}

static void disable_c2_test2(void)
{
}

static void finalize_c2_test2(void)
{
}

static void sf_c2_test2(void)
{
  int32_T c2_em_i0;
  int32_T c2_em_i1;
  uint8_T c2_previousEvent;
  int32_T c2_em_i2;
  int32_T c2_em_i3;
  static uint8_T c2_b_u[768][576];
  int32_T c2_em_i4;
  static real_T c2_em_dv0[2][1] = { { 576.0 }, { 768.0 } };
  real_T c2_em_dv1[2][1];
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c2_em_i0 = 0; c2_em_i0 < 768; c2_em_i0 = c2_em_i0 + 1) {
    for(c2_em_i1 = 0; c2_em_i1 < 576; c2_em_i1 = c2_em_i1 + 1) {
      _SFD_DATA_RANGE_CHECK((real_T)c2_u()[576 * c2_em_i0 + c2_em_i1], 0U);
    }
  }
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for(c2_em_i2 = 0; c2_em_i2 < 768; c2_em_i2 = c2_em_i2 + 1) {
    for(c2_em_i3 = 0; c2_em_i3 < 576; c2_em_i3 = c2_em_i3 + 1) {
      c2_b_u[c2_em_i2][c2_em_i3] = c2_u()[576 * c2_em_i2 + c2_em_i3];
    }
  }
  sf_debug_push_symbol_scope(1U, 0U);
  sf_debug_symbol_scope_add_symbol("u", 3, 2U, 576U, 768U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 1, &c2_b_u, 0);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,3);
  for(c2_em_i4 = 0; c2_em_i4 < 2; c2_em_i4 = c2_em_i4 + 1) {
    c2_em_dv1[c2_em_i4][0] = c2_em_dv0[c2_em_i4][0];
  }
  sf_mex_printf("%s =\\n", "size ( u )");
  sf_mex_call("disp", 0U, 1U, 14, sf_mex_create(&c2_em_dv1, "disp", 0, 0U, 1U,
    2, 1, 2));
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-3);
  sf_debug_pop_symbol_scope();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_test2MachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static uint8_T *c2_u(void)
{
  return (uint8_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c2_test2(FILE *c2_file)
{
  fwrite(&chartInstance.c2_is_active_c2_test2, 1,
   sizeof(chartInstance.c2_is_active_c2_test2), c2_file);
}

static void sf_load_state_c2_test2(FILE *c2_file)
{
  fread(&chartInstance.c2_is_active_c2_test2, 1,
   sizeof(chartInstance.c2_is_active_c2_test2), c2_file);
}

/* SFunction Glue Code */
void sf_c2_test2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1847427923U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2360785953U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1778914483U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(124993828U);
}

mxArray *sf_c2_test2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(791415253U);
    pr[1] = (double)(3320173724U);
    pr[2] = (double)(1284951833U);
    pr[3] = (double)(1814213215U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(576);
      pr[1] = (double)(768);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
        chartAlreadyPresent = sf_debug_initialize_chart(_test2MachineNumber_,
         2,
         1,
         1,
         1,
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
          sf_debug_set_chart_disable_implicit_casting(_test2MachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_test2MachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          {
            unsigned int dimVector[2];
            dimVector[0]= 576;
            dimVector[1]= 768;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"u",0);
          }
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,28);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(0U, c2_u());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_test2MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_test2(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c2_test2();
  initialize_c2_test2();
}

static void sf_opaque_enable_c2_test2(void *chartInstanceVar)
{
  enable_c2_test2();
}

static void sf_opaque_disable_c2_test2(void *chartInstanceVar)
{
  disable_c2_test2();
}

static void sf_opaque_gateway_c2_test2(void *chartInstanceVar)
{
  sf_c2_test2();
}

static void sf_opaque_terminate_c2_test2(void *chartInstanceVar)
{
  finalize_c2_test2();
}

static void mdlProcessParameters_c2_test2(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c2_test2();
}

static void mdlSetWorkWidths_c2_test2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("test2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("test2",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"test2",2,1);
    }
    if (!sf_is_chart_instance_optimized_out("test2",2)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("test2",2);
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

  ssSetChecksum0(S,(153725017U));
  ssSetChecksum1(S,(4003523905U));
  ssSetChecksum2(S,(4059357020U));
  ssSetChecksum3(S,(3842797332U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_test2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "test2", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void sf_save_debug_c2_test2(SFc2_test2InstanceStruct* chartInstance,
 FILE* file)
{
  int machineNumber = _test2MachineNumber_;
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
static void sf_load_debug_c2_test2(SFc2_test2InstanceStruct* chartInstance,FILE*
 file)
{
  int machineNumber = _test2MachineNumber_;
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
static void sf_c2_test2_sim_ctx_io(SimStruct* S, const char io, FILE* file)
{
  if(io == 'r') {
    sf_load_state_c2_test2(file);
    sf_load_debug_c2_test2(&chartInstance, file);
  } else {
    sf_save_state_c2_test2(file);
    sf_save_debug_c2_test2(&chartInstance, file);
  }
}
static void mdlStart_c2_test2(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_test2;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_test2;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_test2;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_test2;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_test2;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_test2;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_test2;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_test2;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S, sf_c2_test2_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c2_test2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_test2(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_test2(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_test2(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_test2_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

