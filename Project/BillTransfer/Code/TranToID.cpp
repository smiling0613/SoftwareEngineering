// TranToID.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "TranToID.h"
#include "afxdialogex.h"
#include "inputInfo.h"

// TranToID �Ի���
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


// TranToID ��Ϣ�������


void TranToID::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void TranToID::OnBnClickedOk()
{
	
	/*
	   �������ID���й淶��ȷ��
	*/
	isID =  false;
	CString reID;
	id_id.GetWindowText(reID);
	if(reID.IsEmpty())
	{
	     AfxMessageBox(_T("��ȷ���Ƿ�������շ��˻���"));
		 return ;

	}
	int length = reID.GetLength();
	if(length<5)
	{
		AfxMessageBox(_T("��������ȷ�Ľ��շ��˻���"));
		 return ;
	}
	idbill.m_friendId = reID;
	idbill.m_Username = "��";
	idbill.m_Uid = "wq752848967";
	idbill.m_Uname = "����";
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
	    ��������ĳ���
	*/
	id_id.SetLimitText(10);
}
