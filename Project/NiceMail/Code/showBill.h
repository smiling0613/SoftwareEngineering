#pragma once
#include "afxwin.h"


// showBill 对话框

class showBill : public CDialogEx
{
	DECLARE_DYNAMIC(showBill)

public:
	showBill(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~showBill();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListBox show_bill;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
