
// MFCApplication2Dlg.h : 헤더 파일
//

#pragma once
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<thread>
#include<string.h>
#include<string>
#include"Protocol.h"

using namespace std;

// CMFCApplication2Dlg 대화 상자
class CMFCApplication2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSearching();


private:
	WSAData wsaData;
	SOCKET s;
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
	void SendMsg(wstring msg);

	void PrintLogWithClear(wstring log);
	void PrintLog(wstring log);
public:
	afx_msg void OnEnChangeEntermsg();
	afx_msg void OnEnChangeMsglog();
	afx_msg void OnBnClickedQuitroom();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
