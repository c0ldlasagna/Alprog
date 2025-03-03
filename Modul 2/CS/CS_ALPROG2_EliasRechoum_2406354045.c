#include <stdio.h>
#include <stdlib.h>


void add(float** matrix,int size){
    for(int i = 0; i<size;i++){
        for(int j=0; j<size;j++){
            if(j<=i){
                continue;
            }
            matrix[i][j] += 0.3;
        }
    }

}

void subtract(float** matrix,int size){
    for(int i = 0; i<size;i++){
        for(int j=0; j<size;j++){
            if(j>=i){
                continue;
            }
            matrix[i][j] -= 0.2;
        }
    }
}

void multiply(float** matrix,int size){
    for(int i = 0; i<size;i++){
        for(int j=0; j<size;j++){
            if(j!=i){
                continue;
            }
            matrix[i][j] *= 2;
        }
    }
}

float** transpose(float** matrix,int size){
    float ** transposed = (float**)malloc(size*sizeof(float*));
    for (int i=0;i<size;i++){
        transposed[i] = (float*)malloc(size*sizeof(float));
    }
    for(int i = 0; i<size;i++){
        for (int j=0;j<size;j++ ){
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

void read_matrix(float** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%g", &matrix[i][j]);
        }
    }
}

int main(){


    int size;
    printf("Insert Size of matrix: ");
    scanf("%d",&size);

    float ** matrix = (float**)malloc(size*sizeof(float*));
    for (int i = 0;i<size;i++){
        matrix[i]=(float*)malloc(size*sizeof(float));
    }

    float ** result = (float**)malloc(size*sizeof(float*));
    for (int i = 0;i<size;i++){
        matrix[i]=(float*)malloc(size*sizeof(float));
    }

    printf("Insert matrix 1. Size: %d :\n",size);
    read_matrix(matrix,size);

    add(matrix,size);
    subtract(matrix,size);
    multiply(matrix,size);
    result = transpose(matrix,size);

    printf("Result: \n");
    for (int i = 0;i<size;i++){
        for (int j=0;j<size;j++){
            printf("%.2g  ",result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0;i<size;i++){
        free(matrix[i]);}
    for (int i = 0;i<size;i++){
        free(result[i]);
    }
    free(matrix);
    free(result);
    return 0;
}