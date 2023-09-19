#include "matrices.h"

void Matrix4d_mult(const Matrix4d *M, const Vector4d *V, Vector4d *result)
{
    for (int i = 0; i < 4; ++i)
    {
        result->v[i] = M->m[i][0] * V->v[0] + M->m[i][1] * V->v[1] + M->m[i][2] * V->v[2] + M->m[i][3] * V->v[3];
    }
}

void Vector4d_copy(Vector4d *dest, const Vector4d *src)
{
    for (int i = 0; i < 4; ++i)
    {
        dest->v[i] = src->v[i];
    }
}