// TranToFriends.cpp : 实现文件
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "TranToFriends.h"
#include "afxdialogex.h"


// TranToFriends 对话框

IMPLEMENT_DYNAMIC(TranToFriends, CDialogEx)

TranToFriends::TranToFriends(CWnd* pParent /*=NULL*/)
	: CDialogEx(TranToFriends::IDD, pParent)
{

}

TranToFriends::~TranToFriends()
{
}

void TranToFriends::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TranToFriends, CDialogEx)
END_MESSAGE_MAP()


// TranToFriends 消息处理程序
