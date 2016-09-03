// Internet ExplorerView.h : interface of the CInternetExplorerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERNETEXPLORERVIEW_H__4CEF959B_45CE_41B2_9191_8E25B97AB4E4__INCLUDED_)
#define AFX_INTERNETEXPLORERVIEW_H__4CEF959B_45CE_41B2_9191_8E25B97AB4E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Internet ExplorerDoc.h"
class CInternetExplorerView : public CHtmlView
{
protected: // create from serialization only
	CInternetExplorerView();
	DECLARE_DYNCREATE(CInternetExplorerView)

// Attributes
public:
	CInternetExplorerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetExplorerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInternetExplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CInternetExplorerView)
	afx_msg void OnGoBack();
	afx_msg void OnGoForward();
	afx_msg void OnGoHome();
	afx_msg void OnGoRefresh();
	afx_msg void OnGoSearch();
	afx_msg void OnGoStop();
	afx_msg void OnSetHome();
	afx_msg void OnHome();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Internet ExplorerView.cpp
inline CInternetExplorerDoc* CInternetExplorerView::GetDocument()
   { return (CInternetExplorerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETEXPLORERVIEW_H__4CEF959B_45CE_41B2_9191_8E25B97AB4E4__INCLUDED_)
