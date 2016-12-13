
// MFCApplication2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 대화 상자



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDSEARCHING, &CMFCApplication2Dlg::OnBnClickedSearching)
	ON_EN_CHANGE(IDENTERMSG, &CMFCApplication2Dlg::OnEnChangeEntermsg)
	ON_EN_CHANGE(IDMSGLOG, &CMFCApplication2Dlg::OnEnChangeMsglog)
	ON_BN_CLICKED(IDQUITROOM, &CMFCApplication2Dlg::OnBnClickedQuitroom)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 메시지 처리기

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
		
	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// 기본적인거 비활
	GetDlgItem(IDENTERMSG)->EnableWindow(false);
	GetDlgItem(IDQUITROOM)->EnableWindow(false);

	// 초기화
	Init();


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*
void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();	
}


void CMFCApplication2Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}*/

void CMFCApplication2Dlg::OnBnClickedSearching()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SearchPeople();
}



// ----- 각종 함수들 -----

// 초기화
bool CMFCApplication2Dlg::Init()
{
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	aa.sin_family = AF_INET;
	aa.sin_port = htons(8888);
	if(inet_pton(AF_INET, "45.76.104.134", &aa.sin_addr.S_un.S_addr) != 1) {
		return false;
	}

	if(connect(s, (SOCKADDR*)&aa, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		PrintLogWithClear(L"서버와 연결에 실패하였습니다.");
		return false;
	}

	state = State::Connected;
	PrintLogWithClear(L"서버와 연결에 성공하였습니다.");

	t = new thread(&CMFCApplication2Dlg::Receive, this);

	return true;
}

// 서버로부터 보내는 함수
void CMFCApplication2Dlg::Send(const string& data)
{
	send(s, data.c_str(), data.size() + 1, 0);
}

// 서버로부터 오는 데이터를 받아오는 함수
void CMFCApplication2Dlg::Receive()
{
	char buf[256];
	while(1) {
		int size = recv(s, buf, sizeof(buf), 0);

		if(size <= 0) { // 연결이 종료됨
			PrintLog(L"서버와의 연결이 종료되었습니다.");
			break;
		}

		// 해당 프로토콜을 분석
		ProcessProtocol(buf);
	}
}

// 프로토콜 분석 함수
void CMFCApplication2Dlg::ProcessProtocol(const char* data)
{
	json j = json::parse(data);

	string type = j["protocolType"];

	if(type == "Protocol_ConnectResult") { // 연결 결과
		Protocol_ConnectResult p = Protocol_ConnectResult::ToProtocol(data);

		// 세션값 얻어옴
		session = p.session;
	} else if(type == "Protocol_FindUserResult") { // 유저 찾기 결과
		Protocol_FindUserResult p = Protocol_FindUserResult::ToProtocol(data);
		if(p.resultCode == ResultCode::Sucess) {
			state = State::Join;
			GetDlgItem(IDENTERMSG)->EnableWindow(true);
			GetDlgItem(IDQUITROOM)->EnableWindow(true);
			PrintLog(L"방에 들어왔습니다. 즐거운 채팅하세요!");
		}
	} else if(type == "Protocol_SendMessageResult") { // 메시지 보내기 결과
		Protocol_SendMessageResult p = Protocol_SendMessageResult::ToProtocol(data);
	} else if(type == "Protocol_GetMessage") { // 메시지 받음
		Protocol_GetMessage p = Protocol_GetMessage::ToProtocol(data);
		p.message = L"상대방 : " + p.message;
		PrintLog(p.message);
	} else if(type == "Protocol_UserLeaved") { // 유저가 나감
		Protocol_UserLeaved p = Protocol_UserLeaved::ToProtocol(data);
		PrintLog(L"상대방이 방을 나갔습니다.");
		GetDlgItem(IDENTERMSG)->EnableWindow(false);
		GetDlgItem(IDQUITROOM)->EnableWindow(false);
		GetDlgItem(IDSEARCHING)->EnableWindow(true);
		state = State::Connected;
	}
}

// 사람을 찾는 함수
void CMFCApplication2Dlg::SearchPeople()
{
	// 연결중 상태 (찾는 중도 아니고 방에 들어간 상태도 아닌)가 아니면 그냥 종료
	if(state != State::Connected)
		return;

	GetDlgItem(IDSEARCHING)->EnableWindow(false);
	
	PrintLogWithClear(L"유저를 찾고 있습니다...");
	state = State::Searching;

	// 유저를 찾는다고 서버에게 보냄
	Protocol_FindUser p;
	p.session = session;
	Send(Protocol_FindUser::ToJson(p));
}

// 방에 나가는 함수
void CMFCApplication2Dlg::QuitRoom()
{
	// 방에 들어간 상태가 아니면 그냥 종료
	if(state != State::Join)
		return;

	// 방에 나간다고 서버에게 보냄
	Protocol_LeaveRoom p;
	p.session = session;
	Send(Protocol_LeaveRoom::ToJson(p));

	state = State::Connected;
	GetDlgItem(IDENTERMSG)->EnableWindow(false);
	GetDlgItem(IDQUITROOM)->EnableWindow(false);
	GetDlgItem(IDSEARCHING)->EnableWindow(true);

	PrintLog(L"방을 나갔습니다.");
}

// 메시지 보냄
void CMFCApplication2Dlg::SendMsg(wstring msg)
{
	if(state == State::Join) {
		Protocol_SendMessage p;
		p.message = msg;
		p.session = session;
		Send(Protocol_SendMessage::ToJson(p));

		PrintLog(L"나 : " + msg);
	}
}

// 다 지우고 새로운 LOG 추가
void CMFCApplication2Dlg::PrintLogWithClear(wstring msg)
{
	msg += L"\r\n";
	GetDlgItem(IDMSGLOG)->SetWindowTextW(msg.c_str());
}

// 새로운 LOG 추가
void CMFCApplication2Dlg::PrintLog(wstring msg)
{
	CString t;
	GetDlgItem(IDMSGLOG)->GetWindowTextW(t);
	msg += L"\r\n";
	t.Append(msg.c_str());
	GetDlgItem(IDMSGLOG)->SetWindowTextW(t);
}

void CMFCApplication2Dlg::OnEnChangeEntermsg()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication2Dlg::OnEnChangeMsglog()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication2Dlg::OnBnClickedQuitroom()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	QuitRoom();
}


BOOL CMFCApplication2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


	// 엔터키 처리
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) {
		if(GetFocus() == GetDlgItem(IDENTERMSG)) {
			CString m;
			GetDlgItem(IDENTERMSG)->GetWindowTextW(m);
			wstring m1 = m;
			SendMsg(m1);

			GetDlgItem(IDENTERMSG)->SetWindowTextW(L"");
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
