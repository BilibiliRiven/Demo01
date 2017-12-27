#include "stdafx.h"
#include "MyObject.h"


const struct CMyRuntimeClass CMyObject::classCMyObject =
{ "CMyObject", sizeof(CMyObject), 0xffff, NULL, NULL, NULL };


CMyObject::CMyObject(){
	cout << "CObject Constructor \n";
}


CMyObject::~CMyObject(){
	cout << "~CObject Constructor \n";
}


BOOL CMyObject::IsKindOf(const CMyRuntimeClass* pClass) const{
	//	ENSURE(this != NULL);
	// it better be in valid memory, at least for CObject size
	//ASSERT(AfxIsValidAddress(this, sizeof(CMyObject)));

	// simple SI case
	CMyRuntimeClass* pClassThis = GetMyRuntimeClass();

	//ENSURE(pClassThis);
	return pClassThis->IsDerivedFrom(pClass);
}


CMyRuntimeClass* CMyObject::GetMyRuntimeClass() const
{
	return _MYRUNTIME_CLASS(CMyObject);
}


BOOL CMyRuntimeClass::IsDerivedFrom(const CMyRuntimeClass* pBaseClass) const
{
	//ENSURE(this != NULL);
	//ASSERT(AfxIsValidAddress(this, sizeof(CRuntimeClass), FALSE));
	//ENSURE(pBaseClass != NULL);
	//ASSERT(AfxIsValidAddress(pBaseClass, sizeof(CRuntimeClass), FALSE));

	// simple SI case
	const CMyRuntimeClass* pClassThis = this;
//#ifdef _AFXDLL
//	for (;;)
//#else
	while (pClassThis != NULL)
//#endif
	{
		if (pClassThis == pBaseClass)
			return TRUE;
//#ifdef _AFXDLL
//		if (pClassThis->m_pfnGetBaseClass == NULL)
//			break;
//		pClassThis = (*pClassThis->m_pfnGetBaseClass)();
//#else
		pClassThis = pClassThis->m_pBaseClass;
//#endif
	}
	return FALSE;       // walked to the top, no match
}


void CMyObject::Serialize(CMyArchive& archive)
{
}

