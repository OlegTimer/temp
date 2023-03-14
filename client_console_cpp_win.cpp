#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <winsock2.h> 
#pragma comment(lib, "WS2_32.lib")
using namespace std;
//based on blog.kislenko.net
//in devcpp 4.9.9.2   tools - compiler options - compiler - add to linker cmd: -lws2_32
DWORD WINAPI clientReceive(LPVOID lpParam) { 
 char buffer[1024] = { 0 };
 SOCKET server = *(SOCKET*)lpParam;
 while (true) {
  if (recv(server, buffer, sizeof(buffer), 0)  == SOCKET_ERROR) {
   cout << "recv function failed with error: " << WSAGetLastError() << endl;
   return -1;
  }
  if (strcmp(buffer, "exit\n") == 0) {
   cout << "Server disconnected." << endl;
   return 1;
  }
  cout << "Server: " << buffer << endl;
  memset(buffer, 0, sizeof(buffer));
 }
 return 1;
}

DWORD WINAPI clientSend(LPVOID lpParam) { 
 char buffer[1024] = { 0 };
 SOCKET server = *(SOCKET*)lpParam;
 while (true) {
  fgets(buffer, 1024, stdin);
  if (send(server, buffer, sizeof(buffer), 0) == SOCKET_ERROR) {
   cout << "send failed with error: " << WSAGetLastError() << endl;
   return -1;
  }
  if (strcmp(buffer, "exit") == 0) {
   cout << "Thank you for using the application" << endl;
   break;
  }
 }
 return 1;
}

int main() {
 WSADATA WSAData;
 SOCKET server;
 SOCKADDR_IN addr;
 
 int portnum; portnum = 26000;
string s; s = "127.0.0.1";
cout << "Will try connect client to ip: "<<s<<" at port: "<<portnum <<"\n";
cout<<"Press Enter to confirm or <1> and Enter to change: \n>";
portnum = cin.get();
if (portnum==49){
cout<<"Print new port: "; 
cin>>portnum;
cout<<"Print new ip: "; 
cin>>s;
} 
else {portnum = 26000;}

char *cstr = new char [s.length()+1];
std::strcpy (cstr, s.c_str());

 WSAStartup(MAKEWORD(2, 0), &WSAData);
 if ((server = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
  cout << "Socket creation failed with error: " << WSAGetLastError() << endl;
  return -1;
 }
 
 addr.sin_addr.s_addr = inet_addr(cstr); 
 addr.sin_family = AF_INET;
 addr.sin_port = htons(portnum);
 if (connect(server, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
  cout << "Server connection failed with error: " << WSAGetLastError() << endl;
  return -1;
 }
 
 cout << "Connected to server!" << endl;
 cout << "Now you can use our live chat application. "  << " Enter \"exit\" to disconnect" << endl;
 
 DWORD tid;
 HANDLE t1 = CreateThread(NULL, 0, clientReceive, &server, 0, &tid);
 if (t1 == NULL) cout << "Thread creation error: " << GetLastError();
 HANDLE t2 = CreateThread(NULL, 0, clientSend, &server, 0, &tid);
 if (t2 == NULL) cout << "Thread creation error: " << GetLastError();

 WaitForSingleObject(t1, INFINITE);
 WaitForSingleObject(t2, INFINITE);
 closesocket(server);
 WSACleanup();
}
