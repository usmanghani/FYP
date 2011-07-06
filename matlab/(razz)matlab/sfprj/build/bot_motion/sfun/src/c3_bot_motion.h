#ifndef __c3_bot_motion_h__
#define __c3_bot_motion_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c3_is_active_c3_bot_motion;
  ChartInfoStruct chartInfo;
} SFc3_bot_motionInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c3_bot_motion_get_check_sum(mxArray *plhs[]);
extern void c3_bot_motion_method_dispatcher(SimStruct *S, int_T method, void
 *data);

#endif

