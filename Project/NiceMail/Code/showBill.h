#pragma once
#include "afxwin.h"


// showBill �Ի���

class showBill : public CDialogEx
{
	DECLARE_DYNAMIC(showBill)

public:
	showBill(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~showBill();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListBox show_bill;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
