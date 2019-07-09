#include <stdio.h>
#define MAX 255
#include <string.h>

int main(){
    int matkhau = 0;
    char a[MAX];
    scanf("%s", &a);
    for(int i = 0; i < strlen(a); i++){
        matkhau += a[i] - '0';
    }
    printf("%d", matkhau);
    return 0;
}
