#include <stdio.h>
#include <string.h>

//Function to shift characters by 1
void shift(char string[]){
    for (int i = 0;i<strlen(string);i++){
        string[i] += 1;
    }
}

int main(){
    char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};
    for(int i = 0;i<5;i++){
        shift(hero[i]);
        printf("Hero 1 : %s \n",hero[i]);
    }
    return 0;
}