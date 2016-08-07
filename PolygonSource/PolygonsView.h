// PolygonsView.h : interface of the CPolygonsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGONSVIEW_H__A1E1084C_8848_11D5_A716_D2F95E84B678__INCLUDED_)
#define AFX_POLYGONSVIEW_H__A1E1084C_8848_11D5_A716_D2F95E84B678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPolygonsView : public CView
{
protected: // create from serialization only
	CPolygonsView();
	DECLARE_DYNCREATE(CPolygonsView)

// Attributes
public:
	CPolygonsDoc* GetDocument();

// Operations
public:
	// variables added to draw polygon
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolygonsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint PointOld;// previous draw point
	CPoint PointOrigin;// first point
	bool m_Drag;// checks drag mode
	double Ox , Oy , Px , Py;
	double phai ;//angle used by me to compute
	double theta ;//angle used by me to compute
	double hyp ;//hyp = hypotnuse
	double x1 ;
	double mu ;
	double x2 ;
	double y2;
	int m_Sides;// no. of sides of polygon	
	virtual ~CPolygonsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPolygonsView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPolyType();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PolygonsView.cpp
inline CPolygonsDoc* CPolygonsView::GetDocument()
   { return (CPolygonsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONSVIEW_H__A1E1084C_8848_11D5_A716_D2F95E84B678__INCLUDED_)
