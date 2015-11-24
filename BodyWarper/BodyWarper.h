// BodyWarper.h : main header file for the BODYWARPER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "..\bldefs.h"

// BEGIN_IVWGEN
#include <Ivf/IvfApp.h>
// END_IVWGEN

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperApp:
// See BodyWarper.cpp for the implementation of this class
//

// BEGIN_IVWGEN
class CBodyWarperApp : public CWinApp , public CIvfApp
// END_IVWGEN
{
public:
	CBodyWarperApp();
	long m_nLastOpenedFilterIX;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBodyWarperApp)
	public:
	virtual BOOL InitInstance();
// BEGIN_IVWGEN
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual BOOL PreTranslateMessage(MSG *pMsg);
// END_IVWGEN
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBodyWarperApp)
	afx_msg void OnAppAbout();
        afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileViewInfo();
	afx_msg void OnUpdateFileViewInfo(CCmdUI *pCmdUI);
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CBodyWarperApp theApp;


/////////////////////////////////////////////////////////////////////////////
