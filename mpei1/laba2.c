#include <stdio.h>

int laba2() {
    /*A0.0 - объявление переменных*/
    // n - длина массивов
    // X, Y - массивы данных X и Y
    // sum - сумма подходящих элементов, count - их количество

    /*A0.1 - ввод входных данных*/
    int n;
    printf("Enter your array length: ");
    scanf_s("%d", &n);
    if (n < 1 || n > 20)
    {
        printf("Error, because array length is not acceptable");
    }
    else
    {
    printf("Enter number in data X: ");
    // A1.1.3 - в цикле от 0 до n-1 считать элементы массива X
    printf("Enter number in data Y: ");
    // A1.1.4 - в цикле от 0 до n-1 считать элементы массива Y

    //вывод входных данных для подтверждения:
    printf("--- Your data ---\n");
    // A1.1.5 - вывести n
    printf("n = %d\n", n);
    // A1.1.6 - в цикле вывести элементы X через пробел
    printf("X: ");
    // цикл вывода X
    printf("\n");
    // A1.1.7 - в цикле вывести элементы Y через пробел
    printf("Y: ");
    // цикл вывода Y
    printf("\n");

    /*A0.2 - Решение задачи*/
    printf("--- Intermediate data ---\n");
    // A1.2.1 - обнулить sum и count
    // A1.2.2 - в цикле по i от 0 до n-1:
    //     A2.2.2.1 - проверить условие для пары X[i], Y[i]
    //     printf("i = %d: x = %d, y = %d\n", i, Xi], Y[i]);
    //     A2.2.2.2 - если условие выполнено: добавить нужное значение к sum
    //     A2.2.2.3 - если условие выполнено: увеличить count на 1
    //     printf("Element suits: sum = %d, count = %d\n", sum, count);

    /*A0.3 - вывод результатов*/
    int count = 5;
    int sum = 10;
    if (count > 0)
    {
        // A1.3.1 - вывести sum и count
        printf("Your result:\n Sum: %d\n count: %d\n", sum, count);
    }
    else
    {
        // A1.3.2 - сообщить, что подходящих элементов нет
        printf("There are no such elements in the array\n");
    }
    }

    return 0;
}