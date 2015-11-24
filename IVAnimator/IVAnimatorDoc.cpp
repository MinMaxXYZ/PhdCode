// IVAnimatorDoc.cpp : implementation of the CIVAnimatorDoc class
//

#include "stdafx.h"
#include "IVAnimator.h"

#include "IVAnimatorDoc.h"
#include "IVAnimatorView.h"

#include "DlgMovieController.h"


#include <fstream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorDoc

IMPLEMENT_DYNCREATE(CIVAnimatorDoc, CDocument)

BEGIN_MESSAGE_MAP(CIVAnimatorDoc, CDocument)
	//{{AFX_MSG_MAP(CIVAnimatorDoc)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_UPDATE_COMMAND_UI(ID_FILE_IMPORT, OnUpdateFileImport)
	ON_UPDATE_COMMAND_UI(IDM_VIEWPOINTS, OnUpdateViewpoints)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_RELOAD, OnFileReload)
	ON_UPDATE_COMMAND_UI(ID_FILE_RELOAD, OnUpdateFileReload)
	ON_COMMAND(ID_VIEW_MOVIECONTROLLER, OnViewMoviecontroller)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorDoc construction/destruction

CIVAnimatorDoc::CIVAnimatorDoc()
{
	// TODO: add one-time construction code here

// BEGIN_IVWGEN
	m_bContainsCamera = FALSE;
	m_eOpenType = IVFDOC_OPEN_NORMAL;
// END_IVWGEN

	EnableMovieController = FALSE;
}

CIVAnimatorDoc::~CIVAnimatorDoc()
{
}

BOOL CIVAnimatorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

// BEGIN_IVWGEN
	IvfOnNewDocument();
// END_IVWGEN

 
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorDoc serialization

void CIVAnimatorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
// BEGIN_IVWGEN
            IvfOnSaveDocument(ar.GetFile()->m_hFile) ;
// END_IVWGEN
 
	}
	else
	{
// BEGIN_IVWGEN
		IvfOnOpenDocument(ar.GetFile()->m_hFile) ;
// END_IVWGEN
	}
}

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorDoc diagnostics

#ifdef _DEBUG
void CIVAnimatorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIVAnimatorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIVAnimatorDoc commands




//  OnFileImport --
//  yet another special file open scenario.  still want to route
//  through OpenDocument to handle menus, urls, etc., but don't
//  want to actually update the document per se.  This just gets
//  added to the current doc.
//
void CIVAnimatorDoc::OnFileImport()
{
m_eOpenType = IVFDOC_OPEN_IMPORT;
theApp.OnFileOpen();
}


void CIVAnimatorDoc::OnUpdateFileImport(CCmdUI *pCmdUI)
{
pCmdUI->Enable(m_pSceneRoot != NULL);
}


BOOL CIVAnimatorDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
return(IvfOnOpenDocumentMessage(lpszPathName));
}

void CIVAnimatorDoc::OnUpdateViewpoints(CCmdUI* pCmdUI) 
{
IvfOnUpdateViewpoints(pCmdUI);
}


static char spv_save_suffix[] = ".iv";
static char spv_save_filter[] =
   "Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0BMP Files (*.bmp)\0*.bmp\0";

void CIVAnimatorDoc::OnFileSaveAs() 
{
CFileDialog save_dlg(FALSE);
                        //  create the dialog

	save_dlg.m_ofn.lpstrFilter = spv_save_filter ;
	save_dlg.m_ofn.nFilterIndex = 1L;
	save_dlg.m_ofn.lpstrCustomFilter = NULL;
	save_dlg.m_ofn.lpstrDefExt = spv_save_suffix+1;
	save_dlg.m_ofn.nMaxCustFilter = 0;
        save_dlg.m_ofn.lpstrFile[0] = '\0';

	save_dlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT) ;


if (save_dlg.DoModal() != IDCANCEL)
   {
   BOOL stat = FALSE;

   // Note: Saving may change the file type, e.g. from Inventor to VRML 
   switch (save_dlg.m_ofn.nFilterIndex)
      {
      case 1: 	// .iv file
         IvfSetFileType(IVF_FILETYPE_IV);
         stat = OnSaveDocument(save_dlg.m_ofn.lpstrFile);
         break;
			// Set filetype to Inventor in case it was VRML.

      case 2:	// .wrl file
         if (IvfGetFileType() == IVF_FILETYPE_IV)
            IvfSetFileType(IVF_FILETYPE_VRML);
         stat = OnSaveDocument(save_dlg.m_ofn.lpstrFile);
         break;
			//  VRML requires new header - need to set the filetype.
                        //  Don't change if file was read in as VRML or VRML2.

      case 3:	// .bmp file
         {
         CIVAnimatorView *t_view =
	    (CIVAnimatorView *)CIvfApp::IvfGetAfxView();
         stat = t_view->SaveAsBitmap(save_dlg.m_ofn.lpstrFile);
         }
         break;
			//  .bmp is totally different - let view handle.
      }
   }
}

BOOL CIVAnimatorDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
BOOL stat;
CIVAnimatorView *pView =
   (CIVAnimatorView *)CIvfApp::IvfGetAfxView();

//  pView->SendMessage(WM_COMMAND, ID_VIEW_VIEWINGMODE, 0);
		//  don't need this any more ??


stat = CDocument::OnSaveDocument(lpszPathName);

return(stat);
}

void CIVAnimatorDoc::OnFileReload() 
{

IvfDeleteContents();
OnOpenDocument(GetPathName());
}

void CIVAnimatorDoc::OnUpdateFileReload(CCmdUI* pCmdUI) 
{
pCmdUI->Enable(m_pSceneRoot != NULL);
}



void CIVAnimatorDoc::IvfSetupUrlFetchCallback(void)
{
CIvfDocument::IvfSetupUrlFetchCallback();
}

BOOL CIVAnimatorDoc::OpenFiles(const CString& input_file)
{
	root = new SoSeparator;
    root->ref();

	myblinker = new SoBlinker;
	myblinker->speed = 0.2;
	root->addChild(myblinker);

	//opening the list file
	ifstream l_file;
	l_file.open(input_file, ios::nocreate|ios::in);
	if (!l_file.good()) {	} //appropriate flag here

	//retrieving the list count
	const unsigned int bufsize=500;
	char buf[bufsize];
	l_file.getline(buf,bufsize,'\n'); //first line is a comment line
	l_file >> n_frames;
	l_file.getline(buf,bufsize,'\n');

	for(unsigned int j = 0; j < n_frames; j++)
	{
		// retrieving the list item
		l_file.getline(buf,bufsize,'\n');
		SoFile* myfile = new SoFile;
		myfile->name = buf;
	
		// copying the file contents to a group node;
		SoGroup* mygroup = new SoGroup;
		mygroup = myfile->copyChildren();
	
		// copying the group nodes to a separator
		myframe[j] = new SoSeparator;
		int n = mygroup->getNumChildren();
		for(int i = 0; i < n; i++)
		{
			myframe[j]->addChild(mygroup->getChild(i));
		}
	
		// attaching the separator to the blinker
		myblinker->addChild(myframe[j]);
	}

	l_file.close();

	// switching on the blinker
	myblinker->on = TRUE;
	IvfSetSceneGraph( root );
	root->unref();

	EnableMovieController = TRUE;

	return TRUE; // change this to flag errors
}

void CIVAnimatorDoc::OnViewMoviecontroller() 
{
	CDlgMovieController* C = new CDlgMovieController;
	C->Create(IDD_MOVIECONTROLLER,NULL);
	C->AttachDocument(this);
}

