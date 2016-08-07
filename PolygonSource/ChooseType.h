#if !defined(AFX_CHOOSETYPE_H__A1E10853_8848_11D5_A716_D2F95E84B678__INCLUDED_)
#define AFX_CHOOSETYPE_H__A1E10853_8848_11D5_A716_D2F95E84B678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ChooseType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChooseType dialog

class CChooseType : public CDialog
{
// Construction
public:
	CChooseType(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChooseType)
	enum { IDD = IDD_DIALOG1 };
	int		m_Type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChooseType)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CChooseType)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSETYPE_H__A1E10853_8848_11D5_A716_D2F95E84B678__INCLUDED_)
