// Histogram.h : header file
//

#define MAX_HIST_SIZE	501
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CHistogram window

class CHistogram 
{
// Construction
public:
	CHistogram();
	CHistogram(long double mn_range, long double mx_range, unsigned int n_clusters);
	CHistogram(long double mn_range, long double mx_range, long double cluster_width);

// Attributes
public:

// Operations
public:
	void IncrementCluster(unsigned int m);
	void Add(long double x);
	unsigned long int Get(unsigned int n);
	unsigned long int GetPeak();
	unsigned int GetPeakPos();
	long double GetPeakVal();
	unsigned int GetNClusters();
	long double GetMin();
	long double GetMax();
	long double GetClusterWidth();
	void Cumulative();

// Implementation
public:
	virtual ~CHistogram();

protected:
	unsigned long int h[MAX_HIST_SIZE];
	BOOL m_Cumulative;
	long double m_range_min;
	long double m_range_max;
	long double m_cluster_width;
	long double m_n_clusters;

};

/////////////////////////////////////////////////////////////////////////////