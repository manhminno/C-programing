#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randNumber(int arr[], int arr2[]){
    srand(time(NULL));
    for(long i = 0; i < MAX; i++){
        arr[i] = rand()%10;
        arr2[i] = arr[i];
    }
}

void quickSort(int a[], int left, int right){
    long pivot = (left + right)/2;
    pivot = a[pivot];
    int i = left;
    int j = right;
    do{
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i < j || i == j){
            Swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }while(i < j);
    if(left < j) quickSort(a, left, j);
    if(right > i) quickSort(a, i, right);
}

void quickSort3Ways(int a[], int l, int r) {
    if (r <= l) return;
    int i = l-1, j = r;
    int p = l-1, q = r;
    while(1) {
        while(a[++i] < a[r]);
        while(a[r] < a[--j]) if (j == l) break;
        if(i > j || i == j) break;
        Swap(&a[i], &a[j]);
        if (a[i] == a[r]) Swap(&a[++p], &a[i]);
        if (a[j] == a[r]) Swap(&a[--q], &a[j]);
    }
    Swap(&a[i], &a[r]);
    j = i - 1;
    i = i + 1;
    for (int k = l ; k <= p; k++) Swap(&a[k], &a[j--]);
    for (int k = r-1; k >= q; k--) Swap(&a[k], &a[i++]);
    quickSort3Ways(a, l, j);
    quickSort3Ways(a, i, r);
}
int main(){
    int arr[MAX];
    int arr2[MAX];
    randNumber(arr, arr2);
    
    clock_t start = clock();
    quickSort(arr, 0, MAX - 1);
    clock_t finish = clock();
    double time1 = (double)(finish - start)/CLOCKS_PER_SEC;

    start = clock();
    quickSort3Ways(arr, 0, MAX-1);
    finish = clock();
    double time2 = (double)(finish - start)/CLOCKS_PER_SEC;

    printf("Time of quick sort 2 ways: %lf\n", time1);
    printf("Time of quick sort 3 ways: %lf\n", time2);
    return 0;
}