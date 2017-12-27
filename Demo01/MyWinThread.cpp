#include "stdafx.h"
#include "MyWinThread.h"


IMPLEMENT_MYDYNAMIC(CMyWinThread, CMyCmdTarget)

CMyWinThread::CMyWinThread()
{
	cout << "CMyWinThread Constructor" << endl;
}


CMyWinThread::~CMyWinThread()
{
	cout << "CMyWinThread Destructor" << endl;
}


BOOL CMyWinThread::InitInstance(){
	return FALSE;
}


int CMyWinThread::ExitInstance(){
	return 0;
}


int CMyWinThread::Run(){
	MSG msg;
	BOOL bRet;

	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			break;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}