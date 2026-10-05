//#include <stdio.h>
//#include <math.h>
//
//int danya() {
//    int n;
//    int X[20];
//    int Y[20];
//    int count = 0;
//    double sum = 0; 
//
//    printf("Введите количество точек n: ");
//    scanf_s("%d", &n);
//
//    if (n < 1 || n > 20)
//    {
//        printf("Ошибка: количество точек должно быть от 1 до 20\n");
//    }
//    else
//    {
//        printf("Введите координаты точек:\n");
//
//        for (int i = 0; i < n; i++)
//        {
//            printf("X[%d] = ", i);
//            scanf_s("%d", &X[i]);
//
//            printf("Y[%d] = ", i);
//            scanf_s("%d", &Y[i]);
//        }
//
//        printf("\nВаши координаты:\n");
//        for (int i = 0; i < n; i++)
//        {
//            printf("(%d; %d)\n", X[i], Y[i]);
//        }
//
//        for (int i = 0; i < n; i++)
//        {
//            if (Y[i] > X[i])
//            {
//                count++;
//            }
//        }
//
//        int last_x = X[n - 1];
//        int last_y = Y[n - 1];
//
//        for (int i = 0; i < n - 1; i++)
//        {
//            double px = last_x - X[i];
//            double py = last_y - Y[i];
//
//            sum += sqrt(px * px + py * py);
//        }
//
//        printf("\nКоличество точек, где Y > X: %d\n", count);
//        printf("Суммарное расстояние до последней точки: %.2lf\n", sum);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <math.h>

int danya() {
    int n;
    int X[20];
    int Y[20];
    int count = 0;
    double sum = 0;

    FILE* fin;
    FILE* fout;

    if (fopen_s(&fin, "input.txt", "r") != 0 || fin == NULL)
    {
        printf("Ошибка: не удалось открыть файл input.txt\n");
        return 1;
    }

    if (fscanf_s(fin, "%d", &n) != 1)
    {
        printf("Ошибка: не удалось прочитать количество точек\n");
        fclose(fin);
        return 1;
    }

    if (n < 1 || n > 20)
    {
        printf("Ошибка: количество точек должно быть от 1 до 20\n");
        fclose(fin);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (fscanf_s(fin, "%d %d", &X[i], &Y[i]) != 2)
        {
            printf("Ошибка: в файле не хватает данных (точка %d)\n", i);
            fclose(fin);
            return 1;
        }
    }
    fclose(fin);

    for (int i = 0; i < n; i++)
    {
        if (Y[i] > X[i])
        {
            count++;
        }
    }

    int last_x = X[n - 1];
    int last_y = Y[n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        double px = last_x - X[i];
        double py = last_y - Y[i];

        sum += sqrt(px * px + py * py);
    }

    if (fopen_s(&fout, "output.txt", "w") != 0 || fout == NULL)
    {
        printf("Ошибка: не удалось создать файл output.txt\n");
        return 1;
    }

    fprintf(fout, "Количество точек: %d\n", n);
    fprintf(fout, "Координаты:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fout, "(%d; %d)\n", X[i], Y[i]);
    }

    fprintf(fout, "\nКоличество точек, где Y > X: %d\n", count);
    fprintf(fout, "Суммарное расстояние до последней точки: %.2lf\n", sum);

    fclose(fout);

    printf("Готово, результат записан в output.txt\n");
    return 0;
}