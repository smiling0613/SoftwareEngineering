#pragma once
#include "afxwin.h"
#include "User.h"

// conInfo �Ի���

class conInfo : public CDialogEx
{
	DECLARE_DYNAMIC(conInfo)

public:
	conInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~conInfo();
	bool checkPassword();
	void getPassword();
// �Ի�������
	enum { IDD = Confirmation };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
