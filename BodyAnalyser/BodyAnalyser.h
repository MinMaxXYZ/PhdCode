// BodyAnalyser.h : main header file for the BODYANALYSER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "..\bldefs.h"

#include <fstream.h>

// BEGIN_IVWGEN
#include <Ivf/IvfApp.h>
// END_IVWGEN

/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserApp:
// See BodyAnalyser.cpp for the implementation of this class
//

// BEGIN_IVWGEN
class CBodyAnalyserApp : public CWinApp , public CIvfApp
// END_IVWGEN
{
public:
	short GetDistance(int slice, int index);
	short GetBrightness(int slice, int index);

	// space for newly downloaded data
	short* m_dist1;
	short* m_dist2;
	short* m_dist3;
	short* m_dist4;
	unsigned char* m_brbuf1;
	unsigned char* m_brbuf2;
	unsigned char* m_brbuf3;
	unsigned char* m_brbuf4;

	BOOL OpenFromFile(ifstream& bls_input);
	CBodyAnalyserApp();
	long m_nLastOpenedFilterIX;

	void SetParams(PARAMS& param_struct);
	BOOL LoadHeadParameters(const CString& params_file, PARAMS& param_struct);
	PARAMS& Params(void);


protected:
	PARAMS m_scanner_params;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBodyAnalyserApp)
	public:
	virtual BOOL InitInstance();
// BEGIN_IVWGEN
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual BOOL PreTranslateMessage(MSG *pMsg);
// END_IVWGEN
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBodyAnalyserApp)
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

extern CBodyAnalyserApp theApp;


/////////////////////////////////////////////////////////////////////////////
