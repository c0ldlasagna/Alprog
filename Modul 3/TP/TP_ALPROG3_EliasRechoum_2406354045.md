# Tugas Pendahuluan Modul 3 - Pointer

```
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 1.

## Teori

### 1. Apa itu tipe data pointer? Bagaimana cara kita mendeklarasikannya, dan bagaimana cara kita mengambil nilai dari sebuah variabel yang alamatnya ditunjuk oleh pointer? (15 poin)

---

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain.

Ada 2 operator penting yang akan kita gunakan dalam konsep pointer, yaitu:

1. Operator *dereference* (*) digunakan untuk mendeklarasikan variabel penunjuk dan mengakses value yang disimpan di alamat memori.
2. Operator *address* (&) digunakan untuk mengembalikan alamat memori suatu variabel atau untuk mengakses alamat memori suatu variabel ke suatu pointer.

### Referensi:

- “C Pointers,” GeeksforGeeks, Dec. 15, 2016. https://www.geeksforgeeks.org/c-pointers/
---

### 2. Dalam C, kita bisa menjalankan fungsi by reference dan by value. Jelaskan perbedaannya! (10 poin)
`(Note: Base Case dan Recursive Case)`

Pass-by-value adalah cara menggunakan fungsi dengan memasukkan value dari variable ke dalam argument dari sebuah function. Ini tidak memungkinkan fungsi mengganti value dari variable tersebut, karena variable asli tidak dapat diakses langsung.

Pass-by-reference adalah cara menggunakan fungsi dengan memasukkan memory address dari sebuah variable ke dalam argument dari sebuah function. Ini memungkinkan fungsi mengganti value dari variable tersebut, karena variable asli  dapat diakses langsung.


### Referensi:

- GeeksForGeeks, “Difference between Call by Value and Call by Reference,” GeeksforGeeks, Dec. 26, 2018. https://www.geeksforgeeks.org/difference-between-call-by-value-and-call-by-reference/

---

### 3. Salah satu metode paling umum membuat array dengan size fleksibel/dinamis adalah dengan malloc/calloc. Apakah command-command tersebut? Bagaimana cara pakainya? (15 poin)
`(Note: Setelah selesai memakai malloc/calloc, memori harus dibebaskan (menggunakan free()). Tidak perlu dijelaskan di jawaban, namun penting untuk diingat`

malloc() dan calloc() adalah fungsi untuk mengalokasi memori secara dinamis.

### `malloc(size)`:
malloc() digunakan untuk mengalokasikan `size` byte memori ke sebuah pointer. `malloc()` tidak menginisialisasikan memori.

#### Cara pakai malloc() untuk mengalokasi memori untuk array integer yang punya 5 item:

```c
int* arr = (int*)malloc(5*sizeof(int));
```
### `calloc(n,size)`
calloc() digunakan untuk mengalokasikan `size` byte memori ke sebuah pointer. Ia mengambil dua argumen, `n`, yaitu jumlah elemen, dan `size`, yaitu ukuran salah satu elemen tersebut. `calloc()` menginisialisasi memori dengan nilai 0.

#### Cara pakai calloc() untuk mengalokasi memori untuk array integer yang punya 5 item:

```c
int* arr = (int*)calloc(5,sizeof(int));
```

### Referensi:

- GeeksforGeeks, “Dynamic memory allocation in C using malloc(), calloc(), free() and realloc(),” GeeksforGeeks, Dec. 13, 2018. https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

### 4. Bagaimana cara untuk memberikan sebuah array / matrix sebagai argumen dalam fungsi (by reference / pointer)?  (10 poin)

Untuk memberikan sebuah array/matrix sebagai argumen ke dalam sebuah fungsi, kita mendeklarasi parameter yang memiliki type pointer atau double pointer sama ukurannya (jika perlu).

#### Contohnya:

```c
void printArray(int* array,int size){
    for(int i = 0;i<size;i++){
        printf("%d",array[i]);
    }
}
```

### Referensi:

- “C - Pointer to Pointer (Double Pointer),” GeeksforGeeks, Apr. 09, 2017. https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/

## Programming

### 5. Buatlah sebuah program yang terdiri atas 2 part. Pertama, program akan meminta nama awal user, lalu memberi user 3 pilihan.

#### a. Hitung Value ASCII Nama (20 poin)
`Note: Bisa langsung memakai typecast`

`Note2: Penghitungan wajib menggunakan function yang menerima array nama, dan pakai call by reference`

#### b. Ganti Nama (30 poin)
`Note: Untuk memudahkan soal ini, gunakan malloc untuk mengganti size array nama (jika panjang berbeda).` 

`Gunakan 1 array tetap untuk nama user`

(dan c. Exit program)

Contoh:
```
Masukkan nama Anda:

Budiwir

Opsi (Nama: Budiwir):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

a

Value nama Anda adalah 468

Opsi (Nama: Budiwir):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

b

Masukkan nama baru:

Budi

Opsi (Nama: Budi):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

a

Value nama Anda adalah 250

Opsi (Nama: Budi):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

b

Masukkan nama baru:

goronggorong

Opsi (Nama: goronggorong):
a. Value ASCII Nama
b. Ganti Nama
c. Exit

c

Program Selesai!
```
Penjelasan:
a. ASCII
- Budiwir = B u d i w i r (Cek ASCII table)
![image](https://hackmd.io/_uploads/HyWhBEIq1e.png)
- Budiwir = 42 + 75 + 64 + 69 + 77 + 69 + 72
- Budiwir = 468
- Budi = 42 + 75 + 64 + 69
- Budi = 250

**Note: C bisa mengubah char ke integer secara otomatis, jadi tidak perlu membuat fungsi khusus untuk menghitung nilai ASCII, cukup typecasting saja dari char ke int.**

b. Ganti Nama
Untuk bagian ini, array diharuskan **sama** untuk nama (tidak membuat array baru tiap kali nama diubah).
**Note: Malloc/Calloc bisa digunakan untuk langsung mengubah size array, sehingga dapat memudahkan perubahan nama**.

Code Kalian:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getName(char* name) //Call by reference
{
    printf("\nMasukkan nama Anda:\n\n");
    fgets(name,50,stdin);
    name[strcspn(name,"\n")] = '\0';
}

void getSum(char* name,int* sum) ///Call by reference
{
    *sum = 0;
    for(int i =0;i<strlen(name);i++){
        *sum += name[i];
    }
    printf("\nValue nama Anda adalah %d",*sum);
}


int main(){
    char name[50],option;
    int sum;

    getName(name);

    while(1){
    printf("\nOpsi (Nama: %s):\n",name);
    printf("a. Value ASCII Nama\nb. Ganti Nama\nc. Exit\n\n");
    scanf(" %c",&option);

    while ((getchar()) != '\n');

    switch (option){
        case 'a':
            getSum(name,&sum);
            break;
        case 'b':
            getName(name);
            break;
        case 'c':
            printf("\nProgram Selesai!\n");
            exit(0);
            break;        
        default:
                printf("\nInvalid Option.\n");
                break;
    }
    } 

    return 0;
}      
```

SS Output Program Kalian :

![Output](https://github.com/user-attachments/assets/134892ae-6585-46b4-8756-60c0d076a94c)
