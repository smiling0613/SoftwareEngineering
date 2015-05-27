#pragma once
#include "afxwin.h"
#include "User.h"

// conInfo 对话框

class conInfo : public CDialogEx
{
	DECLARE_DYNAMIC(conInfo)

public:
	conInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~conInfo();
	bool checkPassword();
	void getPassword();
// 对话框数据
	enum { IDD = Confirmation };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit con_count;
	CEdit con_fid;
	CEdit con_pass;
	int checktimes;
	CString userpass;
	CUser user;
	int trancount;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
};
