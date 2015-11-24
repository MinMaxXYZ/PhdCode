// CamViewer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include <afxwin.h>
#include "CamViewer.h"

#include "MainFrm.h"
#include "CamViewerDoc.h"
#include "CamViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCamViewerApp

BEGIN_MESSAGE_MAP(CCamViewerApp, CWinApp)
	//{{AFX_MSG_MAP(CCamViewerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamViewerApp construction

CCamViewerApp::CCamViewerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCamViewerApp object

CCamViewerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCamViewerApp initialization

BOOL CCamViewerApp::InitInstance()
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

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCamViewerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CCamViewerView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
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
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

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

// App command to run the dialog
void CCamViewerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CCamViewerApp commands
static char *def_ext[] = {NULL, ".hci"};


void CCamViewerApp::OnFileOpen() 
{
	const char szFilter[] =
	"Hamamatsu Camera Images (*.hci)\0*.hci\0 All Files (*.*)\0*.*\0";

	const char szTitle[] = "Open File";

	CFileDialog openDlg(TRUE);

	openDlg.m_ofn.lpstrTitle = szTitle;
	openDlg.m_ofn.lpstrFilter = szFilter ;
	openDlg.m_ofn.nFilterIndex = m_nLastOpenedFilterIX;
	openDlg.m_ofn.lpstrCustomFilter = NULL;
	openDlg.m_ofn.lpstrDefExt = def_ext[m_nLastOpenedFilterIX];
	openDlg.m_ofn.nMaxCustFilter = 0;

	openDlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_PATHMUSTEXIST) ;

	POSITION pos = GetFirstDocTemplatePosition();
	CDocTemplate* pTemplate = GetNextDocTemplate(pos);
	CCamViewerDoc* pDoc = (CCamViewerDoc*)pTemplate->OpenDocumentFile(NULL);

	if (openDlg.DoModal() == IDOK)
	{
		CString newName = openDlg.m_ofn.lpstrFile;
		if (pDoc->OpenFile(openDlg.m_ofn.lpstrFile))
		{
			pDoc->CalculateAngles();
			pDoc->CalculateAngleDerivatives();
			pDoc->UpdateAllViews(NULL);



			HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
			SetCursor(arrowCursor);	
		}
		else
		{
			AfxMessageBox(CString("Cannot open ")+openDlg.m_ofn.lpstrFile, MB_OK);
		}

	}
	
	//RedrawWindow(NULL,NULL,NULL,RDW_UPDATENOW);
}
