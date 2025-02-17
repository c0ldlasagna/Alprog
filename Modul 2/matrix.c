#include <stdio.h>
#include <stdlib.h>

//Function to calculate dot product of two arrays.
int dotProduct(int a[],int b[],int size){
    int product = 0;
    for (int i = 0; i < size; i++) {
        product += a[i] * b[i];
    }
    return product;
}

//Function to transpose a matrix.
int** transpose(int** matrix,int rows,int cols){
    int ** transposed = (int**)malloc(cols*sizeof(int*));
    for (int i=0;i<cols;i++){
        transposed[i] = (int*)malloc(rows*sizeof(int));
    }

    for(int i = 0; i<rows;i++){
        for (int j=0;j<cols;j++ ){
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

//Function to read matrix from user input
void read_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


int main(){
    int rows1,columns1,rows2,columns2;
    printf("Insert Columns of first matrix : ");
    scanf("%d",&columns1);
    printf("Insert Rows of First matrix : ");
    scanf("%d",&rows1);
    printf("Insert Columns of Second matrix : ");
    scanf("%d",&columns2);
    rows2 = columns1;

    // Allocate and read matrix 1 from user
    int ** matrix1 = (int**)malloc(rows1*sizeof(int*));
    for (int i = 0;i<rows1;i++){
        matrix1[i]=(int*)malloc(columns1*sizeof(int));
    }
    printf("Insert matrix 1. (%d Rows and %d Columns) :\n",rows1,columns1);
    read_matrix(matrix1,rows1,columns1);

    // Allocate and read matrix 2 from user
    int ** matrix2 = (int**)malloc(rows2*sizeof(int*));
    for (int i = 0; i<rows2;i++){
        matrix2[i]=(int*)malloc(columns2*sizeof(int));
    }  
    printf("Insert matrix 2. (%d Rows and %d Columns) :\n",rows2,columns2);
    read_matrix(matrix2,rows2,columns2);

    // Transpose matrix2 and store it in matrix2_transposed
    int** matrix2_transposed = transpose(matrix2, rows2, columns2);

    // Store the original matrix2 pointer in temp
    int** temp = matrix2;
    
    // Set matrix2 to the transposed matrix2
    matrix2 = matrix2_transposed;
    
    // Free the original matrix2 (which is now temp)
    for (int i = 0; i < rows2; i++) {
        free(temp[i]);
    }
    free(temp);

    //Allocate memory for result matrix
    int ** result = (int**)malloc(rows1*sizeof(int*));
    for (int i = 0;i<rows1;i++){
        result[i]=(int*)malloc(columns2*sizeof(int));
    }

    //Multiply matrix1 and matrix2 using dotProduct() and store the result in result matrix
    for (int i=0;i<rows1;i++){
        for (int j=0;j<columns2;j++){
            result[i][j] = dotProduct(matrix1[i],matrix2[j],columns1);
        }

    }
    
    printf("Result: \n");
    for (int i = 0;i<rows1;i++){
        for (int j=0;j<columns2;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    
    // Free all the allocated memory
    for (int i = 0;i<rows1;i++){
        free(matrix1[i]);
    }
    for (int i = 0;i<columns2;i++){
        free(matrix2[i]);
    }
    for (int i = 0;i<rows1;i++){
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}