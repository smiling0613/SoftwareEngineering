// TranToID.cpp : 实现文件
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "TranToID.h"
#include "afxdialogex.h"
#include "inputInfo.h"

// TranToID 对话框
Cbilltran idbill;
bool isID =  false;
IMPLEMENT_DYNAMIC(TranToID, CDialogEx)

TranToID::TranToID(CWnd* pParent /*=NULL*/)
	: CDialogEx(TranToID::IDD, pParent)
{

}

TranToID::~TranToID()
{
}

void TranToID::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, id_id);
}


BEGIN_MESSAGE_MAP(TranToID, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &TranToID::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &TranToID::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// TranToID 消息处理程序


void TranToID::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void TranToID::OnBnClickedOk()
{
	
	/*
	   对输入的ID进行规范化确认
	*/
	isID =  false;
	CString reID;
	id_id.GetWindowText(reID);
	if(reID.IsEmpty())
	{
	     AfxMessageBox(_T("请确认是否输入接收方账户！"));
		 return ;

	}
	int length = reID.GetLength();
	if(length<5)
	{
		AfxMessageBox(_T("请输入正确的接收方账户！"));
		 return ;
	}
	idbill.m_friendId = reID;
	idbill.m_Username = "无";
	idbill.m_Uid = "wq752848967";
	idbill.m_Uname = "张三";
	idbill.m_Trantypeid =  1;
	this->EndDialog(0);
	isID =  true;
	inputInfo input;
	input.DoModal();

}


void TranToID::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	/*
	    限制输入的长度
	*/
	id_id.SetLimitText(10);
}
