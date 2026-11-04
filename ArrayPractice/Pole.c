#include <stdio.h>
#include <stdlib.h>
#include "Pole.h"

int* create_array(int size){
    if(size <= 0){
        return NULL;
    }

    return (int*)malloc(size * sizeof(int));
}

int* find_even_numbers(int* arr, int size){
    if(size <= 0){
        return NULL;
    }

    int result[] = create_array(size);
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            result[i] = arr[i];
        }
    }
    return result;
}

int* find_odd_numbers(int* arr, int size){
    if(size <= 0){
        return NULL;
    }

    int result[] = create_array(size);
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 != 0){
            result[i] = arr[i];
        }
    }
    return result;
}

int* assign(int* odd, int* even, int size){
    if(size <= 0){
        return NULL;
    }

    int** result = create_array(size);
    for(int i = 0; i < size; i++){
        result[i] = even[i];
    }
    return result;
}

void sort(int* arr, int size){
    if(size <= 0){
        return;
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}