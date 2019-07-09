#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct _info{
    char name[25];
    char telephone[11];
    char email[25];
} info;

void readFile(FILE *fin, info *PhoneBook){
    int size;
    char c;
    scanf("%d", &size);
    scanf("%c", &c); //loai bo dau xuong dong
    for(int i = 0; i < size; i++){
        gets(PhoneBook[i].name);
        gets(PhoneBook[i].telephone);
        gets(PhoneBook[i].email);
    }
}

void outPut(info PhoneBook[]){
    for(int i = 0; i < 5; i++){
        printf("%s\n", PhoneBook[i].name);
        printf("%s\n", PhoneBook[i].telephone);
        printf("%s\n", PhoneBook[i].email);
        printf("\n");
    }
}

// void swapMem(info *mem1, info *mem2){
//     info temp;
//     temp = *mem1;
//     *mem1 = *mem2;
//     *mem2 = temp;
// }

void merge(info PhoneBook[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    info *temp = (info *)malloc((right - left + 1)*sizeof(info));
    for(int k = 0; k <= right; k++){
        if(strcmp(PhoneBook[i].name, PhoneBook[j].name) > 0){
            temp[k] = PhoneBook[i];
            i++;
        }
        else{
            temp[k] = PhoneBook[j];
            j++;
        }
        if(i == mid + 1){
            while(j <= right){
                k++;
                temp[k] = PhoneBook[j];
                j++;
            }
            break;
        }
        if(j == right + 1){
            while(i <= mid){
                k++;
                temp[k] = PhoneBook[i];
                i++;
            }
            break;
        }
    }
    for(int k = 0; k <= right - left; k++){
        PhoneBook[left + k] = temp[k];
    }
    free(temp);
}


// void quickSort(info *PhoneBook, int left, int right){
//     int pivot = (left + right)/2;
//     char temp[25];
//     strcpy(temp, PhoneBook[pivot].name);
//     int i = left;
//     int j = right;
//     do{
//         while(strcmp(temp, PhoneBook[i].name) < 0) i++;
//         while(strcmp(temp, PhoneBook[i].name) > 0) j--;
//         if(i < j || i == j){
//             swapMem(&PhoneBook[i], &PhoneBook[j]);
//             i++;
//             j--;
//         }
//     }while(i < j);
//     if(left < j) quickSort(PhoneBook, left, j);
//     if(right > i) quickSort(PhoneBook, i, right);
// }

void mergeSort(info PhoneBook[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(PhoneBook, left, mid);
        mergeSort(PhoneBook, mid + 1, right);
        merge(PhoneBook, left, mid, right);
    }
}

int main(){
    info PhoneBook[MAX];
    FILE *fin = freopen("PhoneBook.txt", "r", stdin);
    readFile(fin, PhoneBook);
    // quickSort(PhoneBook, 0, 2);
    mergeSort(PhoneBook, 0, 4);
    outPut(PhoneBook);
    fclose(fin);
    return 0;
}
