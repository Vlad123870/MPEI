#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int laba5() {
    int n = 0;
    int m = 1;
    int i;
    double p = 1;
    double mx = -1;
    double* A;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n (1..20): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        while (getchar() != '\n') {}
        printf("Error, enter n from 1 to 20: ");
    }

    fout = fopen("outputlab5.txt", "w");
    fin = fopen("inputlab5.txt", "r");
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

        for (i = 0; i < n; i++) {
            p *= A[i] * A[i];
            if (p > mx) {
                mx = p;
                m = i + 1;
            }
        }

        fprintf(fout, "Your result:\nm = %d\n", m);
    }

    free(A);
    if (fin) fclose(fin);
    if (fout) fclose(fout);

    return 0;
}