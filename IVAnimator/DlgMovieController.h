// DlgMovieController.h : header file
//

#include "IVAnimatorDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgMovieController dialog

class CDlgMovieController : public CDialog
{
// Construction
public:
	void AttachDocument(CIVAnimatorDoc* d);
	CIVAnimatorDoc* m_pDoc;
	CDlgMovieController(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMovieController)
	enum { IDD = IDD_MOVIECONTROLLER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMovieController)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMovieController)
	afx_msg void OnButtonPause();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonEnd();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonPrevious();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
