#include "Vehice.h"

Vehice::Vehice()
{
    this->Matour = Matour;
    this->Maphuongtien = Maphuongtien;
    this->Tenphuongtien = Tenphuongtien;
    this->Loaiphuongtien = Loaiphuongtien;
    this->Socho = Socho;
}
Vehice::Vehice(string matour, string maphuongtien, string tenphuongtien, string loaiphuongtien, int socho)
: Matour(matour), Maphuongtien(maphuongtien), Tenphuongtien(tenphuongtien), Loaiphuongtien(loaiphuongtien), Socho(socho)
{
}
Vehice::~Vehice()
{
}
void Vehice::Get()
{   
    // cout << "NhapMaphuongtien: ";
    // fflush(stdin);
    // getline(cin, Maphuongtien);
    cout << "NhapTenphuongtien: ";
    fflush(stdin);
    getline(cin, Tenphuongtien);
    cout << "NhapLoaiphuongtien: ";
    fflush(stdin);
    getline(cin, Loaiphuongtien);
    cout << "NhapSoCho: ";
    cin >> Socho;
    while(cin.fail())
    {
        cout << "Chua chinh xac kieu du lieu !!! ";
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Nhaplaisocho: ";
        cin >> Socho;
    }
    cout << endl;
}
void Vehice::Show()
{
    cout << setw(20) << Maphuongtien << setw(20) << Tenphuongtien << setw(20) << Loaiphuongtien << setw(20) << Socho << setw(20) << Matour << endl;
}
void Vehice::SetMaphuongtien(string maphuongtien)
{
    this->Maphuongtien = maphuongtien;
}
void Vehice::SetTenphuongtien(string tenphuongtien)
{
    this->Tenphuongtien = tenphuongtien;
}
void Vehice::SetLoaiphuongtien(string loaiphuongtien)
{
    this->Loaiphuongtien = loaiphuongtien;
}
void Vehice::SetSocho(int socho)
{
    this->Socho = socho;
}
void Vehice::SetMatour(string matour)
{
    this->Matour = matour;
}
string Vehice::GetMatour()
{
    return this->Matour;
}
string Vehice::GetMaphuongtien()
{
    return this->Maphuongtien;
}
string Vehice::GetTenphuongtien()
{
    return this->Tenphuongtien;
}
string Vehice::GetLoaiphuongtien()
{
    return this->Loaiphuongtien;
}
int Vehice::GetSocho()
{
    return this->Socho;
}