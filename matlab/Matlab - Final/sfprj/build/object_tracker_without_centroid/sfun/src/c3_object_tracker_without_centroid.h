#ifndef __c3_object_tracker_without_centroid_h__
#define __c3_object_tracker_without_centroid_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c3_is_active_c3_object_tracker_without_centroid;
  ChartInfoStruct chartInfo;
} SFc3_object_tracker_without_centroidInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c3_object_tracker_without_centroid_get_check_sum(mxArray *plhs[]);
extern void c3_object_tracker_without_centroid_method_dispatcher(SimStruct *S,
 int_T method, void *data);

#endif

