#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int laba4() {
    FILE* fin = fopen("input.txt", "r");
    if (fin == NULL) {
        perror("Cannot open input.txt");
    }

    FILE* fout = fopen("output.txt", "w");
    if (fout == NULL) {
        perror("Cannot open output.txt");
        fclose(fin);
    }

    int n;
    int count = 0;
    int sum = 0;
    int X[20];
    int Y[20];

    if (fscanf(fin, "%d", &n) != 1) {
        fprintf(fout, "Error: cannot read array length\n");
    }
    else if (n < 1 || n > 20) {
        fprintf(fout, "Error, because array length is not acceptable\n");
    }
    else {
        int ok = 1;
        for (int i = 0; i < n && ok; i++) {
            if (fscanf(fin, "%d", &X[i]) != 1) ok = 0;
        }
        for (int i = 0; i < n && ok; i++) {
            if (fscanf(fin, "%d", &Y[i]) != 1) ok = 0;
        }

        if (!ok) {
            fprintf(fout, "Error: not enough data in input file\n");
        }
        else {
            fprintf(fout, "n = %d\n", n);
            fprintf(fout, "--- Array X ---\n");
            for (int i = 0; i < n; i++) {
                fprintf(fout, "%d\n", X[i]);
            }
            fprintf(fout, "--- Array Y ---\n");
            for (int i = 0; i < n; i++) {
                fprintf(fout, "%d\n", Y[i]);
            }

            // Алгоритм
            for (int i = 0; i < n; i++) {
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
    }

    fclose(fin);
    fclose(fout);
    return 0;
}