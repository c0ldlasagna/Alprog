
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