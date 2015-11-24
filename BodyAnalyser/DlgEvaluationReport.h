// DlgEvaluationReport.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgEvaluationReport dialog

class CDlgEvaluationReport : public CDialog
{
// Construction
public:
	CDlgEvaluationReport(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgEvaluationReport)
	enum { IDD = IDD_EVALUATION_REPORT };
	float	m_dthr;
	int		m_n_falsepositives;
	float	m_hthr;
	float	m_lthr;
	int		m_n_truepositives;
	int		m_P;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEvaluationReport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEvaluationReport)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
