// Histogram.cpp : implementation file
//

#include "stdafx.h"
#include "Histogram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistogram

CHistogram::CHistogram()
{
	m_Cumulative = FALSE;
	m_cluster_width = 0.0;
	m_n_clusters = 0;
	m_range_max = 1.0;
	m_range_min = -1.0;
	for(int i = 0; i < MAX_HIST_SIZE; i++) {h[i]=0;}
}

CHistogram::CHistogram(long double mn_range, long double mx_range, unsigned int n_clusters)
{
	ASSERT(mx_range>mn_range);
	ASSERT(n_clusters>0);
	m_range_min = mn_range;
	m_range_max = mx_range;
	m_n_clusters = n_clusters;
	m_cluster_width = (m_range_max-m_range_min)/m_n_clusters;
	for(int i = 0; i < MAX_HIST_SIZE; i++) {h[i]=0;}
}

CHistogram::CHistogram(long double mn_range, long double mx_range, long double cluster_width)
{
	ASSERT(mx_range>mn_range);
	ASSERT(cluster_width>0.0);
	m_range_min = mn_range;
	m_range_max = mx_range;
	m_cluster_width = cluster_width;
	m_n_clusters = (m_range_max-m_range_min)/m_cluster_width;
	for(int i = 0; i < MAX_HIST_SIZE; i++) {h[i]=0;}
}

CHistogram::~CHistogram()
{
}


void CHistogram::IncrementCluster(unsigned int m)
{
	ASSERT(m<m_n_clusters);
	h[m]+=1;
}


void CHistogram::Add(long double x)
{		
	ASSERT(x>=m_range_min);
	ASSERT(x<=m_range_max);

	//workout cluster c
	unsigned int c = (unsigned int)floor( ((long double)m_n_clusters) * ((x-m_range_min)/(m_range_max-m_range_min)) );

	//correction for the top value
	if(x == m_range_max) {c-=1;}

	//add to the cluster
	IncrementCluster(c);
}

unsigned long int CHistogram::Get(unsigned int n)
{
	ASSERT(n<m_n_clusters);
	return(h[n]);
}

unsigned int CHistogram::GetNClusters()
{
	return((unsigned int)m_n_clusters);
}


void CHistogram::Cumulative()
{
	ASSERT(m_Cumulative==FALSE);
	for(int i = 1; i < m_n_clusters; i++) {h[i]+=h[i-1];}
	m_Cumulative = TRUE;
}

long double CHistogram::GetMin()
{
	return m_range_min;
}

long double CHistogram::GetMax()
{
	return m_range_max;
}

long double CHistogram::GetClusterWidth()
{
	return m_cluster_width;
}

unsigned long int CHistogram::GetPeak()
{
	unsigned long int peak = h[0];
	for(unsigned int i = 1; i < m_n_clusters; i++)
	{
		if (h[i] > peak) {peak = h[i];}
	}
	return peak;
}

long double CHistogram::GetPeakVal()
{
	unsigned int peak_pos = 0;
	unsigned long int peak = h[0];
	for(unsigned int i = 1; i < m_n_clusters; i++)
	{
		if (h[i] > peak) {peak_pos = i;}
	}
	long double peak_val = m_range_min+(((long double)peak_pos)*m_cluster_width)+(m_cluster_width/2.0);

	if (		(fabs(peak_val)<0.01) 	) {peak_val = 0.0;}
	
	return peak_val;
}

unsigned int CHistogram::GetPeakPos()
{
	unsigned int peak_pos = 0;
	unsigned long int peak = h[0];
	for(unsigned int i = 1; i < m_n_clusters; i++)
	{
		if (h[i] > peak) {peak_pos = i;}
	}
	return peak_pos;
}
