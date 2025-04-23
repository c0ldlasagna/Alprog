#pragma once
#include <string>

class File{
    private:
        std::string name;
        std::string content;

    public:
        File(const std::string& newName);

        void setName(const std::string& newName);

        void setContent(const std::string& newContent);

        std::string getName()const;

        std::string getContent()const;
};