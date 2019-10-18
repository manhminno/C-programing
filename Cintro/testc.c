// #include <stdio.h>

// long countMoney(int distance){
//     if(distance == 1) return 10000;
//     else if(distance <= 30) return (10000 + (distance-1)*13000);
//     else return (10000 + 29*13000 + (distance-30)*11000);
// }

// int main(){
//     int distance;
//     printf("Write Km: ");
//     scanf("%d", &distance);
//     printf("Money: %ld\n", countMoney(distance));
//     return 0;
// }

#include <stdio.h>

long countElec(int headNum, int tailNum){
    int tmp = tailNum - headNum;
    if(tmp <= 100) return tmp*1000;
    else if(tmp <= 200) return (100*1000 + (tmp-100)*1500);
    else if(tmp <= 300) return (100*1000 + 100*1500 + (tmp-200)*2000);
    else return (100*1000 + 100*1500 + 100*2000 + (tmp-300)*2500);
}

int main(){
    int head, tail;
    printf("Write head number & tail number: ");
    scanf("%d %d", &head, &tail);
    if(tail < head) printf("Error!!\n");
    else printf("Money: %ld", countElec(head, tail));
    return 0;
}