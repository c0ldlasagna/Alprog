#include <stdio.h>
#include <string.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  struct Object {
    char string[100];
    int number;
};

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

void partition(int array[],int start,int end){
    int pivot = array[end];
    int i = start;
    for(int j = start;j<end;j++){
        if(array[j] < pivot){
            swap(&array[j],&array[i]);
            i++;
        }
    }
    swap()
}

int main(){

}