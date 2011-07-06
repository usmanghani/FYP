/* Include files */
#include "object_tracker_intensity_sfun.h"
#include "c1_object_tracker_intensity.h"
#include "c2_object_tracker_intensity.h"
#include "c3_object_tracker_intensity.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _object_tracker_intensityMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void object_tracker_intensity_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void object_tracker_intensity_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_object_tracker_intensity_method_dispatcher(SimStruct
 *simstructPtr, const char *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"object_tracker_intensity/Display Results/Display bounding boxes/NavigationLogic/Embedded MATLAB Function1/ SFunction "))
  {
    c1_object_tracker_intensity_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"object_tracker_intensity/Display Results/Display bounding boxes/Embedded MATLAB Function/ SFunction "))
  {
    c2_object_tracker_intensity_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(!strcmp_ignore_ws(chartName,"object_tracker_intensity/Display Results/Display bounding boxes/NavigationLogic/Embedded MATLAB Function2/ SFunction "))
  {
    c3_object_tracker_intensity_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_object_tracker_intensity_process_check_sum_call( int nlhs,
 mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2492229368U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2395636050U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3680112938U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(890457581U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2073872283U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(626813698U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(215696993U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2233395692U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 1:
        {
          extern void sf_c1_object_tracker_intensity_get_check_sum(mxArray
           *plhs[]);
          sf_c1_object_tracker_intensity_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_object_tracker_intensity_get_check_sum(mxArray
           *plhs[]);
          sf_c2_object_tracker_intensity_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_object_tracker_intensity_get_check_sum(mxArray
           *plhs[]);
          sf_c3_object_tracker_intensity_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3989761619U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(658148739U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(632200876U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(57891142U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_object_tracker_intensity_autoinheritance_info( int nlhs, mxArray
 * plhs[], int nrhs, const mxArray * prhs[] )
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
        extern mxArray
        *sf_c1_object_tracker_intensity_get_autoinheritance_info(void);
        plhs[0] = sf_c1_object_tracker_intensity_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray
        *sf_c2_object_tracker_intensity_get_autoinheritance_info(void);
        plhs[0] = sf_c2_object_tracker_intensity_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray
        *sf_c3_object_tracker_intensity_get_autoinheritance_info(void);
        plhs[0] = sf_c3_object_tracker_intensity_get_autoinheritance_info();
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
void object_tracker_intensity_debug_initialize(void)
{
  _object_tracker_intensityMachineNumber_ =
    sf_debug_initialize_machine("object_tracker_intensity","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(_object_tracker_intensityMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_object_tracker_intensityMachineNumber_,0);
}

void object_tracker_intensity_register_exported_symbols(SimStruct* S)
{
}
