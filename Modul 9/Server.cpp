#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>

using namespace std;

#define PORT 8888
#define PASSWORD "password"

string decrypt(string text, int n) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        result += char((int(text[i] - 97 + n)  % 26) + 97);
    }

    return result;
}

void parseMessage(const string& messageRecv, string& pass, int& key) {
    stringstream ss(messageRecv);
    string temp;

    getline(ss, temp, ' ');
    pass = "";
    for (int x = 0; x < temp.length(); x++) {
        pass += char(tolower(temp[x]));
    }

    getline(ss, temp, ' ');
    key = atoi(temp.c_str());
}

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

    log("Server listening on port " + to_string(PORT),0);

    c = sizeof(struct sockaddr_in);
    client_socket = accept(listen_socket, (struct sockaddr *)&client, &c);
    if (client_socket == INVALID_SOCKET) {
        log("Accept failed.",1);
        return 1;
    }
    
    log("Client Connected.",0);

    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv), 0);
    if (recv_size == SOCKET_ERROR) {
        log("Recv failed.",1);
        return 1;
    }

    messageRecv[recv_size] = '\0';

    parseMessage(messageRecv, pass, key);

    log("Received message: password = " + pass + ", key = " + to_string(key) ,0);


    string decrypted = decrypt(pass, key);
    log("Decrypted password: " + decrypted,0);

    if (decrypted == PASSWORD) {
        log("Authentication Successful",0);
        message = "\033[0;32mAuthentication Successful";
    }
    else{
        log("Authentication Failed",1);
        message = "\033[0;31mAuthentication Failed";
    }
    send(client_socket,message.c_str(),sizeof(message),0);

    closesocket(client_socket);
    closesocket(listen_socket);

    WSACleanup();


    return 0;
}
