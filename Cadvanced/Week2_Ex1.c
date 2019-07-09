#include <stdio.h>
#include <stdlib.h>

void int_swap(void const *a, void const *b){
    int temp = *((int *)a);
    *((int *)a) = *((int *)b);
    *((int *)b) = temp;
}

int int_compare(void const *x, void const *y){
    int m, n;
    m = *((int *)x);
    n = *((int *)y);
    if(m == n) return 0;
    return m>n ? 1:-1;
}

void quickSort3Ways(void *a, int size, int l, int r, int (*int_compare)(void const*, void const*)) {
    if (r <= l) return;
    int i = l-1, j = r;
    int p = l-1, q = r;
    while(1) {
        while(int_compare((char *)a + (++i)*size, (char *)a + r*size) < 0);
        while(int_compare((char *)a + r*size, (char *)a + (--j)*size) < 0) if (j == l) break;
        if(i > j || i == j) break;
        int_swap((char *)a + i*size, (char *)a + j*size);
        if (int_compare((char *)a + i*size, (char *)a + r*size) == 0) int_swap((char *)a + (++p)*size, (char *)a + i*size);
        if (int_compare((char *)a + j*size, (char *)a + r*size) == 0) int_swap((char *)a + (--q)*size, (char *)a + j*size);
    }
    int_swap((char *)a + i*size, (char *)a + r*size);
    j = i - 1;
    i = i + 1;
    for (int k = l ; k <= p; k++) int_swap((char *)a + k*size, (char *)a + (j--)*size);
    for (int k = r-1; k >= q; k--) int_swap((char *)a + k*size, (char *)a + (i++)*size);
    quickSort3Ways(a, sizeof(int), l, j, int_compare);
    quickSort3Ways(a, sizeof(int), i, r, int_compare);
}

int main(){
    int arr[5];
    for(int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    quickSort3Ways(arr, sizeof(int), 0, 4, int_compare);
    for(int i = 0; i < 5; i++)
        printf("\n%d\t", arr[i]);
    return 0;
}
