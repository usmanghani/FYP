/* Include files */
#include "object_tracker_without_centroid_sfun.h"
#include "c2_object_tracker_without_centroid.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "object_tracker_without_centroid_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_object_tracker_without_centroidInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_object_tracker_without_centroid(void);
static void initialize_params_c2_object_tracker_without_centroid(void);
static void enable_c2_object_tracker_without_centroid(void);
static void disable_c2_object_tracker_without_centroid(void);
static void finalize_c2_object_tracker_without_centroid(void);
static void sf_c2_object_tracker_without_centroid(void);
static void c2_power(real_T *c2_a, real_T c2_b, real_T *c2_y);
static real_T *c2_CentroidCoords(void);
static real_T *c2_CentroidArray(void);
static real_T *c2_LineVector(void);
static real_T *c2_booleof(void);
static real_T *c2_StartCoords(void);
static real_T *c2_VidSize(void);
static real_T *c2_CentroidCol(void);
static void init_dsm_address_info(void);
static void sf_save_state_c2_object_tracker_without_centroid(FILE *c2_file);
static void sf_load_state_c2_object_tracker_without_centroid(FILE *c2_file);

/* Function Definitions */
static void initialize_c2_object_tracker_without_centroid(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_LastCentroid_not_empty = false;
  chartInstance.c2_is_active_c2_object_tracker_without_centroid = 0U;
}

static void initialize_params_c2_object_tracker_without_centroid(void)
{
}

static void enable_c2_object_tracker_without_centroid(void)
{
}

static void disable_c2_object_tracker_without_centroid(void)
{
}

static void finalize_c2_object_tracker_without_centroid(void)
{
}

static void sf_c2_object_tracker_without_centroid(void)
{
  int32_T c2_em_i0;
  int32_T c2_em_i1;
  int32_T c2_em_i2;
  int32_T c2_em_i3;
  int32_T c2_em_i4;
  int32_T c2_em_i5;
  uint8_T c2_previousEvent;
  int32_T c2_em_i6;
  int32_T c2_em_i7;
  real_T c2_b_CentroidArray[10][2];
  real_T c2_b_booleof;
  int32_T c2_em_i8;
  real_T c2_b_StartCoords[2];
  real_T c2_b_VidSize[2];
  real_T c2_centroid[2];
  real_T c2_i;
  real_T c2_m;
  real_T c2_myvector[10][1];
  real_T c2_ally[10][1];
  real_T c2_allx[10][1];
  real_T c2_z[2];
  real_T c2_b_CentroidCol;
  real_T c2_b_LineVector[4][1];
  real_T c2_b_CentroidCoords[2];
  boolean_T c2_r;
  int32_T c2_em_i9;
  int32_T c2_em_i10;
  int32_T c2_em_i11;
  real_T c2_c_CentroidArray[10][1];
  real_T c2_b_z;
  int32_T c2_em_i12;
  int32_T c2_em_i13;
  real_T c2_d_CentroidArray[10][1];
  real_T c2_c_z;
  int32_T c2_em_i14;
  int32_T c2_em_i15;
  real_T c2_b_allx[10][1];
  real_T c2_em_dv0[10][1];
  int32_T c2_em_i16;
  real_T c2_b_ally[10][1];
  real_T c2_em_dv1[10][1];
  int32_T c2_em_i17;
  real_T c2_x[10][1];
  real_T c2_y[10][1];
  int32_T c2_em_i18;
  real_T c2_b_x[10][1];
  real_T c2_c_x[10][1];
  real_T c2_jstart;
  real_T c2_minval;
  real_T c2_indx;
  real_T c2_j1;
  real_T c2_b_j1;
  real_T c2_a;
  real_T c2_b;
  real_T c2_d_x;
  boolean_T c2_b_b;
  real_T c2_e_x;
  boolean_T c2_c_b;
  boolean_T c2_em_b0;
  boolean_T c2_p;
  real_T c2_b_minval;
  real_T c2_b_indx;
  int32_T c2_em_i19;
  static int32_T c2_em_iv0[2][1] = { { 0 }, { 1 } };
  int32_T c2_em_i20;
  int32_T c2_em_i21;
  int32_T c2_em_i22;
  real_T c2_A;
  real_T c2_B;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_d_z;
  real_T c2_c_y;
  int32_T c2_em_i23;
  int32_T c2_em_i24;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c2_em_i0 = 0; c2_em_i0 < 2; c2_em_i0 = c2_em_i0 + 1) {
    _SFD_DATA_RANGE_CHECK(c2_CentroidCoords()[c2_em_i0], 0U);
  }
  for(c2_em_i1 = 0; c2_em_i1 < 10; c2_em_i1 = c2_em_i1 + 1) {
    for(c2_em_i2 = 0; c2_em_i2 < 2; c2_em_i2 = c2_em_i2 + 1) {
      _SFD_DATA_RANGE_CHECK(c2_CentroidArray()[(c2_em_i1 << 1) + c2_em_i2], 4U);
    }
  }
  for(c2_em_i3 = 0; c2_em_i3 < 4; c2_em_i3 = c2_em_i3 + 1) {
    _SFD_DATA_RANGE_CHECK(c2_LineVector()[c2_em_i3], 1U);
  }
  _SFD_DATA_RANGE_CHECK(*c2_booleof(), 2U);
  for(c2_em_i4 = 0; c2_em_i4 < 2; c2_em_i4 = c2_em_i4 + 1) {
    _SFD_DATA_RANGE_CHECK(c2_StartCoords()[c2_em_i4], 3U);
  }
  for(c2_em_i5 = 0; c2_em_i5 < 2; c2_em_i5 = c2_em_i5 + 1) {
    _SFD_DATA_RANGE_CHECK(c2_VidSize()[c2_em_i5], 6U);
  }
  _SFD_DATA_RANGE_CHECK(*c2_CentroidCol(), 5U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for(c2_em_i6 = 0; c2_em_i6 < 10; c2_em_i6 = c2_em_i6 + 1) {
    for(c2_em_i7 = 0; c2_em_i7 < 2; c2_em_i7 = c2_em_i7 + 1) {
      c2_b_CentroidArray[c2_em_i6][c2_em_i7] = c2_CentroidArray()[(c2_em_i6 <<
        1) + c2_em_i7];
    }
  }
  c2_b_booleof = *c2_booleof();
  for(c2_em_i8 = 0; c2_em_i8 < 2; c2_em_i8 = c2_em_i8 + 1) {
    c2_b_StartCoords[c2_em_i8] = c2_StartCoords()[c2_em_i8];
    c2_b_VidSize[c2_em_i8] = c2_VidSize()[c2_em_i8];
  }
  sf_debug_push_symbol_scope(15U, 0U);
  sf_debug_symbol_scope_add_symbol("LastCentroid", 0, 1U, 2U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 1, &chartInstance.c2_LastCentroid, 0);
  sf_debug_symbol_scope_add_symbol("centroid", 0, 1U, 2U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 1, &c2_centroid, 0);
  sf_debug_symbol_scope_add_symbol("i", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_i, 0);
  sf_debug_symbol_scope_add_symbol("m", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 0, &c2_m, 0);
  sf_debug_symbol_scope_add_symbol("myvector", 0, 2U, 1U, 10U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 1, &c2_myvector, 0);
  sf_debug_symbol_scope_add_symbol("ally", 0, 2U, 1U, 10U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 1, &c2_ally, 0);
  sf_debug_symbol_scope_add_symbol("allx", 0, 2U, 1U, 10U, 0U, 1.0, 0, 0.0, 0U,
   0, 0U, 1, &c2_allx, 0);
  sf_debug_symbol_scope_add_symbol("z", 0, 1U, 2U, 0U, 0U, 1.0, 0, 0.0, 0U, 0,
   0U, 1, &c2_z, 0);
  sf_debug_symbol_scope_add_symbol("CentroidCol", 0, 0U, 0U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 0, &c2_b_CentroidCol, 0);
  sf_debug_symbol_scope_add_symbol("LineVector", 0, 2U, 1U, 4U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 1, &c2_b_LineVector, 0);
  sf_debug_symbol_scope_add_symbol("CentroidCoords", 0, 1U, 2U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 1, &c2_b_CentroidCoords, 0);
  sf_debug_symbol_scope_add_symbol("VidSize", 0, 1U, 2U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 1, &c2_b_VidSize, 0);
  sf_debug_symbol_scope_add_symbol("StartCoords", 0, 1U, 2U, 0U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 1, &c2_b_StartCoords, 0);
  sf_debug_symbol_scope_add_symbol("booleof", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
   0U, 0, 0U, 0, &c2_b_booleof, 0);
  sf_debug_symbol_scope_add_symbol("CentroidArray", 0, 2U, 2U, 10U, 0U, 1.0, 0,
   0.0, 0U, 0, 0U, 1, &c2_b_CentroidArray, 0);
  CV_EML_FCN(0, 0);
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  if(CV_EML_COND(0, 0, !chartInstance.c2_LastCentroid_not_empty)) {
  } else {
    c2_r = true;
    if(CV_EML_COND(0, 1, c2_b_booleof == (real_T)c2_r)) {
    } else {
      CV_EML_MCDC(0, 0, false);
      CV_EML_IF(0, 0, false);
      goto label_1;
    }
  }
  CV_EML_MCDC(0, 0, true);
  CV_EML_IF(0, 0, true);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  for(c2_em_i9 = 0; c2_em_i9 < 2; c2_em_i9 = c2_em_i9 + 1) {
    chartInstance.c2_LastCentroid[c2_em_i9] = c2_b_StartCoords[c2_em_i9];
  }
  chartInstance.c2_LastCentroid_not_empty = true;
  label_1:;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  for(c2_em_i10 = 0; c2_em_i10 < 2; c2_em_i10 = c2_em_i10 + 1) {
    c2_z[c2_em_i10] = chartInstance.c2_LastCentroid[c2_em_i10];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
  for(c2_em_i11 = 0; c2_em_i11 < 10; c2_em_i11 = c2_em_i11 + 1) {
    c2_c_CentroidArray[c2_em_i11][0] = c2_b_CentroidArray[c2_em_i11][0];
  }
  c2_b_z = c2_z[0];
  for(c2_em_i12 = 0; c2_em_i12 < 10; c2_em_i12 = c2_em_i12 + 1) {
    c2_allx[c2_em_i12][0] = c2_c_CentroidArray[c2_em_i12][0] - c2_b_z;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
  for(c2_em_i13 = 0; c2_em_i13 < 10; c2_em_i13 = c2_em_i13 + 1) {
    c2_d_CentroidArray[c2_em_i13][0] = c2_b_CentroidArray[c2_em_i13][1];
  }
  c2_c_z = c2_z[1];
  for(c2_em_i14 = 0; c2_em_i14 < 10; c2_em_i14 = c2_em_i14 + 1) {
    c2_ally[c2_em_i14][0] = c2_d_CentroidArray[c2_em_i14][0] - c2_c_z;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
  for(c2_em_i15 = 0; c2_em_i15 < 10; c2_em_i15 = c2_em_i15 + 1) {
    c2_b_allx[c2_em_i15][0] = c2_allx[c2_em_i15][0];
  }
  c2_power((real_T *)c2_b_allx, 2.0, (real_T *)c2_em_dv0);
  for(c2_em_i16 = 0; c2_em_i16 < 10; c2_em_i16 = c2_em_i16 + 1) {
    c2_b_ally[c2_em_i16][0] = c2_ally[c2_em_i16][0];
  }
  c2_power((real_T *)c2_b_ally, 2.0, (real_T *)c2_em_dv1);
  for(c2_em_i17 = 0; c2_em_i17 < 10; c2_em_i17 = c2_em_i17 + 1) {
    c2_x[c2_em_i17][0] = c2_em_dv0[c2_em_i17][0] + c2_em_dv1[c2_em_i17][0];
  }
  for(c2_em_i17 = 0; c2_em_i17 < 10; c2_em_i17 = c2_em_i17 + 1) {
    c2_y[c2_em_i17][0] = sqrt(c2_x[c2_em_i17][0]);
    c2_myvector[c2_em_i17][0] = c2_y[c2_em_i17][0];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
  for(c2_em_i18 = 0; c2_em_i18 < 10; c2_em_i18 = c2_em_i18 + 1) {
    c2_b_x[c2_em_i18][0] = c2_myvector[c2_em_i18][0];
    c2_c_x[c2_em_i18][0] = c2_b_x[c2_em_i18][0];
  }
  c2_jstart = 1.0;
  c2_minval = (*(real_T (*)[10])&c2_c_x)[0];
  c2_indx = c2_jstart;
  c2_j1 = 2.0;
  while(c2_j1 <= 10.0) {
    c2_b_j1 = c2_j1;
    c2_a = (*(real_T (*)[10])&c2_c_x)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
     (int32_T)_SFD_INTEGER_CHECK("j1", c2_b_j1), 1, 10, 1) -
    1];
    c2_b = c2_minval;
    c2_d_x = c2_a;
    c2_b_b = rtIsNaN(c2_d_x);
    if(!c2_b_b) {
      c2_e_x = c2_b;
      c2_c_b = rtIsNaN(c2_e_x);
      if(c2_c_b || (c2_a < c2_b)) {
        c2_em_b0 = true;
        goto label_2;
      }
    }
    c2_em_b0 = false;
    label_2:;
    c2_p = c2_em_b0;
    if(c2_p) {
      c2_minval = (*(real_T
        (*)[10])&c2_c_x)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
       (int32_T)_SFD_INTEGER_CHECK("j1", c2_b_j1), 1, 10,
       1) - 1];
      c2_indx = c2_b_j1;
    }
    c2_j1 = c2_j1 + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }
  c2_b_minval = c2_minval;
  c2_b_indx = c2_indx;
  c2_m = c2_b_minval;
  c2_i = c2_b_indx;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
  for(c2_em_i19 = 0; c2_em_i19 < 2; c2_em_i19 = c2_em_i19 + 1) {
    c2_centroid[c2_em_i19] =
      c2_b_CentroidArray[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("CentroidArray",
     (int32_T)_SFD_INTEGER_CHECK("i",
      c2_i), 1, 10, 2) - 1][c2_em_iv0[c2_em_i19][0]];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
  if(CV_EML_COND(0, 2, (*(real_T
      (*)[10])&c2_myvector)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("myvector",
     (int32_T)_SFD_INTEGER_CHECK(
      "i", c2_i), 1, 10, 1) - 1] < 100.0) && CV_EML_COND(0, 3, c2_centroid[0] >
    0.0) && CV_EML_COND(0, 4, c2_centroid[1] > 10.0)) {
    CV_EML_MCDC(0, 1, true);
    CV_EML_IF(0, 1, true);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
    for(c2_em_i20 = 0; c2_em_i20 < 2; c2_em_i20 = c2_em_i20 + 1) {
      chartInstance.c2_LastCentroid[c2_em_i20] = c2_centroid[c2_em_i20];
    }
    chartInstance.c2_LastCentroid_not_empty = true;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    for(c2_em_i21 = 0; c2_em_i21 < 2; c2_em_i21 = c2_em_i21 + 1) {
      c2_b_CentroidCoords[c2_em_i21] = c2_centroid[c2_em_i21];
    }
  } else {
    CV_EML_MCDC(0, 1, false);
    CV_EML_IF(0, 1, false);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,22);
    for(c2_em_i22 = 0; c2_em_i22 < 2; c2_em_i22 = c2_em_i22 + 1) {
      c2_b_CentroidCoords[c2_em_i22] = c2_z[c2_em_i22];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,25);
  c2_A = c2_b_VidSize[1];
  c2_B = 2.0;
  c2_f_x = c2_A;
  c2_b_y = c2_B;
  c2_d_z = c2_f_x / c2_b_y;
  c2_c_y = c2_d_z;
  c2_b_LineVector[0][0] = c2_b_VidSize[0];
  c2_b_LineVector[1][0] = c2_c_y;
  c2_b_LineVector[2][0] = c2_b_CentroidCoords[0];
  c2_b_LineVector[3][0] = c2_b_CentroidCoords[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,26);
  c2_b_CentroidCol = c2_b_CentroidCoords[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-26);
  sf_debug_pop_symbol_scope();
  for(c2_em_i23 = 0; c2_em_i23 < 2; c2_em_i23 = c2_em_i23 + 1) {
    c2_CentroidCoords()[c2_em_i23] = c2_b_CentroidCoords[c2_em_i23];
  }
  for(c2_em_i24 = 0; c2_em_i24 < 4; c2_em_i24 = c2_em_i24 + 1) {
    c2_LineVector()[c2_em_i24] = c2_b_LineVector[c2_em_i24][0];
  }
  *c2_CentroidCol() = c2_b_CentroidCol;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_object_tracker_without_centroidMachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static void c2_power(real_T *c2_a, real_T c2_b, real_T *c2_y)
{
  int32_T c2_em_i25;
  real_T c2_k;
  real_T c2_b_k;
  int32_T c2_em_i26;
  real_T c2_x[10][1];
  real_T c2_c_k;
  real_T c2_xk;
  real_T c2_ak;
  real_T c2_b_x;
  real_T c2_b_xk;
  real_T c2_bk;
  real_T c2_c_x;
  real_T c2_b_y;
  for(c2_em_i25 = 0; c2_em_i25 < 10; c2_em_i25 = c2_em_i25 + 1) {
    c2_y[c2_em_i25] = 0.0;
  }
  for(c2_k = 1.0; c2_k <= 10.0; c2_k = c2_k + 1.0) {
    c2_b_k = c2_k;
    for(c2_em_i26 = 0; c2_em_i26 < 10; c2_em_i26 = c2_em_i26 + 1) {
      c2_x[c2_em_i26][0] = c2_a[c2_em_i26];
    }
    c2_c_k = c2_b_k;
    c2_xk = (*(real_T (*)[10])&c2_x)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
     (int32_T)_SFD_INTEGER_CHECK("k", c2_c_k), 1, 10, 1) - 1];
    c2_ak = c2_xk;
    c2_b_x = c2_b;
    c2_b_xk = c2_b_x;
    c2_bk = c2_b_xk;
    if(c2_ak < 0.0) {
      c2_c_x = c2_bk;
      c2_b_y = floor(c2_c_x);
      if(c2_b_y != c2_bk) {
        sf_mex_call("error", 0U, 1U, 15,
         "Domain error. To compute complex results, make at least one input complex, e.g. \'power(complex(a),b)\'.");
      }
    }
    (*(real_T (*)[10])c2_y)[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
     (int32_T)_SFD_INTEGER_CHECK("k", c2_b_k), 1, 10, 1) - 1] = pow(
      c2_ak, c2_bk);
  }
}

static real_T *c2_CentroidCoords(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real_T *c2_CentroidArray(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
}

static real_T *c2_LineVector(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static real_T *c2_booleof(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
}

static real_T *c2_StartCoords(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
}

static real_T *c2_VidSize(void)
{
  return (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
}

static real_T *c2_CentroidCol(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static void init_dsm_address_info(void)
{
}

static void sf_save_state_c2_object_tracker_without_centroid(FILE *c2_file)
{
  fwrite(&chartInstance.c2_is_active_c2_object_tracker_without_centroid, 1,
   sizeof(chartInstance.
    c2_is_active_c2_object_tracker_without_centroid), c2_file);
  fwrite(&chartInstance.c2_LastCentroid, 1,
   sizeof(chartInstance.c2_LastCentroid), c2_file);
  fwrite(&chartInstance.c2_LastCentroid_not_empty, 1,
   sizeof(chartInstance.c2_LastCentroid_not_empty), c2_file);
}

static void sf_load_state_c2_object_tracker_without_centroid(FILE *c2_file)
{
  fread(&chartInstance.c2_is_active_c2_object_tracker_without_centroid, 1,
   sizeof(chartInstance.
    c2_is_active_c2_object_tracker_without_centroid), c2_file);
  fread(&chartInstance.c2_LastCentroid, 1,
   sizeof(chartInstance.c2_LastCentroid), c2_file);
  fread(&chartInstance.c2_LastCentroid_not_empty, 1,
   sizeof(chartInstance.c2_LastCentroid_not_empty), c2_file);
}

/* SFunction Glue Code */
void sf_c2_object_tracker_without_centroid_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2152042789U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1731905569U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4165203922U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2178026701U);
}

mxArray *sf_c2_object_tracker_without_centroid_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1749386408U);
    pr[1] = (double)(447720091U);
    pr[2] = (double)(3631354856U);
    pr[3] = (double)(3735831604U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(10);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S)
{
  if(ssIsFirstInitCond(S)) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_object_tracker_without_centroidMachineNumber_,
         2,
         1,
         1,
         7,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting(_object_tracker_without_centroidMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_object_tracker_without_centroidMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"CentroidCoords",0);
          }
          {
            unsigned int dimVector[2];
            dimVector[0]= 2;
            dimVector[1]= 10;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"CentroidArray",0);
          }
          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 4;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"LineVector",0);
          }
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"booleof",0);
          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"StartCoords",0);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"VidSize",0);
          }
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"CentroidCol",0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,0,0,0,5,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,774);
        _SFD_CV_INIT_EML_IF(0,0,236,280,-1,315);
        _SFD_CV_INIT_EML_IF(0,1,500,563,623,655);
        {
          static int condStart[] = {239,264};
          static int condEnd[] = {260,279};
          static int pfixExpr[] = {0,1,-2};
          _SFD_CV_INIT_EML_MCDC(0,0,239,279,2,0,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        {
          static int condStart[] = {503,527,546};
          static int condEnd[] = {523,542,562};
          static int pfixExpr[] = {0,1,-3,2,-3};
          _SFD_CV_INIT_EML_MCDC(0,1,503,562,3,2,&(condStart[0]),&(condEnd[0]),5,&(pfixExpr[0]));
        }
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(0U, c2_CentroidCoords());
        _SFD_SET_DATA_VALUE_PTR(4U, c2_CentroidArray());
        _SFD_SET_DATA_VALUE_PTR(1U, c2_LineVector());
        _SFD_SET_DATA_VALUE_PTR(2U, c2_booleof());
        _SFD_SET_DATA_VALUE_PTR(3U, c2_StartCoords());
        _SFD_SET_DATA_VALUE_PTR(6U, c2_VidSize());
        _SFD_SET_DATA_VALUE_PTR(5U, c2_CentroidCol());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_object_tracker_without_centroidMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_object_tracker_without_centroid(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_params_c2_object_tracker_without_centroid();
  initialize_c2_object_tracker_without_centroid();
}

static void sf_opaque_enable_c2_object_tracker_without_centroid(void
 *chartInstanceVar)
{
  enable_c2_object_tracker_without_centroid();
}

static void sf_opaque_disable_c2_object_tracker_without_centroid(void
 *chartInstanceVar)
{
  disable_c2_object_tracker_without_centroid();
}

static void sf_opaque_gateway_c2_object_tracker_without_centroid(void
 *chartInstanceVar)
{
  sf_c2_object_tracker_without_centroid();
}

static void sf_opaque_terminate_c2_object_tracker_without_centroid(void
 *chartInstanceVar)
{
  finalize_c2_object_tracker_without_centroid();
}

static void mdlProcessParameters_c2_object_tracker_without_centroid(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  initialize_params_c2_object_tracker_without_centroid();
}

static void mdlSetWorkWidths_c2_object_tracker_without_centroid(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("object_tracker_without_centroid",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("object_tracker_without_centroid",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"object_tracker_without_centroid",2,4);
      sf_mark_chart_reusable_outputs(S,"object_tracker_without_centroid",2,3);
    }
    if
    (!sf_is_chart_instance_optimized_out("object_tracker_without_centroid",2)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("object_tracker_without_centroid",2);
      dtId = ssRegisterDataType(S, chartInstanceTypedefName);
      if (dtId == INVALID_DTYPE_ID ) return;
      /* Register the size of the udt */
      if (!ssSetDataTypeSize(S, dtId, 8)) return;
      if(!ssSetNumDWork(S,1)) return;
      ssSetDWorkDataType(S, 0, dtId);
      ssSetDWorkWidth(S, 0, 1);
      ssSetDWorkName(S, 0, "ChartInstance"); /*optional name, less than 16 chars*/
      sf_set_rtw_identifier(S);
    }
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3068064867U));
  ssSetChecksum1(S,(3109363621U));
  ssSetChecksum2(S,(3827644143U));
  ssSetChecksum3(S,(3584229332U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_object_tracker_without_centroid(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "object_tracker_without_centroid", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void
sf_save_debug_c2_object_tracker_without_centroid(SFc2_object_tracker_without_centroidInstanceStruct*
 chartInstance, FILE* file)
{
  int machineNumber = _object_tracker_without_centroidMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = sf_debug_get_state_vectors_data_size(machineNumber,
   chartNumber, instanceNumber);
  unsigned char* buffer = (unsigned char*) malloc(bufferSize);
  unsigned int chartActive = sf_debug_get_chart_active(machineNumber,
   chartNumber, instanceNumber);
  fwrite(&chartActive, sizeof(chartActive),1,file);
  sf_debug_get_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  fwrite(&bufferSize, sizeof(bufferSize), 1, file); /* Write number of bytes */
  fwrite(buffer, 1, bufferSize,file);   /* Write buffer */
  free(buffer);
}
static void
sf_load_debug_c2_object_tracker_without_centroid(SFc2_object_tracker_without_centroidInstanceStruct*
 chartInstance,FILE* file)
{
  int machineNumber = _object_tracker_without_centroidMachineNumber_;
  int chartNumber = chartInstance->chartNumber;
  int instanceNumber = chartInstance->instanceNumber;
  int bufferSize = 0;
  unsigned char* buffer = NULL;
  unsigned int chartActive = 0;
  fread(&chartActive, sizeof(chartActive),1,file);
  sf_debug_set_chart_active(machineNumber, chartNumber, instanceNumber,
   chartActive);
  fread(&bufferSize, sizeof(bufferSize), 1, file);
  buffer = (unsigned char*) malloc(bufferSize);
  fread(buffer, 1, bufferSize, file);
  sf_debug_set_state_vectors_data(machineNumber, chartNumber, instanceNumber,
   buffer, bufferSize);
  free(buffer);
}
static void sf_c2_object_tracker_without_centroid_sim_ctx_io(SimStruct* S, const
 char io, FILE* file)
{
  if(io == 'r') {
    sf_load_state_c2_object_tracker_without_centroid(file);
    sf_load_debug_c2_object_tracker_without_centroid(&chartInstance, file);
  } else {
    sf_save_state_c2_object_tracker_without_centroid(file);
    sf_save_debug_c2_object_tracker_without_centroid(&chartInstance, file);
  }
}
static void mdlStart_c2_object_tracker_without_centroid(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_object_tracker_without_centroid;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */
  ssSetmdlSimulationContextIO(S,
   sf_c2_object_tracker_without_centroid_sim_ctx_io);
  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c2_object_tracker_without_centroid_method_dispatcher(SimStruct *S, int_T
 method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_object_tracker_without_centroid(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_object_tracker_without_centroid(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_object_tracker_without_centroid(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_object_tracker_without_centroid_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

