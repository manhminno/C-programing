//Ho va ten: Nguyen Viet Manh   MSSV: 20176816  Lop: Viet Nhat C - K62
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 2000
#define LENGTH 6

int bruteForceMatch(char string[], char key[]){
    int j;
    for(int i = 0; i < MAX - LENGTH; i++){
        j = 0;
        while(j < LENGTH && string[i + j] == key[j]){
            j++;
        }
        if(j == LENGTH) return i;
    }
    return -1;
}

int main(){
    char string[MAX];
    char key[LENGTH];
    srand(time(NULL));
    //sinh string bat ky tu a->f
    for(int i = 0; i < MAX; i++){
        string[i] = rand()%6 + 'a';
    }
    printf("Nhap tap ki tu ban muon tim kiem: ");
    gets(key);
    int check = bruteForceMatch(string, key);
    if(check == -1) printf("Khong tim thay tap ki tu yeu cau!\n");
    else printf("Vi tri tim thay xau bat dau tu vi tri thu %d\n", check);
    return 0;
}