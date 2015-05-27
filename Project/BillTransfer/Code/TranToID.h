#pragma once
#include "afxwin.h"
#include "billtran.h"

// TranToID 对话框
extern Cbilltran idbill;
extern bool isID;
class TranToID : public CDialogEx
{
	DECLARE_DYNAMIC(TranToID)

public:
	TranToID(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TranToID();

// 对话框数据
	enum { IDD = TansferToCount };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit id_id;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
};
