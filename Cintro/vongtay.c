#include<stdio.h>
int main(){
    int n, t1, t2;
    scanf("%d", &n);
    t1=7;
    t2=0;
    if(n<=7){
        t1-=n;
        t2+=n;
    }
    if(n>7){
        int lan=n/7;
        int du=n%7;
        if(lan%2==0){
            t1=7-du;
            t2=du;
        }
        else{
            t1=du;
            t2=7-du;
        }
    }
    printf("%d %d", t1, t2);
    return 0;
}
