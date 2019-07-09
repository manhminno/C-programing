#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d", &a, &b);
    c=0;
    while(a<=b/2){
        c++;
        a*=2;
    }
    printf("%d", c);
    return 0;
}
