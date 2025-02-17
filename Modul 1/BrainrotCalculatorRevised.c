#include <stdio.h>


void printL(int height){
    int i,j;
    for(i=1;i<height;i++){
        printf("*\n");
    }
    for(j=0;j<height;j++){
        printf("*"); 
    }    
}

int* getNumbers(){
    int numbers[2];
    printf("Input angka 1: ");
    scanf("%d", &numbers[0]);
    printf("Input angka 2: ");
    scanf("%d", &numbers[1]);
    return numbers;
}

int getInput()

int main(){

    int exit, choice,num1,num2,result,i,j;
    exit = 0;
    while(exit ==0){
        printf("\n======MENU=======\n");
        printf("1. Tambah\n");
        printf("2. Kurang\n");
        printf("3. Kali\n");
        printf("4. Quit\n");
        printf("Pilihan: ");
        if(scanf("%d",&choice)==1){
            switch(choice){
                case 1:
                    printf("Input angka 1: ");
                    scanf("%d",&num1);
                    printf("Input angka 2: ");
                    scanf("%d",&num2);
                    result = num1 + num2;
                             
                    break;
                case 2:
                printf("Input angka 1: ");
                scanf("%d",&num1);
                printf("Input angka 2: ");
                scanf("%d",&num2);
                result = num1 - num2;
                for(i=1;i<result;i++){
                    printf("*\n");
                }
                for(j=0;j<result;j++){
                    printf("*");   
                }            
                break;
    
                case 3:
                printf("Input angka 1: ");
                    scanf("%d",&num1);
                    printf("Input angka 2: ");
                    scanf("%d",&num2);
                    result = num1 * num2;
                    for(i=1;i<result;i++){
                        printf("*\n");
                    }
                    for(j=0;j<result;j++){
                        printf("*"); 
                    }              
                    break;
                case 4:
                    printf("bye");
                    exit = 1;
                    break;
                    
    
                default:
                    printf("Invalid Input");
    
            }
        }
        
    }
        return 0;
    }