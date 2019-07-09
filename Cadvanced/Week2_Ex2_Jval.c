#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef union myunion{
    int i;
    long l;
    float f;
    double d;
    void *v;
    char *s;
    char c;
} Jval; 

Jval new_jval_i(int i) {
    Jval j;
    j.i = i;
    return j;
}

int jval_i(Jval j) {
    return j.i;
}  

Jval *creat_array_i(int size){
    Jval *arr = (Jval *)malloc(size*sizeof(Jval));
    int tmp;
    for(int i = 0; i < size; i++){
        scanf("%d", &tmp);
        arr[i] = new_jval_i(tmp);
    }
    return arr;
}

void printArr(Jval arr[], int size){
    for(int i = 0; i < size; i++)
        printf("%d\t", jval_i(arr[i]));
}

void Swap(Jval *a, Jval *b){
    Jval temp;
    temp.i = jval_i(*a);
    a->i = jval_i(*b);
    b->i = jval_i(temp);
}

int int_compare(Jval *a, Jval *b){
    if(jval_i(*a) == jval_i(*b)) return 0;
    return jval_i(*a) > jval_i(*b) ? 1:-1;
} 

void quickSort(Jval *a, int left, int right, int (*int_compare)(Jval *, Jval *)){
    int pivot = (left + right)/2;
    pivot = jval_i(a[pivot]);
    Jval temp = new_jval_i(pivot);
    int i = left;
    int j = right;
    do{
        while(int_compare((a + i), &temp) < 0) i++;
        while(int_compare((a + j), &temp) > 0) j--;
        if(i < j || i == j){
            Swap((a + i), (a + j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j) quickSort(a, left, j, int_compare);
    if(right > i) quickSort(a, i, right, int_compare);
}

int main(){
    Jval a;
    Jval *arr;
    int size;

    printf("Size: ");
    scanf("%d", &size);
    arr = creat_array_i(size);
    quickSort(arr, 0, size - 1, int_compare);
    printArr(arr, size);

    return 0;
}
