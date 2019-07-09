#include<stdio.h>
int main(){
    int n, m, ga, cho;
    scanf("%d %d", &n, &m);
    if((m-2*n)%2 == 0 && (m-2*n) >= 0){
        cho = (m-2*n)/2;
        ga = n - cho;
        if(ga >= 0 && cho >= 0) printf("%d %d", ga, cho);
        else printf("-1\n");
    }else printf("-1\n");
    return 0;
}
