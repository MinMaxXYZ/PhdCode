// IVAnimatorView.cpp : implementation of the CIVAnimatorView class
//

#include "stdafx.h"
#include "IVAnimator.h"

#include "IVAnimatorDoc.h"
#include "IVAnimatorView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorView

IMPLEMENT_DYNCREATE(CIVAnimatorView, CView)

BEGIN_MESSAGE_MAP(CIVAnimatorView, CView)
	//{{AFX_MSG_MAP(CIVAnimatorView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
// BEGIN_IVWGEN
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_VIEW_PICEDIT, OnViewPicedit)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PICEDIT, OnUpdateViewPicedit)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_VIEW_VIEWINGMODE, OnViewViewmodesViewingmode)
	ON_COMMAND(ID_VIEW_SELECTIONMODE, OnViewViewmodesSelectionmode)
// END_IVWGEN
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorView construction/destruction

CIVAnimatorView::CIVAnimatorView()
{
	// TODO: add construction code here

}

CIVAnimatorView::~CIVAnimatorView()
{
}

BOOL CIVAnimatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

        return CView::PreCreateWindow(cs);
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorView drawing

void CIVAnimatorView::OnDraw(CDC* pDC)
{
	CIVAnimatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void CIVAnimatorView::OnInitialUpdate()
{
        // TODO: Add your specialized code here and/or call the base class

        CView::OnInitialUpdate();

        IvfOnInitialUpdate(this) ;

	m_nEnableSelection = TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorView printing

BOOL CIVAnimatorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIVAnimatorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
IvfOnBeginPrinting();
}

void CIVAnimatorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
IvfOnEndPrinting();
}

void CIVAnimatorView::OnPrint(CDC* pDC, CPrintInfo*)
{
IvfOnPrint(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorView diagnostics

#ifdef _DEBUG
void CIVAnimatorView::AssertValid() const
{
	CView::AssertValid();
}

void CIVAnimatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIVAnimatorDoc* CIVAnimatorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIVAnimatorDoc)));
	return (CIVAnimatorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorView message handlers

// BEGIN_IVWGEN
void CIVAnimatorView::OnDestroy()
{
	CView::OnDestroy();
	IvfOnDestroy();
}
// END_IVWGEN

// BEGIN_IVWGEN
int CIVAnimatorView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	IvfOnCreate(lpCreateStruct);
	
	return 0;
}

void CIVAnimatorView::OnPaint() 
{
	// IvfOnPaint just does a BeginPaint/EndPaint
	//
	// The view's window does not need to be painted because it is
	// completely covered by the Inventor viewer window (which will
	// automatically paint itself as long as it gets the WM_PAINT).
	// However we still need to "validate" the paint rect so we won't
	// keep getting paint messages over and over.

	IvfOnPaint( this ) ;
}

BOOL CIVAnimatorView::OnEraseBkgnd(CDC* pDC) 
{
	// We don't want to waste cpu cycles painting the background of
	// the view window because it is always completely covered by
	// the Inventor viewer window.  DefWindowProc will draw the back-
	// ground unless we return TRUE from this message handler, which
        // is actually all that IvfOnEraseBkgnd does right now...

	return IvfOnEraseBkgnd(pDC);
}

BOOL CIVAnimatorView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	if( IvfOnCmdMsg( nID, nCode, pExtra, pHandlerInfo ) )
		return TRUE;
	else
		return CView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

// END_IVWGEN



void CIVAnimatorView::OnViewPicedit () 
{ 
if (IvfIsViewing()) OnViewViewmodesSelectionmode();
else		    OnViewViewmodesViewingmode();
} 


void CIVAnimatorView::OnUpdateViewPicedit (CCmdUI* pCmdUI)
{ 
if (IsDocLoaded())
   {
   pCmdUI->Enable(TRUE);
   pCmdUI->SetCheck(GetViewerViewMode() == ID_VIEW_VIEWINGMODE);
   }

else
   {
   pCmdUI->Enable(FALSE);
   pCmdUI->SetCheck(FALSE);
   }
}



void CIVAnimatorView::OnEditCut() 
{
IvfOnEditCut();	
}


void CIVAnimatorView::OnUpdateEditCut(CCmdUI* pCmdUI)
{
IvfOnUpdateEditCut(pCmdUI);
}


void CIVAnimatorView::OnEditCopy() 
{
IvfOnEditCopy();	
}


void CIVAnimatorView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
IvfOnUpdateEditCopy(pCmdUI);
}


void CIVAnimatorView::OnEditPaste() 
{
CDocument *pDoc = CIvfApp::IvfGetAfxDocument(this);
pDoc->SetModifiedFlag();
IvfOnEditPaste();	
}


void CIVAnimatorView::OnUpdateEditPaste(CCmdUI* pCmdUI)
{
IvfOnUpdateEditPaste(pCmdUI);
}


BOOL CIVAnimatorView::IsDocLoaded(void)
{
CIVAnimatorDoc *t_doc = GetDocument();
return(t_doc->IvfGetDocSceneGraph() != NULL);
}


BOOL CIVAnimatorView::IsSelected(void)
{
return(IvfIsSelected());
}


BOOL CIVAnimatorView::SaveAsBitmap( LPCTSTR pFilename )
{
return(IvfSaveAsBitmap(pFilename));
}



UINT CIVAnimatorView::GetViewerViewMode(void)
{
UINT r_stat = 0;

if (IsDocLoaded())
   {
   r_stat = (IvfIsViewing())? ID_VIEW_VIEWINGMODE :
            		      ID_VIEW_SELECTIONMODE;
   }

return(r_stat);
}


void CIVAnimatorView::OnViewViewmodesSelectionmode() 
{
IvfViewmodesSelectionmode();
}

void CIVAnimatorView::OnViewViewmodesViewingmode() 
{
IvfViewmodesViewingmode();
}
