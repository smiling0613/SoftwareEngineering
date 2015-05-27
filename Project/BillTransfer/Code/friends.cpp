// friends.h : Cfriends 类的实现



// Cfriends 实现

// 代码生成在 2015-05-26, 20:54

#include "stdafx.h"
#include "friends.h"
IMPLEMENT_DYNAMIC(Cfriends, CRecordset)

Cfriends::Cfriends(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_friendId = 0;
	m_Username = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}

CString Cfriends::GetDefaultConnect()
{
	return _T("DBQ=F:\\SE Test\\BillTransfer\\BillTransfer\\billtransis.mdb;DefaultDir=F:\\SE Test\\BillTransfer\\BillTransfer;Driver={Driver do Microsoft Access (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=F:\\SE Test\\BillTransfer\\BillTransfer\\billtransis.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString Cfriends::GetDefaultSQL()
{
	return _T("[friends]");
}

void Cfriends::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[friendId]"), m_friendId);
	RFX_Text(pFX, _T("[Username]"), m_Username);

}
/////////////////////////////////////////////////////////////////////////////
// Cfriends 诊断

#ifdef _DEBUG
void Cfriends::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cfriends::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


