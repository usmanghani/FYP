#ifndef __c2_object_tracker_without_centroid_h__
#define __c2_object_tracker_without_centroid_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  real_T c2_LastCentroid[2];
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_LastCentroid_not_empty;
  uint8_T c2_is_active_c2_object_tracker_without_centroid;
  ChartInfoStruct chartInfo;
} SFc2_object_tracker_without_centroidInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c2_object_tracker_without_centroid_get_check_sum(mxArray *plhs[]);
extern void c2_object_tracker_without_centroid_method_dispatcher(SimStruct *S,
 int_T method, void *data);

#endif

