# Tugas Pendahuluan Modul 2 - Array and Function

```
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Jelaskan apa itu array dan keuntungan menggunakan array dibandingkan dengan variabel biasa! (10 poin)

---

Array merupakan struktur data yang digunakan untuk menyimpan sekumpulan data dalam satu tempat.

Salah satu keuntungan array dibandingkan variable biasa adalah array bisa menyimpan beberapa variabel di dalamnya. Misalkan, sebuah koleksi integer atau string dapat disimpan dalam satu array, dibandingkan di define di beberapa variable.

### Referensi:

- “C Arrays,” GeeksforGeeks, May 14, 2015. <https://www.geeksforgeeks.org/c-arrays>

- “Belajar Pemrograman C #10: Mengenal Struktur Data Array pada C,” Petani Kode, May 18, 2019. <https://www.petanikode.com/c-array>

---

### 2. Jelaskan apa yang dimaksud dengan array 1D dan 2D serta jelaskan perbedaan keduanya! (10 poin)

Sebuah 1D Array adalah array yang punya satu dimensi.

#### Contohnya:

```c
int arr[]={1,2,3,4}
```

Sebuah Array 2D adalah array yang punya dua dimensi, yaitu array di dalam sebuah array. Biasanya digunakan untuk mendefinisikan matrix, dengan setiap array di dalam array merepresentasikan baris dalam bentuk *row-major*, atau kolom dalam bentuk *column-major*.

```c
int arr[][] = {{1,2,3,4},{5,6,7,8}}
```

### Referensi:

- “C Arrays,” GeeksforGeeks, May 14, 2015. <https://www.geeksforgeeks.org/c-arrays>

- “Belajar Pemrograman C #10: Mengenal Struktur Data Array pada C,” Petani Kode, May 18, 2019. <https://www.petanikode.com/c-array>

---

### 3. Jelaskan apa itu function dan bagaimana cara penggunaannya! (10 poin)

A function in C is a set of statements that when called perform some specific tasks. It is the basic building block of a C program that provides modularity and code reusability.

Sebuah function adalah blok kode yang bisa di call untuk dijalankan beberapa kali. Untuk menggunakan fungsi, kita harus deklarasi, didefinisikan terus memanggilnya.

#### Contohnya:

```c
#include <stdio.h>

void function() //Deklarasi
{ //Definisi
    printf("This is a function");
}

int main(){
    function(); //Function call
    return 0;
}
```

### Referensi:

- “C - Functions,” GeeksforGeeks, Oct. 09, 2022. <https://www.geeksforgeeks.org/c-functions>

- “C - Functions - Tutorialspoint,” Tutorialspoint.com, 2019. <https://www.tutorialspoint.com/cprogramming/c_functions.htm>

### 4. Jelaskan perbedaan antara pass-by-value dan pass-by-reference! serta jelaskan juga apa yang dimaksud dengan scope variabel dalam function (10 poin)

Pass-by-value adalah cara menggunakan fungsi dengan memasukkan value dari variable ke dalam argument dari sebuah function.

Pass-by-reference adalah cara menggunakan fungsi dengan memasukkan memory address dari sebuah variable ke dalam argument dari sebuah function.

Yang dimaksudkan dari "Variable Scope" adalah fungsi-fungsi yang bisa mengakses sebuah variable. 

Jika variable di definisikan dalam sebuah fungsi, maka hanya fungsi itu akan bisa mengakses variable itu.

Jika variable di definisikan di luar fungsi, maka semua fungsi akan bisa mengakses variable itu.

#### Contohnya:

```c
#include <stdio.h>

int globalVar = 1; //Ini adalah variable global, yang dapa diakses oleh semua fungsi

void passByReference(int* a) //For a pass-by-reference function, we pass the pointer to a value instead of it's value.
{
    printf("This is a pass by reference function. A is %d",*a)// We use the dereference operator (*) to access the value of the pointer.
}

void passByValue(int a) //Since this is a pass-by-value function, we pass the value directly into the parameters of the function.
{
    printf("This is a pass by value function. A is %d",a)
}

int main(){
    passByReference(&globalVar); //Since global var is declared outside any functions, any function in the program can access it.
    passByValue(globalVar);
    return 0;
}
```

### Referensi:

- “Pass By Reference In C,” GeeksforGeeks, Oct. 19, 2023. <https://www.geeksforgeeks.org/pass-by-reference-in-c/>

- bhojas, “Pass by Value in C - Sanfoundry,” Sanfoundry, Feb. 14, 2013. <https://www.sanfoundry.com/c-program-pass-by-value/>

- “Scope rules in C,” GeeksforGeeks, Dec. 30, 2011. <https://www.geeksforgeeks.org/scope-rules-in-c/>

---

## Programming

### 1. Buatlah program yang akan melakukan perkalian pada 2 buah matrix yang diinput oleh user. Gunakan juga function minimal 2 untuk mempermudah perhitungan matrix. (30 poin)

---

#### Contoh output yg benar: 

```
Input matrix 1 :
3 4
2 1

Input matrix 2 :
2 3
4 7

Hasil perkalian :
22 37
8 13
```


Code Kalian :

```c
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
```

SS Output Program Kalian : 
![Output of Matrix Multiplication](https://raw.githubusercontent.com/c0ldlasagna/Alprog/refs/heads/master/Modul%202/TP/matrixmult.png)



### 2. Buatlah sebuah program yang mengenkripsi isi dari array berikut dengan melakukan shifting sebanyak 1 kali. (30 poin)

Contoh shifting ```a --> b```, ```b --> c```, dst.

```
char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};
```

#### Contoh output yg benar: 

```
Hero 1: hvtjpo
Hero 2: gbooz
Hero 3: zjo
Hero 4: kpiotpo
Hero 5: obob
```


---

Code Kalian :

```c
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
    
    //Iterate over strings in array
    for(int i = 0;i<5;i++){
        shift(hero[i]);
        printf("Hero 1 : %s \n",hero[i]);
    }
    return 0;
}
```

SS Output Program Kalian :

![Output of shifting](https://raw.githubusercontent.com/c0ldlasagna/Alprog/refs/heads/master/Modul%202/TP/shift.png)
