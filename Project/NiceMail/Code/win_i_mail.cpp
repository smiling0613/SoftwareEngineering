// win_i_mail.cpp : ʵ���ļ�
//
/*
   �ż�
*/
#include "stdafx.h"
#include "NiceMail.h"
#include "win_i_mail.h"
#include "afxdialogex.h"
bool i_isthis =  false;
Cmail imail;
struct iMail
{
	int maid;
	int matype;
	CString matitle;
	int usrid;
	CString sttime;
	CString rsver;
	CString revaddr;
	CString macontent;
	CString mailcode;
	bool status;
	int orderid;
};

// win_i_mail �Ի���

IMPLEMENT_DYNAMIC(win_i_mail, CDialogEx)

win_i_mail::win_i_mail(CWnd* pParent /*=NULL*/)
	: CDialogEx(win_i_mail::IDD, pParent)
	
{

}

win_i_mail::~win_i_mail()
{
}

void win_i_mail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, i_rsver);
	DDX_Control(pDX, IDC_EDIT2, i_revaddr);
	DDX_Control(pDX, IDC_EDIT3, i_matitle);
	DDX_Control(pDX, IDC_EDIT4, i_macontent);
	DDX_Control(pDX, IDC_BUTTON2, i_send);
	DDX_Control(pDX, IDC_BUTTON3, i_canel);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, i_sttime);
	DDX_Control(pDX, IDC_EDIT5, i_mailcode);
	
}


BEGIN_MESSAGE_MAP(win_i_mail, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &win_i_mail::OnBnClickedButton2)

END_MESSAGE_MAP()


// win_i_mail ��Ϣ�������


void win_i_mail::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	iMail i_mail;
	i_rsver.GetWindowText(i_mail.rsver);
	i_revaddr.GetWindowText(i_mail.revaddr);
	if(i_mail.rsver.IsEmpty()||i_mail.revaddr.IsEmpty())
	{
		 AfxMessageBox(_T("����д�ż����ռ��˻����ռ���ַ��"));
		 return ;
	}
	//��ȡ�ʱ�

	i_mailcode.GetWindowText(i_mail.mailcode);
	if(i_mail.mailcode.IsEmpty())
	{
		AfxMessageBox(_T("����д�ż����ʱ࣡"));
		 return ;
	}


	i_matitle.GetWindowText(i_mail.matitle);
	if(i_mail.matitle.IsEmpty())
	{
		 AfxMessageBox(_T("����д�ż����ռ��˻����ռ���ַ��"));
		 return ;
	}
	i_macontent.GetWindowText(i_mail.macontent);

	//ʱ���ȡ
	CTime tm;
	i_sttime.GetTime(tm);
	i_mail.sttime = tm.Format("%Y-%m-%d");

	imail.m_rsver = i_mail.rsver;
	imail.m_revaddr = i_mail.revaddr;
	imail.m_sttime = i_mail.sttime;
	imail.m_mastatus = 0;
	imail.m_macontent = i_mail.macontent;
	//�ʱ�
	imail.m_mailcode = i_mail.mailcode;
	BillCal();
	if(!imail.Open(AFX_DB_USE_DEFAULT_TYPE,NULL))//�������������������ȱʡֵ
	{

		afxDump<<"access db   open not ok";
	}
	i_isthis  = true;
	imail.Update();
	
}
void win_i_mail::BillCal()
{
	int contentcount  = imail.m_macontent.GetLength();
	CString  bill;
	bill.Format(_T("%d"), (contentcount*0.2)+1);
	imail.m_orderid = bill;
}






