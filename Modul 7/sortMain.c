#include <stdio.h>
#include <string.h>

typedef struct Object {
    char string[100];
    int number;
}Object;

void swap(Object *x, Object *y){
    Object temp = *x;
    *x = *y;
    *y = temp;
}

int strToInt(char * word){
    if(strcmp(word, "one") == 0) return 1;
    if(strcmp(word, "two") == 0) return 2;
    if(strcmp(word, "three") == 0) return 3;
    if(strcmp(word, "four") == 0) return 4;
}

struct Object objects[] = {
    {"one", 4},
    {"two", 3},
    {"one", 2},
    {"three", 1},
    {"two", 5},
    {"three", 6},
    {"four", 1}
};

int partitionObjects(Object array[],int start,int end){
    Object pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){
        if(strToInt(array[j].string) < strToInt(pivot.string)){
            i++;
            swap(&array[j],&array[i]);
            continue;
        }
        if(strToInt(array[j].string) == strToInt(pivot.string)){
            if(array[j].number>pivot.number){
                i++;
                swap(&array[j],&array[i]);
            }
        }
        
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSortObjects(Object array[],int start,int end){
    if(start<end){
        int pivot = partitionObjects(array,start,end);
        quickSortObjects(array,start,pivot-1);
        quickSortObjects(array,pivot+1,end);
    }
}

void printArrayObjects(Object array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%s %d\n", array[i].string,array[i].number);
    }
    printf("\n");
  }

int main(){
    quickSortObjects(objects,0,6);
    printArrayObjects(objects,7);
}