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
