#include "stdafx.h"
#include "MyDocTemplate.h"


IMPLEMENT_MYDYNAMIC(CMyDocTemplate, CMyCmdTarget)


CMyDocTemplate::CMyDocTemplate(
	UINT nIDResource,
	CMyRuntimeClass* pDocClass,
	CMyRuntimeClass* pFrameClass,
	CMyRuntimeClass* pViewClass)
{
	m_nIDResource = nIDResource;
	m_pDocClass = pDocClass;
	m_pFrameClass = pFrameClass;
	m_pViewClass = pViewClass;
}


CMyDocTemplate::~CMyDocTemplate()
{
}
