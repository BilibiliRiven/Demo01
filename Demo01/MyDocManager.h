#pragma once
#include "MyObject.h"
class CMyDocTemplate;


class CMyDocManager :
	public CMyObject
{
	MYDECLARE_DYNCREATE(CMyDocManager)
public:
	CMyDocManager();
	~CMyDocManager();
	void AddDocTemplate(CMyDocTemplate* pTemplate);
	virtual void OnFileNew();
protected:
	list<CMyDocTemplate*> m_templateList;
};

