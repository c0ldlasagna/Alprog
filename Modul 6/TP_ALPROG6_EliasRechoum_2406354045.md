# Tugas Pendahuluan Modul 6 - Searching

```
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori
### 1. Jelaskan apa itu searching, jenis-jenisnya, cara kerjanya, dan pengaplikasiannya! <span style="color:red;">(30 Poin)</span>

Searching adalah proses menemukan elemen tertentu dalam kumpulan data. Jenis-jenis searching meliputi:

1. **Linear Search**: Mencari elemen dengan memeriksa setiap elemen satu per satu dari awal hingga akhir. Cara kerjanya sederhana dan tidak memerlukan data terurut.

2. **Binary Search**: Mencari elemen dengan membagi kumpulan data yang terurut menjadi dua bagian dan memeriksa bagian tengah. Jika elemen yang dicari lebih kecil dari elemen tengah, pencarian dilanjutkan pada bagian kiri, sebaliknya pada bagian kanan. Proses ini diulang hingga elemen ditemukan atau tidak ada lagi bagian yang tersisa.

3. **Hash Search**: Menggunakan struktur data hash table untuk mencari elemen dengan cepat berdasarkan kunci unik. Cara kerjanya melibatkan fungsi hash yang memetakan kunci ke indeks dalam tabel.

Pengaplikasian searching sangat luas, termasuk dalam pencarian database, algoritma pencarian teks, dan pencarian dalam struktur data seperti array dan linked list.

### Referensi

- R. Sedgewick and K. Wayne, "Algorithms," 4th ed. Addison-Wesley, 2011.

- T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, "Introduction to Algorithms," 3rd ed. MIT Press, 2009.

---

### 2. Terdapat sebuah data nilai ujian kalkulus yang telah terurut sebagai berikut:
`77 78 83 83 90 98 100`

### Anda diminta untuk membuat program yang akan mencari ada di index ke berapa mahasiswa yang mendapatkan nilai 98. Buatlah dan jelaskan ilustrasi untuk menggambarkan skenario tersebut menggunakan algoritma selain linear search! <span style="color:red;">(30 Poin)</span>

Contoh gambar ilustrasi: 

### Jawab

Untuk mencari index nilai `98` dalam array `77 78 83 83 90 98 100`, kita bisa pakai **Binary Search**. 

Binary search bekerja dengan membagi array yang sudah terurut menjadi dua bagian, lalu membandingkan nilai tengah dengan target.
Jika target lebih kecil, pencarian berlanjut di setengah kiri, jika lebih besar, di setengah kanan. Proses ini terus diulang hingga target ditemukan atau array habis.

![alt text](https://raw.githubusercontent.com/c0ldlasagna/Alprog/refs/heads/master/Modul%206/image.png)

### Referensi:

- GeeksforGeeks, “Binary Search - GeeksforGeeks,” GeeksforGeeks, Apr. 2019. https://www.geeksforgeeks.org/binary-search/
- “DSA Binary Search,” www.w3schools.com. https://www.w3schools.com/dsa/dsa_algo_binarysearch.php

---


## Programming

### Realisasikan skenario ini dalam program bahasa C. Berikan juga analisa terhadap kode yang telah dibuat! <span style="color:red;">(40 Poin)</span>

---

Code Kalian :

```c
#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[],int size,int target){
    int left,right,middle;
    right = size - 1;
    left = 0;
    while (left <= right){
        middle = (left+right)/2;
        if(arr[middle] == target){
            return middle;
        }
        if(arr[middle] > target){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
        }
    return -1;
}

int main(){
    const int size = 7;
    int scores[] = {77, 78, 83, 83, 90, 98, 100};
    int index = binarySearch(scores,size,98);
    printf("%d",index);
    return 0;

}
```

SS Output Program Kalian : 
![alt text](https://raw.githubusercontent.com/c0ldlasagna/Alprog/refs/heads/master/Modul%206/image-1.png)

**Analisa** : 
Kode ini mengimplementasikan algoritma binary search untuk mencari nilai dalam array yang sudah terurut. Fungsi binarySearch menerima tiga parameter: array arr, ukuran array size, dan nilai target yang ingin dicari. Variabel left dan right digunakan untuk menentukan batas pencarian, dengan left diinisialisasi ke indeks pertama dan right ke indeks terakhir. Selama left masih lebih kecil atau sama dengan right, program akan menghitung indeks tengah middle dan membandingkan elemen pada indeks tersebut dengan target. Jika nilainya sama, fungsi langsung mengembalikan indeks tersebut. Jika elemen di middle lebih besar dari target, batas kanan (right) dipindahkan ke kiri (middle - 1), dan jika lebih kecil, batas kiri (left) dipindahkan ke kanan (middle + 1).

Jika pencarian selesai tanpa menemukan target, fungsi akan mengembalikan -1, menandakan bahwa elemen tidak ditemukan dalam array. Fungsi main mendeklarasikan array scores yang berisi nilai yang sudah diurutkan dan kemudian memanggil binarySearch untuk mencari angka 98. Hasilnya akan dikembalikan dalam variabel index dan diprint ke stdout.
