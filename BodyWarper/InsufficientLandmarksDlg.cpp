// InsufficientLandmarksDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BodyWarper.h"
#include "InsufficientLandmarksDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInsufficientLandmarksDlg dialog


CInsufficientLandmarksDlg::CInsufficientLandmarksDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInsufficientLandmarksDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInsufficientLandmarksDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInsufficientLandmarksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInsufficientLandmarksDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInsufficientLandmarksDlg, CDialog)
	//{{AFX_MSG_MAP(CInsufficientLandmarksDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInsufficientLandmarksDlg message handlers
