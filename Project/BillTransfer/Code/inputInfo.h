#pragma once
#include "afxwin.h"


// inputInfo 对话框

class inputInfo : public CDialogEx
{
	DECLARE_DYNAMIC(inputInfo)

public:
	inputInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~inputInfo();

// 对话框数据
	enum { IDD = AmountAndInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit input_count;
	afx_msg void OnPaint();
	CEdit re_id;
	CEdit ex_info;
	afx_msg void OnBnClickedOk();
};
