// CamViewerView.cpp : implementation of the CCamViewerView class
//

#include "stdafx.h"
#include "CamViewer.h"

#include "CamViewerDoc.h"
#include "CamViewerView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCamViewerView

IMPLEMENT_DYNCREATE(CCamViewerView, CScrollView)

BEGIN_MESSAGE_MAP(CCamViewerView, CScrollView)
	//{{AFX_MSG_MAP(CCamViewerView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamViewerView construction/destruction

CCamViewerView::CCamViewerView()
{
	// TODO: add construction code here

}

CCamViewerView::~CCamViewerView()
{
}

BOOL CCamViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCamViewerView drawing

void CCamViewerView::OnDraw(CDC* pDC)
{
	ClearViewPort(pDC);
	DrawCameraImages(pDC);
	DrawAngleImages(pDC, HORZ);
	DrawAngleImages(pDC, VERT);
	//DrawAngleDerivs(pDC, HORZ);
	//DrawAngleDerivs(pDC, VERT);

}

void CCamViewerView::DrawCameraImages(CDC* pDC)
{
	CCamViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int slice, index;
	int r,g,b;
	int count = 2;
	
	int offset_y = 8;
	int offset_x = pDoc->N_LEDS + offset_y;

	int (* id)[MAX_N_SLICES][MAX_N_LEDS];

	for(int i = 0; i < pDoc->N_CAMERAS; i++)
	{

	switch (i)
		{
			case 0:	id = &(pDoc->imageData0);	break;
			case 1:	id = &(pDoc->imageData1);	break;
			case 2:	id = &(pDoc->imageData2);	break;
			case 3:	id = &(pDoc->imageData3);	break;
			case 4:	id = &(pDoc->imageData4);	break;
			case 5:	id = &(pDoc->imageData5);	break;
			case 6:	id = &(pDoc->imageData6);	break;
			case 7:	id = &(pDoc->imageData7);	break;
		default:	break;
		}
	
		
		for(slice = 0; slice < pDoc->N_SLICES; slice++)
		{
			for(index = 0; index < pDoc->N_LEDS; index++)
			{
				if ( 	 ((* id)[slice][index]) >= 0	)
				{ r = g = b = ((* id)[slice][index]); }
				else
				{ r = R_VOID; g = G_VOID; b = B_VOID; }
		
				pDC->SetPixel(	
								(index+(count*offset_x)+offset_y),
								slice+offset_y,
								RGB(r,g,b));	
		
			}// for leds
		}//for slices
		count = (count+1)%(pDoc->N_CAMERAS);
	
	}//for cameras

	

}

void CCamViewerView::DrawAngleImages(CDC* pDC, int direction)
{
	CCamViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int slice, index;
	int r,g,b;
	int count = 2;
	
	int offset_y = 8;
	int offset_x = (pDoc->N_LEDS) + offset_y;
	int dx = IMG_X_OFFSET*(direction) + IMG_X_OFFSET;

	float (* ad)[MAX_N_SLICES][MAX_N_LEDS][2];
	float curr_angle;
	float w = 0.82; // window factor, must be in [0,1]

	for(int i = 0; i < pDoc->N_CAMERAS; i++)
	{

	switch (i)
		{
			case 0:	ad = &(pDoc->angleData0);	break;
			case 1:	ad = &(pDoc->angleData1);	break;
			case 2:	ad = &(pDoc->angleData2);	break;
			case 3:	ad = &(pDoc->angleData3);	break;
			case 4:	ad = &(pDoc->angleData4);	break;
			case 5:	ad = &(pDoc->angleData5);	break;
			case 6:	ad = &(pDoc->angleData6);	break;
			case 7:	ad = &(pDoc->angleData7);	break;
		default:	break;
		}
	
		for(slice = 0; slice < pDoc->N_SLICES; slice++)
		{
			for(index = 0; index < pDoc->N_LEDS; index++)
			{
				curr_angle = (* ad)[slice][index][direction];
				if (curr_angle==VOID_ANGLE)
				{
					pDC->SetPixel(	(index+(count*offset_x)+offset_y+dx),
									slice+offset_y,
									RGB(R_VOID,G_VOID,B_VOID)
									);	
				}
				else
				{
					float t = PI*0.75;
					/*
					if (curr_angle>t)									//convex
					{
						r = b = 0; g = 255;
						//g = (int)floor((curr_angle*256.0)/(PI*w));
					}
					if (curr_angle< (-1.0*t))							//concave
					{
						g = b = 0; r = 255;
						//r = (int)floor((curr_angle*(-256.0))/(PI*w));
					}
					if ( (curr_angle<=t) && (curr_angle>=(-1.0*t)) )	//flat
					{
						r = g = 255; b = 0;
						//r = (int)floor((curr_angle*(-256.0))/(PI*w));
					}
					*/
					if 	((curr_angle < t) && (curr_angle > 0))			//very (unlikely) convex
					{
						r = b = 0; g = 255;
					}
					if 	((curr_angle < 0) && (curr_angle > (-1.0*t)))	//very (unlikely) concave
					{
						g = b = 0; r = 255;
					}
					if ( abs(curr_angle) == PI)							//flat
					{
						r = g = b = 0;
					}
					if (curr_angle>t)									//convex
					{
						r = b = 0; 
						g = 255.0 - 255.0*( (curr_angle-t)/(PI-t) );
					}
					if (curr_angle < (-1.0*t))							//concave
					{
						g = b = 0;
						r = 255.0 *( (PI+curr_angle)/(PI-t) );
					}

	

					pDC->SetPixel((index+(count*offset_x)+offset_y+dx),slice+offset_y,RGB(r,g,b));	

				}
	
			}
		}
		count = (count+1)%(pDoc->N_CAMERAS);
	
	}//switch

}

void CCamViewerView::DrawAngleDerivs(CDC* pDC, int direction)
{
	CCamViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int slice, index;
	int r,g,b;
	int count = 2;
	
	int offset_y = 8;
	int offset_x = (pDoc->N_LEDS) + offset_y;
	int dx = IMG_X_OFFSET+IMG_X_OFFSET*(direction);

	float (* ad)[MAX_N_SLICES][MAX_N_LEDS][2];
	 BYTE  (* f)[MAX_N_SLICES][MAX_N_LEDS][2];

	float curr_angle;
	 BYTE curr_flag;

	float w = 0.9; // window factor, must be in [0,1]

	for(int i = 0; i < pDoc->N_CAMERAS; i++)
	{

	float MAX = pDoc->maxD[i][direction];

	switch (i)
		{
			case 0:	ad=&(pDoc->angleDeriv0);	f=&(pDoc->flag0);	break;
			case 1:	ad=&(pDoc->angleDeriv1);	f=&(pDoc->flag1);	break;
			case 2:	ad=&(pDoc->angleDeriv2);	f=&(pDoc->flag2);	break;
			case 3:	ad=&(pDoc->angleDeriv3);	f=&(pDoc->flag3);	break;
			case 4:	ad=&(pDoc->angleDeriv4);	f=&(pDoc->flag4);	break;
			case 5:	ad=&(pDoc->angleDeriv5);	f=&(pDoc->flag5);	break;
			case 6:	ad=&(pDoc->angleDeriv6);	f=&(pDoc->flag6);	break;
			case 7:	ad=&(pDoc->angleDeriv7);	f=&(pDoc->flag7);	break;
		default:	break;
		}
	
		for(slice = 0; slice < pDoc->N_SLICES; slice++)
		{
			for(index = 0; index < pDoc->N_LEDS; index++)
			{
				curr_angle = (* ad)[slice][index][direction];
				curr_flag = (* f)[slice][index][direction];

				if ( ( curr_flag == F_VOID ) || ( abs(curr_angle) > (MAX*w) ) )
				{
					pDC->SetPixel(	(index+(count*offset_x)+offset_y+dx),
									slice+offset_y,
									RGB(R_VOID,G_VOID,B_VOID)
									);	
				}
				else
				{

					if (curr_angle>0)
					{
						r = b = 0;
						g = (int)floor((curr_angle*256.0)/(MAX*w));
						pDC->SetPixel((index+(count*offset_x)+offset_y+dx),slice+offset_y,RGB(r,g,b));	
					}
					else
					{
						g = b = 0;
						r = (int)floor((curr_angle*(-256.0))/(MAX*w));
						pDC->SetPixel((index+(count*offset_x)+offset_y+dx),slice+offset_y,RGB(r,g,b));	
					}
				}
	
			}
		}
		count = (count+1)%(pDoc->N_CAMERAS);
	
	}//switch

}

// END DRAWING FUNCTIONS -----------------------------------------------------------
void CCamViewerView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CCamViewerView printing

BOOL CCamViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCamViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCamViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCamViewerView diagnostics

#ifdef _DEBUG
void CCamViewerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCamViewerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCamViewerDoc* CCamViewerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCamViewerDoc)));
	return (CCamViewerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCamViewerView message handlers



void CCamViewerView::ClearViewPort(CDC* pDC)
{
	unsigned int lim = 1000;
	for(int i = 0; i < lim; i++)
	{
		for(int j = 0; j < lim; j++)
		{
			pDC->SetPixel(i,j,RGB(255,255,255));	
		}
	}

}
