#pragma once
#include "MyObject.h"

class CMyWinThread;
class CMyCmdTarget;

typedef void (CMyCmdTarget::*MY_PMSG)(void);

#define AFX_MSG_CALL

class CDC;
class CCmdUI;
class CPoint;
class CMenu;
class CMyWnd;

union MyMsgFunctions
{
	MY_PMSG pfn;   // generic member function pointer

	// specific type safe variants for WM_COMMAND and WM_NOTIFY messages
	void (AFX_MSG_CALL CMyCmdTarget::*pfn_COMMAND)();
	BOOL(AFX_MSG_CALL CMyCmdTarget::*pfn_bCOMMAND)();
	void (AFX_MSG_CALL CMyCmdTarget::*pfn_COMMAND_RANGE)(UINT);
	BOOL(AFX_MSG_CALL CMyCmdTarget::*pfn_COMMAND_EX)(UINT);

	void (AFX_MSG_CALL CMyCmdTarget::*pfn_UPDATE_COMMAND_UI)(CCmdUI*);
	void (AFX_MSG_CALL CMyCmdTarget::*pfn_UPDATE_COMMAND_UI_RANGE)(CCmdUI*, UINT);
	void (AFX_MSG_CALL CMyCmdTarget::*pfn_OTHER)(void*);
	BOOL(AFX_MSG_CALL CMyCmdTarget::*pfn_OTHER_EX)(void*);

	void (AFX_MSG_CALL CMyCmdTarget::*pfn_NOTIFY)(NMHDR*, LRESULT*);
	BOOL(AFX_MSG_CALL CMyCmdTarget::*pfn_bNOTIFY)(NMHDR*, LRESULT*);
	void (AFX_MSG_CALL CMyCmdTarget::*pfn_NOTIFY_RANGE)(UINT, NMHDR*, LRESULT*);
	BOOL(AFX_MSG_CALL CMyCmdTarget::*pfn_NOTIFY_EX)(UINT, NMHDR*, LRESULT*);

	// type safe variant for thread messages

	void (AFX_MSG_CALL CMyWinThread::*pfn_THREAD)(WPARAM, LPARAM);

	// specific type safe variants for WM-style messages
	BOOL(AFX_MSG_CALL CMyWnd::*pfn_bD)(CDC*);
	BOOL(AFX_MSG_CALL CMyWnd::*pfn_bb)(BOOL);
	BOOL(AFX_MSG_CALL CMyWnd::*pfn_bWww)(CMyWnd*, UINT, UINT);
	BOOL(AFX_MSG_CALL CMyWnd::*pfn_bHELPINFO)(HELPINFO*);
	BOOL(AFX_MSG_CALL CMyWnd::*pfn_bWCDS)(CMyWnd*, COPYDATASTRUCT*);
	HBRUSH(AFX_MSG_CALL CMyWnd::*pfn_hDWw)(CDC*, CMyWnd*, UINT);
	HBRUSH(AFX_MSG_CALL CMyWnd::*pfn_hDw)(CDC*, UINT);
	int     (AFX_MSG_CALL CMyWnd::*pfn_iwWw)(UINT, CMyWnd*, UINT);
	int     (AFX_MSG_CALL CMyWnd::*pfn_iww)(UINT, UINT);
	int     (AFX_MSG_CALL CMyWnd::*pfn_iWww)(CMyWnd*, UINT, UINT);
	int     (AFX_MSG_CALL CMyWnd::*pfn_is)(LPTSTR);
	LRESULT(AFX_MSG_CALL CMyWnd::*pfn_lwl)(WPARAM, LPARAM);
	LRESULT(AFX_MSG_CALL CMyWnd::*pfn_lwwM)(UINT, UINT, CMenu*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vv)(void);

	void    (AFX_MSG_CALL CMyWnd::*pfn_vw)(UINT);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vww)(UINT, UINT);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vvii)(int, int);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwww)(UINT, UINT, UINT);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwii)(UINT, int, int);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwl)(WPARAM, LPARAM);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vbWW)(BOOL, CMyWnd*, CMyWnd*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vD)(CDC*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vM)(CMenu*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vMwb)(CMenu*, UINT, BOOL);

	void    (AFX_MSG_CALL CMyWnd::*pfn_vW)(CMyWnd*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vWww)(CMyWnd*, UINT, UINT);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vWp)(CMyWnd*, CPoint);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vWh)(CMyWnd*, HANDLE);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwW)(UINT, CMyWnd*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwWb)(UINT, CMyWnd*, BOOL);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwwW)(UINT, UINT, CMyWnd*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwwx)(UINT, UINT);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vs)(LPTSTR);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vOWNER)(int, LPTSTR);   // force return TRUE
	int     (AFX_MSG_CALL CMyWnd::*pfn_iis)(int, LPTSTR);
	UINT(AFX_MSG_CALL CMyWnd::*pfn_wp)(CPoint);
	UINT(AFX_MSG_CALL CMyWnd::*pfn_wv)(void);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vPOS)(WINDOWPOS*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vCALC)(BOOL, NCCALCSIZE_PARAMS*);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwp)(UINT, CPoint);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vwwh)(UINT, UINT, HANDLE);
	BOOL(AFX_MSG_CALL CMyWnd::*pfn_bwsp)(UINT, short, CPoint);
	void    (AFX_MSG_CALL CMyWnd::*pfn_vws)(UINT, LPCTSTR);
};


enum MySig
{
	MySig_end = 0,     // [marks end of message map]

	MySig_bD,      // BOOL (CDC*)
	MySig_bb,      // BOOL (BOOL)
	MySig_bWww,    // BOOL (CWnd*, UINT, UINT)
	MySig_hDWw,    // HBRUSH (CDC*, CWnd*, UINT)
	MySig_hDw,     // HBRUSH (CDC*, UINT)
	MySig_iwWw,    // int (UINT, CWnd*, UINT)
	MySig_iww,     // int (UINT, UINT)
	MySig_iWww,    // int (CWnd*, UINT, UINT)
	MySig_is,      // int (LPTSTR)
	MySig_lwl,     // LRESULT (WPARAM, LPARAM)
	MySig_lwwM,    // LRESULT (UINT, UINT, CMenu*)
	MySig_vv,      // void (void)

	MySig_vw,      // void (UINT)
	MySig_vww,     // void (UINT, UINT)
	MySig_vvii,    // void (int, int) // wParam is ignored
	MySig_vwww,    // void (UINT, UINT, UINT)
	MySig_vwii,    // void (UINT, int, int)
	MySig_vwl,     // void (UINT, LPARAM)
	MySig_vbWW,    // void (BOOL, CWnd*, CWnd*)
	MySig_vD,      // void (CDC*)
	MySig_vM,      // void (CMenu*)
	MySig_vMwb,    // void (CMenu*, UINT, BOOL)

	MySig_vW,      // void (CWnd*)
	MySig_vWww,    // void (CWnd*, UINT, UINT)
	MySig_vWp,     // void (CWnd*, CPoint)
	MySig_vWh,     // void (CWnd*, HANDLE)
	MySig_vwW,     // void (UINT, CWnd*)
	MySig_vwWb,    // void (UINT, CWnd*, BOOL)
	MySig_vwwW,    // void (UINT, UINT, CWnd*)
	MySig_vwwx,    // void (UINT, UINT)
	MySig_vs,      // void (LPTSTR)
	MySig_vOWNER,  // void (int, LPTSTR), force return TRUE
	MySig_iis,     // int (int, LPTSTR)
	MySig_wp,      // UINT (CPoint)
	MySig_wv,      // UINT (void)
	MySig_vPOS,    // void (WINDOWPOS*)
	MySig_vCALC,   // void (BOOL, NCCALCSIZE_PARAMS*)
	MySig_vNMHDRpl,    // void (NMHDR*, LRESULT*)
	MySig_bNMHDRpl,    // BOOL (NMHDR*, LRESULT*)
	MySig_vwNMHDRpl,   // void (UINT, NMHDR*, LRESULT*)
	MySig_bwNMHDRpl,   // BOOL (UINT, NMHDR*, LRESULT*)
	MySig_bHELPINFO,   // BOOL (HELPINFO*)
	MySig_vwSIZING,    // void (UINT, LPRECT) -- return TRUE

	// signatures specific to CCmdTarget
	MySig_cmdui,   // void (CCmdUI*)
	MySig_cmduiw,  // void (CCmdUI*, UINT)
	MySig_vpv,     // void (void*)
	MySig_bpv,     // BOOL (void*)

	// Other aliases (based on implementation)
	MySig_vwwh,                // void (UINT, UINT, HANDLE)
	MySig_vwp,                 // void (UINT, CPoint)
	MySig_bw = MySig_bb,      // BOOL (UINT)
	MySig_bh = MySig_bb,      // BOOL (HANDLE)
	MySig_iw = MySig_bb,      // int (UINT)
	MySig_ww = MySig_bb,      // UINT (UINT)
	MySig_bv = MySig_wv,      // BOOL (void)
	MySig_hv = MySig_wv,      // HANDLE (void)
	MySig_vb = MySig_vw,      // void (BOOL)
	MySig_vbh = MySig_vww,    // void (BOOL, HANDLE)
	MySig_vbw = MySig_vww,    // void (BOOL, UINT)
	MySig_vhh = MySig_vww,    // void (HANDLE, HANDLE)
	MySig_vh = MySig_vw,      // void (HANDLE)
	MySig_viSS = MySig_vwl,   // void (int, STYLESTRUCT*)
	MySig_bwl = MySig_lwl,
	MySig_vwMOVING = MySig_vwSIZING,  // void (UINT, LPRECT) -- return TRUE

	MySig_vW2,                 // void (CWnd*) (CWnd* comes from lParam)
	MySig_bWCDS,               // BOOL (CWnd*, COPYDATASTRUCT*)
	MySig_bwsp,                // BOOL (UINT, short, CPoint)
	MySig_vws,
};


struct MY_MSGMAP_ENTRY
{
	UINT nMessage;   // windows message
	UINT nCode;      // control code or WM_NOTIFY code
	UINT nID;        // control ID (or 0 for windows messages)
	UINT nLastID;    // used for entries specifying a range of control id's
	UINT nSig;       // signature type (action) or pointer to message #
	MY_PMSG pfn;    // routine to call (or special value)
};


struct MY_MSGMAP
{
	const MY_MSGMAP* (PASCAL* pfnGetBaseMap)();
	const MY_MSGMAP_ENTRY* lpEntries;
};

// 被移动到了CMyWnd.h
// LRESULT CALLBACK CR26WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#define MYDECLARE_MESSAGE_MAP() \
protected: \
	static const MY_MSGMAP*  __stdcall GetThisMessageMap(); \
	virtual const MY_MSGMAP* GetMessageMap() const; \


#define BEGIN_MYTEMPLATE_MESSAGE_MAP(theClass, type_name, baseClass)			\
	PTM_WARNING_DISABLE														\
	template < typename type_name >											\
	const MY_MSGMAP* theClass< type_name >::GetMessageMap() const			\
		{ return GetThisMessageMap(); }										\
	template < typename type_name >											\
	const MY_MSGMAP*  theClass< type_name >::GetThisMessageMap()		\
	{																		\
		typedef theClass< type_name > ThisClass;							\
		typedef baseClass TheBaseClass;										\
		static const MY_MSGMAP_ENTRY _messageEntries[] =					\
		{


#define MYBEGIN_MESSAGE_MAP(theClass, baseClass) \
	const MY_MSGMAP* theClass::GetMessageMap() const \
		{ return GetThisMessageMap(); } \
	const MY_MSGMAP*  theClass::GetThisMessageMap() \
	{ \
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		static const MY_MSGMAP_ENTRY _messageEntries[] =  \
		{



#define MYEND_MESSAGE_MAP() \
		{0, 0, 0, 0, MySig_end, (MY_PMSG)0 } \
	}; \
		static const MY_MSGMAP messageMap = \
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
		return &messageMap; \
	}


class CMyCmdTarget :
	public CMyObject
{
	MYDECLARE_DYNAMIC(CMyCmdTarget)
public:
	CMyCmdTarget();
	~CMyCmdTarget();
	void OnCreate();


	MYDECLARE_MESSAGE_MAP()
};

#ifndef AFX_MSG_CALL
#define AFX_MSG_CALL
#endif






typedef void ( CMyWnd::*AFX_PMSGW)(void);
// like 'AFX_PMSG' but for CWnd derived classes only

typedef void ( CMyCmdTarget::*AFX_PMSG)(void);

#define ON_WM_HSCROLL() \
	{ WM_HSCROLL, 0, 0, 0, MySig_vwwW, \
		(AFX_PMSG)(AFX_PMSGW) \
		(static_cast< void ( CMyWnd::*)(UINT, UINT, CScrollBar*) > ( &ThisClass :: OnHScroll)) },


#define ON_WM_CREATE() \
			{ WM_CREATE, 0, 0, 0, MySig_is, \
		(AFX_PMSG) (AFX_PMSGW) \
		(static_cast< int ( CMyWnd::*)(LPCREATESTRUCT) > ( &ThisClass :: OnCreate)) },