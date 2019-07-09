#include <stdio.h>
int main(){
    int n, sobia, khuyenmai;
    scanf("%d", &n);
    sobia = n;
    while(n>=10){
        khuyenmai = n/10*3;
        sobia += khuyenmai;
        n = n%10 + khuyenmai;
    }
    printf("%d", sobia);
    return 0;
}
