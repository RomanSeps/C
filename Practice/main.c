#include <stdio.h>
#include "fibo.h"

int fibonacci(int n){
    if(n <= 0){
        return 0;
    }

    if(n == 1 || n == 2){
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main(){
    int n = 6;
    int result = fibonacci(n);
    printf("Fibonacci of %d is: %d\n", n, result);
    return 0;
}