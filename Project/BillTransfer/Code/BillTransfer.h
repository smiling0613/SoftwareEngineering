
// BillTransfer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBillTransferApp:
// �йش����ʵ�֣������ BillTransfer.cpp
//

class CBillTransferApp : public CWinApp
{
public:
	CBillTransferApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBillTransferApp theApp;