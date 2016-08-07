// PolygonsView.cpp : implementation of the CPolygonsView class
//*************************************************************
// made by Mayank Malik (www.mayankmalik.cjb.net)
//this code was written by me while working on LCE-CAD 
//www.lcecad.cjb.net 
//
//
//
//**************************************************************

#include "stdafx.h"
#include "Polygons.h"

#include "PolygonsDoc.h"
#include "PolygonsView.h"

#include "math.h" // added for sin / tan etc .functions
const double PI = 3.141592654; // value of pi
#include "ChooseType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPolygonsView

IMPLEMENT_DYNCREATE(CPolygonsView, CView)

BEGIN_MESSAGE_MAP(CPolygonsView, CView)
	//{{AFX_MSG_MAP(CPolygonsView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_POLY_TYPE, OnPolyType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolygonsView construction/destruction

CPolygonsView::CPolygonsView()
{
	// TODO: add construction code here
	m_Drag = false;
	m_Sides = 3;
	

}

CPolygonsView::~CPolygonsView()
{
}

BOOL CPolygonsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonsView drawing

void CPolygonsView::OnDraw(CDC* pDC)
{
	CPolygonsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonsView diagnostics

#ifdef _DEBUG
void CPolygonsView::AssertValid() const
{
	CView::AssertValid();
}

void CPolygonsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPolygonsDoc* CPolygonsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolygonsDoc)));
	return (CPolygonsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPolygonsView message handlers

void CPolygonsView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Drag = true;// for mouse drag check
	PointOrigin = point;// value when mouse drag starts
	CView::OnLButtonDown(nFlags, point);
}

void CPolygonsView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Drag = false;// for mouse drag check
	CView::OnLButtonUp(nFlags, point);
}

void CPolygonsView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_Drag && PointOrigin!=point)// for mouse drag check
	{
		
		CClientDC ClientDC(this);// INITIALIZE GRAPHICS
		ClientDC.SetROP2(R2_NOT);
		Ox = PointOrigin.x;
		Oy = PointOrigin.y;
		Px = PointOld.x;
		Py = PointOld.y;
		phai = PI / ( m_Sides );
		theta = PI / 2 - phai;
		hyp = sqrt( ( Px - Ox ) * ( Px - Ox ) + ( Py - Oy ) * ( Py - Oy ) );
		//hyp = hypotnuse
		// erase the previous drawn polygon
		for ( int f = 0;f < m_Sides;f ++ )
		{

			x1 = hyp * cos( theta );
			mu = atan2( Py - Oy , Px - Ox );
			x2 = x1 * cos( ( mu - theta ) );
			y2 = x1 * sin( ( mu - theta ) );
			ClientDC.MoveTo( int( Px ) , int( Py ) );
			ClientDC.LineTo( int( Px - 2 * x2 ) , int( Py - 2 * y2 ) );
			Px = int( Px - 2 * x2 );
			Py = int( Py - 2 * y2 );


		}
		// draw the new polygon
		Px = point.x;
		Py = point.y;
		hyp = sqrt( ( Px - Ox ) * ( Px - Ox ) + ( Py - Oy ) * ( Py - Oy ) );
		for ( f = 0;f < m_Sides;f ++ )
		{

			x1 = hyp * cos( theta );
			mu = atan2( Py - Oy , Px - Ox );
			x2 = x1 * cos( ( mu - theta ) );
			y2 = x1 * sin( ( mu - theta ) );
			ClientDC.MoveTo( int( Px ) , int( Py ) );
			ClientDC.LineTo( int( Px - 2 * x2 ) , int( Py - 2 * y2 ) );
			Px = int( Px - 2 * x2 );
			Py = int( Py - 2 * y2 );


		}
		

	}
	PointOld = point;// used to erase the previous drawn figure
	CView::OnMouseMove(nFlags, point);
}

void CPolygonsView::OnPolyType() 
{
	// TODO: Add your command handler code here
	CChooseType dlg;
	dlg.m_Type = m_Sides;
	if (dlg.DoModal() == IDOK)
		m_Sides = dlg.m_Type;
}

