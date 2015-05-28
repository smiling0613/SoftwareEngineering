// User.h : CUser ���ʵ��



// CUser ʵ��

// ���������� 2015-05-26, 20:55

#include "stdafx.h"
#include "User.h"
IMPLEMENT_DYNAMIC(CUser, CRecordset)

CUser::CUser(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_uid = 0;
	m_userid = L"";
	m_password = L"";
	m_username = L"";
	m_usercount = 0;
	m_portraitid = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

CString CUser::GetDefaultConnect()
{
	return _T("DBQ=F:\\SE Test\\BillTransfer\\BillTransfer\\billtransis.mdb;DefaultDir=F:\\SE Test\\BillTransfer\\BillTransfer;Driver={Driver do Microsoft Access (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=F:\\SE Test\\BillTransfer\\BillTransfer\\billtransis.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CUser::GetDefaultSQL()
{
	return _T("[User]");
}

void CUser::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[uid]"), m_uid);
	RFX_Text(pFX, _T("[userid]"), m_userid);
	RFX_Text(pFX, _T("[password]"), m_password);
	RFX_Text(pFX, _T("[username]"), m_username);
	RFX_Long(pFX, _T("[usercount]"), m_usercount);
	RFX_Long(pFX, _T("[portraitid]"), m_portraitid);

}
/////////////////////////////////////////////////////////////////////////////
// CUser ���

#ifdef _DEBUG
void CUser::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUser::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


