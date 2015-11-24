// DlgEvaluation.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DlgEvaluation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEvaluation dialog


CDlgEvaluation::CDlgEvaluation(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEvaluation::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEvaluation)
	m_dthr = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgEvaluation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEvaluation)
	DDX_Text(pDX, IDC_DTHR, m_dthr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEvaluation, CDialog)
	//{{AFX_MSG_MAP(CDlgEvaluation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEvaluation message handlers

void CDlgEvaluation::OnOK() 
{
	CComboBox* cBox;
	cBox = (CComboBox*) GetDlgItem(IDC_SYMM_TYPE);
	m_sym_type = cBox->GetCurSel();
	CDialog::OnOK();
}
