// Demo01.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


extern int MYAFXAPI MyAfxWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow
	);

int _tmain(int argc, _TCHAR* argv[])
{
	return MyAfxWinMain(GetModuleHandle(NULL), NULL, GetCommandLine(), SW_NORMAL);
}

