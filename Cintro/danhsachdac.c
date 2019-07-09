#include<stdio.h>
#define SIZEMAX 100
typedef struct{
    int mang[SIZEMAX];
    int size;
} List;
int Init(List *L);
int Isempty(List *L);
int Isfull(List *L);
void Input(List *L);
void Output(List *L);
void Insert(List *L);
void Delete(List *L);
int Search(List *L, int x);
void Delete_x(List *L, int k);

int main(){
    List L;
    Init(&L);
    int x;
    do{
        printf("Nhap so phan tu cua mang:");
        scanf("%d", &L.size);
    }while(L.size<0||L.size>SIZEMAX);
    Input(&L);
    Output(&L);
    Insert(&L);
    Output(&L);
    Delete(&L);
    Output(&L);
    printf("Nhap x can xoa:");
    scanf("%d", &x);
    while(Search(&L, x)){
        int k=Search(&L, x);
        Delete_x(&L, k);
    }
    Output(&L);
}
int Init(List *L){
    L->size=0;
}
int Isempty(List *L){
    return (L->size==0);
}
int Isfull(List *L){
    return (L->size==SIZEMAX);
}
void Input(List *L){
    printf("Nhap thong tin cho mang:");
    for(int i=0; i < L->size; i++){
        scanf("%d", &L->mang[i]);
    }
}
void Output(List *L){
    for(int i=0; i < L->size; i++){
        printf("%d\t", L->mang[i]);
    }
}
void Insert(List *L){
    int k, value;
    if(Isfull(&L)){
        printf("Danh sach da day!");
        return 0;
    }
    do{
    printf("Nhap vi tri can chen:");
    scanf("%d", &k);
    }while(k<=0||k>100);
    printf("Nhap thong tin chen:");
    scanf("%d", &value);
    for(int i=L->size-1; i>=k-1; i--){
        L->mang[i+1]=L->mang[i];
    }
    L->mang[k-1]=value;
    L->size++;
}
void Delete(List *L){
    int k;
    if(Isempty(&L)){
        printf("Danh sach rong!");
        return 0;
    }
    do{
    printf("Nhap vi tri can xoa:");
    scanf("%d", &k);
    }while(k<0||k>100);
    for(int i=k-1; i<L->size-1; i++){
        L->mang[i]=L->mang[i+1];
    }
    L->size--;
}

int Search(List *L, int x){
    for(int i=0; i < L->size; i++){
        if(L->mang[i]==x){
            return i;
            break;
        }
    }
    return 0;
}

void Delete_x(List *L, int k){
    for(int i=k; i<L->size; i++){
        L->mang[i]=L->mang[i+1];
    }
    L->size--;
}





