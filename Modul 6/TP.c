#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[],int size,int target){
    int left,right,middle;
    right = size - 1;
    left = 0;
    while (left <= right){
        middle = (left+right)/2;
        if(arr[middle] == target){
            return middle;
        }
        if(arr[middle] > target){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
        }
    return -1;
}

int main(){
    const int size = 7;
    int scores[] = {77, 78, 83, 83, 90, 98, 100};
    int index = binarySearch(scores,size,98);
    printf("%d",index);
    return 0;

}