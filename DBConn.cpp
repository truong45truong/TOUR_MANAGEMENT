#include "DBConn.h"
#include <iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>
#define Max 1000
using namespace std;

void DBConn::init()
{
	//initializations
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	sqlEnvHandle = NULL;
	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();

	if (SQL_SUCCESS != SQLSetConnectAttr(sqlConnHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
		close();
	//output
	cout << "Attempting connection to SQL Server...";
	cout << "\n";
	switch (SQLDriverConnect(sqlConnHandle, NULL, (SQLTCHAR*)"DRIVER={SQL Server};SERVER=XOT\\SQLEXPRESS;DATABASE=QuanLyTour;trusted=true;UID=sa;PWD=123456",
		SQL_NTS,
		retconstring,
		1024,//ok
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	default:
		break;
	}
	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();
}
vector<Tour> DBConn::selecttour()
{	
	vector<Tour> result;
	Tour arrTour[Max];
	Tour ptr;
	Hotel arrHo[Max];
	Landscape arrLand[Max];
	Vehice arrVe[Max];
	int index;
	char sqlquery[] = "Select * from Tour";
    cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)sqlquery, SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
    else
    {
        char matour[20];
        char tentour[100];
        char ngaybd[20];
        char ngaykt[20];
        int gia;
        while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
        {
            SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &matour, sizeof(matour) ,NULL);
            SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &tentour, sizeof(tentour) ,NULL);
            SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &ngaybd, sizeof(ngaybd) ,NULL);
            SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &ngaykt, sizeof(ngaykt) ,NULL);
            SQLGetData(sqlStmtHandle, 5 , SQL_C_DEFAULT, &gia, sizeof(gia) ,NULL);
			arrTour[index] = Tour(matour, tentour, ngaybd, ngaykt, gia);
			++index;
        }
		for (int i = 0; i < index; i++) 
		{
			result.push_back(arrTour[i]);
		}
    }
	SQLCancel(sqlStmtHandle);
	return result;
}
void DBConn::selectcus()
{
	Customer arrCus[Max];
	int Cus;
	char sqlquery[] = "Select * from Khachhang";
    cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)sqlquery, SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
    else
    {
		char makhachhang[20];
		char tenkhachhang[100];
		char diachi[100];
		int sdt;
        while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
        {
            SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &makhachhang, sizeof(makhachhang) ,NULL);
            SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &tenkhachhang, sizeof(tenkhachhang) ,NULL);
            SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &diachi, sizeof(diachi) ,NULL);
            SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &sdt, sizeof(sdt) ,NULL);
			arrCus[Cus] = Customer(makhachhang, tenkhachhang, diachi, sdt);
			++Cus;
        }
    }
	SQLCancel(sqlStmtHandle);
}
void DBConn::selectregis()
{
	Registration arrReg[Max];
	int reg;
	char sqlquery[] = "Select * from Dangky";
    cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)sqlquery, SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
    else
    {
		char makhachhang[20];
		int sove;
		char madangky[20];
		char matour[20];
        while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
        {
            SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &makhachhang, sizeof(makhachhang) ,NULL);
            SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &sove, sizeof(sove) ,NULL);
            SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &madangky, sizeof(madangky) ,NULL);
            SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &matour, sizeof(matour) ,NULL);
			arrReg[reg] = Registration(matour, makhachhang, sove, madangky);
			++reg;
        }
    }
	SQLCancel(sqlStmtHandle);
}
void DBConn::inserttour()
{

}
void DBConn::insertcus()
{

}
void DBConn::insertregis()
{

}
void DBConn::insertticket()
{

}
void DBConn::updatetour()
{

}
void DBConn::updateland()
{

}
void DBConn::updatehotel()
{

}
void DBConn::updatevehice()
{

}
void DBConn::deletetour()
{

}
void DBConn::close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	system("pause");
	exit(0);
}