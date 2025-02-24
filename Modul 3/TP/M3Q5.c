#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getName(char* name) //Call by reference
{
    printf("\nMasukkan nama Anda:\n\n");
    fgets(name,50,stdin);
    name[strcspn(name,"\n")] = '\0';
}

void getSum(char* name,int* sum) ///Call by reference
{
    *sum = 0;
    for(int i =0;i<strlen(name);i++){
        *sum += name[i];
    }
    printf("\nValue nama Anda adalah %d",*sum);
}


int main(){
    char name[50],option;
    int sum;

    getName(name);

    while(1){
    printf("\nOpsi (Nama: %s):\n",name);
    printf("a. Value ASCII Nama\nb. Ganti Nama\nc. Exit\n\n");
    scanf(" %c",&option);

    while ((getchar()) != '\n');

    switch (option){
        case 'a':
            getSum(name,&sum);
            break;
        case 'b':
            getName(name);
            break;
        case 'c':
            printf("\nProgram Selesai!\n");
            exit(0);
            break;        
        default:
                printf("\nInvalid Option.\n");
                break;
    }
    } 

    return 0;
}      
