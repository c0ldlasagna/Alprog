#include <string>
#include <vector>
#include "Directory.h"
#include "File.h"

Directory::Directory(const std::string& newName):
            name(newName) {}

void Directory::addFile(const std::string& name){
    files.push_back(File(name));
}

std::vector<File>& Directory::getFiles(){
    return files;
}

void Directory::setName(const std::string& newName){
    name = newName;
}

std::string Directory::getName()const{
    return name;
}