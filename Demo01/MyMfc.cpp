#include "stdafx.h"
#include "MyMFC.h"

CTestDemoApp theApp;
list<CMyRuntimeClass*> g_RuntimeList;
HINSTANCE g_hInstance;
typedef list<CMyRuntimeClass*>::iterator MyIterator;


CMyWinApp * MyAfxGetApp(){
	return theApp.m_pCurrentWinApp;
}


CMyWinThread * MyAfxGetThread(){
	return &theApp;
}


HINSTANCE  MyGetInstanceHandle()
{
	return g_hInstance;
}


int MYAFXAPI MyAfxWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine, int nCmdShow)
{

//ASSERT(hPrevInstance == NULL);

	int nReturnCode = -1;
	CMyWinThread* pThread = MyAfxGetThread();
	CMyWinApp* pApp = MyAfxGetApp();

	g_hInstance = hInstance;

	if (!pThread->InitInstance())
	{
		if (pThread->m_pMainWnd != NULL)
		{
			printf("Warning: Destroying non-NULL m_pMainWnd\n");
			pThread->m_pMainWnd->DestroyWindow();
		}
		nReturnCode = pThread->ExitInstance();
		goto InitFailure;
	}
	nReturnCode = pThread->Run();
//
	InitFailure:

//	return nReturnCode;
	return 0;
}