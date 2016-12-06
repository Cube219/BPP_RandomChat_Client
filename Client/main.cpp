#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<thread>
#include<string.h>
#include<string>
#include"json.hpp"
#include"Protocol.h"

using namespace std;

WSAData wsaData;
SOCKET s;
SOCKADDR_IN6 clientAddr;
SOCKADDR_IN aa;

enum State { NotConnected, Connected, Searching, Join };
State state = State::NotConnected;

string session;

thread* t;

bool Init();
void Send(const string& data);
void Receive();
void ProcessProtocol(const char* data);
void SearchPeople();
void QuitRoom();

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

// 서버로부터 보내는 함수
void Send(const string& data)
{
	send(s, data.c_str(), data.size() + 1, 0);
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
	json j = json::parse(data);

	string type = j["protocolType"];

	if(type == "Protocol_ConnectResult") { // 연결 결과
		Protocol_ConnectResult p = Protocol_ConnectResult::ToProtocol(data);

		// 세션값 얻어옴
		session = p.session;
	} else if(type == "Protocol_FindUserResult") { // 유저 찾기 결과
		Protocol_FindUserResult p = Protocol_FindUserResult::ToProtocol(data);
	} else if(type == "Protocol_SendMessageResult") { // 메시지 보내기 결과
		Protocol_SendMessageResult p = Protocol_SendMessageResult::ToProtocol(data);
	} else if(type == "Protocol_GetMessage") { // 메시지 받음
		Protocol_GetMessage p = Protocol_GetMessage::ToProtocol(data);
	} else if(type == "Protocol_UserLeaved") { // 유저가 나감
		Protocol_UserLeaved p = Protocol_UserLeaved::ToProtocol(data);
	}
}

// 사람을 찾는 함수
void SearchPeople()
{
	// 연결중 상태 (찾는 중도 아니고 방에 들어간 상태도 아닌)가 아니면 그냥 종료
	if(state != State::Connected)
		return;

	state = State::Searching;

	// 유저를 찾는다고 서버에게 보냄
	Protocol_FindUser p;
	p.session = session;
	Send(Protocol_FindUser::ToJson(p));
}

// 방에 나가는 함수
void QuitRoom()
{
	// 방에 들어간 상태가 아니면 그냥 종료
	if(state != State::Join)
		return;

	// 방에 나간다고 서버에게 보냄
	Protocol_LeaveRoom p;
	p.session = session;
	Send(Protocol_LeaveRoom::ToJson(p));
}

int main(void)
{
	if(Init() == false) {
		return -1;
	}

	wstring d;
	while(1) {
		wcin >> d;
		if(d[0] == L'!') {
			if(d == L"!search") {
				SearchPeople();
			} else if(d == L"!quitroom") {
				QuitRoom();
			} else if(d == L"!quitprogram") {
				break;
			}
		} else {
			if(state == State::Join) {
				Protocol_SendMessage p;
				p.message = d;
				p.session = session;
				Send(Protocol_SendMessage::ToJson(p));
			}
		}
	}

	delete t;

	Sleep(3000);

	return 0;
}