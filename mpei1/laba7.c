#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Selection sort: find the minimum and put it at the end. */
void choose(char* arr, int n, FILE* fout) {
    int i, j, k, min_id;
    char temp;

    for (i = n - 1; i > 0; i--) {
        min_id = 0;
        for (j = 1; j <= i; j++) {
            if ((unsigned char)arr[j] < (unsigned char)arr[min_id]) {
                min_id = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_id];
        arr[min_id] = temp;

        printf("Pass %d: ", n - i);
        fprintf(fout, "Pass %d: ", n - i);
        for (k = 0; k < n; k++) {
            printf("[%c] ", arr[k]);
            fprintf(fout, "[%c] ", arr[k]);
        }
        printf("\n");
        fprintf(fout, "\n");
    }
}

/* Bubble sort: move the minimum to the end on every pass. */
void bubble(char* arr, int n, FILE* fout) {
    int i, j, k;
    char temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((unsigned char)arr[j] < (unsigned char)arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d: ", i + 1);
        fprintf(fout, "Pass %d: ", i + 1);
        for (k = 0; k < n; k++) {
            printf("[%c] ", arr[k]);
            fprintf(fout, "[%c] ", arr[k]);
        }
        printf("\n");
        fprintf(fout, "\n");
    }
}

int laba7(int argc, char* argv[]) {
    const char* input_name = "input7.txt";
    const char* output_name = "lab7.txt";
    FILE* fin = NULL;
    FILE* fout = NULL;
    char* arr = NULL, * work = NULL;
    int n = 0, mode = 0, i, c, count = 0;

    if (argc > 1) input_name = argv[1];
    if (argc > 2) output_name = argv[2];

    printf("Enter array length n: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid array length.\n");
    }
    else {
        fin = fopen(input_name, "r");
        fout = fopen(output_name, "w");
        arr = (char*)malloc(n * sizeof(char));
        work = (char*)malloc(n * sizeof(char));

        if (fin == NULL || fout == NULL || arr == NULL || work == NULL) {
            printf("Cannot open files or allocate memory.\n");
        }
        else {
            /* Read exactly n characters; spaces are also elements. */
            while (count < n && (c = fgetc(fin)) != EOF) {
                if (c != '\n' && c != '\r') {
                    arr[count] = (char)c;
                    count++;
                }
            }

            if (count != n) {
                printf("Not enough characters in input file.\n");
            }
            else {
                printf("Source: ");
                fprintf(fout, "Source: ");
                for (i = 0; i < n; i++) {
                    printf("[%c] ", arr[i]);
                    fprintf(fout, "[%c] ", arr[i]);
                }
                printf("\n");
                fprintf(fout, "\n");

                printf("1 - Selection sort\n");
                printf("2 - Bubble sort\n");
                printf("3 - Both sorts\n");
                printf("Choose: ");

                if (scanf("%d", &mode) != 1 || mode < 1 || mode > 3) {
                    printf("Invalid choice.\n");
                }
                else {
                    if (mode == 1 || mode == 3) {
                        for (i = 0; i < n; i++) work[i] = arr[i];
                        printf("\nSelection sort (descending):\n");
                        fprintf(fout, "\nSelection sort (descending):\n");
                        choose(work, n, fout);
                    }
                    if (mode == 2 || mode == 3) {
                        for (i = 0; i < n; i++) work[i] = arr[i];
                        printf("\nBubble sort (descending):\n");
                        fprintf(fout, "\nBubble sort (descending):\n");
                        bubble(work, n, fout);
                    }
                    printf("\nDone. \nOutput: %s\n", output_name);
                }
            }
        }
    }

    free(arr);
    free(work);
    if (fin != NULL) fclose(fin);
    if (fout != NULL) fclose(fout);
    return 0;
}
