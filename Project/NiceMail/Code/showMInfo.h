#pragma once
#include "afxwin.h"
#include "mail.h"

// showMInfo �Ի���

class showMInfo : public CDialogEx
{
	DECLARE_DYNAMIC(showMInfo)

public:
	showMInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~showMInfo();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
