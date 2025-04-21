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