
// MFC_GL_TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_GL_Test.h"
#include "MFC_GL_TestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_GL_TestDlg dialog




CMFC_GL_TestDlg::CMFC_GL_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_GL_TestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_GL=NULL;
}

CMFC_GL_TestDlg::~CMFC_GL_TestDlg(void)
{
	if (m_GL)
	{
		delete m_GL;
		m_GL=NULL;
	}
}

void CMFC_GL_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_GL_TestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_GL_TestDlg::OnBnClickedButton1)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CMFC_GL_TestDlg message handlers

BOOL CMFC_GL_TestDlg::OnInitDialog()
	{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
		
	// ����OpenGL��ͼ���ڵľ��δ�С
	//�˶�������OnInitDialog(),����OnCreate��
	CRect rect(0,0,300,300);
	m_GL=new MyOpenGL;//��New�ķ�ʽ����
	m_GL->Create( NULL,   //ȱʡ�Ĵ���
		NULL,   //�޴�������
		WS_CHILD|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_VISIBLE,
		// ���崰�ڷ��
		rect,   // ���ڵĴ�С
		this,   // ָ����ǰ�Ի���Ϊ�丸����ָ��
		0);   
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_GL_TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_GL_TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_GL_TestDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	Invalidate();
}


int CMFC_GL_TestDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	
	return 0;
}
