#include <stdio.h>
#include <stdlib.h>

#include "files.h"

void print_file(){
    FILE * f = fopen("C:\\Users\\Roman\\Documents\\PRG\\C\\HopefullyThisSavesMyAss\\example.txt", "r");
    if(f == NULL){
        printf("Error opening a file\n");
        exit(1);
    }
    int output[50];
    int i = 0;
    printf("Contents of the file are:\n");
    while(i < 50 && fscanf(f, "%d", &output[i]) == 1){
        printf("%d \n", output[i]);
        i++;
    }
    fclose(f);
}


int main(){

    print_file();

    return 0;
}