// IVAnimator.h : main header file for the IVANIMATOR application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

// BEGIN_IVWGEN
#include <Ivf/IvfApp.h>
// END_IVWGEN

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorApp:
// See IVAnimator.cpp for the implementation of this class
//

// BEGIN_IVWGEN
class CIVAnimatorApp : public CWinApp , public CIvfApp
// END_IVWGEN
{
public:
	CIVAnimatorApp();
	long m_nLastOpenedFilterIX;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIVAnimatorApp)
	public:
	virtual BOOL InitInstance();
// BEGIN_IVWGEN
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual BOOL PreTranslateMessage(MSG *pMsg);
// END_IVWGEN
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIVAnimatorApp)
	afx_msg void OnAppAbout();
        afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileViewInfo();
	afx_msg void OnUpdateFileViewInfo(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewMoviecontroller(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CIVAnimatorApp theApp;


/////////////////////////////////////////////////////////////////////////////
