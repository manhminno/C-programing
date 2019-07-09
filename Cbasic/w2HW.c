#include <stdio.h>
#define MAX 100

struct a{
    char name[26];
    char phone[11];
    char email[26];
};
typedef struct a A;

int main(){
    A C[MAX];
    int n;
    FILE *fin;
    scanf("%d", &n);
    int insert;
    scanf("%d", &insert);
//    for(int i = 0; i < size; i++){
//        printf("Name: ");
//        fflush(stdin);
//        gets(List[i].name);
//        printf("Phone: ");
//        gets(List[i].phone);
//        printf("Email: ");
//        gets(List[i].email);
//        printf("\n");
//    }
//    fin = fopen("danhba.dat", "wb");
//    fwrite(List, sizeof(Info), size, fin);
//    fclose(fin);
    fin = fopen("danhba.dat", "rb");
    if(fin == NULL) printf("Fail!\n");
    else{
        if(fseek(fin, (insert-1)*sizeof(A), SEEK_SET) == 0){
            fread(C, sizeof(A), n - insert + 1, fin);
            for(int i = 0; i < n - insert +1; i++){
            printf("%s\n", C[i].name);
            printf("%s\n", C[i].phone);
            printf("%s\n", C[i].email);
            printf("\n");
            }
        }else{
            printf("Fail!\n");
        }
    }
    fclose(fin);
    return 0;
}
