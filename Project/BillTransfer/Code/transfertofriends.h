#pragma once


// TransferToFriends �Ի���

class TransferToFriends : public CDialogEx
{
	DECLARE_DYNAMIC(TransferToFriends)

public:
	TransferToFriends(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TransferToFriends();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
