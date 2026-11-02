#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int laba5() {
    int n = 0;
    int m = 1;
    int m2 = 0;
    int k = 0;
    int i;
    double p = 0;
    double mx = 0;
    double mx2 = 0;
    double* A;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n (1..20): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        while (getchar() != '\n') {}
        printf("Error, enter n from 1 to 20: ");
    }

    fout = fopen("output.txt", "w");
    fin = fopen("input.txt", "r");
    A = (double*)malloc(n * sizeof(double));

    if (!fout) {
        printf("Error: cannot open output.txt\n");
    }
    else if (!fin) {
        printf("Error: cannot open input.txt\n");
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

        p = A[0] * A[0];
        mx = p;
        for (i = 1; i < n; i++) {
            p *= A[i] * A[i];
            if (p > mx) {
                mx = p;
                m = i + 1;
            }
        }

        fprintf(fout, "Your result:\nFirst max number: %d\n", m);

        if (n < 2) {
            fprintf(fout, "There is no second maximum\n");
        }
        else {
            if (m == 1) {
                p = A[0] * A[0];
                p *= A[1] * A[1];
                mx2 = p;
                m2 = 2;
                k = 2;
            }
            else {

                p = A[0] * A[0];
                mx2 = p;
                m2 = 1;
                k = 1;
            }

            for (i = k; i < n; i++) {
                p *= A[i] * A[i];
                if (i + 1 != m && p > mx2) {
                    mx2 = p;
                    m2 = i + 1;
                }
            }

            fprintf(fout, "Second max number: %d\n", m2);
        }
    }

    free(A);
    if (fin) fclose(fin);
    if (fout) fclose(fout);

    return 0;
}