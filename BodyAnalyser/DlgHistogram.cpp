// DlgHistogram.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DlgHistogram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram dialog


CDlgHistogram::CDlgHistogram(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHistogram::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgHistogram)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgHistogram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgHistogram)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgHistogram, CDialog)
	//{{AFX_MSG_MAP(CDlgHistogram)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram message handlers

void CDlgHistogram::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CDlgHistogram::AttachDocument(CBodyAnalyserDoc* pDoc)
{
	m_pDoc = pDoc;
}


void CDlgHistogram::OnPaint() 
{
	CPaintDC m_DC(this); // device context for painting
	
	unsigned int x_offset = 40;
	unsigned int y_offset = 25;
	unsigned int x_width = 507;
	unsigned int y_height = 135;
	unsigned int under_frame_margin = 20;
	unsigned int rec_width = x_width;
	unsigned int rec_height = y_height - under_frame_margin;

	DrawHistogram(&m_DC,&(m_pDoc->h_gaussian),	x_offset,y_offset,y_height,rec_width,rec_height,0,"Gaussian Curvature");
	DrawHistogram(&m_DC,&(m_pDoc->h_mean),		x_offset,y_offset,y_height,rec_width,rec_height,1,"Mean Curvature");
	DrawHistogram(&m_DC,&(m_pDoc->h_curvedness),x_offset,y_offset,y_height,rec_width,rec_height,2,"Curvedness");
	DrawHistogram(&m_DC,&(m_pDoc->h_shapeindex),x_offset,y_offset,y_height,rec_width,rec_height,3,"Shape Index");
}
/*
CDocument* CDlgHistogram::GetDocument()
{
	return m_pDoc;
}
*/
void CDlgHistogram::DrawHistogram(	CPaintDC* m_DC, CHistogram* h, 
								    unsigned int x_offset, unsigned int y_offset, 
									unsigned int y_height, 
									unsigned int rec_width,unsigned int rec_height,
									unsigned int f,
									CString s_label)
{
	unsigned int x, y;
	unsigned int n_clusters = h->GetNClusters(); 
	unsigned long int	peak	= h->GetPeak();
	unsigned int		peakPos	= h->GetPeakPos();
	long double			peakVal	= h->GetPeakVal();
	int x_shift =  2;
	int y_shift = -2;

	CPen blackPen(PS_SOLID,1,RGB(0,0,0));
	CPen bluePen(PS_SOLID,1,RGB(0,0,255));
	CPen greyPen(PS_SOLID,1,RGB(96,96,96));

	m_DC->SelectObject(blackPen);
	m_DC->SetViewportOrg(x_offset,y_offset+((y_offset+y_height)*f));
	m_DC->Rectangle(0,0,rec_width,rec_height);

	m_DC->MoveTo(0+x_shift,rec_height-0+y_shift);
	m_DC->SelectObject(bluePen);
	for(x = 0; x < n_clusters; x++)
	{
		y = rec_height -  ( ((float)(h->Get(x)) / (float)peak) *  (float)(rec_height-2) );
		m_DC->LineTo(x+x_shift,y+y_shift);
	}

	m_DC->SelectObject(greyPen);
	m_DC->MoveTo(-15,-20);
	m_DC->LineTo(rec_width+220,-20);

	m_DC->SetBkColor(RGB(128,128,128));

	CFont f_bold9;
	f_bold9.CreateFont(9,0,0,0,FW_BOLD,0,0,0,1,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"MS Sans Serif");
	m_DC->SelectObject(f_bold9);
	m_DC->TextOut(rec_width+20,-15,s_label);

	CFont f_normal9;
	f_normal9.CreateFont(9,0,0,0,FW_NORMAL,0,0,0,1,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"MS Sans Serif");
	m_DC->SelectObject(f_normal9);

	int u_txt_margin = -15;
	int l_txt_margin = rec_height+6;
	char buffer[8];

	m_DC->TextOut(0+x_shift,			u_txt_margin,	itoa(h->Get(0)				, buffer, 7));
	m_DC->TextOut(peakPos+x_shift,		u_txt_margin,	itoa(peak					, buffer, 7));
	m_DC->TextOut(n_clusters+x_shift,	u_txt_margin,	itoa(h->Get(n_clusters-1)	, buffer, 7));

	m_DC->TextOut(0+x_shift,			l_txt_margin,	gcvt(h->GetMin()			, 7, buffer));
	m_DC->TextOut(peakPos+x_shift,		l_txt_margin,	gcvt(peakVal				, 7, buffer));
	m_DC->TextOut(n_clusters+x_shift,	l_txt_margin,	gcvt(h->GetMax()			, 7, buffer));
}
