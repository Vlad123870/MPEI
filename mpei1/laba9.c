#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int laba9() {
	int n;
	int m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);
    int** a = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }

    }

    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("Row %d has no zeros\n", i);
        }
    }

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}