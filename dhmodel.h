#ifndef DHMODEL
#define DHMODEL

#include "matrices.h"
#define _USE_MATH_DEFINES
#include <math.h>

typedef struct {
    Matrix4d transform[6];
} DHModel6;

typedef struct {
    double theta[6];
    double a[6];
    double d[6];
    double alpha[6];
} DHParams6;

double deg_to_rad(double deg);

void DHModel6_init(DHModel6 *model, const DHParams6 *params);
void DHModel6_transform_matrix_init(Matrix4d *mat, double theta, double  a, double d, double alpha);
void DHModel6_end_point_relative_to_base_frame(const DHModel6 *model, Vector4d *result);

#endif