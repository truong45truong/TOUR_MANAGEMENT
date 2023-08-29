#pragma once
#include <windows.h>
#include "Tour.h"
#include "Customer.h"
#include "Hotel.h"
#include "Landscape.h"
#include "Registration.h"
#include "Ticket.h"
#include "Vehice.h"
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <stdlib.h>
#include <vector>
class DBConn
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLTCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	void init();
    vector<Tour> selecttour();
	void selectcus();
	void selectregis();
	void inserttour();
	void insertcus();
	void insertticket();
	void insertregis();
	void updatetour();
	void updatevehice();
	void updatehotel();
	void updateland();
	void deletetour();
	void close();
};
