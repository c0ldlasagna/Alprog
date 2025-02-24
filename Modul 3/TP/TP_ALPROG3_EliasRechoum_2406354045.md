# Tugas Pendahuluan Modul 3 - Pointer

```
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 1.

## Teori

### 1. Apa itu tipe data pointer? Bagaimana cara kita mendeklarasikannya, dan bagaimana cara kita mengambil nilai dari sebuah variabel yang alamatnya ditunjuk oleh pointer? (15 poin)

---

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
---

### 2. Dalam C, kita bisa menjalankan fungsi by reference dan by value. Jelaskan perbedaannya! (10 poin)
`(Note: Base Case dan Recursive Case)`

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 3. Salah satu metode paling umum membuat array dengan size fleksibel/dinamis adalah dengan malloc/calloc. Apakah command-command tersebut? Bagaimana cara pakainya? (15 poin)
`(Note: Setelah selesai memakai malloc/calloc, memori harus dibebaskan (menggunakan free()). Tidak perlu dijelaskan di jawaban, namun penting untuk diingat`
[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

### 4. Bagaimana cara untuk memberikan sebuah array / matrix sebagai argumen dalam fungsi (by reference / pointer)?  (10 poin)

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
---

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

![image](https://github.com/user-attachments/assets/134892ae-6585-46b4-8756-60c0d076a94c)
