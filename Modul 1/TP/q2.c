#include <stdio.h>

int main(){
    int count = 1; // Track our numbers
int printCount = 0; //Track how many numbers we outputted
    while (count <= 50)  // Continue loop until we reach 50, then stop
    {
        if (count%3==0 && count%5==0) //Check if number is divisible by 5 and 3
        {
            if(printCount>=5) // Check if we skipped first 5 numbers yet
            {
                printf("%d\n",count); //Output number if all conditions are met. 
                printCount++; //Increment printCount when we print a number
            }
        }    
        count++; //Increment count to go to next number
    }
    return 0;
}