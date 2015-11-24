// InsufficientLandmarksDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInsufficientLandmarksDlg dialog

class CInsufficientLandmarksDlg : public CDialog
{
// Construction
public:
	CInsufficientLandmarksDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInsufficientLandmarksDlg)
	enum { IDD = IDD_INSUFFICIENTLANDMARKSDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsufficientLandmarksDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInsufficientLandmarksDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
