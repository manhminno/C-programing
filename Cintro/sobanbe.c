#include<stdio.h>
int tonguoc(int a){
    int tong=0;
    for(int i=1; i <= a/2; i++){
        if(a%i==0) tong+=i;
    }
    return tong;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a==tonguoc(b) && b==tonguoc(a)) printf("YES\n");
    else printf("NO");
    return 0;
}
