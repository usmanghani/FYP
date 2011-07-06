/* Include files */
#include "test2_sfun.h"
#include "c2_test2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _test2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void test2_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void test2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_test2_method_dispatcher(SimStruct *simstructPtr, const char
 *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"test2/Embedded MATLAB Function/ SFunction ")) {
    c2_test2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_test2_process_check_sum_call( int nlhs, mxArray * plhs[], int
 nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(777598333U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1964941220U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3922543537U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(76793577U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(170345085U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4083563725U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2720482814U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2588563919U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 2:
        {
          extern void sf_c2_test2_get_check_sum(mxArray *plhs[]);
          sf_c2_test2_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2981326882U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2057084731U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(854439120U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(901613029U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_test2_autoinheritance_info( int nlhs, mxArray * plhs[], int
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
     case 2:
      {
        extern mxArray *sf_c2_test2_get_autoinheritance_info(void);
        plhs[0] = sf_c2_test2_get_autoinheritance_info();
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
void test2_debug_initialize(void)
{
  _test2MachineNumber_ = sf_debug_initialize_machine("test2","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_test2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_test2MachineNumber_,0);
}

void test2_register_exported_symbols(SimStruct* S)
{
}
