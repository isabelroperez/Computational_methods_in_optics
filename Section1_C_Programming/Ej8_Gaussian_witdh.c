#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100
#define X0 -3
#define X1 3

int main()
{
    double dx = (double)(X1 - X0) / (NUM_POINTS);
    float xi, yi, point1, high1, point2, high2, area;
    float e = 2.71818;
    float bound = 1 / (pow(e, 2));
    FILE *file;
    file = fopen("gaussian.txt", "w");

    for (int i = 0; xi < 3; i++)
    {
        xi = X0 + i * dx;
        yi = exp(-pow(xi, 2)); // pow(number, exponent)
        fprintf(file, "%f  %f\n", xi, yi);
        if (yi < bound && xi < 0)
        {
            point1 = xi;
            high1 = yi;
        }
        if (yi > bound && xi > 0)
        {
            point2 = xi;
            high2 = yi;
        }
    }
    fclose(file);
    area = (point2 - point1) * (high2 + high1) / 2;
    printf("The first intersection point is X1: %f and Y1: %f\n", point1, high1);
    printf("The second intersection point is X2: %f and Y2: %f\n", point2, high2);
    printf("The area is %f\n", area);

    return 0;
}
