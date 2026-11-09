#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void choose(char* arr, int* len) {
    int min_id = 0;

    for (int j = 1; j < *len; j++) {
        if (arr[j] < arr[min_id]) {
            min_id = j;
        }
    }

    char temp = arr[*len - 1];
    arr[*len - 1] = arr[min_id];
    arr[min_id] = temp;
}


void bubble(char* arr, int* len) {
    for (int j = 0; j < *len - 1; j++) {
        if (arr[j] < arr[j + 1]) {
            char temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

int laba7() {
    int n = 0, count = 0, c;
    char* arr;
    char* work;
    FILE* fin;
    FILE* fout;

    printf("Enter array length n: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid array length.\n");
    }
    else {
        fin = fopen("input7.txt", "r");
        fout = fopen("lab7.txt", "w");
        arr = (char*)malloc(n * sizeof(char));
        work = (char*)malloc(n * sizeof(char));

        if (!fin) {
            printf("Error opening input7.txt.\n");
        }
        else if (!fout) {
            printf("Error opening lab7.txt.\n");
        }
        else if (!arr || !work) {
            printf("Memory allocation error.\n");
        }
        else {
            while (count < n && (c = fgetc(fin)) != EOF) {
                if (c != '\n' && c != '\r') {
                    arr[count] = (char)c;
                    count++;
                }
            }

            if (count != n) {
                printf("Not enough characters in input7.txt.\n");
            }
            else {
                printf("Source: ");
                fprintf(fout, "Source: ");
                for (int i = 0; i < n; i++) {
                    printf("[%c] ", arr[i]);
                    fprintf(fout, "[%c] ", arr[i]);
                }
                printf("\n");
                fprintf(fout, "\n");

                for (int method = 1; method <= 2; method++) {
                    for (int i = 0; i < n; i++) {
                        work[i] = arr[i];
                    }

                    if (method == 1) {
                        printf("\nSelection sort (descending):\n");
                        fprintf(fout, "\nSelection sort (descending):\n");
                    }
                    else {
                        printf("\nBubble sort (descending):\n");
                        fprintf(fout, "\nBubble sort (descending):\n");
                    }

                    for (int pass = 0; pass < n - 1; pass++) {
                        int len = n - pass;

                        if (method == 1) {
                            choose(work, &len);
                        }
                        else {
                            bubble(work, &len);
                        }

                        printf("Pass %d: ", pass + 1);
                        fprintf(fout, "Pass %d: ", pass + 1);
                        for (int i = 0; i < n; i++) {
                            printf("[%c] ", work[i]);
                            fprintf(fout, "[%c] ", work[i]);
                        }
                        printf("\n");
                        fprintf(fout, "\n");
                    }
                }
                printf("\nDone. Results saved to lab7.txt.\n");
            }
        }

        free(arr);
        free(work);
        if (fin) fclose(fin);
        if (fout) fclose(fout);
    }

    return 0;
}