// Polygons.h : main header file for the POLYGONS application
//

#if !defined(AFX_POLYGONS_H__A1E10844_8848_11D5_A716_D2F95E84B678__INCLUDED_)
#define AFX_POLYGONS_H__A1E10844_8848_11D5_A716_D2F95E84B678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPolygonsApp:
// See Polygons.cpp for the implementation of this class
//

class CPolygonsApp : public CWinApp
{
public:
	CPolygonsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolygonsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPolygonsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONS_H__A1E10844_8848_11D5_A716_D2F95E84B678__INCLUDED_)
