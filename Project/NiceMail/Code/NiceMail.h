
// NiceMail.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNiceMailApp:
// �йش����ʵ�֣������ NiceMail.cpp
//

class CNiceMailApp : public CWinApp
{
public:
	CNiceMailApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNiceMailApp theApp;