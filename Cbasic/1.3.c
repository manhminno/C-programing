#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void ThayThe(char *str, char a, char b){
    while (*str != '\0'){
        if(*str == a)
            *str = b;
        str++;
    }
}
int main(){
    char xau[100];
    char a, b;
    printf("Nhap xau ban muon: ");
    gets(xau);
    printf("Nhap chu can thay the trong xau: ");
    scanf("%c", &a);
    fflush(stdin);
    printf("Nhap chu thay the: ");
    scanf("%c", &b);
    ThayThe(xau, a, b);
    printf("Xau sau khi thay the: %s", xau);
    return 0;
}
