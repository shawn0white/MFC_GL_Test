#pragma once
#include "afxwin.h"
#include <gl/glut.h>
#include<math.h>
class MyOpenGL :
	public CWnd
{
public:
	MyOpenGL(void);
	~MyOpenGL(void);
	//////////////////////////////////////////////////////////////////////////
	//成员变量
	int MySetPixelFormat(HDC hDC);
	void DrawColorBox(void);
	void Rendercene();
	void LightShine(void);
	void OnTimer(UINT nIDEvent);
	HDC hdc;
	HGLRC hglrc;
	//////////////////////////////////////////////////////////////////////////
	GLfloat step,s;

	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

