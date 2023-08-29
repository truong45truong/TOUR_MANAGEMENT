#include "Landscape.h"

Landscape::Landscape()
{   
    this->Matour = Matour;
    this->Makhachsan = Makhachsan;
    this->Madtq = Madtq;
    this->Tendtq = Tendtq;
    this->DiadiemTQuan = DiadiemTQuan;
}
Landscape::Landscape(string matour, string makhachsan, string madtq, string tendtq, string diadiemthamquan)
    : Matour(matour), Makhachsan(makhachsan), Madtq(madtq), Tendtq(tendtq), DiadiemTQuan(diadiemthamquan)
{ 
}
Landscape::~Landscape()
{
}
void Landscape::Get()
{   
    // cout << "NhapMadtq: ";
    // fflush(stdin);
    // getline(cin, Madtq);
    cout << "NhapTendtq: ";
    fflush(stdin);
    getline(cin, Tendtq);
    cout << "NhapDiadiemthamquan: ";
    fflush(stdin);
    getline(cin, DiadiemTQuan);
    cout << endl;
}
void Landscape::Show()
{
    cout << setw(20) << Madtq << setw(20) << Tendtq << setw(20) << DiadiemTQuan << setw(20) << Makhachsan << setw(20) << Matour << endl;
}
void Landscape::SetMadtq(string madtq)
{
    this->Madtq = madtq;
}
void Landscape::SetTendtq(string tendtq)
{
    this->Tendtq = tendtq;
}
void Landscape::SetDiadiemTQuan(string diadiemtq)
{
    this->DiadiemTQuan = diadiemtq;
}
void Landscape::SetMatour(string matour)
{
    this->Matour = matour;
}
void Landscape::SetMakhachsan(string makhachsan)
{
    this->Makhachsan = makhachsan;
}
string Landscape::GetMatour()
{
    return this->Matour;
}
string Landscape::GetMadtq()
{
    return this->Madtq;
}
string Landscape::GetTendtq()
{
    return this->Tendtq;
}
string Landscape::GetDiadiemTQuan()
{
    return this->DiadiemTQuan;
}
string Landscape::GetMakhachsan()
{
    return this->Makhachsan;
}