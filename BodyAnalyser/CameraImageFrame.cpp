// CameraImageFrame.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "CameraImageFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCameraImageFrame

IMPLEMENT_DYNCREATE(CCameraImageFrame, CFrameWnd)

CCameraImageFrame::CCameraImageFrame()
{
}

CCameraImageFrame::~CCameraImageFrame()
{
}


BEGIN_MESSAGE_MAP(CCameraImageFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CCameraImageFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCameraImageFrame message handlers

BOOL CCameraImageFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
