// BodyAnalyser.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "direct.h"
#include "BodyAnalyser.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "BodyAnalyserDoc.h"
#include "BodyAnalyserView.h"

#include <process.h>
#include <fstream.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserApp

BEGIN_MESSAGE_MAP(CBodyAnalyserApp, CWinApp)
	//{{AFX_MSG_MAP(CBodyAnalyserApp)
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
// CBodyAnalyserApp construction

CBodyAnalyserApp::CBodyAnalyserApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
		
	// init the arrays that will store downloaded data from hardware
	m_dist1 = new short[25600];
	m_dist2 = new short[25600];
	m_dist3 = new short[25600];
	m_dist4 = new short[25600];

	m_brbuf1 = new unsigned char[25600];
	m_brbuf2 = new unsigned char[25600];
	m_brbuf3 = new unsigned char[25600];
	m_brbuf4 = new unsigned char[25600];

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBodyAnalyserApp object

CBodyAnalyserApp theApp;

// BEGIN_IVWGEN
IVF_AFX_CONVERSION_METHOD(CBodyAnalyserView,CBodyAnalyserDoc)
// END_IVWGEN


/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserApp initialization

BOOL CBodyAnalyserApp::InitInstance()
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
		IDR_BODYANTYPE,
		RUNTIME_CLASS(CBodyAnalyserDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CBodyAnalyserView));
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


	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
 
	// get the default head parameters for this scanner
	char cwd[256];
	_getcwd(cwd, 256);
	CString params_file = cwd;
	params_file += "\\default.prm";
	PARAMS param_struct;
	LoadHeadParameters(params_file, param_struct);
	SetParams(param_struct);

	// construct the debug directory
	_mkdir("c:\\BA_Monitor");

	//throw a readme.txt file in the debug directory
	ofstream readme_file;
	readme_file.open("c:\\BA_Monitor\\README.TXT",ios::out|ios::trunc);
	readme_file << "This folder was created by BodyAnalyser for the purposes of error output.\n\n";
	readme_file << "It is created automatically every time BodyAnalyser is run,\n";
	readme_file << "and it is completely safe to delete if you want to save some disk space.\n\n";
	readme_file << "It will typically contain files of a total size of no more than 2-3MB.\n\n";
	readme_file << "BodyAnalyser - Copyright(c) Ioannis Douros 2003.\n";
	readme_file.close();


	return TRUE;
}

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
	CString	m_slices;
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_slices = _T("");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_ABOUT_TEXT, m_slices);
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

	CWnd *pWnd = GetDlgItem(IDC_ABOUT_TEXT) ;
	IvfCreateComponent(pWnd,(void *)cArgs);

	IvfSpinText("MICROSOFT\nVisual C++\n4.2");

	return TRUE;
}
// END_IVWGEN

// App command to run the dialog
void CBodyAnalyserApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserApp commands

static char *def_ext[] = {NULL, ".iv", ".wrl"};
#define NUM_EXT_VALS	3

// BEGIN_IVWGEN
void CBodyAnalyserApp::OnFileOpen() 
{

	const char szFilter[] =
	"Hamamatsu Scans (*.bls)\0*.bls\0Hamamatsu Structured Cartesian (*.hci)\0*.hci\0Structured Curvature Map (*.hcc)\0*.hcc\0Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0";

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

           if (!_stricmp( "bls",&(openDlg.m_ofn.lpstrFile[extn]) ) )

		   //if it's a Hamamatsu Scan
			{
				POSITION pos = GetFirstDocTemplatePosition();
				CDocTemplate* pTemplate = GetNextDocTemplate(pos);
				CBodyAnalyserDoc* pDoc = (CBodyAnalyserDoc*)pTemplate->OpenDocumentFile(NULL);

				if (pDoc)
				{	
					HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
					SetCursor(waitCursor);	
					
					if (pDoc->OpenFile(openDlg.m_ofn.lpstrFile))
					{
						//Insert own implementations of cleaning and rendering here 
						pDoc->CleanBody();
						pDoc->RenderBody();	
						//pDoc->CreateCameraImages();	//debug purposes only

						// set the title text
						CView* pView = IvfGetAfxView();
						pView->SetWindowText(openDlg.m_ofn.lpstrFile);

						HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
						SetCursor(arrowCursor);	
					}
					else
					{
						AfxMessageBox(CString("Cannot open ")+openDlg.m_ofn.lpstrFile, MB_OK);
					}
				}
		   }

			else
		   //if it's not a Hamamatsu Scan

			if(!_stricmp("hci",&(openDlg.m_ofn.lpstrFile[extn]))) 
			// it's a structured cartesian
			{
				POSITION pos = GetFirstDocTemplatePosition();
				CDocTemplate* pTemplate = GetNextDocTemplate(pos);
				CBodyAnalyserDoc* pDoc = (CBodyAnalyserDoc*)pTemplate->OpenDocumentFile(NULL);

				if (pDoc)
				{	
					HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
					SetCursor(waitCursor);	
					
					if (pDoc->OpenSCFile(openDlg.m_ofn.lpstrFile))
					{
						//Insert own implementations of cleaning and rendering here 
						pDoc->RenderBody();	

						// set the title text
						CView* pView = IvfGetAfxView();
						pView->SetWindowText(openDlg.m_ofn.lpstrFile);

						HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
						SetCursor(arrowCursor);	
					}
					else
					{
						AfxMessageBox(CString("Cannot open ")+openDlg.m_ofn.lpstrFile, MB_OK);
					}
				}
			}
// ----------------			
			
			else if(!_stricmp("hcc",&(openDlg.m_ofn.lpstrFile[extn])))
				//  it is a curvature map
			{
				POSITION pos = GetFirstDocTemplatePosition();
				CDocTemplate* pTemplate = GetNextDocTemplate(pos);
				CBodyAnalyserDoc* pDoc = (CBodyAnalyserDoc*)pTemplate->OpenDocumentFile(NULL);

				if (pDoc)
				{	
					HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
					SetCursor(waitCursor);	
					
					if (pDoc->OpenHCCFile(openDlg.m_ofn.lpstrFile))
					{
						//Insert own implementations of cleaning and rendering here 
						pDoc->RenderBody();	

						// set the title text
						CView* pView = IvfGetAfxView();
						pView->SetWindowText(openDlg.m_ofn.lpstrFile);

// -----------------------------------------------------------------------------
//							COPIED FROM THE BOTTOM OF OnToolsCurvature
// it should be a separate function

/*
	//histogramming
	CreateCurvatureHistograms();
//	SaveCurvatureHistograms();	// make this a user choice or menu item.
	CDlgHistogram* m_dlgHistogram = new CDlgHistogram;
	m_dlgHistogram->AttachDocument(this);
	m_dlgHistogram->DoModal();
*/
	//The block above has been removed because we do not have the extremal values of 
	//the curvature properties (a future task...)

	//visualisation 
	for(unsigned int cam = 0; cam < pDoc->getCameras(); cam++) 
	{
		//curvature map
		pDoc->RenderCurvatureMap(cam);

		//curvature directions
		//SoSeparator* sd = new SoSeparator;
		//sd = RenderCurvatureDirections(cam);
		//s_curvatureDirections->addChild(sd);
	}
//---------------------------------------------------------------------------



						HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
						SetCursor(arrowCursor);	
					}
					else
					{
						AfxMessageBox(CString("Cannot open ")+openDlg.m_ofn.lpstrFile, MB_OK);
					}
				}
			}
			
			
			
// ----------------			
			
			else
			// it's not a structured cartesian either
			{

		      CBodyAnalyserDoc *pDoc =
			 (CBodyAnalyserDoc *)OpenDocumentFile(newName);

			  if (openDlg.m_ofn.nFilterIndex < NUM_EXT_VALS)
			  m_nLastOpenedFilterIX = openDlg.m_ofn.nFilterIndex;
			}
	      }
	   }
}


int CBodyAnalyserApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class

    IvfExitInstance();
	
	return CWinApp::ExitInstance();
}


BOOL CBodyAnalyserApp::OnIdle(LONG lCount) 
{
	CIvfApp::IvfOnIdle(lCount);
	
	return CWinApp::OnIdle(lCount);
}


//  PreTranslateMessage -
//  thread messages are forwarded to the document for handling.
//
BOOL CBodyAnalyserApp::PreTranslateMessage(MSG *pMsg) 
{
   CIvfDocument *pDoc = IvfGetDocument();
   if (!pDoc->IvfPreTranslateMessage(pMsg))
      return CWinApp::PreTranslateMessage(pMsg);

return(TRUE);
}

void CBodyAnalyserApp::OnFileViewInfo() 
{
CIvfDocument *pIvfDoc = IvfGetDocument();
pIvfDoc->OnFileViewInfo();
}


void CBodyAnalyserApp::OnUpdateFileViewInfo(CCmdUI* pCmdUI) 
{
CIvfDocument *t_IvfDoc = IvfGetDocument();
pCmdUI->Enable(t_IvfDoc != NULL && t_IvfDoc->IvfIsInfoSet());
}


//  OnFileNew --
//  Overridden to prevent prompt for filetype in case of multiple
//  document types.
void CBodyAnalyserApp::OnFileNew()
{
//POSITION pos = GetFirstDocTemplatePosition();
//CDocTemplate* pTemplate = GetNextDocTemplate(pos);
//pTemplate->OpenDocumentFile(NULL);
}
// END_IVWGEN


BOOL CBodyAnalyserApp::OpenFromFile(ifstream& bls_input)
{
	bls_input >> binary;
	bls_input.read((char*)m_dist1, 51200);
	bls_input.read((char*)m_dist2, 51200);
	bls_input.read((char*)m_dist3, 51200);
	bls_input.read((char*)m_dist4, 51200);
	bls_input.read((char*)m_brbuf1, 25600);
	bls_input.read((char*)m_brbuf2, 25600);
	bls_input.read((char*)m_brbuf3, 25600);
	bls_input.read((char*)m_brbuf4, 25600);

	return TRUE;
}

short CBodyAnalyserApp::GetBrightness(int slice, int index)
{
	unsigned char* br_buf;

	assert(slice>=0 && slice<400);
	assert(index>=0 && index<256);

	long abs_index = slice*256 + index;
	int buf_no = (float)abs_index/25600;
	long rel_index = abs_index - buf_no*25600;
	
	assert(buf_no>=0 && buf_no<5);
	assert(rel_index>=0 && rel_index<25600);

	switch (buf_no)
	{
	case 0:
		br_buf = m_brbuf1;
		break;
	case 1:
		br_buf = m_brbuf2;
		break;
	case 2:
		br_buf = m_brbuf3;
		break;
	case 3:
		br_buf = m_brbuf4;
		break;
	}

	return br_buf[rel_index];

}

short CBodyAnalyserApp::GetDistance(int slice, int index)
{
	short* dist_buf;

	assert(slice>=0 && slice<400);
	assert(index>=0 && index<256);

	long abs_index = slice*256 + index;
	int buf_no = (float)abs_index/25600;
	long rel_index = abs_index - buf_no*25600;
	
	assert(buf_no>=0 && buf_no<5);
	assert(rel_index>=0 && rel_index<25600);

	switch (buf_no)
	{
	case 0:
		dist_buf = m_dist1;
		break;
	case 1:
		dist_buf = m_dist2;
		break;
	case 2:
		dist_buf = m_dist3;
		break;
	case 3:
		dist_buf = m_dist4;
		break;
	}

	return dist_buf[rel_index];

}

// parameter management

void CBodyAnalyserApp::SetParams(PARAMS& params)
{
	int i;
	for (i=0; i<8; i++)
	{
		m_scanner_params.m_hdx[i] = params.m_hdx[i];
		m_scanner_params.m_hdy[i] = params.m_hdy[i];
		m_scanner_params.m_hda[i] = params.m_hda[i];
	}
	m_scanner_params.m_params_file = params.m_params_file;
}

BOOL CBodyAnalyserApp::LoadHeadParameters(const CString& params_file, PARAMS& params)
{
	int head;
	ifstream prm_file;
	BOOL status = FALSE;
	
	prm_file.open(params_file,ios::in|ios::nocreate);
	
	if (!prm_file.good())
	{
		AfxMessageBox("Cannot open parameters file", MB_OK);
		return FALSE;
	}

	for (head=0; head<8; head++)
	{
		if (!prm_file.good())
		{
			AfxMessageBox("Incorrect format in parameters file", MB_OK);
			return FALSE;
		}
		prm_file >> params.m_hdx[head];
		prm_file >> params.m_hdy[head];
		prm_file >> params.m_hda[head];
	}
	prm_file.close();

	if (prm_file.good())
	{
		params.m_params_file = params_file;
		status = TRUE;
	}	

	return status;
}

PARAMS& CBodyAnalyserApp::Params(void)
{
	return m_scanner_params;
}
