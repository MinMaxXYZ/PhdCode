// BodyWarperView.h : interface of the CBodyWarperView class
//
/////////////////////////////////////////////////////////////////////////////

// BEGIN_IVWGEN
#include "resource.h"
#include <Ivf/Viewers/IvfExaminerViewer.h>
// END_IVWGEN


class CBodyWarperDoc;

// BEGIN_IVWGEN
class CBodyWarperView : public CView , public CIvfExaminerViewer
// END_IVWGEN
{
protected: // create from serialization only
	CBodyWarperView();
	DECLARE_DYNCREATE(CBodyWarperView)


// Attributes
public:
	CBodyWarperDoc* GetDocument();
	BOOL IsDocLoaded();
	BOOL IsSelected();
	UINT GetViewerViewMode();

// Operations
public:
	BOOL SaveAsBitmap(LPCTSTR pFilename);

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBodyWarperView)
public:
// BEGIN_IVWGEN
	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
// END_IVWGEN
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBodyWarperView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBodyWarperView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
// BEGIN_IVWGEN
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	afx_msg void OnViewPicedit();
	afx_msg void OnUpdateViewPicedit(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnViewViewmodesSelectionmode();
	afx_msg void OnViewViewmodesViewingmode();
// END_IVWGEN
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BodyWarperView.cpp
inline CBodyWarperDoc* CBodyWarperView::GetDocument()
   { return (CBodyWarperDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
