#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>

using namespace std;

int main(void)
{
	WSAData wsaData;
	SOCKET s;
	SOCKADDR_IN6 clientAddr;
	SOCKADDR_IN aa;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	clientAddr.sin6_family = AF_INET6;
	clientAddr.sin6_flowinfo = 0;
	clientAddr.sin6_port = htons(8888);
	inet_pton(AF_INET6, "2001:19f0:7001:1f35:5400:00ff:fe43:904f", &clientAddr.sin6_addr);

	aa.sin_family = AF_INET;
	aa.sin_port = htons(8888);
	if(inet_pton(AF_INET, "45.76.104.134", &aa.sin_addr.S_un.S_addr) != 1) {
		cout << "H";
		return -1;
	}

	if(connect(s, (SOCKADDR*)&aa, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		cout << "Fail to Connect" << endl;
		return -1;
	}

	char buf[256];
	while(1) {
		int size = recv(s, buf, sizeof(buf), 0);

		if(size <= 0) {
			cout << "Connection End" << endl;
			break;
		}
		cout<<"Received Size :" <<size<<endl;
		cout << "Received Data : " << buf << endl;
	}

	Sleep(3000);

	return 0;
}