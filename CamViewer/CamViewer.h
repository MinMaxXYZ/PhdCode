// CamViewer.h : main header file for the CAMVIEWER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "..\bldefs.h"


/////////////////////////////////////////////////////////////////////////////
// CCamViewerApp:
// See CamViewer.cpp for the implementation of this class
//

class CCamViewerApp : public CWinApp
{
public:
	CCamViewerApp();

public:
	long m_nLastOpenedFilterIX;




// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCamViewerApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
