// TranToCard.cpp : 实现文件
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "TranToCard.h"
#include "afxdialogex.h"
#include "inputInfo.h"
 Cbilltran cbill;
 bool isCard =  false;
// TranToCard 对话框

IMPLEMENT_DYNAMIC(TranToCard, CDialogEx)

TranToCard::TranToCard(CWnd* pParent /*=NULL*/)
	: CDialogEx(TranToCard::IDD, pParent)
{

}

TranToCard::~TranToCard()
{
}

void TranToCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, c_card);
	DDX_Control(pDX, IDC_EDIT2, c_name);
}


BEGIN_MESSAGE_MAP(TranToCard, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &TranToCard::OnBnClickedOk)
END_MESSAGE_MAP()


// TranToCard 消息处理程序


void TranToCard::OnPaint()
{
	c_card.SetLimitText(20);
	c_name.SetLimitText(10);
}


void TranToCard::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	isCard = false;
	CString ccard;
	CString cname;
	c_card.GetWindowText(ccard);
	c_name.GetWindowText(cname);
	/*
	    判空
	*/
	if(ccard.IsEmpty())
	{
		 AfxMessageBox(_T("请确认输入收账人的卡号！"));
		 return ;
    }
	if(cname.IsEmpty())
	{
		 AfxMessageBox(_T("请确认输入收账人的姓名！"));
		 return ;
    }
	cbill.m_friendId = ccard;
	cbill.m_Username = cname;
	cbill.m_Uid = "wq752848967";
	cbill.m_Uname = "张三";
	this->EndDialog(0);
	inputInfo input;
	input.DoModal();
}
