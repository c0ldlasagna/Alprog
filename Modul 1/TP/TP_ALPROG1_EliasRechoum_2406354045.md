# Tugas Pendahuluan - Introduction to C

```
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Sebutkan dan jelaskan minimal 10 tipe data dalam bahasa C! (10 poin)

---

| #  | Tipe                 | Size (byte) | Range          | Deskripsi |
|----|----------------------|--------------|--------------------------------|-----------|
| 1  | `char`              | 1            | -128 hingga 127                     | Menyimpan satu karakter dengan kode ASCII. |
| 2  | `unsigned char`     | 1            | 0 hingga 255                        | Menyimpan satu karakter yang non-negatif dalam 1 byte.|
| 3  | `short int` (`short`) | 2          | -32768 hingga 32767                 | Menyimpan bilangan bulat dalam 2 byte. |
| 4  | `int`               | 4            | -2147483648 hingga 2147483647       | Menyimpan bilangan bulat dalam 4 byte, dan bisa negatif. |
| 5  | `unsigned int`      | 4            | 0 hingga 4294967295                 | Menyimpan bilangan bulat dalam 4 byte, tanpa bilangan negatif. |
| 6  | `long int` (`long`) | 4 atau 8     | Tergantung sistem (minimal 32-bit)  | Menyimpan bilangan bulat lebih besar dari `int`, biasanya 64-bit di sistem modern. |
| 7  | `float`             | 4            | 1.2e-38  hingga 3.4e38              | Bilangan floating-point presisi tunggal, digunakan untuk angka desimal dengan presisi terbatas. |
| 8  | `double`            | 8            | 1.7e-308 hingga 1.7e308             | Bilangan floating-point presisi ganda, lebih akurat dibandingkan `float`. |
| 9  | `void`              | 0            | N/A                                 | Menunjukkan tidak ada tipe, digunakan untuk function yang tidak return nilai apapun. |
| 10 | `struct`            | Bervariasi   | N/A                                 | Struktur data kustom yang menyimpan beberapa variabel dengan tipe yang berbeda. |





### Referensi:

- geeksforgeeks, “Data Types in C,” GeeksforGeeks, 30 Jun, 2015. <https://www.geeksforgeeks.org/data-types-in-c/>. [Diakses 9-Feb-2025 ]
- B. W. Kernighan and D. M. Ritchie, The C programming language. Englewood Cliffs, Nj Prentice-Hall, 1991.

---

### 2. Jelaskan apa yang dimaksud dengan #include <math.h> dalam bahasa C! (10 poin)

`#include <math.h>` mengimport fungsi matematika standar yang dapat digunakan untuk melakukan berbagai operasi matematika dalam program C, seperti perhitungan trigonometri, logaritma, eksponensial, dan sebagainya.

Fungsi yang terdapat dalam `<math.h>`, antara lain:

1. Fungsi Trigonometri: `sin()`,`cos()`,`tan()`
2. Fungsi Logaritma: `log()`,`log10()`
3. Fungsi Exponensial: `exp()`,`exp2()`  

### Referensi:

- B. W. Kernighan and D. M. Ritchie, The C programming language. Englewood Cliffs, Nj Prentice-Hall, 1991.
- "C math (math.h) Library Reference,” W3schools.com, 2025. <https://www.w3schools.com/c/c_ref_math.php>. [Diakses 9-Feb-2025]
‌

---

### 3. Jelaskan perbedaan antara for, while, dan do-while loop! (10 poin)

| Jenis Loop      | Kondisi Diperiksa | Eksekusi Pertama |
|-----------------|-------------------|------------------|
| **`for`**       | Sebelum loop | Biasanya digunakan untuk perulangan dengan jumlah iterasi yang diketahui, seperti iterasi index di array. |
| **`while`**     | Sebelum loop | Kode hanya dieksekusi jika kondisi awal true. |
| **`do-while`**  | Setelah loop | Kode selalu dieksekusi minimal sekali, karena kondisi diperiksa setelah eksekusi kode pertama.|

### Referensi:

- “C For Loop,” W3schools.com, 2025. <https://www.w3schools.com/c/c_for_loop.php>. [Diakses 9-Feb-2025]
- “C While Loop,” W3schools.com, 2025. <https://www.w3schools.com/c/c_while_loop.php>. [Diakses 9-Feb-2025]

---

### 4. Jelaskan apa yang menyebabkan terjadinya infinite loop? Hal ini dapat terjadi pada jenis looping statement apa saja? (10 poin)

Infinite loop terjadi karena ada loop yang kondisinya selalu true. Infinite loop bisa terjadi pada looping statement apa saja.

Contohnya:

#### While Loop

```c
#include <stdio.h>

int main(){
  int i = 1
  while(i==1) //Kondisi ini selalu true, jadi infinite loop akan terjadi
  {
    printf("This is an Infinite Loop\n")
  }
}
```

#### For loop

```c
#include <stdio.h>

int main(){
  int i;
  for(i=1;i>0;i++) //i akan selalu lebih besar dari 0, akan terjadi infinite loop.
  {
    printf("This is an Infinite Loop\n");
  }
  return 0;
}
```

#### do while

```c
#include <stdio.h>

int main(){
  int i = 1;
  do{
    printf("This is an infinite loop\n");
  }
  while(i==1); //Kondisi ini selalu true, jadi infinite loop akan terjadi
  return 0;
}
```

### Referensi:

- “Infinite Loop in C - javatpoint,” <www.javatpoint.com.> <https://www.javatpoint.com/infinite-loop-in-c> [Diakses 9-Feb-2025]
‌
- “C For Loop,” W3schools.com, 2025. <https://www.w3schools.com/c/c_for_loop.php>. [Diakses 9-Feb-2025]
- “C While Loop,” W3schools.com, 2025. <https://www.w3schools.com/c/c_while_loop.php>. [Diakses 9-Feb-2025]

---

## Programming

### 1. Buatlah program yang menampilkan output berupa teks "Hello [Nama Anda]!" dalam bahasa C! Cantumkan kode program dan screenshot hasil outputnya! (20 poin)

---

```c
#include <stdio.h>

int main() {
    printf("Hello, Elias!\n");
    return 0;
}
```

[![Output Soal 1](https://i.postimg.cc/bJ8p5YVH/Screenshot-2025-02-09-135954.png)](https://postimg.cc/R3Pk6mBN)

### 2. Himpunan A berisi bilangan 1 - 50 (inklusif) yang habis dibagi 3 dan 5. Dengan **WHILE** loop, buatlah program yang akan print semua elemen dari A, tetapi skip 5 bilangan pertama dari A! Cantumkan kode program dan screenshot hasil outputnya! (20 poin)

---

```c
#include <stdio.h>

int main(){
    int count = 1; // Track our numbers
    int printCount = 0; // Track how many numbers we outputted
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
```

[![Output Soal 2](https://i.postimg.cc/J0zm16Ls/Screenshot-2025-02-09-215058.png)](https://postimg.cc/BLkRpCt3)

### 3. Alien-Drawing? (20 poin)

> Hint: Gunakan for loop.

Buatlah program yang akan menampilkan output suatu shape dengan panjang yang ditentukan oleh user. Program akan menerima input panjang dari user, kemudian program akan menampilkan sebuah shape dengan panjang tersebut. Contoh output program adalah sebagai berikut:

Test Case 1:  
Input:
```bash
1
```

Output:
```bash
*
```

Test Case 2:  
Input:
```bash
2
```

Output:
```bash
  *
* *
  *
```

Test Case 3:  
Input:
```bash
3
```

Output:
```bash
   *
 * *
*  *
 * *
   *
```

Test Case 4:  
Input:
```bash
6
```

Output:
```bash
      *
    * *
   *  *
  *   *
 *    *
*     *
 *    *
  *   *
   *  *
    * *
      *
```

---

```c
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
```


[![Output Soal 3](https://i.postimg.cc/FzCv1yrD/Screenshot-2025-02-09-215530.png)](https://postimg.cc/SY93vzzM)
=======
