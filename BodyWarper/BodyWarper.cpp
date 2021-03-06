// BodyWarper.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BodyWarper.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "BodyWarperDoc.h"
#include "BodyWarperView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <Ivf/Viewers/IvfRenderArea.h>
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


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
// CBodyWarperApp

BEGIN_MESSAGE_MAP(CBodyWarperApp, CWinApp)
	//{{AFX_MSG_MAP(CBodyWarperApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	ON_COMMAND(ID_FILE_INFO, OnFileViewInfo)
	ON_UPDATE_COMMAND_UI(ID_FILE_INFO, OnUpdateFileViewInfo)
	//}}AFX_MSG_MAP

	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperApp construction

CBodyWarperApp::CBodyWarperApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBodyWarperApp object

CBodyWarperApp theApp;

// BEGIN_IVWGEN
IVF_AFX_CONVERSION_METHOD(CBodyWarperView,CBodyWarperDoc)
// END_IVWGEN


/////////////////////////////////////////////////////////////////////////////
// CBodyWarperApp initialization

BOOL CBodyWarperApp::InitInstance()
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

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_BODYWATYPE,
		RUNTIME_CLASS(CBodyWarperDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CBodyWarperView));
	AddDocTemplate(pDocTemplate);

// BEGIN_IVWGEN
	CIvfApp::m_pDocTemplate = pDocTemplate;
// END_IVWGEN


	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

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

	// Some corporate branding
	CAboutDlg A;	
	A.DoModal();



	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
 



	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

#include <Ivf/Viewers/IvfRenderArea.h>


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
void CBodyWarperApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperApp commands

//static char *def_ext[] = {NULL, ".iv", ".wrl"};
#define NUM_EXT_VALS	3

// BEGIN_IVWGEN
void CBodyWarperApp::OnFileOpen() 
{

	const char szFilter[] =
	"Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0";

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
	      CBodyWarperDoc *pDoc =
		 (CBodyWarperDoc *)OpenDocumentFile(newName);

	      if (openDlg.m_ofn.nFilterIndex < NUM_EXT_VALS)
		 m_nLastOpenedFilterIX = openDlg.m_ofn.nFilterIndex;
	      }
	   }
}


int CBodyWarperApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class

    IvfExitInstance();
	
	return CWinApp::ExitInstance();
}


BOOL CBodyWarperApp::OnIdle(LONG lCount) 
{
	CIvfApp::IvfOnIdle(lCount);
	
	return CWinApp::OnIdle(lCount);
}


//  PreTranslateMessage -
//  thread messages are forwarded to the document for handling.
//
BOOL CBodyWarperApp::PreTranslateMessage(MSG *pMsg) 
{
   CIvfDocument *pDoc = IvfGetDocument();
   if (!pDoc->IvfPreTranslateMessage(pMsg))
      return CWinApp::PreTranslateMessage(pMsg);

return(TRUE);
}

void CBodyWarperApp::OnFileViewInfo() 
{
CIvfDocument *pIvfDoc = IvfGetDocument();
pIvfDoc->OnFileViewInfo();
}


void CBodyWarperApp::OnUpdateFileViewInfo(CCmdUI* pCmdUI) 
{
CIvfDocument *t_IvfDoc = IvfGetDocument();
pCmdUI->Enable(t_IvfDoc != NULL && t_IvfDoc->IvfIsInfoSet());
}


//  OnFileNew --
//  Overridden to prevent prompt for filetype in case of multiple
//  document types.
void CBodyWarperApp::OnFileNew()
{
POSITION pos = GetFirstDocTemplatePosition();
CDocTemplate* pTemplate = GetNextDocTemplate(pos);
pTemplate->OpenDocumentFile(NULL);
}
// END_IVWGEN

