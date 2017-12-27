#pragma once
#include "MyWnd.h"

class CMyCreateContext;

class CMyFrameWnd :
	public CMyWnd
{
	MYDECLARE_DYNCREATE(CMyFrameWnd)
public:
	CMyFrameWnd();
	~CMyFrameWnd();
	virtual BOOL LoadFrame(UINT nIDResource,
		DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW,
		CMyWnd* pParentWnd = NULL,
		CMyCreateContext* pContext = NULL);
	BOOL Create(
		LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName,
		DWORD dwStyle,
		const RECT& rect,
		CMyWnd* pParentWnd,
		LPCTSTR lpszMenuName,
		DWORD dwExStyle,
		CMyCreateContext* pContext);
};

