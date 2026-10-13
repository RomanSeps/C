#include <stdio.h>

void sizes(int *size_int, int *size_char, int *size_float, int *size_double) { // Pointery jako argumenty, jelikož bez nich se dané proměnné nezmění.
	*size_int = sizeof(int);
	*size_char = sizeof(char);
	*size_float = sizeof(float);
	*size_double = sizeof(double);
}

void swap4bytes(double *num) {
	char* bytes = (char*)num;

	for (int i = 0; i < 4; i++) {
		char temp = bytes[i];
		bytes[i] = bytes[i + 4];
		bytes[i + 4] = temp;			// Pointery lze procházet jako pole. Jinak: *bytes(i + 4)
	}
}

void print_bytes(double* num) {
	char* bytes = (char*)num;

	for (int i = 0; i < sizeof(double); i++) {
		printf("%02X ", bytes[i]);
	}
	printf("\n");
}


int main() {
	int size_int, size_char, size_float, size_double;
	sizes(&size_int, &size_char, &size_float, &size_double);

	printf("Size of int: %d bytes\n", size_int);
	printf("Size of char: %d bytes\n", size_char);
	printf("Size of float: %d bytes\n", size_float);
	printf("Size of double: %d bytes\n", size_double);

	double d = 1234.5678;

	double* p_d;
	p_d = &d;

	printf("Double regular:\n");
	print_bytes(&d);
	swap4bytes(&d);
	printf("Double swapped:\n");
	print_bytes(&d);
	
	

	*p_d = 3.14;

	int* p_int;
	p_int = (int *)p_d; // Ukazuje na stejný blok paměti, jen je přetypován
	*(p_int + 1) = 10; // posune se o datový typ (int)

	char* p_char;
	p_char = (char*)p_d;
	p_char + 2;
}
