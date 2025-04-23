#include "FileSystemManager.h"
#include "File.h"
#include "Directory.h"
#include <iostream>

FileSystemManager::FileSystemManager(Directory& dir): directory(dir) {};

void FileSystemManager::run(){
    {
        std::string command;
        while (true)
        {
            std::cout << "[" << directory.getName() << "]$ ";
            std::cin >> command;
    
            if (command == "touch")
            {
                std::string name;
                std::cin >> name;
                touch(name);
            }
            else if (command == "echo")
            {
                std::string content, name;
                int mode;
                std::cin >> content;
                std::cin >> name;
                std::cin >> mode;
                echo(content,name,mode);
            }
            else if (command == "ls")
            {
                ls();
            }
            else if (command == "cat")
            {
                std::string name;
                std::cin >> name;
                cat(name);
            }
            else if (command == "exit")
            {
                break;
            }
            else
            {
                std::cout << "Unknown command." << '\n';
            }
        }
    }
}

void FileSystemManager::touch(const std::string& name){
    directory.addFile(name);
}

void FileSystemManager::echo(const std::string& content, const std::string& name, const int& mode) {
    for (File& file : directory.getFiles()) { // Iterate through files in the directory
        if (file.getName() == name) { // Check if the file name matches
            if (mode == 1) { // Overwrite mode
                file.setContent(content); // Replace the file's content
                std::cout << file.getContent() << std::endl;
            } else if (mode == 2) { // Append mode
                file.setContent(file.getContent() + content); // Append to the file's content
                std::cout << file.getContent() << std::endl;
            }
            return; // Exit the function after modifying the file
        }
    }
    std::cout << "File not found." << '\n'; // If no matching file is found
}

void FileSystemManager::ls(){
    for (const File& fileName : directory.getFiles()){
        std::cout << fileName.getName() << '\n';
    }
}

void FileSystemManager::cat(const std::string& name) {
    for (File& file : directory.getFiles()) { // Iterate through files in the directory
        if(file.getName() == name){
            std::cout << file.getName() << '\n';
            std::cout << file.getContent() << '\n'; // Print the file's content to the terminal
            return; // Exit the function after printing the content
        }
    }
    std::cout << "File not found." << '\n'; // If no matching file is found
}