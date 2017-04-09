
// MFC_GL_Test.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_GL_TestApp:
// See MFC_GL_Test.cpp for the implementation of this class
//

class CMFC_GL_TestApp : public CWinApp
{
public:
	CMFC_GL_TestApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_GL_TestApp theApp;