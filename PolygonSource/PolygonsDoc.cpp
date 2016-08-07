// PolygonsDoc.cpp : implementation of the CPolygonsDoc class
//

#include "stdafx.h"
#include "Polygons.h"

#include "PolygonsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPolygonsDoc

IMPLEMENT_DYNCREATE(CPolygonsDoc, CDocument)

BEGIN_MESSAGE_MAP(CPolygonsDoc, CDocument)
	//{{AFX_MSG_MAP(CPolygonsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolygonsDoc construction/destruction

CPolygonsDoc::CPolygonsDoc()
{
	// TODO: add one-time construction code here

}

CPolygonsDoc::~CPolygonsDoc()
{
}

BOOL CPolygonsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPolygonsDoc serialization

void CPolygonsDoc::Serialize(CArchive& ar)
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
// CPolygonsDoc diagnostics

#ifdef _DEBUG
void CPolygonsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPolygonsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPolygonsDoc commands
