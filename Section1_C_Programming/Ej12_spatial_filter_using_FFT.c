#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fftw3.h"

/* Macros for real and imaginary parts */
#define REAL 0
#define IMAG 1

int main() {
    /* Variables to extract values from "data.txt" */
    int data;
    float float1;

    /* Auxiliary variables */
    int j = -1;

    /* Define the length of the complex array */
    int n = 640;

    /* Value from which to zero out FFT values */
    /* Removing high frequencies */
    int lower_limit = 13;
    int upper_limit;

    /* Input FFT array */
    fftw_complex x[n];

    /* Output FFT array */
    fftw_complex y[n];

    /* Variable to store the absolute value of the FFT */
    double absolute_value;

    /* Declare file variables as FILE pointers */
    FILE *file1; /* Read the data */
    FILE *file2; /* Initial data for Mathematica */
    FILE *file3; /* Data after FFT for Mathematica */
    FILE *file4; /* Filtered data for Mathematica */

    /* Open "data.txt" in text mode and store its address in the pointer */
    file1 = fopen("data.txt", "r");

    /* Open "initial_data.txt" in write mode and store its address in the pointer */
    file2 = fopen("initial_data.txt", "w");
    file3 = fopen("fft_data.txt", "w");
    file4 = fopen("filtered_data.txt", "w");

    while (1) {
        int ret = fscanf(file1, " %d %f%*[^\n]\n", &data, &float1);
        if (ret == EOF) {
            break;
        }

        if (ret >= 2) {
            /* Insert data into the input array */
            j++;
            printf("%d %d %f \n", j, data, float1);
            x[j][REAL] = float1;
            x[j][IMAG] = 0;
            fprintf(file2, "%d %f\n", j, float1);
        } else {
            fscanf(file1, " %*[^\n]\n");
        }
    }

    /* Close "data.txt" */
    fclose(file1);

    /* Fourier Transform: Define the plan and execute it */
    fftw_plan plan;

    plan = fftw_plan_dft_1d(n, x, y, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(plan);

    /* Destroy the plan */
    fftw_destroy_plan(plan);

    /* Display what has been calculated */
    upper_limit = data - lower_limit;
    printf("FFT: \n");
    printf("data %d\n", data);
    printf("lower_limit %d\n", lower_limit);
    printf("upper_limit %d\n", upper_limit);

    for (int i = 0; i < data; i++) {
        if (i >= lower_limit && i <= upper_limit) {
            /* Zero out intermediate values */
            y[i][REAL] = 0;
            y[i][IMAG] = 0;
        }
        absolute_value = sqrt(pow(y[i][REAL], 2) + pow(y[i][IMAG], 2));
        printf("%f + (%f *i) \n", y[i][REAL], y[i][IMAG]);
        fprintf(file3, "%d %f\n", i, absolute_value);
    }

    /* Inverse Fourier Transform: Define the plan and execute it */
    fftw_plan plan2;

    plan2 = fftw_plan_dft_1d(n, y, x, FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(plan2);

    /* Display and save in file2 what has been calculated */
    printf("IFFT: \n");

    for (int i = 0; i < data; i++) {
        printf("%f + (%f *i) \n", x[i][REAL], x[i][IMAG]);
        fprintf(file4, "%d %f \n", i, x[i][REAL] / data);
    }

    /* Destroy the plan */
    fftw_destroy_plan(plan2);

    /* Close the file where we wrote the data */
    fclose(file2);
    fclose(file3);
    fclose(file4);

    return 0;
}
