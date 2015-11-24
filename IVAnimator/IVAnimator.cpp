// IVAnimator.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "IVAnimator.h"

#include "MainFrm.h"
#include "IVAnimatorDoc.h"
#include "IVAnimatorView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#include <Ivf/Viewers/IvfRenderArea.h>

class CAboutDlg : public CDialog, public CIvfRenderArea
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
// BEGIN_IVWGEN
	virtual BOOL OnInitDialog();
// END_IVWGEN
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorApp

BEGIN_MESSAGE_MAP(CIVAnimatorApp, CWinApp)
	//{{AFX_MSG_MAP(CIVAnimatorApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_INFO, OnFileViewInfo)
	ON_UPDATE_COMMAND_UI(ID_FILE_INFO, OnUpdateFileViewInfo)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MOVIECONTROLLER, OnUpdateViewMoviecontroller)
	//}}AFX_MSG_MAP

	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorApp construction

CIVAnimatorApp::CIVAnimatorApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIVAnimatorApp object

CIVAnimatorApp theApp;

// BEGIN_IVWGEN
IVF_AFX_CONVERSION_METHOD(CIVAnimatorView,CIVAnimatorDoc)
// END_IVWGEN


/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorApp initialization

BOOL CIVAnimatorApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

// BEGIN_IVWGEN
	static int cArgs[]= {
		TRUE,		// Decoration
		TRUE,	// URL Display
		TRUE,					// Viewpoints
		TRUE};		// URL Fetch

	IVF_INIT_INSTANCE(
		 this,
		 IvfCvtAfxView,
		 IvfCvtIvfComponent,
		 NULL,
		 NULL,
		 IvfCvtAfxDoc,
		 IvfCvtIvfDoc,
		 IvfCvtAfxFrame,
		 (void *)cArgs,
		 FALSE);
// END_IVWGEN

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CIVAnimatorDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CIVAnimatorView));
	AddDocTemplate(pDocTemplate);

// BEGIN_IVWGEN
	CIvfApp::m_pDocTemplate = pDocTemplate;
// END_IVWGEN


	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::FileNew)
			//  need to intercept FileNew so we can
			//  call our own OnFileNew directly
	   {
	   OnFileNew();
	   if (!m_pMainWnd) return(FALSE);
	   m_nCmdShow = SW_SHOWNORMAL;
	   }

	else if (!ProcessShellCommand(cmdInfo))
		return FALSE;


	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();
 

	//some corporate branding
	CAboutDlg A;	A.DoModal();

	return TRUE;
}


CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// BEGIN_IVWGEN
BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	static int cArgs[]= {FALSE,FALSE,FALSE,FALSE};

	//CWnd *pWnd = GetDlgItem(IDC_ABOUT_TEXT) ;
	//IvfCreateComponent(pWnd,(void *)cArgs);

	return TRUE;
}
// END_IVWGEN

// App command to run the dialog
void CIVAnimatorApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorApp commands

static char *def_ext[] = {NULL, ".iv", ".wrl"};
#define NUM_EXT_VALS	3

// BEGIN_IVWGEN
void CIVAnimatorApp::OnFileOpen() 
{

	const char szFilter[] =
	"Frame List Files (*.txt)\0*.txt\0Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0";

	const char szTitle[] = "Open File";

	CFileDialog openDlg(TRUE);

	openDlg.m_ofn.lpstrTitle = szTitle;
	openDlg.m_ofn.lpstrFilter = szFilter ;
	openDlg.m_ofn.nFilterIndex = m_nLastOpenedFilterIX;
	openDlg.m_ofn.lpstrCustomFilter = NULL;
	openDlg.m_ofn.lpstrDefExt = def_ext[m_nLastOpenedFilterIX];
	openDlg.m_ofn.nMaxCustFilter = 0;

	openDlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_PATHMUSTEXIST) ;


	if (openDlg.DoModal() == IDOK)
	   {
	   CIvfDocument *pIvfDoc = IvfGetDocument();

	   if (pIvfDoc &&
	       pIvfDoc->m_eOpenType == CIvfDocument::IVFDOC_OPEN_IMPORT)
	      pIvfDoc->IvfOnOpenDocumentMessage(openDlg.m_ofn.lpstrFile);

	   else
	      {
	      CString newName = openDlg.m_ofn.lpstrFile;

			int extn = openDlg.m_ofn.nFileExtension;
			if (!_stricmp("txt",&(openDlg.m_ofn.lpstrFile[extn])))	//if it is a txt list
			{
				CView* pView = IvfGetAfxView();
				CIVAnimatorDoc *pDoc = (CIVAnimatorDoc*)pView->GetDocument();

				if(pDoc)
				{
					HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
					SetCursor(waitCursor);	
					
					if (pDoc->OpenFiles(openDlg.m_ofn.lpstrFile))
					{
						// set the title text
						CView* pView = IvfGetAfxView();
						pView->SetWindowText(openDlg.m_ofn.lpstrFile);
					}
					else
					{
						AfxMessageBox(CString("Cannot open ")+openDlg.m_ofn.lpstrFile, MB_OK);
					}

					HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
					SetCursor(arrowCursor);	
				}
			}
			else
			{
		      CIVAnimatorDoc *pDoc =
			 (CIVAnimatorDoc *)OpenDocumentFile(newName);

			  if (openDlg.m_ofn.nFilterIndex < NUM_EXT_VALS)
			 m_nLastOpenedFilterIX = openDlg.m_ofn.nFilterIndex;
			}

	      }
	   }
}


int CIVAnimatorApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class

    IvfExitInstance();
	
	return CWinApp::ExitInstance();
}


BOOL CIVAnimatorApp::OnIdle(LONG lCount) 
{
	CIvfApp::IvfOnIdle(lCount);
	
	return CWinApp::OnIdle(lCount);
}


//  PreTranslateMessage -
//  thread messages are forwarded to the document for handling.
//
BOOL CIVAnimatorApp::PreTranslateMessage(MSG *pMsg) 
{
   CIvfDocument *pDoc = IvfGetDocument();
   if (!pDoc->IvfPreTranslateMessage(pMsg))
      return CWinApp::PreTranslateMessage(pMsg);

return(TRUE);
}

void CIVAnimatorApp::OnFileViewInfo() 
{
CIvfDocument *pIvfDoc = IvfGetDocument();
pIvfDoc->OnFileViewInfo();
}


void CIVAnimatorApp::OnUpdateFileViewInfo(CCmdUI* pCmdUI) 
{
CIvfDocument *t_IvfDoc = IvfGetDocument();
pCmdUI->Enable(t_IvfDoc != NULL && t_IvfDoc->IvfIsInfoSet());
}


//  OnFileNew --
//  Overridden to prevent prompt for filetype in case of multiple
//  document types.
void CIVAnimatorApp::OnFileNew()
{
POSITION pos = GetFirstDocTemplatePosition();
CDocTemplate* pTemplate = GetNextDocTemplate(pos);
pTemplate->OpenDocumentFile(NULL);
}
// END_IVWGEN


void CIVAnimatorApp::OnUpdateViewMoviecontroller(CCmdUI* pCmdUI) 
{
	CView* pView = IvfGetAfxView();
	CIVAnimatorDoc *pDoc = (CIVAnimatorDoc*)pView->GetDocument();
	pCmdUI->Enable(pDoc->EnableMovieController);
}
