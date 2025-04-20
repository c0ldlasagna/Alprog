#pragma once
#include <string>

class Dosen{
    private:
        int id;
        std::string name;
    public:
    Dosen(const std::string& newName, const int& newId);
    std::string getName() const;
    void setName(const std::string& newName) ;
    int getId() const;
    void setId(const int& newId);
};