#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "mail.h"

// win_i_mail �Ի���
extern bool i_isthis;
extern Cmail imail;
class win_i_mail : public CDialogEx
{
	DECLARE_DYNAMIC(win_i_mail)
	
public:
	win_i_mail(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~win_i_mail();
	void BillCal();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit i_rsver;
	CEdit i_revaddr;
	CEdit i_matitle;
	CEdit i_macontent;
	CButton i_send;
	CButton i_canel;
	afx_msg void OnBnClickedButton2();
	CDateTimeCtrl i_sttime;
	
	CEdit i_mailcode;
	
//	int i_out;
//	int i_check;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
};
