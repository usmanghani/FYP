#ifndef __c2_object_tracker_intensity_h__
#define __c2_object_tracker_intensity_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint16_T c2_LastCentroid[2];
  boolean_T c2_LastCentroid_not_empty;
  uint8_T c2_is_active_c2_object_tracker_intensity;
  ChartInfoStruct chartInfo;
} SFc2_object_tracker_intensityInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c2_object_tracker_intensity_get_check_sum(mxArray *plhs[]);
extern void c2_object_tracker_intensity_method_dispatcher(SimStruct *S, int_T
 method, void *data);

#endif

