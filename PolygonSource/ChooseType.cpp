// ChooseType.cpp : implementation file
//

#include "stdafx.h"
#include "Polygons.h"
#include "ChooseType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChooseType dialog


CChooseType::CChooseType(CWnd* pParent /*=NULL*/)
	: CDialog(CChooseType::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChooseType)
	m_Type = 0;
	//}}AFX_DATA_INIT
}


void CChooseType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChooseType)
	DDX_Text(pDX, IDC_EDIT1, m_Type);
	DDV_MinMaxInt(pDX, m_Type, 3, 15);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChooseType, CDialog)
	//{{AFX_MSG_MAP(CChooseType)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChooseType message handlers
