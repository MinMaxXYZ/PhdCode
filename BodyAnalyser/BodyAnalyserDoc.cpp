// BodyAnalyserDoc.cpp : implementation of the CBodyAnalyserDoc class
//

#include "stdafx.h"
#include "BodyAnalyser.h"

#include "BodyAnalyserDoc.h"
#include "BodyAnalyserView.h"
#include "DialogCameraImager.h"
#include "CameraImageFrame.h"
#include "ConfirmDialog.h"
#include "NoCurvMapDialog.h"
#include "CurvMapConfirmDialog.h"
#include "CannyParamsDialog.h"
#include "DlgCurvatureProgress.h"
#include "DlgHistogram.h"
#include "DlgCurvThresholds.h"
#include "DlgEvaluation.h"
#include "DlgEvaluationReport.h"
#include "DlgWrapMesh.h"

#include <fstream.h>
#include <string.h>

#include <Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoPointSet.h>
#include <Inventor/nodes/SoLineSet.h>
#include <Inventor/nodes/SoFaceSet.h>
#include <Inventor/nodes/SoIndexedFaceSet.h>
#include <Inventor/nodes/SoNormal.h>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoSphere.h>

#include <MathTools.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// for the curvature estimation

#define UNDEFINED	0
#define BOTH1		1
#define BOTH2		2
#define FLAT		3
#define TOUGH		4
#define BOTH		5



/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserDoc

IMPLEMENT_DYNCREATE(CBodyAnalyserDoc, CDocument)

BEGIN_MESSAGE_MAP(CBodyAnalyserDoc, CDocument)
	//{{AFX_MSG_MAP(CBodyAnalyserDoc)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_UPDATE_COMMAND_UI(ID_FILE_IMPORT, OnUpdateFileImport)
	ON_UPDATE_COMMAND_UI(IDM_VIEWPOINTS, OnUpdateViewpoints)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_RELOAD, OnFileReload)
	ON_UPDATE_COMMAND_UI(ID_FILE_RELOAD, OnUpdateFileReload)
	ON_COMMAND(ID_VIEW_POINTCLOUD, OnViewPointcloud)
	ON_UPDATE_COMMAND_UI(ID_VIEW_POINTCLOUD, OnUpdateViewPointcloud)
	ON_COMMAND(ID_VIEW_REFERENCEFRAME, OnViewReferenceframe)
	ON_UPDATE_COMMAND_UI(ID_VIEW_REFERENCEFRAME, OnUpdateViewReferenceframe)
	ON_COMMAND(ID_VIEW_COORDINATEORIGIN, OnViewCoordinateorigin)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COORDINATEORIGIN, OnUpdateViewCoordinateorigin)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA0, OnViewConnectedmeshCamera0)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA0, OnUpdateViewConnectedmeshCamera0)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_NONE, OnViewConnectedmeshNone)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_NONE, OnUpdateViewConnectedmeshNone)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_ALL, OnViewConnectedmeshAll)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_ALL, OnUpdateViewConnectedmeshAll)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA1, OnViewConnectedmeshCamera1)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA1, OnUpdateViewConnectedmeshCamera1)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA2, OnViewConnectedmeshCamera2)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA2, OnUpdateViewConnectedmeshCamera2)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA3, OnViewConnectedmeshCamera3)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA3, OnUpdateViewConnectedmeshCamera3)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA4, OnViewConnectedmeshCamera4)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA4, OnUpdateViewConnectedmeshCamera4)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA5, OnViewConnectedmeshCamera5)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA5, OnUpdateViewConnectedmeshCamera5)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA6, OnViewConnectedmeshCamera6)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA6, OnUpdateViewConnectedmeshCamera6)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_CAMERA7, OnViewConnectedmeshCamera7)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_CAMERA7, OnUpdateViewConnectedmeshCamera7)
	ON_COMMAND(ID_TOOLS_CAMERAIMAGER, OnToolsCameraImager)
	ON_COMMAND(ID_VIEW_OUTLIERCLOUD, OnViewOutliercloud)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OUTLIERCLOUD, OnUpdateViewOutliercloud)
	ON_COMMAND(ID_TOOLS_SURFACESMOOTHING, OnToolsSurfacesmoothing)
	ON_COMMAND(ID_TOOLS_TEXTUREEDGEDETECTOR, OnToolsTextureedgedetector)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_TEXTUREEDGEDETECTOR, OnUpdateToolsTextureedgedetector)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_TEXTUREEDGELS, OnUpdateViewConnectedmeshTextureedgels)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_TEXTUREEDGELS, OnViewConnectedmeshTextureedgels)
	ON_COMMAND(ID_TOOLS_HISTOGRAMEQUALISATION, OnToolsHistogramequalisation)
	ON_COMMAND(ID_TOOLS_CURVATUREMAP_EXPORTCOVARIANCES, OnToolsCurvatureMap)
	ON_COMMAND(ID_VIEW_COLOURMAP_N, OnViewColourmapNone)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOURMAP_N, OnUpdateViewColourmapN)
	ON_COMMAND(ID_VIEW_COLOURMAP_INTENSITIES, OnViewColourmapIntensities)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOURMAP_INTENSITIES, OnUpdateViewColourmapIntensities)
	ON_COMMAND(ID_VIEW_COLOURMAP_GAUSSIANCURVATURE, OnViewColourmapGaussiancurvature)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOURMAP_GAUSSIANCURVATURE, OnUpdateViewColourmapGaussiancurvature)
	ON_COMMAND(ID_VIEW_COLOURMAP_MEANCURVATURE, OnViewColourmapMeancurvature)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOURMAP_MEANCURVATURE, OnUpdateViewColourmapMeancurvature)
	ON_COMMAND(ID_VIEW_COLOURMAP_CURVEDNESS, OnViewColourmapCurvedness)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOURMAP_CURVEDNESS, OnUpdateViewColourmapCurvedness)
	ON_COMMAND(ID_VIEW_COLOURMAP_SHAPEINDEX, OnViewColourmapShapeindex)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOURMAP_SHAPEINDEX, OnUpdateViewColourmapShapeindex)
	ON_COMMAND(ID_VIEW_CONNECTEDMESH_PHOTOREALISTIC, OnViewConnectedmeshPhotorealistic)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CONNECTEDMESH_PHOTOREALISTIC, OnUpdateViewConnectedmeshPhotorealistic)
	ON_COMMAND(ID_VIEW_CURVATUREDIRECTIONS, OnViewCurvaturedirections)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVATUREDIRECTIONS, OnUpdateViewCurvaturedirections)
	ON_COMMAND(ID_VIEW_CURVATUREDIRECTIONS_BLUE, OnViewCurvaturedirectionsBlue)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVATUREDIRECTIONS_BLUE, OnUpdateViewCurvaturedirectionsBlue)
	ON_COMMAND(ID_VIEW_CURVATUREDIRECTIONS_RED, OnViewCurvaturedirectionsRed)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVATUREDIRECTIONS_RED, OnUpdateViewCurvaturedirectionsRed)
	ON_COMMAND(ID_VIEW_CURVATUREDIRECTIONS_ALL, OnViewCurvaturedirectionsAll)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVATUREDIRECTIONS_ALL, OnUpdateViewCurvaturedirectionsAll)
	ON_COMMAND(ID_VIEW_CURVATUREDIRECTIONS_NONE, OnViewCurvaturedirectionsNone)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVATUREDIRECTIONS_NONE, OnUpdateViewCurvaturedirectionsNone)
	ON_COMMAND(ID_VIEW_RIDGES, OnViewRidges)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RIDGES, OnUpdateViewRidges)
	ON_COMMAND(ID_VIEW_FLEXCORDS, OnViewFlexcords)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FLEXCORDS, OnUpdateViewFlexcords)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYMMETRYPLANES_NONE, OnUpdateViewSymmetryplanesNone)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYMMETRYPLANES_BODY, OnUpdateViewSymmetryplanesBody)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYMMETRYPLANES_ELLIPSOID, OnUpdateViewSymmetryplanesEllipsoid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYMMETRYPLANES_TOOTHCUBE, OnUpdateViewSymmetryplanesToothcube)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYMMETRYPLANES_OCTAHEDRONDIAMOND, OnUpdateViewSymmetryplanesOctahedrondiamond)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SYMMETRYPLANES_BUMPYSPHERETETRAHEDRON, OnUpdateViewSymmetryplanesBumpyspheretetrahedron)
	ON_COMMAND(ID_VIEW_SYMMETRYPLANES_BODY, OnViewSymmetryplanesBody)
	ON_COMMAND(ID_VIEW_SYMMETRYPLANES_ELLIPSOID, OnViewSymmetryplanesEllipsoid)
	ON_COMMAND(ID_VIEW_SYMMETRYPLANES_TOOTHCUBE, OnViewSymmetryplanesToothcube)
	ON_COMMAND(ID_VIEW_SYMMETRYPLANES_OCTAHEDRONDIAMOND, OnViewSymmetryplanesOctahedrondiamond)
	ON_COMMAND(ID_VIEW_SYMMETRYPLANES_BUMPYSPHERETETRAHEDRON, OnViewSymmetryplanesBumpyspheretetrahedron)
	ON_COMMAND(ID_VIEW_SYMMETRYPLANES_NONE, OnViewSymmetryplanesNone)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserDoc construction/destruction

CBodyAnalyserDoc::CBodyAnalyserDoc()
{
	// TODO: add one-time construction code here

// BEGIN_IVWGEN
	m_bContainsCamera = FALSE;
	m_eOpenType = IVFDOC_OPEN_NORMAL;
// END_IVWGEN

	unsigned int s,i;

	m_showPointCloud				= FALSE;
	m_showOutlierCloud				= FALSE;
	m_showCoordOrigin				= FALSE; //TRUE
	m_showRefFrame					= FALSE; //TRUE
	m_showTextureEdgels				= FALSE;
	m_showCurvatureDirections		= FALSE;
	m_showCurvatureDirectionsRed	= FALSE;
	m_showCurvatureDirectionsBlue	= FALSE;
	m_showRidges					= FALSE;
	m_showFlexcords					= FALSE;

	m_bHasData = FALSE;
	m_data_source = NONE;

	m_x_correction = X_CORRECTION;
	m_y_correction = Y_CORRECTION;
	m_z_correction = Z_CORRECTION;

	// copy scanner params from the app
	for (i=0; i<MAX_N_CAMERAS; i++)
	{
		m_scanner_params.m_hdx[i] = (theApp.Params()).m_hdx[i];
		m_scanner_params.m_hdy[i] = (theApp.Params()).m_hdy[i];
		m_scanner_params.m_hda[i] = (theApp.Params()).m_hda[i];
		//m_show_head[i] = TRUE;
	}
	m_scanner_params.m_params_file = (theApp.Params()).m_params_file;

	N_CAMERAS	= 8		;
	N_SLICES	= 400	;
	N_LEDS		= 32	;

	N_GSCALES	= 255	;
	N_CHANNELS	= 1		;
	N_COLS		= 180	;


	//needs sorting
	camera_start[0] = 0; 
	camera_start[1] = 32; 
	camera_start[2] = 64; 
	camera_start[3] = 96; 
	camera_start[4] = 128; 
	camera_start[5] = 160; 
	camera_start[6] = 192; 
	camera_start[7] = 224; 
	
	camera_end[0] = 31;
	camera_end[1] = 63;
	camera_end[2] = 95;
	camera_end[3] = 127;
	camera_end[4] = 159;
	camera_end[5] = 191;
	camera_end[6] = 223;
	camera_end[7] = 255;

	m_input_file = "";

	for (s=0; s<N_SLICES; s++)
	{
		m_xyz_array[s] = new SbVec3f[N_CAMERAS*N_LEDS];
		m_norm_array[s] = new SbVec3f[N_CAMERAS*N_LEDS];
		m_b_array[s] = new unsigned char[N_CAMERAS*N_LEDS];
		m_flag_array[s] = new unsigned char[N_CAMERAS*N_LEDS];
		m_indices[s] = new long[N_CAMERAS*N_LEDS];
		for (i=0; i<(N_CAMERAS*N_LEDS); i++)
		{
			m_b_array[s][i] = 0;
			m_flag_array[s][i] = ACCEPTED;
			m_indices[s][i] = SO_END_FACE_INDEX;
		}
	}

	m_surface_smoothed = FALSE;
	m_curv_map_calculated = FALSE;
	m_texture_edges_detected = FALSE;

	c_gmask = 7;
	c_lhthr = 20;
	c_uhthr = 100;

	min_mean_curv	=  999999.0;
	max_mean_curv	=       0.0;

	min_gaus_curv	=  999999.0;
	max_gaus_curv	= -999999.0;

	min_curvedness	=  999999.0;
	max_curvedness	=       0.0;

	min_shapeindex	=  999999.0;
	max_shapeindex	= -999999.0;
}

CBodyAnalyserDoc::~CBodyAnalyserDoc()
{
}

BOOL CBodyAnalyserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

 
// BEGIN_IVWGEN
	IvfOnNewDocument();
// END_IVWGEN
 
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserDoc serialization

void CBodyAnalyserDoc::Serialize(CArchive& ar)
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
// CBodyAnalyserDoc diagnostics

#ifdef _DEBUG
void CBodyAnalyserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBodyAnalyserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBodyAnalyserDoc commands




//  OnFileImport --
//  yet another special file open scenario.  still want to route
//  through OpenDocument to handle menus, urls, etc., but don't
//  want to actually update the document per se.  This just gets
//  added to the current doc.
//
void CBodyAnalyserDoc::OnFileImport()
{
m_eOpenType = IVFDOC_OPEN_IMPORT;
theApp.OnFileOpen();
}


void CBodyAnalyserDoc::OnUpdateFileImport(CCmdUI *pCmdUI)
{
pCmdUI->Enable(m_pSceneRoot != NULL);
}


BOOL CBodyAnalyserDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
return(IvfOnOpenDocumentMessage(lpszPathName));
}

void CBodyAnalyserDoc::OnUpdateViewpoints(CCmdUI* pCmdUI) 
{
IvfOnUpdateViewpoints(pCmdUI);
}


static char spv_save_suffix[] = ".iv";
static char spv_save_filter[] =
   "Inventor Files (*.iv)\0*.iv\0Vrml Files (*.wrl)\0*.wrl\0Curvature Maps (*.hcc)\0*.hcc\0BMP Files (*.bmp)\0*.bmp\0";

void CBodyAnalyserDoc::OnFileSaveAs() 
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
         /*
		  if (IvfGetFileType() == IVF_FILETYPE_IV)
            IvfSetFileType(IVF_FILETYPE_VRML);
         stat = OnSaveDocument(save_dlg.m_ofn.lpstrFile);
		 */
		  stat = SaveAsVRML2(save_dlg.m_ofn.lpstrFile);
         break;
			//  VRML requires new header - need to set the filetype.
                        //  Don't change if file was read in as VRML or VRML2.
	  case 3:   // .hcc file (curvature map)
		  stat = SaveCurvatureMap(save_dlg.m_ofn.lpstrFile);
		 break;

      case 4:	// .bmp file
         {
         CBodyAnalyserView *t_view =
	    (CBodyAnalyserView *)CIvfApp::IvfGetAfxView();
         stat = t_view->SaveAsBitmap(save_dlg.m_ofn.lpstrFile);
         }
         break;
			//  .bmp is totally different - let view handle.
      }
   }
}

BOOL CBodyAnalyserDoc::SaveAsVRML2(LPCTSTR lpszPathName)
{
	HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
	SetCursor(waitCursor);

	ofstream vrml_file;
	vrml_file.open(lpszPathName);

	unsigned int cam;
	unsigned int start, finish;
	unsigned int index, slice;
	float x,y,z;
	long int a, b, c;

	vrml_file << "#VRML V2.0 utf8\n\n";

	vrml_file << "Viewpoint {\n";
    vrml_file << "orientation    0 0 1 0 \n";
    vrml_file << "position       0 10000 50000\n";   
    vrml_file << "}\n\n";

	for(cam = 0; cam < N_CAMERAS; cam++)
	{

		start = camera_start[cam]+1;
		finish = camera_end[cam]-1;

		vrml_file << "Shape {\n";

		vrml_file << "geometry IndexedFaceSet {\n";

		vrml_file << "coord Coordinate {\n";
		vrml_file << "point [\n";
	
		for(slice = 0; slice<N_SLICES; slice++)
		{
			for(index = start; index<=finish; index++)
			{
				if (m_indices[slice][index] != SO_END_FACE_INDEX)
				{
					m_xyz_array[slice][index].getValue(x,y,z);
					vrml_file << "" << x << " " << y << " " << z << "\n";
				}
			}
		}

		vrml_file << "]\n";
		vrml_file << "}\n";	// end of coord

		vrml_file << "normal Normal {\n";
		vrml_file << "vector [\n";
	
		for(slice = 0; slice<N_SLICES; slice++)
		{
			for(index = start; index<=finish; index++)
			{
				if (m_indices[slice][index] != SO_END_FACE_INDEX)
				{
					m_norm_array[slice][index].getValue(x,y,z);
					vrml_file << "" << x << " " << y << " " << z << "\n";
				}
			}
		}

		vrml_file << "]\n";
		vrml_file << "}\n";	// end of normal
	
		vrml_file << "color Color {\n";
		vrml_file << "color [\n";

		for(slice = 0; slice<N_SLICES; slice++)
		{
			for(index = start; index<=finish; index++)
			{
				if (m_indices[slice][index] != SO_END_FACE_INDEX)
				{
					x = m_b_array[slice][index] / 256.0;
					vrml_file << "" << x << " " << x << " " << x << "\n";
				}
			}
		}

		vrml_file << "]\n";
		vrml_file << "}\n";	// end of colo(u)r

		vrml_file << "coordIndex [\n";
	
		for(index = start; index<finish; index++)
		{
			for(slice = 0; slice<N_SLICES-1; slice++)
			{
				if (m_indices[slice][index] != SO_END_FACE_INDEX)
				{
					//downwards
					if(
						(m_indices[slice][index] != SO_END_FACE_INDEX) &&
						(m_indices[slice+1][index] != SO_END_FACE_INDEX) &&
						(m_indices[slice+1][index+1] != SO_END_FACE_INDEX)
						)
					{
						a = m_indices[slice][index];
						b = m_indices[slice+1][index];
						c = m_indices[slice+1][index+1];
						vrml_file << "" << a << " " << b << " " << c << " " << SO_END_FACE_INDEX << "\n";
					}

					//to the right
					if(
						(m_indices[slice][index] != SO_END_FACE_INDEX) &&
						(m_indices[slice][index+1] != SO_END_FACE_INDEX) &&
						(m_indices[slice+1][index+1] != SO_END_FACE_INDEX)
						)
					{
						a = m_indices[slice][index+1];
						b = m_indices[slice][index];
						c = m_indices[slice+1][index+1];
						vrml_file << "" << a << " " << b << " " << c << " " << SO_END_FACE_INDEX << "\n";
					}
				}
			}
		}
		
		
		vrml_file << "]\n";	// end of coordindex

		vrml_file << "}\n"; // end of indexedfaceset

		vrml_file << "}\n";	// end of shape
	
	}

	vrml_file.close();

	HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
	SetCursor(arrowCursor);

	return 1;
}

BOOL CBodyAnalyserDoc::SaveCurvatureMap(LPCTSTR lpszPathName)
{
	BOOL stat = FALSE;
	if(!m_curv_map_calculated)
	{
		AfxMessageBox("Cannot save the Curvature Map as it has not been calculated. Please press Alt+C to calculate it and try saving again.",MB_OK);
	}
	else
	{
		HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		unsigned int index, slice;
		float x,y,z;

		ofstream hcc_file;
		hcc_file.open(lpszPathName);
	
		hcc_file << N_CAMERAS << "\n" << N_LEDS << " " << N_SLICES << "\n";

		for(slice = 0; slice<N_SLICES; slice++)
		{
			for(index = 0; index< (N_CAMERAS * N_LEDS); index++)
			{
				if (m_indices[slice][index] != SO_END_FACE_INDEX)
				{
					m_xyz_array[slice][index].getValue(x,y,z);
					hcc_file << "1 " << x << " " << y << " " << z << " ";

					if(m_curv_map[slice][index].exists==TRUE)
					{
						hcc_file << "1 " << m_curv_map[slice][index].k1 << " " << m_curv_map[slice][index].k2 << "\n";
						// ADD ALSO : The curvature directions
						// And later: the features (maybe add them as flags on the curvature profile)					
					}
					else
					{
						hcc_file << "0 \n";
					}


				}
				else
				{
					hcc_file << "0 \n";
	
				}
			}
		}

	
		hcc_file.close();

		HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);

		stat = TRUE;
	}



	return stat;
}

BOOL CBodyAnalyserDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
BOOL stat;
CBodyAnalyserView *pView =
   (CBodyAnalyserView *)CIvfApp::IvfGetAfxView();

//  pView->SendMessage(WM_COMMAND, ID_VIEW_VIEWINGMODE, 0);
		//  don't need this any more ??


stat = CDocument::OnSaveDocument(lpszPathName);

return(stat);
}

void CBodyAnalyserDoc::OnFileReload() 
{
CIvfApp *pApp = CIvfApp::IvfGetApp();

IvfDeleteContents();
OnOpenDocument(GetPathName());
if (pApp->IvfIsMdi()) IvfSceneGraphChanged();
			//  an mdi app needs to treat the single
			//  frame as an SDI to reload.
}

void CBodyAnalyserDoc::OnUpdateFileReload(CCmdUI* pCmdUI) 
{
pCmdUI->Enable(m_pSceneRoot != NULL);
}



void CBodyAnalyserDoc::IvfSetupUrlFetchCallback(void)
{
CIvfDocument::IvfSetupUrlFetchCallback();
}

short CBodyAnalyserDoc::OpenHCCFile(const CString& input_file)
{
	ifstream hcc_file;
	int cams, slices, indices;

	unsigned int slice, index;

	float curr_x, curr_y, curr_z;
	int curr_g, curr_j;
	float k1, k2;
	SbVec3f curr_v;


	hcc_file.open(input_file, ios::nocreate|ios::in);
	if (!hcc_file.good())
	{
		return FALSE;
	}
	else
	{
		m_curv_map_calculated = TRUE;

		hcc_file >> cams;
		hcc_file >> indices;
		hcc_file >> slices;

		// sort out properly, so that it works automatically with hamamatsu scans too
		if(cams==1)
		{
			camera_start[0] = 0;
			camera_end[0] = indices-1;
		}


		if (1==1 /*(indices==N_LEDS) && (slices==N_SLICES) && (tones==N_GSCALES) */)
		{
			N_CAMERAS	= cams;
			N_LEDS		= indices;
			N_SLICES	= slices;

			for(slice = 0; slice < N_SLICES; slice++)
			{
				for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
				{
					hcc_file >> curr_g;

				if (curr_g == 1)
					{
						m_flag_array[slice][index] = ACCEPTED;

						hcc_file >> curr_x;
						hcc_file >> curr_y;
						hcc_file >> curr_z;
	
						curr_v.setValue(curr_x,curr_y,curr_z);
						m_xyz_array[slice][index] = curr_v;
						m_b_array[slice][index] = 200;
							
						hcc_file >> curr_j;
						if(curr_j == 1)
						{
							hcc_file >> k1;
							hcc_file >> k2;
						// ADD here: add the curvatures etc to the m_curv_map.
							m_curv_map[slice][index].exists = TRUE;
							m_curv_map[slice][index].k1 = k1;
							m_curv_map[slice][index].k2 = k2;
							
							// the following should be a member function of CCurvatureProfile
							// and called in EVERY occasion. 
							m_curv_map[slice][index].K = k1 * k2;		if (fabs(m_curv_map[slice][index].K)<0.000000000000001) {m_curv_map[slice][index].K = 0.0;}
							m_curv_map[slice][index].H = (k1+k2)/2.0;	if (fabs(m_curv_map[slice][index].H)<0.000000000000001) {m_curv_map[slice][index].H = 0.0;}

							// also to add here: the calculation of shape indices and the
							// extremal values of the curvature metrics
							// (for histogramming and proper display)
						}
					}// end id 
					else
					{
						m_flag_array[slice][index] = REJECTED;
						curr_v.setValue(0,0,0);
						m_xyz_array[slice][index] = curr_v;
						m_curv_map[slice][index].exists = FALSE;
					}

				}// end loop index
			}//end loop slice
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	hcc_file.close();
}

short CBodyAnalyserDoc::OpenSCFile(const CString& input_file)
{
	ifstream ppm_file;
	int cams, slices, indices, tones, chans;

	unsigned int slice, camera, index;

	float curr_x, curr_y, curr_z;
	int curr_g;
	SbVec3f curr_v;

	float f = 10.0;		// scaling factor for non-hamamatsu data.
	float c = 10000.0;	//   shift factor for non-hamamatsu data.

	// sort out properly, so that it works automatically with hamamatsu scans too


	ppm_file.open(input_file, ios::nocreate|ios::in);
	if (!ppm_file.good())
	{
		return FALSE;
	}
	else
	{
		ppm_file >> cams;
		ppm_file >> indices;
		ppm_file >> slices;
		ppm_file >> tones;
		ppm_file >> chans;

		// sort out properly, so that it works automatically with hamamatsu scans too
		if(cams==1)
		{
			camera_start[0] = 0;
			camera_end[0] = indices-1;
		}


		if (1==1 /*(indices==N_LEDS) && (slices==N_SLICES) && (tones==N_GSCALES) */)
		{
			N_CAMERAS	= cams;
			N_LEDS		= indices;
			N_SLICES	= slices;
			N_GSCALES	= tones;
			N_CHANNELS	= chans;

			for(camera = 0; camera < N_CAMERAS; camera++)
			{
				for(slice = 0; slice < N_SLICES; slice++)
				{
					for(index = 0; index < N_LEDS; index++)
					{
						ppm_file >> curr_x;
						ppm_file >> curr_y;
						ppm_file >> curr_z;
						ppm_file >> curr_g;

						if (curr_g!=(-1))
						{
							m_flag_array[slice][index+(camera*N_LEDS)] = ACCEPTED;
						}
						else
						{
							m_flag_array[slice][index+(camera*N_LEDS)] = REJECTED;
						}

						if(N_CAMERAS==8)	// Hamamatsu Scan
						{
							curr_v.setValue(curr_x,curr_y,curr_z);
						}
						else				// SomaView Output
						{
							curr_v.setValue(-curr_y*f,(curr_z*f)+c,-curr_x*f);
						}

						m_xyz_array[slice][index+(camera*N_LEDS)] = curr_v;
						m_b_array[slice][index+(camera*N_LEDS)] = curr_g;


					}//index
				}//slice
			}//camera

		}//if(1==1)
		else
		{
			return FALSE;
		}

		ppm_file.close();

		// closing round (for test objects)
		if(cams==1)
		{
			CDlgWrapMesh wrapdlg;
			if(wrapdlg.DoModal()==IDOK)
			{
				N_LEDS+=2;
				camera_end[0]+=2;
				for(slice = 0; slice < N_SLICES; slice++)
				{
					m_flag_array[slice][N_LEDS-2]	= m_flag_array[slice][0];
					m_b_array[slice][N_LEDS-2]		= m_b_array[slice][0];
					m_xyz_array[slice][N_LEDS-2]	= m_xyz_array[slice][0];		

					m_flag_array[slice][N_LEDS-1]	= m_flag_array[slice][1];
					m_b_array[slice][N_LEDS-1]		= m_b_array[slice][1];
					m_xyz_array[slice][N_LEDS-1]	= m_xyz_array[slice][1];		
				}
			}
		}
		
		return TRUE;
	}
}

short CBodyAnalyserDoc::OpenFile(const CString& input_file)
{
	unsigned int head, slice, index;
	int num_in;
	int buf_num, rel_index;
	short* dist_buf;
	unsigned char* br_buf;

	ifstream bls_file;

	bls_file.open(input_file, ios::nocreate|ios::in);
	if (!bls_file.good())
		return FALSE;

	const int sz_header = 16;
	const int sz_dword = 4;
	const int sz_float = 4;

	DWORD x, y;
	float a;
	char header[sz_header];
	
	m_bHasData = TRUE;

	bls_file >> binary;
	bls_file.read(header, 16);

	m_data_source = BLS_ASCII;
	if (!strcmp(header, "BLS_V_10_150997"))
		m_data_source = BLS_V_10_150997;
	if (!strcmp(header, "BLS_V009_300998"))
		m_data_source = BLS_V009_300998;

	switch(m_data_source)
	{
		case(BLS_V009_300998):
			// binary format: app opens file and gets data as if 
			// downloading directly from hardware; doc then gets
			// the data from the app
			for (head=0; head<8; head++)
			{
				bls_file.read((char*)(&x), sz_dword);
				m_scanner_params.m_hdx[head] = x;
				bls_file.read((char*)(&y), sz_dword);
				m_scanner_params.m_hdy[head] = y;
				bls_file.read((char*)(&a), sz_float);
				m_scanner_params.m_hda[head] = a;
			}
			m_scanner_params.m_params_file = input_file;
			// get the rest of the data
			theApp.OpenFromFile(bls_file);
			GetDownload();
			break;

		case(BLS_V_10_150997):
			// binary format: app opens file and gets data as if 
			// downloading directly from hardware; doc then gets
			// the data from the app
			theApp.OpenFromFile(bls_file);
			GetDownload();
			break;

		case(BLS_ASCII):
			// close file and reopen it as text
			bls_file.close();
			bls_file.open(input_file);
			// old ASCII format
			// convert the string to integer (num_in)

			// need also to store data in the app's raw data buffers in case
			// we want to save it later in a different format

			// distance values
			for (slice=0; slice<N_SLICES; slice++)
			{
				buf_num = slice/100; // int division
				switch(buf_num)
				{
				case 0:
					dist_buf = theApp.m_dist1;
					break;
				case 1:
					dist_buf = theApp.m_dist2;
					break;
				case 2:
					dist_buf = theApp.m_dist3;
					break;
				case 3:
					dist_buf = theApp.m_dist4;
					break;
				}

				for (index=0; index<(N_LEDS*N_CAMERAS); index++)
				{
					bls_file >> num_in;
					m_xyz_array[slice][index] = Cartesian(slice,index,num_in);
					rel_index = (slice*(N_LEDS*N_CAMERAS)+index)%25600;
					dist_buf[rel_index] = num_in; // store raw value
				}
				// if ASCII, error in input - data was stored as 4x25601 values
				if (slice%100==99)
					bls_file >> num_in;	
			}			
			// brightness values
			for (slice=0; slice<N_SLICES; slice++)
			{
				buf_num = slice/100; // int division
				switch(buf_num)
				{
				case 0:
					br_buf = theApp.m_brbuf1;
					break;
				case 1:
					br_buf = theApp.m_brbuf2;
					break;
				case 2:
					br_buf = theApp.m_brbuf3;
					break;
				case 3:
					br_buf = theApp.m_brbuf4;
					break;
				}

				for (index=0; index<(N_LEDS*N_CAMERAS); index++)
				{
					bls_file >> num_in;
					m_b_array[slice][index] = num_in;
					rel_index = (slice*(N_LEDS*N_CAMERAS)+index)%25600;
					br_buf[rel_index] = num_in;	// store raw value
				}
				// if version 0.x, error in input - data was stored as 4x25601 values
				if (slice%100==99)
					bls_file >> num_in;	
			}
			// initialise flag array
			// at start we don't know to which part of the body points belong
			// so designate them as WHOLE body until we know
			for (slice=0; slice<N_SLICES; slice++)
			{
				for (index=0; index<(N_LEDS*N_CAMERAS); index++)
					m_flag_array[slice][index] = ACCEPTED;	
			}
			break;
	}	
	
	bls_file.close();
	m_input_file = input_file;	
	return TRUE;
}

BOOL CBodyAnalyserDoc::GetDownload(void)
{
	unsigned int slice, index;
	m_bHasData = TRUE;
	short distance, brightness;

	for (slice=0; slice<N_SLICES; slice++)
	{
		for (index=0; index<(N_LEDS*N_CAMERAS); index++)
		{			
			distance = theApp.GetDistance(slice,index);
			m_xyz_array[slice][index] = Cartesian(slice,index,distance);		
			brightness = theApp.GetBrightness(slice,index);
			m_b_array[slice][index] = brightness;	
		}
	}

	// initialise flag array
	// at start we don't know to which part of the body points belong
	// so designate them as WHOLE body until we know
	for (slice=0; slice<N_SLICES; slice++)
	{
		for (index=0; index<(N_LEDS*N_CAMERAS); index++)
		{
			m_flag_array[slice][index] = ACCEPTED;	
		}
	}

	//char cwd[256];
	//_getcwd(cwd, 256);
	//m_input_file = cwd;
	//m_input_file += "\\tmp.bls";
	m_data_source = HARDWARE;
	return TRUE;

}

SbVec3f& CBodyAnalyserDoc::Cartesian(int slice, int index, int distance)
{
	assert(slice >= 0  &&  slice < N_SLICES  &&  index >=0  && index < (N_LEDS*N_CAMERAS));

	float dm, xn, yn, zn;
	float angle, d_angle;
    
    // calculate the x and y values according to the distance data,
    // using the angle obtained from the head number and LED number
	// this is stored per document

	// Note the use of Hamamatsu's original coordinate system 
	// using y = -z
    if (index < 32)
	{
		d_angle = d_theta * index;
        angle = m_scanner_params.m_hda[0] - d_angle;
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[0] + dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[0] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 31 && index < 64) 
	{
		d_angle = d_theta * (index - 32);
        angle = m_scanner_params.m_hda[1] - d_theta * (index - 32);
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[1] + dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[1] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 63 && index < 96) 
	{
		d_angle = d_theta * (index - 64);
        angle = m_scanner_params.m_hda[2] - d_angle;
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[2] + dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[2] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 95 && index < 128)
	{
		d_angle = d_theta * (index - 96);
        angle = m_scanner_params.m_hda[3] - d_angle;
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[3] + dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[3] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 127 && index < 160)
	{
		d_angle = d_theta * (index - 128);
        angle = m_scanner_params.m_hda[4] + d_angle; //-11.9
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[4] - dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[4] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 159 && index < 192) 
	{
		d_angle = d_theta * (index - 160);
        angle = m_scanner_params.m_hda[5] + d_angle;
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[5] - dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[5] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 191 && index < 224) 
	{
		d_angle = d_theta * (index - 192);
        angle = m_scanner_params.m_hda[6] + d_angle;
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[6] - dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[6] + dm * sin((angle * M_PI) / 180);
	}
    else if (index > 223 && index < 256)
	{
		d_angle = d_theta * (index - 224);
        angle = m_scanner_params.m_hda[7] + d_angle;
        dm = distance / cos(((12.243 - d_angle) * M_PI) / 180);
        xn = m_scanner_params.m_hdx[7] - dm * cos((angle * M_PI) / 180);
        yn = m_scanner_params.m_hdy[7] + dm * sin((angle * M_PI) / 180);
    }

    // calculate the height of the current point, assuming
    // uniform movement of heads throughout scan

	double abs_index = slice*256+index;
	zn = 20000.0 - 20000.0 * (abs_index/102400.0);
	
	// correct the xyz values and output in the right-hand 
	// coordinate system 
	return SbVec3f(xn*m_x_correction,zn*m_y_correction,-yn*m_z_correction);
}

void CBodyAnalyserDoc::RenderBody()
{
	unsigned short int i;

	root = new SoSeparator;
	root->ref();

	// initialising drawstyles
	m_PointCloud_DrawStyle				= new SoDrawStyle;
	m_OutlierCloud_DrawStyle			= new SoDrawStyle;
	m_CoordOrigin_DrawStyle				= new SoDrawStyle;
	m_RefFrame_DrawStyle				= new SoDrawStyle;
	m_CurvDir_NearUmbilics_DrawStyle	= new SoDrawStyle;
	m_CurvDir_Red_DrawStyle				= new SoDrawStyle;
	m_CurvDir_Blue_DrawStyle			= new SoDrawStyle;
	m_TextureEdgels_DrawStyle			= new SoDrawStyle;
	m_Ridges_DrawStyle					= new SoDrawStyle;
	m_Flexcords_DrawStyle				= new SoDrawStyle;
	m_Connected_DrawStyle_0				= new SoDrawStyle;
	m_Connected_DrawStyle_1				= new SoDrawStyle;
	m_Connected_DrawStyle_2				= new SoDrawStyle;
	m_Connected_DrawStyle_3				= new SoDrawStyle;
	m_Connected_DrawStyle_4				= new SoDrawStyle;
	m_Connected_DrawStyle_5				= new SoDrawStyle;
	m_Connected_DrawStyle_6				= new SoDrawStyle;
	m_Connected_DrawStyle_7				= new SoDrawStyle;
	for(i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i] = new SoDrawStyle;}

	// initialising light model
	m_LightModel = new SoLightModel;
	root->addChild(m_LightModel);
	m_LightModel->model.setValue(SoLightModel::PHONG);
	
	// initialising point cloud
	SoSeparator* s_pointCloud = new SoSeparator;
	s_pointCloud = RenderPointCloud();
	root->addChild(s_pointCloud);

	// initialising outlier cloud
	SoSeparator* s_outlierCloud = new SoSeparator;
	s_outlierCloud = RenderOutlierCloud();
	root->addChild(s_outlierCloud);

	// initialising reference frame
	SoSeparator* s_referenceFrame = new SoSeparator;
	s_referenceFrame = RenderReferenceFrame();
	root->addChild(s_referenceFrame);

	// initialising coordinate origin
	SoSeparator* s_coordOrigin = new SoSeparator;
	s_coordOrigin = RenderCoordOrigin();
	root->addChild(s_coordOrigin);

	// initialising connected mesh
	for(i = 0; i < N_CAMERAS; i++)
	{	
		//connectedMesh[i] = new SoSeparator;
		//connectedMesh[i] = RenderConnectedMesh(i);
		//root->addChild(connectedMesh[i]);
	}
	
	// initialising triangulated mesh
	CalculateNormals();
	for(int j = 0; j < N_CAMERAS; j++)
	{
		s_triangMesh[j] = new SoSeparator;
		s_triangMesh[j] = RenderTriangMesh(j);
		root->addChild(s_triangMesh[j]);
	}

	//initialising symmetry planes
	SoSeparator* s_symPlanes = new SoSeparator;
	s_symPlanes = RenderSymmetryPlanes();
	root->addChild(s_symPlanes);



	IvfSetSceneGraph( root );
	root -> unref();

	//initialising toggles
	OnViewConnectedmeshAll();
	SetDisplayProperties(POINT_CLOUD);
	SetDisplayProperties(OUTLIER_CLOUD);
	SetDisplayProperties(REF_FRAME);
	SetDisplayProperties(COORD_ORIGIN);
	SetDisplayProperties(CURV_DIR_ALL);

	
}

// -----------------renderers -------------------------------------------------------------

SoSeparator* CBodyAnalyserDoc::RenderPointCloud()
{
	SoSeparator* S = new SoSeparator;			

	S->addChild(m_PointCloud_DrawStyle);

	int slice, index; 
	int i = 0;

	SoCoordinate3 *vertices = new SoCoordinate3;
		
	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_LEDS*N_CAMERAS); index++)
		{
			if (m_flag_array[slice][index]!=REJECTED)
			{
			vertices->point.set1Value(i++, m_xyz_array[slice][index]);
			}
		}
	}

	SoPointSet *cPoints = new SoPointSet;
	S->addChild(vertices);

	SoMaterial  *pointColor = new SoMaterial;
	pointColor->diffuseColor.setValue(0.0, 0.0, 0.99); 
	S->addChild(pointColor);

	S->addChild(cPoints);

	return S;

}

SoSeparator* CBodyAnalyserDoc::RenderOutlierCloud()
{
	SoSeparator* S = new SoSeparator;			

	S->addChild(m_OutlierCloud_DrawStyle);

	int slice, index; 
	int i = 0;

	SoCoordinate3 *vertices = new SoCoordinate3;
		
	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_LEDS*N_CAMERAS); index++)
		{
			if (m_flag_array[slice][index]==REJECTED)
			{
			vertices->point.set1Value(i++, m_xyz_array[slice][index]);
			}
		}
	}


	SoPointSet *cPoints = new SoPointSet;
	S->addChild(vertices);

	SoMaterial  *pointColor = new SoMaterial;
	pointColor->diffuseColor.setValue(0.8, 0.8, 0.8); 
	S->addChild(pointColor);

	S->addChild(cPoints);

	return S;

}


SoSeparator* CBodyAnalyserDoc::RenderReferenceFrame()
{
	SoSeparator* S = new SoSeparator;			int c,i;

	S->addChild(m_RefFrame_DrawStyle);

	SoMaterial *refFrameColor = new SoMaterial;
	refFrameColor->diffuseColor.setValue(0.35, 0.35, 0.5); 
	S->addChild(refFrameColor);

	float f = GLOBAL_SCALING_FACTOR;
	float small = -500*f;
	float large =  500*f;
	float  step = 50*f;
	float lim = 2000*f;


	//-----------------------------------------------------------RIGHT SIDE
	for(i = 0; i<=lim; i+=step)
	{
		SoSeparator* L = new SoSeparator;	c = 0;
	
		SoCoordinate3 *vertices = new SoCoordinate3;
		vertices->point.set1Value(c++, small, i, small);
		vertices->point.set1Value(c++, large, i, small);

		SoLineSet *cLines = new SoLineSet;
		L->addChild(vertices);
		L->addChild(cLines);

		S->addChild(L);
	}

	
	for(i = small; i<=large; i+=step)
	{
		SoSeparator* L = new SoSeparator;	c = 0;
	
		SoCoordinate3 *vertices = new SoCoordinate3;
		vertices->point.set1Value(c++, i, 0,   small);
		vertices->point.set1Value(c++, i, lim, small);

		SoLineSet *cLines = new SoLineSet;
		L->addChild(vertices);
		L->addChild(cLines);

		S->addChild(L);
	}

	//-----------------------------------------------------------REAR SIDE 
	
	for(i = 0; i<=lim; i+=step)
	{
		SoSeparator* L = new SoSeparator;	c = 0;
	
		SoCoordinate3 *vertices = new SoCoordinate3;
		vertices->point.set1Value(c++, large, i, small);
		vertices->point.set1Value(c++, large, i, large);

		SoLineSet *cLines = new SoLineSet;
		L->addChild(vertices);
		L->addChild(cLines);

		S->addChild(L);
	}
	
	for(i = small; i<=large; i+=step)
	{
		SoSeparator* L = new SoSeparator;	c = 0;
	
		SoCoordinate3 *vertices = new SoCoordinate3;
		vertices->point.set1Value(c++, large, 0,   i);
		vertices->point.set1Value(c++, large, lim, i);

		SoLineSet *cLines = new SoLineSet;
		L->addChild(vertices);
		L->addChild(cLines);
	
		S->addChild(L);
	}

	//-----------------------------------------------------------FLOOR 
	
	for(i = small; i<=large; i+=step)
	{
		SoSeparator* L = new SoSeparator;	c = 0;
	
		SoCoordinate3 *vertices = new SoCoordinate3;
		vertices->point.set1Value(c++, i, 0, small);
		vertices->point.set1Value(c++, i, 0, large);

		SoLineSet *cLines = new SoLineSet;
		L->addChild(vertices);
		L->addChild(cLines);

		S->addChild(L);
	}
	
	for(i = small; i<=large; i+=step)
	{
		SoSeparator* L = new SoSeparator;	c = 0;
	
		SoCoordinate3 *vertices = new SoCoordinate3;
		vertices->point.set1Value(c++, large, 0,   i);
		vertices->point.set1Value(c++, small, 0,   i);

		SoLineSet *cLines = new SoLineSet;
		L->addChild(vertices);
		L->addChild(cLines);
	
		S->addChild(L);
	}

	return S ;
}

SoSeparator* CBodyAnalyserDoc::RenderCoordOrigin()
{
	SoSeparator* S = new SoSeparator;	
	
	S->addChild(m_CoordOrigin_DrawStyle);

	SoMaterial *coordOriginColor = new SoMaterial;
	coordOriginColor->diffuseColor.setValue(1.0, 0.0, 0.0); 
	S->addChild(coordOriginColor);

	//x axis
	SoSeparator* aX = new SoSeparator;
	SoCoordinate3 *Xvertices = new SoCoordinate3;
	Xvertices->point.set1Value(0, 0, 0, 0);
	Xvertices->point.set1Value(1, 1500, 0, 0);
	SoLineSet *Xlines = new SoLineSet;
	aX->addChild(Xvertices);
	aX->addChild(Xlines);
	S->addChild(aX);
 
	//y axis
	SoSeparator* aY = new SoSeparator;
	SoCoordinate3 *Yvertices = new SoCoordinate3;
	Yvertices->point.set1Value(0, 0, 0, 0);
	Yvertices->point.set1Value(1, 0, 1000, 0);
	SoLineSet *Ylines = new SoLineSet;
	aY->addChild(Yvertices);
	aY->addChild(Ylines);
	S->addChild(aY);
 
	//z axis
	SoSeparator* aZ = new SoSeparator;
	SoCoordinate3 *Zvertices = new SoCoordinate3;
	Zvertices->point.set1Value(0, 0, 0, 0);
	Zvertices->point.set1Value(1, 0, 0, 500);
	SoLineSet *Zlines = new SoLineSet;
	aZ->addChild(Zvertices);
	aZ->addChild(Zlines);
	S->addChild(aZ);

	return S;
}

SoSeparator* CBodyAnalyserDoc::RenderTextureEdgels()
{
	SoSeparator* S = new SoSeparator;	

	S->addChild(m_TextureEdgels_DrawStyle);
	m_TextureEdgels_DrawStyle->pointSize = 3;

	SoMaterial *texEdgelsColor = new SoMaterial;
	texEdgelsColor->diffuseColor.setValue(1.0, 0.0, 0.0); 
	S->addChild(texEdgelsColor);

	int slice, index; 
	int i = 0;

	SoCoordinate3 *vertices = new SoCoordinate3;
		
	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_LEDS*N_CAMERAS); index++)
		{
			if ((m_edge_array[slice][index]) && (m_flag_array[slice][index]!=REJECTED))
			{
			vertices->point.set1Value(i++, m_xyz_array[slice][index]);
			}
		}
	}


	SoPointSet *cPoints = new SoPointSet; 
	S->addChild(vertices);
	S->addChild(cPoints); 
	return S;
}

SoSeparator* CBodyAnalyserDoc::RenderRidges()
{
	SoSeparator* S = new SoSeparator;	

	S->addChild(m_Ridges_DrawStyle);
	m_Ridges_DrawStyle->pointSize = 3;

	SoMaterial *RidgesColor = new SoMaterial;
	RidgesColor->diffuseColor.setValue(1.0, 1.0, 1.0); 
	S->addChild(RidgesColor);

	int slice, index; 
	int i = 0;

	SoCoordinate3 *vertices = new SoCoordinate3;
		
	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_LEDS*N_CAMERAS); index++)
		{
			if ((m_curv_map[slice][index].exists) && 
				(m_curv_map[slice][index].ridge))
			{
			vertices->point.set1Value(i++, m_xyz_array[slice][index]);
			}
		}
	}

	SoPointSet *cPoints = new SoPointSet; 
	S->addChild(vertices);
	S->addChild(cPoints); 
	return S;
}

SoSeparator* CBodyAnalyserDoc::RenderFlexcords()
{
	SoSeparator* S = new SoSeparator;	

	S->addChild(m_Flexcords_DrawStyle);
	m_Flexcords_DrawStyle->pointSize = 3;

	SoMaterial *FlexcordsColor = new SoMaterial;
	FlexcordsColor->diffuseColor.setValue(0.0, 0.0, 0.0); 
	S->addChild(FlexcordsColor);

	int slice, index; 
	int i = 0;

	SoCoordinate3 *vertices = new SoCoordinate3;
		
	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_LEDS*N_CAMERAS); index++)
		{
			if ((m_curv_map[slice][index].exists) && 
				(m_curv_map[slice][index].flexcord))
			{
			vertices->point.set1Value(i++, m_xyz_array[slice][index]);
			}
		}
	}

	SoPointSet *cPoints = new SoPointSet; 
	S->addChild(vertices);
	S->addChild(cPoints); 
	return S;
}

SoSeparator* CBodyAnalyserDoc::RenderSymmetryPlanes()
{
	int i;
	float A = 5000.0;
	//float A = 15000.0; // for the hi res bumpy umbilic
	float dY = 10000.0;

	SoSeparator* S = new SoSeparator;

	SoMaterial *sPlaneColour = new SoMaterial;
	sPlaneColour->diffuseColor.setValue(0.35, 0.35, 0.0); 
	sPlaneColour->transparency.setValue(0.6); 
	S->addChild(sPlaneColour);

	SoShapeHints *sPlaneHints = new SoShapeHints;
	sPlaneHints->vertexOrdering.setValue(SoShapeHints::COUNTERCLOCKWISE);
	sPlaneHints->shapeType.setValue(SoShapeHints::UNKNOWN_SHAPE_TYPE);
	S->addChild(sPlaneHints);

	SoSeparator* SS[N_SYM_SETS];
	for(i = 0; i<N_SYM_SETS; i++) 
	{
		SS[i] = new SoSeparator;
		SS[i]->addChild(m_Symmetry_DrawStyle[i]);
		S->addChild(SS[i]);
	}

	//Sx
	SoFaceSet* Sx_faceset = new SoFaceSet;
	Sx_faceset->numVertices.set1Value(0,4);
	//Sx_faceset->numVertices.set1Value(1,4);	// debug only

	SoCoordinate3* Sx_coords = new SoCoordinate3;
	Sx_coords->ref();
	Sx_coords->point.set1Value(0,	0,	-A+dY,	-A);
	Sx_coords->point.set1Value(1,	0,	-A+dY,	A);
	Sx_coords->point.set1Value(2,	0,	A+dY,	A);
	Sx_coords->point.set1Value(3,	0,	A+dY,	-A);
	// debug only
	//Sx_coords->point.set1Value(4,	100,	-A+dY,	-A);
	//Sx_coords->point.set1Value(5,	100,	-A+dY,	A);
	//Sx_coords->point.set1Value(6,	100,	A+dY,	A);
	//Sx_coords->point.set1Value(7,	100,	A+dY,	-A);
	// end debug only

	SS[SYM_SX]->addChild(Sx_coords);
	SS[SYM_SX]->addChild(Sx_faceset);

	//Sy

	SoFaceSet* Sy_faceset = new SoFaceSet;
	Sy_faceset->numVertices.setValue(4);

	SoCoordinate3* Sy_coords = new SoCoordinate3;
	Sy_coords->ref();
	Sy_coords->point.set1Value(0,	-A,	dY,	-A);
	Sy_coords->point.set1Value(1,	-A,	dY,	A);
	Sy_coords->point.set1Value(2,	A,	dY,	A);
	Sy_coords->point.set1Value(3,	A,	dY,	-A);

	SS[SYM_SY]->addChild(Sy_coords);
	SS[SYM_SY]->addChild(Sy_faceset);

	//Sz
	SoFaceSet* Sz_faceset = new SoFaceSet;
	Sz_faceset->numVertices.setValue(4);

	SoCoordinate3* Sz_coords = new SoCoordinate3;
	Sz_coords->ref();
	Sz_coords->point.set1Value(0,	-A,	-A+dY,	0);
	Sz_coords->point.set1Value(1,	-A,	A+dY,	0);
	Sz_coords->point.set1Value(2,	A,	A+dY,	0);
	Sz_coords->point.set1Value(3,	A,	-A+dY,	0);

	SS[SYM_SZ]->addChild(Sz_coords);
	SS[SYM_SZ]->addChild(Sz_faceset);

	//Dx
	SoFaceSet* Dx_faceset = new SoFaceSet;
	Dx_faceset->numVertices.set1Value(0,4);
	Dx_faceset->numVertices.set1Value(1,4);

	SoCoordinate3* Dx_coords = new SoCoordinate3;
	Dx_coords->ref();
	Dx_coords->point.set1Value(0,	-A,	-A+dY,	A);
	Dx_coords->point.set1Value(1,	A,	-A+dY,	A);
	Dx_coords->point.set1Value(2,	A,	A+dY,	-A);
	Dx_coords->point.set1Value(3,	-A,	A+dY,	-A);
	Dx_coords->point.set1Value(4,	-A,	A+dY,	A);
	Dx_coords->point.set1Value(5,	A,	A+dY,	A);
	Dx_coords->point.set1Value(6,	A,	-A+dY,	-A);
	Dx_coords->point.set1Value(7,	-A,	-A+dY,	-A);

	SS[SYM_DX]->addChild(Dx_coords);
	SS[SYM_DX]->addChild(Dx_faceset);

	//Dy
	SoFaceSet* Dy_faceset = new SoFaceSet;
	Dy_faceset->numVertices.set1Value(0,4);
	Dy_faceset->numVertices.set1Value(1,4);

	SoCoordinate3* Dy_coords = new SoCoordinate3;
	Dy_coords->ref();
	Dy_coords->point.set1Value(0,	A,	-A+dY,	A);
	Dy_coords->point.set1Value(1,	-A,	-A+dY,	-A);
	Dy_coords->point.set1Value(2,	-A,	A+dY,	-A);
	Dy_coords->point.set1Value(3,	A,	A+dY,	A);
	Dy_coords->point.set1Value(4,	A,	-A+dY,	-A);
	Dy_coords->point.set1Value(5,	-A,	-A+dY,	A);
	Dy_coords->point.set1Value(6,	-A,	A+dY,	A);
	Dy_coords->point.set1Value(7,	A,	A+dY,	-A);

	SS[SYM_DY]->addChild(Dy_coords);
	SS[SYM_DY]->addChild(Dy_faceset);

	//Dz
	SoFaceSet* Dz_faceset = new SoFaceSet;
	Dz_faceset->numVertices.set1Value(0,4);
	Dz_faceset->numVertices.set1Value(1,4);

	SoCoordinate3* Dz_coords = new SoCoordinate3;
	Dz_coords->ref();
	Dz_coords->point.set1Value(0,	A,	-A+dY,	A);
	Dz_coords->point.set1Value(1,	-A,	A+dY,	A);
	Dz_coords->point.set1Value(2,	-A,	A+dY,	-A);
	Dz_coords->point.set1Value(3,	A,	-A+dY,	-A);
	Dz_coords->point.set1Value(4,	-A,	-A+dY,	A);
	Dz_coords->point.set1Value(5,	A,	A+dY,	A);
	Dz_coords->point.set1Value(6,	A,	A+dY,	-A);
	Dz_coords->point.set1Value(7,	-A,	-A+dY,	-A);

	SS[SYM_DZ]->addChild(Dz_coords);
	SS[SYM_DZ]->addChild(Dz_faceset);

	//end

	OnViewSymmetryplanesNone();
	return S;
}

SoSeparator* CBodyAnalyserDoc::RenderConnectedMesh(int cam)
{
	SoSeparator* S = new SoSeparator;	

	int start, finish;
	int index, slice;

	//replace this later
	switch (cam)
	{
	case 0: S->addChild(m_Connected_DrawStyle_0); break;
	case 1: S->addChild(m_Connected_DrawStyle_1); break;
	case 2: S->addChild(m_Connected_DrawStyle_2); break;
	case 3: S->addChild(m_Connected_DrawStyle_3); break;
	case 4: S->addChild(m_Connected_DrawStyle_4); break;
	case 5: S->addChild(m_Connected_DrawStyle_5); break;
	case 6: S->addChild(m_Connected_DrawStyle_6); break;
	case 7: S->addChild(m_Connected_DrawStyle_7); break;
	default: break;
	}

	start = camera_start[cam]+1;
	finish = camera_end[cam]-1;

	SoMaterial *coordOriginColor = new SoMaterial;
	coordOriginColor->diffuseColor.setValue(0.0, 0.0, 1.0); 
	S->addChild(coordOriginColor);

	//vertical
	for(index = start; index <= finish; index++)
	{
		for(slice = 0; slice<N_SLICES-1; slice++)
		{
			if( (m_flag_array[slice][index]!=REJECTED) && (m_flag_array[slice+1][index]!=REJECTED) )
			{
				SoSeparator* L = new SoSeparator;
				SoCoordinate3 *Lvertices = new SoCoordinate3;
				Lvertices->point.set1Value(0, m_xyz_array[slice][index]);
				Lvertices->point.set1Value(1, m_xyz_array[slice+1][index]);			
				SoLineSet *lines = new SoLineSet;
				L->addChild(Lvertices);
				L->addChild(lines);
				S->addChild(L);

			}
		}
	}

	//horizontal
	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = start; index<finish; index++)
		{
			if( (m_flag_array[slice][index]!=REJECTED) && (m_flag_array[slice][index+1]!=REJECTED) )
			{
				SoSeparator* L = new SoSeparator;
				SoCoordinate3 *Lvertices = new SoCoordinate3;
				Lvertices->point.set1Value(0, m_xyz_array[slice][index]);
				Lvertices->point.set1Value(1, m_xyz_array[slice][index+1]);			
				SoLineSet *lines = new SoLineSet;
				L->addChild(Lvertices);
				L->addChild(lines);
				S->addChild(L);

			}
		}
	}


	return S;
}


SoSeparator* CBodyAnalyserDoc::RenderTriangMesh(int cam)
{
	SoSeparator* S = new SoSeparator;	

	int start, finish;
	int index, slice;

	int i;

	//replace this later
	switch (cam)
	{
	case 0: S->addChild(m_Connected_DrawStyle_0); break;
	case 1: S->addChild(m_Connected_DrawStyle_1); break;
	case 2: S->addChild(m_Connected_DrawStyle_2); break;
	case 3: S->addChild(m_Connected_DrawStyle_3); break;
	case 4: S->addChild(m_Connected_DrawStyle_4); break;
	case 5: S->addChild(m_Connected_DrawStyle_5); break;
	case 6: S->addChild(m_Connected_DrawStyle_6); break;
	case 7: S->addChild(m_Connected_DrawStyle_7); break;
	default: break;
	}

	/*
	start = camera_start[cam]+1;
	finish = camera_end[cam]-1;
	*/
//	/*
	start = camera_start[cam];
	finish = camera_end[cam];
//	*/


	// Adding Vertices
	i = 0;
	SoCoordinate3* Tvertices = new SoCoordinate3;

	for(slice = 0; slice<N_SLICES; slice++)
	{
		for(index = start; index <= finish; index++)
		{
			if (m_indices[slice][index] != SO_END_FACE_INDEX)
			{
				Tvertices->point.set1Value(i, m_xyz_array[slice][index]);
				i++;
			}
		}
	}

	S->addChild(Tvertices);

	// Adding Normals
	i = 0;
	SoNormal* Tnormal = new SoNormal;

	for(slice = 0; slice<N_SLICES; slice++)
	{
		for(index = start; index <= finish; index++)
		{
			if (m_indices[slice][index] != SO_END_FACE_INDEX)
			{
				Tnormal->vector.set1Value(i, m_norm_array[slice][index]);
				i++;
			}
		}
	}

	S->addChild(Tnormal);

	// Adding Materials
	SoMaterial* Tmaterial = new SoMaterial;		Tmaterial->ref();
	SoMaterial* Smaterial = new SoMaterial;		Smaterial->ref();
	i = 0;
	for(slice = 0; slice<N_SLICES; slice++)
	{
		for(index = start; index <= finish; index++)
		{
			if (m_indices[slice][index] != SO_END_FACE_INDEX)
			{
				float c = (m_b_array[slice][index]) / 256.0;
				float s = 0.7;
				Tmaterial->diffuseColor.set1Value(i, c,c,c);
				Smaterial->diffuseColor.set1Value(i, s,s,s);
				i++;
			}
		}
	}

	m_Texture_Material[cam] = new SoMaterial;
	m_Texture_Material[cam]->ref();
	m_Texture_Material[cam] = Tmaterial; 
	//m_Texture_Material[cam]->transparency.setValue(0.6); 

	m_Smooth_Material[cam] = new SoMaterial;
	m_Smooth_Material[cam]->ref();
	m_Smooth_Material[cam] = Smaterial; 
	//m_Smooth_Material[cam]->transparency.setValue(0.6); 

	m_ColourMappingMode = INTENSITIES;
	S->addChild(m_Texture_Material[cam]);

	m_Connected_Material_Binding[cam] = new SoMaterialBinding;
	m_Connected_Material_Binding[cam]->ref();
	m_Connected_Material_Binding[cam]->value = SoMaterialBinding::PER_VERTEX_INDEXED;
	S->addChild(m_Connected_Material_Binding[cam]);

	// Adding Indices
	i = 0;
	SoIndexedFaceSet* TfaceSet = new SoIndexedFaceSet;

	for(index = start; index < finish; index++)
	{
		for(slice = 0; slice<N_SLICES-1; slice++)
		{
			if (m_indices[slice][index] != SO_END_FACE_INDEX)
			{
				//downwards
				if (
					(m_indices[slice][index] != SO_END_FACE_INDEX) &&
					(m_indices[slice+1][index] != SO_END_FACE_INDEX) &&
					(m_indices[slice+1][index+1] != SO_END_FACE_INDEX)
					)
				{
					TfaceSet->coordIndex.set1Value(i++,m_indices[slice][index]);
					TfaceSet->coordIndex.set1Value(i++,m_indices[slice+1][index]);
					TfaceSet->coordIndex.set1Value(i++,m_indices[slice+1][index+1]);
					TfaceSet->coordIndex.set1Value(i++,SO_END_FACE_INDEX);
				}
				

				//to the right
				if (
					(m_indices[slice][index] != SO_END_FACE_INDEX) &&
					(m_indices[slice][index+1] != SO_END_FACE_INDEX) &&
					(m_indices[slice+1][index+1] != SO_END_FACE_INDEX)
					)
				{
					TfaceSet->coordIndex.set1Value(i++,m_indices[slice][index+1]);
					TfaceSet->coordIndex.set1Value(i++,m_indices[slice][index]);
					TfaceSet->coordIndex.set1Value(i++,m_indices[slice+1][index+1]);
					TfaceSet->coordIndex.set1Value(i++,SO_END_FACE_INDEX);
				}
				

			
			}
		}
	}

	S->addChild(TfaceSet);


	return S;

}

void CBodyAnalyserDoc::RenderCurvatureMap(int cam)
{
	m_Gaussian_Curvature_Material[cam]		= new SoMaterial;	m_Gaussian_Curvature_Material[cam]	->ref();
	m_Mean_Curvature_Material[cam]			= new SoMaterial;	m_Mean_Curvature_Material[cam]		->ref();	
	m_Curvedness_Material[cam]				= new SoMaterial;	m_Curvedness_Material[cam]			->ref();	
	m_ShapeIndex_Material[cam]				= new SoMaterial;	m_ShapeIndex_Material[cam]			->ref();

	int i = 0;
	int slice,index;

	int start = camera_start[cam];
	int finish = camera_end[cam];

	long double v,c;
	//long double r,g,b;
	long double h,s,l;

	long double V_SMALL = 8e-5;//5e-5;
	const long double twothirds = 2.0/3.0;

/*
	// thresholding factors - bls
	//long double t_g = 500000000.0;//gaussian	 
	long double t_m = 90.0;			//mean			
	long double t_c = 1.0;			//curvedness	
	long double t_s = 1.0;			//shape index	
*/
	// thresholding factors - hci (seem to work fine with bls too)
	//long double t_g = 500000.0;	//gaussian		
	//long double t_m = 900.0;		//mean			
	long double t_c = 1.0;			//curvedness	
	long double t_s = 1.0;			//shape index	

	// threshold values
	long double g_m1 = 0.0000005;//max_gaus_curv/t_g;		//gaussian curvature - positive 
	long double g_m2 = -0.0000005;//min_gaus_curv/t_g;		//gaussian curvature - negative
	long double m_m = 0.005;//max_mean_curv/t_m;			//mean curvature - absolute
	long double c_m1 = (2.0/PI)*log(max_curvedness)/t_c;	//curvedness - maximum
	long double c_m2 = (2.0/PI)*log(min_curvedness)/t_c;	//curvedness - minimum
	long double s_m1 =  1.0/t_s;							//shape index - positive
	long double s_m2 = -1.0/t_s;							//shape index - negative
	
	for(slice = 0; slice<N_SLICES; slice++)
	{
		for(index = start; index <= finish; index++)
		{
			if (m_indices[slice][index] != SO_END_FACE_INDEX)
			{
/*
				// GaussianCurvature - red to brown to green
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = m_curv_map[slice][index].K;
					if(v>=0.0)
					{
						if (v>g_m1)	{c = 0.5;}	else {c = (v/g_m1)/2.0;}
						r = 0.5 - c;
						g = 0.5 + c;
						b = 0.0;
					}
					else
					{
						if (v<g_m2)	{c = 0.5;}	else {c = (v/g_m2)/2.0;}
						r = 0.5 + c;
						g = 0.5 - c;
						b = 0.0;
					}
				}
				else {r = g = b = 0;}
				m_Gaussian_Curvature_Material[cam]->diffuseColor.set1Value(i, r,g,b);
*/
				// GaussianCurvature - rainbow spectrum
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = m_curv_map[slice][index].K;
					c = twothirds - twothirds*((v-g_m2)/(g_m1-g_m2));
					if (v>g_m1)	{c = 0.0;}
					if (v<g_m2)	{c = twothirds;}
					h = c;
					s = 1.0;
					l = 0.5;
				}
				else {h = s = l = 0;}
				m_Gaussian_Curvature_Material[cam]->diffuseColor.set1HSVValue(i, h,s,l);

/*
				// MeanCurvature - blue to red
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = fabs(m_curv_map[slice][index].H);
					if (v>m_m) {c = 0.0;} else {c = 1.0 - (v/m_m);}
					r = 1.0-c;
					g = 0.0;
					b = c;
					// next line for debugging only, shows the genuinely middle values
					//if( (c<0.25)||(c>0.75) ) {r=g=b=1.0;}
				}
				else {r = g = b = 0.0;}
				m_Mean_Curvature_Material[cam]->diffuseColor.set1Value(i, r,g,b);
*/
				// MeanCurvature - rainbow spectrum
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = fabs(m_curv_map[slice][index].H);
					if (v>m_m) {c = 0.0;} else {c = twothirds-(v/m_m)*twothirds;}
					h = c;
					s = 1.0;
					l = 0.5;
				}
				else {h = s = v = 0.0;}
				m_Mean_Curvature_Material[cam]->diffuseColor.set1HSVValue(i, h,s,l);

/*
				// Curvedness - blue to red
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = m_curv_map[slice][index].C;
					if (m_curv_map[slice][index].R == 0) {v=c_m2;}
					c = 1.0 - ((v-c_m2)/(c_m1-c_m2));
					r = 1.0-c;
					g = 0.0;
					b = c;
				}
				else {r = g = b = 0.0;}
				m_Curvedness_Material[cam]->diffuseColor.set1Value(i, r,g,b);
*/
				// Curvedness - rainbow spectrum
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = m_curv_map[slice][index].C;
					if (m_curv_map[slice][index].R == 0) {v=c_m2;}
					c = twothirds - twothirds*((v-c_m2)/(c_m1-c_m2));
					h = c;
					s = 1.0;
					l = 0.5;
				}
				else {h = s = l = 0.0;}
				m_Curvedness_Material[cam]->diffuseColor.set1HSVValue(i, h,s,l);
/*
				// Shape Index - red to brown to green
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = m_curv_map[slice][index].S;
					if(v>=0.0)
					{
						c = (v/s_m1)/2.0;
						r = 0.5 - c;
						g = 0.5 + c;
						b = 0;
					}
					else
					{
						c = (v/s_m2)/2.0;
						r = 0.5 + c;
						g = 0.5 - c;
						b = 0;
					}
					if ( (m_curv_map[slice][index].k1==0.0) && (m_curv_map[slice][index].k2==0.0) ) 
					{r = g = b = 1.0;}//flat umbilic
				}
				else {r = g = b = 0.0;}
				m_ShapeIndex_Material[cam]->diffuseColor.set1Value(i, r,g,b);
*/
				// Shape Index - red to brown to green
				if(m_curv_map[slice][index].exists==TRUE)
				{
					v = m_curv_map[slice][index].S;
					c = twothirds - twothirds*((v-s_m2)/(s_m1-s_m2));
					//if (v>s_m1)	{c = 0.0;}
					//if (v<s_m2)	{c = twothirds;}
					h = c;
					s = 1.0;
					l = 0.5;
					if ( (fabs(m_curv_map[slice][index].k1)<V_SMALL) && (fabs(m_curv_map[slice][index].k2)<V_SMALL) ) 
					{s = l = 1.0;}//flat umbilic
				}
				else {h = s = l = 0.0;}
				m_ShapeIndex_Material[cam]->diffuseColor.set1HSVValue(i, h,s,l);

				i++;
			}
		}
	}
}

SoSeparator* CBodyAnalyserDoc::RenderCurvatureDirections()
{
	SoSeparator* S = new SoSeparator;
	SoSeparator* SU = new SoSeparator;		S->addChild(SU);
	SoSeparator* SR = new SoSeparator;		S->addChild(SR);
	SoSeparator* SB = new SoSeparator;		S->addChild(SB);
	int slice,index;
	long double f = 100.0;

	// Adding Materials

	SU->addChild(m_CurvDir_NearUmbilics_DrawStyle);
	SR->addChild(m_CurvDir_Red_DrawStyle);
	SB->addChild(m_CurvDir_Blue_DrawStyle);
	
	SoMaterial *coordOriginColor = new SoMaterial;
	SoMaterial *coordOriginColorRed = new SoMaterial;
	SoMaterial *coordOriginColorBlue = new SoMaterial;
	
	coordOriginColor->diffuseColor.setValue(0.6, 0.0, 0.6); // dark purple
	coordOriginColorRed->diffuseColor.setValue(1.0, 0.0, 0.0); // red
	coordOriginColorBlue->diffuseColor.setValue(0.0, 0.0, 1.0); //  blue

	SU->addChild(coordOriginColor);
	SR->addChild(coordOriginColorRed);
	SB->addChild(coordOriginColorBlue);

	for(slice = 0; slice<N_SLICES; slice++)
	{
		for(index = 0; index < (N_CAMERAS*N_LEDS); index++)						
		{
			if (m_curv_map[slice][index].exists == TRUE)
			{
				SoSeparator* L1 = new SoSeparator;
				SoCoordinate3 *Lvertices1 = new SoCoordinate3;
				SbVec3f curvdir1 = SbVec3f(	m_curv_map[slice][index].v1[0],
											m_curv_map[slice][index].v1[1],
											m_curv_map[slice][index].v1[2]);
				Lvertices1->point.set1Value(0, m_xyz_array[slice][index]-curvdir1*f);
				Lvertices1->point.set1Value(1, m_xyz_array[slice][index]+curvdir1*f);			
				SoLineSet *lines1 = new SoLineSet;
				L1->addChild(Lvertices1);
				L1->addChild(lines1);

				SoSeparator* L2 = new SoSeparator;
				SoCoordinate3 *Lvertices2 = new SoCoordinate3;
				SbVec3f curvdir2 = SbVec3f(	m_curv_map[slice][index].v2[0],
											m_curv_map[slice][index].v2[1],
											m_curv_map[slice][index].v2[2]);
				Lvertices2->point.set1Value(0, m_xyz_array[slice][index]-curvdir2*f);
				Lvertices2->point.set1Value(1, m_xyz_array[slice][index]+curvdir2*f);			
				SoLineSet *lines2 = new SoLineSet;
				L2->addChild(Lvertices2);
				L2->addChild(lines2);

				switch(m_curv_map[slice][index].redlabel)
				{
				case 0:
					SU->addChild(L1);
					SU->addChild(L2);
					break;
				case 1:
					SR->addChild(L1);
					SB->addChild(L2);
					break;
				case 2:
					SB->addChild(L1);
					SR->addChild(L2);
					break;
				default:
					break;
				}
			}
		}
	}

	return S;
}


// --------------------- responses to toggle view events -------------------------

void CBodyAnalyserDoc::SetDisplayProperties(int component)
{
	switch (component)
	{
	case POINT_CLOUD:
			if (m_showPointCloud==TRUE)		
			{m_PointCloud_DrawStyle->style.setValue(SoDrawStyle::POINTS);}
			else	
			{m_PointCloud_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case OUTLIER_CLOUD:
			if (m_showOutlierCloud==TRUE)		
			{m_OutlierCloud_DrawStyle->style.setValue(SoDrawStyle::POINTS);}
			else	
			{m_OutlierCloud_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case COORD_ORIGIN:
			if (m_showCoordOrigin==TRUE)	
			{m_CoordOrigin_DrawStyle->style.setValue(SoDrawStyle::LINES);}
			else	
			{m_CoordOrigin_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case REF_FRAME:
			if (m_showRefFrame==TRUE)		
			{m_RefFrame_DrawStyle->style.setValue(SoDrawStyle::LINES);}
			else	
			{m_RefFrame_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case TEXTURE_EDGELS:
			if (m_showTextureEdgels==TRUE)		
			{m_TextureEdgels_DrawStyle->style.setValue(SoDrawStyle::FILLED);}//filled!
			else	
			{m_TextureEdgels_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case RIDGES:
			if (m_showRidges==TRUE)		
			{m_Ridges_DrawStyle->style.setValue(SoDrawStyle::FILLED);}//filled!
			else	
			{m_Ridges_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case FLEXCORDS:
			if (m_showFlexcords==TRUE)		
			{m_Flexcords_DrawStyle->style.setValue(SoDrawStyle::FILLED);}//filled!
			else	
			{m_Flexcords_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CURV_DIR:
			if (m_showCurvatureDirections==TRUE)		
			{m_CurvDir_NearUmbilics_DrawStyle->style.setValue(SoDrawStyle::LINES);}
			else	
			{m_CurvDir_NearUmbilics_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CURV_DIR_RED:
			if (m_showCurvatureDirectionsRed==TRUE)		
			{m_CurvDir_Red_DrawStyle->style.setValue(SoDrawStyle::LINES);}
			else	
			{m_CurvDir_Red_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CURV_DIR_BLUE:
			if (m_showCurvatureDirectionsBlue==TRUE)		
			{m_CurvDir_Blue_DrawStyle->style.setValue(SoDrawStyle::LINES);}
			else	
			{m_CurvDir_Blue_DrawStyle->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CURV_DIR_ALL:
			m_CurvDir_NearUmbilics_DrawStyle	-> style.setValue(SoDrawStyle::LINES);
			m_CurvDir_Red_DrawStyle				-> style.setValue(SoDrawStyle::LINES);
			m_CurvDir_Blue_DrawStyle			-> style.setValue(SoDrawStyle::LINES);
		break;
	case CURV_DIR_NONE:
			m_CurvDir_NearUmbilics_DrawStyle	-> style.setValue(SoDrawStyle::INVISIBLE);
			m_CurvDir_Red_DrawStyle				-> style.setValue(SoDrawStyle::INVISIBLE);
			m_CurvDir_Blue_DrawStyle			-> style.setValue(SoDrawStyle::INVISIBLE);
		break;
	case PHOTOREALISTIC:
			if (m_showPhotorealistic==TRUE)		
			{m_LightModel->model.setValue(SoLightModel::PHONG);}
			else	
			{m_LightModel->model.setValue(SoLightModel::BASE_COLOR);}
		break;
	case CONNECTED_0:
			if (m_showConnected_0==TRUE)		
			{m_Connected_DrawStyle_0->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_0->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_1:
			if (m_showConnected_1==TRUE)		
			{m_Connected_DrawStyle_1->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_1->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_2:
			if (m_showConnected_2==TRUE)		
			{m_Connected_DrawStyle_2->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_2->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_3:
			if (m_showConnected_3==TRUE)		
			{m_Connected_DrawStyle_3->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_3->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_4:
			if (m_showConnected_4==TRUE)		
			{m_Connected_DrawStyle_4->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_4->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_5:
			if (m_showConnected_5==TRUE)		
			{m_Connected_DrawStyle_5->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_5->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_6:
			if (m_showConnected_6==TRUE)		
			{m_Connected_DrawStyle_6->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_6->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_7:
			if (m_showConnected_7==TRUE)		
			{m_Connected_DrawStyle_7->style.setValue(SoDrawStyle::FILLED);}
			else	
			{m_Connected_DrawStyle_7->style.setValue(SoDrawStyle::INVISIBLE);}
		break;
	case CONNECTED_ALL:
			m_Connected_DrawStyle_0->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_1->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_2->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_3->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_4->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_5->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_6->style.setValue(SoDrawStyle::FILLED);
			m_Connected_DrawStyle_7->style.setValue(SoDrawStyle::FILLED);
		break;
	case CONNECTED_NONE:
			m_Connected_DrawStyle_0->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_1->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_2->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_3->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_4->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_5->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_6->style.setValue(SoDrawStyle::INVISIBLE);
			m_Connected_DrawStyle_7->style.setValue(SoDrawStyle::INVISIBLE);
		break;
	default:
		break;
	}//switch

}

// --------------------- responses to toggle view events -------------------------

void CBodyAnalyserDoc::OnViewPointcloud() 
{
	m_showPointCloud = (!m_showPointCloud);
	SetDisplayProperties(POINT_CLOUD);
}

void CBodyAnalyserDoc::OnViewOutliercloud() 
{
	m_showOutlierCloud = (!m_showOutlierCloud);
	SetDisplayProperties(OUTLIER_CLOUD);
}

void CBodyAnalyserDoc::OnViewCoordinateorigin() 
{
	m_showCoordOrigin = (!m_showCoordOrigin);
	SetDisplayProperties(COORD_ORIGIN);
}
void CBodyAnalyserDoc::OnViewReferenceframe() 

{
	m_showRefFrame = (!m_showRefFrame);
	SetDisplayProperties(REF_FRAME);
}

void CBodyAnalyserDoc::OnViewConnectedmeshPhotorealistic() 
{
	m_showPhotorealistic = (!m_showPhotorealistic);
	SetDisplayProperties(PHOTOREALISTIC);
}


void CBodyAnalyserDoc::OnViewConnectedmeshCamera0() 
{
	m_showConnected_0 = (!m_showConnected_0);
	SetDisplayProperties(CONNECTED_0);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera1() 
{
	m_showConnected_1 = (!m_showConnected_1);
	SetDisplayProperties(CONNECTED_1);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera2() 
{
	m_showConnected_2 = (!m_showConnected_2);
	SetDisplayProperties(CONNECTED_2);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera3() 
{
	m_showConnected_3 = (!m_showConnected_3);
	SetDisplayProperties(CONNECTED_3);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera4() 
{
	m_showConnected_4 = (!m_showConnected_4);
	SetDisplayProperties(CONNECTED_4);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera5() 
{
	m_showConnected_5 = (!m_showConnected_5);
	SetDisplayProperties(CONNECTED_5);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera6() 
{
	m_showConnected_6 = (!m_showConnected_6);
	SetDisplayProperties(CONNECTED_6);
}

void CBodyAnalyserDoc::OnViewConnectedmeshCamera7() 
{
	m_showConnected_7 = (!m_showConnected_7);
	SetDisplayProperties(CONNECTED_7);
}

void CBodyAnalyserDoc::OnViewConnectedmeshAll() 
{
	m_showConnected_0 = TRUE;
	m_showConnected_1 = TRUE;
	m_showConnected_2 = TRUE;
	m_showConnected_3 = TRUE;
	m_showConnected_4 = TRUE;
	m_showConnected_5 = TRUE;
	m_showConnected_6 = TRUE;
	m_showConnected_7 = TRUE;
	SetDisplayProperties(CONNECTED_ALL);
}


void CBodyAnalyserDoc::OnViewConnectedmeshNone() 
{
	m_showConnected_0 = FALSE;
	m_showConnected_1 = FALSE;
	m_showConnected_2 = FALSE;
	m_showConnected_3 = FALSE;
	m_showConnected_4 = FALSE;
	m_showConnected_5 = FALSE;
	m_showConnected_6 = FALSE;
	m_showConnected_7 = FALSE;
	SetDisplayProperties(CONNECTED_NONE);
}

void CBodyAnalyserDoc::OnViewCurvaturedirections() 
{
	m_showCurvatureDirections = (!m_showCurvatureDirections);
	SetDisplayProperties(CURV_DIR);
}

void CBodyAnalyserDoc::OnViewCurvaturedirectionsBlue() 
{
	m_showCurvatureDirectionsBlue = (!m_showCurvatureDirectionsBlue);
	SetDisplayProperties(CURV_DIR_BLUE);
}

void CBodyAnalyserDoc::OnViewCurvaturedirectionsRed() 
{
	m_showCurvatureDirectionsRed = (!m_showCurvatureDirectionsRed);
	SetDisplayProperties(CURV_DIR_RED);
}

void CBodyAnalyserDoc::OnViewCurvaturedirectionsAll() 
{
	m_showCurvatureDirections		= TRUE;
	m_showCurvatureDirectionsRed	= TRUE;
	m_showCurvatureDirectionsBlue	= TRUE;
	SetDisplayProperties(CURV_DIR_ALL);
}


void CBodyAnalyserDoc::OnViewCurvaturedirectionsNone() 
{
	m_showCurvatureDirections		= FALSE;
	m_showCurvatureDirectionsRed	= FALSE;
	m_showCurvatureDirectionsBlue	= FALSE;
	SetDisplayProperties(CURV_DIR_NONE);
}

// --------------------- menu updators --------------------------------------------

void CBodyAnalyserDoc::OnUpdateViewPointcloud(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showPointCloud);
}

void CBodyAnalyserDoc::OnUpdateViewOutliercloud(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showOutlierCloud);
}

void CBodyAnalyserDoc::OnUpdateViewCoordinateorigin(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showCoordOrigin);
}

void CBodyAnalyserDoc::OnUpdateViewReferenceframe(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showRefFrame);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshPhotorealistic(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showPhotorealistic);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera0(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_0);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera1(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_1);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera2(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_2);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera3(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_3);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera4(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_4);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera5(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_5);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera6(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_6);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshCamera7(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_showConnected_7);
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshNone(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshAll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
}

void CBodyAnalyserDoc::OnUpdateViewCurvaturedirections(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
	pCmdUI->SetCheck(m_showCurvatureDirections);
}

void CBodyAnalyserDoc::OnUpdateViewCurvaturedirectionsBlue(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
	pCmdUI->SetCheck(m_showCurvatureDirectionsBlue);
}

void CBodyAnalyserDoc::OnUpdateViewCurvaturedirectionsRed(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
	pCmdUI->SetCheck(m_showCurvatureDirectionsRed);
}

void CBodyAnalyserDoc::OnUpdateViewCurvaturedirectionsAll(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
}

void CBodyAnalyserDoc::OnUpdateViewCurvaturedirectionsNone(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
}

void CBodyAnalyserDoc::OnUpdateViewSymmetryplanesNone(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_SymmetryMode==SYM_MODE_NONE);
}

void CBodyAnalyserDoc::OnUpdateViewSymmetryplanesBody(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_SymmetryMode==SYM_MODE_BODY);
}

void CBodyAnalyserDoc::OnUpdateViewSymmetryplanesEllipsoid(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_SymmetryMode==SYM_MODE_ELLIPSOID);
}

void CBodyAnalyserDoc::OnUpdateViewSymmetryplanesToothcube(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_SymmetryMode==SYM_MODE_TOOTH);
}

void CBodyAnalyserDoc::OnUpdateViewSymmetryplanesOctahedrondiamond(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_SymmetryMode==SYM_MODE_OCTAHEDRON);
}

void CBodyAnalyserDoc::OnUpdateViewSymmetryplanesBumpyspheretetrahedron(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_SymmetryMode==SYM_MODE_BUMPY);
}

// ----------------------------------------------------------------------------------

void CBodyAnalyserDoc::CleanBody()
{
	Clean_Thresholding();
	Clean_FirstAndLast();
	Clean_SpatialCulling();
	Clean_ProximityTest();
	//Clean_BottomSlice();
}

void CBodyAnalyserDoc::Clean_Thresholding()
{
	int slice, index; 

	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
		{
			if (m_b_array[slice][index]<=INTENSITY_THRESHOLD) 
				{m_flag_array[slice][index]=REJECTED;}
		}
	}

}

void CBodyAnalyserDoc::Clean_FirstAndLast()
{
	int slice, index; 

	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
		{
			if (
				(index==camera_start[0]) || (index==camera_end[0]) ||
				(index==camera_start[1]) || (index==camera_end[1]) ||
				(index==camera_start[2]) || (index==camera_end[2]) ||
				(index==camera_start[3]) || (index==camera_end[3]) ||
				(index==camera_start[4]) || (index==camera_end[4]) ||
				(index==camera_start[5]) || (index==camera_end[5]) ||
				(index==camera_start[6]) || (index==camera_end[6]) ||
				(index==camera_start[7]) || (index==camera_end[7])
				) 
				{m_flag_array[slice][index]=REJECTED;}
		}
	}


}

void CBodyAnalyserDoc::Clean_SpatialCulling()
{
	int slice, index; 
	float x,y,z;

	int f = GLOBAL_SCALING_FACTOR;
	float lowlim = -490.0*f;
	float highlim = 490.0*f;

	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
		{
			if (m_flag_array[slice][index] == ACCEPTED)
			{
				m_xyz_array[slice][index].getValue(x,y,z);

				if 
					(
						(x<lowlim) || (x>highlim) ||
	
						(z<lowlim) || (z>highlim) 
					)
					{m_flag_array[slice][index]=REJECTED;}
			}
		}
	}
}

void CBodyAnalyserDoc::Clean_ProximityTest()
{
	for(int slice = 0; slice < N_SLICES; slice++)	
	{
		Clean_Slice(slice);
		if(slice > (N_SLICES-3)) {Clean_BottomSlice(slice);}
	}
}

void CBodyAnalyserDoc::Clean_Slice(int s)
{
	float min_dist, temp_dist;
	float x1, y1, z1;
	float x2, y2, z2;

	for(int i = 0; i<(N_CAMERAS*N_LEDS); i++)
	{
		if(m_flag_array[s][i]!=REJECTED)
		{
			m_xyz_array[s][i].getValue(x1,y1,z1);
			min_dist=99999.9;
			for(int j = 0; j<(N_CAMERAS*N_LEDS); j++)
			{
				if( (i<j) && (m_flag_array[s][j]!=REJECTED) )
				{
					m_xyz_array[s][j].getValue(x2,y2,z2);
					temp_dist = EucDist3D(x1,y1,z1,x2,y2,z2);
					if(temp_dist<min_dist) {min_dist = temp_dist;}
				}
			}
			if(min_dist>DISTANCE_THRESHOLD) {m_flag_array[s][i]=REJECTED;}
		}
	}
}

void CBodyAnalyserDoc::Clean_BottomSlice(int s)
{
	float min_dist, temp_dist;
	float x1, y1, z1;
	float x2, y2, z2;

	for(int i = 0; i<(N_CAMERAS*N_LEDS); i++)
	{
		if(m_flag_array[s][i]!=REJECTED)
		{
			m_xyz_array[s][i].getValue(x1,y1,z1);
			min_dist=99999.9;
			for(int j = 0; j<(N_CAMERAS*N_LEDS); j++)
			{
				if(m_flag_array[s-1][j]!=REJECTED)
				{
					m_xyz_array[s-1][j].getValue(x2,y2,z2);
					temp_dist = EucDist3D(x1,y1,z1,x2,y2,z2);
					if(temp_dist<min_dist) {min_dist = temp_dist;}
				}
			}
			if(min_dist>DISTANCE_THRESHOLD) {m_flag_array[s][i]=REJECTED;}
		}
	}

}


//------CAMERA IMAGE GENERATION-------------------------------------------------------

void CBodyAnalyserDoc::CreateCameraImages()
{
	int slice, index, camera, gscale;; 

	int null_r = 120;
	int null_g = 150;
	int null_b = 220;

	float x,y,z;

	ofstream cam_img_file;

	cam_img_file.open("cam_imgs.hci");

	cam_img_file	<< N_CAMERAS << "\n" 
					<< N_LEDS << " " << N_SLICES << "\n" 
					<< N_GSCALES << " "<< N_CHANNELS << "\n";

	for(camera = 0; camera < N_CAMERAS; camera++)
	{
		for(slice = 0; slice < N_SLICES; slice++)
		{
			for(index = 0; index < N_LEDS; index++)  
			{
				if (m_flag_array[slice][index+(camera*N_LEDS)] == ACCEPTED)
				{ 
					m_xyz_array[slice][index+(camera*N_LEDS)].getValue(x,y,z);
					gscale = m_b_array[slice][index+(camera*N_LEDS)];
					cam_img_file << x << " " << y << " " << z << " " << gscale << "\n";
				}
				else
				{ 
					cam_img_file << 0 << " " << 0 << " " << 0 << " " << -1 << "\n"; 
				}
			}
		}
		
		cam_img_file << "\n";
	}

	cam_img_file.close();
}


//---------------- NORMALS -----------------------------------------------------------

void CBodyAnalyserDoc::CalculateNormals()
{
// also assigns an index number to every valid point that is
// associated to at least one triangle

	int slice,index;
	int start,finish;
	int camera;

	float x,y,z;	//current point
	float x1,y1,z1;
	float x2,y2,z2;
	float xn,yn,zn; //current normal
	float xs,ys,zs; //sum of normals
	
	int n_adjacent_faces;

	for(camera = 0; camera < N_CAMERAS; camera++)
	{
		start  = camera_start[camera];
		finish = camera_end[camera];

		valid_point_counter[camera] = 0;

		for(slice = 0; slice < N_SLICES; slice++)
		{
			for(index = start; index <= finish; index++)
			{
				if(m_flag_array[slice][index]!=REJECTED)
				{
					m_xyz_array[slice][index].getValue(x,y,z);
					
					n_adjacent_faces = xs = ys = zs = 0;
					
					//    2 3
					//   1   4
					//
					//   8   5
					//    7 6

					// 1
					if ( 
						( slice!=0 ) &&
						( index>start) &&
						( m_flag_array[slice-1][index-1]!=REJECTED ) &&
						( m_flag_array[slice][index-1]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice-1][index-1].getValue(x1,y1,z1);
						m_xyz_array[slice][index-1].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 2
					if ( 
						( slice!=0 ) &&
						( index>start) &&
						( m_flag_array[slice-1][index]!=REJECTED ) &&
						( m_flag_array[slice-1][index-1]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice-1][index].getValue(x1,y1,z1);
						m_xyz_array[slice-1][index-1].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 3
					if ( 
						( slice!=0 ) &&
						( index<finish) &&
						( m_flag_array[slice-1][index+1]!=REJECTED ) &&
						( m_flag_array[slice-1][index]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice-1][index+1].getValue(x1,y1,z1);
						m_xyz_array[slice-1][index].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 4
					if ( 
						( slice!=0 ) &&
						( index<finish) &&
						( m_flag_array[slice][index+1]!=REJECTED ) &&
						( m_flag_array[slice-1][index+1]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice][index+1].getValue(x1,y1,z1);
						m_xyz_array[slice-1][index+1].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 5
					if ( 
						( slice!=N_SLICES ) &&
						( index<finish) &&
						( m_flag_array[slice+1][index+1]!=REJECTED ) &&
						( m_flag_array[slice][index+1]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice+1][index+1].getValue(x1,y1,z1);
						m_xyz_array[slice][index+1].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 6
					if ( 
						( slice!=N_SLICES ) &&
						( index<finish) &&
						( m_flag_array[slice+1][index]!=REJECTED ) &&
						( m_flag_array[slice+1][index+1]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice+1][index].getValue(x1,y1,z1);
						m_xyz_array[slice+1][index+1].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 7
					if ( 
						( slice!=N_SLICES ) &&
						( index>start) &&
						( m_flag_array[slice+1][index-1]!=REJECTED ) &&
						( m_flag_array[slice+1][index]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice+1][index-1].getValue(x1,y1,z1);
						m_xyz_array[slice+1][index].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// 8
					if ( 
						( slice!=N_SLICES ) &&
						( index>start) &&
						( m_flag_array[slice+1][index-1]!=REJECTED ) &&
						( m_flag_array[slice+1][index]!=REJECTED ) 
						)
					{
						n_adjacent_faces++;

						m_xyz_array[slice][index-1].getValue(x1,y1,z1);
						m_xyz_array[slice+1][index-1].getValue(x2,y2,z2);

						CrossProduct(	x-x1,	y-y1,	z-z1,
										x1-x2,	y1-y2,	z1-z2,
										xn,		yn,		zn);

						xs += xn;
						ys += yn;
						zs += zn;
					}

					// associate index number if valid
					if (n_adjacent_faces > 0)
					{
						m_indices[slice][index] = valid_point_counter[camera];
						valid_point_counter[camera]++;
					}
					else
					{
						m_indices[slice][index] = SO_END_FACE_INDEX;
					}

					// average
					xs /= n_adjacent_faces;
					ys /= n_adjacent_faces;
					zs /= n_adjacent_faces;
				

					// normalise
					normaliseVector(xs,ys,zs);

					// assign vector value
					m_norm_array[slice][index].setValue(xs,ys,zs);

				}// end processing point
			}//end index
		}//end slice
	}//end camera
}

//-------------- AUXILIARY FUNCTIONS -------------------------------------------

/*
float CBodyAnalyserDoc::eucDist(float x1, float y1, float z1, float x2, float y2, float z2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	float dz = z1 - z2;
	float result = sqrt( (dx*dx) + (dy*dy) + (dz*dz) );
	return result;
}
*/

void CBodyAnalyserDoc::normaliseVector(float& x, float& y, float& z)
{
	float m = Magnitude(x,y,z);
	if (m>0)
	{
		x /= m;
		y /= m;
		z /= m;
	}
	else
	{
		x = y = z = 0.0;
	}
}

/*
float CBodyAnalyserDoc::vectorMagnitude(float x, float y, float z)
{
	float m = EucDist3D(x,y,z,0.0,0.0,0.0);
	return m;
}
*/




float CBodyAnalyserDoc::Gauss2D(float x, float y, float s)
{
	float xpr1 = ((x*x) + (y*y)) / (2*s*s);
	float xpr2 = exp(-xpr1);
	float xpr3 = 1.0/(2*PI*s*s);
	return xpr3*xpr2;
}

void CBodyAnalyserDoc::Convolve(SbVec3f data_in[MAX_N_SLICES+6][MAX_N_LEDS+6], float m[7][7], SbVec3f data_out[MAX_N_SLICES+6][MAX_N_LEDS+6], unsigned char flags[MAX_N_SLICES+6][MAX_N_LEDS+6])
{
	int i,j;
	float s;
	float x1,y1,z1,x2,y2,z2;

	for (int slice = 3; slice < N_SLICES+3; slice++)		
	{
		for (int index = 3; index < N_LEDS+3; index++)
		{
			if(flags[slice][index] != REJECTED)
			{

				float accX = 0.0;
				float accY = 0.0;
				float accZ = 0.0;
				float x,y,z;	
				
				s = 0.0;

				for(i = -3; i < 4; i++)
				{
					for(j = -3; j < 4; j++)
					{
						data_in[slice][index].getValue(x1,y1,z1);
						data_in[slice+i][index+j].getValue(x2,y2,z2);

						if(
							(flags[slice+i][index+j] != REJECTED) &&
							(EucDist3D(x1,y1,z1,x2,y2,z2) < (DISTANCE_THRESHOLD))
							)
						{
							data_in[slice+i][index+j].getValue(x,y,z);
					
							float pX = m[i+3][j+3] * x;
							float pY = m[i+3][j+3] * y;
							float pZ = m[i+3][j+3] * z;

							accX += pX;
							accY += pY;
							accZ += pZ;

							s += m[i+3][j+3];
						}
					}
				}
	
				data_out[slice][index] = SbVec3f(accX/s,accY/s,accZ/s);
		
			}
		}
	}
}


// ------ PROCESSING TOOLS --------------------------------------


void CBodyAnalyserDoc::OnToolsCameraImager() 
{
	HINSTANCE CIV = ShellExecute(	
						NULL,
						"open", 
						camviewerpath,
						NULL,
						NULL,
						SW_SHOW);
}

void CBodyAnalyserDoc::OnToolsSurfacesmoothing() 
{
	int s,i,j;
//	float x,y,z;

	CConfirmDialog cdlg;
	if (cdlg.DoModal() == IDOK)

for(int qwer = 0; qwer < 2; qwer++)
{

	{//SMOOTHING
				
		HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		// create temporary result arrays

		SbVec3f* m_r_array[MAX_N_SLICES];			// Cartesian coordinates
		for (s=0; s<N_SLICES; s++)		{m_r_array[s] = new SbVec3f[N_CAMERAS*N_LEDS];}

		// build gaussian convolution mask
		const int mask_size_factor = 1;
		const int mask_size = (mask_size_factor*6) + 1;
		float mask[mask_size][mask_size];
		float sigma = mask_size / 120.0;
		float start = -4.0 * sigma;
		float step = -(2.0*start)/(mask_size-1);
		for(i = 0; i < mask_size; i++)
		{
			for(j = 0; j < mask_size; j++)
			{
				mask[i][j] = Gauss2D(start+(i*step),start+(j*step),sigma);
			}
		}
				
		// render mask (temporary - remove later)
		//SoSeparator* gm = new SoSeparator;
		//gm = RenderGaussMask(mask);
		//root->addChild(gm);

		// convolve
		
		SbVec3f temp_in[MAX_N_SLICES+6][MAX_N_LEDS+6];
		SbVec3f temp_out[MAX_N_SLICES+6][MAX_N_LEDS+6];
		unsigned char flags_in[MAX_N_SLICES+6][MAX_N_LEDS+6];

		for(i = 0; i < MAX_N_SLICES+6; i++)
		{
			for(j = 0; j < MAX_N_LEDS+6; j++)
			{
				flags_in[i][j] = REJECTED;
				temp_in[i][j] = SbVec3f(0.0,0.0,0.0);
			}
		}
		
		int st,en;

		for(int cam = 0; cam < N_CAMERAS; cam++)
		{
			st = cam * N_LEDS;
			en = ((cam+1)*N_LEDS)-1;

			// copy sub-image to temporary array
			for(i = 3; i < N_SLICES+3; i++)
			{
				for(j = 3; j < N_LEDS+3; j++)
				{
					temp_in[i][j] = m_xyz_array[i-3][j-3+st];
					flags_in[i][j] = m_b_array[i-3][j-3+st];
				}
			}

			// call the convolution function
			Convolve(temp_in,mask,temp_out, flags_in);

			// copy resulting temporary array to result array
			for(i = 3; i < N_SLICES+3; i++)
			{
				for(j = 3; j < N_LEDS+3; j++)
				{
					m_r_array[i-3][j-3+st] = temp_out[i][j];
				}
			}

		}

		// copy result arrays to point arrays
		for (s=0; s<N_SLICES; s++)		
		{
			for (i=0; i<(N_CAMERAS*N_LEDS); i++)
			{
				m_xyz_array[s][i] = m_r_array[s][i];
			}
		}

		// delete result arrays
		for (s=0; s<N_SLICES; s++)		{delete m_r_array[s];}

		// re-render
		CalculateNormals();
		for(j = 0; j < N_CAMERAS; j++)
		{	
			smooth_triangMesh[j] = new SoSeparator;
			smooth_triangMesh[j] = RenderTriangMesh(j);
			root->replaceChild(s_triangMesh[j], smooth_triangMesh[j]);
			s_triangMesh[j] = smooth_triangMesh[j];
		}


		HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);

	}
}	
m_surface_smoothed = TRUE;
}

void CBodyAnalyserDoc::OnToolsTextureedgedetector() 
{

	long double curr_image[MAX_IMAGE_X][MAX_IMAGE_Y];
	BOOL curr_edges[MAX_IMAGE_X][MAX_IMAGE_Y];
	
	CCannyParamsDialog m_cpd;
	m_cpd.m_masksize = c_gmask;
	m_cpd.m_upper_threshold = c_uhthr;
	m_cpd.m_lower_threshold = c_lhthr;

	if(m_cpd.DoModal()==IDOK)
	{
		c_gmask = m_cpd.m_masksize;
		c_uhthr = m_cpd.m_upper_threshold;
		c_lhthr = m_cpd.m_lower_threshold;

	
		HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
		SetCursor(waitCursor);

		int led;

		for(int i = 0; i < N_CAMERAS; i++)
		{
			//copy out the current image
			int st_ndx = i * N_LEDS;
			int en_ndx = ((i+1)*N_LEDS)-1;

			for(led = 0; led < N_LEDS; led++)
			{
				for(int slice = 0; slice < N_SLICES; slice++)
				{
					curr_image[led][slice] = (long double)m_b_array[slice][led+st_ndx];
				}
			}

			//call the canny function
			CannyEdgeDetector(&curr_image, &curr_edges, N_LEDS, N_SLICES, c_gmask, c_lhthr, c_uhthr);

			//copy results back
			for(led = 0; led < N_LEDS; led++)
			{
				for(int slice = 0; slice < N_SLICES; slice++)
				{
					m_edge_array[slice][led+st_ndx] = curr_edges[led][slice];

					//remove this when done
					m_b_array[slice][led+st_ndx] = (unsigned char)curr_image[led][slice];
				}
			}
		}

		//rendering the results
		if(m_texture_edges_detected)	
		{	
			SoSeparator* newEdgels = new SoSeparator;
			newEdgels = RenderTextureEdgels();
			root->replaceChild(s_textureEdgels,newEdgels);
			s_textureEdgels = newEdgels;
		}
		else
		{
			s_textureEdgels = new SoSeparator;
			s_textureEdgels = RenderTextureEdgels();
			root->addChild(s_textureEdgels);
		}

		//setting display properties
		m_showTextureEdgels = TRUE;
		m_texture_edges_detected = TRUE;	

		HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
		SetCursor(arrowCursor);
	}

}

void CBodyAnalyserDoc::OnUpdateToolsTextureedgedetector(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CBodyAnalyserDoc::OnUpdateViewConnectedmeshTextureedgels(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_texture_edges_detected);
	pCmdUI->SetCheck(m_showTextureEdgels);
}

void CBodyAnalyserDoc::OnUpdateViewRidges(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
	pCmdUI->SetCheck(m_showRidges);
}

void CBodyAnalyserDoc::OnUpdateViewFlexcords(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_curv_map_calculated);
	pCmdUI->SetCheck(m_showFlexcords);
}



void CBodyAnalyserDoc::OnViewConnectedmeshTextureedgels() 
{
	m_showTextureEdgels = (!m_showTextureEdgels);
	SetDisplayProperties(TEXTURE_EDGELS);
}

void CBodyAnalyserDoc::OnViewRidges() 
{
	m_showRidges = (!m_showRidges);
	SetDisplayProperties(RIDGES);
}

void CBodyAnalyserDoc::OnViewFlexcords() 
{
	m_showFlexcords = (!m_showFlexcords);
	SetDisplayProperties(FLEXCORDS);
}



void CBodyAnalyserDoc::OnViewSymmetryplanesBody() 
{
	m_SymmetryMode = SYM_MODE_BODY;
	for(int i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i]->style.setValue(SoDrawStyle::INVISIBLE);}
	m_Symmetry_DrawStyle[SYM_SZ]->style.setValue(SoDrawStyle::FILLED);
}

void CBodyAnalyserDoc::OnViewSymmetryplanesEllipsoid() 
{
	m_SymmetryMode = SYM_MODE_ELLIPSOID;
	for(int i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i]->style.setValue(SoDrawStyle::INVISIBLE);}
	m_Symmetry_DrawStyle[SYM_SX]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_SY]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_SZ]->style.setValue(SoDrawStyle::FILLED);
}

void CBodyAnalyserDoc::OnViewSymmetryplanesToothcube() 
{
	m_SymmetryMode = SYM_MODE_TOOTH;
	for(int i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i]->style.setValue(SoDrawStyle::FILLED);}
}

void CBodyAnalyserDoc::OnViewSymmetryplanesOctahedrondiamond() 
{
	m_SymmetryMode = SYM_MODE_OCTAHEDRON;
	for(int i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i]->style.setValue(SoDrawStyle::INVISIBLE);}
	m_Symmetry_DrawStyle[SYM_SX]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_SY]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_SZ]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_DY]->style.setValue(SoDrawStyle::FILLED);
}

void CBodyAnalyserDoc::OnViewSymmetryplanesBumpyspheretetrahedron() 
{
	m_SymmetryMode = SYM_MODE_BUMPY;
	for(int i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i]->style.setValue(SoDrawStyle::INVISIBLE);}
	m_Symmetry_DrawStyle[SYM_DX]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_DY]->style.setValue(SoDrawStyle::FILLED);
	m_Symmetry_DrawStyle[SYM_DZ]->style.setValue(SoDrawStyle::FILLED);
}

void CBodyAnalyserDoc::OnViewSymmetryplanesNone() 
{
	m_SymmetryMode = SYM_MODE_NONE;
	for(int i = 0; i < N_SYM_SETS; i++)	{m_Symmetry_DrawStyle[i]->style.setValue(SoDrawStyle::INVISIBLE);}
}



void CBodyAnalyserDoc::OnToolsHistogramequalisation() 
{

	HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
	SetCursor(waitCursor);

	int slice,index;
	float max = -999.0;
	float min = 9999.0;
	float val,newval;

	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < N_CAMERAS*N_LEDS; index++)
		{
			val = (float)m_b_array[slice][index];
			if(val>max) {max = val;}
			if(val<min) {min = val;}
		}
	}

	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < N_CAMERAS*N_LEDS; index++)
		{
			val = (float)m_b_array[slice][index];
			newval = (val/max)*255.0;
			m_b_array[slice][index] = (unsigned char)newval;
		}
	}

	//re-rendering
	for(int i = 0; i < N_CAMERAS; i++)
	{
		SoSeparator* newTex = new SoSeparator;
		newTex = RenderTriangMesh(i);
		root -> replaceChild(s_triangMesh[i],newTex);
		s_triangMesh[i] = newTex;
	}

	HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
	SetCursor(arrowCursor);
}

void CBodyAnalyserDoc::OnUpdateToolsCurvaturemap(CCmdUI* pCmdUI) 
{
	//pCmdUI->Enable(m_surface_smoothed);
}

//----------------------------------------- NEW CURVATURE MAPPING FUNCTIONS

void CBodyAnalyserDoc::OnToolsCurvatureMap() 
{
  if(!m_curv_map_calculated)
  {
	HCURSOR waitCursor = theApp.LoadStandardCursor(IDC_WAIT);
	SetCursor(waitCursor);
	

	long double p_neigh[MAX_N_POINTS][3];// the array to store the point neighbourhood
	int neigh_size;
	CPointSet P;

	unsigned int slice;		// the current slice (main loop)
	unsigned int index;		// the current index (main loop)
	float p_x,p_y,p_z;		// coords of the current point in the main loop
	float t_x,t_y,t_z;		// coords of the current point in the search loop
	int s,i,j,k;			// the current slice and index for the search loop
	int st_ndx,en_ndx;		// index limit for the current sensor
	int st_s,en_s;			// slice range for the search loop 
	int st_i,en_i;			// index range for the search loop
	float d;				// distance between current points in main and search loops
	int cam;				// current sensor

	int radius = 5;			// 5
	int radstep = 1;		// 1

	int n;
	long double x,y,z;
	int ii,jj;

	//the auxiliary matrices
	const int N = 10;
	CFloatMatrix  u			= CFloatMatrix(N,1);
	CFloatMatrix uT			= CFloatMatrix(1,N);
	CFloatMatrix temp1		= CFloatMatrix(N,1);
	CFloatMatrix S			= CFloatMatrix(N,N);
	CSmallFloatMatrix x0	= CSmallFloatMatrix(4,1);
	CSmallFloatMatrix xx	= CSmallFloatMatrix();

	//intermediate matrices
	float mu[N];
	float mean[3];
	long double quadric_coeffs[10];
	float m_x[MAX_N_POINTS][3];

	CQuadricSurf m_qs;		//the surface patch
	CPointSet PP;

	unsigned int slice_offset = 0;			unsigned int slice_range = N_SLICES;
	unsigned int index_offset = 0;			unsigned int index_range = N_LEDS*N_CAMERAS;

// debug variables
	BOOL chuckout		= TRUE;
	BOOL chuckout2		= FALSE;
	BOOL ridge_chuckout	= TRUE;
	BOOL stinks;
	ofstream chuckout_file, chuckout_file2, stink_file, ridge_chuckout_file;
	int succ_points = 0;
	int void_points = 0;
	int fail_points = 0;
// end debug variables

	if(chuckout)	
	{
		chuckout_file.open("c:\\BA_Monitor\\BodyAnalyser_Differentials.csv",ios::out|ios::trunc);
		chuckout_file << "Quadric Coefficients from Hamamatsu Scan\n";
		chuckout_file << " Number of Slices:  " << N_SLICES << "\n";
		chuckout_file << "Number of Cameras:  " << N_CAMERAS << "\n";
		chuckout_file << "   Number of Leds:  " << N_LEDS << "\n\n";
		chuckout_file << "A zero row corresponds to a non-patch or non point (ignore it).\n\n";
		chuckout_file << "Eigenvalues, , , , , , , , , ,Coefficients, , , , , , , , , ,Point, , ,Closest, , ,k1,k2,d1, , ,d2\n";
	}
	stink_file.open("c:\\BA_Monitor\\BodyAnalyser_Errors.csv",ios::out|ios::trunc);
	stink_file << "Quadric Coefficients from Hamamatsu Scan\n";
	stink_file << " Number of Slices: " << N_SLICES << "\n";
	stink_file << "Number of Cameras: " << N_CAMERAS << "\n";
	stink_file << "   Number of Leds: " << N_LEDS << "\n\n";
	stink_file << "Check the end of the file for success statistics\n\n";

	if(chuckout2)	
	{
		chuckout_file2.open("c:\\BA_Monitor\\BodyAnalyser_Design_Matrices.csv",ios::out|ios::trunc);
		chuckout_file2 << "Quadric Coefficients from Hamamatsu Scan\n";
		chuckout_file2 << " Number of Slices:  " << N_SLICES << "\n";
		chuckout_file2 << "Number of Cameras:  " << N_CAMERAS << "\n";
		chuckout_file2 << "   Number of Leds:  " << N_LEDS << "\n";
	}

	for(slice = 0; slice < N_SLICES-1; slice++)
	{
		st_s = slice - radius; if (st_s < 0) {st_s = 0;}
		en_s = slice + radius; if (en_s >=N_SLICES) {en_s = N_SLICES-1;}

		if((slice%40)==0) {Beep(300,100);} //progress indicator

		for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
		{
			cam = index / N_LEDS;

			st_ndx = cam*N_LEDS;
			en_ndx = ((cam+1)*N_LEDS)-1;
			st_i = index - radius; if (st_i < st_ndx) {st_i = st_ndx;}
			en_i = index + radius; if (en_i > en_ndx) {en_i = en_ndx;}


			if( (m_flag_array[slice][index] != REJECTED)  
				&& (slice >= slice_offset)
				&& (slice < slice_offset + slice_range)
				&& (index >= index_offset)
				&& (index <= index_offset + index_range)
				)
			{
				m_xyz_array[slice][index].getValue(p_x,p_y,p_z);

				//select a number of points around m_xyz_array[slice][index]
				//(try DISTANCE_THRESHOLD)
				neigh_size = 0;

				for(s = st_s; s <= en_s; s+=radstep)
				{
					for(i = st_i; i <= en_i; i+=radstep)
					{
						if((m_flag_array[s][i] != REJECTED)&&(neigh_size<(46)) ) //(limitation due to matrix size)
						{
							m_xyz_array[s][i].getValue(t_x,t_y,t_z);
							d = EucDist3D(p_x,p_y,p_z,t_x,t_y,t_z);
							//if (d < (DISTANCE_THRESHOLD*4)) // for the hi-res bumpy umbilic
							if (d < (DISTANCE_THRESHOLD*1.7))
								// multiply by 1.7 for telmat torsos
							{
								p_neigh[neigh_size][0] = t_x;
								p_neigh[neigh_size][1] = t_y;
								p_neigh[neigh_size][2] = t_z;
								neigh_size++;
							}	//endif
						}	// endif - 
					}	//end looping by index
				}	// end looping by slice
				if(neigh_size >= 10) 
				{//calculate and export the covariance matrix

					//generate the point set
					P = CPointSet(neigh_size,&p_neigh);
					n = neigh_size;
					CFloatMatrix D = CFloatMatrix(n,N);
					P.Center();
					
					//building the design matrix
					for(ii=0; ii<n; ii++)
					{
						x = P.a[ii][0];
						y = P.a[ii][1];
						z = P.a[ii][2];

						D.set(ii,0,x*x);		
						D.set(ii,1,y*y);		
						D.set(ii,2,z*z);		
						D.set(ii,3,x*y);		
						D.set(ii,4,y*z);		
						D.set(ii,5,x*z);		
						D.set(ii,6,x);		
						D.set(ii,7,y);		
						D.set(ii,8,z);		
						D.set(ii,9,1.0);		
					}
					CFloatMatrix DT = CFloatMatrix(N,n);
					DT = N_Transp(&D);

					//writing the scatter matrix to a file
					if(chuckout2 && (slice!=0) && (slice!=(N_SLICES-1)))
					{
						int pp1, pp2;
						char* cc;
						unsigned int n_digits = 15;

						chuckout_file2 << "\nSlice: " << slice << " Index: " << index << "\n";
						chuckout_file2 << "Point Coordinates:," << p_x-P.mean[0] << " , " << p_y-P.mean[1] << " , " << p_z-P.mean[2] << "\n";
						chuckout_file2 << "Neighbourhood Mean:," << P.mean[0] << " , " << P.mean[1] << " , " << P.mean[2] << "\n";
						chuckout_file2 << "Number of neighbours (incl. the point): " << neigh_size << "\n";
						for(ii=0; ii<n; ii++)
						{
							for(jj = 0; jj < 3; jj++)	
							{
								cc = _fcvt(P.a[ii][jj],n_digits,&pp1,&pp2);
								ProperFloat(cc,pp1,pp2);
								if (fabs(P.a[ii][jj])>1.0)
								{chuckout_file2 << cc << " , ";}
								else {chuckout_file2 << P.a[ii][jj] << " , ";}
							}
							chuckout_file2 << " , ";
							for(jj = 0; jj < N; jj++)	
							{
								cc = _fcvt(D.get(ii,jj),n_digits,&pp1,&pp2);
								ProperFloat(cc,pp1,pp2);
								if (fabs(D.get(ii,jj))>1.0)
								{chuckout_file2 << cc << " , ";}
								else {chuckout_file2 << D.get(ii,jj) << " , ";}
							}
							chuckout_file2 << "\n";		
						}
					}

					//building the scatter matrix
					CFloatMatrix S;
					S = N_Multiply(&DT,&D);

					//eigensolving the scatter matrix
					CFloatMatrix L = CFloatMatrix(1,N);
					CFloatMatrix V = CFloatMatrix(N,N);
					EigensolveRealSymmetric(&S,&L,&V);

					stinks = FALSE;

// THE FOLLOWING IS REMOVED FOR DEBUGGING PURPOSES ONLY
// IN THE STRICT IMPLEMENTATION IT ***MUST*** BE ACTIVATED!
/*
					//looking for negative eigenvalues
					for(j=0; j<N; j++)				
					{	
						if ( L.get(0,j) < 0.0 ) 
						{
							stinks = TRUE;
							stink_file << "Error fitting patch for point index " << index << " on slice " << slice << "\n";
							stink_file << "Reason: There is a negative eigenvalue (index:" << j << ") returned for a real symmetric matrix.\n";
							fflush(NULL);
						}	
					}
*/

					//get the lowest eigenvector (absolute value)
					k = 0;
					for(j=1; j<N; j++)				
					{	
						if ( fabs(L.get(0,j)) < fabs(L.get(0,j-1)) ) 	{k=j;}	
					}
		
					//calculating the mu code
					for(j=0; j<N; j++)
					{
						for(i=0; i<N; i++)	{u.set(i,0,V.get(i,j));}	

						uT = N_Transp(&u);
						temp1 = N_Multiply(&S,&u);
						mu[j]=0;
						for(int ijk = 0; ijk < N; ijk++) {mu[j]+= (uT.get(0,ijk)*temp1.get(ijk,0));}
					}

					//push the diagonal elements back into the surface object m_qs
					for(j=0; j<N; j++)	{quadric_coeffs[j] = mu[k]*V.get(j,k);}

					// checking the sum of absolute values of the coefficients.
					// if they are all zero, something stinks.
					long double sum_coeffs = 0.0;
					for(j=0; j<N; j++)	{sum_coeffs += fabs(quadric_coeffs[j]);}
					if(sum_coeffs==0.0) 
					{
						stinks = TRUE;
						stink_file << "Error fitting patch for point index " << index << " on slice " << slice << "\n";
						stink_file << "Reason: All coefficients of the quadric are zero.\n";
						fflush(NULL);
					}

					//chuckout code
					int chcnt; // the chuckout counter
					if(chuckout)
					{
						//This is where we sort the eigenvalues
						float sorted_eigenvals[N];
						for(chcnt = 0; chcnt<N; chcnt++)		{sorted_eigenvals[chcnt] = fabs(L.get(0,chcnt));}
						SortFloatArray(sorted_eigenvals,N);

						for(chcnt = 0; chcnt<N; chcnt++)		{chuckout_file << sorted_eigenvals[chcnt]   << ",";}
						for(chcnt = 0; chcnt<N; chcnt++)		{chuckout_file << quadric_coeffs[chcnt] << ",";}
						chuckout_file << p_x << ",";
						chuckout_file << p_y << ",";
						chuckout_file << p_z << ",";
					}

					//create the patch
					m_qs = CQuadricSurf(quadric_coeffs);

					for(i = 0; i < 3; i++)			{m_qs.centre[i] = P.mean[i];}

					// render the patches (optional - for debugging purposes only)
					/*
					int kk = 5;
					int sk = 0;	
					if (	
						//		(slice > 150) && 
						//		(slice < 210) &&  
						//		(index > 32) && 
						//		(index < 84) && 
								(((slice+sk)%kk)==0) && 
								((index%(kk-2))==0)
						)
					{
						PP = PointCloudFromQuadric(m_qs);
						root->addChild(PP.render());
					} 
					*/
				
					//CLOSEST POINT CALCULATION
			
					//copying the point
					x0.set(0,0,p_x);	
					x0.set(1,0,p_y);
					x0.set(2,0,p_z);
					x0.set(3,0,1.0);

					//calculation of the closest point
					xx = QuadricClosestPoint(m_qs, &x0);

					// retrieval of the resulting point
					m_x[0][0] = xx.get(0,0);
					m_x[0][1] = xx.get(1,0);
					m_x[0][2] = xx.get(2,0);

					//chuckout code
					if(chuckout)
					{
						chuckout_file << m_x[0][0] << ",";
						chuckout_file << m_x[0][1] << ",";
						chuckout_file << m_x[0][2] << ",";
					}

					BOOL curv_failed;
					if(!stinks)
					{
						// calculation of curvatures and shape indices
						Curvatures(m_qs,
						m_x[0][0]-m_qs.centre[0],
						m_x[0][1]-m_qs.centre[1],
						m_x[0][2]-m_qs.centre[2],
						curv_failed);
	
						if(curv_failed) 
						{
							stinks = TRUE;
							stink_file << "Error calculating curvatures for point index " << index << " on slice " << slice << "\n";
							stink_file << "Reason: This is probably a singular point (flat umbilic).\n";
							fflush(NULL);
						}
					}

					if(!stinks)
					{
						ShapeIndices(m_qs);
					
						// assignment to the curvature map
						m_curv_map[slice][index].exists = TRUE;
						m_curv_map[slice][index].tracked = FALSE;
						m_curv_map[slice][index].ridge = FALSE;
						m_curv_map[slice][index].flexcord = FALSE;
						m_curv_map[slice][index].k1 = m_qs.k1;
						m_curv_map[slice][index].k2 = m_qs.k2;
						m_curv_map[slice][index].K = m_qs.K;
						m_curv_map[slice][index].H = m_qs.H;
						m_curv_map[slice][index].R = m_qs.R;
						m_curv_map[slice][index].S = m_qs.S;
						m_curv_map[slice][index].C = m_qs.C;
						for(int dd = 0; dd < 3; dd++)
						{
							m_curv_map[slice][index].v1[dd] = m_qs.v1[dd];
							m_curv_map[slice][index].v2[dd] = m_qs.v2[dd];
						}


						//chuckout code
						if(chuckout)
						{
							int ddd;
							chuckout_file << m_qs.k1 << ",";
							chuckout_file << m_qs.k2 << ",";
							for(ddd = 0; ddd < 3; ddd++)  {chuckout_file << m_curv_map[slice][index].v1[ddd] << ",";}
							for(ddd = 0; ddd < 3; ddd++)  {chuckout_file << m_curv_map[slice][index].v2[ddd] << ",";}
							chuckout_file << "\n";
							
						}


						// umbilic detection
						//long double V_SMALL = 8e-10;	// bumpy spheres
						long double V_SMALL = 8e-5;		// octahedra, teeth, ellipsoids
						//long double V_SMALL = 5e-5;		// initial go
						if (fabs(m_qs.k1-m_qs.k2) < V_SMALL)
						{
							m_curv_map[slice][index].redlabel = 0;
						}
						else
						{
							m_curv_map[slice][index].redlabel = 3;
						}

						// minima and maxima
						if (m_qs.K < min_gaus_curv) {min_gaus_curv = m_qs.K;}
						if (m_qs.K > max_gaus_curv) {max_gaus_curv = m_qs.K;}	

						if (fabs(m_qs.H) < min_mean_curv) {min_mean_curv = fabs(m_qs.H);}
						if (fabs(m_qs.H) > max_mean_curv) {max_mean_curv = fabs(m_qs.H);}

						if ((m_qs.R < min_curvedness) && (m_qs.R!=0.0) )	{min_curvedness = m_qs.R;}
						if ( m_qs.R > max_curvedness                   )	{max_curvedness = m_qs.R;}

						if (m_qs.S < min_shapeindex)	{min_shapeindex = m_qs.S;}
						if (m_qs.S > max_shapeindex)	{max_shapeindex = m_qs.S;}
						// that last one is really only for debugging, since we do know the limits

						succ_points++;
					} // end doesn't stink
					else
					{
						m_curv_map[slice][index].exists = FALSE;
						m_curv_map[slice][index].redlabel = 3;
						/*
						stink_file << "Values of relevant variables for the point follow below:\n";	

						stink_file << "Point coordinates:\n";
						stink_file << p_x << ", " << p_y << ", " << p_z << "\n";
					
						stink_file << "Scatter Matrix:\n";
						for(j=0; j<N; j++)	{for(i=0; i<N; i++)	{stink_file << S.get(i,j) << ", ";}	stink_file << "\n";}
					
						stink_file << "Eigenvalues:\n";
						for(j = 0; j < N; j++)		{stink_file << L.get(0,j) << ", ";}
						stink_file << "\n";
					
						stink_file << "Eigenvectors:\n";
						for(j=0; j<N; j++)	{for(i=0; i<N; i++)	{stink_file << V.get(i,j) << ", ";	}	stink_file << "\n";}
					
						stink_file << "Quadric Coefficients:\n";
						for(j = 0; j < N; j++)		{stink_file << quadric_coeffs[j] << ", ";}
						stink_file << "\n\n";
						*/

						//chuckout code
						if(chuckout)
						{
							chuckout_file <<  "0,0\n";
						}

						fail_points++;
					} //end stinks

				} // end sufficient neighbours
				else
				{
					//insufficient neighbours
					m_curv_map[slice][index].exists = FALSE;
					if(chuckout)	{chuckout_file << " 0\n";}
					stink_file << "Error fitting patch for point index " << index << " on slice " << slice << "\n";
					stink_file << "Reason: Insufficient neighbours within distance threshold.\n\n";
					void_points++;
				}
			} // if not rejected
			else
			{
				m_curv_map[slice][index].exists = FALSE;
			}
		}//loop by index
	}//loop by slice

	if(chuckout2)	{chuckout_file2.close();}

	// statistics
	float stat_s = (float)succ_points;
	float stat_v = (float)void_points;
	float stat_f = (float)fail_points;

	//closing
	stink_file << "\n\n OVERALL SUCCESS STATISTICS:\n";
	stink_file << "          Successfull Points (patch fitted): " << succ_points <<  "\n";
	stink_file << "      Void Points (no attempt to fit patch): " << void_points <<  "\n";
	stink_file << "Failed Points (attempt to fit patch failed): " << fail_points <<  "\n";
	stink_file << "                    TOTAL POINTS (checksum): " << succ_points+void_points+fail_points <<  "\n";
	stink_file << "\n";
	stink_file << "               Percentage of fitting attempts overall: " << ((stat_s+stat_f)/(stat_s+stat_f+stat_v))*100.0 << "%\n";
	stink_file << "Percentage of successful fits over number of attempts: " << ((stat_s)/(stat_s+stat_f))*100.0 << "%\n";
	fflush(NULL);
	stink_file.close();
	if(chuckout)	{chuckout_file.close();}
	m_curv_map_calculated = TRUE;

	//histogramming
	CreateCurvatureHistograms();
//	SaveCurvatureHistograms();	// make this a user choice or menu item.
	CDlgHistogram* m_dlgHistogram = new CDlgHistogram;
	m_dlgHistogram->AttachDocument(this);
	m_dlgHistogram->DoModal();

	//ridge and flexcord detection
	BOOL minridges = TRUE;				// determine whether or not we want the (unstable) minimal ridges if we can
	long double T_lo = 0.00035;				// lower threshold for hysteresis
	long double T_hi = 0.0004;			// upper threshold for hysteresis (or the sole one if no hysteresis)
	CDlgCurvThresholds DCT;
	DCT.m_lthres = (float)T_lo;
	DCT.m_hthres = (float)T_hi;
	DCT.m_minridges = minridges;
	DCT.DoModal();
	T_lo	  = (long double)DCT.m_lthres;
	T_hi	  = (long double)DCT.m_hthres;
	minridges = DCT.m_minridges;
	// ON THE ABOVE, THE DEFAULT (BEST) VALUES ARE:
	// sc	1
	// T	0.0004 (0.00004 for Tooth, slightly better - also maybe 0 for bumpy spheres)
	// minridges = FALSE
	for(cam = 0; cam < N_CAMERAS; cam++) 	{TrackRidgesAndFlexcords(cam, T_lo, T_hi, minridges);}

	//output to file
	if(ridge_chuckout)
	{
		//opening file header
		ridge_chuckout_file.open("c:\\BA_Monitor\\BodyAnalyser_RidgePoints.csv",ios::out|ios::trunc);
		ridge_chuckout_file << "Ridge Points from BodyAnalyser\n\n";
		ridge_chuckout_file << "File Size Statistics\n";
		ridge_chuckout_file << " Number of Slices:  " << N_SLICES << "\n";
		ridge_chuckout_file << "Number of Cameras:  " << N_CAMERAS << "\n";
		ridge_chuckout_file << "   Number of Leds:  " << N_LEDS << "\n\n";
		
		//counting total number of ridge points
		unsigned long int N_TOTAL_RIDGES = 0;
		for(cam = 0; cam < N_CAMERAS; cam++)
		{
			N_TOTAL_RIDGES += (N_RIDGES[cam]);
		}
		ridge_chuckout_file << "   Number of Detected Ridge Points:  " << N_TOTAL_RIDGES << "\n\n";

		//output of ridge coordinates
		for(slice = 0; slice < N_SLICES; slice++)
		{
			for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
			{
				if(m_curv_map[slice][index].ridge)
				{
					//retrieve the point
					float x,y,z;
					m_xyz_array[slice][index].getValue(x,y,z);

					//write to the file
					ridge_chuckout_file << x << "," << y << "," << z << "\n";
				}
			}//index
		}//slice

		//close
		ridge_chuckout_file.close();
	}


	// rendering the ridge results

	s_Ridges = new SoSeparator;
	s_Ridges = RenderRidges();
	root->addChild(s_Ridges);
	SetDisplayProperties(RIDGES);
	
	s_Flexcords = new SoSeparator;
	s_Flexcords = RenderFlexcords();
	root->addChild(s_Flexcords);
	SetDisplayProperties(FLEXCORDS);
	
	// evaluation of the results

	CDlgEvaluation DlgEval;
	DlgEval.m_dthr = 0.1;
	if (DlgEval.DoModal()==IDOK) {EvaluateRidgeResults(DlgEval.m_sym_type, T_hi, T_lo, DlgEval.m_dthr);}


	//tracking : FOR VISUALISATION ONLY - DOES NOT MEAN MUCH
	for(cam = 0; cam < N_CAMERAS; cam++) 	{TrackCurvatureLines(cam);}

	//visualisation 
	for(cam = 0; cam < N_CAMERAS; cam++) 	{RenderCurvatureMap(cam);}
	if(N_CAMERAS<2)
	{	// We do not attempt to render the directions for whole body scans
		// (too much data, this machine just chokes)
		s_curvatureDirections = new SoSeparator;
		s_curvatureDirections = RenderCurvatureDirections();
		root->addChild(s_curvatureDirections);
		OnViewCurvaturedirectionsNone();
	}

	// cursor back to arrow
	HCURSOR arrowCursor = theApp.LoadStandardCursor(IDC_ARROW);
	SetCursor(arrowCursor);
	
	//rendering
	OnViewColourmapGaussiancurvature(); 
  }//if not done
}


///////////////////////////////////////////////////////////////////////////////////////////
///  TEMPORARY FUNCTIONS - REMOVE WHEN DONE


SoSeparator* CBodyAnalyserDoc::RenderGaussMask(float m[7][7])
{
	SoSeparator* S = new SoSeparator;			

	//S->addChild(m_PointCloud_DrawStyle);

	int i,j,c;

	float x,y,z;
	float f = 1000.0;

	SoCoordinate3 *vertices = new SoCoordinate3;
	
	c = 0;
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
		{
			x = f*(float)i;
			y = f*(float)j;
			z = f*m[i][j];
			vertices->point.set1Value(c++, x, y, z);
		}
	}


	SoPointSet *cPoints = new SoPointSet;
	S->addChild(vertices);

	SoMaterial  *pointColor = new SoMaterial;
	pointColor->diffuseColor.setValue(0.0, 1.0, 0.3); 
	S->addChild(pointColor);

	S->addChild(cPoints);

	return S;

}

/// END OF TEMPORARY FUNCTIONS




// --------------- FUNCTIONS THAT CONTROL THE DISPLAY OF COLOUR MAPS --------------------

// command functions
void CBodyAnalyserDoc::OnViewColourmapNone() 
{
	for(int j = 0; j < N_CAMERAS; j++)
	{
		switch(m_ColourMappingMode)
		{
			case INTENSITIES:			s_triangMesh[j]->replaceChild(m_Texture_Material[j],			m_Smooth_Material[j]);	break;
			case GAUSSIAN_CURVATURE:	s_triangMesh[j]->replaceChild(m_Gaussian_Curvature_Material[j],	m_Smooth_Material[j]);	break;
			case MEAN_CURVATURE:		s_triangMesh[j]->replaceChild(m_Mean_Curvature_Material[j],		m_Smooth_Material[j]);	break;
			case CURVEDNESS:			s_triangMesh[j]->replaceChild(m_Curvedness_Material[j],			m_Smooth_Material[j]);	break;
			case SHAPE_INDEX:			s_triangMesh[j]->replaceChild(m_ShapeIndex_Material[j],			m_Smooth_Material[j]);	break;
			default: break;
		}
	}
	m_ColourMappingMode = SMOOTH;
}

void CBodyAnalyserDoc::OnViewColourmapIntensities() 
{	
	for(int j = 0; j < N_CAMERAS; j++)
	{
		switch(m_ColourMappingMode)
		{
			case SMOOTH:				s_triangMesh[j]->replaceChild(m_Smooth_Material[j],				m_Texture_Material[j]);	break;
			case GAUSSIAN_CURVATURE:	s_triangMesh[j]->replaceChild(m_Gaussian_Curvature_Material[j],	m_Texture_Material[j]);	break;
			case MEAN_CURVATURE:		s_triangMesh[j]->replaceChild(m_Mean_Curvature_Material[j],		m_Texture_Material[j]);	break;
			case CURVEDNESS:			s_triangMesh[j]->replaceChild(m_Curvedness_Material[j],			m_Texture_Material[j]);	break;
			case SHAPE_INDEX:			s_triangMesh[j]->replaceChild(m_ShapeIndex_Material[j],			m_Texture_Material[j]);	break;
			default: break;
		}
	}
	m_ColourMappingMode = INTENSITIES;
}

void CBodyAnalyserDoc::OnViewColourmapGaussiancurvature() 
{
	for(int j = 0; j < N_CAMERAS; j++)
	{
		switch(m_ColourMappingMode)
		{
			case SMOOTH:				s_triangMesh[j]->replaceChild(m_Smooth_Material[j],				m_Gaussian_Curvature_Material[j]);	break;
			case INTENSITIES:			s_triangMesh[j]->replaceChild(m_Texture_Material[j],			m_Gaussian_Curvature_Material[j]);	break;
			case MEAN_CURVATURE:		s_triangMesh[j]->replaceChild(m_Mean_Curvature_Material[j],		m_Gaussian_Curvature_Material[j]);	break;
			case CURVEDNESS:			s_triangMesh[j]->replaceChild(m_Curvedness_Material[j],			m_Gaussian_Curvature_Material[j]);	break;
			case SHAPE_INDEX:			s_triangMesh[j]->replaceChild(m_ShapeIndex_Material[j],			m_Gaussian_Curvature_Material[j]);	break;
			default: break;
		}
	}
	m_ColourMappingMode = GAUSSIAN_CURVATURE;
}

void CBodyAnalyserDoc::OnViewColourmapMeancurvature() 
{
	for(int j = 0; j < N_CAMERAS; j++)
	{
		switch(m_ColourMappingMode)
		{
			case SMOOTH:				s_triangMesh[j]->replaceChild(m_Smooth_Material[j],				m_Mean_Curvature_Material[j]);	break;
			case INTENSITIES:			s_triangMesh[j]->replaceChild(m_Texture_Material[j],			m_Mean_Curvature_Material[j]);	break;
			case GAUSSIAN_CURVATURE:	s_triangMesh[j]->replaceChild(m_Gaussian_Curvature_Material[j],	m_Mean_Curvature_Material[j]);	break;
			case CURVEDNESS:			s_triangMesh[j]->replaceChild(m_Curvedness_Material[j],			m_Mean_Curvature_Material[j]);	break;
			case SHAPE_INDEX:			s_triangMesh[j]->replaceChild(m_ShapeIndex_Material[j],			m_Mean_Curvature_Material[j]);	break;
			default: break;
		}
	}
	m_ColourMappingMode = MEAN_CURVATURE;
}

void CBodyAnalyserDoc::OnViewColourmapCurvedness() 
{
	for(int j = 0; j < N_CAMERAS; j++)
	{
		switch(m_ColourMappingMode)
		{
			case SMOOTH:				s_triangMesh[j]->replaceChild(m_Smooth_Material[j],				m_Curvedness_Material[j]);	break;
			case INTENSITIES:			s_triangMesh[j]->replaceChild(m_Texture_Material[j],			m_Curvedness_Material[j]);	break;
			case GAUSSIAN_CURVATURE:	s_triangMesh[j]->replaceChild(m_Gaussian_Curvature_Material[j],	m_Curvedness_Material[j]);	break;
			case MEAN_CURVATURE:		s_triangMesh[j]->replaceChild(m_Mean_Curvature_Material[j],		m_Curvedness_Material[j]);	break;
			case SHAPE_INDEX:			s_triangMesh[j]->replaceChild(m_ShapeIndex_Material[j],			m_Curvedness_Material[j]);	break;
			default: break;
		}
	}
	m_ColourMappingMode = CURVEDNESS;
}

void CBodyAnalyserDoc::OnViewColourmapShapeindex() 
{
	for(int j = 0; j < N_CAMERAS; j++)
	{
		switch(m_ColourMappingMode)
		{
			case SMOOTH:				s_triangMesh[j]->replaceChild(m_Smooth_Material[j],				m_ShapeIndex_Material[j]);	break;
			case INTENSITIES:			s_triangMesh[j]->replaceChild(m_Texture_Material[j],			m_ShapeIndex_Material[j]);	break;
			case GAUSSIAN_CURVATURE:	s_triangMesh[j]->replaceChild(m_Gaussian_Curvature_Material[j],	m_ShapeIndex_Material[j]);	break;
			case MEAN_CURVATURE:		s_triangMesh[j]->replaceChild(m_Mean_Curvature_Material[j],		m_ShapeIndex_Material[j]);	break;
			case CURVEDNESS:			s_triangMesh[j]->replaceChild(m_Curvedness_Material[j],			m_ShapeIndex_Material[j]);	break;
			default: break;
		}
	}
	m_ColourMappingMode = SHAPE_INDEX;
}

// update command functions

void CBodyAnalyserDoc::OnUpdateViewColourmapN(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_ColourMappingMode==SMOOTH);
}

void CBodyAnalyserDoc::OnUpdateViewColourmapIntensities(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_ColourMappingMode==INTENSITIES);
}

void CBodyAnalyserDoc::OnUpdateViewColourmapGaussiancurvature(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_ColourMappingMode==GAUSSIAN_CURVATURE);
	pCmdUI->Enable(m_curv_map_calculated);
}

void CBodyAnalyserDoc::OnUpdateViewColourmapMeancurvature(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_ColourMappingMode==MEAN_CURVATURE);
	pCmdUI->Enable(m_curv_map_calculated);
}

void CBodyAnalyserDoc::OnUpdateViewColourmapCurvedness(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_ColourMappingMode==CURVEDNESS);
	pCmdUI->Enable(m_curv_map_calculated);
}

void CBodyAnalyserDoc::OnUpdateViewColourmapShapeindex(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_ColourMappingMode==SHAPE_INDEX);
	pCmdUI->Enable(m_curv_map_calculated);
}


// ---------------------------- end of colourmapping functions -------------------------------


// ----- Histogram Manipulation

void CBodyAnalyserDoc::CreateCurvatureHistograms()
{
	unsigned int hist_clusters = 480;

	h_gaussian		= CHistogram(min_gaus_curv,	max_gaus_curv,	hist_clusters);
	h_mean			= CHistogram(min_mean_curv,	max_mean_curv,	hist_clusters);
	h_curvedness	= CHistogram((2.0/PI)*log(min_curvedness),(2.0/PI)*log(max_curvedness), hist_clusters);
	h_shapeindex	= CHistogram(-1.0,			1.0,			hist_clusters);

	int slice,index;

	for(slice = 0; slice < N_SLICES; slice++)
	{
		for(index = 0; index < (N_CAMERAS*N_LEDS); index++)
		{
			if(m_curv_map[slice][index].exists == TRUE)
			{
				h_gaussian.Add(m_curv_map[slice][index].K);

				h_mean.Add(	fabs(	m_curv_map[slice][index].H));

				if(m_curv_map[slice][index].R!=0.0)	{h_curvedness.Add(	m_curv_map[slice][index].C);}
				else {h_curvedness.IncrementCluster(0);}

				h_shapeindex.Add(	m_curv_map[slice][index].S);
			}
		}
	}
}

void CBodyAnalyserDoc::SaveCurvatureHistograms()
{
	unsigned int N = h_gaussian.GetNClusters();
	ofstream hist_file;
	hist_file.open("c:\\BA_Monitor\\BodyAnalyser_Histograms.csv",ios::out|ios::trunc);

	hist_file << "Histograms of curvarure maps for\n";
	hist_file << N << "\n";
	hist_file << "Gaussian, , Mean, ,Curvedness, ,ShapeIndex\n";

	for(int i = 0; i<N; i++)
	{
		hist_file << h_gaussian.GetMin()	+ (h_gaussian.GetClusterWidth()*(long double)i)		<< ", ";
		hist_file << h_gaussian.Get(i)															<< ", ";

		hist_file << h_mean.GetMin()		+ (h_mean.GetClusterWidth()*(long double)i)			<< ", ";
		hist_file << h_mean.Get(i)																<< ", ";

		hist_file << h_curvedness.GetMin()	+ (h_curvedness.GetClusterWidth()*(long double)i)	<< ", ";
		hist_file << h_curvedness.Get(i)														<< ", ";

		hist_file << h_shapeindex.GetMin()	+ (h_shapeindex.GetClusterWidth()*(long double)i)	<< ", ";
		hist_file << h_shapeindex.Get(i)														<< "\n ";
	}

	hist_file.close();
}

// end of histogram manipulation

unsigned int CBodyAnalyserDoc::getCameras()
{
	ASSERT(N_CAMERAS);
	return (unsigned int)N_CAMERAS;
}


void CBodyAnalyserDoc::TrackCurvatureLines(int cam)
{
	BOOL done;
	int counter = 1;
	int slice, index, slice2, index2;

	int start  = camera_start[cam];
	int finish = camera_end[cam];

	// initialising the seed
	unsigned int seed_slice = 30;
	unsigned int seed_index = 10;
	BOOL initialised = FALSE;
	while(!initialised)
	{
		if(
			(m_curv_map[seed_slice][seed_index].exists) &&
			(m_curv_map[seed_slice][seed_index].redlabel) // not an umbilic
		   )
		{
			m_curv_map[seed_slice][seed_index].redlabel = 1;
			initialised = TRUE;
		}
		else
		{
			seed_slice++;
			seed_index++;
		}

	}


	// passes top to bottom
	for(unsigned int n_passes = 0; counter>0; n_passes++)
	{
		counter = 0;
		for(slice = 0; slice < N_SLICES; slice++)
		{
			for(index = start; index <= finish; index++)
			{
				if(
					(m_curv_map[slice][index].exists) && 
					(m_curv_map[slice][index].tracked == FALSE) &&
					(m_curv_map[slice][index].redlabel > 0) &&
					(m_curv_map[slice][index].redlabel < 3)
					)
				{
					TrackCurvatureLinesLocally(slice,index,cam,counter,1);
					m_curv_map[slice][index].tracked = TRUE;
				} //
			} // index
		} // slice
	} // pass

	// all possible passes done at this point
}


void CBodyAnalyserDoc::TrackRidgesAndFlexcords(int cam, long double T_lo, long double T_hi, BOOL minridges)
{
	BOOL Do_Hysteresis = TRUE;
	BOOL chuckout = TRUE;

	int slice, index, counter;

	const int top_to_bottom				= 0;
	const int left_to_right				= 2;
	const int topleft_to_bottomright	= 1;
	const int topright_to_bottomleft	= 3;
	const long double V_LARGE = 999999999.9;

	long double meandistance[4];
	int ss, ii;

	long double krPr1, krPr2, krPb1, krPb2;
	long double kbPr1, kbPr2, kbPb1, kbPb2;
	long double krP, kbP;
	long double v1x, v1y, v1z;
	long double px, py, pz;
	long double neighax, neighay, neighaz;
	long double neighbx, neighby, neighbz;

	float fl_px, fl_py, fl_pz;
	float fl_neighax, fl_neighay, fl_neighaz;
	float fl_neighbx, fl_neighby, fl_neighbz;

	//const int sc = 1;							// scale: how far we want to take neighbours (sc<1 if we can)

	int start  = camera_start[cam];
	int finish = camera_end[cam];

	long double (* hyst_in)[MAX_IMAGE_X][MAX_IMAGE_Y];
	long double (* hyst_out)[MAX_IMAGE_X][MAX_IMAGE_Y];

	hyst_in = (long double (*)[MAX_IMAGE_X][MAX_IMAGE_Y])malloc(MAX_IMAGE_X*MAX_IMAGE_Y*10);
	hyst_out = (long double (*)[MAX_IMAGE_X][MAX_IMAGE_Y])malloc(MAX_IMAGE_X*MAX_IMAGE_Y*10);

	int row, col;

	for(col = 0; col <= (finish-start) ; col++)
	{
		for(row = 0; row < N_SLICES; row++)
		{
			(* hyst_in)[col][row] = (* hyst_out)[col][row] = 0.0;
		}
	}

	for(slice = 0; slice < (N_SLICES); slice++)
	{
		for(index = start; index <= (finish); index++)
		{
			m_curv_map[slice][index].ridge		= FALSE;
			m_curv_map[slice][index].flexcord	= FALSE;
		}
	}

	N_RIDGES[cam] = 0;

	unsigned int margin = 2;
	for(slice = margin; slice < (N_SLICES-margin); slice++)
	{
		for(index = start+1; index <= (finish-1); index++)
		{
			// checking to see if the point can be studied
			if(	
				(m_curv_map[slice][index].exists) &&
				(m_curv_map[slice][index].redlabel) // not an umbilic
			   )
			{
				// initialising a local tracking of curvature lines
				m_curv_map[slice][index].redlabel = 1; //(red curvature is k1)
				krP = m_curv_map[slice][index].k1;
				kbP = m_curv_map[slice][index].k2;

				// tracking
				TrackCurvatureLinesLocally(slice,index,cam,counter,1);

				// retrieving the point and the direction
				v1x = m_curv_map[slice][index].v1[0];
				v1y = m_curv_map[slice][index].v1[1];
				v1z = m_curv_map[slice][index].v1[2];
				m_xyz_array[slice][index].getValue(fl_px, fl_py, fl_pz);
				px = fl_px;
				py = fl_py;
				pz = fl_pz;


				// tracing the neighbours along the curvature directions
				// first for the direction of k1 ("red")-------------------------------------
				
				// top-to-bottom
				m_xyz_array[slice-1][index].getValue(fl_neighax,fl_neighay,fl_neighaz);
				m_xyz_array[slice+1][index].getValue(fl_neighbx,fl_neighby,fl_neighbz);
				neighax = fl_neighax; neighay = fl_neighay; neighaz = fl_neighaz;
				neighbx = fl_neighbx; neighby = fl_neighby;	neighbz = fl_neighbz;
				meandistance[top_to_bottom] = 0.5 * 
					(DistPointToLine(neighax,neighay,neighaz,px,py,pz,v1x,v1y,v1z) + 
					DistPointToLine(neighbx,neighby,neighbz,px,py,pz,v1x,v1y,v1z));

				// left-to-right
				m_xyz_array[slice][index-1].getValue(fl_neighax,fl_neighay,fl_neighaz);
				m_xyz_array[slice][index+1].getValue(fl_neighbx,fl_neighby,fl_neighbz);
				neighax = fl_neighax; neighay = fl_neighay; neighaz = fl_neighaz;
				neighbx = fl_neighbx; neighby = fl_neighby;	neighbz = fl_neighbz;
				meandistance[left_to_right] = 0.5 * 
					(DistPointToLine(neighax,neighay,neighaz,px,py,pz,v1x,v1y,v1z) + 
					DistPointToLine(neighbx,neighby,neighbz,px,py,pz,v1x,v1y,v1z));
	
				// topleft-to-bottomright
				m_xyz_array[slice-1][index-1].getValue(fl_neighax,fl_neighay,fl_neighaz);
				m_xyz_array[slice+1][index+1].getValue(fl_neighbx,fl_neighby,fl_neighbz);
				neighax = fl_neighax; neighay = fl_neighay; neighaz = fl_neighaz;
				neighbx = fl_neighbx; neighby = fl_neighby;	neighbz = fl_neighbz;
				meandistance[topleft_to_bottomright] = 0.5 * 
					(DistPointToLine(neighax,neighay,neighaz,px,py,pz,v1x,v1y,v1z) + 
					DistPointToLine(neighbx,neighby,neighbz,px,py,pz,v1x,v1y,v1z));

				// topright-to-bottomleft
				m_xyz_array[slice-1][index+1].getValue(fl_neighax,fl_neighay,fl_neighaz);
				m_xyz_array[slice+1][index-1].getValue(fl_neighbx,fl_neighby,fl_neighbz);
				neighax = fl_neighax; neighay = fl_neighay; neighaz = fl_neighaz;
				neighbx = fl_neighbx; neighby = fl_neighby;	neighbz = fl_neighbz;
				meandistance[topright_to_bottomleft] = 0.5 * 
					(DistPointToLine(neighax,neighay,neighaz,px,py,pz,v1x,v1y,v1z) + 
					DistPointToLine(neighbx,neighby,neighbz,px,py,pz,v1x,v1y,v1z));

				// finding the minimum directions
				unsigned int red_neigh_direction = ArrayMinimum(meandistance,4);
				unsigned int blue_neigh_direction = (red_neigh_direction + 2) % 4;

				// retrieving the curvatures of the appropriate neighbours
				// !!! (careful about which one is "red" and which one is "blue")
				switch(red_neigh_direction)
				{
				case top_to_bottom:
				// let Pr1 the top neighbour and Pr2 the bottom neighbour
				// (and Pb1 the left neighbour and Pb2 the right neighbour)
				// then we have:
				// for the top neighbour
					ss = slice-1; ii = index;
					krPr1 = kbPr1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr1 = m_curv_map[ss][ii].k1; 
						kbPr1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr1 = m_curv_map[ss][ii].k1; 
						krPr1 = m_curv_map[ss][ii].k2;
					}
				// for the bottom neighbour
					ss = slice+1; ii = index;
					krPr2 = kbPr2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr2 = m_curv_map[ss][ii].k1; 
						kbPr2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr2 = m_curv_map[ss][ii].k1; 
						krPr2 = m_curv_map[ss][ii].k2;
					}
				// for the left neighbour 
					ss = slice; ii = index-1;
					krPb1 = kbPb1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb1 = m_curv_map[ss][ii].k1; 
						kbPb1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb1 = m_curv_map[ss][ii].k1; 
						krPb1 = m_curv_map[ss][ii].k2;
					}
				// for the right neighbour
					ss = slice; ii = index+1;
					krPb2 = kbPb2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb2 = m_curv_map[ss][ii].k1; 
						kbPb2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb2 = m_curv_map[ss][ii].k1; 
						krPb2 = m_curv_map[ss][ii].k2;
					}
					break;
				case left_to_right:
				// let Pr1 the left neighbour and Pr2 the right neighbour
				// (and Pb1 the top neighbour and Pb2 the bottom neighbour)
				// then we have:
				// for the left neighbour
					ss = slice; ii = index-1;
					krPr1 = kbPr1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr1 = m_curv_map[ss][ii].k1; 
						kbPr1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr1 = m_curv_map[ss][ii].k1; 
						krPr1 = m_curv_map[ss][ii].k2;
					}
				// for the right neighbour
					ss = slice; ii = index+1;
					krPr2 = kbPr2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr2 = m_curv_map[ss][ii].k1; 
						kbPr2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr2 = m_curv_map[ss][ii].k1; 
						krPr2 = m_curv_map[ss][ii].k2;
					}
				// for the top neighbour 
					ss = slice-1; ii = index;
					krPb1 = kbPb1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb1 = m_curv_map[ss][ii].k1; 
						kbPb1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb1 = m_curv_map[ss][ii].k1; 
						krPb1 = m_curv_map[ss][ii].k2;
					}
				// for the bottom neighbour
					ss = slice+1; ii = index;
					krPb2 = kbPb2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb2 = m_curv_map[ss][ii].k1; 
						kbPb2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb2 = m_curv_map[ss][ii].k1; 
						krPb2 = m_curv_map[ss][ii].k2;
					}
					break;
				case topleft_to_bottomright:
				// let Pr1 the topleft neighbour and Pr2 the bottomright neighbour
				// (and Pb1 the topright neighbour and Pb2 the bottomleft neighbour)
				// then we have:
				// for the topleft neighbour
					ss = slice-1; ii = index-1;
					krPr1 = kbPr1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr1 = m_curv_map[ss][ii].k1; 
						kbPr1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr1 = m_curv_map[ss][ii].k1; 
						krPr1 = m_curv_map[ss][ii].k2;
					}
				// for the bottomright neighbour
					ss = slice+1; ii = index+1;
					krPr2 = kbPr2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr2 = m_curv_map[ss][ii].k1; 
						kbPr2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr2 = m_curv_map[ss][ii].k1; 
						krPr2 = m_curv_map[ss][ii].k2;
					}
				// for the topright neighbour 
					ss = slice-1; ii = index+1;
					krPb1 = kbPb1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb1 = m_curv_map[ss][ii].k1; 
						kbPb1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb1 = m_curv_map[ss][ii].k1; 
						krPb1 = m_curv_map[ss][ii].k2;
					}
				// for the bottomleft neighbour
					ss = slice+1; ii = index-1;
					krPb2 = kbPb2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb2 = m_curv_map[ss][ii].k1; 
						kbPb2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb2 = m_curv_map[ss][ii].k1; 
						krPb2 = m_curv_map[ss][ii].k2;
					}
					break;
				case topright_to_bottomleft:
				// let Pr1 the topright neighbour and Pr2 the bottomleft neighbour
				// (and Pb1 the topleft neighbour and Pb2 the bottomright neighbour)
				// then we have:
				// for the topright neighbour
					ss = slice-1; ii = index+1;
					krPr1 = kbPr1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr1 = m_curv_map[ss][ii].k1; 
						kbPr1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr1 = m_curv_map[ss][ii].k1; 
						krPr1 = m_curv_map[ss][ii].k2;
					}
				// for the bottomleft neighbour
					ss = slice+1; ii = index-1;
					krPr2 = kbPr2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPr2 = m_curv_map[ss][ii].k1; 
						kbPr2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPr2 = m_curv_map[ss][ii].k1; 
						krPr2 = m_curv_map[ss][ii].k2;
					}
				// for the topleft neighbour 
					ss = slice-1; ii = index-1;
					krPb1 = kbPb1 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb1 = m_curv_map[ss][ii].k1; 
						kbPb1 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb1 = m_curv_map[ss][ii].k1; 
						krPb1 = m_curv_map[ss][ii].k2;
					}
				// for the bottomright neighbour
					ss = slice+1; ii = index+1;
					krPb2 = kbPb2 = V_LARGE;
					if (m_curv_map[ss][ii].redlabel <= 1) 
					{
						krPb2 = m_curv_map[ss][ii].k1; 
						kbPb2 = m_curv_map[ss][ii].k2;
					}
					if (m_curv_map[ss][ii].redlabel == 2) 
					{
						kbPb2 = m_curv_map[ss][ii].k1; 
						krPb2 = m_curv_map[ss][ii].k2;
					}
					break;
				}
				// comparing curvatures to classify a ridge point
				if(Do_Hysteresis)
				{
					// just feeding the hysteresis algorithm now, no final conclusion
					if(
						( (fabs(kbP)>fabs(kbPb1))&&(fabs(kbP)>=fabs(kbPb2)) /*&& (fabs(kbP)>T_hi)*/ ) ||

						// the following two lines only for evaluating bumpy sphere (the proper ROC)
						//( (fabs(kbP)>=fabs(kbPb1))&&(fabs(kbP)>fabs(kbPb2)) /*&& (fabs(kbP)>T_hi)*/ ) ||
						//( (fabs(kbP)<=fabs(kbPb1))&&(fabs(kbP)<fabs(kbPb2)) && (minridges) ) ||

						( (fabs(kbP)<fabs(kbPb1))&&(fabs(kbP)<=fabs(kbPb2)) && (minridges) ) 
						)
					{	// the BLUE curvature is a candidate ridge
						(* hyst_in)[index-start][slice] = fabs(kbP);
					}
					if(
						( (fabs(krP)>fabs(krPr1))&&(fabs(krP)>=fabs(krPr2)) /*&& (fabs(krP)>T_hi)*/ ) ||	

						// the following two lines only for evaluating bumpy sphere (the proper ROC)
						//( (fabs(krP)>=fabs(krPr1))&&(fabs(krP)>fabs(krPr2)) /*&& (fabs(krP)>T_hi)*/ ) ||	
						//( (fabs(krP)<=fabs(krPr1))&&(fabs(krP)<fabs(krPr2)) && (minridges) ) ||

						( (fabs(krP)<fabs(krPr1))&&(fabs(krP)<=fabs(krPr2)) && (minridges) ) 
						)
					{	// the RED curvature is a candidate ridge
						(* hyst_in)[index-start][slice] = fabs(krP);
					}
				}
				else
				{
					if(
						( (fabs(kbP)>fabs(kbPb1))&&(fabs(kbP)>=fabs(kbPb2)) && (fabs(kbP)>T_hi) ) ||
						( (fabs(krP)>fabs(krPr1))&&(fabs(krP)>=fabs(krPr2)) && (fabs(krP)>T_hi) ) ||	
						( (fabs(kbP)<fabs(kbPb1))&&(fabs(kbP)<=fabs(kbPb2)) && (minridges) ) ||
						( (fabs(krP)<fabs(krPr1))&&(fabs(krP)<=fabs(krPr2)) && (minridges) ) 
						)
					{
						m_curv_map[slice][index].ridge = TRUE;
						N_RIDGES[cam] = (N_RIDGES[cam])+1;
					}
				}

				// comparing curvatures to classify a flexcord point
				if(
					( (fabs(kbP)>fabs(kbPr1))&&(fabs(kbP)>=fabs(kbPr2)) && (fabs(kbP)>T_hi) ) ||
					( (fabs(krP)>fabs(krPb1))&&(fabs(krP)>=fabs(krPb2)) && (fabs(krP)>T_hi) ) || 
					( (fabs(kbP)<fabs(kbPr1))&&(fabs(kbP)<=fabs(kbPr2)) && (minridges) ) ||
					( (fabs(krP)<fabs(krPb1))&&(fabs(krP)<=fabs(krPb2)) && (minridges) ) 
					)
				{
					m_curv_map[slice][index].flexcord = TRUE;
				}

				// Undoing the tracking
				for(int i = slice-1; i<=(slice+1); i++)
				{
					for(int j = index-1; j<=(index+1); j++)
					{
						if(m_curv_map[i][j].redlabel > 0)
						{
							m_curv_map[i][j].redlabel = 3;
						}
					}
				}
			} // if
			else
			{
				if(Do_Hysteresis)
				{
					(* hyst_in)[index-start][slice] = 0.0;
				}
			}
		} // index
	} // slice

	//  Hysteresis step - Ridges only 
	if(Do_Hysteresis)
	{
		Hysteresis(hyst_in, hyst_out, finish-start+1, N_SLICES, T_lo, T_hi);
		for(row = 0; row < N_SLICES; row++)
		{
			for(col = 0; col <= (finish-start) ; col++)
			{
				if((* hyst_out)[col][row] > 0.0)
				{
					m_curv_map[row][col+start].ridge = TRUE;
					N_RIDGES[cam] = (N_RIDGES[cam])+1;
				}
			}
		}
	}

/*
	// finishing off (this is not per camera, so it must be at the end of all cam images processed)
	/// !!! MAY ACTUALLY NEED TO MOVE IT OUTSIDE!!!
	if((cam+1)==N_CAMERAS)
	{
		// rendering the results

		s_Ridges = new SoSeparator;
		s_Ridges = RenderRidges();
		root->addChild(s_Ridges);
		SetDisplayProperties(RIDGES);
		
		s_Flexcords = new SoSeparator;
		s_Flexcords = RenderFlexcords();
		root->addChild(s_Flexcords);
		SetDisplayProperties(FLEXCORDS);
	
		// evaluation of the results

		CDlgEvaluation DlgEval;
		DlgEval.m_dthr = 0.1;
		if (DlgEval.DoModal()==IDOK) {EvaluateRidgeResults(DlgEval.m_sym_type, T_hi, T_lo, DlgEval.m_dthr);}
	}
*/
}

void CBodyAnalyserDoc::TrackCurvatureLinesLocally(int slice, int index, int cam, int &counter, unsigned int sc)
{
	int slice2, index2;

	// above
	slice2 = slice-sc;
	index2 = index;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// below
	slice2 = slice+sc;
	index2 = index;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// left
	slice2 = slice;
	index2 = index-sc;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// right
	slice2 = slice;
	index2 = index+sc;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// above left
	slice2 = slice-sc;
	index2 = index-sc;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// above right
	slice2 = slice-sc;
	index2 = index+sc;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// below left
	slice2 = slice+sc;
	index2 = index-sc;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

	// below right
	slice2 = slice+sc;
	index2 = index+sc;
	if (
		(SliceIndexInBounds(slice2,index2,cam)) &&
		(m_curv_map[slice2][index2].exists) &&
		(m_curv_map[slice2][index2].redlabel == 3)
		)
	{
		PropagateCurvatureLabels(slice,index,slice2,index2);
		counter++;
	}

}

BOOL CBodyAnalyserDoc::SliceIndexInBounds(int slice, int index, int cam)
{
	int start  = camera_start[cam];
	int finish = camera_end[cam];

	if( (slice >= 0) &&
		(slice < N_SLICES) &&
		(index >= start) &&
		(index <= finish) 
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void CBodyAnalyserDoc::PropagateCurvatureLabels(int slice1, int index1, int slice2, int index2)
{
	// take v11 
	long double v11x = m_curv_map[slice1][index1].v1[0];
	long double v11y = m_curv_map[slice1][index1].v1[1];
	long double v11z = m_curv_map[slice1][index1].v1[2];

	// take v21
	long double v21x = m_curv_map[slice2][index2].v1[0];
	long double v21y = m_curv_map[slice2][index2].v1[1];
	long double v21z = m_curv_map[slice2][index2].v1[2];

	// take v22
	long double v22x = m_curv_map[slice2][index2].v2[0];
	long double v22y = m_curv_map[slice2][index2].v2[1];
	long double v22z = m_curv_map[slice2][index2].v2[2];

	// calculate p1 = abs(v11.v21)
	long double p1 = fabs(DotProduct(v11x,v11y,v11z,v21x,v21y,v21z));

	// calculate p2 = abs(v11.v22)
	long double p2 = fabs(DotProduct(v11x,v11y,v11z,v22x,v22y,v22z));

	// if p1 > p2 then redlabel2 = redlabel1
	// else redlabel 2 = opposite(redlabe11)
	if(p1>=p2)
	{
		m_curv_map[slice2][index2].redlabel = m_curv_map[slice1][index1].redlabel;
	}
	else
	{
		if (m_curv_map[slice1][index1].redlabel == 2)
		{
			m_curv_map[slice2][index2].redlabel = 1;
		}
		else
		{
			m_curv_map[slice2][index2].redlabel = 2;
		}
	}

}



void CBodyAnalyserDoc::EvaluateRidgeResults(int sym_type, long double uthr, long double lthr, long double dthr)
{
	
	unsigned long int true_positives = 0;
	unsigned long int false_positives = 0;

	unsigned long int P = CountAllPositives(sym_type, dthr);

	for(int slice=0; slice<(N_SLICES-1); slice++)
	{
		for(int index=0; index<(N_CAMERAS*N_LEDS); index++)
		{
			if(m_curv_map[slice][index].ridge)
			{
				BOOL close_enough = FALSE;
				//retrieve the point
				float fl_x, fl_y, fl_z;
				long double x,y,z;
				m_xyz_array[slice][index].getValue(fl_x,fl_y,fl_z);
				x = fl_x; y = fl_y; z = fl_z; 
				
				// check planar distances to see if it is a true or false positive
				switch(sym_type)
				{
				case SYM_MODE_BODY:
					if ( (FALSE)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_ELLIPSOID:
					if ( (FALSE)
						// check against Sx
						|| (PlanarDistanceTest(x,y,z,1,0,0,0)<dthr)
						// check against Sy
						|| (PlanarDistanceTest(x,y,z,0,1,0,-10000)<dthr)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_TOOTH:
					if ( (FALSE)
						// check against Sx
						|| (PlanarDistanceTest(x,y,z,1,0,0,0)<dthr)
						// check against Sy
						|| (PlanarDistanceTest(x,y,z,0,1,0,-10000)<dthr)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						// check against Dx
						|| (PlanarDistanceTest(x,y,z,0,1,-1,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,0,1,1,-10000)<dthr)
						// check against Dy
						|| (PlanarDistanceTest(x,y,z,1,0,-1,0)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,0,1,0)<dthr)
						// check against Dz
						|| (PlanarDistanceTest(x,y,z,-1,1,0,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,1,0,-10000)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_OCTAHEDRON:
					if ( (FALSE)
						// check against Sx
						|| (PlanarDistanceTest(x,y,z,1,0,0,0)<dthr)
						// check against Sy
						|| (PlanarDistanceTest(x,y,z,0,1,0,-10000)<dthr)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						// check against Dy
						|| (PlanarDistanceTest(x,y,z,1,0,-1,0)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,0,1,0)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_BUMPY:
					if ( (FALSE)
						// check against Dx
						|| (PlanarDistanceTest(x,y,z,0,1,-1,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,0,1,1,-10000)<dthr)
						// check against Dy
						|| (PlanarDistanceTest(x,y,z,1,0,-1,0)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,0,1,0)<dthr)
						// check against Dz
						|| (PlanarDistanceTest(x,y,z,-1,1,0,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,1,0,-10000)<dthr)
						)
					{close_enough = TRUE;}
					break;
				default:
					break;
				}
				if(close_enough) 
				{	
					true_positives++;
				} 
				else 
				{
					false_positives++;
				}
 
			}// if ridge
		}//index
	}//slice

	//dialog to show results
	CDlgEvaluationReport ER;
	ER.m_dthr = dthr;
	ER.m_lthr = lthr;
	ER.m_hthr = uthr;
	ER.m_n_falsepositives = false_positives;
	ER.m_n_truepositives = true_positives;
	ER.m_P = P;
	ER.DoModal();
}

unsigned long int CBodyAnalyserDoc::CountAllPositives(int sym_type, long double dthr)
{
	unsigned long int P = 0;
	int margin = 2;

	for(int slice=margin; slice<((N_SLICES-1)-margin); slice++)
	{
		for(int index=margin; index<((N_CAMERAS*N_LEDS)-margin); index++)
		{
			//if(m_curv_map[slice][index].ridge)
			//{

				// *** IMPORTANT ***
				// Check this segment - it must always be identical to the one in the evaluation
				// function ("if ridge"). In future, make it into a funtion and call it from both.

				BOOL close_enough = FALSE;
				//retrieve the point
				float fl_x, fl_y, fl_z;
				long double x,y,z;
				m_xyz_array[slice][index].getValue(fl_x,fl_y,fl_z);
				x = fl_x; y = fl_y; z = fl_z; 
				
				// check planar distances to see if it is a true or false positive
				switch(sym_type)
				{
				case SYM_MODE_BODY:
					if ( (FALSE)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_ELLIPSOID:
					if ( (FALSE)
						// check against Sx
						|| (PlanarDistanceTest(x,y,z,1,0,0,0)<dthr)
						// check against Sy
						|| (PlanarDistanceTest(x,y,z,0,1,0,-10000)<dthr)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_TOOTH:
					if ( (FALSE)
						// check against Sx
						|| (PlanarDistanceTest(x,y,z,1,0,0,0)<dthr)
						// check against Sy
						|| (PlanarDistanceTest(x,y,z,0,1,0,-10000)<dthr)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						// check against Dx
						|| (PlanarDistanceTest(x,y,z,0,1,-1,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,0,1,1,-10000)<dthr)
						// check against Dy
						|| (PlanarDistanceTest(x,y,z,1,0,-1,0)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,0,1,0)<dthr)
						// check against Dz
						|| (PlanarDistanceTest(x,y,z,-1,1,0,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,1,0,-10000)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_OCTAHEDRON:
					if ( (FALSE)
						// check against Sx
						|| (PlanarDistanceTest(x,y,z,1,0,0,0)<dthr)
						// check against Sy
						|| (PlanarDistanceTest(x,y,z,0,1,0,-10000)<dthr)
						// check against Sz
						|| (PlanarDistanceTest(x,y,z,0,0,1,0)<dthr)
						// check against Dy
						|| (PlanarDistanceTest(x,y,z,1,0,-1,0)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,0,1,0)<dthr)
						)
					{close_enough = TRUE;}
					break;
				case SYM_MODE_BUMPY:
					if ( (FALSE)
						// check against Dx
						|| (PlanarDistanceTest(x,y,z,0,1,-1,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,0,1,1,-10000)<dthr)
						// check against Dy
						|| (PlanarDistanceTest(x,y,z,1,0,-1,0)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,0,1,0)<dthr)
						// check against Dz
						|| (PlanarDistanceTest(x,y,z,-1,1,0,-10000)<dthr)
						|| (PlanarDistanceTest(x,y,z,1,1,0,-10000)<dthr)
						)
					{close_enough = TRUE;}
					break;
				default:
					break;
				}
				if(close_enough) {P++;} 
 
			//}// if ridge
		}//index
	}//slice
	
	return(P);
}
