// DlgCurvThresholds.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCurvThresholds dialog

class CDlgCurvThresholds : public CDialog
{
// Construction
public:
	CDlgCurvThresholds(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCurvThresholds)
	enum { IDD = IDD_HYST_THRESHOLDS };
	float	m_hthres;
	float	m_lthres;
	BOOL	m_minridges;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCurvThresholds)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCurvThresholds)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
