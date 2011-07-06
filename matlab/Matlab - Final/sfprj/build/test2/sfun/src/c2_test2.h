#ifndef __c2_test2_h__
#define __c2_test2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c2_is_active_c2_test2;
  ChartInfoStruct chartInfo;
} SFc2_test2InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c2_test2_get_check_sum(mxArray *plhs[]);
extern void c2_test2_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

