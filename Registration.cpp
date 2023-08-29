#include "Registration.h"

Registration::Registration()
{
    this->Matour = Matour;
    this->Makhachhang = Makhachhang;
    this->Soluongve = Soluongve;
    this->Madangky = Madangky;
}
Registration::Registration(string matour, string makhachhang, int soluongve, string madangky)
: Matour(matour), Makhachhang(makhachhang), Soluongve(soluongve), Madangky(madangky)
{
}
Registration::~Registration()
{
}
void Registration::Get()
{   
    cout << "NhapMakhachhang: ";
    fflush(stdin);
    getline(cin, Makhachhang);
    cout << "NhapSoluongve: ";
    cin >> Soluongve;
    cout << "NhapMadangky: ";
    fflush(stdin);
    getline(cin, Madangky);
}
void Registration::Show()
{
    cout << "Matour: " << this->Matour << endl
         << "Makhachhang: " << this->Makhachhang << endl
         << "Soluongve: " << this->Soluongve << endl;
}
void Registration::SetSoluongve(int soluongve)
{
    this->Soluongve = soluongve;
}
void Registration::SetMadangky(string madangky)
{
    this->Madangky = madangky;
}
void Registration::SetMatour(string matour)
{
    this->Matour = matour;
}
void Registration::SetMakhachhang(string makhachhang)
{
    this->Makhachhang = makhachhang;
}
int Registration::GetSoluongve()
{
    return this->Soluongve;
}
string Registration::GetMadangky()
{
    return this->Madangky;
}
string Registration::GetMatour()
{
    return this->Matour;
}
string Registration::GetMakhachhang()
{
    return this->Makhachhang;
}
ostream &operator<<(ostream &o, const Registration &r)
{
    o << setw(20) << r.Matour << setw(20) << r.Makhachhang << setw(20) << setw(20) << r.Soluongve << endl;
    return o;
}