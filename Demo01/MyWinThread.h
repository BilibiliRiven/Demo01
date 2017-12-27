#pragma once
#include "MyCmdTarget.h"

class CMyWnd;

class CMyWinThread :
	public CMyCmdTarget
{
	MYDECLARE_DYNAMIC(CMyWinThread)
public:

	CMyWinThread();
	~CMyWinThread();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
public:
	CMyWnd * m_pMainWnd;      // main window (usually same AfxGetApp()->m_pMainWnd)
};

