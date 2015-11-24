// NoCurvMapDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "NoCurvMapDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoCurvMapDialog dialog


CNoCurvMapDialog::CNoCurvMapDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNoCurvMapDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoCurvMapDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNoCurvMapDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoCurvMapDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNoCurvMapDialog, CDialog)
	//{{AFX_MSG_MAP(CNoCurvMapDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoCurvMapDialog message handlers
