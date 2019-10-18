#include <stdio.h>
#include <math.h>

typedef struct _diem{
    double a;
    double b;
} diem;

double distance(diem a, diem b){
    double tmp = sqrt((a.a - b.a)*(a.a - b.a) + (a.b - b.b)*(a.b - b.b));
    return tmp;
}

int main(){
    diem S, Q, R;
    printf("Nhap toa do:\n");
    printf("Diem S: ");
    scanf("%lf %lf", &S.a, &S.b);
    printf("Diem Q: ");
    scanf("%lf %lf", &Q.a, &Q.b);
    printf("Diem R: ");
    scanf("%lf %lf", &R.a, &R.b);
    double check1 = distance(S, Q);
    double check2 = distance(Q, R);
    double check3 = distance(S, R);
    if(check1 == (check2 + check3) || check2 == (check1 + check3) || check3 == (check1 + check2))
        printf("3 diem khong tao thanh tam giac!");
    else{
        printf("3 diem tao thanh tam giac!\n");
        diem G;
        G.a = (S.a + Q.a + R.a)/3;
        G.b = (S.b + Q.b + R.b)/3;
        printf("Tam giac co trong tam la: G(%.2lf, %.2lf)", G.a, G.b);
    }
}