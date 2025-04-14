#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[],int start,int end){
    int pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){
        if(array[j] > pivot){
            i++;
            swap(&array[j],&array[i]);
            continue;
        }    
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSort(int array[],int start,int end){
    if(start<end){
        int pivot = partition(array,start,end);
        quickSort(array,start,pivot-1);
        quickSort(array,pivot+1,end);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%d\n", array[i]);
    }
}

int main(){
    int array[] = {432,643,123,754,213,763,876,156,888};
    quickSort(array,0,4);
    printArray(array,5);
    return 0;
}
