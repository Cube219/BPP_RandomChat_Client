#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<thread>
#include<string.h>

using namespace std;

enum State {NotConnected, Connected, Searching, Join};
State state = State::NotConnected;

void Receive(SOCKET s)
{
	char buf[256];
	while(1) {
		int size = recv(s, buf, sizeof(buf), 0);

		if(size <= 0) {
			cout << "Connection End" << endl;
			break;
		}
		cout << "Received Size :" << size << endl;
		cout << "Received Data : " << buf << endl;
	}
}

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

	state = State::Connected;

	thread* t = new thread(Receive, s);

	char d[101];
	while(1) {
		cin >> d;
		if(d[0] == '!') {
			if(strcmp(d, "!search") == 0) {
			} else if(strcmp(d, "!quit") == 0) {
			}
		} else {

		}
	}

	Sleep(3000);

	return 0;
}