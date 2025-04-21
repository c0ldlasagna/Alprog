# Tugas Pendahuluan Modul 8

```help
Nama  : Elias Rechoum
NPM   : 2406354045
```

> Note: Soal Programming tidak perlu dicantumkan referensi, hanya soal Teori saja yang perlu referensi minimal 2.

# Teori

## 1. Jelaskan apa itu class dan object. Berikan contoh penggunaan class dan object serta tunjukkan bagian mana yang merupakan class ataupun object dalam bahasa pemrograman C++! (10 poin)

---

**Class** adalah blueprint atau cetakan untuk membuat object. Di dalam class, kita dapat mendefinisikan atribut (variabel) dan fungsi (method) yang dimiliki oleh sebuah entitas.

**Object** adalah instance dari sebuah class. Setelah kita mendefinisikan sebuah class, kita dapat membuat banyak object dari class tersebut dengan data dan perilaku yang sesuai.

#### Contoh

```cpp
#include <iostream>
#include <string>

class Person{
  public:
    //Attributes
    std::string name;
    int age;
    
    //Method
    void introduction()
    {                
      std::cout << "Hello, I'm " << name << " and I'm " << age << " years old!" << std::endl;
    }
};

int main(){
  Person guy;
  guy.name = "John Doe";
  guy.age = 25;
  guy.introduction();
  return 0;
}
```

#### Output

```apparentlyitdoesn'tmatterwhatyouputherelol
Hello, I'm John Doe and I'm 25 years old!
```

#### Penjelasan

- `class Person` adalah sebuah class, yang mendefinisikan struktur data dari Person dan fungsi/method `introduction()`, yang akan memakai data dari instansi sebuah object.

- `guy` adalah object, yaitu instance dari `class Person`. Object ini memiliki nilai data spesifik seperti `name = "John Doe"` dan `age = 25`.

### Referensi:

- Cplusplus.com [Online]. Available: <https://www.cplusplus.com/doc/tutorial/classes/>. [Diakses: 21-04-2025]

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/c-classes-and-objects/>. [Diakses: 21-04-2025]

---

## 2. Jelaskan apa itu constructor. Berikan contoh penggunaan constructor dalam bahasa pemrograman C++! (10 poin)

Constructor adalah sebuah method khusus dalam sebuah class yang otomatis dipanggil saat object dibuat. Fungsi utamanya adalah untuk menginisialisasi nilai awal dari atribut-atribut dalam class. Constructor memiliki nama yang sama dengan nama class, dan tidak memiliki return type, bahkan void sekalipun.

#### Contoh

```cpp
#include <iostream>
#include <string>

class Person{
  private:
   //private attributes
    std::string name;               
    int age;                        

  public:
    // Constructor
    Person(const std::string& newName,const int& newAge): name(newName),age(newAge) {}

    //Method
    void introduction(){                
      std::cout << "Hello, I'm " << name << " and I'm " << age << " years old!" << std::endl;
    }
};

int main(){
  // Initialisation of "guy" with attributes using constructor
  Person guy("John Doe", 25);

  guy.introduction();

  return 0;
}
```

#### Output

```funnywords
Hello, I'm John Doe and I'm 25 years old!
```

Penjelasan:

- `Person(const std::string& newName, const int& newAge)` adalah sebuah fungsi **constructor**. Fungsi ini secara otomatis dijalankan saat object guy dibuat.

- `guy("John Doe", 25)` mengisi nilai atribut name dan age melalui fungsi constructor.

Constructor memudahkan pengisian data saat pembuatan object, dan membuat kode lebih rapi serta aman dari lupa menginisialisasi nilai.

### Referensi:

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/constructors-in-cpp/>. [Diakses: 21-04-2025]

- Cplusplus.com [Online]. Available: <https://www.cplusplus.com/doc/tutorial/classes2/>. [Diakses: 21-04-2025]

---

### 3. Jelaskan apa itu encapsulation dan manfaatnya sebagai salah satu konsep OOP! Berikan contoh kode encapsulation dalam C++! (10 poin)

Encapsulation adalah konsep dalam Pemrograman Berorientasi Objek (OOP) yang mengacu pada penyembunyian detail implementasi objek dan hanya menyediakan antarmuka yang diperlukan untuk berinteraksi dengan objek tersebut. Dengan kata lain, data dan fungsi terkait dikemas dalam satu unit (kelas) dan akses terhadap data tersebut dibatasi menggunakan akses modifier seperti private, protected, dan public.

Manfaat dari encapsulation antara lain:

- Keamanan Data: Menghindari data diubah secara langsung oleh bagian lain dari program yang bisa menyebabkan kesalahan.

- Pengendalian Akses: Dengan menggunakan fungsi getter dan setter, kita bisa mengendalikan bagaimana data dimodifikasi atau dibaca.

- Pemeliharaan Kode: Memudahkan pengelolaan kode karena kita bisa mengubah implementasi internal tanpa mempengaruhi bagian lain dari program yang menggunakan objek tersebut.

#### Contoh

```cpp
#include <iostream>
#include <string>

class Person {
private:
    //private/encapsulated attributes, can only be accessed from within the class.
    std::string name; 
    int age;           

public:
    // Constructor
    Person(const std::string& newName, const int& newAge)
        : name(newName), age(newAge) {}

    // Method
    void introduction() {
        std::cout << "Hello, I'm " << name << " and I'm " << age << " years old!" << std::endl;
    }

    // getter method to access "name"
    std::string getName() const {
        return name;
    }

    // setter to modify "age" with conditions  (Age cannot be less than 0)
    void setAge(int newAge) {
            std::cout << "Attempting to change age...."<<std::endl;
            if (newAge < 0){
            std::cout << "Invalid age.(" << newAge << ")" << std::endl;
            return;
            }
            age = newAge;
            std::cout << "Changed age to " << newAge << std::endl;
    }
};

int main() {
    // Initialisation of Person "guy"
    Person guy("John Doe", 25);

    //Initial attributes
    guy.introduction();

    // Accessing attributes with getters
    std::cout << "Accessing name with getter: " << guy.getName() << std::endl;

    // Modifying attributes with setters
    guy.setAge(-10); // Will be invalid due to setter protecting the attribute
    guy.setAge(30); //Valid age change

    //Changes reflected in method too!
    guy.introduction();

    return 0;
}
```

#### Output

```c--
Hello, I'm John Doe and I'm 25 years old!
Accessing name with getter: John Doe
Attempting to change age....
Invalid age.(-10)
Attempting to change age....
Changed age to 30
Hello, I'm John Doe and I'm 30 years old!
```

Penjelasan:

- Pada contoh di atas, atribut name dan age bersifat private dan tidak bisa diakses langsung dari luar kelas. Hal ini merupakan bagian dari encapsulation, yang membatasi akses ke data internal.

- Setter untuk age memastikan bahwa nilai yang dimasukkan valid, misalnya umur harus bilangan positif. Ini menjaga agar data tetap konsisten dan mencegah kesalahan.

- Getter untuk name hanya mengembalikan nilai name, karena attributnya private dan tidak dapat diakses secara langsung.

Dengan menggunakan getters dan setters, kita bisa memastikan bahwa data yang diubah atau diakses selalu dalam kondisi yang benar dan valid, sekaligus melindungi data internal objek dari perubahan yang tidak diinginkan.

### Referensi:

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/encapsulation-in-cpp/>. [Diakses: 21-04-2025]

- Cplusplus.com [Online]. Available: <https://www.cplusplus.com/doc/tutorial/classes/>. [Diakses: 21-04-2025]

---

### 4. Jelaskan apa itu access modifier dan jelaskan perbedaan antara public, private, dan protected! (10 poin)

Access modifier (modifier akses) adalah kata kunci dalam pemrograman berorientasi objek (OOP) yang digunakan untuk menentukan tingkat akses terhadap anggota (atribut dan fungsi) dari sebuah kelas. Dengan access modifier, kita dapat mengontrol bagian mana dari sebuah kelas yang dapat diakses dari luar kelas, hanya dari dalam kelas, atau dari turunan kelas.

Di C++, terdapat tiga jenis access modifier utama:

- #### public

    Anggota dengan access modifier public dapat diakses dari mana saja, baik dari dalam kelas itu sendiri maupun dari luar kelas (misalnya objek dari kelas tersebut). Biasanya digunakan untuk fungsi-fungsi yang ingin kita jadikan antarmuka (interface) agar bisa digunakan oleh pengguna kelas.

- #### private

    Anggota private hanya dapat diakses dari dalam kelas itu sendiri. Atribut dan metode yang bersifat private tidak dapat diakses langsung dari luar kelas. Ini berguna untuk menjaga keamanan dan integritas data agar tidak sembarangan diubah dari luar.

- #### protected

    Anggota protected mirip dengan private, tetapi bisa diakses oleh kelas turunan (subclass). Jadi meskipun atribut atau metode tidak bisa diakses dari luar kelas, subclass masih bisa mengaksesnya. protected biasanya digunakan dalam konteks inheritance (pewarisan).

### Referensi:

- GeeksforGeeks [Online]. Available: <https://www.geeksforgeeks.org/access-modifiers-in-c/>. [Diakses: 21-04-2025]

- Cplusplus.com [Online]. Available: <https://www.cplusplus.com/doc/tutorial/inheritance/>. [Diakses: 21-04-2025]

---

### 5. Jelaskan apa itu abstraction dalam OOP! Tunjukkan contoh kode abstraction lewat header file dalam C++! (10 poin)

Abstraction dalam Object-Oriented Programming (OOP) adalah konsep untuk menyembunyikan detail implementasi dan hanya menampilkan fungsionalitas yang dibutuhkan oleh pengguna. Dengan abstraksi, kita dapat menyederhanakan kompleksitas program dan membuat kode menjadi lebih bersih, mudah digunakan, dan aman dari penyalahgunaan.

Abstraksi memungkinkan kita untuk berinteraksi dengan objek melalui antarmuka publik tanpa perlu mengetahui bagaimana cara kerja internal objek tersebut. Di C++, abstraksi dapat dicapai dengan menggunakan kelas dan access modifier seperti `private` dan `public`. Atribut-atribut penting disembunyikan (`private`) dan hanya dapat diakses melalui method (`public`) yang disediakan oleh kelas tersebut.

### Contoh abstraksi menggunakan header file

#### Person.h

```cpp
#pragma once
#include <string>

class Person{
    private:
    std::string name;
    int age;

    public:
        Person(const std::string& newName, const int& newAge);
        void introduction()const;
        std::string getName()const;
        void setAge(const int& newAge);
};
```

#### Person.cpp

```cpp
#include "Person.h"
#include <string>
#include <iostream>

Person::Person(const std::string& newName, const int& newAge):
        name(newName),age(newAge) {}

void Person::introduction()const{
    std::cout << "Hello, I'm " << name << " and I'm " << age << " years old!" << std::endl;   
}

std::string Person::getName()const{
    return name;
}

void Person::setAge(const int& newAge){
    std::cout << "Attempting to change age...."<<std::endl;
            if (newAge < 0){
            std::cout << "Invalid age.(" << newAge << ")" << std::endl;
            return;
            }
            age = newAge;
            std::cout << "Changed age to " << newAge << std::endl;
};
```

#### main.cpp

```cpp
#include "Person.h"
#include <iostream>
#include <string>

int main() {
    // Initialisation of Person "guy"
    Person guy("John Doe", 25);

    //Initial attributes
    guy.introduction();

    // Accessing attributes with getters
    std::cout << "Accessing name with getter: " << guy.getName() << std::endl;

    // Modifying attributes with setters
    guy.setAge(-10); // Will be invalid due to setter protecting the attribute
    guy.setAge(30); //Valid age change

    //Changes reflected in method too!
    guy.introduction();

    return 0;
}
```

#### Compile + run command

```bash
g++ -o main *.cpp && ./main
```

#### Output

```outputlang
Hello, I'm John Doe and I'm 25 years old!
Accessing name with getter: John Doe
Attempting to change age....
Invalid age.(-10)
Attempting to change age....
Changed age to 30
Hello, I'm John Doe and I'm 30 years old!
```

Kode di atas menunjukkan bagaimana abstraksi bekerja dalam C++. Pengguna objek Person hanya perlu mengetahui cara menggunakan method seperti setAge() atau introduction(), tanpa perlu tahu bagaimana atribut age atau name disimpan dan dikelola. Ini meningkatkan keamanan dan kemudahan pemeliharaan kode.

### Referensi:

- Pwskills [Online]. Available: <https://pwskills.com/blog/what-is-abstraction-in-oops-definition-types-and-advantages/> [Diakses: 21-04-2025]
- digitalocean.com [Online]. Available: <https://www.digitalocean.com/community/tutorials/what-is-abstraction-in-oops> [Diakses: 21-04-2025]

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

### SS Output Program Kalian :
![alt text](https://raw.githubusercontent.com/c0ldlasagna/Alprog/refs/heads/master/Modul%208/image.png)

