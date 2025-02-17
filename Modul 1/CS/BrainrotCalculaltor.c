#include <stdio.h>


int main(){

    int exit, choice,num1,num2,result,i,j,check;
    exit = 0;
    check = 0;
    while(exit == 0 && check != -1){
        printf("\n======MENU=======\n");
        printf("1. Tambah\n");
        printf("2. Kurang\n");
        printf("3. Kali\n");
        printf("4. Quit\n");
        printf("Pilihan: ");
        check = scanf("%d",choice);
            switch(choice){
                case 1:
                    printf("Input angka 1: ");
                    scanf("%d",&num1);
                    printf("Input angka 2: ");
                    scanf("%d",&num2);
                    result = num1 + num2;
                    for(i=1;i<result;i++){
                        printf("*\n");
                    }
                    for(j=0;j<result;j++){
                        printf("*"); 
                    }             
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
        return 0;
    }