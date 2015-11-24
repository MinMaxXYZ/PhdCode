// DlgWrapMesh.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgWrapMesh dialog

class CDlgWrapMesh : public CDialog
{
// Construction
public:
	CDlgWrapMesh(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgWrapMesh)
	enum { IDD = IDD_WRAP_MESH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgWrapMesh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgWrapMesh)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
