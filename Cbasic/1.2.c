#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int Check(int mang1[], int mang2[]){
    for(int i = 0; i < MAX; i++){
        if(mang1[i] != mang2[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int mang1[MAX];
    int mang2[MAX];
    printf("Nhap so phan tu cua mang thu nhat:\n");
    for(int i = 0; i < MAX; i++){
        scanf("%d",&mang1[i]);
    }
    printf("Nhap so phan tu cua mang thu hai:\n");
    for(int i = 0; i < MAX; i++){
        scanf("%d", &mang2[i]);
    }
    printf("%d", Check(mang1, mang2));
    return 0;
}
