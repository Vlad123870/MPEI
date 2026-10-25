#include <stdio.h>
#include <stdlib.h>
int km1() {
	int* B;
	int a, b;
	int n;
	int ar, mn, num, min;
	scanf_s("%d", &n);
	B = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("arrx[%d] = ", i);
		scanf_s("%d", &B[i]);
	}
	for (int i = 0; i < n; i++) {
		min = B[0];
		if (B[i] < min) {
			num = i;
			mn = B[i];
		}
	}

	printf("%d %d", mn, num);
	free(B);
	return 0;
}