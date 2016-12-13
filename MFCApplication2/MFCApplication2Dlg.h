
// MFCApplication2Dlg.h : ��� ����
//

#pragma once
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<thread>
#include<string.h>
#include<string>
#include"Protocol.h"

using namespace std;

// CMFCApplication2Dlg ��ȭ ����
class CMFCApplication2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
