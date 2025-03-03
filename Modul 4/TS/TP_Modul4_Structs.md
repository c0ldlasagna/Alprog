# Tugas Pendahuluan Modul 4 - Structs

```
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 1.

## Teori

### 1. Bagaimana cara mendeklarasikan, menginisialisasi, dan mengakses anggota dari sebuah struct?  (15 poin)

---

Struct dideklarasikan menggunakan keyword `struct` dan nama struct dan variable yang disimpan di dalamnya.

#### Contoh: Deklarasi struct `Orang`

```c
#include <stdio.h>

struct Orang{
    char nama[32];
    int usia;
};
```

Menginisialisasikan sebuah `struct` itu seperti menginisialisasikan array atau variable biasa.

#### Contoh: Inisialisasi struct `Orang` ke variable bernama `orang1`

```c
struct Orang orang1 = {"John Doe",25};
```

Untuk mengakses anggota dari `struct`, kita bisa menggunakan **dot operator** ( . ) atau **arrow operator** (->).

#### Dot operator

```c
printf("%d\n",orang1.usia);  // Dot operator
struct Orang *orang1Ptr = &orang1; // Inisialisasi pointer untuk arrow operator
printf("%d",orang1Ptr->usia); // Arrow operator
```

##### Output

```txt
25
25
```

### Referensi:

- W3Schools, “C Structures (structs),” www.w3schools.com. https://www.w3schools.com/c/c_structs.php
-  GeeksforGeeks, “Structures in C,” GeeksforGeeks, Oct. 12, 2014. https://www.geeksforgeeks.org/structures-c/
---

### 2. Jelaskan apa itu nested struct (struct dalam struct) dan bagaimana cara implementasinya! (10 poin)
`(Note: Bisa menggunakan typedef agar struct jadi lebih ringkas)`

*Nested Struct* adalah sebuah struct yang memiliki struct lain sebagai salah satu anggotanya.

Untuk mengimplementasikan nested struct, deklrasikan sebuah struct sebagai anggota dari struct yang lain.

#### Contohnya

```c
#include <stdio.h>

struct Orang{
    struct Biodata{
    char nama[32];
    int usia;
    char tempatLahir[32];
    } biodata;
}
```

### Referensi:

- W3Schools, “C Structures (structs),” www.w3schools.com. https://www.w3schools.com/c/c_structs.php
-  GeeksforGeeks, “Structures in C,” GeeksforGeeks, Oct. 12, 2014. https://www.geeksforgeeks.org/structures-c/

---

### 3. Bagaimana cara mengirimkan struct sebagai parameter ke dalam fungsi (by value dan by reference)? Contohkan dengan singkat! (15 poin)

Untuk mengirimkan struct sebagai parameter ke dalam fungsi, kita hanya perlu masukkan parameter struct yang kita telah buat ke dalam fungsi.

```c
#include <stdio.h>

struct Orang{
    char nama[32];
    int usia;
};

void displayOrang(struct Orang orang) // Pass by value
{
    printf("%s is %d years old. (Pass by value)\n",orang.nama,orang.usia);
}

void displayOrangPtr(struct Orang *orang) // Pass by reference
{
    printf("%s is %d years old. (Pass by reference)\n",orang->nama,orang->usia);
}



int main() {

    struct Orang orang1 = {"John Doe",25};
    struct Orang *orang1Ptr = &orang1;

    displayOrang(orang1);
    displayOrangPtr(orang1Ptr);

    return 0;
}
```


### Referensi:

- W3Schools, “C Structures (structs),” www.w3schools.com. <https://www.w3schools.com/c/c_structs.php>

-  GeeksforGeeks, “Structures in C,” GeeksforGeeks, Oct. 12, 2014. <https://www.geeksforgeeks.org/structures-c/>

### 4. Apakah perbedaan dari metode akses anggota struct lewat titik (.) dibanding dengan panah (->)?  (10 poin)

Dot operator digunakan untuk mengakses anggota dari instansi struct, dan arrow operator digunakan untuk mengakses anggota dari pointer ke instansi struct.

#### Contoh: Deklarasi struct `Orang`

```c
#include <stdio.h>

struct Orang{
    char nama[32];
    int usia;
};

struct Orang orang1 = {"John Doe",25};

int main() {
    printf("%d\n",orang1.usia);  // Dot operator

    struct Orang *orang1Ptr = &orang1;

    printf("%d",orang1Ptr->usia); //Arrow operators

    return 0;
}
```

##### Output

```txt
25
25
```

### Referensi:

- W3Schools, “C Structures (structs),” www.w3schools.com. <https://www.w3schools.com/c/c_structs.php>

-  GeeksforGeeks, “Structures in C,” GeeksforGeeks, Oct. 12, 2014. <https://www.geeksforgeeks.org/structures-c/>

---

## Programming

### 5. Buatlah sebuah program yang dapat memanage data mahasiswa menggunakan array of structs dengan nested structs! (30 poin)
#### Spesifikasi:
- Program akan memberi opsi untuk menambahkan siswa baru atau menampilkan semua siswa yang ada dalam database
- Boleh menggunakan array dengan dynamic memory allocation agar jumlah mahasiswa fleksibel, atau boleh juga menggunakan array dengan size 100 (max 100 mahasiswa)
- Implementasikan nested structs untuk pemisahan data.
* Struct `AkademikInfo` yang berisi:
* Semester (int)
* IPK (float / double)
* Jurusan (string)
Struct `PersonalInfo` yang berisi:
* Nama (string)
* NPM (string)
* Alamat (string)
Struct `Mahasiswa` yang berisi:
* PersonalInfo (struct)
* AkademikInfo (struct)
* Kesibukan (string)


Contoh:
```
Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


1


List Mahasiswa
---------------


Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


2


Add Mahasiswa
---------------
Data Personal:
Nama : Theory
NPM : 2307274500
Alamat : Jl M Kahfi II 
Jurusan : Teknik Elektro
Semester : 4
IPK : 3.88
Kesibukan : Magang di BNI
Mahasiswa ditambahkan!


Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


2


Add Mahasiswa
---------------
Data Personal:
Nama : Hendy Bengkel
NPM : 2408040201
Alamat : Bengkel
Jurusan : Teknik Elektro
Semester : 2
IPK : 2.1
Kesibukan : Bengkel
Mahasiswa ditambahkan!


Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


1


List Mahasiswa
---------------
1. Theory - 2307274500
Alamat: Jl M Kahfi II
Jurusan: Teknik Elektro
Semester 4
IPK 3.88
Kesibukan: Magang di BNI

2. Hendy Bengkel - 2408040201
Alamat: Bengkel
Jurusan: Teknik Elektro
Semester 2
IPK 2.1
Kesibukan: Bengkel
   
   
Database Kuliah
---------------
1. Show Mahasiswa
2. Mahasiswa Baru
3. Exit


3


Program selesai!
```

Kode
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa
{
    struct{
        int semester;
        float ipk;
        char jurusan[32];
    } AcademicInfo;
    struct{
        char nama[32],alamat[64],npm[16];
    } PersonalInfo;
    char kesibukan[32];
} Mahasiswa;

Mahasiswa create() {
    Mahasiswa m;
    printf("Data Personal:\n");

    printf("Nama: ");
    fgets(m.PersonalInfo.nama, 32, stdin);
    m.PersonalInfo.nama[strcspn(m.PersonalInfo.nama, "\n")] = '\0';

    printf("NPM: ");
    fgets(m.PersonalInfo.npm, 32, stdin);
    m.PersonalInfo.npm[strcspn(m.PersonalInfo.npm, "\n")] = '\0';

    printf("Alamat: ");
    fgets(m.PersonalInfo.alamat, 64, stdin);
    m.PersonalInfo.alamat[strcspn(m.PersonalInfo.alamat, "\n")] = '\0';

    printf("Jurusan: ");
    fgets(m.AcademicInfo.jurusan, 32, stdin);
    m.AcademicInfo.jurusan[strcspn(m.AcademicInfo.jurusan, "\n")] = '\0';

    printf("Semester: ");
    scanf("%d", &m.AcademicInfo.semester);

    printf("IPK: ");
    scanf("%f", &m.AcademicInfo.ipk);

    while ((getchar()) != '\n');

    printf("Kesibukan: ");
    fgets(m.kesibukan, 32, stdin);
    m.kesibukan[strcspn(m.kesibukan, "\n")] = '\0';
    printf("Mahasiswa Ditambahkan!\n");
    return m;
}

void display(Mahasiswa m) {
    printf("%s - %s\n", m.PersonalInfo.nama, m.PersonalInfo.npm);
    printf("Alamat: %s\n", m.PersonalInfo.alamat);
    printf("Jurusan: %s\n", m.AcademicInfo.jurusan);
    printf("Semester %d\n", m.AcademicInfo.semester);
    printf("IPK %.2f\n", m.AcademicInfo.ipk);
    printf("Kesibukan: %s\n", m.kesibukan);
}
int main(){
    int capacity = 2; 
    Mahasiswa *list = (Mahasiswa*)malloc(capacity * sizeof(Mahasiswa));
    int count = 0; 
    while(1){
        printf("\nDatabase Kuliah\n---------------\n");
        printf("1. Show Mahasiswa\n2. Mahasiswa Baru\n3. Exit\n\n");
        int option;
        scanf("%d", &option);
        while ((getchar()) != '\n');
        switch (option)
        {
        case 1:
            printf("\nList Mahasiswa\n---------------\n\n");
            for (int i = 0; i < count; i++)
            {
                printf("%d. ", i + 1);
                display(list[i]);
                printf("\n");
            }
            break;
        case 2:
        printf("\nAdd Mahasiswa\n---------------\n");
            if (count == capacity)
            {
                capacity *= 2;
                list = (Mahasiswa*)realloc(list, capacity * sizeof(Mahasiswa));
            }
            list[count++] = create();
            break;
        case 3:
            printf("\nProgram selsai!\n");
            free(list);
            return 0;
        default:
            break;
        }
    }
    return 0;   
}
```

SS Output Program Kalian :
![image](https://github.com/user-attachments/assets/bb23d5cd-b0ee-4629-b6ee-cd87aa3d9718)
