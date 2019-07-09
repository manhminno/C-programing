#include <stdio.h>

int check(int a){
    int b = 0;
    int c = a;
    while(a >= 10){
        b = b*10 + a%10;
        a = a/10;
        if(a < 10) b = b*10 + a;
    }
    if(b == c) return c;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int mang[n];
    for(int i = 0;  i < n; i++){
        scanf("%d", &mang[i]);
    }
    for(int i = 0;  i < n; i++){
        if(mang[i] < 10) printf("%d ", mang[i]);
        else if(check(mang[i]) != 0) printf("%d ", mang[i]);
    }
    return 0;
}
