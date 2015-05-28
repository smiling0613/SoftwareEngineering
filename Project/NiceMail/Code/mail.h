// mail.h : Cmail ������

#pragma once

// ���������� 2015-05-24, 23:00

class Cmail : public CRecordset
{
public:
	Cmail(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cmail)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_mailid;
	CStringW	m_matype;
	CStringW	m_matitle;
	CStringW	m_usrid;
	CStringW	m_sttime;
	long	m_mastatus;
	CStringW	m_orderid;
	CStringW	m_rsver;
	CStringW	m_revaddr;
	CStringW	m_macontent;
	CStringW	m_mailcode;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


