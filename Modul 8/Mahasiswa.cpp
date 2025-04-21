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