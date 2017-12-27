#include "stdafx.h"
#include "MyMFC.h"
#include <map>


IMPLEMENT_MYDYNCREATE(CMyWnd, CMyCmdTarget)

MYBEGIN_MESSAGE_MAP(CMyWnd, CMyCmdTarget)
ON_WM_CREATE()
ON_WM_HSCROLL()
MYEND_MESSAGE_MAP()

WNDPROC g_pfnOldProc;
map<HWND, CMyWnd*> g_mapHWND;
CMyWnd * g_pWndInit = NULL;
HHOOK g_hHook;

CMyWnd::CMyWnd()
{
	m_hWnd = NULL;
	cout << "CMyWnd Constructor" << endl;
}


CMyWnd::~CMyWnd()
{
	cout << "CMyWnd Desstructor" << endl;
}


LRESULT CALLBACK MyCbtFilterHook(int code, WPARAM wParam, LPARAM lParam)
{
	if (code == HCBT_CREATEWND)
	{

		//子类化
		HWND hWnd = (HWND)wParam;

		//保存HWND和CWnd的映射关系
		if (g_pWndInit){
			g_pWndInit->Attach(hWnd);

			g_pfnOldProc = (WNDPROC)::SetWindowLong(hWnd, GWL_WNDPROC, (LONG)CR26WindowProc);

			g_pWndInit->m_pfnSuper = g_pfnOldProc;
			g_pWndInit = NULL;
		}
	}
	return CallNextHookEx(g_hHook, code, wParam, lParam);
}


BOOL CMyWnd::CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName, DWORD dwStyle,
	int x, int y, int nWidth, int nHeight,
	HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam){

	CREATESTRUCT cs;
	cs.dwExStyle = dwExStyle;
	cs.lpszClass = lpszClassName;
	cs.lpszName = lpszWindowName;
	cs.style = dwStyle;
	cs.x = x;
	cs.y = y;
	cs.cx = nWidth;
	cs.cy = nHeight;
	cs.hwndParent = hWndParent;
	cs.hMenu = nIDorHMenu;
	cs.hInstance = MyGetInstanceHandle();
	cs.lpCreateParams = lpParam;

	g_pWndInit = this;
	g_hHook = ::SetWindowsHookEx(WH_CBT, MyCbtFilterHook, NULL, ::GetCurrentThreadId());

	HWND hWnd = ::CreateWindowEx(cs.dwExStyle, cs.lpszClass,
		cs.lpszName, cs.style, cs.x, cs.y, cs.cx, cs.cy,
		cs.hwndParent, cs.hMenu, cs.hInstance, cs.lpCreateParams);

	::UnhookWindowsHookEx(g_hHook);

	m_hWnd = hWnd;
	return TRUE;
}


HWND CMyWnd::GetSafeHwnd() const
{	
	return this == NULL ? NULL : m_hWnd;
}


BOOL CMyWnd::ShowWindow(int nCmdShow)
{
	return ::ShowWindow(m_hWnd, nCmdShow);
}


void CMyWnd::UpdateWindow()
{
	::UpdateWindow(m_hWnd);
}


BOOL CMyWnd::DestroyWindow(){
	return FALSE;
}


BOOL CMyWnd::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	LRESULT result = FALSE;

	for (const MY_MSGMAP * pMsgMap = GetMessageMap(); pMsgMap != NULL; pMsgMap = pMsgMap != NULL ?0 : pMsgMap->pfnGetBaseMap()){
		for (const MY_MSGMAP_ENTRY *pMsgEntry = pMsgMap->lpEntries; pMsgEntry != NULL && pMsgEntry->nSig != MySig_end; pMsgEntry++){

			if (pMsgEntry->nMessage == message)
			{
				MyMsgFunctions mmf;
				mmf.pfn = pMsgEntry->pfn;

				//(this->*(void (CMyCmdTarget::*)(void*))pMsgEntry->pfn)(NULL);

				switch (pMsgEntry->nSig)
				{
				case MySig_vv:
					(this->*mmf.pfn_vv)();
					break;
				case MySig_vpv:
					(this->*mmf.pfn_bD)(NULL);
					break;
				case MySig_is:
					(this->*mmf.pfn_is)((LPTSTR)lParam);
					break;
				}

				goto EXIT;
			}
		}
	}

	EXIT:
	return *pResult = result;
}


BOOL CMyWnd::OnCreate(CREATESTRUCT *pCreate)
{
	return FALSE;
}


BOOL CMyWnd::OnLButtonDown(int x, int y)
{
	// MessageBox(m_hWnd, NULL, NULL, MB_OK);
	return FALSE;
}


BOOL CMyWnd::OnLButtonUp(int x, int y)
{
	MessageBox(m_hWnd, NULL, NULL, MB_OK);
	return FALSE;
}


CMyWnd * CMyWnd::FromHandle(HWND hWnd){
	return g_mapHWND[hWnd];
}


#define WM_QUERYAFXWNDPROC  0x0360  // lResult = 1 if processed by AfxWndProc
LRESULT CALLBACK CR26WindowProc(HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{

	if (uMsg == WM_QUERYAFXWNDPROC)
		return 1;
	CMyWnd * pWnd = NULL;
	pWnd = CMyWnd::FromHandle(hwnd);

	if (pWnd){
		return pWnd->WindowProc(uMsg, wParam, lParam);
	}
	return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
}


BOOL CMyWnd::Attach(HWND hWndNew)
{
	m_hWnd = hWndNew;
	g_mapHWND[hWndNew] = this;
	return TRUE;
}


LRESULT CMyWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT lResult = 0;
	if (!OnWndMsg(message, wParam, lParam, &lResult))
		lResult = m_pfnSuper(m_hWnd, message, wParam, lParam);
	return lResult;
}


void CMyWnd::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
}

