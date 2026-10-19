#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int roma()
{
    int n = 0;
    int* X;
    int count;
    float sum;
    float sumall;
    FILE* fin;
    FILE* fout;

    while (n < 1 || n > 20)
    {
        printf("введите длину массива n: ");
        scanf("%d", &n);
        if (n < 1 || n > 20)
        {
            printf("ошибка: длина массива должна быть от 1 до 20\n");
        }
    }

    fin = fopen("input.txt", "r");
    X = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        fscanf(fin, "%d", &X[i]);
    }

    sumall = 0.0;
    for (int i = 0; i < n; i++)
    {
        sumall += X[i];
    }

    count = 0;
    sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (X[i] <= X[0])
        {
            sum += X[i];
            count++;
        }
    }

    fout = fopen("output.txt", "w");

    fprintf(fout, "Ваши данные:\nn = %d\nX = ", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fout, "%d ", X[i]);
    }
    fprintf(fout, "\n");

    fprintf(fout, "\nВаш результат:\n");
    if (count == n)
    {
        fprintf(fout, "Все элементы подходят: %.2f\n", (double)sumall / n);
    }
    else if (count > 1)
    {
        fprintf(fout, "Среднее элементов <= X1: %.2f\n", (double)sum / count);
        fprintf(fout, "Среднее всех элементов: %.2f\n", (double)sumall / n);
    }
    else
    {
        fprintf(fout, "Только один подходящий элемент: %d\n", X[0]);
        fprintf(fout, "Среднее всех элементов: %.2f\n", (double)sumall / n);
    }

    fclose(fout);
    free(X);
    fclose(fin);

    return 0;
}