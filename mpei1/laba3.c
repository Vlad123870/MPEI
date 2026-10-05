//лабораторная работа 2
// Задан одномерный массив
// А - вещественный, размер на(цел на[1,20])
// Получить М1 - цел, С1 - вещ, кол-во и сумма положительных, М2 - цел и С2 - вещ кол-во и сумма отрицательных 
// Если М1 = М2 = 0, то печатаем только 0. Если М1 = 0, то нет положительных. Если М2 = 0, то нет отриц.

// Таблица данных
//		Класс			Имя		Тип			Структура		Смысл					Формат		Диапазон
//		Входные			на,а	цел,вещ		п.п, вектор		Размер вх массива		%2i, 5.2f	[1,20]
//		Выходные		М1,М2	цел, цел	п.п				%2i, %2i, %5.2f, %5.2f
//						С1,С2	вещ, вещ
//		Промежуточные	i		цел			п.п

// Входная форма
// Введите размер массива <na>
// А (в круге)

// Выходная форма
// Все нули, Нет отриц, все случаи рассмотреть

// Аномалии
// н не принадлежит [1,20]
// 
// Метод
// Блок-схема
// Начало -) на -) на не лежит [1,20] -) "+" - ошибка -) "Ввод вектора" на -) 
// 
// Тест				Результат		Смысл
// на = 1			Ошибка			Выход размера за ниж границу
// н = 5 А={0,0,0}	все нули		
//
//#include <stdio.h>
//int lab2() {
//	int n;
//	int arr[20];
//	do
//	{
//		printf("Enter your number: ");
//		if (scanf_s("%d", n) != 1) {
//			printf("Not available number");
//			while (getchar() != '\n');
//			continue;
//		}
//		if (n < 1 || n > 20)
//		{
//			printf("Неверный размер");
//		}
//	} while (n < 1 || n > 20);
//	printf("The size of the array is equal to %d. Enter your number.\n", n);
//	for 
//}

#include <stdio.h>
#include <stdlib.h>
int laba3() {
	int n;
	int count = 0;
	int sum = 0;
	printf("Enter your array length: ");
	scanf_s("%d", &n);
	int *X = NULL;
	int *Y = NULL;
	if (n < 1 || n > 20)
	{
		printf("Error, because array length is not acceptable\n");
		return 1;
	}
	else {
		X = (int*)malloc(n * sizeof(int));
		Y = (int*)malloc(n * sizeof(int));
		if (X == NULL || Y == NULL) {
			printf("Memory allocation failed\n");
			free(X);
			free(Y);
			return 1;
		}

		printf("--- Enter array X ---\n");
		for (int i = 0; i < n; i++) {
			printf("arrx[%d] = ", i);
			scanf_s("%d", &X[i]);
		}

		printf("--- Enter array Y ---\n");
		for (int i = 0; i < n; i++) {
			printf("arry[%d] = ", i);
			scanf_s("%d", &Y[i]);
		}


	printf("--- Array X ---\n");
	for (int i = 0; i < n; i++) {
		printf("%d \n", X[i]);
	}

	printf("--- Array Y ---\n");
	for (int i = 0; i < n; i++) {
		printf("%d \n", Y[i]);
	}
	printf("\n\n");


		for (int i = 0; i < n; i++)
		{
			if (X[i] > Y[i])
			{
				if (X[i] > 0)
				{
					count += 1;
					sum += X[i];
				}
			}
		}
		if (count > 0) {
			printf("Your result: \nSum: %d\ncount: %d\n", sum, count);
		}
		else
		{
			printf("There are not such elements in the array: no X element exceeds\n");
		}

		free(X);
		free(Y);
	}

	return 0;
}