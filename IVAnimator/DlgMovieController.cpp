// DlgMovieController.cpp : implementation file
//

#include "stdafx.h"
#include "IVAnimator.h"
#include "DlgMovieController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMovieController dialog


CDlgMovieController::CDlgMovieController(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMovieController::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMovieController)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_pDoc = 0;
}


void CDlgMovieController::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMovieController)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	if(m_pDoc)
	{
		CSliderCtrl* pSpeed = (CSliderCtrl*) GetDlgItem(IDC_SPEED);
		m_pDoc->myblinker->speed.setValue((pSpeed->GetPos())/10.0);
	}

}


BEGIN_MESSAGE_MAP(CDlgMovieController, CDialog)
	//{{AFX_MSG_MAP(CDlgMovieController)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, OnButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMovieController message handlers

void CDlgMovieController::AttachDocument(CIVAnimatorDoc* d)
{
	m_pDoc = d;

	CSliderCtrl* pSpeed = (CSliderCtrl*) GetDlgItem(IDC_SPEED);
	pSpeed->SetRange(1,30);
	pSpeed->SetPos((int)((m_pDoc->myblinker->speed.getValue())*10));

	int sk = pSpeed->GetPos();
}

void CDlgMovieController::OnButtonPause() 
{
	m_pDoc->myblinker->on = FALSE;
}


void CDlgMovieController::OnButtonPlay() 
{
	m_pDoc->myblinker->on = TRUE;
}

void CDlgMovieController::OnButtonStart() 
{
	m_pDoc->myblinker->on = FALSE;
	m_pDoc->myblinker->whichChild = 0;
}

void CDlgMovieController::OnButtonEnd() 
{
	m_pDoc->myblinker->on = FALSE;
	m_pDoc->myblinker->whichChild = (m_pDoc->n_frames)-1;
}

void CDlgMovieController::OnButtonNext() 
{
	m_pDoc->myblinker->on = FALSE;
	unsigned int c = m_pDoc->myblinker->whichChild.getValue();
	if (c<((m_pDoc->n_frames)-1)) 
	{
		m_pDoc->myblinker->whichChild = c+1;
	}
}

void CDlgMovieController::OnButtonPrevious() 
{
	m_pDoc->myblinker->on = FALSE;
	unsigned int c = m_pDoc->myblinker->whichChild.getValue();
	if (c>0) 
	{
		m_pDoc->myblinker->whichChild = c-1;
	}
}

BOOL CDlgMovieController::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDlgMovieController::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int nControl = pScrollBar->GetDlgCtrlID();
	CSliderCtrl* pSpeed = (CSliderCtrl*)GetDlgItem(nControl);

	if(m_pDoc) {m_pDoc->myblinker->speed.setValue((pSpeed->GetPos())/10.0);}

	//UpdateData(TRUE);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
