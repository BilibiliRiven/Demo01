#include "stdafx.h"
#include "MyMFC.h"


IMPLEMENT_MYDYNAMIC(CMyWinApp, CMyWinThread)

CMyWinApp::CMyWinApp()
{
	// m_pCurrentWinApp = this;
	cout << "CMyWinApp Constructor" << endl;
	m_pDocManager = NULL;
}


CMyWinApp::~CMyWinApp()
{
	cout << "CMyWinApp Destructor" << endl;
}


BOOL CMyWinApp::InitInstance()
{
	return FALSE;
}


int CMyWinApp::ExitInstance()
{
	return 0;
}


void CMyWinApp::AddDocTemplate(CMyDocTemplate* pTemplate)
{
	if (m_pDocManager == NULL)
		m_pDocManager = new CMyDocManager;
	m_pDocManager->AddDocTemplate(pTemplate);
}


void CMyWinApp::OnFileNew(){
	m_pDocManager->OnFileNew();
}