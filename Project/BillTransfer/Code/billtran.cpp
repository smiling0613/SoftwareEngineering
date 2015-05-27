// billtran.h : Cbilltran 类的实现



// Cbilltran 实现

// 代码生成在 2015-05-26, 20:53

#include "stdafx.h"
#include "billtran.h"
IMPLEMENT_DYNAMIC(Cbilltran, CRecordset)

Cbilltran::Cbilltran(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_friendId = L"";
	m_Username = L"";
	m_Uid = L"";
	m_Uname = L"";
	m_Trancount = 0;
	m_Trantypeid = 0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}

CString Cbilltran::GetDefaultConnect()
{
	return _T("DBQ=F:\\SE Test\\BillTransfer\\BillTransfer\\billtransis.mdb;DefaultDir=F:\\SE Test\\BillTransfer\\BillTransfer;Driver={Driver do Microsoft Access (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=F:\\SE Test\\BillTransfer\\BillTransfer\\billtransis.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString Cbilltran::GetDefaultSQL()
{
	return _T("[billtran]");
}

void Cbilltran::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[friendId]"), m_friendId);
	RFX_Text(pFX, _T("[Username]"), m_Username);
	RFX_Text(pFX, _T("[Uid]"), m_Uid);
	RFX_Text(pFX, _T("[Uname]"), m_Uname);
	RFX_Long(pFX, _T("[Trancount]"), m_Trancount);
	RFX_Long(pFX, _T("[Trantypeid]"), m_Trantypeid);

}
/////////////////////////////////////////////////////////////////////////////
// Cbilltran 诊断

#ifdef _DEBUG
void Cbilltran::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cbilltran::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


