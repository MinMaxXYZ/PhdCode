#ifndef __doc_INCLUDED
#define __doc_INCLUDED


// BodyAnalyserDoc.h : interface of the CBodyAnalyserDoc class
//
/////////////////////////////////////////////////////////////////////////////
// BEGIN_IVWGEN
#include <Ivf/IvfDocument.h>
// END_IVWGEN

#include "..\bldefs.h"
#include "CurvatureProfile.h"
#include "Histogram.h"



#include <assert.h>
#include <Inventor/nodes/SoDrawStyle.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoMaterialBinding.h>
#include <Inventor/nodes/SoLightModel.h>


// BEGIN_IVWGEN
class CBodyAnalyserDoc : public CDocument , public CIvfDocument
{
// END_IVWGEN
protected: // create from serialization only
	CString m_input_file;
	short m_bHasData;

	float m_x_correction;
	float m_y_correction;
	float m_z_correction;

	int N_CAMERAS;
	int N_SLICES;
	int N_LEDS;

	int N_GSCALES;
	int N_CHANNELS;
	int N_COLS;

	int camera_start[MAX_N_CAMERAS];
	int camera_end[MAX_N_CAMERAS];


	SbVec3f* m_xyz_array[MAX_N_SLICES];			// Cartesian coordinates
	SbVec3f* m_norm_array[MAX_N_SLICES];		// Cartesian coordinates of the normals
	unsigned char* m_b_array[MAX_N_SLICES];		// brightness values
	unsigned char* m_flag_array[MAX_N_SLICES];	// flags
	long* m_indices[MAX_N_SLICES];				// indices for rendering
	long valid_point_counter[MAX_N_CAMERAS];	
	unsigned long int N_RIDGES[MAX_N_CAMERAS];
	CCurvatureProfile m_curv_map[MAX_N_SLICES][MAX_N_LEDS*MAX_N_CAMERAS];//the curvature map
	BOOL m_edge_array[MAX_N_SLICES][MAX_N_LEDS*MAX_N_CAMERAS];			//the texture edge map


	PARAMS m_scanner_params;
	CBodyAnalyserDoc();
	DECLARE_DYNCREATE(CBodyAnalyserDoc)

	BOOLEAN m_bContainsCamera;

	int c_gmask;
	int c_lhthr;
	int c_uhthr;

	// the extremal values for the curvature attributes
	long double min_mean_curv;
	long double max_mean_curv;
	long double min_gaus_curv;
	long double max_gaus_curv;
	long double min_curvedness;
	long double max_curvedness;
	long double min_shapeindex;
	long double max_shapeindex;
	// we don't really need one for shape index, we know the range... (Koenderink does)

// Attributes
public:
	unsigned int getCameras();

	SoSeparator* RenderGaussMask(float m[7][7]);
	BOOL SaveAsVRML2(LPCTSTR lpszPathName);
	BOOL SaveCurvatureMap(LPCTSTR lpszPathName);

	void CreateCameraImages();
	void CreateCurvatureHistograms();
	void SaveCurvatureHistograms();

	void normaliseVector(float& x, float& y, float& z);
	void CalculateNormals();
	float Gauss2D(float x, float y, float s);
	void Convolve(SbVec3f data_in[MAX_N_SLICES+6][MAX_N_LEDS+6], float m[7][7], SbVec3f data_out[MAX_N_SLICES+6][MAX_N_LEDS+6], unsigned char flags[MAX_N_SLICES+6][MAX_N_LEDS+6]);

	void Clean_BottomSlice(int s);
	void Clean_FirstAndLast();
	void Clean_Slice(int s);
	void Clean_ProximityTest();
	void Clean_SpatialCulling();
	void Clean_Thresholding();
	void CleanBody();


	SoLightModel* m_LightModel;

	SoDrawStyle* m_PointCloud_DrawStyle;
	SoDrawStyle* m_OutlierCloud_DrawStyle;
	SoDrawStyle* m_CoordOrigin_DrawStyle;
	SoDrawStyle* m_RefFrame_DrawStyle;
	SoDrawStyle* m_TextureEdgels_DrawStyle;
	SoDrawStyle* m_Ridges_DrawStyle;
	SoDrawStyle* m_Flexcords_DrawStyle;
	SoDrawStyle* m_CurvDir_NearUmbilics_DrawStyle;
	SoDrawStyle* m_CurvDir_Red_DrawStyle;
	SoDrawStyle* m_CurvDir_Blue_DrawStyle;
	SoDrawStyle* m_Connected_DrawStyle_0;
	SoDrawStyle* m_Connected_DrawStyle_1;
	SoDrawStyle* m_Connected_DrawStyle_2;
	SoDrawStyle* m_Connected_DrawStyle_3;
	SoDrawStyle* m_Connected_DrawStyle_4;
	SoDrawStyle* m_Connected_DrawStyle_5;
	SoDrawStyle* m_Connected_DrawStyle_6;
	SoDrawStyle* m_Connected_DrawStyle_7;
	SoDrawStyle* m_Symmetry_DrawStyle[N_SYM_SETS];

	SoMaterial* m_Texture_Material[MAX_N_CAMERAS];
	SoMaterial* m_Smooth_Material[MAX_N_CAMERAS];
	SoMaterial* m_Gaussian_Curvature_Material[MAX_N_CAMERAS];
	SoMaterial* m_Mean_Curvature_Material[MAX_N_CAMERAS];
	SoMaterial* m_Curvedness_Material[MAX_N_CAMERAS];
	SoMaterial* m_ShapeIndex_Material[MAX_N_CAMERAS];

	SoMaterialBinding* m_Connected_Material_Binding[MAX_N_CAMERAS];

	void RenderBody();
	SoSeparator* root;
	SoSeparator* RenderPointCloud();
	SoSeparator* RenderOutlierCloud();
	SoSeparator* RenderCoordOrigin();
	SoSeparator* RenderReferenceFrame();
	SoSeparator* RenderTextureEdgels();
	SoSeparator* RenderConnectedMesh(int cam);
	SoSeparator* RenderTriangMesh(int cam);
	void RenderCurvatureMap(int cam);
	SoSeparator* RenderCurvatureDirections();
	SoSeparator* RenderFlexcords();
	SoSeparator* RenderRidges();
	SoSeparator* RenderSymmetryPlanes();

	SoSeparator* s_pointCloud;
	SoSeparator* s_outlierCloud;
	SoSeparator* s_referenceFrame;
	SoSeparator* s_coordinateOrigin;
	SoSeparator* s_textureEdgels;
	SoSeparator* s_Ridges;
	SoSeparator* s_Flexcords;
	SoSeparator* s_triangMesh[MAX_N_CAMERAS];
	SoSeparator* smooth_triangMesh[MAX_N_CAMERAS];
//	SoSeparator* connectedMesh[MAX_N_CAMERAS];
//	SoSeparator* smooth_connectedMesh[MAX_N_CAMERAS];
	SoSeparator* s_curvatureDirections;

	SbVec3f& Cartesian(int slice, int index, int distance);
	BOOL GetDownload(void);
	DSOURCE m_data_source;
	short OpenFile(const CString& input_file);
	short OpenSCFile(const CString& input_file);
	short OpenHCCFile(const CString& input_file);

	CHistogram h_gaussian;
	CHistogram h_mean;
	CHistogram h_curvedness;
	CHistogram h_shapeindex;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBodyAnalyserDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBodyAnalyserDoc();
	virtual void IvfSetupUrlFetchCallback(void);
	BOOL HasAnchors(void) { return (m_pAnchorList != NULL); }
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBodyAnalyserDoc)
	afx_msg void OnFileImport();
	afx_msg void OnUpdateFileImport(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewpoints(CCmdUI *pCmdUI);
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileReload();
	afx_msg void OnUpdateFileReload(CCmdUI *pCmdUI);
	afx_msg void OnViewPointcloud();
	afx_msg void OnUpdateViewPointcloud(CCmdUI* pCmdUI);
	afx_msg void OnViewReferenceframe();
	afx_msg void OnUpdateViewReferenceframe(CCmdUI* pCmdUI);
	afx_msg void OnViewCoordinateorigin();
	afx_msg void OnUpdateViewCoordinateorigin(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera0();
	afx_msg void OnUpdateViewConnectedmeshCamera0(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshNone();
	afx_msg void OnUpdateViewConnectedmeshNone(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshAll();
	afx_msg void OnUpdateViewConnectedmeshAll(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera1();
	afx_msg void OnUpdateViewConnectedmeshCamera1(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera2();
	afx_msg void OnUpdateViewConnectedmeshCamera2(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera3();
	afx_msg void OnUpdateViewConnectedmeshCamera3(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera4();
	afx_msg void OnUpdateViewConnectedmeshCamera4(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera5();
	afx_msg void OnUpdateViewConnectedmeshCamera5(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera6();
	afx_msg void OnUpdateViewConnectedmeshCamera6(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshCamera7();
	afx_msg void OnUpdateViewConnectedmeshCamera7(CCmdUI* pCmdUI);
	afx_msg void OnToolsCameraImager();
	afx_msg void OnViewOutliercloud();
	afx_msg void OnUpdateViewOutliercloud(CCmdUI* pCmdUI);
	afx_msg void OnToolsSurfacesmoothing();
	afx_msg void OnToolsTextureedgedetector();
	afx_msg void OnUpdateToolsTextureedgedetector(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewConnectedmeshTextureedgels(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshTextureedgels();
	afx_msg void OnToolsHistogramequalisation();
	afx_msg void OnUpdateToolsCurvaturemap(CCmdUI* pCmdUI);
	afx_msg void OnToolsCurvatureMap();
	afx_msg void OnViewColourmapNone();
	afx_msg void OnUpdateViewColourmapN(CCmdUI* pCmdUI);
	afx_msg void OnViewColourmapIntensities();
	afx_msg void OnUpdateViewColourmapIntensities(CCmdUI* pCmdUI);
	afx_msg void OnViewColourmapGaussiancurvature();
	afx_msg void OnUpdateViewColourmapGaussiancurvature(CCmdUI* pCmdUI);
	afx_msg void OnViewColourmapMeancurvature();
	afx_msg void OnUpdateViewColourmapMeancurvature(CCmdUI* pCmdUI);
	afx_msg void OnViewColourmapCurvedness();
	afx_msg void OnUpdateViewColourmapCurvedness(CCmdUI* pCmdUI);
	afx_msg void OnViewColourmapShapeindex();
	afx_msg void OnUpdateViewColourmapShapeindex(CCmdUI* pCmdUI);
	afx_msg void OnViewConnectedmeshPhotorealistic();
	afx_msg void OnUpdateViewConnectedmeshPhotorealistic(CCmdUI* pCmdUI);
	afx_msg void OnViewCurvaturedirections();
	afx_msg void OnUpdateViewCurvaturedirections(CCmdUI* pCmdUI);
	afx_msg void OnViewCurvaturedirectionsBlue();
	afx_msg void OnUpdateViewCurvaturedirectionsBlue(CCmdUI* pCmdUI);
	afx_msg void OnViewCurvaturedirectionsRed();
	afx_msg void OnUpdateViewCurvaturedirectionsRed(CCmdUI* pCmdUI);
	afx_msg void OnViewCurvaturedirectionsAll();
	afx_msg void OnUpdateViewCurvaturedirectionsAll(CCmdUI* pCmdUI);
	afx_msg void OnViewCurvaturedirectionsNone();
	afx_msg void OnUpdateViewCurvaturedirectionsNone(CCmdUI* pCmdUI);
	afx_msg void OnViewRidges();
	afx_msg void OnUpdateViewRidges(CCmdUI* pCmdUI);
	afx_msg void OnViewFlexcords();
	afx_msg void OnUpdateViewFlexcords(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSymmetryplanesNone(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSymmetryplanesBody(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSymmetryplanesEllipsoid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSymmetryplanesToothcube(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSymmetryplanesOctahedrondiamond(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewSymmetryplanesBumpyspheretetrahedron(CCmdUI* pCmdUI);
	afx_msg void OnViewSymmetryplanesBody();
	afx_msg void OnViewSymmetryplanesEllipsoid();
	afx_msg void OnViewSymmetryplanesToothcube();
	afx_msg void OnViewSymmetryplanesOctahedrondiamond();
	afx_msg void OnViewSymmetryplanesBumpyspheretetrahedron();
	afx_msg void OnViewSymmetryplanesNone();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	unsigned long int CountAllPositives(int sym_type, long double dthr);
	void EvaluateRidgeResults(int sym_type, long double uthr, long double lthr, long double dthr);
	void TrackRidgesAndFlexcords(int cam, long double T_lo, long double T_hi, BOOL minridges);
	void PropagateCurvatureLabels(int slice1, int index1, int slice2, int index2);
	BOOL SliceIndexInBounds(int slice, int index, int cam);
	void TrackCurvatureLinesLocally(int slice, int index, int cam, int& counter, unsigned int sc);
	void TrackCurvatureLines(int cam);
	void SetDisplayProperties(int component);
	BOOL m_showPointCloud;
	BOOL m_showOutlierCloud;
	BOOL m_showCoordOrigin;
	BOOL m_showRefFrame;
	BOOL m_showConnected_0;
	BOOL m_showConnected_1;
	BOOL m_showConnected_2;
	BOOL m_showConnected_3;
	BOOL m_showConnected_4;
	BOOL m_showConnected_5;
	BOOL m_showConnected_6;
	BOOL m_showConnected_7;
	BOOL m_showTextureEdgels;
	BOOL m_showRidges;
	BOOL m_showFlexcords;
	BOOL m_showCurvatureDirections;
	BOOL m_showCurvatureDirectionsRed;
	BOOL m_showCurvatureDirectionsBlue;
	BOOL m_showPhotorealistic;

	int m_ColourMappingMode;
	int m_SymmetryMode;

	//completion flags
	BOOL m_surface_smoothed;
	BOOL m_curv_map_calculated;
	BOOL m_texture_edges_detected;
};

/////////////////////////////////////////////////////////////////////////////

#endif // __doc_INCLUDED
