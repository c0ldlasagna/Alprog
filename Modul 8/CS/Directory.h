#pragma once
#include <string>
#include <vector>
#include "File.h"

class Directory{
    private:
        std::string name;
        std::vector<File> files;
    public:
        Directory(const std::string& newName);
        void addFile(const std::string& name);
        std::vector<File>& getFiles();
        std::vector<File>& getFiles() const;
        void setName(const std::string& newName);
        std::string getName()const; 

};