// DlgCurvatureProgress.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DlgCurvatureProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCurvatureProgress dialog


CDlgCurvatureProgress::CDlgCurvatureProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCurvatureProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCurvatureProgress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}



void CDlgCurvatureProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCurvatureProgress)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCurvatureProgress, CDialog)
	//{{AFX_MSG_MAP(CDlgCurvatureProgress)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCurvatureProgress message handlers
