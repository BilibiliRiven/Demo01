#pragma once
#include "MyDocument.h"

class CTestDemoDoc :
	public CMyDocument
{
	MYDECLARE_DYNCREATE(CTestDemoDoc)
public:
	CTestDemoDoc();
	~CTestDemoDoc();
};

