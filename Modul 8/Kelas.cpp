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