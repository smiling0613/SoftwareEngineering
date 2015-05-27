// showBill.cpp : 实现文件
//

#include "stdafx.h"
#include "NiceMail.h"
#include "showBill.h"
#include "afxdialogex.h"
#include "win_i_mail.h"
#include "win_e_mail.h"
// showBill 对话框

IMPLEMENT_DYNAMIC(showBill, CDialogEx)

showBill::showBill(CWnd* pParent /*=NULL*/)
	: CDialogEx(showBill::IDD, pParent)
{

}

showBill::~showBill()
{
}

void showBill::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, show_bill);
}


BEGIN_MESSAGE_MAP(showBill, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &showBill::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &showBill::OnBnClickedCancel)
END_MESSAGE_MAP()


// showBill 消息处理程序


void showBill::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	if(i_isthis==true)
	{
		CString info(imail.m_orderid);
		show_bill.AddString("费用为："+info);
	}
	else
	{
		CString info(email.m_orderid);
		show_bill.AddString("费用为："+info);
	}
	
}


void showBill::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	this->EndDialog(0);
}


void showBill::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	this->EndDialog(0);
}
