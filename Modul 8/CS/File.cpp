#include "File.h"
#include <string>

File::File(const std::string& newName):
         name(newName),content("")  {}

void File::setName(const std::string& newName){
    name = newName;
}

void File::setContent(const std::string& newContent){
    content = newContent;
}

std::string File::getName()const{
    return name;
}

std::string File::getContent()const{
    return content;
}