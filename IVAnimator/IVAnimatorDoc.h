#ifndef __doc_INCLUDED
#define __doc_INCLUDED


// IVAnimatorDoc.h : interface of the CIVAnimatorDoc class
//
/////////////////////////////////////////////////////////////////////////////


// BEGIN_IVWGEN
#include <Ivf/IvfDocument.h>
// END_IVWGEN

#include <Inventor/nodes/SoFile.h>
#include <Inventor/nodes/SoGroup.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoBlinker.h>

#define MAX_NFRAMES	100

// BEGIN_IVWGEN
class CIVAnimatorDoc : public CDocument , public CIvfDocument
{
// END_IVWGEN
protected: // create from serialization only
	CIVAnimatorDoc();
	DECLARE_DYNCREATE(CIVAnimatorDoc)

	BOOLEAN m_bContainsCamera;

// Attributes
public:
	BOOL EnableMovieController;
	SoBlinker* myblinker;
	BOOL OpenFiles(const CString& input_file);
	unsigned int n_frames;
	SoSeparator* myframe[MAX_NFRAMES];
	SoSeparator* root;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIVAnimatorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIVAnimatorDoc();
	virtual void IvfSetupUrlFetchCallback(void);
	BOOL HasAnchors(void) { return (m_pAnchorList != NULL); }
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIVAnimatorDoc)
	afx_msg void OnFileImport();
	afx_msg void OnUpdateFileImport(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewpoints(CCmdUI *pCmdUI);
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileReload();
	afx_msg void OnUpdateFileReload(CCmdUI *pCmdUI);
	afx_msg void OnViewMoviecontroller();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
#endif // __doc_included
