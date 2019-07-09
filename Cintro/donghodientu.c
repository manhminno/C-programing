#include <stdio.h>
int main(){
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    if(s == 59 && m == 59 && h == 23) printf("%d %d %d", h - 23, m - 59, s - 59);
    else if(s == 59 && m == 59) printf("%d %d %d", h + 1, m - 59, s - 59);
    else if(s == 59) printf("%d %d %d", h, m+1, s-59);
    else printf("%d %d %d", h, m, s + 1);
}
