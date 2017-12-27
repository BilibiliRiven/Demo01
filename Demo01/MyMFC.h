#ifndef MY_AFXH
	#define MY_AFXH
	#include "MyObject.h"
	#include "MyCmdTarget.h"
	#include "MyWinThread.h"
	#include "MyWinApp.h"
	#include "MyDocument.h"
	#include "MyWnd.h"
	#include "MyView.h"
	#include "MyFrameWnd.h"
	#include "TestDemoDoc.h"
	#include "TestDemoView.h"
	#include "TestDemoApp.h"
	#include "TestDemoFrame.h"
	#include "MyDocTemplate.h"
	#include "MySingleDocTemplate.h"
	#include "MyDocManager.h"
	#include "MyCreateContext.h"
	CMyWinApp * MyAfxGetApp();
	CMyWinThread * MyAfxGetThread();
	HINSTANCE  MyGetInstanceHandle();
#endif
