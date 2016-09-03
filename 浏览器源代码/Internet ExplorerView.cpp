// Internet ExplorerView.cpp : implementation of the CInternetExplorerView class
//

#include "stdafx.h"
#include "Internet Explorer.h"

#include "Internet ExplorerDoc.h"
#include "Internet ExplorerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerView

IMPLEMENT_DYNCREATE(CInternetExplorerView, CHtmlView)

BEGIN_MESSAGE_MAP(CInternetExplorerView, CHtmlView)
	//{{AFX_MSG_MAP(CInternetExplorerView)
	ON_COMMAND(ID_GO_BACK, OnGoBack)
	ON_COMMAND(ID_GO_FORWARD, OnGoForward)
	ON_COMMAND(ID_GO_HOME, OnGoHome)
	ON_COMMAND(ID_GO_REFRESH, OnGoRefresh)
	ON_COMMAND(ID_GO_SEARCH, OnGoSearch)
	ON_COMMAND(ID_GO_STOP, OnGoStop)
	ON_COMMAND(ID_HOME, OnHome)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerView construction/destruction

CInternetExplorerView::CInternetExplorerView()
{
	// TODO: add construction code here

}

CInternetExplorerView::~CInternetExplorerView()
{
}

BOOL CInternetExplorerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerView drawing

void CInternetExplorerView::OnDraw(CDC* pDC)
{
	CInternetExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}
CString str="http://www.hao123.com";     //定义一进来出现的页面就是百度的界面
void CInternetExplorerView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T(str),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerView printing


/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerView diagnostics

#ifdef _DEBUG
void CInternetExplorerView::AssertValid() const  //确保该类已经创建窗口
{
	CHtmlView::AssertValid();
}

void CInternetExplorerView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CInternetExplorerDoc* CInternetExplorerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInternetExplorerDoc)));
	return (CInternetExplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerView message handlers

void CInternetExplorerView::OnGoBack() 
{
	// TODO: Add your command handler code here
	GoBack();
}

void CInternetExplorerView::OnGoForward() 
{
	// TODO: Add your command handler code here
	GoForward();
}

void CInternetExplorerView::OnGoHome() 
{
	// TODO: Add your command handler code here
	GoHome();
}

void CInternetExplorerView::OnGoRefresh() 
{
	// TODO: Add your command handler code here
	Refresh();
}

void CInternetExplorerView::OnGoSearch() 
{
	// TODO: Add your command handler code here
	GoSearch();
}

void CInternetExplorerView::OnGoStop() 
{
	// TODO: Add your command handler code here
	Stop();
}



void CInternetExplorerView::OnHome() 
{
	// TODO: Add your command handler code here
	Navigate2(_T(str),NULL,NULL);
}
