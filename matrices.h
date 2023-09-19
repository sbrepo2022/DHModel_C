#ifndef MATRICES
#define MATRICES

typedef struct {
    double m[4][4];
} Matrix4d;

typedef struct {
    double v[4];
} Vector4d;

void Matrix4d_mult(const Matrix4d *M, const Vector4d *V, Vector4d *result);
void Vector4d_copy(Vector4d *dest, const Vector4d *src);

#endif