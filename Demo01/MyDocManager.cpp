#include "stdafx.h"
#include "MyMFC.h"


IMPLEMENT_MYDYNAMIC(CMyDocManager, CMyObject)


CMyDocManager::CMyDocManager()
{
}


CMyDocManager::~CMyDocManager()
{
}


void CMyDocManager::AddDocTemplate(CMyDocTemplate* pTemplate){
	m_templateList.push_back(pTemplate);
	return;
}


void CMyDocManager::OnFileNew(){
	if (m_templateList.empty()){
		return;
	}
	CMyDocTemplate * pTemplate = m_templateList.front();
	pTemplate->OpenDocumentFile(NULL);
}