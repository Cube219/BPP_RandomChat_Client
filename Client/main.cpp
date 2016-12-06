#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<thread>
#include<string.h>
#include<string>
#include"json.hpp"

using namespace std;

WSAData wsaData;
SOCKET s;
SOCKADDR_IN6 clientAddr;
SOCKADDR_IN aa;

enum State { NotConnected, Connected, Searching, Join };
State state = State::NotConnected;

string session;

thread* t;

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

	t = new thread(Receive);

	return true;
}

// 서버로부터 오는 데이터를 받아오는 함수
void Receive()
{
	char buf[256];
	while(1) {
		int size = recv(s, buf, sizeof(buf), 0);

		if(size <= 0) { // 연결이 종료됨
			cout << "Connection End" << endl;
			break;
		}
		cout << "Received Size :" << size << endl;
		cout << "Received Data : " << buf << endl;

		// 해당 프로토콜을 분석
		ProcessProtocol(buf);
	}
}

// 프로토콜 분석 함수
void ProcessProtocol(const char* data)
{

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

	string d;
	while(1) {
		cin >> d;
		if(d[0] == '!') {
			if(d == "!search") {
				SearchPeople();
			} else if(d == "!quitroom") {
				QuitRoom();
			} else if(d == "!quitprogram") {
				break;
			}
		} else {
			if(state == State::Join) {
			}
		}
	}

	delete t;

	Sleep(3000);

	return 0;
}