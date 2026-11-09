#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int laba6() {
    int n = 0;
    int T1 = 0;
    int T2 = 0;
    int k = 0;    
    int m = 0; 
    int i;
    int* A;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n (1..20): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        while (getchar() != '\n') {}
        printf("Error, enter n from 1 to 20: ");
    }
    printf("Enter T1: ");
    scanf("%d", &T1);
    printf("Enter T2: ");
    scanf("%d", &T2);

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    A = (int*)malloc(n * sizeof(int));

    if (!fout) {
        printf("Error: cannot open output file\n");
    }
    else if (!fin) {
        printf("Error: cannot open input file\n");
    }
    else if (!A) {
        printf("Error: memory allocation failed\n");
        fprintf(fout, "Error: memory allocation failed\n");
    }
    else {
        fprintf(fout, "n = %d\nT1 = %d\nT2 = %d\n", n, T1, T2);
        fprintf(fout, "--- Array A ---\n");
        for (i = 0; i < n; i++) {
            fscanf(fin, "%d", &A[i]);
            fprintf(fout, "%d\n", A[i]);
        }

        i = 0;
        while (i < n && A[i] <= T2) {
            i++;
        }
        if (i < n) {
            k = i + 1;
        }

        for (i = k; i < n; i++) {
            if (A[i] < T1 && (m == 0 || A[i] <= A[m - 1])) {
                m = i + 1;
            }
        }

        fprintf(fout, "Your result:\n");
        if (m > 0) {
            fprintf(fout, "Number of the last minimum: %d\n", m);
        }
        else if (k > 0) {
            fprintf(fout, "No elements less than T1 after the first element greater than T2\n");
        }
        else {
            fprintf(fout, "No elements less than T1\n");
        }
    }

    free(A);
    if (fin) fclose(fin);
    if (fout) fclose(fout);

    return 0;
}