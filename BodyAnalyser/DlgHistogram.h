// DlgHistogram.h : header file
//

#include "BodyAnalyserDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgHistogram dialog

class CDlgHistogram : public CDialog
{
// Construction
public:
	void DrawHistogram(				CPaintDC* m_DC, CHistogram* h, 
								    unsigned int x_offset, unsigned int y_offset, 
									unsigned int y_height, 
									unsigned int rec_width,unsigned int rec_height,
									unsigned int f,
									CString s_label);
//	CDocument* GetDocument();
	void AttachDocument(CBodyAnalyserDoc* pDoc);
	CDlgHistogram(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgHistogram)
	enum { IDD = IDD_HISTOGRAM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgHistogram)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgHistogram)
	virtual void OnOK();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBodyAnalyserDoc* m_pDoc;
};
