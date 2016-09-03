// Internet ExplorerDoc.cpp : implementation of the CInternetExplorerDoc class
//

#include "stdafx.h"
#include "Internet Explorer.h"

#include "Internet ExplorerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerDoc

IMPLEMENT_DYNCREATE(CInternetExplorerDoc, CDocument)

BEGIN_MESSAGE_MAP(CInternetExplorerDoc, CDocument)
	//{{AFX_MSG_MAP(CInternetExplorerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerDoc construction/destruction

CInternetExplorerDoc::CInternetExplorerDoc()
{
	// TODO: add one-time construction code here

}

CInternetExplorerDoc::~CInternetExplorerDoc()
{
}

BOOL CInternetExplorerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerDoc serialization

void CInternetExplorerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerDoc diagnostics

#ifdef _DEBUG
void CInternetExplorerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInternetExplorerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInternetExplorerDoc commands
