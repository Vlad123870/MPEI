#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void choose(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_id = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_id]) {
                min_id = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min_id];
        arr[min_id] = tmp;
    }
}

void bubble(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int laba7(void) {
    int n = 0;
    int mode = 0;
    int read = 0;
    int i;
    int* arr;
    int* work;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n: ");
    while (scanf("%d", &n) != 1 || n < 1) {
        while (getchar() != '\n') {}
        printf("Error, enter n >= 1: ");
    }

    fin = fopen("input7.txt", "r");
    fout = fopen("lab7.txt", "w");
    arr = (int*)malloc(n * sizeof(int));
    work = (int*)malloc(n * sizeof(int));

    if (!fin) {
        printf("Error: cannot open input7.txt\n");
    }
    else if (!fout) {
        printf("Error: cannot open lab7.txt\n");
    }
    else if (!arr || !work) {
        printf("Error: memory allocation failed\n");
        fprintf(fout, "Error: memory allocation failed\n");
    }
    else {
        for (i = 0; i < n; i++) {
            if (fscanf(fin, "%d", &arr[i]) == 1) {
                read++;
            }
        }

        if (read != n) {
            printf("Error: input7.txt contains fewer than %d numbers\n", n);
            fprintf(fout, "Error: input7.txt contains fewer than %d numbers\n", n);
        }
        else {
            fprintf(fout, "n = %d\n", n);
            fprintf(fout, "--- Source array ---\n");
            for (i = 0; i < n; i++) {
                fprintf(fout, "%d ", arr[i]);
            }
            fprintf(fout, "\n");

            printf("\nChoose sorting method:\n");
            printf("1 - Selection sort (choose)\n");
            printf("2 - Bubble sort\n");
            printf("3 - Both\n");
            printf("Your choice: ");
            scanf("%d", &mode);

            if (mode < 1 || mode > 3) {
                printf("Invalid choice\n");
                fprintf(fout, "Invalid choice\n");
            }
            else {
                if (mode == 1 || mode == 3) {
                    for (i = 0; i < n; i++) {
                        work[i] = arr[i];
                    }
                    choose(work, n);
                    fprintf(fout, "--- Selection sort ---\n");
                    for (i = 0; i < n; i++) {
                        fprintf(fout, "%d ", work[i]);
                    }
                    fprintf(fout, "\n");
                }

                if (mode == 2 || mode == 3) {
                    for (i = 0; i < n; i++) {
                        work[i] = arr[i];
                    }
                    bubble(work, n);
                    fprintf(fout, "--- Bubble sort ---\n");
                    for (i = 0; i < n; i++) {
                        fprintf(fout, "%d ", work[i]);
                    }
                    fprintf(fout, "\n");
                }

                printf("Done, result is written to lab7.txt\n");
            }
        }
    }

    free(arr);
    free(work);
    if (fin) fclose(fin);
    if (fout) fclose(fout);

    return 0;
}