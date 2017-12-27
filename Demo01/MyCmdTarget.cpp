#include "stdafx.h"
#include "MyMFC.h"
#include "MyCmdTarget.h"


IMPLEMENT_MYDYNAMIC(CMyCmdTarget, CMyObject)




CMyCmdTarget::CMyCmdTarget()
{
	cout << "CMyCmdTarget Constructor" << endl;
}


CMyCmdTarget::~CMyCmdTarget()
{
	cout << "CMyCmdTarget Destructor" << endl;
}


void CMyCmdTarget::OnCreate()
{
}


const MY_MSGMAP* CMyCmdTarget::GetMessageMap() const
{
	return GetThisMessageMap();
}

const MY_MSGMAP*  CMyCmdTarget::GetThisMessageMap()
{
	static const MY_MSGMAP_ENTRY _messageEntries[] =
	{
		{ 0, 0, MySig_end, 0 }     // nothing here
	};
	static const MY_MSGMAP messageMap =
	{
		NULL,
		&_messageEntries[0]
	};
	return &messageMap;
}