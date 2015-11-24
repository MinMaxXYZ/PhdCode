// CurvMapConfirmDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "CurvMapConfirmDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCurvMapConfirmDialog dialog


CCurvMapConfirmDialog::CCurvMapConfirmDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCurvMapConfirmDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCurvMapConfirmDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCurvMapConfirmDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCurvMapConfirmDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCurvMapConfirmDialog, CDialog)
	//{{AFX_MSG_MAP(CCurvMapConfirmDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCurvMapConfirmDialog message handlers
