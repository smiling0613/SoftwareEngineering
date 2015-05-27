
// NiceMailDlg.cpp : 实现文件
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


// CNiceMailDlg 对话框



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


// CNiceMailDlg 消息处理程序

BOOL CNiceMailDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNiceMailDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNiceMailDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNiceMailDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//this->EndDialog(0);
	win_e_mail e_mail;
	e_mail.DoModal();

}


void CNiceMailDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//this->EndDialog(0);
	win_i_mail i_mail;
	i_mail.DoModal();
}


void CNiceMailDlg::OnBnClickedButton4()
{
	this->EndDialog(0);
	// TODO: 在此添加控件通知处理程序代码
}


void CNiceMailDlg::OnBnClickedButton2()
{
	showMInfo show;
	show.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
