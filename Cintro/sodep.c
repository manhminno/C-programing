#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n, tong=0;
    scanf("%d", &n);
    char s[50];
    itoa(n, s, 10);
    for(int i=0; i<strlen(s); i++){
        tong+=s[i]-48;
    }
    if((tong-9)%10==0) printf("YES\n");
    else printf("NO\n");
}
