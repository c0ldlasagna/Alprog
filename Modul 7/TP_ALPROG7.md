# Tugas Pendahuluan 7 - Sorting

```txt
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Catatan: Soal Programming tidak perlu mencantumkan referensi, hanya soal Teori saja yang memerlukan referensi minimal 2.

## Teori

### 1. Pilih dua dari algoritma sorting berikut: Bubble Sort, Selection Sort, Insertion Sort, dan jelaskan cara kerjanya! Juga, jelaskan perbedaan di antara mereka! (15 poin)

Bubble Sort bekerja dengan cara membandingkan pasangan elemen yang berdekatan dan menukarnya jika urutannya salah. Proses ini diulang terus-menerus hingga tidak ada lagi elemen yang perlu ditukar. Intinya, elemen terbesar "menggelembung" ke akhir array setiap iterasi.

Insertion Sort menyusun dari indeks ke-1 dibandingkan ke kiri dan disisipkan di posisi yang tepat. Ini terus dilakukan sampai seluruh array tersusun.

Perbedaan:

- Bubble Sort membandingkan dan menukar setiap pasangan berdekatan, sedangkan Insertion Sort menyisipkan elemen di posisi satu per satu.

- Insertion Sort cenderung lebih efisien pada data yang hampir terurut.

- Bubble Sort melakukan banyak pertukaran; Insertion Sort lebih hemat pertukaran.

Referensi

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/bubble-sort/>. [Diakses: 14-04-2025]

- Programiz [Online]. Available: <https://www.programiz.com/dsa/insertion-sort>. [Diakses: 14-04-2025]

---

### 2. Pilih salah satu dari algoritma sorting berikut: Quick Sort, Merge Sort, dan jelaskan cara kerjanya! Juga, jelaskan perbedaan algoritma ini dengan algoritma sorting pada soal nomor 1! (12 poin)

Quick Sort adalah algoritma sorting yang menggunakan pendekatan divide and conquer. Prosesnya melibatkan pemilihan elemen acuan yang disebut pivot, kemudian array dibagi menjadi dua bagian: elemen yang lebih kecil dari pivot dan elemen yang lebih besar dari pivot. Proses ini dilakukan secara rekursif hingga seluruh array terurut.

Langkah-langkah Quick Sort:

- Pilih pivot: Pilih satu elemen dari array sebagai pivot (misalnya, elemen terakhir).

- Partisi: Susun ulang elemen sehingga semua elemen yang lebih kecil dari pivot berada di sebelah kiri, dan yang lebih besar di sebelah kanan.

- Rekursi: Terapkan langkah 1 dan 2 secara rekursif pada sub-array di kiri dan kanan pivot hingga seluruh array terurut.

Perbedaan dengan Bubble dan Insertion Sort:

- Efisiensi: Quick Sort memiliki kompleksitas waktu rata-rata O(n log n), sedangkan Bubble dan Insertion Sort memiliki kompleksitas waktu O(n²), sehingga Quick Sort lebih efisien untuk dataset besar.

- Pendekatan: Quick Sort menggunakan pendekatan rekursif dan partisi, sementara Bubble dan Insertion Sort menggunakan pendekatan iteratif dan in-place.

- Penggunaan ruang: Quick Sort dapat diimplementasikan secara in-place tanpa memerlukan ruang tambahan yang signifikan, berbeda dengan Merge Sort yang memerlukan ruang tambahan untuk array sementara.

Referensi:

- Visualgo [Online]. Available: <https://visualgo.net/en/sorting>. [Diakses: 14-04-2025]

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/quick-sort-algorithm/>. [Diakses: 14-04-2025]

---

### 3. Jelaskan secara singkat algoritma sorting selain yang disebutkan pada pertanyaan sebelumnya! (10 poin)

Heap Sort adalah algoritma sorting yang menggunakan struktur data heap (biasanya max-heap). Data diubah menjadi heap, lalu elemen terbesar (root) dipindahkan ke akhir array dan heap diperbaiki. Proses ini diulang sampai array terurut.

Keunggulan Heap Sort:

- Kompleksitas waktu O(n log n)

- Bersifat in-place (tidak butuh ruang tambahan besar)

- Tidak stabil (urutan elemen yang sama bisa berubah)

Referensi

- Programiz [Online]. Available: <https://www.programiz.com/dsa/heap-sort>. [Diakses: 14-04-2025]

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/heap-sort/>. [Diakses: 14-04-2025]

---

### 4. Jelaskan cara mengurutkan array angka dalam urutan naik dan turun dalam C (12 poin)

Dengan menggunakan algoritma *Quick Sort*, kita dapat mengurutkan angka naik dan turun dengan mengganti kondisi swap di function sort.

Untuk urutan naik:

```c
#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[],int start,int end){
    int pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){ //Kondisi untuk urutan naik
        if(array[j] < pivot){
            i++;
            swap(&array[j],&array[i]);
            continue;
        }    
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSort(int array[],int start,int end){
    if(start<end){
        int pivot = partition(array,start,end);
        quickSort(array,start,pivot-1);
        quickSort(array,pivot+1,end);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%d\n", array[i]);
    }
}

int main(){
    int array[] = {432,643,123,754,213,763,876,156,888};
    quickSort(array,0,4);
    printArray(array,5);
    return 0;
}

```

Output:

```txt
123
213
432
643
754
```

Untuk urutan turun:

```c
#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[],int start,int end){
    int pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){
        if(array[j] > pivot){ //Kondisi untuk urutan turun
            i++;
            swap(&array[j],&array[i]);
            continue;
        }    
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSort(int array[],int start,int end){
    if(start<end){
        int pivot = partition(array,start,end);
        quickSort(array,start,pivot-1);
        quickSort(array,pivot+1,end);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%d\n", array[i]);
    }
}

int main(){
    int array[] = {432,643,123,754,213,763,876,156,888};
    quickSort(array,0,4);
    printArray(array,5);
    return 0;
}

```

Output:

```txt
754
643
432
213
123
```

#### Referensi

- Visualgo [Online]. Available: <https://visualgo.net/en/sorting>. [Diakses: 14-04-2025]

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/quick-sort-algorithm/>. [Diakses: 14-04-2025]

---

### 5. Jelaskan cara mengurutkan array struct berdasarkan field tertentu (bisa berupa integer atau string) (11 poin)

Untuk mengurutkan array struct berdasarkan field tertentu, kita hanya perlu compare attribute tersebut pada algoritma sort, contohnya, untuk mengurutkan struct Person berdasarkan usianya:

```c
#include <stdio.h>

typedef struct Person{
    char name[100];
    int age;
}Person;

void swap(Person *x, Person *y){
    Person temp = *x;
    *x = *y;
    *y = temp;
}

int partitionPersonAge(Person array[],int start,int end){
    Person pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){
        if(array[j].age < pivot.age){ //Kondisi untuk mengurutkan berdasarkan Person.age secara naik
            i++;
            swap(&array[j],&array[i]);
            continue;
        }    
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSortPerson(Person array[],int start,int end){
    if(start<end){
        int pivot = partitionPersonAge(array,start,end);
        quickSortPerson(array,start,pivot-1);
        quickSortPerson(array,pivot+1,end);
    }
}

void printArrayPerson(Person array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%s %d\n", array[i].name,array[i].age);
    }
}

int main(){
    Person Persons[] = {{"Alex",54},{"Bob",33},{"Charlie",19},{"David",65},{"Edward",27}};
    quickSortPerson(Persons,0,4);
    printArrayPerson(Persons,5);
    return 0;
}
```

Output:

```txt
Charlie 19
Edward 27
Bob 33
Alex 54
David 65
```



#### Referensi

- Visualgo [Online]. Available: <https://visualgo.net/en/sorting>. [Diakses: 14-04-2025]

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/quick-sort-algorithm/>. [Diakses: 14-04-2025]

---

## Pemrograman (40 poin)

> Masukkan screenshot layar output kode Anda di tempat yang disediakan.

### Mengurutkan Struct dengan Urutan String Custom

Sebuah objek berisi string dan integer. Anda perlu mengurutkan objek berdasarkan string dalam urutan naik. Jika string sama, maka urutkan berdasarkan integer dalam urutan turun.

Sebagai contoh, array objek adalah:

```c
struct Object {
    char string[100];
    int number;
};

---

struct Object objects[] = {
    {"one", 4},
    {"two", 3},
    {"one", 2},
    {"three", 1},
    {"two", 5},
    {"three", 6}
    {"four", 1}
};
```

> Jika kita mengurutkan string secara alfabetis, kita mendapatkan: `four, one, three, two`. Kita ingin mengurutkan string `one, two, three, four`, jadi kode Anda perlu mengurutkan objek berdasarkan urutan string custom.

Output yang diharapkan adalah:

```c
one 4
one 2
two 5
two 3
three 6
three 1
four 1
```

> **Catatan:** ubah `object` ke nama lain yang menurut Anda lebih sesuai, juga ubah string dan integer ke nama yang tepat, dan ubah urutan string custom agar sesuai dengan kasus spesifik Anda.
> Sebagai contoh `one, two, three, four` dapat diubah menjadi `apple, banana, cherry, date` dan Objects dapat diubah menjadi `Fruits`, dll. Jangan lupa untuk mengubah nama struct dan nama variabel.

---

### Jawaban Anda

```c
#include <stdio.h>
#include <string.h>

typedef struct Object {
    char string[100];
    int number;
}Object;

void swap(Object *x, Object *y){
    Object temp = *x;
    *x = *y;
    *y = temp;
}

int strToInt(char * word){
    if(strcmp(word, "one") == 0) return 1;
    if(strcmp(word, "two") == 0) return 2;
    if(strcmp(word, "three") == 0) return 3;
    if(strcmp(word, "four") == 0) return 4;
}

struct Object objects[] = {
    {"one", 4},
    {"two", 3},
    {"one", 2},
    {"three", 1},
    {"two", 5},
    {"three", 6},
    {"four", 1}
};

int partitionObjects(Object array[],int start,int end){
    Object pivot = array[end];
    int i = start-1;
    for(int j = start;j<end;j++){
        if(strToInt(array[j].string) < strToInt(pivot.string)){
            i++;
            swap(&array[j],&array[i]);
            continue;
        }
        if(strToInt(array[j].string) == strToInt(pivot.string)){
            if(array[j].number>pivot.number){
                i++;
                swap(&array[j],&array[i]);
            }
        }
        
    }
    swap(&array[i+1],&array[end]);
    return(i+1);
}

void quickSortObjects(Object array[],int start,int end){
    if(start<end){
        int pivot = partitionObjects(array,start,end);
        quickSortObjects(array,start,pivot-1);
        quickSortObjects(array,pivot+1,end);
    }
}

void printArrayObjects(Object array[], int size){
    for (int i = 0; i < size; ++i) {
      printf("%s %d\n", array[i].string,array[i].number);
    }
    printf("\n");
  }

int main(){
    quickSortObjects(objects,0,6);
    printArrayObjects(objects,7);
}
```

![Output Program](https://raw.githubusercontent.com/c0ldlasagna/Alprog/refs/heads/master/Modul%207/image.png)
