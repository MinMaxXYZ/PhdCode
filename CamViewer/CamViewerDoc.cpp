// CamViewerDoc.cpp : implementation of the CCamViewerDoc class
//

#include "stdafx.h"
#include "CamViewer.h"
#include "CamViewerDoc.h"
#include <fstream.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define	PI	3.14159

/////////////////////////////////////////////////////////////////////////////
// CCamViewerDoc

IMPLEMENT_DYNCREATE(CCamViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CCamViewerDoc, CDocument)
	//{{AFX_MSG_MAP(CCamViewerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamViewerDoc construction/destruction

CCamViewerDoc::CCamViewerDoc()
{
	
	int slice, index, camera;

	N_CAMERAS	= 8		;
	N_SLICES	= 400	;
	N_LEDS		= 32	;

	N_GSCALES	= 255	;
	N_CHANNELS	= 1		;
	N_COLS		= 180	;



	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < N_LEDS; index++)
		{
			angleData0[slice][index][0] = angleData0[slice][index][1] = VOID_ANGLE;
			angleData1[slice][index][0] = angleData1[slice][index][1] = VOID_ANGLE;
			angleData2[slice][index][0] = angleData2[slice][index][1] = VOID_ANGLE;
			angleData3[slice][index][0] = angleData3[slice][index][1] = VOID_ANGLE;
			angleData4[slice][index][0] = angleData4[slice][index][1] = VOID_ANGLE;
			angleData5[slice][index][0] = angleData5[slice][index][1] = VOID_ANGLE;
			angleData6[slice][index][0] = angleData6[slice][index][1] = VOID_ANGLE;
			angleData7[slice][index][0] = angleData7[slice][index][1] = VOID_ANGLE;

			angleDeriv0[slice][index][0] = angleDeriv0[slice][index][1] = 0.0;
			angleDeriv1[slice][index][0] = angleDeriv1[slice][index][1] = 0.0;
			angleDeriv2[slice][index][0] = angleDeriv2[slice][index][1] = 0.0;
			angleDeriv3[slice][index][0] = angleDeriv3[slice][index][1] = 0.0;
			angleDeriv4[slice][index][0] = angleDeriv4[slice][index][1] = 0.0;
			angleDeriv5[slice][index][0] = angleDeriv5[slice][index][1] = 0.0;
			angleDeriv6[slice][index][0] = angleDeriv6[slice][index][1] = 0.0;
			angleDeriv7[slice][index][0] = angleDeriv7[slice][index][1] = 0.0;
		}
	}
	
//	for(camera = 0; camera < N_CAMERAS; camera)
//	{
//		maxD[camera][HORZ] = maxD[camera][VERT] = 0.0;
//	}

}

CCamViewerDoc::~CCamViewerDoc()
{
}

BOOL CCamViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCamViewerDoc serialization

void CCamViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCamViewerDoc diagnostics

#ifdef _DEBUG
void CCamViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCamViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCamViewerDoc commands

// file reading ---------------------------------------------------------------------

short CCamViewerDoc::OpenFile(const CString& input_file)
{
	ifstream ppm_file;
	int cams, slices, indices, tones, chans;
	char filetype[2];

	int slice, index;


	ppm_file.open(input_file, ios::nocreate|ios::in);
	if (!ppm_file.good())
	{
		return FALSE;
	}
	else
	{
		ppm_file >> cams;
		ppm_file >> indices;
		ppm_file >> slices;
		ppm_file >> tones;
		ppm_file >> chans;

//		if ( (indices==N_LEDS) && (slices==N_SLICES) && (tones==N_GSCALES) )
//		{
			N_CAMERAS	= cams;
			N_LEDS		= indices;
			N_SLICES	= slices;
			N_GSCALES	= tones;
			N_CHANNELS	= chans;


			// camera 0 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData0[slice][index][0];
					ppm_file >> geomData0[slice][index][1];
					ppm_file >> geomData0[slice][index][2];
					ppm_file >> imageData0[slice][index];
				}
			}

			// camera 1 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData1[slice][index][0];
					ppm_file >> geomData1[slice][index][1];
					ppm_file >> geomData1[slice][index][2];
					ppm_file >> imageData1[slice][index];
				}
			}

			// camera 2 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData2[slice][index][0];
					ppm_file >> geomData2[slice][index][1];
					ppm_file >> geomData2[slice][index][2];
					ppm_file >> imageData2[slice][index];
				}
			}

			// camera 3 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData3[slice][index][0];
					ppm_file >> geomData3[slice][index][1];
					ppm_file >> geomData3[slice][index][2];
					ppm_file >> imageData3[slice][index];
				}
			}

			// camera 4 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData4[slice][index][0];
					ppm_file >> geomData4[slice][index][1];
					ppm_file >> geomData4[slice][index][2];
					ppm_file >> imageData4[slice][index];
				}
			}

			// camera 5 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData5[slice][index][0];
					ppm_file >> geomData5[slice][index][1];
					ppm_file >> geomData5[slice][index][2];
					ppm_file >> imageData5[slice][index];
				}
			}

			// camera 6 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData6[slice][index][0];
					ppm_file >> geomData6[slice][index][1];
					ppm_file >> geomData6[slice][index][2];
					ppm_file >> imageData6[slice][index];
				}
			}

			// camera 7 
			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < N_LEDS; index++)
				{
					ppm_file >> geomData7[slice][index][0];
					ppm_file >> geomData7[slice][index][1];
					ppm_file >> geomData7[slice][index][2];
					ppm_file >> imageData7[slice][index];
				}
			}


			return TRUE;
//		}
//		else
//		{
//			return FALSE;
//		}
	}

	ppm_file.close();
}

// calculation of the angle image ---------------------------------------------------

void CCamViewerDoc::CalculateAngles()
{
	int i;
	int s, l;

	  int (* a)[MAX_N_SLICES][MAX_N_LEDS];
	float (* b)[MAX_N_SLICES][MAX_N_LEDS][2];
	float (* c)[MAX_N_SLICES][MAX_N_LEDS][3];


	for (i = 0; i < N_CAMERAS; i++)
	{
		switch (i)
		{
			case 0:	a = &imageData0;	c = &geomData0;		b = &angleData0;	break;
			case 1:	a = &imageData1;	c = &geomData1;		b = &angleData1;	break;
			case 2:	a = &imageData2;	c = &geomData2;		b = &angleData2;	break;
			case 3:	a = &imageData3;	c = &geomData3;		b = &angleData3;	break;
			case 4:	a = &imageData4;	c = &geomData4;		b = &angleData4;	break;
			case 5:	a = &imageData5;	c = &geomData5;		b = &angleData5;	break;
			case 6:	a = &imageData6;	c = &geomData6;		b = &angleData6;	break;
			case 7:	a = &imageData7;	c = &geomData7;		b = &angleData7;	break;
		default:	break;
		}
	
		CalculateAngles(a, c, b);
	}
}

void CCamViewerDoc::CalculateAngles(	int (* i)[MAX_N_SLICES][MAX_N_LEDS], 
										float (* g)[MAX_N_SLICES][MAX_N_LEDS][3],
										float (* r)[MAX_N_SLICES][MAX_N_LEDS][2])
{
	int w;	//smothing factor

	int slice, led;
	float thetaX, detX;
	float thetaY, detY;

	for (slice = 0+w; slice < N_SLICES-w; slice++)
	{
		for(led = 0+w; led < N_LEDS-w; led++)
		{
			int sh = 0;
			
			if ((*i)[slice][led] < 0)
			{
				(*r)[slice][led][0] = VOID_ANGLE;	
				(*r)[slice][led][1] = VOID_ANGLE;	
			}
			else 
			{

				w = 3;
				// calculation of X angle value

				thetaX = CalcAngle(
								(*g)[slice][led][0],
								(*g)[slice][led][1],
								(*g)[slice][led][2],

								(*g)[slice][led+w][0],
								(*g)[slice][led+w][1],
								(*g)[slice][led+w][2],

								(*g)[slice][led-w][0],
								(*g)[slice][led-w][1],
								(*g)[slice][led-w][2]
								);

		
				
				// calculation of X angle sign

				detX = CalcDeterminant(
								(*g)[slice][led][0],
								(*g)[slice][led][1],
								(*g)[slice][led][2],

								(*g)[slice][led+w][0],
								(*g)[slice][led+w][1],
								(*g)[slice][led+w][2],

								(*g)[slice][led-w][0],
								(*g)[slice][led-w][1],
								(*g)[slice][led-w][2]
								);

				if (detX<0) {thetaX *= -1.0;}

				(*r)[slice][led][0] = thetaX;

				w = 5;
				// calculation of Y angle value

				thetaY = CalcAngle(
								(*g)[slice][led][0],
								(*g)[slice][led][1],
								(*g)[slice][led][2],

								(*g)[slice+w][led][0],
								(*g)[slice+w][led][1],
								(*g)[slice+w][led][2],

								(*g)[slice-w][led][0],
								(*g)[slice-w][led][1],
								(*g)[slice-w][led][2]
								);

		
				
				// calculation of Y angle sign

				detY = CalcDeterminant(
								(*g)[slice][led][0],
								(*g)[slice][led][1],
								(*g)[slice][led][2],

								(*g)[slice+w][led][0],
								(*g)[slice+w][led][1],
								(*g)[slice+w][led][2],

								(*g)[slice-w][led][0],
								(*g)[slice-w][led][1],
								(*g)[slice-w][led][2]
								);


				if (detY<0) {thetaY *= -1.0;}

				(*r)[slice][led][1] = thetaY;


			}

		 

		}//for led
	}//for slice

}

// calculation of derivatives for the angle image -----------------------------------

void CCamViewerDoc::CalculateAngleDerivatives()
{
	int i;
	//int s, l;

	  int (* a)[MAX_N_SLICES][MAX_N_LEDS];
	float (* b)[MAX_N_SLICES][MAX_N_LEDS][2];
	float (* c)[MAX_N_SLICES][MAX_N_LEDS][2];
	 BYTE (* f)[MAX_N_SLICES][MAX_N_LEDS][2];

	for (i = 0; i < N_CAMERAS; i++)
	{
		switch (i)
		{
			case 0:	a=&imageData0;b=&angleData0;c=&angleDeriv0;f=&flag0;break;
			case 1:	a=&imageData1;b=&angleData1;c=&angleDeriv1;f=&flag1;break;
			case 2:	a=&imageData2;b=&angleData2;c=&angleDeriv2;f=&flag2;break;
			case 3:	a=&imageData3;b=&angleData3;c=&angleDeriv3;f=&flag3;break;
			case 4:	a=&imageData4;b=&angleData4;c=&angleDeriv4;f=&flag4;break;
			case 5:	a=&imageData5;b=&angleData5;c=&angleDeriv5;f=&flag5;break;
			case 6:	a=&imageData6;b=&angleData6;c=&angleDeriv6;f=&flag6;break;
			case 7:	a=&imageData7;b=&angleData7;c=&angleDeriv7;f=&flag7;break;
		default:	break;
		}
	
		CalculateAngleDerivatives(a, b, c, f, i);
	}

}


void CCamViewerDoc::CalculateAngleDerivatives(	int (* i)[MAX_N_SLICES][MAX_N_LEDS], 
												float (* g)[MAX_N_SLICES][MAX_N_LEDS][2], 
												float (* r)[MAX_N_SLICES][MAX_N_LEDS][2],
												BYTE (* f)[MAX_N_SLICES][MAX_N_LEDS][2],
												int cam)
{
	int slice, led;
	float dX, dY;

	for (slice = 0+1; slice < N_SLICES-1; slice++)
	{
		for(led = 0+1; led < N_LEDS-1; led++)
		{

			if ( (*i)[slice][led] < 0)
			{
				(*f)[slice][led][0] = F_VOID;	
				(*f)[slice][led][1] = F_VOID;	
			}
			else 
			{
				// calculation of X angle derivative
 
				if (  ((*g)[slice][led+1][0] != VOID_ANGLE)  && ((*g)[slice][led][0] != VOID_ANGLE)	)
					{
						dX = (*g)[slice][led+1][0] - (*g)[slice][led][0];
						(*f)[slice][led][0] = F_VALID;
					}
				else
					{
						dX = 0;
						(*f)[slice][led][0] = F_VOID;
					}
				(*r)[slice][led][0] = dX;
				if (abs(dX) > maxD[cam][0]) {maxD[cam][0] = abs(dX);}

				// calculation of Y angle derivative
				if (  ((*g)[slice+1][led][1] != VOID_ANGLE)  && ((*g)[slice][led][1] != VOID_ANGLE)	)
					{
						dY = (*g)[slice+1][led][1] - (*g)[slice][led][1];
						(*f)[slice][led][1] = F_VALID;
					}
				else
					{
						dY = 0;
						(*f)[slice][led][1] = F_VOID;
					}
				(*r)[slice][led][1] = dY;
				if (abs(dY) > maxD[cam][1]) {maxD[cam][1] = abs(dY);}

				//(*r)[slice][led][1] = (abs(thetaX)+abs(thetaY)) / 2;
			}

		 

		}//for led
	}//for slice


}


// auxiliary mathematical functions -------------------------------------------------

float CCamViewerDoc::CalcAngle(float v0x, float v0y, float v0z, 
							   float v1x, float v1y, float v1z, 
							   float v2x, float v2y, float v2z)
{
	float d1x = v1x - v0x;
	float d2x = v2x - v0x;

	float d1y = v1y - v0y;
	float d2y = v2y - v0y;

	float d1z = v1z - v0z;
	float d2z = v2z - v0z;

	float e = (d1x*d2x) + (d1y*d2y) + (d1z*d2z);

	float sq1x = d1x*d1x;
	float sq2x = d2x*d2x;

	float sq1y = d1y*d1y;
	float sq2y = d2y*d2y;

	float sq1z = d1z*d1z;
	float sq2z = d2z*d2z;

	float d = sqrt(sq1x+sq1y+sq1z)*sqrt(sq2x+sq2y+sq2z);

	float ctheta = acos(e/d);
	return ctheta;
}

float CCamViewerDoc::CalcDeterminant(float x1, float y1, float z1, 
									 float x2, float y2, float z2, 
									 float x3, float y3, float z3)
{
	float d1 = (y2*z3)-(y3*z2);
	float d2 = (y1*z3)-(y3*z1);
	float d3 = (y1*z2)-(y2*z1);

	float d = (x1*d1) - (x2*d2) + (x3*d3);

	return d;
}
