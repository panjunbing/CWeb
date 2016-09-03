// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Internet Explorer.h"

#include "MainFrm.h"
#include "Internet ExplorerView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	
	//}}AFX_MSG_MAP
	ON_CBN_SELENDOK(AFX_IDW_TOOLBAR+1,OnNewAddress)
	ON_COMMAND(IDOK,OnNewAddressEnter)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CImageList img;
	CString str;
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//if (!m_wndToolBar.CreateEx(this))
	//	{
	//		MessageBox("Failed to create toobar");
	//	}
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if(!m_wndReBar.Create(this))
		MessageBox("Failed to create toobar");

	
	
	//创建一个组合框作为地址条
	if(!m_wndAddress.Create(CBS_DROPDOWN|WS_CHILD,CRect(0,0,200,120),this,AFX_IDW_TOOLBAR+1))
	{
		MessageBox("Faild to create combobox");
		return -1;
	}
	//添加工具条 地址到Rebar中
	//m_wndReBar.AddBar(&m_wndToolBar);
	str.LoadString(IDS_ADDRESS);
	m_wndReBar.AddBar(&m_wndAddress,str,NULL,RBBS_FIXEDBMP|RBBS_BREAK);
	//设定ReBar中每个元素大小
	REBARBANDINFO rbbi;
	rbbi.cbSize=sizeof(rbbi);
	rbbi.fMask=RBBIM_CHILDSIZE|RBBIM_IDEALSIZE|RBBIM_SIZE;
	//rbbi.cxMinChild=rectToolBar.Width();
	//rbbi.cyMinChild=rectToolBar.Height();
	//rbbi.cx=rbbi.cxIdeal=rectToolBar.Width()*9;
	//m_wndReBar.GetReBarCtrl().SetBandInfo(0,&rbbi);
	rbbi.cxMinChild=0;
	CRect rectAddress;
	rbbi.fMask=RBBIM_CHILDSIZE|RBBIM_IDEALSIZE;
	m_wndAddress.GetEditCtrl()->GetWindowRect(&rectAddress);
	rbbi.cyMinChild=rectAddress.Height()+10;
	rbbi.cxIdeal=200;
	m_wndReBar.GetReBarCtrl().SetBandInfo(0,&rbbi);
	//m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle()|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_FIXED);
	
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}
void CMainFrame::OnNewAddress()
{
	CString str;
	m_wndAddress.GetLBText(m_wndAddress.GetCurSel(),str);
	((CInternetExplorerView*)GetActiveView())->Navigate2(str,0,NULL);
}
void CMainFrame::OnNewAddressEnter()
{
	CString str;
	m_wndAddress.GetEditCtrl()->GetWindowText(str);
	((CInternetExplorerView*)GetActiveView())->Navigate2(str,0,NULL);
	COMBOBOXEXITEM item;
	item.mask=CBEIF_TEXT;
	item.iItem=-1;
	item.pszText=(LPTSTR)(LPCTSTR)str;
	m_wndAddress.InsertItem(&item);
}
/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


