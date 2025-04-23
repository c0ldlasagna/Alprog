#include <string>
#include "Directory.h"
#include "File.h"

class FileSystemManager{
    private:
        Directory directory;
    public:
        void touch(const std::string& name);
        void echo(const std::string& content, const std::string& name, const int& mode);
        void cat(const std::string name);
        void ls()const;
        void run();
                FileSystemManager(Directory& dir);
        };