# Tugas Pendahuluan Modul 8

```
Nama  : [your name here]
NPM   : [your NPM here]
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

## Teori

### 1. Jelaskan apa itu class dan object. Berikan contoh penggunaan class dan object serta tunjukkan bagian mana yang merupakan class ataupun object dalam bahasa pemrograman C++! (10 poin)

---

[your answer here]

```cpp
// your code here
```

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 2. Jelaskan apa itu constructor. Berikan contoh penggunaan constructor dalam bahasa pemrograman C++! (10 poin)

[your answer here]

```cpp
// your code here
```

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 3. Jelaskan apa itu encapsulation dan manfaatnya sebagai salah satu konsep OOP! Berikan contoh kode encapsulation dalam C++! (10 poin)

[your answer here]

```cpp
// your code here
```

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 4. Jelaskan apa itu access modifier dan jelaskan perbedaan antara public, private, dan protected! (10 poin)

[your answer here]

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

---

### 5. Jelaskan apa itu abstraction dalam OOP! Tunjukkan contoh kode abstraction lewat header file dalam C++! (10 poin)

[your answer here]

```cpp
// your code here
```

### Referensi:

- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]
- Contoh Situs [Online]. Available: https://www.myWebsite.com/ilovedigilab/. [Diakses: 25-Agustus-2024]

## Programming

> Gunakan abstraction lewat header file untuk kode di bawah ini.

### 1. Buatlah enumeration bernama `Jurusan` dengan isi sebagai berikut:

```cpp
enum Jurusan {
    ELEKTRO,
    BIOMEDIK,
    KOMPUTER
};
```

---

### 2. Buatlah class bernama `Dosen` dengan isi sesuai deskripsi berikut:
- Class ini memiliki atribut private `name` dan `id`.
- Buat **constructor** untuk mengisi kedua atribut tersebut.
- Tambahkan getter `getName()` dan setter `setName()` serta `setId()` untuk encapsulation.

---

### 3. Buatlah class bernama `Kelas` dengan atribut private:
- `namaKelas` (string)
- `nilai` (float)
- `sks` (int)
- `dosen` (objek dari class `Dosen`)

Isi dari class:
- Buat constructor yang menerima semua atribut sebagai parameter.
- Buat method `showDetail()` yang menampilkan informasi nama kelas, nama dosen pengajar, SKS, dan nilai.
- Tambahkan method `getNilai()`, `getSKS()`, serta setter `setNilai()`, `setSKS()`, dan `setNamaKelas()`.

Contoh output method `showDetail()`:
```bash
Kelas: Alpro, Nilai: 3.5, SKS: 3, Dosen: Mr. Budi
```

---

### 4. Buatlah class `Mahasiswa` dengan atribut private:
- `nama` (string)
- `id` (int)
- `alprog`, `sisben`, `matdis`, `fislis` (tipe Kelas)
- `jurusan` (tipe enum Jurusan)

Isi dari class:
- Constructor untuk mengisi semua atribut.
- Method `getIPK()` yang menghitung IPK berdasarkan rumus:
```txt
IPK = (nilai * sks dari semua mata kuliah) / total sks
```
- Method `showDetail()` yang menampilkan:
  - Nama mahasiswa
  - ID
  - Jurusan (sebagai string, seperti "Teknik Elektro", dll)
  - IPK dengan format dua angka di belakang koma
  - Informasi seluruh kelas mahasiswa (panggil `showDetail()` dari masing-masing objek kelas)

Contoh output:
```bash
Nama: Ali, ID: 12345, Jurusan: Teknik Elektro
Kelas: Alpro, Nilai: 3.5, SKS: 3, Dosen: Mr. Budi
Kelas: Sisben, Nilai: 3.7, SKS: 3, Dosen: Mr. Thomas
Kelas: Matdis, Nilai: 3.9, SKS: 3, Dosen: Ms. Puff
Kelas: Fislis, Nilai: 3.6, SKS: 2, Dosen: Ms. Sandy
IPK: 3.66
```

---

### 5. Buatlah `main.cpp` dan lakukan hal berikut:
- Buat 4 objek dosen:
  | Object     | Nama Dosen | ID  |
  |------------|-------------|-----|
  | dosenAlpro | Mr. Budi    | 10  |
  | dosenSisben| Mr. Thomas  | 11  |
  | dosenMatdis| Ms. Puff    | 12  |
  | dosenFislis| Ms. Sandy   | 13  |

- Buat 4 objek kelas:
  | Object      | Nama Kelas       | Nilai | SKS | Dosen        |
  |-------------|------------------|-------|-----|---------------|
  | alprog      | Algoritma Pemrograman | bebas | 3   | dosenAlpro    |
  | sisben      | Sistem Benam     | bebas | 3   | dosenSisben   |
  | matdis      | Matematika Diskrit| bebas | 3   | dosenMatdis   |
  | fislis      | Fisika Listrik   | bebas | 2   | dosenFislis   |

- Buat 1 objek `Mahasiswa` dengan nama bebas yang mengikuti 4 objek kelas yang sudah diset di atas.

---

### 6. Jalankan program dan pastikan output menampilkan:
- Informasi setiap kelas (`alprog`, `sisben`, `matdis`, `fislis`)
- Informasi lengkap mahasiswa

Contoh output:
```bash
Nama: Burhan, ID: 12345, Jurusan: Teknik Elektro
Kelas: Alprog, Nilai: 3.8, SKS: 3, Dosen: Pak Budi
Kelas: Fismek, Nilai: 3.5, SKS: 3, Dosen: Bu Sari
Kelas: Matdis, Nilai: 4, SKS: 2, Dosen: Pak Budi
Kelas: Fislis, Nilai: 3.6, SKS: 2, Dosen: Bu Sari
IPK: 3.71
```

---

Jurusan.h

```cpp
#pragma once

enum Jurusan{
    ELEKTRO,BIOMEDIK,KOMPUTER
};
```

Dosen.h:

```cpp
#pragma once
#include <string>

class Dosen{
    private:
        std::string name;   
        int id;
    public:
    Dosen(const std::string& newName, const int& newId);
    std::string getName() const;
    void setName(const std::string& newName) ;
    int getId() const;
    void setId(const int& newId);
};
```

Dosen.cpp :

```cpp
#include "Dosen.h"
#include <iostream>

Dosen::Dosen(const std::string& newName,const int& newId): name(newName), id(newId) {}

std::string Dosen::getName() const{
    return name;
}

void Dosen::setName(const std::string& newName){
    name = newName;
}

int Dosen::getId() const {
    return id;
}

void Dosen::setId(const int& newId){
    id = newId;
}
```

Kelas.h:

```cpp

#pragma once
#include <string>
#include "Dosen.h"

class Kelas{
    private:
        std::string name;
        float nilai;
        int sks;
        Dosen dosen;
    public:
        void showDetail()const;
        float getNilai()const;
        void setNilai(const float& newNilai);
        int getSks()const;
        void setSks(const int& newSks);
        std::string getName()const;
        void setName(const std::string newName);
        Kelas(const std::string newName,const float newNilai,const int newSks, const Dosen newDosen);
};
```

Kelas.cpp:
```cpp
#include "Kelas.h"
#include <iostream>
#include <format>
#include <string>

Kelas::Kelas(const std::string newName, const float newNilai, const int newSks, const Dosen newDosen)    : name(newName), nilai(newNilai), sks(newSks), dosen(newDosen) {}
void Kelas::showDetail() const {
    std::cout << std::format("Kelas: {}, Nilai {:.2f}, SKS: {}, Dosen: {}", name, nilai, sks, dosen.getName()) << std::endl;

}

float Kelas::getNilai() const {
    return nilai;
}

void Kelas::setNilai(const float& newNilai) {
    nilai = newNilai;
}

int Kelas::getSks() const {
    return sks;
}

void Kelas::setSks(const int& newSks) {
    sks = newSks;
}

std::string Kelas::getName() const {
    return name;
}

void Kelas::setName(const std::string newName) {
    name = newName;
}
```

Mahasiswa.h:

```cpp
#pragma once
#include <string>
#include <vector>
#include "Kelas.h"
#include "Jurusan.h"

class Mahasiswa{
    private:
        std::string name;
        int id;
        std::vector<Kelas> classes;
        Jurusan jurusan;
    public:
        Mahasiswa(
            const std::string newName,
            const int newId,
            const std::vector<Kelas> newClasses,
            const Jurusan newJurusan
        );
        float getIpk()const;
        void showDetail()const;
};
```

Mahasiswa.cpp:

```cpp
#include "Mahasiswa.h"
#include <string>
#include <format>
#include <iostream>

Mahasiswa::Mahasiswa(
    const std::string newName,
            const int newId,
            const std::vector<Kelas> newClasses,
            const Jurusan newJurusan
): name(newName),id(newId),classes(newClasses),jurusan(newJurusan) {}

float Mahasiswa::getIpk()const{
    float ipk = 0;
            int totalSks = 0;
            for (Kelas k : classes) {
                ipk += k.getNilai() * k.getSks();
                totalSks += k.getSks();
            }
            ipk /= totalSks;
            return ipk;
}

void Mahasiswa::showDetail()const{
    std::string jurusanStr = (jurusan == ELEKTRO) ? "Teknik Elektro" : (jurusan == BIOMEDIK) ? "Teknik Biomedik" : "Teknik Komputer";
            std::cout << std::format("Nama: {}, ID: {}, Jurusan {}",name,id,jurusanStr) << std::endl;
            for (Kelas k : classes) {
                k.showDetail();
            }
            std::cout << std::format("IPK: {:.2f}",getIpk());
}
```

main.cpp:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "Dosen.h"
#include "Mahasiswa.h"
#include "Kelas.h"

int main() {
    Dosen dosenAlprog("Mr. Budi", 10), dosenSisben("Mr. Thomas", 11), dosenMatdis("Ms. Puff", 12), dosenFislis("Ms. Sandy", 13);
    Kelas alprog("Algoritma Pemrograman", 3.8, 3, dosenAlprog), sisben("Sistem Benam", 3.5, 3, dosenSisben), matdis("Matematika Diskrit", 4, 3, dosenMatdis), fislis("Fisika Listrik", 3.6, 2, dosenFislis);
    Mahasiswa m("Seorang Mahasiswa", 69420, {alprog, sisben, matdis, fislis}, ELEKTRO);
    m.showDetail();
    return 0;
}
```

dst.

SS Output Program Kalian : 
![Output Program](https://itsfoss.com/content/images/2023/03/run-c-program-in-linux-with-visual-studio-code.jpg)

