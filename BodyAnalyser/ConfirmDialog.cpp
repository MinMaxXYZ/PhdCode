// ConfirmDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "ConfirmDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfirmDialog dialog


CConfirmDialog::CConfirmDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CConfirmDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfirmDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CConfirmDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfirmDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfirmDialog, CDialog)
	//{{AFX_MSG_MAP(CConfirmDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfirmDialog message handlers
