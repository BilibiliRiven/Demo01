#include "stdafx.h"
#include "MyMFC.h"


IMPLEMENT_MYDYNAMIC(CMySingleDocTemplate, CMyDocTemplate)


CMySingleDocTemplate::CMySingleDocTemplate(
	UINT nIDResource,
	CMyRuntimeClass* pDocClass,
	CMyRuntimeClass* pFrameClass,
	CMyRuntimeClass* pViewClass)
	: CMyDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
	m_pOnlyDoc = NULL;
}


CMySingleDocTemplate::~CMySingleDocTemplate()
{
}


CMyDocument* CMySingleDocTemplate::OpenDocumentFile(
	LPCTSTR lpszPathName,
	BOOL bMakeVisible){
	CMyDocument * pDocument = NULL;
	CMyFrameWnd * pFrame = NULL;

	if (m_pOnlyDoc == NULL){
		pDocument = (CMyDocument *)m_pDocClass->m_pfnCreateObject();
		m_pOnlyDoc = pDocument;

		pFrame = (CMyFrameWnd *)m_pFrameClass->m_pfnCreateObject();


		CMyWinThread* pThread = MyAfxGetThread();
		pThread->m_pMainWnd = pFrame;

		CMyCreateContext context;
		context.m_pView = m_pViewClass;
		pFrame->LoadFrame(m_nIDResource, WS_OVERLAPPEDWINDOW, NULL, &context);
	}

	return pDocument;
}