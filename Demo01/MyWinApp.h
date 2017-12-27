#pragma once
#include "MyWinThread.h"


class CMyDocTemplate;
class CMyDocManager;


class CMyWinApp :
	public CMyWinThread
{
	MYDECLARE_DYNAMIC(CMyWinApp)
public:
	CMyWinApp();
	~CMyWinApp();
public:
	CMyWinApp * m_pCurrentWinApp;
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual void OnFileNew();
	void AddDocTemplate(CMyDocTemplate* pTemplate);
protected:
	CMyDocManager * m_pDocManager;
};

