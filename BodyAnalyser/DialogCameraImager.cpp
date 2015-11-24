// DialogCameraImager.cpp : implementation file
//

#include "stdafx.h"
#include "BodyAnalyser.h"
#include "DialogCameraImager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogCameraImager dialog


CDialogCameraImager::CDialogCameraImager(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogCameraImager::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogCameraImager)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT


}


void CDialogCameraImager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogCameraImager)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

}


BEGIN_MESSAGE_MAP(CDialogCameraImager, CDialog)
	//{{AFX_MSG_MAP(CDialogCameraImager)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogCameraImager message handlers
