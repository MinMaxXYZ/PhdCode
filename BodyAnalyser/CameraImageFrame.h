// CameraImageFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCameraImageFrame frame

class CCameraImageFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CCameraImageFrame)
protected:
	CCameraImageFrame();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCameraImageFrame)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCameraImageFrame();

	// Generated message map functions
	//{{AFX_MSG(CCameraImageFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
