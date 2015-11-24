// DialogCameraImager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogCameraImager dialog

class CDialogCameraImager : public CDialog
{
// Construction
public:
	CDialogCameraImager(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogCameraImager)
	enum { IDD = IDD_CAMERA_IMAGER };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogCameraImager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogCameraImager)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
