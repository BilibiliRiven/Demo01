#pragma once
#include "MyWinApp.h"



class CTestDemoApp :
	public CMyWinApp
{
	MYDECLARE_DYNCREATE(CTestDemoApp)
public:
	CTestDemoApp();
	~CTestDemoApp();
	virtual BOOL InitInstance();
};

