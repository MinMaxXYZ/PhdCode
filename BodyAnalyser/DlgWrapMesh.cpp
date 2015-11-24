// DlgWrapMesh.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DlgWrapMesh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgWrapMesh dialog


CDlgWrapMesh::CDlgWrapMesh(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgWrapMesh::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgWrapMesh)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgWrapMesh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgWrapMesh)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgWrapMesh, CDialog)
	//{{AFX_MSG_MAP(CDlgWrapMesh)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgWrapMesh message handlers
