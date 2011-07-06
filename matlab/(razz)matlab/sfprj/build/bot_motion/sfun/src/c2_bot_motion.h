#ifndef __c2_bot_motion_h__
#define __c2_bot_motion_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c2_is_active_c2_bot_motion;
  ChartInfoStruct chartInfo;
} SFc2_bot_motionInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c2_bot_motion_get_check_sum(mxArray *plhs[]);
extern void c2_bot_motion_method_dispatcher(SimStruct *S, int_T method, void
 *data);

#endif

