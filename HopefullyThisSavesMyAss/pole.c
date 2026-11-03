#include <stdio.h>
#include <stdlib.h>

#include "pole.h"

int * alocateArray(int size){
    if(size <= 0){
            return NULL;
        }
        return (int *)malloc(size * sizeof(int));
}

void print_array(int * arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
}

int * move_even(int ** pptr, int *size, int *num_even){
    if(pptr == NULL || *pptr == NULL || size == NULL || num_even == NULL || *size <= 0){
        return NULL;
    }

    int * original = *pptr;

    const int n = *size;

    int * even = alocateArray(n);
    if(even == NULL){
        return NULL;
    }

    int num_odd = 0;
    int num_e = 0;

    for(int i = 0; i < n; i++){
        int val = original[i];
        if (val % 2 == 0) {
            even[num_e++] = val;
        } else {
            original[num_odd++] = val;
        }
    }

    if (num_odd == 0) {
        free(original);
        *pptr = NULL;
    } else if (num_odd < n) {
        int *zmensene = realloc(original, num_odd * sizeof(int));
        if (zmensene != NULL) {
            *pptr = zmensene; /* při selhání zůstává původní blok platný, jen o něco větší */
        }
    }

    *size = num_odd;
    *num_even = num_e;
    return even;
}


int main(){
    int values[] = {2, 4, 5, 3, 1, 8};

    int n = 6;

    int num_even = 0;

    int* ptr = alocateArray(n);

    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        *(ptr + i) = values[i];
    }

    print_array(ptr, n);

    /*
    int **pptr = alocateArray(n);

    for(int j = 0; j < n; j++){
        *pptr = &values[j];
    }
    */

    int * even = move_even(&ptr, &n, &num_even);
    if(even == NULL){
        printf("You stupid.");
        return 2;
    }

    printf("Result: \n");
    print_array(even, n);

    free(even);
    free(ptr);
}