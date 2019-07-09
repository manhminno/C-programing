#include<stdio.h>
int main(){
    int solan, n, vitri = 0;
    scanf("%d", &solan);
    int mang[solan];
    for(int i=0; i<solan; i++){
        scanf("%d", &mang[i]);
    }
    for(int i=0; i<solan; i++){
        if(mang[i] == 1){
            vitri++;
        }
        else vitri--;
    }
    if(vitri<0) vitri=-vitri;
    printf("%d", vitri);
    return 0;
}
