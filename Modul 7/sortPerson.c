#include <stdio.h>

typedef struct Person{
    char name[100];
    int age;
}Person;

void swap(Person *x, Person *y){
    Person temp = *x;
    *x = *y;
    *y = temp;
}

int partitionPersonAge(Person array[],int start,int end){
    Person pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){
        if(array[j].age < pivot.age){ //Kondisi untuk mengurutkan berdasarkan Person.age secara naik
            i++;
            swap(&array[j],&array[i]);
            continue;
        }    
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSortPerson(Person array[],int start,int end){
    if(start<end){
        int pivot = partitionPersonAge(array,start,end);
        quickSortPerson(array,start,pivot-1);
        quickSortPerson(array,pivot+1,end);
    }
}

void printArrayPerson(Person array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%s %d\n", array[i].name,array[i].age);
    }
}

int main(){
    Person Persons[] = {{"Alex",54},{"Bob",33},{"Charlie",19},{"David",65},{"Edward",27}};
    quickSortPerson(Persons,0,4);
    printArrayPerson(Persons,5);
    return 0;
}
