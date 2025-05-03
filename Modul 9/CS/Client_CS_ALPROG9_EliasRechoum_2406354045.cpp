#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

#define SERVER "127.0.0.1"
#define PORT 8888

void log(const string& message,int mode){
    string prompt;
    mode == 1 ? prompt = "\033[0;31m[ERROR] " : mode == 2 ? prompt = "\033[0;35m[INPUT] ": prompt = "\033[0;34m[INFO]  ";
    cout << prompt << "\033[0m" << message;
    if (mode != 2) {
        cout << endl;
    } else {
        return;
    }
    return;
}

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    string command;
    char serverReply[2000];
    int key;

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        log("Startup Failed.",1);
        return 1;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        log("Socket creation failed.",1);
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        log("Connection to server failed.",1);
        return 1;
    }

    log("Connected to server.",0);

    log("> ",2);

    getline(cin,command);

    while (true) {
        if (send(client_socket, command.c_str(), command.length(), 0) == SOCKET_ERROR) {
            log("Send Failed", 1);
            return 1;
        }

        int recv_size = recv(client_socket, serverReply, sizeof(serverReply) - 1, 0);
        if (recv_size == SOCKET_ERROR) {
            log("Receive Failed", 1);
            return 1;
        }

        serverReply[recv_size] = '\0';
        log("Received message: " + string(serverReply), 0);

        log("> ", 2);
        getline(cin, command);

        if (command == "exit") {
            log("Exiting client.", 0);
            break;
        }
    }
    

    return 0;
}