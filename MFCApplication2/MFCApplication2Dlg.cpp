
// MFCApplication2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCApplication2Dlg ��ȭ ����



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


// CMFCApplication2Dlg �޽��� ó����

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.
		
	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	// �⺻���ΰ� ��Ȱ
	GetDlgItem(IDENTERMSG)->EnableWindow(false);
	GetDlgItem(IDQUITROOM)->EnableWindow(false);

	// �ʱ�ȭ
	Init();


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*
void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CDialogEx::OnOK();	
}


void CMFCApplication2Dlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}*/

void CMFCApplication2Dlg::OnBnClickedSearching()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SearchPeople();
}



// ----- ���� �Լ��� -----

// �ʱ�ȭ
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
		PrintLogWithClear(L"������ ���ῡ �����Ͽ����ϴ�.");
		return false;
	}

	state = State::Connected;
	PrintLogWithClear(L"������ ���ῡ �����Ͽ����ϴ�.");

	t = new thread(&CMFCApplication2Dlg::Receive, this);

	return true;
}

// �����κ��� ������ �Լ�
void CMFCApplication2Dlg::Send(const string& data)
{
	send(s, data.c_str(), data.size() + 1, 0);
}

// �����κ��� ���� �����͸� �޾ƿ��� �Լ�
void CMFCApplication2Dlg::Receive()
{
	char buf[256];
	while(1) {
		int size = recv(s, buf, sizeof(buf), 0);

		if(size <= 0) { // ������ �����
			PrintLog(L"�������� ������ ����Ǿ����ϴ�.");
			break;
		}

		// �ش� ���������� �м�
		ProcessProtocol(buf);
	}
}

// �������� �м� �Լ�
void CMFCApplication2Dlg::ProcessProtocol(const char* data)
{
	json j = json::parse(data);

	string type = j["protocolType"];

	if(type == "Protocol_ConnectResult") { // ���� ���
		Protocol_ConnectResult p = Protocol_ConnectResult::ToProtocol(data);

		// ���ǰ� ����
		session = p.session;
	} else if(type == "Protocol_FindUserResult") { // ���� ã�� ���
		Protocol_FindUserResult p = Protocol_FindUserResult::ToProtocol(data);
		if(p.resultCode == ResultCode::Sucess) {
			state = State::Join;
			GetDlgItem(IDENTERMSG)->EnableWindow(true);
			GetDlgItem(IDQUITROOM)->EnableWindow(true);
			PrintLog(L"�濡 ���Խ��ϴ�. ��ſ� ä���ϼ���!");
		}
	} else if(type == "Protocol_SendMessageResult") { // �޽��� ������ ���
		Protocol_SendMessageResult p = Protocol_SendMessageResult::ToProtocol(data);
	} else if(type == "Protocol_GetMessage") { // �޽��� ����
		Protocol_GetMessage p = Protocol_GetMessage::ToProtocol(data);
		p.message = L"���� : " + p.message;
		PrintLog(p.message);
	} else if(type == "Protocol_UserLeaved") { // ������ ����
		Protocol_UserLeaved p = Protocol_UserLeaved::ToProtocol(data);
		PrintLog(L"������ ���� �������ϴ�.");
		GetDlgItem(IDENTERMSG)->EnableWindow(false);
		GetDlgItem(IDQUITROOM)->EnableWindow(false);
		GetDlgItem(IDSEARCHING)->EnableWindow(true);
		state = State::Connected;
	}
}

// ����� ã�� �Լ�
void CMFCApplication2Dlg::SearchPeople()
{
	// ������ ���� (ã�� �ߵ� �ƴϰ� �濡 �� ���µ� �ƴ�)�� �ƴϸ� �׳� ����
	if(state != State::Connected)
		return;

	GetDlgItem(IDSEARCHING)->EnableWindow(false);
	
	PrintLogWithClear(L"������ ã�� �ֽ��ϴ�...");
	state = State::Searching;

	// ������ ã�´ٰ� �������� ����
	Protocol_FindUser p;
	p.session = session;
	Send(Protocol_FindUser::ToJson(p));
}

// �濡 ������ �Լ�
void CMFCApplication2Dlg::QuitRoom()
{
	// �濡 �� ���°� �ƴϸ� �׳� ����
	if(state != State::Join)
		return;

	// �濡 �����ٰ� �������� ����
	Protocol_LeaveRoom p;
	p.session = session;
	Send(Protocol_LeaveRoom::ToJson(p));

	state = State::Connected;
	GetDlgItem(IDENTERMSG)->EnableWindow(false);
	GetDlgItem(IDQUITROOM)->EnableWindow(false);
	GetDlgItem(IDSEARCHING)->EnableWindow(true);

	PrintLog(L"���� �������ϴ�.");
}

// �޽��� ����
void CMFCApplication2Dlg::SendMsg(wstring msg)
{
	if(state == State::Join) {
		Protocol_SendMessage p;
		p.message = msg;
		p.session = session;
		Send(Protocol_SendMessage::ToJson(p));

		PrintLog(L"�� : " + msg);
	}
}

// �� ����� ���ο� LOG �߰�
void CMFCApplication2Dlg::PrintLogWithClear(wstring msg)
{
	msg += L"\r\n";
	GetDlgItem(IDMSGLOG)->SetWindowTextW(msg.c_str());
}

// ���ο� LOG �߰�
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication2Dlg::OnEnChangeMsglog()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication2Dlg::OnBnClickedQuitroom()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	QuitRoom();
}


BOOL CMFCApplication2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.


	// ����Ű ó��
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
