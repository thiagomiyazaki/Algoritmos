#include <stdio.h>

int partition(int lb, int ub, int arr[]){
    int a = arr[lb];
    int up = ub, down = lb;
    int temp;
    while(down < up){
        while(arr[down] <= a && down < ub){
            down++;
        }
        while(arr[up] > a){
            up--;
        }
        if(down < up){
            temp = arr[down];
            arr[down] = arr[up];
            arr[up] = temp;
        }
    }
    arr[lb] = arr[up];
    arr[up] = a;
    return up;
}

void quicksort(int lb, int ub, int arr[]){
    int aux;
    if(lb > ub)
        return;
    else{
        aux = partition(lb, ub, arr);
        quicksort(lb, aux-1, arr);
        quicksort(aux+1, ub, arr);
    }
}

void printarray(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    puts(" ");
}

int main(){
    int A[10] = {10, 8, 9, 7, 5, 3, 6, 4, 2, 1};
    quicksort(0, 9, A);
    printarray(A, 10);
}