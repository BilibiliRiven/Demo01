#pragma once
#include "MyCmdTarget.h"

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
class CScrollBar;

class CMyWnd :
	public CMyCmdTarget
{
	MYDECLARE_DYNCREATE(CMyWnd)
public:
	CMyWnd();
	~CMyWnd();
	BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		int x, int y, int nWidth, int nHeight,
		HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam);
	HWND GetSafeHwnd() const;
	BOOL ShowWindow(int nCmdShow);
	void UpdateWindow();

	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL DestroyWindow();
	BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	BOOL OnCreate(CREATESTRUCT *pCreate);
	BOOL OnLButtonDown(int x, int y);
	BOOL OnLButtonUp(int x, int y);

	static CMyWnd * FromHandle(HWND hWnd);
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	BOOL Attach(HWND hWndNew);
public:
	HWND m_hWnd;
	WNDPROC m_pfnSuper; // for subclassing of controls

	MYDECLARE_MESSAGE_MAP()
};


LRESULT CALLBACK CR26WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

