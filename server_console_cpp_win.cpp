#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <winsock2.h> 
#include <conio.h>
#pragma comment(lib, "WS2_32.lib")
using namespace std;
//based on blog.kislenko.net
//in devcpp 4.9.9.2   tools - compiler options - compiler - add to linker cmd: -lws2_32
DWORD WINAPI serverReceive(LPVOID lpParam) { 
 char buffer[1024] = { 0 }; 
 SOCKET client = *(SOCKET*)lpParam; 
 while (true) { 
  if (recv(client, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
   cout << "recv function failed with error " << WSAGetLastError() << endl;
   return -1;
  }
  if (strcmp(buffer, "exit\n") == 0) { 
   cout << "Client Disconnected." << endl;
   break;
  }
  cout << "Client: " << buffer << endl;
  memset(buffer, 0, sizeof(buffer)); 
 }
 return 1;
}

DWORD WINAPI serverSend(LPVOID lpParam) { 
 char buffer[1024] = { 0 };
 SOCKET client = *(SOCKET*)lpParam;
 while (true) {
  fgets(buffer, 1024, stdin);
  if (send(client, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
   cout << "send failed with error " << WSAGetLastError() << endl;
   return -1;
  }
  if (strcmp(buffer, "exit\n") == 0) {
   cout << "Thank you for using the application" << endl;
   break;
  }
 }
 return 1;
}

int main() {
 WSADATA WSAData;
 SOCKET server, client;
 SOCKADDR_IN serverAddr, clientAddr; 
 WSAStartup(MAKEWORD(2, 0), &WSAData);
 
 char ac[80];
    if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
         cerr << "Host err" ;
        return 1;
    }

    struct hostent *phe = gethostbyname(ac);
    if (phe == 0) {
        cerr << "Host err" ;
        return 1;
    }

string s;	
    for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        s = inet_ntoa(addr);
    }
cout <<"Hello! Server will run on ip: "<<s<<"\n";

int portnum; portnum = 26000;
cout<<"Current port is: "<<portnum<<"\n";
cout<<"Press Enter to confirm or <1> and Enter to change: \n>";
portnum = cin.get();
if (portnum==49){cout<<"Print new port: "; cin>>portnum;} 
else {portnum = 26000;}
 
 server = socket(AF_INET, SOCK_STREAM, 0); 
 if (server == INVALID_SOCKET) {
  cout << "Socket creation failed with error:" << WSAGetLastError() << endl;
  return -1;
 }
 serverAddr.sin_addr.s_addr = INADDR_ANY;
 serverAddr.sin_family = AF_INET;
 serverAddr.sin_port = htons(portnum);
 if (bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
  cout << "Bind function failed with error: " << WSAGetLastError() << endl;
  return -1;
 }

 if (listen(server, 0) == SOCKET_ERROR) { 
  cout << "Listen function failed with error:" << WSAGetLastError() << endl;
  return -1;
 }
 cout << "Running server at ip: "<<s<<" at port: "<<portnum <<". Wait for client...";

 char buffer[1024]; 
 int clientAddrSize = sizeof(clientAddr); 
 if ((client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize)) != INVALID_SOCKET) {
  
  cout << "Client connected!" << endl;
  cout << "Now you can use our live chat application. " << "Enter \"exit\" to disconnect" << endl;

  DWORD tid;
  HANDLE t1 = CreateThread(NULL, 0, serverReceive, &client, 0, &tid); 
  if (t1 == NULL) { 
   cout << "Thread Creation Error: " << WSAGetLastError() << endl;
  }
  HANDLE t2 = CreateThread(NULL, 0, serverSend, &client, 0, &tid); 
  if (t2 == NULL) {
   cout << "Thread Creation Error: " << WSAGetLastError() << endl;
  }

  WaitForSingleObject(t1, INFINITE);
  WaitForSingleObject(t2, INFINITE);

  closesocket(client); 
  if (closesocket(server) == SOCKET_ERROR) { 
   cout << "Close socket failed with error: " << WSAGetLastError() << endl;
   return -1;
  }
  WSACleanup();
 }
}
