#pragma once
#include "afxwin.h"


// inputInfo �Ի���

class inputInfo : public CDialogEx
{
	DECLARE_DYNAMIC(inputInfo)

public:
	inputInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~inputInfo();

// �Ի�������
	enum { IDD = AmountAndInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit input_count;
	afx_msg void OnPaint();
	CEdit re_id;
	CEdit ex_info;
	afx_msg void OnBnClickedOk();
};
