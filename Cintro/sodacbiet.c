#include <stdio.h>

int main(){
    long long a;
    int tong = 0;
    scanf("%lld", &a);
    long long b = a;
    if(a <= 10){
        printf("1\n");
    }else{
        while(a >= 10){
            tong += a%10;
            a = a/10;
            if(a < 10) tong += a;
        }
        if(b%tong == 0) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
