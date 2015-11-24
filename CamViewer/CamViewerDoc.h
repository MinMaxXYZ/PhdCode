// CamViewerDoc.h : interface of the CCamViewerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#include "..\bldefs.h"


class CCamViewerDoc : public CDocument
{
protected: // create from serialization only
	CCamViewerDoc();
	DECLARE_DYNCREATE(CCamViewerDoc)

// Attributes
public:
	float CalcDeterminant(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	float CalcAngle(float v0x, float v0y, float v0z, float v1x, float v1y, float v1z, float v2x, float v2y, float v2z);
	short OpenFile(const CString& input_file);

	int imageData0[MAX_N_SLICES][MAX_N_LEDS];
	int imageData1[MAX_N_SLICES][MAX_N_LEDS];
	int imageData2[MAX_N_SLICES][MAX_N_LEDS];
	int imageData3[MAX_N_SLICES][MAX_N_LEDS];
	int imageData4[MAX_N_SLICES][MAX_N_LEDS];
	int imageData5[MAX_N_SLICES][MAX_N_LEDS];
	int imageData6[MAX_N_SLICES][MAX_N_LEDS];
	int imageData7[MAX_N_SLICES][MAX_N_LEDS];

	float geomData0[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData1[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData2[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData3[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData4[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData5[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData6[MAX_N_SLICES][MAX_N_LEDS][3];
	float geomData7[MAX_N_SLICES][MAX_N_LEDS][3];

	float angleData0[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData1[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData2[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData3[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData4[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData5[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData6[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleData7[MAX_N_SLICES][MAX_N_LEDS][2];

	float maxD[MAX_N_CAMERAS][2];
	float angleDeriv0[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv1[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv2[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv3[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv4[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv5[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv6[MAX_N_SLICES][MAX_N_LEDS][2];
	float angleDeriv7[MAX_N_SLICES][MAX_N_LEDS][2];

	BYTE flag0[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag1[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag2[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag3[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag4[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag5[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag6[MAX_N_SLICES][MAX_N_LEDS][2];
	BYTE flag7[MAX_N_SLICES][MAX_N_LEDS][2];

	unsigned int N_CAMERAS;
	unsigned int N_SLICES;
	unsigned int N_LEDS;

	unsigned int N_GSCALES;
	unsigned int N_CHANNELS;
	unsigned int N_COLS;


// Operations
public:
	void CalculateAngles();
	void CalculateAngles(	int (* i)[MAX_N_SLICES][MAX_N_LEDS], 
							float (* g)[MAX_N_SLICES][MAX_N_LEDS][3],
							float (* r)[MAX_N_SLICES][MAX_N_LEDS][2]);

	void CalculateAngleDerivatives();
	void CalculateAngleDerivatives(	int (* i)[MAX_N_SLICES][MAX_N_LEDS], 
		float (* g)[MAX_N_SLICES][MAX_N_LEDS][2],
		float (* r)[MAX_N_SLICES][MAX_N_LEDS][2],
		 BYTE (* f)[MAX_N_SLICES][MAX_N_LEDS][2],
		int cam);	


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamViewerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCamViewerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};

/////////////////////////////////////////////////////////////////////////////
