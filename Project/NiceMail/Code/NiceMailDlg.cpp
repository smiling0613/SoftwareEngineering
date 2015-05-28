
// NiceMailDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NiceMail.h"
#include "NiceMailDlg.h"
#include "afxdialogex.h"
#include "win_e_mail.h"
#include "win_i_mail.h"
#include "showMInfo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNiceMailDlg �Ի���



CNiceMailDlg::CNiceMailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNiceMailDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNiceMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON1, main_email);
	DDX_Control(pDX, IDC_BUTTON3, main_imail);
}

BEGIN_MESSAGE_MAP(CNiceMailDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CNiceMailDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CNiceMailDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CNiceMailDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CNiceMailDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CNiceMailDlg ��Ϣ�������

BOOL CNiceMailDlg::OnInitDialog()
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

void CNiceMailDlg::OnPaint()
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
HCURSOR CNiceMailDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNiceMailDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//this->EndDialog(0);
	win_e_mail e_mail;
	e_mail.DoModal();

}


void CNiceMailDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//this->EndDialog(0);
	win_i_mail i_mail;
	i_mail.DoModal();
}


void CNiceMailDlg::OnBnClickedButton4()
{
	this->EndDialog(0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CNiceMailDlg::OnBnClickedButton2()
{
	showMInfo show;
	show.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
