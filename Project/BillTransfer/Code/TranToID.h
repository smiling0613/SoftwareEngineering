#pragma once
#include "afxwin.h"
#include "billtran.h"

// TranToID �Ի���
extern Cbilltran idbill;
extern bool isID;
class TranToID : public CDialogEx
{
	DECLARE_DYNAMIC(TranToID)

public:
	TranToID(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TranToID();

// �Ի�������
	enum { IDD = TansferToCount };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit id_id;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
};
