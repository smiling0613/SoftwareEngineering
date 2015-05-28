// inputInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "inputInfo.h"
#include "afxdialogex.h"
#include "TranToID.h"
#include "TranToCard.h"
#include "TransferToFriends.h"
#include "conInfo.h"
// inputInfo �Ի���

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


// inputInfo ��Ϣ�������


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
	    ��Edit �ؼ������볤�Ƚ�������
	*/
	input_count.SetLimitText(10);
	ex_info.SetLimitText(50);
	
}


void inputInfo::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*
	    ���������ݽ����п�
	*/
		int tcount = 0;
	CString scount;
	input_count.GetWindowText(scount);
	tcount = _ttoi(scount);
	/*
	   ���������ֵ�����п�
	*/
	if(tcount<0)
	{
		AfxMessageBox(_T("��������ȷ��ת����Ϣ��"));
		 return ;

	}

	/*
          ���������	
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
