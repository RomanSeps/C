#include <stdio.h>
#include <stdlib.h>

int* create_array(int size) {
	if (size <= 0) {
		return NULL;
	}
	return (int*)malloc(size * sizeof(int));
}

int* find_even(int* pole) {

	int result[] = (int*)malloc(sizeof(pole));

	for (int i = 0; i < sizeof(pole); i++) {
		if (i % 2 == 0) {
			result[i] = pole[i];
		}
		else {
			result[i] = pole[i++];
		}
	}

	return result;
}

int* find_odd(int* pole) {
	int result[] = (int*)malloc(sizeof(pole));

	for (int i = 0; i < sizeof(pole); i++) {
		if (i % 2 == 0) {
			result[i] = pole[i++];
		}
		else {
			result[i] = pole[i];
		}
	}

	return result;
}

void assign(int* odd, int* even, int size) {
	int **orig = (int**)malloc(size * sizeof(int*));
	// orig[1] = &odd[1];

	for (int i = 0; i < sizeof(orig); i++) {
		// for(int j = 0; j < sizeof(orig); j++){}

		if (i % 2 == 0) {
			orig[i] = &even[i];
		}
		else {
			orig[i] = &odd[i];
		}
	}
}

void print(int** orig, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *orig[i]);
	}
	printf("\n");
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sort(int** orig) {
	bool swapped;

	for (int i = 0; i < sizeof(orig) - 1; i++) {
		swapped = false;
		for (int j = 0; j < sizeof(orig) - 1; j++) {
			if (*orig[j] > *orig[j + 1]) {
				swap(orig[j], orig[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}



int main() {
	int size = 5;
	int* pole = create_array(size);

	int* even = find_even(pole);
	int* odd = find_odd(pole);


	free(pole);
	free(even);
	free(odd);
}
