#include "File.h"
#include "Directory.h"
#include "FileSystemManager.h"

int main(){
    Directory dir("root");
    FileSystemManager fs(dir);
    fs.run();
    return 0;
}