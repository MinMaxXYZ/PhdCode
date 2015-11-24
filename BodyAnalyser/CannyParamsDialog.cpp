// CannyParamsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "CannyParamsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCannyParamsDialog dialog


CCannyParamsDialog::CCannyParamsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCannyParamsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCannyParamsDialog)
	m_lower_threshold = 0;
	m_masksize = 0;
	m_upper_threshold = 0;
	//}}AFX_DATA_INIT
}


void CCannyParamsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCannyParamsDialog)
	DDX_Text(pDX, IDC_LOWER_THRESHOLD, m_lower_threshold);
	DDV_MinMaxInt(pDX, m_lower_threshold, 0, 255);
	DDX_Text(pDX, IDC_MASKSIZE, m_masksize);
	DDV_MinMaxInt(pDX, m_masksize, 7, 25);
	DDX_Text(pDX, IDC_UPPER_THRESHOLD, m_upper_threshold);
	DDV_MinMaxInt(pDX, m_upper_threshold, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCannyParamsDialog, CDialog)
	//{{AFX_MSG_MAP(CCannyParamsDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCannyParamsDialog message handlers
