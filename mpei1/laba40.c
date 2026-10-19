#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int laba40() {
    int n = 0;
    int count = 0;
    int sum = 0;
    int i;
    int r;
    int extra;
    int* X;
    int* Y;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n (1..20): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        while (getchar() != '\n') {}
        printf("Error, enter n from 1 to 20: ");
    }

    fout = fopen("output.txt", "w");
    if (!fout) {
        perror("Cannot open output.txt");
    }
    else {
        X = (int*)malloc(n * sizeof(int));
        Y = (int*)malloc(n * sizeof(int));

        if (!X || !Y) {
            printf("Error: memory allocation failed\n");
            fprintf(fout, "Error: memory allocation failed\n");
        }
        else {
            fin = fopen("inputx1.txt", "r");
            if (!fin) {
                printf("Error: cannot open inputx1.txt\n");
                fprintf(fout, "Error: cannot open inputx1.txt\n");
            }
            else {
                i = 0;
                while (i < n && fscanf(fin, "%d", &X[i]) == 1) {
                    i++;
                }
                r = fscanf(fin, "%d", &extra);
                fclose(fin);

                if (i < n || r != EOF) {
                    printf("Error: wrong or insufficient data in inputx1.txt (need exactly n integers)\n");
                    fprintf(fout, "Error: wrong or insufficient data in inputx1.txt (need exactly n integers)\n");
                }
                else {
                    fin = fopen("inputy1.txt", "r");
                    if (!fin) {
                        printf("Error: cannot open inputy1.txt\n");
                        fprintf(fout, "Error: cannot open inputy1.txt\n");
                    }
                    else {
                        i = 0;
                        while (i < n && fscanf(fin, "%d", &Y[i]) == 1) {
                            i++;
                        }
                        r = fscanf(fin, "%d", &extra);
                        fclose(fin);

                        if (i < n || r != EOF) {
                            printf("Error: wrong or insufficient data in inputy1.txt (need exactly n integers)\n");
                            fprintf(fout, "Error: wrong or insufficient data in inputy1.txt (need exactly n integers)\n");
                        }
                        else {
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
                    }
                }
            }
        }

        free(X);
        free(Y);
        fclose(fout);
    }

    return 0;
}