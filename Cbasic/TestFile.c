#include <stdio.h>
#include <string.h>

void Check(char *string){
    for(int i = 0; i < strlen(string); i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i]+= 'a' - 'A';
        }
    }
}

int main(){
    FILE *fin = fopen("test.txt", "r");
    char string[20];
    if(fin == NULL) printf("Error\n");
    else{
        FILE *fout = fopen("test2.txt", "w");
        fgets(string, 20, fin);
        Check(string);
        fputs(string, fout);
        fclose(fin);
        fclose(fout);
        printf("OK!");
    }
    return 0;
}
