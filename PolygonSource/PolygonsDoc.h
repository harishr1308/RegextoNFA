// PolygonsDoc.h : interface of the CPolygonsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGONSDOC_H__A1E1084A_8848_11D5_A716_D2F95E84B678__INCLUDED_)
#define AFX_POLYGONSDOC_H__A1E1084A_8848_11D5_A716_D2F95E84B678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPolygonsDoc : public CDocument
{
protected: // create from serialization only
	CPolygonsDoc();
	DECLARE_DYNCREATE(CPolygonsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolygonsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPolygonsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPolygonsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONSDOC_H__A1E1084A_8848_11D5_A716_D2F95E84B678__INCLUDED_)
