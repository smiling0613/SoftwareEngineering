#pragma once
#include "afxwin.h"
#include "billtran.h"

// TranToCard �Ի���
extern Cbilltran cbill;
extern bool isCard;
class TranToCard : public CDialogEx
{
	DECLARE_DYNAMIC(TranToCard)

public:
	TranToCard(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TranToCard();

// �Ի�������
	enum { IDD = TransferToCard };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit c_card;
	CEdit c_name;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
};
