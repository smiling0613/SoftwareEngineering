// inputInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "inputInfo.h"
#include "afxdialogex.h"
#include "TranToID.h"
#include "TranToCard.h"
#include "TransferToFriends.h"
#include "conInfo.h"
// inputInfo 对话框

IMPLEMENT_DYNAMIC(inputInfo, CDialogEx)

inputInfo::inputInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(inputInfo::IDD, pParent)
{

}

inputInfo::~inputInfo()
{
}

void inputInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, input_count);
	DDX_Control(pDX, IDC_EDIT3, re_id);
	DDX_Control(pDX, IDC_EDIT2, ex_info);
}


BEGIN_MESSAGE_MAP(inputInfo, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &inputInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// inputInfo 消息处理程序


void inputInfo::OnPaint()
{
	if(isID)
	{
		CString fid(idbill.m_friendId);
		re_id.SetWindowText(fid);
	}
	else if(isCard)
	{
		CString fid(idbill.m_Username);
		re_id.SetWindowText(fid);
	}

	/*
	    对Edit 控件的输入长度进行限制
	*/
	input_count.SetLimitText(10);
	ex_info.SetLimitText(50);
	
}


void inputInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	    对输入数据进行判空
	*/
		int tcount = 0;
	CString scount;
	input_count.GetWindowText(scount);
	tcount = _ttoi(scount);
	/*
	   对输入的数值进行判空
	*/
	if(tcount<0)
	{
		AfxMessageBox(_T("请输入正确的转账信息！"));
		 return ;

	}

	/*
          分情况处理	
	*/
	if(isID)
	{
	
	idbill.m_Trancount = tcount;
	}
	else if(isCard)
	{
	
	   cbill.m_Trancount = tcount;
	}
	this->EndDialog(0);
	conInfo confirm;
	confirm.DoModal();
	
	
}
