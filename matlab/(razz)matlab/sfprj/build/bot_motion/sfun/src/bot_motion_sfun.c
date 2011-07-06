/* Include files */
#include "bot_motion_sfun.h"
#include "c1_bot_motion.h"
#include "c2_bot_motion.h"
#include "c3_bot_motion.h"
#include "c4_bot_motion.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _bot_motionMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void bot_motion_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void bot_motion_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_bot_motion_method_dispatcher(SimStruct *simstructPtr, const char
 *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"bot_motion/Embedded MATLAB Function1/ SFunction "))
  {
    c1_bot_motion_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"bot_motion/Embedded MATLAB Function/ SFunction "))
  {
    c2_bot_motion_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"bot_motion/Embedded MATLAB Function2/ SFunction "))
  {
    c3_bot_motion_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"bot_motion/Embedded MATLAB Function3/ SFunction "))
  {
    c4_bot_motion_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_bot_motion_process_check_sum_call( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3868294915U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4077229251U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(348433699U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1882370424U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4014023674U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1826995535U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2855217581U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3880147522U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 1:
        {
          extern void sf_c1_bot_motion_get_check_sum(mxArray *plhs[]);
          sf_c1_bot_motion_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_bot_motion_get_check_sum(mxArray *plhs[]);
          sf_c2_bot_motion_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_bot_motion_get_check_sum(mxArray *plhs[]);
          sf_c3_bot_motion_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_bot_motion_get_check_sum(mxArray *plhs[]);
          sf_c4_bot_motion_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1754806362U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1973214305U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1659388014U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2148097642U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4105747326U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2914560426U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(155371523U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3539950827U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_bot_motion_autoinheritance_info( int nlhs, mxArray * plhs[], int
 nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_bot_motion_get_autoinheritance_info(void);
        plhs[0] = sf_c1_bot_motion_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_bot_motion_get_autoinheritance_info(void);
        plhs[0] = sf_c2_bot_motion_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_bot_motion_get_autoinheritance_info(void);
        plhs[0] = sf_c3_bot_motion_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_bot_motion_get_autoinheritance_info(void);
        plhs[0] = sf_c4_bot_motion_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void bot_motion_debug_initialize(void)
{
  _bot_motionMachineNumber_ =
  sf_debug_initialize_machine("bot_motion","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(_bot_motionMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_bot_motionMachineNumber_,0);
}

void bot_motion_register_exported_symbols(SimStruct* S)
{
}
