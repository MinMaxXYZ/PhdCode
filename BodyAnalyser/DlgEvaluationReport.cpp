// DlgEvaluationReport.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DlgEvaluationReport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEvaluationReport dialog


CDlgEvaluationReport::CDlgEvaluationReport(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEvaluationReport::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEvaluationReport)
	m_dthr = 0.0f;
	m_n_falsepositives = 0;
	m_hthr = 0.0f;
	m_lthr = 0.0f;
	m_n_truepositives = 0;
	m_P = 0;
	//}}AFX_DATA_INIT
}


void CDlgEvaluationReport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEvaluationReport)
	DDX_Text(pDX, IDC_DTHR, m_dthr);
	DDX_Text(pDX, IDC_FALSEPOSITIVES, m_n_falsepositives);
	DDX_Text(pDX, IDC_HTHR, m_hthr);
	DDX_Text(pDX, IDC_LTHR, m_lthr);
	DDX_Text(pDX, IDC_TRUEPOSITIVES, m_n_truepositives);
	DDX_Text(pDX, IDC_ALLPOSITIVES, m_P);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEvaluationReport, CDialog)
	//{{AFX_MSG_MAP(CDlgEvaluationReport)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEvaluationReport message handlers
