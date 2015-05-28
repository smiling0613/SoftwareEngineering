// mail.h : Cmail ���ʵ��



// Cmail ʵ��

// ���������� 2015-05-24, 23:00

#include "stdafx.h"
#include "mail.h"
IMPLEMENT_DYNAMIC(Cmail, CRecordset)

Cmail::Cmail(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_mailid = 0;
	m_matype = L"";
	m_matitle = L"";
	m_usrid = L"";
	m_sttime = L"";
	m_mastatus = 0;
	m_orderid = L"";
	m_rsver = L"";
	m_revaddr = L"";
	m_macontent = L"";
	m_mailcode = L"";
	m_nFields = 11;
	m_nDefaultType = dynaset;
}

CString Cmail::GetDefaultConnect()
{
	return _T("DBQ=F:\\SE Test\\NiceMail\\NiceMail\\testdb.mdb;DefaultDir=F:\\SE Test\\NiceMail\\NiceMail;Driver={Driver do Microsoft Access (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=F:\\SE Test\\NiceMail\\NiceMail\\testdb.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString Cmail::GetDefaultSQL()
{
	return _T("[mail]");
}

void Cmail::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[mailid]"), m_mailid);
	RFX_Text(pFX, _T("[matype]"), m_matype);
	RFX_Text(pFX, _T("[matitle]"), m_matitle);
	RFX_Text(pFX, _T("[usrid]"), m_usrid);
	RFX_Text(pFX, _T("[sttime]"), m_sttime);
	RFX_Long(pFX, _T("[mastatus]"), m_mastatus);
	RFX_Text(pFX, _T("[orderid]"), m_orderid);
	RFX_Text(pFX, _T("[rsver]"), m_rsver);
	RFX_Text(pFX, _T("[revaddr]"), m_revaddr);
	RFX_Text(pFX, _T("[macontent]"), m_macontent);
	RFX_Text(pFX, _T("[mailcode]"), m_mailcode);

}
/////////////////////////////////////////////////////////////////////////////
// Cmail ���

#ifdef _DEBUG
void Cmail::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cmail::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


