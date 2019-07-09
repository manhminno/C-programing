#include<stdio.h>
int main(){
    int n, s=0, dem1=0, dem2=0;
    scanf("%d", &n);
    int mang[n];
    for(int i=0; i<n; i++){
        scanf("%d", &mang[i]);
        if(mang[i] == 100) dem1+=1;
        else dem2+=2;
    }
    for(int i=0; i<n; i++){
        s+=mang[i];
    }
    if(n%2 == 0){
        if(s%200 == 0) printf("YES\n");
        else printf("NO\n");
    }else{
        if(s%200 == 0 && (dem1-dem2)%2 == 0 && dem1 != 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
