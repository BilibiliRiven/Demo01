#pragma once
#include "MyFrameWnd.h"
class CTestDemoFrame :
	public CMyFrameWnd
{
	MYDECLARE_DYNCREATE(CTestDemoFrame)
public:
	CTestDemoFrame();
	~CTestDemoFrame();
	int OnCreate(CREATESTRUCT *pCreate);
	MYDECLARE_MESSAGE_MAP()
};

