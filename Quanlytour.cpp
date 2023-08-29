#include "Quanlytour.h"
#define Max 1000
#define SQL_RETURN_CODE_LEN 1024
SQLHANDLE sqlConnHandle = NULL;
SQLHANDLE sqlStmtHandle = NULL;
SQLHANDLE sqlEnvHandle = NULL;
SQLTCHAR retconstring[SQL_RETURN_CODE_LEN];
int Searching(Tour arr[], int n, string matour)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMatour() == matour)
        {
            return i;
        }
    }
    return -1;
}
int SearchingHo(Hotel arr[], int n, string matour)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMaTour() == matour)
        {
            return i;
        }
    }
    return -1;
}
int SearchingVeh(Vehice arr[], int n, string matour)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMatour() == matour)
        {
            return i;
        }
    }
    return -1;
}
int SearchingLand(Landscape arr[], int n, string matour)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMatour() == matour)
        {
            return i;
        }
    }
    return -1;
}
int SearchingCustomer(Customer arr[], int n, string makhachhang)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMakhachhang() == makhachhang)
        {
            return i;
        }
    }
    return -1;
}
int SearchingNameCustomer(Customer arr[], int n, string tenkhachhang)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetTenkhachhang() == tenkhachhang)
        {
            return i;
        }
    }
    return -1;
}
int SearchingRegis(Registration arr[], int n, string makhachhang)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMakhachhang() == makhachhang)
        {
            return i;
        }
    }
    return -1;
}
int SearchingTic(Ticket arr[], int n, string matour)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].GetMatour() == matour)
        {
            return i;
        }
    }
    return -1;
}
template <typename Val>
void swapVal(Val &x, Val &y)
{
    Val swap = x;
    x = y;
    y = swap;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        swapVal(arr[left], arr[right]);
        left++;
        right--;
    }
    swapVal(arr[left], arr[high]);
    return left;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
} 
bool KMP(string s, string p)
{
    int m, n;
    m = p.length();
    n = s.length();
    vector<int> lps(m, 0);
    for (int i = 1; i < m; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && p[i] != p[j])
            j = lps[j - 1];
        if (p[i] == p[j])
            j++;
        lps[i] = j;
    }
    int i = 0, j = 0;
    while (i < n)
    {
        if (p[j] == s[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            j = lps[j - 1];
            return true;
        }
        else if (i < n && p[j] != s[i])
        {
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }
    return false;
}
void DBClose()
{
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
    system("pause");
    exit(0);
}
void DBInit()
{
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
    DBClose();
    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
	DBClose();
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
    DBClose();
	if (SQL_SUCCESS != SQLSetConnectAttr(sqlConnHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
	DBClose();
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
		DBClose();
		break;
	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		DBClose();
		break;
	default:
		break;
	}
	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		DBClose();
}
void Quanlytour::Menu()
{   
    Customer arrCus[Max];
    Hotel arrHo[Max];
    Landscape arrLand[Max];
    Registration arrReg[Max];
    Ticket arrTic[Max];
    Tour arrTour[Max];
    Vehice arrVehice[Max];
    int index = 0;
    int cus = 0;
    int reg = 0;
    int ticket = 0;
    int ho = 0;
    int veh = 0;
    int land = 0;
    int n, k, r, x;
    do
    {   
        system("cls");
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t";
        DBInit();
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)"SELECT * FROM Tour", SQL_NTS)) 
        {
		    cout << "Error querying SQL Server";
		    cout << "\n";
		    DBClose();
	    }
        else
        {
            char matour[20];
            char tentour[100];
            char ngaybd[20];
            char ngaykt[20];
            int  gia;
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
        }
        SQLCancel(sqlStmtHandle);
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)"SELECT * FROM Khachsan", SQL_NTS)) 
        {
		    cout << "Error querying SQL Server";
		    cout << "\n";
		    DBClose();
	    }
        else
        {
            char makhachsan[20];
            char tenkhachsan[100];
            char diadiemkhachsan[100];
            char matour[20];
            while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
            {
                SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &makhachsan, sizeof(makhachsan) ,NULL);
                SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &tenkhachsan, sizeof(tenkhachsan) ,NULL);
                SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &diadiemkhachsan, sizeof(diadiemkhachsan) ,NULL);
                SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &matour, sizeof(matour) ,NULL);
			    arrHo[ho] = Hotel(matour, makhachsan, tenkhachsan, diadiemkhachsan);
			    ++ho;
            }
        }
        SQLCancel(sqlStmtHandle);
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)"SELECT * FROM Phuongtien", SQL_NTS)) 
        {
		    cout << "Error querying SQL Server";
		    cout << "\n";
		    DBClose();
	    }
        else
        {
            char maphuongtien[20];
            char tenphuongtien[100];
            char loaiphuongtien[100];
            int socho;
            char matour[20];
            while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
            {
                SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &maphuongtien, sizeof(maphuongtien) ,NULL);
                SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &tenphuongtien, sizeof(tenphuongtien) ,NULL);
                SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &loaiphuongtien, sizeof(loaiphuongtien) ,NULL);
                SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &socho, sizeof(socho) ,NULL);
                SQLGetData(sqlStmtHandle, 5 , SQL_C_DEFAULT, &matour, sizeof(matour) ,NULL);
			    arrVehice[veh] = Vehice(matour, maphuongtien, tenphuongtien, loaiphuongtien, socho);
			    ++veh;
            }
        }
        SQLCancel(sqlStmtHandle);
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)"SELECT * FROM Diemthamquan", SQL_NTS)) 
        {
		    cout << "Error querying SQL Server";
		    cout << "\n";
		    DBClose();
	    }
        else
        {
            char madiemthamquan[20];
            char tendiadiemthamquan[100];
            char diadiemthamquan[100];
            char makhachsan[20];
            char matour[20];
            while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
            {
                SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &madiemthamquan, sizeof(madiemthamquan) ,NULL);
                SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &tendiadiemthamquan, sizeof(tendiadiemthamquan) ,NULL);
                SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &diadiemthamquan, sizeof(diadiemthamquan) ,NULL);
                SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &makhachsan, sizeof(makhachsan) ,NULL);
                SQLGetData(sqlStmtHandle, 5 , SQL_C_DEFAULT, &matour, sizeof(matour) ,NULL);
			    arrLand[land] = Landscape(matour, makhachsan, madiemthamquan, tendiadiemthamquan, diadiemthamquan);
			    ++land;
            }
        }
        SQLCancel(sqlStmtHandle);
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)"SELECT * FROM Khachhang", SQL_NTS)) 
        {
		    cout << "Error querying SQL Server";
		    cout << "\n";
		    DBClose();
	    }
        else
        {
            char makhachhang[20];
            char tenkhachhang[100];
            char diachikhachhang[100];
            int sdt;
            while(SQLFetch(sqlStmtHandle)== SQL_SUCCESS)
            {
                SQLGetData(sqlStmtHandle, 1 , SQL_C_DEFAULT, &makhachhang, sizeof(makhachhang) ,NULL);
                SQLGetData(sqlStmtHandle, 2 , SQL_C_DEFAULT, &tenkhachhang, sizeof(tenkhachhang) ,NULL);
                SQLGetData(sqlStmtHandle, 3 , SQL_C_DEFAULT, &diachikhachhang, sizeof(diachikhachhang) ,NULL);
                SQLGetData(sqlStmtHandle, 4 , SQL_C_DEFAULT, &sdt, sizeof(sdt) ,NULL);
			    arrCus[cus] = Customer(makhachhang, tenkhachhang, diachikhachhang, sdt);
			    ++cus;
            }
        }
        SQLCancel(sqlStmtHandle);
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)"SELECT * FROM Dangky", SQL_NTS)) 
        {
		    cout << "Error querying SQL Server";
		    cout << "\n";
		    DBClose();
	    }
        else
        {
            char madangky[20];
            int sove;
            char makhachhang[20];
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
        system("pause");
        tryagain:
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\t ***Quan Ly Tour Du Lich*** \n";
        cout << "\t\t\t\t\t\t\t\t\t 1. Ban la Khach Hang \n";
        cout << "\t\t\t\t\t\t\t\t\t 2. Ban la Nhan vien Quan Ly \n";
        cout << "\t\t\t\t\t\t\t\t\t 0. Thoat khoi ung dung \n";
        cout << "\t\t\t\t\t\t\t\t\t Nhan so de lua chon: ";
        cin >> x;
        while (cin.fail())
        {
            cout << "\t\t\t\t\t\t\t\t    Loi kieu nhap !!! Vui long nhap lai";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t Nhan so de lua chon: ";
            cin >> x;
        }
        switch (x)
        {
        case 1:
        {
            int kh;
            do
            {   
                tryagain1:
                system("cls");
                cout << "\n\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t-------------------- List Lua Chon Cho Khach Hang -------------------- \n";
                cout << "\t\t\t\t\t\t\t\t 1. Dat Tour \n";
                cout << "\t\t\t\t\t\t\t\t 2. Tim Kiem Dia Diem \n";
                cout << "\t\t\t\t\t\t\t\t 3. Sap Xep Theo gia ve \n";
                cout << "\t\t\t\t\t\t\t\t 4. Thong Tin Ve Tour \n";
                cout << "\t\t\t\t\t\t\t\t 5. Trang Thai Tour \n";
                cout << "\t\t\t\t\t\t\t\t 6. Danh sach Tour \n";
                cout << "\t\t\t\t\t\t\t\t 7. Tao lap khach hang va tim kiem ma khach hang \n";
                cout << "\t\t\t\t\t\t\t\t 0. Thoat Ve Trang Chu \n";
                cout << "\t\t\t\t\t\t\t\t Nhap lua chon cua ban: ";
                cin >> kh;
                while (cin.fail())
                {
                    cout << "\t\t\t\t\t\t\t\t Loi kieu nhap !!! Vui long nhap lai";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\n";
                    cout << "\t\t\t\t\t\t\t\t Nhap lua chon cua ban: ";
                    cin >> kh;
                }
                switch (kh)
                {
                case 1:
                {
                    system("cls");
                    string matour, makhachhang, madangky, thutuve;
                    int vt, lc, vt1, sove, vtho, vtveh, vtland;
                    int dem = 0;
                    int dem1= 0;
                    cout << "\t\t\t\t\t\t---------------------------- List Tour ---------------------------- \n";
                    cout << "\t" << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(30) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << endl;
                    for (int i = 0; i < index; i++)
                    {
                        arrTour[i].Show();
                    }
                    cout << "\n Lua Chon Ma Tour - Xem Thong tin chi tiet : ";
                    fflush(stdin);
                    getline(cin, matour);
                    vt = Searching(arrTour, index, matour);
                    vtho = SearchingHo(arrHo, ho, matour);
                    vtveh = SearchingVeh(arrVehice, veh, matour);
                    vtland = SearchingLand(arrLand, land, matour);
                    if (vt != -1 && vtho != -1 && vtveh != -1 && vtland != -1)
                    {
                        system("cls");
                        cout << setw(20) << "Tour: \n\n"
                             << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(20) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << endl;
                        arrTour[vt].Show();
                        cout << endl;
                        cout << setw(20) << "Hotel: \n\n"
                             << setw(20) << "Makhachsan" << setw(20) << "Ten Khach San" << setw(20) << "Dia diem khach san" << setw(20) << "Matour" << endl;
                        arrHo[vtho].Show();
                        cout << endl;
                        cout << setw(20) << "Landscape: \n\n"
                             << setw(20) << "Madtq" << setw(20) << "Tendtq" << setw(20) << "DiaDiemThamQuan" << setw(20) << "MaKhachsan" << setw(20) << "Matour" << endl;
                        arrLand[vtland].Show();
                        cout << endl;
                        cout << setw(20) << "Vehice: \n\n"
                             << setw(20) << "Maphuontien" << setw(20) << "Tenphuongtien" << setw(20) << "Loaiphuongtien" << setw(20) << "Socho" << setw(20) << "Matour" << endl;
                        arrVehice[vtveh].Show();
                        do
                        {
                            cout << "\n\n Ban co muon dat tour nay khong ? 1. Co - 2. Khong" << endl;
                            cout << "Lua Chon Cua Ban: ";
                            cin >> lc;
                            while (cin.fail())
                            {
                                cout << "Loi kieu nhap !!! Vui long nhap lai";
                                cin.clear();
                                cin.ignore(256, '\n');
                                cout << "\n";
                                cout << "Lua chon cua ban: ";
                                cin >> lc;
                            }
                            switch (lc)
                            {
                            case 1:
                            {
                                system("cls");
                                int count = 0;
                                cout << "Nhap Makhachhang: ";
                                fflush(stdin);
                                getline(cin, makhachhang);
                                vt1 = SearchingCustomer(arrCus, cus, makhachhang);
                                while(vt1 == -1 && count <= 3)
                                {
                                    cout << "Khong tim thay khach hang co ma " << makhachhang << endl;
                                    cin.clear();
                                    getline(cin, makhachhang);
                                    vt1 = SearchingCustomer(arrCus, cus, makhachhang);
                                    ++count;
                                    if (count > 3)
                                    {
                                        goto tryagain1;
                                    }
                                }
                                arrCus[vt1].Show();
                                if (vt1 != -1)
                                {
                                    cout << "\nNhap so luong ve ban muon: ";
                                    cin >> sove;
                                    if (sove <= arrVehice[vtveh].GetSocho())
                                    {
                                        arrVehice[vt].SetSocho(arrVehice[vtveh].GetSocho() - sove);
                                        cout << "\n\nTong gia tien: ";
                                        int total = arrTour[vt].GetGia() * sove;
                                        cout << total;
                                        int chapthuan;
                                        cout << "\n Nhan 1.Chap Thuan - 2. Khong Chap Thuan ----> ";
                                        cin >> chapthuan;
                                        if (chapthuan == 1)
                                        {
                                            for (int i = reg; i <  1 + reg; i++)
                                            {
                                                arrReg[i].SetMatour(matour);
                                                arrReg[i].SetMakhachhang(makhachhang);
                                                arrReg[i].SetSoluongve(sove);
                                                madangky = to_string(i + 1);
                                                arrReg[i].SetMadangky("DK" + madangky);
                                                dem++;
                                            }
                                            reg += dem;
                                            string slve = to_string(sove);
                                            string str1 = "INSERT INTO [dbo].[Dangky] VALUES (N'"+makhachhang+"',"+slve+",N'""DK"+madangky+"',N'"+matour+"')";
                                            char m1[Max];
                                            strcpy(m1,str1.c_str());
                                            if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m1, SQL_NTS))
                                            {
                                                cout << "\n";
		                                        cout << "Error querying SQL Server";
		                                        cout << "\n";
		                                        DBClose();
	                                        }
	                                        else 
                                            {
                                                cout << "\nINSERT SUCCESS REGIS";
                                            }
                                            SQLCancel(sqlStmtHandle);
                                            for (int j = ticket; j < 1 + ticket; j++)
                                            {
                                                arrTic[j].SetMakhachhang(makhachhang);
                                                arrTic[j].SetMatour(matour);
                                                arrTic[j].SetTenve(arrTour[vt].GetTentour());
                                                thutuve = to_string(j + 1);
                                                arrTic[j].SetMave("MV" + thutuve);
                                                dem1++;
                                            }
                                            ticket += dem1;
                                            string str2 = "INSERT INTO [dbo].[Ve] VALUES (N'""MV"+thutuve+"',N'"+arrTour[vt].GetTentour()+"',N'"+matour+"',N'"+makhachhang+"')";
                                            char m2[Max];
                                            strcpy(m2,str2.c_str());
                                            if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m2, SQL_NTS))
                                            {
                                                cout << "\n";
		                                        cout << "Error querying SQL Server";
		                                        cout << "\n";
		                                        DBClose();
	                                        }
	                                        else 
                                            {
                                                cout << "\nINSERT SUCCESS TIC";
                                            }
                                            SQLCancel(sqlStmtHandle);
                                            cout << "Thuc hien Thanh cong ";
                                            system("pause");
                                            lc = 2;
                                            break;
                                        }
                                        else
                                        {   
                                            lc = 2;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        cout << "So ve ban dat da het !!";
                                        lc = 2;
                                        break;
                                    }
                                }
                            }
                            break;
                            case 2:
                                break;
                            }
                        } while (lc != 2);
                    }
                    else
                    {
                        cout << "Tour Chua duoc thiet lap hoan chinh hoac khong ton tai" << endl;
                        system("pause");
                    }
                }
                break;
                case 2:
                {
                    string diadiem;
                    string tentour;
                    int dem = 0;
                    system("cls");
                    cout << "Nhap Dia Diem ban muon tiem kiem: ";
                    fflush(stdin);
                    getline(cin, diadiem);
                    cout << "\t\t\t\t\t\t\t\t Nhung Tour co dia diem lien quan \n\n";
                    for (int i = 0; i < index; i++)
                    {
                        tentour = arrTour[i].GetTentour();
                        if (KMP(tentour, diadiem) == true)
                        {
                            arrTour[i].Show();
                        }
                    }
                    system("pause");
                }
                break;
                case 3:
                {
                    system("cls");
                    int price[Max];
                    cout << "\t" << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(30) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << endl;
                    for (int i = 0; i < index; i++)
                    {
                        price[i] = arrTour[i].GetGia();
                    }
                    quicksort(price, 0, index - 1);
                    for (int i = 0; i < index; i++)
                    {
                        for (int j = i + 1; j < index; j++)
                        {
                            if (arrTour[i].GetGia() > arrTour[j].GetGia())
                            {
                                swapVal(arrTour[i], arrTour[j]);
                            }
                        }
                    }
                    for (int i = 0; i < index; i++)
                    {
                        arrTour[i].Show();
                    }
                    system("pause");
                }
                break;
                case 4:
                {
                    string tenkhachhang, makhachhang;
                    int vt1,vt2;
                    system("cls");
                    cout << "Nhap ten khach hang ban da dang ky: ";
                    fflush(stdin);
                    getline(cin, tenkhachhang);
                    vt1 = SearchingNameCustomer(arrCus, cus, tenkhachhang);
                    if (vt1 != -1)
                    {   
                        makhachhang = arrCus[vt1].GetMakhachhang();
                        vt2 = SearchingRegis(arrReg, reg, makhachhang);
                        cout << "\t\t\t\t\t\t\t\t Khach hang da dang ky Tour \n\n\n";
                        cout << "\t" << setw(20) << "Makhachhang" << setw(25) << "Tenkhachhang" << setw(25) << "DiaChi" << setw(25) << "SDT" << setw(20) << "Matour" << setw(20) << "SoLuongVe" << endl;
                        cout << arrCus[vt1] << setw(20) << arrReg[vt2].GetMatour() << setw(20) << arrReg[vt2].GetSoluongve() << endl;
                    }
                    system("pause");
                }
                break;
                case 5:
                {
                    system("cls");
                    string matour;
                    int vtveh;
                    cout << "\t\t\t\t\t\t---------------------------- Tinh Trang Tour ---------------------------- \n";
                    cout << "\t" << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(30) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << setw(20) << "Socho" << endl;
                    for (int i = 0; i < index; i++)
                    {
                        matour = arrTour[i].GetMatour();
                        vtveh = SearchingVeh(arrVehice, veh, matour);
                        cout << arrTour[i] << setw(20) << arrVehice[vtveh].GetSocho() << endl;
                    }
                    system("pause");
                }
                break;
                case 6:
                {
                    system("cls");
                    cout << "\t" << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(30) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << endl;
                    for (int i = 0; i < index; i++)
                    {
                        arrTour[i].Show();
                    }
                    system("pause");
                }
                break;
                case 7:
                {
                    system("cls");
                    int lc, vt2, dem = 0;
                    string thutu, sdt;
                    do
                    {
                        system("cls");
                        cout << "\n\n\n\n\n\n\n";
                        cout << "\t\t\t\t\t\t\t\t 1. Tao lap khach hang \n";
                        cout << "\t\t\t\t\t\t\t\t 2. Tim kiem ma khach hang theo ten \n";
                        cout << "\t\t\t\t\t\t\t\t 0. Thoat ra \n";
                        cout << "\t\t\t\t\t\t\t\t Lua chon cua ban: ";
                        cin >> lc;
                        while (cin.fail())
                        {
                            cout << "\t\t\t\t\t\t\t    Loi kieu nhap !!! Vui long nhap lai";
                            cin.clear();
                            cin.ignore(256, '\n');
                            cout << "\n";
                            cout << "\t\t\t\t\t\t\t\t Lua chon cua ban: ";
                            cin >> lc;
                        }
                        switch (lc)
                        {
                        case 1:
                        {
                            system("cls");
                            cout << "\t\t Luu y: neu ban la khach hang thu i trong danh sach vui long nhap makhachhang la KH + i , i la so thu tu khach hang \n\n";
                            // cout << " Nhap khach hang ban muon them : ";
                            // cin >> k;
                            while(cin.fail())
                            {
                                cout << " Nhap lai de dung kieu du lieu";
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\n";
                                cout << " Nhap khach hang ban muon them : ";
                                cin >> k;
                            }
                            for (int i = cus; i < 1 + cus; i++)
                            {
                                cout << " Ban La khach hang thu " << i + 1 << " : " << endl;
                                arrCus[i].Get();
                                thutu = to_string(i+1);
                                arrCus[i].SetMakhachhang("KH" + thutu);
                                dem++;
                                sdt = to_string(arrCus[i].GetSDT());
                                string str2 = "INSERT INTO [dbo].[Khachhang] VALUES (N'""KH"+thutu+"',N'"+arrCus[i].GetTenkhachhang()+"',N'"+arrCus[i].GetDiachi()+"',"+sdt+")";
                                char m2[Max];
                                strcpy(m2,str2.c_str());
                                system("pause");
                                if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m2, SQL_NTS))
                                {
                                    cout << "\n";
                                    cout << "Error querying SQL Server";
                                    cout << "\n";
                                    DBClose();
                                }
                                else 
                                {
                                    cout << "\nINSERT SUCCESS CUSTOMER";
                                }
                                SQLCancel(sqlStmtHandle);
                            }
                            cus += dem;
                            cout << "\n\n";
                            cout << " Thuc hien Thanh Cong";
                            system("pause");
                        }
                        break;
                        case 2:
                        {
                            system("cls");
                            string tenkhachhang, tensosanh;
                            cout << "Nhap Ten Cua Ban: ";
                            fflush(stdin);
                            getline(cin, tenkhachhang);
                            vt2 = SearchingNameCustomer(arrCus, cus, tenkhachhang);
                            for (int i = 0; i < cus; i++)
                            {
                                tensosanh = arrCus[i].GetTenkhachhang();
                                if (KMP(tensosanh, tenkhachhang) == true)
                                {
                                    arrCus[i].Show();
                                }
                            }
                            system("pause");
                        }
                        break;
                        case 0:
                        break;
                        }
                    } while (lc != 0);
                }
                break;
                case 0:
                    goto tryagain;
                    break;
                }
            } while (kh != 0);
        }
        break;

        case 2:
        {
            int ql, k;
            do
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t-------------------- List Lua Chon Cho Quan ly -------------------- \n";
                cout << "\t\t\t\t\t\t\t\t 1. Them Tour \n";
                cout << "\t\t\t\t\t\t\t\t 2. Danh Sach Tour \n";
                cout << "\t\t\t\t\t\t\t\t 3. Tim Kiem Va Chinh Sua Tour \n";
                cout << "\t\t\t\t\t\t\t\t 4. Xoa Tour \n";
                cout << "\t\t\t\t\t\t\t\t 5. Danh sach khach hang da dat Tour \n";
                cout << "\t\t\t\t\t\t\t\t 0. Thoat Ve Trang Chu \n";
                cout << "\t\t\t\t\t\t\t\t Nhap Lua Chon Cua Ban: ";
                cin >> ql;
                while (cin.fail())
                {
                    cout << "\t\t\t\t\t\t\t    Loi kieu nhap !!! Vui long nhap lai";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\n";
                    cout << "\t\t\t\t\t\t\t\t Nhap lua chon cua ban: ";
                    cin >> ql;
                }
                switch (ql)
                {
                case 1:
                {
                    system("cls");
                    string matour, makhachsan;
                    int dem = 0, dem1 = 0, dem2 = 0, dem3 = 0;
                    for (int i = 0; i < index; i++)
                    {
                        for (int j = i + 1; j < index; j++)
                        {
                            for (int z = 2; z <= 5; z++)
                            {
                                if(int(arrTour[i].GetMatour()[z]) > int(arrTour[j].GetMatour()[z]))
                                {
                                    swapVal(arrTour[i], arrTour[j]);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < ho; i++)
                    {
                        for (int j = i + 1; j < ho; j++)
                        {
                            for (int z = 2; z <= 5; z++)
                            {
                                if(int(arrHo[i].GetMakhachsan()[z]) > int(arrHo[j].GetMakhachsan()[z]))
                                {
                                    swapVal(arrHo[i], arrHo[j]);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < land; i++)
                    {
                        for (int j = i + 1; j < land; j++)
                        {
                            for (int z = 3; z <= 6; z++)
                            {
                                if(int(arrLand[i].GetMadtq()[z]) > int(arrLand[j].GetMadtq()[z]))
                                {
                                    swapVal(arrLand[i], arrLand[j]);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < veh; i++)
                    {
                        for (int j = i + 1; j < veh; j++)
                        {
                            for (int z = 2; z <= 5; z++)
                            {
                                if(int(arrVehice[i].GetMaphuongtien()[z]) > int(arrVehice[j].GetMaphuongtien()[z]))
                                {
                                    swapVal(arrVehice[i], arrVehice[j]);
                                }
                            }
                        }
                    }
                    for (int i = index; i < 1 + index; i++)
                    {
                        cout << "\n Nhap thong tin Tour thu " << i + 1 << " :" << endl;
                        string thutu = to_string(i + 1);
                        string thutu2 = to_string(i + 2);
                        string thutu3 = to_string(i - 1);
                        for (int j = 0; j < index; j++)
                        {
                            if (("MT" + thutu) == arrTour[j].GetMatour())
                            {
                                arrTour[i].SetMatour("MT" + thutu2);
                            }
                            else
                            {
                                for (int k = 0; k < index - 1; k++)
                                {
                                    if (("MT" + thutu) == arrTour[k].GetMatour())
                                    {
                                        arrTour[i].SetMatour("MT" + thutu3);
                                    }
                                    else
                                    {
                                        arrTour[i].SetMatour("MT" + thutu);
                                    }
                                }
                            }
                        }
                        arrTour[i].Get();
                        matour = arrTour[i].GetMatour();
                        dem++;
                        string gia = to_string(arrTour[i].GetGia());
                        string str1 = "INSERT INTO [dbo].[Tour] VALUES (N'"+arrTour[i].GetMatour()+"',N'"+arrTour[i].GetTentour()+"','"+arrTour[i].GetNgayBD()+"','"+arrTour[i].GetNgayKT()+"',"+gia+")";
                        char m1[Max];
                        strcpy(m1,str1.c_str());
                        cout << m1;
                        system("pause");
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m1, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nINSERT SUCCESS TOUR\n";
                        }
                        SQLCancel(sqlStmtHandle);
                    }
                    index += dem;
                    for (int j = ho; j < 1 + ho; j++)
                    {
                        arrHo[j].SetMatour(matour);
                        string thutu = to_string(j + 1);
                        string thutu2 = to_string(j + 2);
                        string thutu3 = to_string(j - 1);
                        for (int k = 0; k < ho; k++)
                        {
                            if(("KS" + thutu) == arrHo[k].GetMakhachsan())
                            {
                                arrHo[j].SetMakhachsan("KS" + thutu2);
                            }
                            else
                            {
                                for (int i = 0; i < ho - 1; i++)
                                {
                                    if (("KS" + thutu) == arrHo[i].GetMakhachsan())
                                    {
                                        arrHo[j].SetMakhachsan("KS" + thutu3);
                                    }
                                    else
                                    {
                                        arrHo[j].SetMakhachsan("KS" + thutu);
                                    }
                                }
                            }
                        }
                        arrHo[j].Get();
                        makhachsan = arrHo[j].GetMakhachsan();
                        dem1++;
                        string str2 = "INSERT INTO [dbo].[Khachsan] VALUES (N'"+arrHo[j].GetMakhachsan()+"',N'"+arrHo[j].GetTenkhachsan()+"',N'"+arrHo[j].GetDiadiemKS()+"',N'"+arrHo[j].GetMaTour()+"')";
                        char m2[Max];
                        strcpy(m2,str2.c_str());
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m2, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nINSERT SUCCESS HOTEL\n";
                        }
                        SQLCancel(sqlStmtHandle);
                    }
                    ho += dem1;
                    for (int z = land; z < 1 + land; z++)
                    {
                        arrLand[z].SetMatour(matour);
                        arrLand[z].SetMakhachsan(makhachsan);
                        string thutu = to_string(z + 1);
                        string thutu2 = to_string(z + 2);
                        string thutu3 = to_string(z - 1);
                        for (int j = 0; j < land; j++)
                        {
                            if(("DTQ" + thutu) == arrLand[j].GetMadtq())
                            {
                                arrLand[z].SetMadtq("DTQ" + thutu2);
                            }
                            else
                            {
                                for(int i = 0; i < land - 1; i++)
                                {
                                    if(("DTQ" + thutu) == arrLand[i].GetMadtq())
                                    {
                                        arrLand[z].SetMadtq("DTQ" + thutu3);
                                    }
                                    else
                                    {
                                        arrLand[z].SetMadtq("DTQ" + thutu);
                                    }
                                }
                            }
                        }
                        arrLand[z].Get();
                        dem2++;
                        string str3 = "INSERT INTO [dbo].[Diemthamquan] VALUES (N'"+arrLand[z].GetMadtq()+"',N'"+arrLand[z].GetTendtq()+"',N'"+arrLand[z].GetDiadiemTQuan()+"',N'"+arrLand[z].GetMakhachsan()+"',N'"+arrLand[z].GetMatour()+"')";
                        char m3[Max];
                        strcpy(m3,str3.c_str());
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m3, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nINSERT SUCCESS LANDSCAPE\n";
                        }
                        SQLCancel(sqlStmtHandle);
                    }
                    land += dem2;
                    for (int c = veh; c < 1 + veh; c++)
                    {
                        arrVehice[c].SetMatour(matour);
                        string thutu = to_string(c + 1);
                        string thutu2 = to_string(c + 2);
                        string thutu3 = to_string(c - 1);
                        for (int i = 0; i < veh; i++)
                        {
                            if(("PT" + thutu) == arrVehice[i].GetMaphuongtien())
                            {
                                arrVehice[c].SetMaphuongtien("PT" + thutu2);
                            }
                            else
                            {   
                                for(int j = 0; j < veh - 1; j++)
                                {
                                    if(("PT" + thutu) == arrVehice[j].GetMaphuongtien())
                                    {
                                        arrVehice[c].SetMaphuongtien("PT" + thutu3);
                                    }
                                    else
                                    {
                                        arrVehice[c].SetMaphuongtien("PT" + thutu);
                                    }
                                }
                            }
                        }
                        arrVehice[c].Get();
                        string socho = to_string(arrVehice[c].GetSocho());
                        dem3++;
                        string str4 = "INSERT INTO [dbo].[Phuongtien] VALUES (N'"+arrVehice[c].GetMaphuongtien()+"',N'"+arrVehice[c].GetTenphuongtien()+"',N'"+arrVehice[c].GetLoaiphuongtien()+"',"+socho+",N'"+arrVehice[c].GetMatour()+"')";
                        char m4[Max];
                        strcpy(m4,str4.c_str());
                        cout << m4;
                        system("pause");
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m4, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nINSERT SUCCESS VEHICE\n";
                        }
                        SQLCancel(sqlStmtHandle);
                    } 
                    veh += dem3;
                    cout << "\n Da Nhap Xong !";
                                        for (int i = 0; i < index; i++)
                    {
                        for (int j = i + 1; j < index; j++)
                        {
                            for (int z = 2; z <= 5; z++)
                            {
                                if(int(arrTour[i].GetMatour()[z]) > int(arrTour[j].GetMatour()[z]))
                                {
                                    swapVal(arrTour[i], arrTour[j]);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < ho; i++)
                    {
                        for (int j = i + 1; j < ho; j++)
                        {
                            for (int z = 2; z <= 5; z++)
                            {
                                if(int(arrHo[i].GetMakhachsan()[z]) > int(arrHo[j].GetMakhachsan()[z]))
                                {
                                    swapVal(arrHo[i], arrHo[j]);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < land; i++)
                    {
                        for (int j = i + 1; j < land; j++)
                        {
                            for (int z = 3; z <= 6; z++)
                            {
                                if(int(arrLand[i].GetMadtq()[z]) > int(arrLand[j].GetMadtq()[z]))
                                {
                                    swapVal(arrLand[i], arrLand[j]);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < veh; i++)
                    {
                        for (int j = i + 1; j < veh; j++)
                        {
                            for (int z = 2; z <= 5; z++)
                            {
                                if(int(arrVehice[i].GetMaphuongtien()[z]) > int(arrVehice[j].GetMaphuongtien()[z]))
                                {
                                    swapVal(arrVehice[i], arrVehice[j]);
                                }
                            }
                        }
                    }
                    system("pause");
                }
                break;
                case 2:
                {
                    system("cls");
                    cout << "\t" << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(30) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << endl;
                    for (int i = 0; i < index; i++)
                    {
                        arrTour[i].Show();
                    }
                    system("pause");
                }
                break;
                case 3:
                {
                    int vt, n, t, d, vtveh, vtho, vtland;
                    do
                    {
                        system("cls");
                        string matour;
                        cout << "\n Nhap Ma tour ma ban muon tim kiem: ";
                        fflush(stdin);
                        getline(cin, matour);
                        vt = Searching(arrTour, index, matour);
                        vtveh = SearchingVeh(arrVehice, veh, matour);
                        vtho = SearchingHo(arrHo, ho, matour);
                        vtland = SearchingLand(arrLand, land, matour);
                        if (vt != -1 && vtho != -1 && vtveh != -1 && vtland != -1) 
                        {
                            system("cls");
                            cout << "\t\t\t\t\t\t\t\t Thong tin Tour co MaTour " << matour << endl;
                            cout << "\t" << setw(20) << "MaTour" << setw(40) << "Ten Tour" << setw(30) << "NgayBD" << setw(20) << "NgayKT" << setw(20) << "Gia" << endl;
                            arrTour[vt].Show();
                            do
                            {

                                cout << "\t\t\t\t\t\t\t\t ----Bang Sua Thong tin tour----" << endl;
                                cout << "\t\t\t\t\t\t\t\t 1. Sua TenTour \n";
                                cout << "\t\t\t\t\t\t\t\t 2. Sua NgayBD \n";
                                cout << "\t\t\t\t\t\t\t\t 3. Sua NgayKT \n";
                                cout << "\t\t\t\t\t\t\t\t 4. Sua Gia \n";
                                cout << "\t\t\t\t\t\t\t\t 5. Sua Thong tin khach san \n";
                                cout << "\t\t\t\t\t\t\t\t 6. Sua Thong tin phuong tien \n";
                                cout << "\t\t\t\t\t\t\t\t 7. Sua Thong tin diem tham quan \n";
                                cout << "\t\t\t\t\t\t\t\t 0. Quay Ve \n";
                                cout << "\n Su lua chon cua ban la: ";
                                cin >> t;
                                while (cin.fail())
                                {
                                    cout << "\t\t\t\t\t\t\t    Loi kieu nhap !!! Vui long nhap lai";
                                    cin.clear();
                                    cin.ignore(256, '\n');
                                    cout << "\n";
                                    cout << "\t\t\t\t\t\t\t\t Lua chon cua ban: ";
                                    cin >> t;
                                }
                                switch (t)
                                {
                                case 1:
                                {
                                    system("cls");
                                    string tentour;
                                    cout << "TenTour Ban Muon Sua: ";
                                    fflush(stdin);
                                    getline(cin, tentour);
                                    arrTour[vt].SetTentour(tentour);
                                    string str = "UPDATE [DBO].[Tour] SET Tentour = N'"+tentour+"' WHERE Matour = N'"+arrTour[vt].GetMatour()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong !";
                                    system("pause");
                                }
                                break;
                                case 2:
                                {
                                    system("cls");
                                    string ngayBD;
                                    cout << "NgayBD Ban Muon Sua: ";
                                    fflush(stdin);
                                    getline(cin, ngayBD);
                                    arrTour[vt].SetNgayBD(ngayBD);
                                    string str = "UPDATE [DBO].[Tour] SET NgayBD = N'"+ngayBD+"' WHERE Matour = N'"+arrTour[vt].GetMatour()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong";
                                    system("pause");
                                }
                                break;
                                case 3:
                                {
                                    system("cls");
                                    string ngayKt;
                                    cout << "NgayKt Ban Muon Sua: ";
                                    fflush(stdin);
                                    getline(cin, ngayKt);
                                    arrTour[vt].SetNgayKT(ngayKt);
                                    string str = "UPDATE [DBO].[Tour] SET NgayKT = N'"+ngayKt+"' WHERE Matour = N'"+arrTour[vt].GetMatour()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong";
                                    system("pause");
                                }
                                break;
                                case 4:
                                {
                                    system("cls");
                                    int gia;
                                    cout << "Gia Ban Muon Sua: ";
                                    cin >> gia;
                                    while(cin.fail())
                                    {
                                        cout << "Nhap sai kieu du lieu !!! Nhaplai: ";
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> gia;
                                    }
                                    arrTour[vt].SetGia(gia);
                                    string giatour = to_string(gia);
                                    string str = "UPDATE [DBO].[Tour] SET Gia = "+giatour+" WHERE Matour = N'"+arrTour[vt].GetMatour()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong";
                                    system("pause");
                                }
                                break;
                                case 5:
                                {
                                    system("cls");
                                    string tenkhachsan, diadiemkhachsan;
                                    cout << "Ten khach san moi: ";
                                    fflush(stdin);
                                    getline(cin, tenkhachsan);
                                    arrHo[vtho].SetTenkhachsan(tenkhachsan);
                                    cout << "Dia diem khach san moi: ";
                                    fflush(stdin);
                                    getline(cin, diadiemkhachsan);
                                    arrHo[vtho].SetDiadiemKS(diadiemkhachsan);
                                    string str = "UPDATE [DBO].[Khachsan] SET Tenks = N'"+tenkhachsan+"', Diadiem = N'"+diadiemkhachsan+"' WHERE Maks = N'"+arrHo[vtho].GetMakhachsan()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong";
                                    system("pause");
                                }
                                break;
                                case 6:
                                {
                                    system("cls");
                                    string tenphuongtien, loaiphuongtien, sochophuongtien;
                                    int socho;
                                    cout << "Ten phuong tien moi: ";
                                    fflush(stdin);
                                    getline(cin, tenphuongtien);
                                    arrVehice[vtveh].SetTenphuongtien(tenphuongtien);
                                    cout << "Loai phuong tien moi: ";
                                    fflush(stdin);
                                    getline(cin, loaiphuongtien);
                                    arrVehice[vtveh].SetLoaiphuongtien(loaiphuongtien);
                                    cout << "So cho moi: ";
                                    cin >> socho;
                                    while(cin.fail())
                                    {
                                        cout << "Nhap sai kieu du lieu !!! Nhaplai: ";
                                        cin.clear();
                                        cin.ignore(256, '\n');
                                        cin >> socho;
                                    }
                                    arrVehice[vtveh].SetSocho(socho);
                                    sochophuongtien = to_string(socho);
                                    string str = "UPDATE [DBO].[Phuongtien] SET Tenpt = N'"+tenphuongtien+"', Loaipt = N'"+loaiphuongtien+"', Socho = "+sochophuongtien+" WHERE Mapt = N'"+arrVehice[vtveh].GetMaphuongtien()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong";
                                    system("pause");
                                }
                                case 7:
                                {
                                    system("cls");
                                    string tendtq, diadiemthamquan;
                                    cout << "Ten diem tham quan moi: ";
                                    fflush(stdin);
                                    getline(cin, tendtq);
                                    arrLand[vtland].SetTendtq(tendtq);
                                    cout << "Dia diem tham quan moi: ";
                                    fflush(stdin);
                                    getline(cin, diadiemthamquan);
                                    arrLand[vtland].SetDiadiemTQuan(diadiemthamquan);
                                    string str = "UPDATE [DBO].[Diemthamquan] SET Tendtv = N'"+tendtq+"', Diadiem = N'"+diadiemthamquan+"' WHERE Madtq = N'"+arrLand[vtland].GetMadtq()+"'";
                                    char m[Max];
                                    strcpy(m,str.c_str());
                                    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                                    {
                                        cout << "\n";
                                        cout << "Error querying SQL Server";
                                        cout << "\n";
                                        DBClose();
                                    }
                                    else 
                                    {
                                        cout << "\nUPDATE SUCCESS\n";
                                    }
                                    SQLCancel(sqlStmtHandle);
                                    cout << "\n Da cap nhat thanh cong";
                                    system("pause");
                                }
                                case 0:
                                    break;
                                }
                            } while (t != 0);
                            d = 1;
                        }
                        else
                        {
                            cout << "\nWarning Ma Tour Khong tim thay hoac Chua hoan thien!! \n";
                            d = 2;
                            system("pause");
                            break;
                        }
                    } while (d != 1);
                }
                break;
                case 4:
                {
                    string matour;
                    int n, vt, vtveh, vtland, vtho, vttic;
                    int dem = 0, dem1 = 0, dem2= 0, dem3 = 0;;
                    system("cls");
                    cout << "Nhap MaTour Ma Ban Muon Xoa: ";
                    fflush(stdin);
                    getline(cin, matour);
                    vt = Searching(arrTour, index, matour);
                    vtveh = SearchingVeh(arrVehice, veh, matour);
                    vtho = SearchingHo(arrHo, ho, matour);
                    vtland = SearchingLand(arrLand, land ,matour);
                    vttic = SearchingTic(arrTic, ticket, matour);
                    if (vt != -1 && vtveh != -1 && vtho != -1 && vtland != -1 && vttic == -1)
                    {   
                        string str = "DELETE FROM [DBO].[Diemthamquan] WHERE Madtq = N'"+arrLand[vtland].GetMadtq()+"'";
                        char m[Max];
                        strcpy(m,str.c_str());
                        cout << m;
                        system("pause");
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nDELETE SUCCESS 1\n";
                        }
                        SQLCancel(sqlStmtHandle);
                        for (int c = vtland; c < land - 1; c++)
                        {
                            arrLand[c] = arrLand[c + 1];
                        }
                        dem3++;
                        land--;
                        string str1 = "DELETE FROM [DBO].[Phuongtien] WHERE Mapt = N'"+arrVehice[vtveh].GetMaphuongtien()+"'";
                        char m1[Max];
                        strcpy(m1,str1.c_str());
                        cout << m1;
                        system("pause");
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m1, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nDELETE SUCCESS 2\n";
                        }
                        SQLCancel(sqlStmtHandle);
                        for (int z = vtveh; z < veh - 1; z++)
                        {
                            arrVehice[z] = arrVehice[z + 1];
                        }
                        dem2++;
                        veh--;
                        string str2 = "DELETE FROM [DBO].[Khachsan] WHERE Maks = N'"+arrHo[vtho].GetMakhachsan()+"'";
                        char m2[Max];
                        strcpy(m2,str2.c_str());
                        cout << m2;
                        system("pause");
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m2, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nDELETE SUCCESS 3\n";
                        }
                        SQLCancel(sqlStmtHandle);
                        for (int j = vtho; j < ho - 1; j++)
                        {
                            arrHo[j] = arrHo[j + 1];
                        }
                        dem1++;
                        ho--;
                        string str3 = "DELETE FROM [DBO].[Tour] WHERE Matour = N'"+arrTour[vt].GetMatour()+"'";
                        char m3[Max];
                        strcpy(m3,str3.c_str());
                        cout << m3;
                        system("pause");
                        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLTCHAR*)m3, SQL_NTS))
                        {
                            cout << "\n";
                            cout << "Error querying SQL Server";
                            cout << "\n";
                            DBClose();
                        }
                        else 
                        {
                            cout << "\nDELETE SUCCESS 4\n";
                        }
                        SQLCancel(sqlStmtHandle);
                        for (int i = vt; i < index - 1; i++)
                        {
                            arrTour[i] = arrTour[i + 1];
                        }
                        dem++;
                        index--;
                        cout << "\n Da Xoa Du Lieu ";
                    }
                    else
                    {
                        cout << "Khong co Matour phu hop voi gia tri ban muon xoa hay la co khach hang ton tai da dat tour";
                    }
                    cout << endl;
                    system("pause");
                }
                break;
                case 5:
                {
                    system("cls");
                    cout << "\t\t\t\t\t\t\t\t Danh sach khach hang da dang ky Tour \n\n\n";
                    cout << setw(20) << "Makhachhang" << setw(25) << "Tenkhachhang" << setw(25) << "DiaChi" << setw(25) << "SDT" << setw(20) << "Matour" << setw(20) << "SoLuongVe" << endl;
                    for (int i = 0; i < cus; i++)
                    {
                        for (int j = 0; j < reg; j++)
                        {
                            if (arrCus[i].GetMakhachhang() == arrReg[j].GetMakhachhang())
                                cout << arrCus[i] << setw(20) << arrReg[j].GetMatour() << setw(20) << arrReg[j].GetSoluongve() << endl;
                        }
                    }
                    system("pause");
                }
                break;
                case 0:
                    goto tryagain;
                    break;
                }
            } while (ql != 0);
        }
        break;
        case 0:
            DBClose();
            break;
        }
    } while (x != 0);
}
