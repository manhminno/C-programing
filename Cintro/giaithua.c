#include<stdio.h>
int main(){
    int n;
    long long s=1;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        s=s*i;
    }
    printf("%lld", s);
    return 0;
}
