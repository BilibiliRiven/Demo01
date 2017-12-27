#pragma once
#include "MyCmdTarget.h"


class CMyDocument;


class CMyDocTemplate :
	public CMyCmdTarget
{
	MYDECLARE_DYNAMIC(CMyDocTemplate)
public:
	CMyDocTemplate(
		UINT nIDResource,
		CMyRuntimeClass* pDocClass,
		CMyRuntimeClass* pFrameClass,
		CMyRuntimeClass* pViewClass);

	~CMyDocTemplate();

	virtual CMyDocument* OpenDocumentFile(
		LPCTSTR lpszPathName,
		BOOL bMakeVisible = TRUE) = 0;
protected:
	UINT m_nIDResource;                 // IDR_ for frame/menu/accel as well
	CMyRuntimeClass * m_pDocClass;
	CMyRuntimeClass * m_pFrameClass;
	CMyRuntimeClass * m_pViewClass;
};

