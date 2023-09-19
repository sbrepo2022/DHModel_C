#include "dhmodel.h"

double deg_to_rad(double deg)
{
    return deg * M_PI / 180;
}

void DHModel6_init(DHModel6 *model, const DHParams6 *params)
{
    for (int i = 0; i < 6; ++i)
    {
        DHModel6_transform_matrix_init(&model->transform[i], params->theta[i], params->a[i], params->d[i], params->alpha[i]);
    }
}

void DHModel6_transform_matrix_init(Matrix4d *mat, double theta, double  a, double d, double alpha)
{
    mat->m[0][0] = cos(deg_to_rad(theta));
    mat->m[0][1] = -sin(deg_to_rad(theta)) * cos(deg_to_rad(alpha));
    mat->m[0][2] = sin(deg_to_rad(theta)) * sin(deg_to_rad(alpha));
    mat->m[0][3] = a * cos(deg_to_rad(theta));

    mat->m[1][0] = sin(deg_to_rad(theta));
    mat->m[1][1] = cos(deg_to_rad(theta)) * cos(deg_to_rad(alpha));
    mat->m[1][2] = -cos(deg_to_rad(theta)) * sin(deg_to_rad(alpha));
    mat->m[1][3] = a * sin(deg_to_rad(theta));

    mat->m[2][0] = 0;
    mat->m[2][1] = sin(deg_to_rad(alpha));
    mat->m[2][2] = cos(deg_to_rad(alpha));
    mat->m[2][3] = d;

    mat->m[3][0] = 0;
    mat->m[3][1] = 0;
    mat->m[3][2] = 0;
    mat->m[3][3] = 1; 
}

void DHModel6_end_point_relative_to_base_frame(const DHModel6 *model, Vector4d *result)
{
    Vector4d tmp = {0, 0, 0, 1};
    for (int i = 5; i >= 0; --i)
    {
        Matrix4d_mult(&model->transform[i], &tmp, result);
        Vector4d_copy(&tmp, result);
    }
}