#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "Dosen.h"

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::format;

enum Jurusan {
    ELEKTRO,
    BIOMEDIK,
    KOMPUTER
};

class Kelas {
    private:
        std::string namaKelas;
        float nilai;
        int sks;
        Dosen dosen;
    public:
        void showDetail() {
            cout << format("Kelas: {}, Nilai {:.2f}, SKS: {}, Dosen: {}",namaKelas,nilai,sks,dosen.getName()) << endl;
        }
        Kelas(std::string n, float f, int i, Dosen d) 
            : namaKelas(n), nilai(f), sks(i), dosen(d) {}
        float getNilai() {
            return nilai;
        }
        void setNilai(float f) {
            nilai = f;
        }
        int getSks() {
            return sks;
        }
        void setSks(int i) {
            sks = i;
        }
};

class Mahasiswa {
    private:
        std::string nama;
        int id;
        vector<Kelas> classes;
        Jurusan jurusan;
    public:
        Mahasiswa(std::string n, int i, std::vector<Kelas> cls, Jurusan j)
            : nama(n), id(i), classes(cls), jurusan(j) {}
        string getIpk() {
            float ipk = 0;
            int totalSks = 0;
            for (Kelas k : classes) {
                ipk += k.getNilai() * k.getSks();
                totalSks += k.getSks();
            }
            ipk /= totalSks;
            return std::format("{:.2f}",ipk);
        }

        void showDetail() {
            std::string jurusanStr = (jurusan == ELEKTRO) ? "Teknik Elektro" : (jurusan == BIOMEDIK) ? "Teknik Biomedik" : "Teknik Komputer";
            cout << format("Nama: {}, ID: {}, Jurusan {}",nama,id,jurusanStr) << endl;
            for (Kelas k : classes) {
                k.showDetail();
            }
            cout << "IPK: " << getIpk() << endl;
        }
};

int main() {
    Dosen dosenAlprog("Mr. Budi", 10), dosenSisben("Mr. Thomas", 11), dosenMatdis("Ms. Puff", 12), dosenFislis("Ms. Sandy", 13);
    Kelas alprog("Algoritma Pemrograman", 3.8, 3, dosenAlprog), sisben("Sistem Benam", 3.5, 3, dosenSisben), matdis("Matematika Diskrit", 4, 3, dosenMatdis), fislis("Fisika Listrik", 3.6, 2, dosenFislis);
    Mahasiswa m("Seorang Mahasiswa", 69420, {alprog, sisben, matdis, fislis}, ELEKTRO);
    m.showDetail();
    return 0;
}
