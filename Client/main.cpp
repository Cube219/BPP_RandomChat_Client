﻿#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<thread>
#include<string.h>

using namespace std;

enum State {NotConnected, Connected, Searching, Join};
State state = State::NotConnected;

WSAData wsaData;
SOCKET s;
SOCKADDR_IN6 clientAddr;
SOCKADDR_IN aa;

// 초기화
bool Init()
{
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
		return false;
	}

	if(connect(s, (SOCKADDR*)&aa, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		cout << "Fail to Connect" << endl;
		return false;
	}

	state = State::Connected;

	thread* t = new thread(Receive);

	return true;
}

// 서버로부터 오는 데이터를 받아오는 함수
void Receive()
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

// 사람을 찾는 함수
void SearchPeople()
{
	// 연결중 상태 (찾는 중도 아니고 방에 들어간 상태도 아닌)가 아니면 그냥 종료
	if(state != State::Connected)
		return;

	state = State::Searching;
}

// 방에 나가는 함수
void QuitRoom()
{
	// 방에 들어간 상태가 아니면 그냥 종료
	if(state != State::Join)
		return;
}

int main(void)
{
	if(Init() == false) {
		return -1;
	}

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