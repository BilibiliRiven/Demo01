#include "stdafx.h"
#include "MyMFC.h"


IMPLEMENT_MYDYNCREATE(CTestDemoApp, CMyWinApp)



CTestDemoApp::CTestDemoApp()
{

	cout << "CTestDemoApp Constructor" << endl;
}


CTestDemoApp::~CTestDemoApp()
{
	// cout << "CTestDemoApp Desstructor" << endl;
}




BOOL CTestDemoApp::InitInstance(){


	CMySingleDocTemplate* pDocTemplate;
	pDocTemplate = new CMySingleDocTemplate(
		(UINT)NULL,
		_MYRUNTIME_CLASS(CTestDemoDoc),
		_MYRUNTIME_CLASS(CTestDemoFrame),       // main SDI frame window
		_MYRUNTIME_CLASS(CTestDemoView));
	AddDocTemplate(pDocTemplate);

	CMyWinApp::OnFileNew();

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}




