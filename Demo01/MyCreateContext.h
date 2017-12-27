#pragma once

struct CMyRuntimeClass;

class CMyCreateContext
{
public:
	CMyCreateContext();
	~CMyCreateContext();
public:
	CMyRuntimeClass *m_pView;
};

