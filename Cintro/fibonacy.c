#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int fb[n];
    fb[0]=1;
    fb[1]=1;
    for(int i=2; i < n; i++){
        fb[i]=fb[i-1]+fb[i-2];
    }
    for(int i = 0; i < n; i++){
        printf("%d ", fb[i]);
    }
    return 0;
}
