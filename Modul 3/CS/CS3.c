#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void getString(char* string) //Call by reference
{
    printf("\nMasukkan String: ");
    fgets(string,50,stdin);
    string[strcspn(string,"\n")] = '\0';
}

void getShift(int* shift){
    printf("Masukkan Jarak Geser: ");
    scanf("%d",shift);
    while ((getchar()) != '\n');
}

void shift(char* string,int* shiftptr){
    printf("\n---\n\n");

    int shift = *shiftptr;
    if(shift != 0){
        for (int i = 0;i<strlen(string);i++){
            int ascii = string[i];
            if (ascii == 32){
                continue;
            }
            if(ascii+shift > 122 || ascii + shift < 65){
                printf("Out of Bounds!");
                return;
            }
            string[i] += shift;
            switch (string[i]){
                case 'A':
                case 'a':
                string[i] = '4';
                break;
    
                case 'E':
                case 'e':
                string[i] = '3';
                break;
    
                case 'I':
                case 'i':
                string[i]= '1';
                break;
    
                case 'O':
                case 'o':
                string[i]='0';
                break;
    
                case 'U':
                case 'u':
                string[i]= 'V';
                break;
            }
        }
    }
    
    printf("String Cipher: %s",string);
}

int main(){
    int* shiftptr;
    char* string;
    printf("Halo Upin & Ipin (dah besar)!");
    getString(string);
    getShift(shiftptr);
    shift(string,shiftptr);
    return 0;
}