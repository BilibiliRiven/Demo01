#pragma once
#include "MYNoTrackObject.h"


class CMyWinThread;
class MYAFX_MODULE_THREAD_STATE
	//public CMYNoTrackObject
{
public:
	MYAFX_MODULE_THREAD_STATE();
	virtual ~MYAFX_MODULE_THREAD_STATE();

	// current CWinThread pointer
	CMyWinThread* m_pCurrentWinThread;
};

