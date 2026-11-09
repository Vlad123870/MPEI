#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roma()
{
    int n = 0;
    int i;
    double mx;
    double mn;
    double x;
    double result;
    double* A;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n (1..20): ");
    scanf("%d", &n);

    while (n < 1 || n > 20) {
        printf("Error, enter n from 1 to 20: ");
        scanf("%d", &n);
    }

    fout = fopen("output.txt", "w");
    fin = fopen("input.txt", "r");
    A = (double*)malloc(n * sizeof(double));

    if (!fout) {
        printf("Error: cannot open output.txt\n");
    }
    else if (!fin) {
        printf("Error: cannot open input.txt\n");
        fprintf(fout, "Error: cannot open input.txt\n");
    }
    else if (!A) {
        printf("Error: memory allocation failed\n");
        fprintf(fout, "Error: memory allocation failed\n");
    }
    else {
        for (i = 0; i < n; i++) {
            fscanf(fin, "%lf", &A[i]);
        }

        fprintf(fout, "n = %d\n", n);
        fprintf(fout, "--- Array A ---\n");

        for (i = 0; i < n; i++) {
            fprintf(fout, "%g\n", A[i]);
        }

        mx = fabs(A[0]);
        mn = fabs(A[0]);

        for (i = 1; i < n; i++) {
            x = fabs(A[i]);

            if (x > mx) {
                mx = x;
            }

            if (x < mn) {
                mn = x;
            }
        }

        result = mx - mn;

        fprintf(fout, "Your result:\n");
        fprintf(fout, "Maximum absolute value: %g\n", mx);
        fprintf(fout, "Minimum absolute value: %g\n", mn);
        fprintf(fout, "Difference: %g\n", result);

        printf("Done. See output.txt\n");
    }

    free(A);

    if (fin) fclose(fin);
    if (fout) fclose(fout);

    return 0;
}
