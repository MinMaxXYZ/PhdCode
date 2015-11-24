// DlgCurvatureProgress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCurvatureProgress dialog

class CDlgCurvatureProgress : public CDialog
{
// Construction
public:
	CDlgCurvatureProgress(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCurvatureProgress)
	enum { IDD = IDD_CURVATURE_PROGRESS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCurvatureProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCurvatureProgress)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
