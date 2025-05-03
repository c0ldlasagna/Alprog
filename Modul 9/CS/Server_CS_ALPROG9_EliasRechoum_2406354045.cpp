#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888

class File {
    public:
        string name;
        string type;

        File(string file_name){
            stringstream ss (file_name);
            string temp;

            getline(ss, temp, '.');
            name = temp;
            
            getline(ss, temp);
            type = temp;
        }
};


class DirectoryReader {
    private:
        string DIRECTORY = "system";

        void _create_file(string file_name){
            ofstream file;
        
            file.open("./" + DIRECTORY + "/"+ file_name);
            file.close();
        }

        void _create_directory(){
            mkdir(DIRECTORY.c_str());
            string tmpFile = "output.txt";
            string path = "./" + DIRECTORY;

            _create_file("A.txt");
            _create_file("B.txt");
            _create_file("k.cpp");
            _create_file("b.cpp");

            string command = "ls " + path + " > " + tmpFile;
    
            system(command.c_str());
        }

    public:
        static vector<File> GetData() {
            DirectoryReader reader;
            reader._create_directory();

            vector<File> data = {};

            string tmpFile = "output.txt";
            ifstream file_data;

            file_data.open(tmpFile);

            string line, result;
            while (!file_data.eof()) {
                getline(file_data, line);
                
                File newFile(line);
                data.push_back(newFile);
            }
            file_data.close();

            remove(tmpFile.c_str()); 

            return data;
        }
};

void log(const string& message,int mode){
    string prompt;
    mode == 1 ? prompt = "\033[0;31m[ERROR] " : mode == 2 ? prompt = "\033[0;35m[INPUT] ": prompt = "\033[0;34m[INFO]  ";
    cout << prompt << "\033[0m" << message << endl;
    return;
}

int main() {
    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string pass, message;
    int key;

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        log("Startup Failed.",1);
        return 1;
    }
    log("Initialised Winsock",0);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == INVALID_SOCKET) {
        log("Socket creation failed.",1);
        return 1;
    }
    log("Socket Created",0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    
    if (bind(listen_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        log("Bind failed.",1);
        return 1;
    }
    log("Bind Successful",0);

    listen(listen_socket, 3);
    log("Waiting for incoming connections...",0);

    c = sizeof(struct sockaddr_in);
    client_socket = accept(listen_socket, (struct sockaddr *)&client, &c);
    if (client_socket == INVALID_SOCKET) {
        log("Accept failed.",1);
        return 1;
    }

    log("Client Connected.",0);

    while (true) {
        recv_size = recv(client_socket, messageRecv, sizeof(messageRecv), 0);
        if (recv_size == SOCKET_ERROR) {
            log("Recv failed.",1);
            break;
        }

        messageRecv[recv_size] = '\0';

        log("Received message: " + string(messageRecv), 0);

        if (string(messageRecv) == "SHUTDOWN") {
            log("Server shutting down...", 0);
            send(client_socket, "Server shutting down...", 22, 0);
            break;
        }

        if (string(messageRecv).substr(0, 4) == "LIST") {
            string extension = string(messageRecv).substr(5);
            vector<File> file_list = DirectoryReader::GetData();
            string response = "";

            for (const auto& file : file_list) {
                if (file.type == extension) {
                    response += file.name + "." + file.type + " ";
                }
            }

            if (response.empty()) {
                response = "No files found with the ." + extension + " extension.\n";
            }

            send(client_socket, response.c_str(), response.length(), 0);
        }
        else{
            string response = "Unknown command: " + string(messageRecv) + "\n";
            send(client_socket, response.c_str(), response.length(), 0);
        }
        }
    closesocket(client_socket);
    closesocket(listen_socket);
    WSACleanup();
    
    return 0;
}
