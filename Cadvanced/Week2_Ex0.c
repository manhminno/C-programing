#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int arr[100];
    int arr2[100];
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    memcpy(arr2, arr, sizeof(int)*10);
    for(int i = 0; i < 10; i++)
        printf("%d\t", arr2[i]);
    return 0;
}