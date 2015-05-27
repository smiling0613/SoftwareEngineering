// conInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "conInfo.h"
#include "afxdialogex.h"
#include "TranToID.h"
#include "TranToCard.h"

#include "User.h"

// conInfo 对话框

IMPLEMENT_DYNAMIC(conInfo, CDialogEx)

	conInfo::conInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(conInfo::IDD, pParent)
{

}

conInfo::~conInfo()
{
}

void conInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, con_count);
	DDX_Control(pDX, IDC_EDIT2, con_fid);
	DDX_Control(pDX, IDC_EDIT3, con_pass);
}


BEGIN_MESSAGE_MAP(conInfo, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &conInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// conInfo 消息处理程序


void conInfo::OnPaint()
{
	checktimes =  0;
	con_pass.SetLimitText(15);
	if(isID)
	{
		CString fid(idbill.m_friendId);
		CString fcount;
		fcount.Format(_T("%d"), idbill.m_Trancount);
		con_count.SetWindowText(fid);
		con_fid.SetWindowText(fcount);
	}
	else if(isCard)
	{
		CString fid(cbill.m_Username);
		CString fcount;
		fcount.Format(_T("%d"), cbill.m_Trancount);
		con_count.SetWindowText(fid);
		con_fid.SetWindowText(fcount);
	}

}


void conInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	bool result = checkPassword();
	if(!result)
	{

	}
	else
	{
		if(checktimes==3)
		{
			AfxMessageBox(_T("转账失败！"));
			this->EndDialog(0);
		}
		else
		{
			AfxMessageBox(_T("密码错误，请确认后重试！"));
			
		}
	}
}
bool conInfo::checkPassword()
{
	CString input_pass;
	con_pass.GetWindowText(input_pass);
	if(input_pass.IsEmpty())
	{
		AfxMessageBox(_T("请输入密码确认！"));
		return false;
	}
	getPassword();
	if(input_pass.Compare(userpass))
	{
		
		int count = user.m_usercount;
		//更改余额
		user.m_usercount = trancount;
		user.Update();
		return true;
	}
	else
	{
		checktimes++;
		return false;
	}


}
void conInfo::getPassword()
{

	CString userid;
	if(!user.Open(AFX_DB_USE_DEFAULT_TYPE,NULL))//这个函数几个参数都有缺省值
	{

		afxDump<<"access db   open not ok";
	}
	if(isID)
	{
		userid =  idbill.m_Uid;
		trancount =  idbill.m_Trancount;
	}
	else if(isCard)
	{
		userid =  cbill.m_Uid;
		trancount =  cbill.m_Trancount;
	}
	else
	{
		userid =  "wq752848967";
		trancount =  12;
	}
	int mcount =  user.GetRecordCount();

	if(mcount!=0)
	{
		user.MoveFirst();

	}
	for(int i=0;i<mcount;i++)
	{
		CString user_id(user.m_userid);
		if(userid.Compare(user_id))
		{
			userpass = user.m_password;

		}


		if(i+1<mcount)
		{
			user.MoveNext();
		}

	}


}




