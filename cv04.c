#include <stdio.h>
#include <stdlib.h>


double* create_array(int N) {
	if (N <= 0) {
		return NULL;
	}
	return (double *)malloc(N * sizeof(double));
}

void fill_double_array(double *arr, int N) {
	if (arr == NULL) {
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 10 + 1;
	}
}

int* create_int_array(double *arr, int N) {
	int size = (int)arr[N-1];
	return (int *)malloc(size * sizeof(int));
}

void test() {
	int m = 0;												// Test 1
	if (create_array(m) != NULL) { printf("Chyba"); }
	else { printf("Spravne osetreno\n"); }

	double k = 6.8;											// Test 2
	double *test_pole = create_array(k);
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (test_pole[i] != NULL) {
			count++;
		}
	}
	printf("Pocet prvku: %d\nZadane cislo: %f\n", count, k);
	

	int n = 5;											// Test 3
	double *pole = create_array(n);

	fill_double_array(pole, n);

	for (int i = 0; i < n; i++) {
		printf("%f\n", pole[i]);
	}

	int* pole_int = create_int_array(pole, n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", pole[i]);
	}

	free(pole);
	free(pole_int);
}


int main() {
	test();

	return 0;
}
