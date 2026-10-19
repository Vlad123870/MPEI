#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int zashita4() {
    int n = 0;
    int i;
    int* X;
    int* Y;
    double dx, dy;
    double sum = 0;    
    double average;     
    FILE* finX;
    FILE* finY;
    FILE* fout;

    printf("Enter number of points n (1..20): ");
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
        fprintf(fout, "--- Points (x, y) ---\n");
        for (i = 0; i < n; i++) {
            fprintf(fout, "%d: (%d, %d)\n", i + 1, X[i], Y[i]);
        }
        fprintf(fout, "Last point: (%d, %d)\n", X[n - 1], Y[n - 1]);

        for (i = 0; i < n-1; i++) {
            dx = X[i] - X[n - 1];
            dy = Y[i] - Y[n - 1];
            sum += sqrt(dx * dx + dy * dy);
        }
        average = sum / (n-1);

        fprintf(fout, "Average distance from the last point: %.4f\n", average);
    }

    free(X); 
    free(Y);
    if (finX) fclose(finX);
    if (finY) fclose(finY);
    if (fout) fclose(fout);

    return 0;
}