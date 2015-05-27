// win_e_mail.cpp : 实现文件
//

#include "stdafx.h"
#include "NiceMail.h"
#include "win_e_mail.h"
#include "afxdialogex.h"

/*

   定义电邮结构体

*/
Cmail email;
struct Mail
{
	int maid;
	int matype;
	CString matitle;
	int usrid;
	CString sttime;
	CString rsver;
	CString revaddr;
	CString macontent;
	bool status;
	int orderid;
};

// win_e_mail 对话框

IMPLEMENT_DYNAMIC(win_e_mail, CDialogEx)



win_e_mail::win_e_mail(CWnd* pParent /*=NULL*/)
	: CDialogEx(win_e_mail::IDD, pParent)
{

}

win_e_mail::~win_e_mail()
{
}

void win_e_mail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, e_rsver);
	DDX_Control(pDX, IDC_EDIT2, e_revaddr);
	DDX_Control(pDX, IDC_EDIT4, e_matitle);
	DDX_Control(pDX, IDC_EDIT5, e_macontent);
	DDX_Control(pDX, IDC_LIST1, e_mailheadid);
	DDX_Control(pDX, IDC_BUTTON1, e_send);
	DDX_Control(pDX, IDC_BUTTON2, e_cancel);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, e_sttime);
}


BEGIN_MESSAGE_MAP(win_e_mail, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &win_e_mail::OnBnClickedButton1)
END_MESSAGE_MAP()


// win_e_mail 消息处理程序
/*
电邮发送

*/

void win_e_mail::OnBnClickedButton1()
{

	/*

	   电邮存储
	
	*/
	Mail e_mail;
	e_rsver.GetWindowText(e_mail.rsver);
	
	//邮箱
	e_revaddr.GetWindowText(e_mail.revaddr);
	/*
	     判空操作
	*/
	if(e_mail.rsver.IsEmpty()||e_mail.revaddr.IsEmpty())
	{
		 AfxMessageBox(_T("请填写收件方信息，并确认！"));
		 return ;
	}
	e_matitle.GetWindowText(e_mail.matitle);
	/*
	     判空操作
	*/
	if(e_mail.matitle.IsEmpty())
	{
		 AfxMessageBox(_T("请填写邮件的主题！"));
		 return ;
	}

	//获取时间
	CTime tm;
	e_sttime.GetTime(tm);
	e_mail.sttime = tm.Format("%Y-%m-%d");
	e_macontent.GetWindowText(e_mail.macontent);

	
	email.m_rsver = e_mail.rsver;
	email.m_revaddr = e_mail.revaddr;
	email.m_sttime = e_mail.sttime;
	email.m_revaddr = e_mail.revaddr;
	email.m_mastatus = 0;
	email.m_macontent = e_mail.macontent;
	BillCal();
	if(!email.Open(AFX_DB_USE_DEFAULT_TYPE,NULL))//这个函数几个参数都有缺省值
	{

		afxDump<<"access db   open not ok";
	}
	
	email.Update();
	//在此处计算电邮的费用  
	//后期可以将此方法单独拿出去





	/*CTime tm;

	e_sttime.GetTime(tm);
	CString e_time = tm.Format("%Y-%m-%d");*/
	//afxDump<<e_rev<<"   *-     ";
	// TODO: 在此添加控件通知处理程序代码
}
void win_e_mail::BillCal()
{
	 int contentcount  = email.m_macontent.GetLength();
	CString  bill;
	bill.Format(_T("%d"), (contentcount*0.2)+1);
	email.m_orderid = bill;
}