// TranToCard.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "TranToCard.h"
#include "afxdialogex.h"
#include "inputInfo.h"
 Cbilltran cbill;
 bool isCard =  false;
// TranToCard �Ի���

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


// TranToCard ��Ϣ�������


void TranToCard::OnPaint()
{
	c_card.SetLimitText(20);
	c_name.SetLimitText(10);
}


void TranToCard::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	isCard = false;
	CString ccard;
	CString cname;
	c_card.GetWindowText(ccard);
	c_name.GetWindowText(cname);
	/*
	    �п�
	*/
	if(ccard.IsEmpty())
	{
		 AfxMessageBox(_T("��ȷ�����������˵Ŀ��ţ�"));
		 return ;
    }
	if(cname.IsEmpty())
	{
		 AfxMessageBox(_T("��ȷ�����������˵�������"));
		 return ;
    }
	cbill.m_friendId = ccard;
	cbill.m_Username = cname;
	cbill.m_Uid = "wq752848967";
	cbill.m_Uname = "����";
	this->EndDialog(0);
	inputInfo input;
	input.DoModal();
}
