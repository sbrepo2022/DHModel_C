#include <stdio.h>
#include <stdlib.h>
#include "dhmodel.h"

int main(int argc, char **argv) {
    if (argc != 7)
    {
        fprintf(stderr, "Error: %s\n", "need 6 'theta' values");
        return 1;
    }

    DHParams6 params = {
        {0, 0, 0, 0, 0, 0},
        {0, -0.8, -0.598, 0, 0, 0},
        {0.21, 0.193, -0.16, 0.25, 0.25, 0.25},
        {90, 0, 0, 90, -90, 0},
    };

    for (int i = 0; i < 6; ++i)
    {
        params.theta[i] = atof(argv[i + 1]);
    }

    DHModel6 model;
    DHModel6_init(&model, &params);

    Vector4d result;
    Vector4d base = {0, 0, 0, 1};
    DHModel6_end_point_relative_to_base_frame(&model, &result);

    printf("%f %f %f\n", result.v[0], result.v[1], result.v[2]);

    return 0;
}