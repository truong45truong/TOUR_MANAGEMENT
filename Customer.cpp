#include "Customer.h"

Customer::Customer()
{
    this->Makhachhang = Makhachhang;
    this->Tenkhachhang = Tenkhachhang;
    this->Diachi = Diachi;
    this->SDT = SDT;
}
Customer::Customer(string makhachhang, string tenkhachhang, string diachi, int sdt)
    : Makhachhang(makhachhang), Tenkhachhang(tenkhachhang), Diachi(diachi), SDT(sdt)
{}
Customer::~Customer()
{
}
void Customer::Get()
{
    // cout << "Nhap Makhachhang: ";
    // fflush(stdin);
    // getline(cin, this->Makhachhang);
    cout << "Nhap Tenkhachhang: ";
    fflush(stdin);
    getline(cin, this->Tenkhachhang);
    cout << "Nhap Diachi: ";
    fflush(stdin);
    getline(cin, this->Diachi);
    cout << "Nhap SDT: ";
    cin >> this->SDT;
    while(cin.fail())
    {
        cout << "Nhap sai kieu du lieu !!! ";
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Nhap lai SDT: ";
        cin >> SDT;
    }
    cout << endl;
}
void Customer::Show()
{
    cout << setw(20) << Makhachhang << setw(25) << Tenkhachhang << setw(25) << Diachi << setw(20) << "(+84)" << SDT << endl;
}
void Customer::SetMakhachhang(string Makhachhang)
{
    this->Makhachhang = Makhachhang;
}
void Customer::SetTenkhachhang(string Tenkhachhang)
{
    this->Tenkhachhang = Tenkhachhang;
}
void Customer::SetDiachi(string Diachi)
{
    this->Diachi = Diachi;
}
void Customer::SetSDT(int SDT)
{
    this->SDT = SDT;
}
string Customer::GetMakhachhang()
{
    return Makhachhang;
}
string Customer::GetTenkhachhang()
{
    return Tenkhachhang;
}
string Customer::GetDiachi()
{
    return Diachi;
}
int Customer::GetSDT()
{
    return SDT;
}
ostream &operator<<(ostream &o, const Customer &c)
{
    o << setw(20) << c.Makhachhang << setw(25) << c.Tenkhachhang << setw(25) << c.Diachi << setw(20) << "(+84)"<< c.SDT;
    return o;
}
