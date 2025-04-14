# Tugas Pendahuluan 7 - Sorting

```txt
Nama  : [Sakiko Togawa]
NPM   : [2300000000]
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

- GeeksforGeeks [Online]. Available: https://www.geeksforgeeks.org/bubble-sort/. [Diakses: 25-Agustus-2024]

- Programiz [Online]. Available: https://www.programiz.com/dsa/insertion-sort. [Diakses: 25-Agustus-2024]

---

### 2. Pilih salah satu dari algoritma sorting berikut: Quick Sort, Merge Sort, dan jelaskan cara kerjanya! Juga, jelaskan perbedaan algoritma ini dengan algoritma sorting pada soal nomor 1! (12 poin)

Merge Sort adalah algoritma divide and conquer. Array dibagi dua secara rekursif hingga hanya tersisa satu elemen, lalu dimerge atau digabungkan kembali dalam urutan yang benar. Proses penggabungan ini dilakukan secara sistematis hingga seluruh array terurut.

Perbedaan dengan Bubble dan Insertion Sort:

- Merge Sort menggunakan pendekatan rekursif dan efisien untuk data besar (kompleksitas waktu O(n log n)).

- Bubble dan Insertion Sort lebih sederhana tapi lambat untuk data besar (kompleksitas O(n²)).

- Merge Sort menggunakan ruang tambahan (karena array baru saat merge), sedangkan Insertion dan Bubble bersifat in-place.

Referensi

- Visualgo [Online]. Available: https://visualgo.net/en/sorting. [Diakses: 25-Agustus-2024]

- GeeksforGeeks [Online]. Available: https://www.geeksforgeeks.org/merge-sort/. [Diakses: 25-Agustus-2024]

---

### 3. Jelaskan secara singkat algoritma sorting selain yang disebutkan pada pertanyaan sebelumnya! (10 poin)

Heap Sort adalah algoritma sorting yang menggunakan struktur data heap (biasanya max-heap). Data diubah menjadi heap, lalu elemen terbesar (root) dipindahkan ke akhir array dan heap diperbaiki. Proses ini diulang sampai array terurut.

Keunggulan Heap Sort:

- Kompleksitas waktu O(n log n)

- Bersifat in-place (tidak butuh ruang tambahan besar)

- Tidak stabil (urutan elemen yang sama bisa berubah)

Referensi

- Programiz [Online]. Available: https://www.programiz.com/dsa/heap-sort. [Diakses: 25-Agustus-2024]

- GeeksforGeeks [Online]. Available: https://www.geeksforgeeks.org/heap-sort/. [Diakses: 25-Agustus-2024]

---

### 4. Jelaskan cara mengurutkan array angka dalam urutan naik dan turun dalam C (12 poin)

[your answer here]

```c
kode Anda di sini
```

#### Referensi

- Contoh Situs [Online]. Available: <https://www.myWebsite.com/ilovedigilab/>. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: <https://www.myWebsite.com/ilovedigilab/>. [Diakses: 25-Agustus-2024]

---

### 5. Jelaskan cara mengurutkan array struct berdasarkan field tertentu (bisa berupa integer atau string) (11 poin)

[your answer here]

```c
kode Anda di sini
```

#### Referensi

- Contoh Situs [Online]. Available: <https://www.myWebsite.com/ilovedigilab/>. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: <https://www.myWebsite.com/ilovedigilab/>. [Diakses: 25-Agustus-2024]

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
// kode Anda di sini
```

![Output Program](https://itsfoss.com/content/images/2023/03/run-c-program-in-linux-with-visual-studio-code.jpg)
