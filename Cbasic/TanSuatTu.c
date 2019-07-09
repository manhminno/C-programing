#include <stdio.h>
#include <string.h>
#define MAX 25

int scanFile(char key[]){
    int count = 0;
    FILE *fin = fopen("FileScan.txt", "r");
    if(fin == NULL) printf("Can't read file!");
    else{
        char temp[MAX];
        while(!feof(fin)){
            fscanf(fin, "%s", &temp);
            if(strcmp(key, temp) == 0) count++;
        }
    }
    return count;
}

int main(){
    char key[MAX];
    printf("Nhap tu muon tim kiem tuan suat: ");
    gets(key);
    printf("%d\n", scanFile(key));
    return 0;
}