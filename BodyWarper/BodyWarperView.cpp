// BodyWarperView.cpp : implementation of the CBodyWarperView class
//

#include "stdafx.h"
#include "BodyWarper.h"

#include "BodyWarperDoc.h"
#include "BodyWarperView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperView

IMPLEMENT_DYNCREATE(CBodyWarperView, CView)

BEGIN_MESSAGE_MAP(CBodyWarperView, CView)
	//{{AFX_MSG_MAP(CBodyWarperView)
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
// CBodyWarperView construction/destruction

CBodyWarperView::CBodyWarperView()
{
	// TODO: add construction code here

}

CBodyWarperView::~CBodyWarperView()
{
}

BOOL CBodyWarperView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

        return CView::PreCreateWindow(cs);
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperView drawing

void CBodyWarperView::OnDraw(CDC* pDC)
{
	CBodyWarperDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void CBodyWarperView::OnInitialUpdate()
{
        // TODO: Add your specialized code here and/or call the base class

        CView::OnInitialUpdate();

        IvfOnInitialUpdate(this) ;

	m_nEnableSelection = TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperView printing

BOOL CBodyWarperView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBodyWarperView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
IvfOnBeginPrinting();
}

void CBodyWarperView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
IvfOnEndPrinting();
}

void CBodyWarperView::OnPrint(CDC* pDC, CPrintInfo*)
{
IvfOnPrint(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperView diagnostics

#ifdef _DEBUG
void CBodyWarperView::AssertValid() const
{
	CView::AssertValid();
}

void CBodyWarperView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBodyWarperDoc* CBodyWarperView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBodyWarperDoc)));
	return (CBodyWarperDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperView message handlers

// BEGIN_IVWGEN
void CBodyWarperView::OnDestroy()
{
	CView::OnDestroy();
	IvfOnDestroy();
}
// END_IVWGEN

// BEGIN_IVWGEN
int CBodyWarperView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	IvfOnCreate(lpCreateStruct);
	
	return 0;
}

void CBodyWarperView::OnPaint() 
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

BOOL CBodyWarperView::OnEraseBkgnd(CDC* pDC) 
{
	// We don't want to waste cpu cycles painting the background of
	// the view window because it is always completely covered by
	// the Inventor viewer window.  DefWindowProc will draw the back-
	// ground unless we return TRUE from this message handler, which
        // is actually all that IvfOnEraseBkgnd does right now...

	return IvfOnEraseBkgnd(pDC);
}

BOOL CBodyWarperView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	if( IvfOnCmdMsg( nID, nCode, pExtra, pHandlerInfo ) )
		return TRUE;
	else
		return CView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

// END_IVWGEN

// BEGIN_IVWGEN
void CBodyWarperView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
CBodyWarperDoc* pDoc = GetDocument();
			  //  need the document pointer

        // TODO: Add your specialized code here and/or call the base class

	if(bActivate && pActivateView == (CView *)this) {
        // Moved component creation here so we can avoid creating
        // it when we are not even active.  If we're here then it's
        // certain that we're active and have a frame window.

      	if (m_pComponent == NULL) {
        	// Get pointer that was passed into IVF_INIT_INSTANCE
	        int *cArgs = (int *)CIvfApp::IvfCreateArgs();
        	ASSERT_VALID(pDoc);

	    IvfCreateComponent( this, cArgs ) ;

	    if (pDoc->IvfGetDocSceneGraph() != NULL) IvfResetComponent(pDoc);
			// scenegraph was already loaded, but
			// the component could not be initialized.
			// do it now.

	    IvfSetBackgroundColor(pDoc->IvfGetBgColor());
        }

        // For some reason MS-Word doesn't pass WM_QUERYNEWPALETTE to us
        // (although this works fine in the test container).
        // This call will force Inventor to realize its palette.

        IvfOnActivateComponent(pActivateView) ;

			//  don't want this happening in normal
			//  standalone scenario
			//  note also that Word activates and deactivates
			//  us several times.  Make sure the doc is
			//  considered modified for every activation.
        }
	else if(!bActivate && pDeactiveView == (CView *)this) {
	IvfOnDeactivateComponent() ;
	}
CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
// END_IVWGEN


void CBodyWarperView::OnViewPicedit () 
{ 
if (IvfIsViewing()) OnViewViewmodesSelectionmode();
else		    OnViewViewmodesViewingmode();
} 


void CBodyWarperView::OnUpdateViewPicedit (CCmdUI* pCmdUI)
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



void CBodyWarperView::OnEditCut() 
{
IvfOnEditCut();	
}


void CBodyWarperView::OnUpdateEditCut(CCmdUI* pCmdUI)
{
IvfOnUpdateEditCut(pCmdUI);
}


void CBodyWarperView::OnEditCopy() 
{
IvfOnEditCopy();	
}


void CBodyWarperView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
IvfOnUpdateEditCopy(pCmdUI);
}


void CBodyWarperView::OnEditPaste() 
{
CDocument *pDoc = CIvfApp::IvfGetAfxDocument(this);
pDoc->SetModifiedFlag();
IvfOnEditPaste();	
}


void CBodyWarperView::OnUpdateEditPaste(CCmdUI* pCmdUI)
{
IvfOnUpdateEditPaste(pCmdUI);
}


BOOL CBodyWarperView::IsDocLoaded(void)
{
CBodyWarperDoc *t_doc = GetDocument();
return(t_doc->IvfGetDocSceneGraph() != NULL);
}


BOOL CBodyWarperView::IsSelected(void)
{
return(IvfIsSelected());
}


BOOL CBodyWarperView::SaveAsBitmap( LPCTSTR pFilename )
{
return(IvfSaveAsBitmap(pFilename));
}



UINT CBodyWarperView::GetViewerViewMode(void)
{
UINT r_stat = 0;

if (IsDocLoaded())
   {
   r_stat = (IvfIsViewing())? ID_VIEW_VIEWINGMODE :
            		      ID_VIEW_SELECTIONMODE;
   }

return(r_stat);
}


void CBodyWarperView::OnViewViewmodesSelectionmode() 
{
IvfViewmodesSelectionmode();
}

void CBodyWarperView::OnViewViewmodesViewingmode() 
{
IvfViewmodesViewingmode();
}
