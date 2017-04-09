
// MFC_GL_TestDlg.h : header file
//

#pragma once
#include "MyOpenGL.h"

// CMFC_GL_TestDlg dialog
class CMFC_GL_TestDlg : public CDialog
{
// Construction
public:
	CMFC_GL_TestDlg(CWnd* pParent = NULL);	// standard constructor
	~CMFC_GL_TestDlg(void);
	MyOpenGL* m_GL;

// Dialog Data
	enum { IDD = IDD_MFC_GL_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
