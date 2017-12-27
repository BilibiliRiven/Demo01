#pragma once
#include "MyDocTemplate.h"

struct CMyRuntimeClass;
class CMyDocument;


class CMySingleDocTemplate :
	public CMyDocTemplate
{
	MYDECLARE_DYNAMIC(CMySingleDocTemplate)
public:
	CMySingleDocTemplate(UINT nIDResource,
		CMyRuntimeClass* pDocClass,
		CMyRuntimeClass* pFrameClass,
		CMyRuntimeClass* pViewClass);
	
	~CMySingleDocTemplate();
	
	virtual CMyDocument* OpenDocumentFile(
		LPCTSTR lpszPathName,
		BOOL bMakeVisible = TRUE);
protected:  // standard implementation
	CMyDocument* m_pOnlyDoc;
};

