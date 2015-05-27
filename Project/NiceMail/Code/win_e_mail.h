#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "mail.h"

// win_e_mail 对话框
extern Cmail email;
class win_e_mail : public CDialogEx
{
	DECLARE_DYNAMIC(win_e_mail)

public:
	win_e_mail(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~win_e_mail();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void BillCal();
	DECLARE_MESSAGE_MAP()
public:
	CEdit e_rsver;
	CEdit e_revaddr;
	CEdit e_matitle;
	CEdit e_macontent;
	CListBox e_mailheadid;
	CButton e_send;
	CButton e_cancel;
	CDateTimeCtrl e_sttime;
	
	
	afx_msg void OnBnClickedButton1();
};
