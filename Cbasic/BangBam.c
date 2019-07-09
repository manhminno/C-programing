#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashString(char key[]){
    int sum = 0;
    for(int i = 0; i < strlen(key); i++){
        sum += atoi(key[i]);
    }
    return sum;
}

