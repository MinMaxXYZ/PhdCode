// BodyWarperDoc.h : interface of the CBodyWarperDoc class
//
/////////////////////////////////////////////////////////////////////////////
// BEGIN_IVWGEN
#include <Ivf/IvfDocument.h>
// END_IVWGEN

#include "..\bldefs.h"

#include <Inventor\nodes\SoSeparator.h>
#include <Inventor\nodes\SoMaterial.h>
#include <Inventor\nodes\SoCoordinate3.h>
#include <Inventor\nodes\SoDrawStyle.h>
#include <Inventor\nodes\SoShapeHints.h>
#include <Inventor\nodes\SoQuadMesh.h>
#include <Inventor\nodes\SoSphere.h>
#include <Inventor\nodes\SoTranslation.h>
#include <Inventor\nodes\SoPointSet.h>


static char *def_ext[] = {NULL, ".iv", ".wrl"};


// BEGIN_IVWGEN
class CBodyWarperDoc : public CDocument , public CIvfDocument
{
// END_IVWGEN
protected: // create from serialization only
	CBodyWarperDoc();
	DECLARE_DYNCREATE(CBodyWarperDoc)

	BOOLEAN m_bContainsCamera;

// Attributes
public:
	void Main_GetLandmarkCoords(int c_plane, float &x1, float &y1, float &z1, float &x2, float &y2, float &z2, float &x3, float &y3, float &z3);
	void Main_Warp(	float (* w)[MAX_N_SLICES*MAX_N_COLS][3],
					float (* c)[MAX_N_SLICES*MAX_N_COLS][3],//debug
					int (* f)[MAX_N_SLICES*MAX_N_COLS],
					int ro, int co);
	void Main_ConstructTransformations();
	void Main_CopyAndClassify(	float (* s)[MAX_N_SLICES*MAX_N_COLS][3], 
								float (* t)[MAX_N_SLICES*MAX_N_COLS][3], 
								int (* f)[MAX_N_SLICES*MAX_N_COLS],
								BOOL (* d)[MAX_N_SLICES*MAX_N_COLS],
								float (* c)[MAX_N_SLICES*MAX_N_COLS][3],
								int ro, int co);
	SoSeparator* renderLandmarkSet(const int part);
	SoSeparator* renderSegment(	float (* s)[MAX_N_SLICES*MAX_N_COLS][3], 
								float (* c)[MAX_N_SLICES*MAX_N_COLS][3], 
								int ro, int co, const int part);
	void render(const int part);

	BOOL SourceShapeLoaded;
	BOOL SourceLandmarksLoaded;
	BOOL TargetShapeLoaded;
	BOOL TargetLandmarksLoaded;
	BOOL WarpingComplete;

	BOOL ShowSourceLandmarks;
	BOOL ShowTargetLandmarks;

	SoMaterial* source_shape_color;
	SoDrawStyle* source_shape_style;

	SoMaterial* target_shape_color;
	SoDrawStyle* target_shape_style;

	SoMaterial* warped_shape_color;
	SoDrawStyle* warped_shape_style;

	SoMaterial* source_landmarks_color;
	SoDrawStyle* source_landmarks_style;

	SoMaterial* target_landmarks_color;
	SoDrawStyle* target_landmarks_style;


	SoSeparator* root;

	float source_head[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int source_head_rows;
	unsigned int source_head_cols;

	float source_torso[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int source_torso_rows;
	unsigned int source_torso_cols;

	float source_rleg[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int source_rleg_rows;
	unsigned int source_rleg_cols;

	float source_lleg[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int source_lleg_rows;
	unsigned int source_lleg_cols;
/*
	float source_rarm[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int source_rarm_rows;
	unsigned int source_rarm_cols;

	float source_larm[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int source_larm_rows;
	unsigned int source_larm_cols;
*/
	//-------------------------------------------

	float target_head[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int target_head_rows;
	unsigned int target_head_cols;

	float target_torso[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int target_torso_rows;
	unsigned int target_torso_cols;

	float target_rleg[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int target_rleg_rows;
	unsigned int target_rleg_cols;

	float target_lleg[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int target_lleg_rows;
	unsigned int target_lleg_cols;
/*
	float target_rarm[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int target_rarm_rows;
	unsigned int target_rarm_cols;

	float target_larm[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int target_larm_rows;
	unsigned int target_larm_cols;
*/	
	//-------------------------------------------

	float warped_head[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int warped_head_rows;
	unsigned int warped_head_cols;

	float warped_torso[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int warped_torso_rows;
	unsigned int warped_torso_cols;

	float warped_rleg[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int warped_rleg_rows;
	unsigned int warped_rleg_cols;

	float warped_lleg[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int warped_lleg_rows;
	unsigned int warped_lleg_cols;
/*
	float warped_rarm[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int warped_rarm_rows;
	unsigned int warped_rarm_cols;

	float warped_larm[MAX_N_SLICES*MAX_N_COLS][3];
	unsigned int warped_larm_rows;
	unsigned int warped_larm_cols;
*/
		//-------------------------------------------

	int flags_head[MAX_N_SLICES*MAX_N_COLS];
	int flags_torso[MAX_N_SLICES*MAX_N_COLS];
	int flags_rleg[MAX_N_SLICES*MAX_N_COLS];
	int flags_lleg[MAX_N_SLICES*MAX_N_COLS];
/*	int flags_rarm[MAX_N_SLICES*MAX_N_COLS];
	int flags_larm[MAX_N_SLICES*MAX_N_COLS]; */

	float c_head[MAX_N_SLICES*MAX_N_COLS][3];
	float c_torso[MAX_N_SLICES*MAX_N_COLS][3];
	float c_rleg[MAX_N_SLICES*MAX_N_COLS][3];
	float c_lleg[MAX_N_SLICES*MAX_N_COLS][3];
/*	float c_rarm[MAX_N_SLICES*MAX_N_COLS][3];
	float c_larm[MAX_N_SLICES*MAX_N_COLS][3]; */

	BOOL d[MAX_N_SLICES*MAX_N_COLS];

	//-------------------------------------------

	CString source_landmark_label[N_LANDMARKS];
	float source_landmark[N_LANDMARKS][3];
	unsigned int n_source_landmarks;

	CString target_landmark_label[N_LANDMARKS];
	float target_landmark[N_LANDMARKS][3];
	unsigned int n_target_landmarks;

	//-------------------------------------------

	float local_affine_transform[N_TETRAHEDRA][4][4];

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBodyWarperDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBodyWarperDoc();
	virtual void IvfSetupUrlFetchCallback(void);
	BOOL HasAnchors(void) { return (m_pAnchorList != NULL); }
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBodyWarperDoc)
	afx_msg void OnFileImport();
	afx_msg void OnUpdateFileImport(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewpoints(CCmdUI *pCmdUI);
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileReload();
	afx_msg void OnUpdateFileReload(CCmdUI *pCmdUI);
	afx_msg void OnFileLoadsourceshape();
	afx_msg void OnUpdateViewSourceshapeSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSourceshapeWireframe(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSourceshapePoints(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSourceshapeHide(CCmdUI* pCmdUI);
	afx_msg void OnFileLoadtargetshape();
	afx_msg void OnUpdateViewTargetshapeSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTargetshapeWireframe(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTargetshapePoints(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTargetshapeHide(CCmdUI* pCmdUI);
	afx_msg void OnFileLoadsourcelandmarks();
	afx_msg void OnFileLoadtargetlandmarks();
	afx_msg void OnUpdateViewSourcelandmarks(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTargetlandmarks(CCmdUI* pCmdUI);
	afx_msg void OnFileCalculatetransformation();
	afx_msg void OnFileLoadtransformation();
	afx_msg void OnUpdateFileSavetransformation(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewWarpedshapeSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewWarpedshapeWireframe(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewWarpedshapePoints(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewWarpedshapeHide(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileCalculatetransformation(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileLoadtransformation(CCmdUI* pCmdUI);
	afx_msg void OnViewSourceshapeSolid();
	afx_msg void OnViewSourceshapeWireframe();
	afx_msg void OnViewSourceshapePoints();
	afx_msg void OnViewSourceshapeHide();
	afx_msg void OnViewTargetshapeSolid();
	afx_msg void OnViewTargetshapeWireframe();
	afx_msg void OnViewTargetshapePoints();
	afx_msg void OnViewTargetshapeHide();
	afx_msg void OnViewSourcelandmarks();
	afx_msg void OnViewTargetlandmarks();
	afx_msg void OnViewWarpedshapeSolid();
	afx_msg void OnViewWarpedshapeWireframe();
	afx_msg void OnViewWarpedshapePoints();
	afx_msg void OnViewWarpedshapeHide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
