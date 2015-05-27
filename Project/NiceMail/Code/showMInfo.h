#pragma once
#include "afxwin.h"
#include "mail.h"

// showMInfo 对话框

class showMInfo : public CDialogEx
{
	DECLARE_DYNAMIC(showMInfo)

public:
	showMInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~showMInfo();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void showInfo();
	void getMails();
	CString getMstatus(long statusnum);
	DECLARE_MESSAGE_MAP()
public:
	CListBox show_list;
	Cmail mails;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	CListBox show_list2;
	afx_msg void OnPaint();
};
