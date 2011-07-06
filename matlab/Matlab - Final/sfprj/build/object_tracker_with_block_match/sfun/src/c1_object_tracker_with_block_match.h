#ifndef __c1_object_tracker_with_block_match_h__
#define __c1_object_tracker_with_block_match_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  real_T c1_brakecount;
  real_T c1_movecount;
  real_T c1_startflag;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_brakecount_not_empty;
  boolean_T c1_movecount_not_empty;
  boolean_T c1_startflag_not_empty;
  uint8_T c1_is_active_c1_object_tracker_with_block_match;
  ChartInfoStruct chartInfo;
} SFc1_object_tracker_with_block_matchInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c1_object_tracker_with_block_match_get_check_sum(mxArray *plhs[]);
extern void c1_object_tracker_with_block_match_method_dispatcher(SimStruct *S,
 int_T method, void *data);

#endif

