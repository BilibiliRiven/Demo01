#include "stdafx.h"
#include "MyDocument.h"


IMPLEMENT_MYDYNAMIC(CMyDocument, CMyCmdTarget)


CMyDocument::CMyDocument()
{
	cout << "CMyDocument Constructor" << endl;
}


CMyDocument::~CMyDocument()
{
	cout << "CMyDocument Destructor" << endl;
}
