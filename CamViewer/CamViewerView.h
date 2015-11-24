// CamViewerView.h : interface of the CCamViewerView class
//
/////////////////////////////////////////////////////////////////////////////

class CCamViewerView : public CScrollView
{
protected: // create from serialization only
	CCamViewerView();
	DECLARE_DYNCREATE(CCamViewerView)

// Attributes
public:
	void ClearViewPort(CDC* pDC);
	void DrawAngleDerivs(CDC* pDC, int direction);
	void DrawAngleImages(CDC* pDC, int direction);
	void DrawCameraImages(CDC* pDC);
	CCamViewerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamViewerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCamViewerView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CamViewerView.cpp
inline CCamViewerDoc* CCamViewerView::GetDocument()
   { return (CCamViewerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
