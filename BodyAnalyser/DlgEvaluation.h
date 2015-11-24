// DlgEvaluation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgEvaluation dialog

class CDlgEvaluation : public CDialog
{
// Construction
public:
	CDlgEvaluation(CWnd* pParent = NULL);   // standard constructor
	int m_sym_type;

// Dialog Data
	//{{AFX_DATA(CDlgEvaluation)
	enum { IDD = IDD_EVALUATION };
	float	m_dthr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEvaluation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEvaluation)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
