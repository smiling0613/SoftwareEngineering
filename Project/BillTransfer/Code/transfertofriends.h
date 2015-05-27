#pragma once


// TransferToFriends 对话框

class TransferToFriends : public CDialogEx
{
	DECLARE_DYNAMIC(TransferToFriends)

public:
	TransferToFriends(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TransferToFriends();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
