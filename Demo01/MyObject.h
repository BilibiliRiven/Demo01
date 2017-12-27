#pragma once
#include <windows.h>
#include <list>
struct  CMyRuntimeClass;

class CMyArchive;

class CMyObject
{
public:
	static const  CMyRuntimeClass classCMyObject;

	virtual CMyRuntimeClass* GetMyRuntimeClass() const;
	virtual ~CMyObject();
	BOOL IsKindOf(const CMyRuntimeClass* pClass) const;
	virtual void Serialize(CMyArchive& archive);
protected:
	CMyObject();
};

struct CMyRuntimeClass
{
	// Attributes
	LPCSTR m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema; // schema number of the loaded class
	CMyObject* (*m_pfnCreateObject)(); // NULL => abstract class
	//#ifdef _AFXDLL
	//	CRuntimeClass* (PASCAL* m_pfnGetBaseClass)();
	//#else
	CMyRuntimeClass* m_pBaseClass;
	//#endif

	// Operations
	CMyObject* CreateObject();
	BOOL IsDerivedFrom(const CMyRuntimeClass* pBaseClass) const;

	// Implementation
	// void Store(CArchive& ar) const;
	// static CMyRuntimeClass* PASCAL Load(CArchive& ar, UINT* pwSchemaNum);

	// CRuntimeClass objects linked together in simple list
	CMyRuntimeClass* m_pNextClass;       // linked list of registered classes
};

extern std::list<CMyRuntimeClass*> g_RuntimeList;

#define _MYRUNTIME_CLASS(class_name) ((CMyRuntimeClass*)(&class_name::class##class_name))
#define MYRUNTIME_CLASS(class_name) _MYRUNTIME_CLASS(class_name)

#define MYDECLARE_DYNAMIC(class_name) \
public: \
	static const  CMyRuntimeClass class##class_name; \
	virtual CMyRuntimeClass* GetMyRuntimeClass() const; \

#define _MYDECLARE_DYNAMIC(class_name) \
public: \
	static  CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define MYDECLARE_DYNCREATE(class_name) \
	MYDECLARE_DYNAMIC(class_name) \
	static CMyObject*  CreateObject();

#define _MYDECLARE_DYNCREATE(class_name) \
	_MYDECLARE_DYNAMIC(class_name) \
	static CObject*  CreateObject();


#define MYDECLARE_SERIAL(class_name) \
	_MYDECLARE_DYNCREATE(class_name) \
	friend CMyArchive& __stdcall operator>>(CMyArchive& ar, class_name* &pOb);

/////////////////////////////////////////////////////////////////////////////////////
// Implement

#define IMPLEMENT_MYRUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	 const  CMyRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			_MYRUNTIME_CLASS(base_class_name), NULL }; \
	CMyRuntimeClass* class_name::GetMyRuntimeClass() const \
		{ return _MYRUNTIME_CLASS(class_name); } \


#define _IMPLEMENT_MYRUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CMyRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			MYRUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CMyRuntimeClass* class_name::GetMyRuntimeClass() const \
		{ return MYRUNTIME_CLASS(class_name); }


#define IMPLEMENT_MYDYNAMIC(class_name, base_class_name) \
	IMPLEMENT_MYRUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL)


#define IMPLEMENT_MYDYNCREATE(class_name, base_class_name) \
	CMyObject*  class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_MYRUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject)


#define IMPLEMENT_MYSERIAL(class_name, base_class_name, wSchema) \
	CObject* __stdcall class_name::CreateObject() \
		{ return new class_name; } \
	extern MY_AFX_CLASSINIT _init_##class_name; \
	_IMPLEMENT_MYRUNTIMECLASS(class_name, base_class_name, wSchema, \
		class_name::CreateObject, &_init_##class_name) \
	MY_AFX_CLASSINIT _init_##class_name(MYRUNTIME_CLASS(class_name)); \
	CArchive& __stdcall operator>>(CMyArchive& ar, class_name* &pOb) \
		{ pOb = (class_name*) ar.ReadObject(MYRUNTIME_CLASS(class_name)); \
			return ar; }



struct MY_AFX_CLASSINIT
{
	MY_AFX_CLASSINIT(CMyRuntimeClass* pNewClass) { /*MyAfxClassInit(pNewClass);*/g_RuntimeList.push_back(pNewClass); }
};


class CMyArchive
{
public:
	enum Mode { store = 0, load = 1, bNoFlushOnDelete = 2, bNoByteSwap = 4 };
public:
	CMyArchive(enum Mode nMode)
	{
		m_nMode = nMode;
	}
	BOOL IsStoring() const
	{
		return (m_nMode & CMyArchive::load) == 0;
	}

	void Write(BYTE *pBuff, int Size)
	{
		for (int i = 0; i < Size; i++)
			printf("%02X ", pBuff[i]);
	}

	CMyArchive& operator << (int n)
	{
		Write((BYTE*)&n, sizeof(n));
		return *this;
	}
	CMyArchive& operator << (UINT n)
	{
		Write((BYTE*)&n, sizeof(n));
		return *this;
	}
	CMyArchive& operator << (WORD n)
	{
		Write((BYTE*)&n, sizeof(n));
		return *this;
	}
	CMyArchive& operator >> (int& n)
	{
		return *this;
	}
	CMyArchive& operator << (CMyObject *pObj)
	{
		//完成序列化
		CMyRuntimeClass* pClassRef = pObj->GetMyRuntimeClass();

		*this << (WORD)0xffff; //文件特征
		*this << (WORD)pClassRef->m_wSchema; //文件特征
		*this << (WORD)strlen(pClassRef->m_lpszClassName);
		Write((BYTE*)pClassRef->m_lpszClassName, strlen(pClassRef->m_lpszClassName));

		pObj->Serialize(*this);
		return *this;
	}
private:
	Mode m_nMode;
};
