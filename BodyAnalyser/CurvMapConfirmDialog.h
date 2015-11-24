// CurvMapConfirmDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCurvMapConfirmDialog dialog

class CCurvMapConfirmDialog : public CDialog
{
// Construction
public:
	CCurvMapConfirmDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCurvMapConfirmDialog)
	enum { IDD = IDD_CURVMAP_CONFIRM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCurvMapConfirmDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCurvMapConfirmDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
