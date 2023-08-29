#include "Hotel.h"

Hotel::Hotel()
{   
    this->Matour = Matour;
    this->Makhachsan = Makhachsan;
    this->Tenkhachsan = Tenkhachsan;
    this->DiadiemKhachsan = DiadiemKhachsan;
}
Hotel::Hotel(string matour, string makhachsan, string tenkhachsan, string diadiemkhachsan)
:   Matour(matour), Makhachsan(makhachsan), Tenkhachsan(tenkhachsan), DiadiemKhachsan(diadiemkhachsan)
{
}
Hotel::~Hotel()
{
}
void Hotel::Get()
{   
    // cout << "NhapMakhachsan: ";
    // fflush(stdin);
    // getline(cin, Makhachsan);
    cout << "NhapTenkhachsan: ";
    fflush(stdin);
    getline(cin, Tenkhachsan);
    cout << "NhapDiadiemKS: ";
    fflush(stdin);
    getline(cin, DiadiemKhachsan);
    cout << endl;
}
void Hotel::Show()
{
    cout << setw(20) << Makhachsan << setw(20) << Tenkhachsan << setw(20) << DiadiemKhachsan << setw(20) << Matour << endl;
}
void Hotel::SetMakhachsan(string MaKhachsan)
{
    this->Makhachsan = MaKhachsan;
}
void Hotel::SetTenkhachsan(string Tenkhachsan)
{
    this->Tenkhachsan = Tenkhachsan;
}
void Hotel::SetDiadiemKS(string DiadiemKS)
{
    this->DiadiemKhachsan = DiadiemKS;
}
void Hotel::SetMatour(string matour)
{
    this->Matour = matour;
}
string Hotel::GetMaTour()
{
    return this->Matour;
}
string Hotel::GetMakhachsan()
{
    return this->Makhachsan;
}
string Hotel::GetTenkhachsan()
{
    return this->Tenkhachsan;
}
string Hotel::GetDiadiemKS()
{
    return this->DiadiemKhachsan;
}