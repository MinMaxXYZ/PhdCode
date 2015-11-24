// CurvatureProfile.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCurvatureProfile window

class CCurvatureProfile 
{
// Construction
public:
	BOOL nearUmbilic();
	CCurvatureProfile();	// Default constructor

// Attributes
public:
	BOOL exists;			// flag to indincate successful calculation
	BOOL tracked;			// flag to indincate that the vertex has propagated its colour labels
	BOOL ridge;
	BOOL flexcord;

	unsigned short int redlabel;	//	values:
									// 0 - point is umbilic 
									// 1 - red curvature is k1
									// 2 - red curvature is k2
									// 3 - point is still unclassified

	long double k1;				// principal curvatures
	long double k2;

	long double K;				// gaussian curvature
	long double H;				// mean curvature

	long double R;				// curvedness
	long double S;				// shape index
	long double C;				// natural logarithm of curvedness

	long double v1[3];			// principal curvature directions
	long double v2[3];

public:
	virtual ~CCurvatureProfile();

};

/////////////////////////////////////////////////////////////////////////////
