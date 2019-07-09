#include<stdio.h>
#include<stdlib.h>
#define MAX 26
int main(){
    int mang[MAX] = {0};
    char check;
    printf("Nhap chuoi ban muon: ");
    check = getchar();
    while( check != '\n'){
        mang[check - 'a']++;
        check = getchar();
    }
    for(int i = 0; i < MAX; i++){
        if(mang[i] > 0){
            printf("Chu '%c' xuat hien %d lan \n", i + 'a', mang[i]);
        }
    }
    return 0;
}
