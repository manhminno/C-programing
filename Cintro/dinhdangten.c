#include<stdio.h>
#include<string.h>
int CheckSpace(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i]== 32 && s[i+1]== 32)
            return i+1;
    }
    return 0;
}

int CheckLower(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ' ' && s[i+1] > 96)
//            s[i+1] -= 32; /* sua loi khong viet hoa dau ten */
            return i+1;
        if(s[i] > 96 && s[i+1] < 96 && s[i+1] > 64)
//            s[i+1] +=32; /* sua loi viet hoa sai vi tri */
            return i+1;
        if(s[i] < 96 && s[i] > 64 && s[i+1] < 96 && s[i+1] >64 )
//            s[i+1] +=32; /* sua loi viet hoa sai vi tri */
            return i+1;
    }
    if(s[0] > 96)
        s[0] -= 32; /* sua loi khong viet hoa dau ten */
    return 0;
}

void DeleteChar(char s[], int vitri){
    for(int i = vitri; i < strlen(s)-1; i++){
        s[i]=s[i+1];
    }
    s[strlen(s)-1]= '\0';
}

void Adjust(char s[]){
    int check;
    do{
        check = CheckSpace(s);
        DeleteChar(s, check);
    }while(check);
    if(s[0] == 32 ) DeleteChar(s, 0);
    if(s[strlen(s)-1] == ' ') s[strlen(s)-1] = '\0';
    do{
        check = CheckLower(s);
    }while(check);

}
int main(){
    char s[20];
    gets(s);
    Adjust(s);
    printf("%s", s);
}
