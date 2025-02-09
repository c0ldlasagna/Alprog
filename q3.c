#include <stdio.h>

int main(){
    int length,i,j; // Initialize variables
    printf("Insert length of shape: ");
    scanf("%d",&length); //Get length from user input
    for (j = 0; j < length; j++) // Controls lines for first half
    {
        for (i = 0; i <= length; i++) // Controls dots for first half
        {
            if (i==length-j-1 || i==length-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for (j = length-2; j >=0; j--) //Controls lines for second half
    {
        for (i = 0; i <= length; i++) //Controls dots for second half
        {
            if (i==length-j-1 || i==length-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}