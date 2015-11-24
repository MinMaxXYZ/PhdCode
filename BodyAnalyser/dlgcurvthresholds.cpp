// DlgCurvThresholds.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DlgCurvThresholds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgCurvThresholds dialog


CDlgCurvThresholds::CDlgCurvThresholds(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCurvThresholds::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCurvThresholds)
	m_hthres = 0.0f;
	m_lthres = 0.0f;
	m_minridges = FALSE;
	//}}AFX_DATA_INIT
}


void CDlgCurvThresholds::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCurvThresholds)
	DDX_Text(pDX, IDC_HTHRES, m_hthres);
	DDX_Text(pDX, IDC_LTHRES, m_lthres);
	DDX_Check(pDX, IDC_MINRIDGES, m_minridges);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCurvThresholds, CDialog)
	//{{AFX_MSG_MAP(CDlgCurvThresholds)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCurvThresholds message handlers
