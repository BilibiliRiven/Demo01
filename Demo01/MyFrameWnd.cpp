#include "stdafx.h"
#include "MyMFC.h"


IMPLEMENT_MYDYNCREATE(CMyFrameWnd, CMyWnd)


CMyFrameWnd::CMyFrameWnd()
{
	cout << "CMyFrameWnd Constructor" << endl;
}


CMyFrameWnd::~CMyFrameWnd()
{
	cout << "CMyFrameWnd Constructor" << endl;
}


BOOL CMyFrameWnd::LoadFrame(UINT nIDResource,
	DWORD dwDefaultStyle,
	CMyWnd* pParentWnd,
	CMyCreateContext* pContext){
	HMENU hMenu = NULL;

	//×¢²á´°¿Ú
	WNDCLASS wc;
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)DefWindowProc;;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = MyGetInstanceHandle();
	wc.hIcon = ::LoadIcon((HINSTANCE)NULL,
		IDI_APPLICATION);
	wc.hCursor = ::LoadCursor((HINSTANCE)NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL; // _T("MainMenu");
	wc.lpszClassName = _T("CR26WndClass");

	if (!::RegisterClass(&wc))
		return FALSE;

	LPCTSTR lpszClass = _T("CR26WndClass");
	LPCTSTR lpszTitle = _T("CR26 Title");
	RECT rectDefault = { 0, 0, 1000, 500 };
	if (!Create(lpszClass, lpszTitle, dwDefaultStyle, rectDefault,
		pParentWnd, MAKEINTRESOURCE(nIDResource), 0L, pContext))
	{
		return FALSE;   // will self destruct on failure normally
	}

	return TRUE;

}


BOOL CMyFrameWnd::Create(
	LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName,
	DWORD dwStyle,
	const RECT& rect,
	CMyWnd* pParentWnd,
	LPCTSTR lpszMenuName,
	DWORD dwExStyle,
	CMyCreateContext* pContext){

	HMENU hMenu = NULL;
	hMenu = ::LoadMenu(MyGetInstanceHandle(), lpszMenuName);

	if (!CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		pParentWnd->GetSafeHwnd(), hMenu, (LPVOID)pContext))
	{
		return FALSE;
	}

	return TRUE;
}