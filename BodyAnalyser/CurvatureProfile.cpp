// CurvatureProfile.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "CurvatureProfile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCurvatureProfile

CCurvatureProfile::CCurvatureProfile()
{
}

CCurvatureProfile::~CCurvatureProfile()
{
}



BOOL CCurvatureProfile::nearUmbilic()
{
	return(!redlabel);
}
