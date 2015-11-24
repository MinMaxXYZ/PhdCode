// NoCurvMapDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNoCurvMapDialog dialog

class CNoCurvMapDialog : public CDialog
{
// Construction
public:
	CNoCurvMapDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNoCurvMapDialog)
	enum { IDD = IDD_NOCURVMAP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoCurvMapDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNoCurvMapDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
