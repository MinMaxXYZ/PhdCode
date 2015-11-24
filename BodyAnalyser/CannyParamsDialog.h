// CannyParamsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCannyParamsDialog dialog

class CCannyParamsDialog : public CDialog
{
// Construction
public:
	CCannyParamsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCannyParamsDialog)
	enum { IDD = IDD_CANNY_PARAMS };
	int		m_lower_threshold;
	int		m_masksize;
	int		m_upper_threshold;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCannyParamsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCannyParamsDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
