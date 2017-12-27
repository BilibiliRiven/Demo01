#include "stdafx.h"
#include "MyMFC.h"


IMPLEMENT_MYDYNCREATE(CTestDemoFrame, CMyFrameWnd)
MYBEGIN_MESSAGE_MAP(CTestDemoFrame, CMyFrameWnd)
	ON_WM_CREATE()
MYEND_MESSAGE_MAP()

CTestDemoFrame::CTestDemoFrame()
{
}


CTestDemoFrame::~CTestDemoFrame()
{
}


BOOL CTestDemoFrame::OnCreate(CREATESTRUCT *pCreate)
{
	return TRUE;
}
