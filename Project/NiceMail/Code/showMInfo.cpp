// showMInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NiceMail.h"
#include "showMInfo.h"
#include "afxdialogex.h"


// showMInfo �Ի���

IMPLEMENT_DYNAMIC(showMInfo, CDialogEx)

showMInfo::showMInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(showMInfo::IDD, pParent)
{
	
}

showMInfo::~showMInfo()
{
}

void showMInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, show_list2);
}


BEGIN_MESSAGE_MAP(showMInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &showMInfo::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &showMInfo::OnBnClickedButton2)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// showMInfo ��Ϣ�������




/*
    �����ݿ��ȡ��Ϣ
*/
void showMInfo::getMails()
{
	
	if(!mails.Open(AFX_DB_USE_DEFAULT_TYPE,NULL))//�������������������ȱʡֵ
	{

		afxDump<<"access db   open not ok";
	}
	
	int mcount =  mails.GetRecordCount();
	
	if(mcount!=0)
	{
		mails.MoveFirst();
		
	}
	
	CString mailItem;
	//show_list.ResetContent();
	for(int i=0;i<mcount;i++)
	{

		
		CString rsver(mails.m_rsver);
		
		CString mstatus = getMstatus(mails.m_mastatus);
		CString bill(mails.m_orderid);
		//afxDump<<i<<"\n 1.*-  "<<mcount<<"\n";
		//CString mid = mails.m_mailid;
		show_list2.AddString("123             "+rsver+"            "+CString(mails.m_sttime)+"            "+mstatus+"              "+bill);
		//afxDump<<"\n  *-       "<<rsver<<"   "<<mstatus<<"\n";
		//+"     "+rsver+"    "+CString(mails.m_sttime)+"    "+mstatus+"    "+"123.0"
		//afxDump<<i<<"\n2.*-  "<<mcount<<"\n";
		if(i+1<mcount)
		{
			//afxDump<<i<<"\n2.*-  "<<"  next"<<"\n";
			mails.MoveNext();
		}
	}
	mails.Close();
	
}
/*
   �����ʼ�����Ϣ
*/
void showMInfo::showInfo()
{
	getMails();
}
CString showMInfo::getMstatus(long statusnum)
{
	if(statusnum==0)
	{
		return "δ����";
	}
	else if(statusnum==1)
	{
		return "�ѷ���";
	}
	else
	{
		return "δ֪";
	}

}
void showMInfo::OnBnClickedButton1()
{
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void showMInfo::OnBnClickedButton2()
{
	this->EndDialog(0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void showMInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	showInfo();
}
