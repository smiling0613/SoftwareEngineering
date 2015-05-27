// User.h : CUser 类的实现



// CUser 实现

// 代码生成在 2015-05-26, 20:55

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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[uid]"), m_uid);
	RFX_Text(pFX, _T("[userid]"), m_userid);
	RFX_Text(pFX, _T("[password]"), m_password);
	RFX_Text(pFX, _T("[username]"), m_username);
	RFX_Long(pFX, _T("[usercount]"), m_usercount);
	RFX_Long(pFX, _T("[portraitid]"), m_portraitid);

}
/////////////////////////////////////////////////////////////////////////////
// CUser 诊断

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


