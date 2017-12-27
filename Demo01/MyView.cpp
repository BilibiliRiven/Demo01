#include "stdafx.h"
#include "MyView.h"


IMPLEMENT_MYDYNAMIC(CMyView, CMyWnd)


CMyView::CMyView()
{
	cout << "CMyView Constructor \n";
}


CMyView::~CMyView()
{
	cout << "CMyView Destructor \n";
}
