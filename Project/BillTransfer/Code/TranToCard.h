#pragma once
#include "afxwin.h"
#include "billtran.h"

// TranToCard 对话框
extern Cbilltran cbill;
extern bool isCard;
class TranToCard : public CDialogEx
{
	DECLARE_DYNAMIC(TranToCard)

public:
	TranToCard(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TranToCard();

// 对话框数据
	enum { IDD = TransferToCard };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit c_card;
	CEdit c_name;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
};
