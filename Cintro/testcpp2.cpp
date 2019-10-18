#include <stdio.h>

int main(){
    int m;
    printf("Nhap m(5<= m <= 200): ");
    scanf("%d", &m);
    while(m < 5 || m > 200){
        printf("Nhap m(5<= m <= 200): ");
        scanf("%d", &m);
    }
}