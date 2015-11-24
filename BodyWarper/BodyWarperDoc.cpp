// BodyWarperDoc.cpp : implementation of the CBodyWarperDoc class
//



#include "stdafx.h"
#include "BodyWarper.h"

#include "BodyWarperDoc.h"
#include "BodyWarperView.h"

#include <fstream.h>
#include <MathTools.h>
#include "InsufficientLandmarksDlg.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperDoc

IMPLEMENT_DYNCREATE(CBodyWarperDoc, CDocument)

BEGIN_MESSAGE_MAP(CBodyWarperDoc, CDocument)
	//{{AFX_MSG_MAP(CBodyWarperDoc)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_UPDATE_COMMAND_UI(ID_FILE_IMPORT, OnUpdateFileImport)
	ON_UPDATE_COMMAND_UI(IDM_VIEWPOINTS, OnUpdateViewpoints)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_RELOAD, OnFileReload)
	ON_UPDATE_COMMAND_UI(ID_FILE_RELOAD, OnUpdateFileReload)
	ON_COMMAND(ID_FILE_LOADSOURCESHAPE, OnFileLoadsourceshape)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SOURCESHAPE_SOLID, OnUpdateViewSourceshapeSolid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SOURCESHAPE_WIREFRAME, OnUpdateViewSourceshapeWireframe)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SOURCESHAPE_POINTS, OnUpdateViewSourceshapePoints)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SOURCESHAPE_HIDE, OnUpdateViewSourceshapeHide)
	ON_COMMAND(ID_FILE_LOADTARGETSHAPE, OnFileLoadtargetshape)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TARGETSHAPE_SOLID, OnUpdateViewTargetshapeSolid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TARGETSHAPE_WIREFRAME, OnUpdateViewTargetshapeWireframe)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TARGETSHAPE_POINTS, OnUpdateViewTargetshapePoints)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TARGETSHAPE_HIDE, OnUpdateViewTargetshapeHide)
	ON_COMMAND(ID_FILE_LOADSOURCELANDMARKS, OnFileLoadsourcelandmarks)
	ON_COMMAND(ID_FILE_LOADTARGETLANDMARKS, OnFileLoadtargetlandmarks)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SOURCELANDMARKS, OnUpdateViewSourcelandmarks)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TARGETLANDMARKS, OnUpdateViewTargetlandmarks)
	ON_COMMAND(ID_FILE_CALCULATETRANSFORMATION, OnFileCalculatetransformation)
	ON_COMMAND(ID_FILE_LOADTRANSFORMATION, OnFileLoadtransformation)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVETRANSFORMATION, OnUpdateFileSavetransformation)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WARPEDSHAPE_SOLID, OnUpdateViewWarpedshapeSolid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WARPEDSHAPE_WIREFRAME, OnUpdateViewWarpedshapeWireframe)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WARPEDSHAPE_POINTS, OnUpdateViewWarpedshapePoints)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WARPEDSHAPE_HIDE, OnUpdateViewWarpedshapeHide)
	ON_UPDATE_COMMAND_UI(ID_FILE_CALCULATETRANSFORMATION, OnUpdateFileCalculatetransformation)
	ON_UPDATE_COMMAND_UI(ID_FILE_LOADTRANSFORMATION, OnUpdateFileLoadtransformation)
	ON_COMMAND(ID_VIEW_SOURCESHAPE_SOLID, OnViewSourceshapeSolid)
	ON_COMMAND(ID_VIEW_SOURCESHAPE_WIREFRAME, OnViewSourceshapeWireframe)
	ON_COMMAND(ID_VIEW_SOURCESHAPE_POINTS, OnViewSourceshapePoints)
	ON_COMMAND(ID_VIEW_SOURCESHAPE_HIDE, OnViewSourceshapeHide)
	ON_COMMAND(ID_VIEW_TARGETSHAPE_SOLID, OnViewTargetshapeSolid)
	ON_COMMAND(ID_VIEW_TARGETSHAPE_WIREFRAME, OnViewTargetshapeWireframe)
	ON_COMMAND(ID_VIEW_TARGETSHAPE_POINTS, OnViewTargetshapePoints)
	ON_COMMAND(ID_VIEW_TARGETSHAPE_HIDE, OnViewTargetshapeHide)
	ON_COMMAND(ID_VIEW_SOURCELANDMARKS, OnViewSourcelandmarks)
	ON_COMMAND(ID_VIEW_TARGETLANDMARKS, OnViewTargetlandmarks)
	ON_COMMAND(ID_VIEW_WARPEDSHAPE_SOLID, OnViewWarpedshapeSolid)
	ON_COMMAND(ID_VIEW_WARPEDSHAPE_WIREFRAME, OnViewWarpedshapeWireframe)
	ON_COMMAND(ID_VIEW_WARPEDSHAPE_POINTS, OnViewWarpedshapePoints)
	ON_COMMAND(ID_VIEW_WARPEDSHAPE_HIDE, OnViewWarpedshapeHide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperDoc construction/destruction

CBodyWarperDoc::CBodyWarperDoc()
{
	// TODO: add one-time construction code here

// BEGIN_IVWGEN
	m_bContainsCamera = FALSE;
	m_eOpenType = IVFDOC_OPEN_NORMAL;
// END_IVWGEN


	source_shape_color = new SoMaterial;
	source_shape_style = new SoDrawStyle;

	target_shape_color = new SoMaterial;
	target_shape_style = new SoDrawStyle;

	warped_shape_color = new SoMaterial;
	warped_shape_style = new SoDrawStyle;

	source_landmarks_color = new SoMaterial;
	source_landmarks_style = new SoDrawStyle;
	source_landmarks_style->pointSize = 7;

	target_landmarks_color = new SoMaterial;
	target_landmarks_style = new SoDrawStyle;
	target_landmarks_style->pointSize = 7;

	SourceShapeLoaded		= FALSE;
	SourceLandmarksLoaded	= FALSE;
	TargetShapeLoaded		= FALSE;
	TargetLandmarksLoaded	= FALSE;
	WarpingComplete			= FALSE;

}

CBodyWarperDoc::~CBodyWarperDoc()
{
}

BOOL CBodyWarperDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

 
// BEGIN_IVWGEN
	IvfOnNewDocument();
// END_IVWGEN
 
	root = new SoSeparator;
	root->ref();

	IvfSetSceneGraph(root);
	root->unref();


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperDoc serialization

void CBodyWarperDoc::Serialize(CArchive& ar)
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
// CBodyWarperDoc diagnostics

#ifdef _DEBUG
void CBodyWarperDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBodyWarperDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBodyWarperDoc commands




//  OnFileImport --
//  yet another special file open scenario.  still want to route
//  through OpenDocument to handle menus, urls, etc., but don't
//  want to actually update the document per se.  This just gets
//  added to the current doc.
//
void CBodyWarperDoc::OnFileImport()
{
m_eOpenType = IVFDOC_OPEN_IMPORT;
theApp.OnFileOpen();
}


void CBodyWarperDoc::OnUpdateFileImport(CCmdUI *pCmdUI)
{
pCmdUI->Enable(m_pSceneRoot != NULL);
}


BOOL CBodyWarperDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
return(IvfOnOpenDocumentMessage(lpszPathName));
}

void CBodyWarperDoc::OnUpdateViewpoints(CCmdUI* pCmdUI) 
{
IvfOnUpdateViewpoints(pCmdUI);
}


static char spv_save_suffix[] = ".iv";
static char spv_save_filter[] =
   "Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0BMP Files (*.bmp)\0*.bmp\0";

void CBodyWarperDoc::OnFileSaveAs() 
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
         CBodyWarperView *t_view =
	    (CBodyWarperView *)CIvfApp::IvfGetAfxView();
         stat = t_view->SaveAsBitmap(save_dlg.m_ofn.lpstrFile);
         }
         break;
			//  .bmp is totally different - let view handle.
      }
   }
}

BOOL CBodyWarperDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
BOOL stat;
CBodyWarperView *pView =
   (CBodyWarperView *)CIvfApp::IvfGetAfxView();

//  pView->SendMessage(WM_COMMAND, ID_VIEW_VIEWINGMODE, 0);
		//  don't need this any more ??


stat = CDocument::OnSaveDocument(lpszPathName);

return(stat);
}

void CBodyWarperDoc::OnFileReload() 
{
CIvfApp *pApp = CIvfApp::IvfGetApp();

IvfDeleteContents();
OnOpenDocument(GetPathName());
if (pApp->IvfIsMdi()) IvfSceneGraphChanged();
			//  an mdi app needs to treat the single
			//  frame as an SDI to reload.
}

void CBodyWarperDoc::OnUpdateFileReload(CCmdUI* pCmdUI) 
{
pCmdUI->Enable(m_pSceneRoot != NULL);
}



void CBodyWarperDoc::IvfSetupUrlFetchCallback(void)
{
CIvfDocument::IvfSetupUrlFetchCallback();
}

void CBodyWarperDoc::OnFileLoadsourceshape() 
{
	const char szFilter[] =
	"Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0";

	const char szTitle[] = "Open Source Shape File";

	CFileDialog openDlg(TRUE);

	openDlg.m_ofn.lpstrTitle = szTitle;
	openDlg.m_ofn.lpstrFilter = szFilter ;
	openDlg.m_ofn.nFilterIndex = theApp.m_nLastOpenedFilterIX;
	openDlg.m_ofn.lpstrCustomFilter = NULL;
	openDlg.m_ofn.lpstrDefExt = def_ext[theApp.m_nLastOpenedFilterIX];
	openDlg.m_ofn.nMaxCustFilter = 0;

	openDlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_PATHMUSTEXIST) ;

	SourceShapeLoaded = TRUE;
	if (openDlg.DoModal() == IDOK)
	{
		HCURSOR waitCursor= theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		const unsigned int bufsize = 500;
		char buf[bufsize];
		ifstream iv_file;
		int pCount;
		float x,y,z;
		char ch[10];
		//float a,b,c;
		BOOL carryOn;

		iv_file.open(openDlg.m_ofn.lpstrFile, ios::nocreate|ios::in);
		if (!iv_file.good()) {	SourceShapeLoaded = FALSE;}

		// HEAD
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			source_head[pCount][0] = x;
			source_head[pCount][1] = y;
			source_head[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> source_head_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> source_head_cols;

		//TORSO
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			source_torso[pCount][0] = x;
			source_torso[pCount][1] = y;
			source_torso[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> source_torso_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> source_torso_cols;
		
		// RLEG
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			source_rleg[pCount][0] = x;
			source_rleg[pCount][1] = y;
			source_rleg[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> source_rleg_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> source_rleg_cols;

		//LLEG
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			source_lleg[pCount][0] = x;
			source_lleg[pCount][1] = y;
			source_lleg[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> source_lleg_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> source_lleg_cols;
/*
		// Rarm
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			source_rarm[pCount][0] = x;
			source_rarm[pCount][1] = y;
			source_rarm[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> source_rarm_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> source_rarm_cols;

		//Larm
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			source_larm[pCount][0] = x;
			source_larm[pCount][1] = y;
			source_larm[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> source_larm_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> source_larm_cols;
*/		
		iv_file.close();
		render(SOURCE);

		HCURSOR arrowCursor= theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);
	}


}

void CBodyWarperDoc::OnFileLoadsourcelandmarks() 
{

		const char szFilter[] =
	"Text Landmark Files (*_lmk.txt)\0*_lmk.txt\0Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0All Files (*.*)\0*.*\0";

	const char szTitle[] = "Open Source Landmarks File";

	CFileDialog openDlg(TRUE);

	openDlg.m_ofn.lpstrTitle = szTitle;
	openDlg.m_ofn.lpstrFilter = szFilter ;
	openDlg.m_ofn.nFilterIndex = theApp.m_nLastOpenedFilterIX;
	openDlg.m_ofn.lpstrCustomFilter = NULL;
	openDlg.m_ofn.lpstrDefExt = def_ext[theApp.m_nLastOpenedFilterIX];
	openDlg.m_ofn.nMaxCustFilter = 0;

	openDlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_PATHMUSTEXIST) ;

	SourceLandmarksLoaded = TRUE;
	ShowSourceLandmarks = TRUE;

	if (openDlg.DoModal() == IDOK)
	{
		HCURSOR waitCursor= theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		const unsigned int bufsize = 50;
		char buf[bufsize];
		CString label;
		char curr_label[bufsize];
		ifstream iv_file;
		int pCount,i;
		float x,y,z;
		char ch[10];
		float a,b,c;
		BOOL carryOn, usefulLandmark;
		unsigned int loc;

		iv_file.open(openDlg.m_ofn.lpstrFile, ios::nocreate|ios::in);
		if (!iv_file.good()) {	SourceLandmarksLoaded = FALSE;	ShowSourceLandmarks = FALSE;}

		i = 0;
		carryOn = TRUE;
		for(pCount = 0; carryOn; )
		{
			iv_file.getline(buf,bufsize,' ');
			iv_file.getline(curr_label,bufsize,'\n');
			label = curr_label;
			
			iv_file.getline(buf,bufsize,':');
			iv_file >> x;		//height	

			iv_file.getline(buf,bufsize,':');
			iv_file >> y;		//width

			iv_file.getline(buf,bufsize,':');
			iv_file >> z;		//depth

			iv_file.getline(buf,bufsize,':');

			usefulLandmark = FALSE;

			if(label == "top_of_head")						{usefulLandmark = TRUE;		loc = TOP_OF_HEAD;}
			if(label == "centre_back_bust")					{usefulLandmark = TRUE;		loc = CENTRE_BACK_BUST;}
			if(label == "centre_front_bust")				{usefulLandmark = TRUE;		loc = CENTRE_FRONT_BUST;}
			if(label == "left_shoulder_point")				{usefulLandmark = TRUE;		loc = LEFT_SHOULDER_POINT;}
			if(label == "right_shoulder_point")				{usefulLandmark = TRUE;		loc = RIGHT_SHOULDER_POINT;}
			if(label == "greatest_posterior_prominence")	{usefulLandmark = TRUE;		loc = GREATEST_POSTERIOR_PROMINENCE;}
			if(label == "crotch_point")						{usefulLandmark = TRUE;		loc = CROTCH_POINT;}
			if(label == "left_hip_point")					{usefulLandmark = TRUE;		loc = LEFT_HIP_POINT;}
			if(label == "right_hip_point")					{usefulLandmark = TRUE;		loc = RIGHT_HIP_POINT;}
			if(label == "right_outer_ankle")				{usefulLandmark = TRUE;		loc = RIGHT_OUTER_ANKLE;}
			if(label == "left_outer_ankle")					{usefulLandmark = TRUE;		loc = LEFT_OUTER_ANKLE;}
			if(label == "left_side_waist")					{usefulLandmark = TRUE;		loc = LEFT_SIDE_WAIST;}
			if(label == "right_side_waist")					{usefulLandmark = TRUE;		loc = RIGHT_SIDE_WAIST;}
			if(label == "centre_back_waist")				{usefulLandmark = TRUE;		loc = CENTRE_BACK_WAIST;}
			if(label == "centre_front_waist")				{usefulLandmark = TRUE;		loc = CENTRE_FRONT_WAIST;}
			if(label == "left_inner_knee")					{usefulLandmark = TRUE;		loc = LEFT_INNER_KNEE;}
			if(label == "right_inner_knee")					{usefulLandmark = TRUE;		loc = RIGHT_INNER_KNEE;}
			if(label == "greatest_abdominal_prominence")	{usefulLandmark = TRUE;		loc = GREATEST_ABDOMINAL_PROMINENCE;}


			if(usefulLandmark)
			{
				source_landmark_label[loc] = label;
				source_landmark[loc][0] = z;	//depth
				source_landmark[loc][1] = x;	//height
				source_landmark[loc][2] = y;	//width
				
				pCount++;
			}
			i++;
			iv_file.getline(ch,10,'\n');
			if((pCount==N_LANDMARKS)||(i>37)) {carryOn = FALSE;}
		}

		source_landmark_label[FRONT_KNEE_PROJECTION] = "front_knee_projection";
		source_landmark[FRONT_KNEE_PROJECTION][0] = source_landmark[GREATEST_ABDOMINAL_PROMINENCE][0];	//depth
		source_landmark[FRONT_KNEE_PROJECTION][1] = 0.5*(source_landmark[LEFT_INNER_KNEE][1]+source_landmark[LEFT_INNER_KNEE][1]);	//height
		source_landmark[FRONT_KNEE_PROJECTION][2] = source_landmark[GREATEST_ABDOMINAL_PROMINENCE][2];	//width
		
		source_landmark_label[BACK_KNEE_PROJECTION] = "back_knee_projection";
		source_landmark[BACK_KNEE_PROJECTION][0] = source_landmark[GREATEST_POSTERIOR_PROMINENCE][0];	//depth
		source_landmark[BACK_KNEE_PROJECTION][1] = 0.5*(source_landmark[LEFT_INNER_KNEE][1]+source_landmark[LEFT_INNER_KNEE][1]);	//height
		source_landmark[BACK_KNEE_PROJECTION][2] = source_landmark[GREATEST_POSTERIOR_PROMINENCE][2];	//width

		source_landmark_label[ORIGIN] = "origin";
		source_landmark[ORIGIN][0] = 0.0;
		source_landmark[ORIGIN][1] = 0.0; 
		source_landmark[ORIGIN][2] = 0.0; 


		iv_file.close();
		n_source_landmarks = pCount;

		HCURSOR arrowCursor= theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);
		
		if(n_source_landmarks+3 < N_LANDMARKS)
		{
			SourceLandmarksLoaded = FALSE;
			ShowSourceLandmarks = FALSE;
			CInsufficientLandmarksDlg ilD;
			ilD.DoModal();
		}
		else
		{
			render(SOURCE_L);
		}

	}

}

void CBodyWarperDoc::OnFileLoadtargetshape() 
{
	const char szFilter[] =
	"Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0";

	const char szTitle[] = "Open Target Shape File";

	CFileDialog openDlg(TRUE);

	openDlg.m_ofn.lpstrTitle = szTitle;
	openDlg.m_ofn.lpstrFilter = szFilter ;
	openDlg.m_ofn.nFilterIndex = theApp.m_nLastOpenedFilterIX;
	openDlg.m_ofn.lpstrCustomFilter = NULL;
	openDlg.m_ofn.lpstrDefExt = def_ext[theApp.m_nLastOpenedFilterIX];
	openDlg.m_ofn.nMaxCustFilter = 0;

	openDlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_PATHMUSTEXIST) ;

	TargetShapeLoaded = TRUE;
	if (openDlg.DoModal() == IDOK)
	{
		HCURSOR waitCursor= theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		const unsigned int bufsize = 500;
		char buf[bufsize];
		ifstream iv_file;
		int pCount;
		float x,y,z;
		char ch[10];
		float a,b,c;
		BOOL carryOn;

		iv_file.open(openDlg.m_ofn.lpstrFile, ios::nocreate|ios::in);
		if (!iv_file.good()) {	TargetShapeLoaded = FALSE;}

		// HEAD
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			target_head[pCount][0] = x;
			target_head[pCount][1] = y;
			target_head[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> target_head_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> target_head_cols;

		//TORSO
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			target_torso[pCount][0] = x;
			target_torso[pCount][1] = y;
			target_torso[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> target_torso_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> target_torso_cols;
		
		// RLEG
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			target_rleg[pCount][0] = x;
			target_rleg[pCount][1] = y;
			target_rleg[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> target_rleg_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> target_rleg_cols;

		//LLEG
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			target_lleg[pCount][0] = x;
			target_lleg[pCount][1] = y;
			target_lleg[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> target_lleg_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> target_lleg_cols;
/*		
		// Rarm
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			target_rarm[pCount][0] = x;
			target_rarm[pCount][1] = y;
			target_rarm[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> target_rarm_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> target_rarm_cols;

		//Larm
		iv_file.getline(buf,bufsize,'[');
		carryOn = TRUE;
		for(pCount = 0; carryOn; pCount++)
		{
			iv_file >> x;			
			iv_file >> y;			
			iv_file >> z;
			target_larm[pCount][0] = x;
			target_larm[pCount][1] = y;
			target_larm[pCount][2] = z;
			iv_file.getline(ch,10,'\n');
			if(ch[0]!=',') {carryOn = FALSE;}
		}
		iv_file.getline(buf,bufsize,'n');
		iv_file >> target_larm_rows;
		iv_file.getline(buf,bufsize,'w');
		iv_file >> target_larm_cols;
*/
		iv_file.close();
		render(TARGET);

		HCURSOR arrowCursor= theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);
	}
}

void CBodyWarperDoc::OnFileLoadtargetlandmarks() 
{

		const char szFilter[] =
	"Text Landmark Files (*_lmk.txt)\0*_lmk.txt\0Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0All Files (*.*)\0*.*\0";

	const char szTitle[] = "Open target Landmarks File";

	CFileDialog openDlg(TRUE);

	openDlg.m_ofn.lpstrTitle = szTitle;
	openDlg.m_ofn.lpstrFilter = szFilter ;
	openDlg.m_ofn.nFilterIndex = theApp.m_nLastOpenedFilterIX;
	openDlg.m_ofn.lpstrCustomFilter = NULL;
	openDlg.m_ofn.lpstrDefExt = def_ext[theApp.m_nLastOpenedFilterIX];
	openDlg.m_ofn.nMaxCustFilter = 0;

	openDlg.m_ofn.Flags |= (OFN_HIDEREADONLY | OFN_PATHMUSTEXIST) ;

	TargetLandmarksLoaded = TRUE;
	ShowTargetLandmarks = TRUE;
	if (openDlg.DoModal() == IDOK)
	{
		HCURSOR waitCursor= theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		const unsigned int bufsize = 50;
		char buf[bufsize];
		CString label;
		char curr_label[bufsize];
		ifstream iv_file;
		int pCount,i;
		float x,y,z;
		char ch[10];
		float a,b,c;
		BOOL carryOn, usefulLandmark;
		unsigned int loc;

		iv_file.open(openDlg.m_ofn.lpstrFile, ios::nocreate|ios::in);
		if (!iv_file.good()) {	TargetLandmarksLoaded = FALSE;	ShowTargetLandmarks = FALSE;}

		i = 0;
		carryOn = TRUE;
		for(pCount = 0; carryOn; )
		{
			iv_file.getline(buf,bufsize,' ');
			iv_file.getline(curr_label,bufsize,'\n');
			label = curr_label;
			
			iv_file.getline(buf,bufsize,':');
			iv_file >> x;		//height	

			iv_file.getline(buf,bufsize,':');
			iv_file >> y;		//width

			iv_file.getline(buf,bufsize,':');
			iv_file >> z;		//depth

			iv_file.getline(buf,bufsize,':');

			usefulLandmark = FALSE;

			if(label == "top_of_head")						{usefulLandmark = TRUE;		loc = TOP_OF_HEAD;}
			if(label == "centre_back_bust")					{usefulLandmark = TRUE;		loc = CENTRE_BACK_BUST;}
			if(label == "centre_front_bust")				{usefulLandmark = TRUE;		loc = CENTRE_FRONT_BUST;}
			if(label == "left_shoulder_point")				{usefulLandmark = TRUE;		loc = LEFT_SHOULDER_POINT;}
			if(label == "right_shoulder_point")				{usefulLandmark = TRUE;		loc = RIGHT_SHOULDER_POINT;}
			if(label == "greatest_posterior_prominence")	{usefulLandmark = TRUE;		loc = GREATEST_POSTERIOR_PROMINENCE;}
			if(label == "crotch_point")						{usefulLandmark = TRUE;		loc = CROTCH_POINT;}
			if(label == "left_hip_point")					{usefulLandmark = TRUE;		loc = LEFT_HIP_POINT;}
			if(label == "right_hip_point")					{usefulLandmark = TRUE;		loc = RIGHT_HIP_POINT;}
			if(label == "right_outer_ankle")				{usefulLandmark = TRUE;		loc = RIGHT_OUTER_ANKLE;}
			if(label == "left_outer_ankle")					{usefulLandmark = TRUE;		loc = LEFT_OUTER_ANKLE;}
			if(label == "left_side_waist")					{usefulLandmark = TRUE;		loc = LEFT_SIDE_WAIST;}
			if(label == "right_side_waist")					{usefulLandmark = TRUE;		loc = RIGHT_SIDE_WAIST;}
			if(label == "centre_back_waist")				{usefulLandmark = TRUE;		loc = CENTRE_BACK_WAIST;}
			if(label == "centre_front_waist")				{usefulLandmark = TRUE;		loc = CENTRE_FRONT_WAIST;}
			if(label == "left_inner_knee")					{usefulLandmark = TRUE;		loc = LEFT_INNER_KNEE;}
			if(label == "right_inner_knee")					{usefulLandmark = TRUE;		loc = RIGHT_INNER_KNEE;}
			if(label == "greatest_abdominal_prominence")	{usefulLandmark = TRUE;		loc = GREATEST_ABDOMINAL_PROMINENCE;}

			if(usefulLandmark)
			{
				target_landmark_label[loc] = label;
				target_landmark[loc][0] = z;
				target_landmark[loc][1] = x;
				target_landmark[loc][2] = y;
				
				pCount++;
			}
			i++;
			iv_file.getline(ch,10,'\n');
			if((pCount==N_LANDMARKS)||(i>37)) {carryOn = FALSE;}
		}
		target_landmark_label[FRONT_KNEE_PROJECTION] = "front_knee_projection";
		target_landmark[FRONT_KNEE_PROJECTION][0] = target_landmark[GREATEST_ABDOMINAL_PROMINENCE][0];	//depth
		target_landmark[FRONT_KNEE_PROJECTION][1] = 0.5*(target_landmark[LEFT_INNER_KNEE][1]+target_landmark[LEFT_INNER_KNEE][1]);	//height
		target_landmark[FRONT_KNEE_PROJECTION][2] = target_landmark[GREATEST_ABDOMINAL_PROMINENCE][2];	//width
		
		target_landmark_label[BACK_KNEE_PROJECTION] = "back_knee_projection";
		target_landmark[BACK_KNEE_PROJECTION][0] = target_landmark[GREATEST_POSTERIOR_PROMINENCE][0];	//depth
		target_landmark[BACK_KNEE_PROJECTION][1] = 0.5*(target_landmark[LEFT_INNER_KNEE][1]+target_landmark[LEFT_INNER_KNEE][1]);	//height
		target_landmark[BACK_KNEE_PROJECTION][2] = target_landmark[GREATEST_POSTERIOR_PROMINENCE][2];	//width

		target_landmark_label[ORIGIN] = "origin";
		target_landmark[ORIGIN][0] = 0.0;
		target_landmark[ORIGIN][1] = 0.0; 
		target_landmark[ORIGIN][2] = 0.0; 

		iv_file.close();
		n_target_landmarks = pCount;


		HCURSOR arrowCursor= theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);
		
		if(n_target_landmarks+3 < N_LANDMARKS)
		{
			TargetLandmarksLoaded = FALSE;
			ShowTargetLandmarks = FALSE;
			CInsufficientLandmarksDlg ilD;
			ilD.DoModal();
		}
		else
		{
			render(TARGET_L);
		}

	}
}


void CBodyWarperDoc::OnUpdateViewSourceshapeSolid(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceShapeLoaded);	
}

void CBodyWarperDoc::OnUpdateViewSourceshapeWireframe(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceShapeLoaded);	
}

void CBodyWarperDoc::OnUpdateViewSourceshapePoints(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceShapeLoaded);	
}

void CBodyWarperDoc::OnUpdateViewSourceshapeHide(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceShapeLoaded);	
}


void CBodyWarperDoc::OnUpdateViewTargetshapeSolid(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TargetShapeLoaded);	
}

void CBodyWarperDoc::OnUpdateViewTargetshapeWireframe(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TargetShapeLoaded);	
}

void CBodyWarperDoc::OnUpdateViewTargetshapePoints(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TargetShapeLoaded);	
}

void CBodyWarperDoc::OnUpdateViewTargetshapeHide(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TargetShapeLoaded);	
}



void CBodyWarperDoc::OnUpdateViewSourcelandmarks(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceLandmarksLoaded);	
	if (SourceLandmarksLoaded) 
	{
		pCmdUI->SetCheck(ShowSourceLandmarks);	
	}
}

void CBodyWarperDoc::OnUpdateViewTargetlandmarks(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TargetLandmarksLoaded);	
	if (TargetLandmarksLoaded) 
	{
		pCmdUI->SetCheck(ShowTargetLandmarks);	
	}

}

void CBodyWarperDoc::OnFileCalculatetransformation() 
{
	HCURSOR waitCursor= theApp.LoadStandardCursor(IDC_WAIT);
	SetCursor(waitCursor);

	warped_head_rows=source_head_rows;			warped_head_cols=source_head_cols;
	warped_torso_rows=source_torso_rows;		warped_torso_cols=source_torso_cols;
	warped_rleg_rows=source_rleg_rows;			warped_rleg_cols=source_rleg_cols;
	warped_lleg_rows=source_lleg_rows;			warped_lleg_cols=source_lleg_cols;
	//warped_rarm_rows=source_rarm_rows;		warped_rarm_cols=source_rarm_cols;
	//warped_larm_rows=source_larm_rows;		warped_larm_cols=source_larm_cols;

	Main_CopyAndClassify(&source_head,	&warped_head,	&flags_head,	&d,	&c_head,	warped_head_rows,warped_head_cols);
	Main_CopyAndClassify(&source_torso,	&warped_torso,	&flags_torso,	&d,	&c_torso,	warped_torso_rows,warped_torso_cols);
	Main_CopyAndClassify(&source_rleg,	&warped_rleg,	&flags_rleg,	&d,	&c_rleg,	warped_rleg_rows,warped_rleg_cols);
	Main_CopyAndClassify(&source_lleg,	&warped_lleg,	&flags_lleg,	&d,	&c_lleg,	warped_lleg_rows,warped_lleg_cols);
	//Main_CopyAndClassify(&source_rarm,&warped_rarm,	&flags_rarm,	&d,	&c_rarm,	warped_rarm_rows,warped_rarm_cols);
	//Main_CopyAndClassify(&source_larm,&warped_larm,	&flags_larm,	&d,	&c_larm,	warped_larm_rows,warped_larm_cols);

	Main_ConstructTransformations();

	
	Main_Warp(&warped_head,		&c_head,	&flags_head,	warped_head_rows,warped_head_cols);
	Main_Warp(&warped_torso,	&c_torso,	&flags_torso,	warped_torso_rows,warped_torso_cols);
	Main_Warp(&warped_rleg,		&c_rleg,	&flags_rleg,	warped_rleg_rows,warped_rleg_cols);
	Main_Warp(&warped_lleg,		&c_lleg,	&flags_lleg,	warped_lleg_rows,warped_lleg_cols);
	//Main_Warp(&warped_rarm,	&c_rarm,	&flags_rarm,	warped_rarm_rows,warped_rarm_cols);
	//Main_Warp(&warped_larm,	&c_larm,	&flags_larm,	warped_larm_rows,warped_larm_cols);
	
	
	WarpingComplete = TRUE;

	HCURSOR arrowCursor= theApp.LoadStandardCursor(IDC_ARROW);
	SetCursor(arrowCursor);

	render(WARPED);
}

void CBodyWarperDoc::OnFileLoadtransformation() 
{
	// TODO: Add your command handler code here

	

	SourceLandmarksLoaded = TRUE;
	TargetShapeLoaded = TRUE;
	TargetLandmarksLoaded = TRUE;
	WarpingComplete = TRUE;
}

void CBodyWarperDoc::OnUpdateFileSavetransformation(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(WarpingComplete);	
}

void CBodyWarperDoc::OnUpdateViewWarpedshapeSolid(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(WarpingComplete);	
}

void CBodyWarperDoc::OnUpdateViewWarpedshapeWireframe(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(WarpingComplete);	
}

void CBodyWarperDoc::OnUpdateViewWarpedshapePoints(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(WarpingComplete);	
}

void CBodyWarperDoc::OnUpdateViewWarpedshapeHide(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(WarpingComplete);	
}

void CBodyWarperDoc::OnUpdateFileCalculatetransformation(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceShapeLoaded && SourceLandmarksLoaded && TargetShapeLoaded && TargetLandmarksLoaded);	
}

void CBodyWarperDoc::OnUpdateFileLoadtransformation(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(SourceShapeLoaded);	
}

void CBodyWarperDoc::render(const int part)
{
	SoSeparator* s_source_shape = new SoSeparator;
	SoSeparator* s_target_shape = new SoSeparator;
	SoSeparator* s_warped_shape = new SoSeparator;

	SoSeparator* s_source_landmarks = new SoSeparator;
	SoSeparator* s_target_landmarks = new SoSeparator;

	switch(part)
	{
	case SOURCE :	
			source_shape_color->diffuseColor.setValue( 0, 0, 1 ); 
			source_shape_style->style.setValue(SoDrawStyle::INVISIBLE);
			s_source_shape->addChild(source_shape_color);
			s_source_shape->addChild(source_shape_style);
			s_source_shape->addChild(renderSegment(&source_head,	NULL,		source_head_rows,	source_head_cols,	SOURCE));
			s_source_shape->addChild(renderSegment(&source_torso,	NULL,		source_torso_rows,	source_torso_cols,	SOURCE));
			s_source_shape->addChild(renderSegment(&source_rleg,	NULL,		source_rleg_rows,	source_rleg_cols,	SOURCE));
			s_source_shape->addChild(renderSegment(&source_lleg,	NULL,		source_lleg_rows,	source_lleg_cols,	SOURCE));
			//s_source_shape->addChild(renderSegment(&source_rarm,	NULL,		source_rarm_rows,	source_rarm_cols,	SOURCE));
			//s_source_shape->addChild(renderSegment(&source_larm,	NULL,		source_larm_rows,	source_larm_cols,	SOURCE));
			root->addChild(s_source_shape);
			break;
	case TARGET :
			target_shape_color->diffuseColor.setValue( 0, 1, 0 ); 
			target_shape_style->style.setValue(SoDrawStyle::INVISIBLE);
			s_target_shape->addChild(target_shape_color);
			s_target_shape->addChild(target_shape_style);
			s_target_shape->addChild(renderSegment(&target_head,	NULL,		target_head_rows,	target_head_cols,	TARGET));
			s_target_shape->addChild(renderSegment(&target_torso,	NULL,		target_torso_rows,	target_torso_cols,	TARGET));
			s_target_shape->addChild(renderSegment(&target_rleg,	NULL,		target_rleg_rows,	target_rleg_cols,	TARGET));
			s_target_shape->addChild(renderSegment(&target_lleg,	NULL,		target_lleg_rows,	target_lleg_cols,	TARGET));
			//s_target_shape->addChild(renderSegment(&target_rarm,	NULL,		target_rarm_rows,	target_rarm_cols,	TARGET));
			//s_target_shape->addChild(renderSegment(&target_larm,	NULL,		target_larm_rows,	target_larm_cols,	TARGET));
			root->addChild(s_target_shape);
			break;
	case WARPED : 
			warped_shape_color->diffuseColor.setValue( 1, 0, 0 ); 
			warped_shape_style->style.setValue(SoDrawStyle::FILLED);
			//warped_shape_style->pointSize = 3;
			s_warped_shape->addChild(warped_shape_color);
			s_warped_shape->addChild(warped_shape_style);
			s_warped_shape->addChild(renderSegment(&warped_head,	&c_head,	warped_head_rows,	warped_head_cols,	WARPED));
			s_warped_shape->addChild(renderSegment(&warped_torso,	&c_torso,	warped_torso_rows,	warped_torso_cols,	WARPED));
			s_warped_shape->addChild(renderSegment(&warped_rleg,	&c_rleg,	warped_rleg_rows,	warped_rleg_cols,	WARPED));
			s_warped_shape->addChild(renderSegment(&warped_lleg,	&c_lleg,	warped_lleg_rows,	warped_lleg_cols,	WARPED));
			//s_warped_shape->addChild(renderSegment(&warped_rarm,	&c_rarm,	warped_rarm_rows,	warped_rarm_cols,	WARPED));
			//s_warped_shape->addChild(renderSegment(&warped_larm,	&c_larm,	warped_larm_rows,	warped_larm_cols,	WARPED));
			root->addChild(s_warped_shape);
			break;
	case SOURCE_L :
			source_landmarks_color->diffuseColor.setValue( 0.5, 0.5, 1 ); 
			source_landmarks_style->style.setValue(SoDrawStyle::FILLED);
			s_source_landmarks->addChild(source_landmarks_color);
			s_source_landmarks->addChild(source_landmarks_style);
			s_source_landmarks->addChild(renderLandmarkSet(SOURCE_L));
			root->addChild(s_source_landmarks);
			break;
	case TARGET_L :
			target_landmarks_color->diffuseColor.setValue( 0.5, 1, 0.5 ); 
			target_landmarks_style->style.setValue(SoDrawStyle::FILLED);
			s_target_landmarks->addChild(target_landmarks_color);
			s_target_landmarks->addChild(target_landmarks_style);
			s_target_landmarks->addChild(renderLandmarkSet(TARGET_L));
			root->addChild(s_target_landmarks);
			break;
	default:
			break;
	}

}

SoSeparator* CBodyWarperDoc::renderSegment(float (* s)[MAX_N_SLICES*MAX_N_COLS][3], 
										   float (* c)[MAX_N_SLICES*MAX_N_COLS][3],
										   int ro, int co, const int part)
{
		SoSeparator* S = new SoSeparator;
		
		int i,j;


		SoSeparator* cpolySep = new SoSeparator;
		S->addChild(cpolySep);

		SoMaterial* mat = new SoMaterial;
		SoMaterialBinding* bind = new SoMaterialBinding;
		bind->value.setValue(SoMaterialBinding::PER_VERTEX);

		if(part==WARPED) 
		{
			cpolySep->addChild(mat);
			cpolySep->addChild(bind);
		}

		SoCoordinate3* vertices = new SoCoordinate3;
		for(i = 0; i < ro*co; i++)
		{
				vertices->point.set1Value(i,(*s)[i][0],(*s)[i][1],(*s)[i][2]);
				if(part==WARPED) {mat->diffuseColor.set1Value(i, (*c)[i][0],(*c)[i][1],(*c)[i][2]);}
		}


		SoQuadMesh* cLines = new SoQuadMesh;
		cLines->verticesPerColumn = ro;
		cLines->verticesPerRow = co;
		cpolySep->addChild(vertices);


		cpolySep->addChild(cLines);

		return S;	
}

void CBodyWarperDoc::OnViewSourceshapeSolid() 
{
	source_shape_style->style.setValue(SoDrawStyle::FILLED);
}

void CBodyWarperDoc::OnViewSourceshapeWireframe() 
{
	source_shape_style->style.setValue(SoDrawStyle::LINES);
}

void CBodyWarperDoc::OnViewSourceshapePoints() 
{
	source_shape_style->style.setValue(SoDrawStyle::POINTS);
}

void CBodyWarperDoc::OnViewSourceshapeHide() 
{
	source_shape_style->style.setValue(SoDrawStyle::INVISIBLE);
}

void CBodyWarperDoc::OnViewTargetshapeSolid() 
{
	target_shape_style->style.setValue(SoDrawStyle::FILLED);
}

void CBodyWarperDoc::OnViewTargetshapeWireframe() 
{
	target_shape_style->style.setValue(SoDrawStyle::LINES);
}

void CBodyWarperDoc::OnViewTargetshapePoints() 
{
	target_shape_style->style.setValue(SoDrawStyle::POINTS);
}

void CBodyWarperDoc::OnViewTargetshapeHide() 
{
	target_shape_style->style.setValue(SoDrawStyle::INVISIBLE);
}

SoSeparator* CBodyWarperDoc::renderLandmarkSet(const int part)
{
	SoSeparator* S = new SoSeparator;
	int i;

	SoSeparator* sph_sep;
	SoTranslation* sph_transl[N_LANDMARKS];
	SoSphere* sph;

	switch(part)
	{
	case SOURCE_L:
		for(i = 0; i < n_source_landmarks; i++)
		{
			sph_sep = new SoSeparator;

			sph = new SoSphere;
			sph->radius = 100;

			sph_transl[i] = new SoTranslation;
			sph_transl[i]->translation.setValue(source_landmark[i][0],source_landmark[i][1],source_landmark[i][2]);

			S->addChild(sph_sep);
			sph_sep->addChild(sph_transl[i]);
			sph_sep->addChild(sph);
		}
		break;
	case TARGET_L:
		for(i = 0; i < n_target_landmarks; i++)
		{
			sph_sep = new SoSeparator;

			sph = new SoSphere;
			sph->radius = 100;

			sph_transl[i] = new SoTranslation;
			sph_transl[i]->translation.setValue(target_landmark[i][0],target_landmark[i][1],target_landmark[i][2]);

			S->addChild(sph_sep);
			sph_sep->addChild(sph_transl[i]);
			sph_sep->addChild(sph);
		}
		break;
	default:
		break;
	}


	return S;
}

void CBodyWarperDoc::OnViewSourcelandmarks() 
{
	ShowSourceLandmarks = (!ShowSourceLandmarks);
	if(ShowSourceLandmarks)
	{
		source_landmarks_style->style.setValue(SoDrawStyle::FILLED);
	}
	else
	{
		source_landmarks_style->style.setValue(SoDrawStyle::INVISIBLE);
	}
}

void CBodyWarperDoc::OnViewTargetlandmarks() 
{
	ShowTargetLandmarks = (!ShowTargetLandmarks);
	if(ShowTargetLandmarks)
	{
		target_landmarks_style->style.setValue(SoDrawStyle::FILLED);
	}
	else
	{
		target_landmarks_style->style.setValue(SoDrawStyle::INVISIBLE);
	}
}

void CBodyWarperDoc::Main_CopyAndClassify(	float (* s)[MAX_N_SLICES*MAX_N_COLS][3], 
											float (* w)[MAX_N_SLICES*MAX_N_COLS][3], 
											int (* f)[MAX_N_SLICES*MAX_N_COLS],
											BOOL (* d)[MAX_N_SLICES*MAX_N_COLS],
											float (* c)[MAX_N_SLICES*MAX_N_COLS][3],
											int ro, int co)
{
	int i,j,k;
	float x1,y1,z1, x2,y2,z2, x3,y3,z3, x, y, z;
	int n_discr_planes, curr_case, curr_plane, curr_plane_index, num_planes;
	float sign[4];

	for(i = 0; i < ro*co; i++)
	{
		(*d)[i] = FALSE;

		x = (*s)[i][0];
		y = (*s)[i][1];
		z = (*s)[i][2];

		(*w)[i][0] = x;
		(*w)[i][1] = y;
		(*w)[i][2] = z;

		(*f)[i] = -1;

		curr_case = 0;
		curr_plane_index = 0;

		//test volume 0 --- planes 0 1

		for(curr_case = 0; curr_case < N_TETRAHEDRA; curr_case++)
		{
			num_planes = planelimit_index[curr_case];
			for(k = 0; k < num_planes; k++)
			{
				curr_plane = subvolume_index[curr_plane_index];
				Main_GetLandmarkCoords(curr_plane, x1,y1,z1,x2,y2,z2,x3,y3,z3);
				curr_plane_index++;
				sign[k] = Det3(x-x1,y-y1,z-z1, x2-x1,y2-y1,z2-z1, x3-x1,y3-y1,z3-z1);
			}

			switch(curr_case)	// mutually exclusive!!!!
			{
			case 0:
				if( (sign[0]<0) && (sign[1]>=0) && (!(*d)[i]) )								
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=1.0; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //light red
				break;
			case 1:
				if( (sign[0]>=0) && (sign[1]<0) && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.8; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //dark red 
				break;
			case 2:
				if( (sign[0]>=0) && (sign[1]<0) && (!(*d)[i]))	
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.9; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //MID red
				break;
			case 3:
				if( (sign[0]<0) && (sign[1]>=0)  && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.9; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //mid red
				break;
			case 4:
				if( (sign[0]>=0) && (sign[1]<0)  && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=1.0; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //light red
				break;
			case 5:
				if( (sign[0]<0) && (sign[1]>=0)  && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=1.0; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //light red
				break;
			case 6:
				if( (sign[0]>=0) && (sign[1]<0)  && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.9; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //mid red
				break;
			case 7:
				if( (sign[0]<0) && (sign[1]>=0)  && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.9; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //mid red
				break;
			case 8:
				if( (sign[0]>=0) && (sign[1]<0) &&  (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=1.0; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //light red
				break;
			case 9:
				if( (sign[0]<0) && (sign[1]>=0)  && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=1.0; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //light red
				break;
			case 10:
				if( (sign[0]>=0) && (sign[1]<0) && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.8; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //dark red
				break;
			case 11:
				if( (sign[0]<0) && (sign[1]>=0) && (!(*d)[i])) 
					{(*f)[i]=curr_case; (*d)[i]=TRUE; (*c)[i][0]=0.9; (*c)[i][1]=0.0; (*c)[i][2]=0.0;} //mid red
				break;
			default:
				break;
			}
			curr_plane_index++;
		}
		
		if ((*f)[i] == -1) //failed to classify
		{
			//assign a segment label using neighbour voting
			int prev = i-1;		if(prev<0)				{prev = 0;}

			if((*f)[prev] != -1) {(*f)[i] = (*f)[prev];}

			if( ((*f)[i]==0) || ((*f)[i]==5) || ((*f)[i]==8) || ((*f)[i]==11) ) 
				{(*c)[i][0]=1.0; (*c)[i][1]=0.0; (*c)[i][2]=0.0;}	//light red
			if( ((*f)[i]==3) || ((*f)[i]==4) || ((*f)[i]==6) || ((*f)[i]==9) )
				{(*c)[i][0]=0.9; (*c)[i][1]=0.0; (*c)[i][2]=0.0;}	//medium red
			if( ((*f)[i]==1) || ((*f)[i]==2) || ((*f)[i]==7) || ((*f)[i]==10) )
				{(*c)[i][0]=0.8; (*c)[i][1]=0.0; (*c)[i][2]=0.0;}	//dark red
		}

		if ((*f)[i] == -1) // still failed to classify
		{
			(*c)[i][0]=1.0; (*c)[i][1]=1.0; (*c)[i][2]=0.0;
		}


		ASSERT( (*f)[i] != -1); //bummer!
	}

}



void CBodyWarperDoc::Main_ConstructTransformations()
{
	float ix0, iy0, iz0;	
	float ix1, iy1, iz1;	
	float ix2, iy2, iz2;	
	float ix3, iy3, iz3;	

	float fx0, fy0, fz0;	
	float fx1, fy1, fz1;	
	float fx2, fy2, fz2;	
	float fx3, fy3, fz3;	

	int point_index_0;
	int point_index_1;
	int point_index_2;
	int point_index_3;

	for(int current_tetrahedron = 0; current_tetrahedron < N_TETRAHEDRA; current_tetrahedron++)
	{
		//retrieve ix iy iz fx fy fz
		point_index_0 = landmark_index[(current_tetrahedron*4)];
		point_index_1 = landmark_index[(current_tetrahedron*4)+1];
		point_index_2 = landmark_index[(current_tetrahedron*4)+2];
		point_index_3 = landmark_index[(current_tetrahedron*4)+3];


		ix0 = source_landmark[point_index_0][0];	fx0 = target_landmark[point_index_0][0];
		iy0 = source_landmark[point_index_0][1];	fy0 = target_landmark[point_index_0][1];
		iz0 = source_landmark[point_index_0][2];	fz0 = target_landmark[point_index_0][2];
	
		ix1 = source_landmark[point_index_1][0];	fx1 = target_landmark[point_index_1][0];
		iy1 = source_landmark[point_index_1][1];	fy1 = target_landmark[point_index_1][1];
		iz1 = source_landmark[point_index_1][2];	fz1 = target_landmark[point_index_1][2];

		ix2 = source_landmark[point_index_2][0];	fx2 = target_landmark[point_index_2][0];
		iy2 = source_landmark[point_index_2][1];	fy2 = target_landmark[point_index_2][1];
		iz2 = source_landmark[point_index_2][2];	fz2 = target_landmark[point_index_2][2];

		ix3 = source_landmark[point_index_3][0];	fx3 = target_landmark[point_index_3][0];
		iy3 = source_landmark[point_index_3][1];	fy3 = target_landmark[point_index_3][1];
		iz3 = source_landmark[point_index_3][2];	fz3 = target_landmark[point_index_3][2];

		//matrix variables
		CFloatMatrix a = CFloatMatrix(4,5);
		CFloatMatrix r;

		a.set(0,0,ix0);		a.set(0,1,iy0);		a.set(0,2,iz0);		a.set(0,3,1.0);
		a.set(1,0,ix1);		a.set(1,1,iy1);		a.set(1,2,iz1);		a.set(1,3,1.0);
		a.set(2,0,ix2);		a.set(2,1,iy2);		a.set(2,2,iz2);		a.set(2,3,1.0);
		a.set(3,0,ix3);		a.set(3,1,iy3);		a.set(3,2,iz3);		a.set(3,3,1.0);

	//SYSTEM 0
		//building the augmented matrix
		a.set(0,4,fx0);
		a.set(1,4,fx1);
		a.set(2,4,fx2);
		a.set(3,4,fx3);
		//solving system 
		BOOL ge_failed = FALSE;
		r = GaussElimination(a, ge_failed);
		//returning solution
		local_affine_transform[current_tetrahedron][0][0] = r.get(0,0);
		local_affine_transform[current_tetrahedron][0][1] = r.get(1,0);
		local_affine_transform[current_tetrahedron][0][2] = r.get(2,0);
		local_affine_transform[current_tetrahedron][0][3] = r.get(3,0);
		
	//SYSTEM 1
		//building the augmented matrix
		a.set(0,4,fy0);
		a.set(1,4,fy1);
		a.set(2,4,fy2);
		a.set(3,4,fy3);
		//solving system 
		r = GaussElimination(a, ge_failed);
		//returning solution
		local_affine_transform[current_tetrahedron][1][0] = r.get(0,0);
		local_affine_transform[current_tetrahedron][1][1] = r.get(1,0);
		local_affine_transform[current_tetrahedron][1][2] = r.get(2,0);
		local_affine_transform[current_tetrahedron][1][3] = r.get(3,0);
		
	//SYSTEM 2
		//building the augmented matrix
		a.set(0,4,fz0);
		a.set(1,4,fz1);
		a.set(2,4,fz2);
		a.set(3,4,fz3);
		//solving system 
		r = GaussElimination(a, ge_failed);
		//returning solution
		local_affine_transform[current_tetrahedron][2][0] = r.get(0,0);
		local_affine_transform[current_tetrahedron][2][1] = r.get(1,0);
		local_affine_transform[current_tetrahedron][2][2] = r.get(2,0);
		local_affine_transform[current_tetrahedron][2][3] = r.get(3,0);
		
	//SYSTEM 3
		//building the augmented matrix
		a.set(0,4,1.0);
		a.set(1,4,1.0);
		a.set(2,4,1.0);
		a.set(3,4,1.0);
		//solving system 
		r = GaussElimination(a, ge_failed);
		//returning solution
		local_affine_transform[current_tetrahedron][3][0] = r.get(0,0);
		local_affine_transform[current_tetrahedron][3][1] = r.get(1,0);
		local_affine_transform[current_tetrahedron][3][2] = r.get(2,0);
		local_affine_transform[current_tetrahedron][3][3] = r.get(3,0);

	}

}

void CBodyWarperDoc::Main_Warp(		float (* w)[MAX_N_SLICES*MAX_N_COLS][3],
									float (* c)[MAX_N_SLICES*MAX_N_COLS][3], //debug
									int (* f)[MAX_N_SLICES*MAX_N_COLS],
									int ro, int co)
{
	int t;
	float ix,iy,iz, fx,fy,fz;
	for(int i = 0; i < ro*co; i++)
	{
		t = (*f)[i];

		if(6==6)
		{//debug purposes only

		ix = (*w)[i][0];
		iy = (*w)[i][1];
		iz = (*w)[i][2];

		fx =	ix*local_affine_transform[t][0][0] + 
				iy*local_affine_transform[t][0][1] + 
				iz*local_affine_transform[t][0][2] + 
				   local_affine_transform[t][0][3];
		
		fy =	ix*local_affine_transform[t][1][0] + 
				iy*local_affine_transform[t][1][1] + 
				iz*local_affine_transform[t][1][2] + 
				   local_affine_transform[t][1][3];
		
		fz =	ix*local_affine_transform[t][2][0] + 
				iy*local_affine_transform[t][2][1] + 
				iz*local_affine_transform[t][2][2] + 
				   local_affine_transform[t][2][3];
		
		float corr;
		corr =	ix*local_affine_transform[t][3][0] + 
				iy*local_affine_transform[t][3][1] + 
				iz*local_affine_transform[t][3][2] + 
				   local_affine_transform[t][3][3];


		(*w)[i][0] = fx;
		(*w)[i][1] = fy;
		(*w)[i][2] = fz;

		}//debug if
		else
		{
			(*c)[i][0] = (*c)[i][1] = (*c)[i][2] = 0.3;
		}//debug else

	}
}

void CBodyWarperDoc::OnViewWarpedshapeSolid() 
{
	warped_shape_style->style.setValue(SoDrawStyle::FILLED);
}

void CBodyWarperDoc::OnViewWarpedshapeWireframe() 
{
	warped_shape_style->style.setValue(SoDrawStyle::LINES);
}

void CBodyWarperDoc::OnViewWarpedshapePoints() 
{
	warped_shape_style->style.setValue(SoDrawStyle::POINTS);
}

void CBodyWarperDoc::OnViewWarpedshapeHide() 
{
	warped_shape_style->style.setValue(SoDrawStyle::INVISIBLE);
}

void CBodyWarperDoc::Main_GetLandmarkCoords(int c_plane, 
											float &x1, float &y1, float &z1, 
											float &x2, float &y2, float &z2, 
											float &x3, float &y3, float &z3)
{
			x1 = source_landmark[plane_index[c_plane*3]][0];
			y1 = source_landmark[plane_index[c_plane*3]][1];
			z1 = source_landmark[plane_index[c_plane*3]][2];
	
			x2 = source_landmark[plane_index[c_plane*3+1]][0];			
			y2 = source_landmark[plane_index[c_plane*3+1]][1];			
			z2 = source_landmark[plane_index[c_plane*3+1]][2];

			x3 = source_landmark[plane_index[c_plane*3+2]][0];			
			y3 = source_landmark[plane_index[c_plane*3+2]][1];			
			z3 = source_landmark[plane_index[c_plane*3+2]][2];
}
