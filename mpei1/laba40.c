#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int laba40() {
    int n = 0;
    int count = 0;
    int sum = 0;
    int i;
    int* X;
    int* Y;
    FILE* finX;
    FILE* finY;
    FILE* fout;

    printf("Enter array length n (1..20): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        while (getchar() != '\n') {}
        printf("Error, enter n from 1 to 20: ");
    }

    fout = fopen("output.txt", "w");
    finX = fopen("inputx1.txt", "r");
    finY = fopen("inputy1.txt", "r");
    X = (int*)malloc(n * sizeof(int));
    Y = (int*)malloc(n * sizeof(int));

    if (!fout) {
        printf("Error: cannot open output.txt\n");
    }
    else if (!finX) {
        printf("Error: cannot open inputx1.txt\n");
        fprintf(fout, "Error: cannot open inputx1.txt\n");
    }
    else if (!finY) {
        printf("Error: cannot open inputy1.txt\n");
        fprintf(fout, "Error: cannot open inputy1.txt\n");
    }
    else if (!X || !Y) {
        printf("Error: memory allocation failed\n");
        fprintf(fout, "Error: memory allocation failed\n");
    }
    else {
        for (i = 0; i < n; i++) {
            fscanf(finX, "%d", &X[i]);
        }
        for (i = 0; i < n; i++) {
            fscanf(finY, "%d", &Y[i]);
        }

        fprintf(fout, "n = %d\n", n);
        fprintf(fout, "--- Array X ---\n");
        for (i = 0; i < n; i++) {
            fprintf(fout, "%d\n", X[i]);
        }
        fprintf(fout, "--- Array Y ---\n");
        for (i = 0; i < n; i++) {
            fprintf(fout, "%d\n", Y[i]);
        }

        for (i = 0; i < n; i++) {
            if (X[i] > Y[i] && X[i] > 0) {
                count++;
                sum += X[i];
            }
        }

        if (count > 0) {
            fprintf(fout, "Your result:\nSum: %d\nCount: %d\n", sum, count);
        }
        else {
            fprintf(fout, "There are no such elements in the array\n");
        }
    }

    free(X);
    free(Y);
    if (finX) fclose(finX);
    if (finY) fclose(finY);
    if (fout) fclose(fout);

    return 0;
}