// Internet Explorer.h : main header file for the INTERNET EXPLORER application
//

#if !defined(AFX_INTERNETEXPLORER_H__7CE2A099_2DAA_4CFE_BD0D_C231807EF069__INCLUDED_)
#define AFX_INTERNETEXPLORER_H__7CE2A099_2DAA_4CFE_BD0D_C231807EF069__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerApp:
// See Internet Explorer.cpp for the implementation of this class
//

class CInternetExplorerApp : public CWinApp
{
public:
	CInternetExplorerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetExplorerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CInternetExplorerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETEXPLORER_H__7CE2A099_2DAA_4CFE_BD0D_C231807EF069__INCLUDED_)
