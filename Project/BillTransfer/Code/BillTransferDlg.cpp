
// BillTransferDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BillTransfer.h"
#include "BillTransferDlg.h"
#include "afxdialogex.h"

#include "TranToID.h"
#include "TranToCard.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBillTransferDlg �Ի���



CBillTransferDlg::CBillTransferDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBillTransferDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBillTransferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON1, l123);
}

BEGIN_MESSAGE_MAP(CBillTransferDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBillTransferDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CBillTransferDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CBillTransferDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CBillTransferDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBillTransferDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CBillTransferDlg ��Ϣ�������

BOOL CBillTransferDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBillTransferDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBillTransferDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBillTransferDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CBillTransferDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	/*TranToFriends tranDialog;
	tranDialog.DoModal();*/

}


void CBillTransferDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->EndDialog(0);
}


void CBillTransferDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	TranToID tranID;
	tranID.DoModal();
}


void CBillTransferDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	TranToCard tranCard;
	tranCard.DoModal();
}
