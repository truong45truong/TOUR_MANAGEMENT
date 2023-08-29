#include "Tour.h"

Tour::Tour()
{
    this->Matour = Matour;
    this->Tentour = Tentour;
    this->NgayBD = NgayBD;
    this->NgayKT = NgayKT;
    this->Gia = Gia;
}
Tour::Tour(string matour, string tentour, string ngaybd, string ngaykt, int gia)
    : Matour(matour), Tentour(tentour), NgayBD(ngaybd), NgayKT(ngaykt), Gia(gia)
{
}
Tour::~Tour()
{
}
void Tour::Get()
{
    // cout << "Nhap Matour: ";
    // fflush(stdin);
    // getline(cin, Matour);
    cout << "Nhap Tentour: ";
    fflush(stdin);
    getline(cin, Tentour);
    cout << "Nhap NgayBD (YYYY-MM-DD): ";
    fflush(stdin);
    getline(cin, NgayBD);
    for (int i = 0; i < (sizeof(NgayBD) / sizeof(string)); i++)
    {
        while (NgayBD[4] != '-' || NgayBD[7] != '-' || NgayBD[0] != '2' || NgayBD[1] != '0' || NgayBD[2] != '2' || NgayBD[3] > '5' || NgayBD[5] >= '2' || NgayBD[5] == '1' && NgayBD[6] >= '3' || NgayBD[8] >= '4' || NgayBD[8] == '3' && NgayBD[9] >= '2'|| NgayBD[5] == '0' && NgayBD[6] == '2' && NgayBD[8] == '3' || NgayBD[3] > '0' && NgayBD[3] <= '5'  && NgayBD[5] == '0' && NgayBD[6] == '2' && NgayBD[9] == '9' ||NgayBD[5] == '0' && NgayBD[6] == '4' && NgayBD[8] == '3' && NgayBD[9] >= '1'|| NgayBD[5] == '0' && NgayBD[6] == '6' && NgayBD[8] == '3' && NgayBD[9] >= '1'|| NgayBD[5] == '0' && NgayBD[6] == '9' && NgayBD[8] == '3' && NgayBD[9] >= '1'|| NgayBD[5] == '1' && NgayBD[6] == '1' && NgayBD[8] == '3' && NgayBD[9] >= '1')
        {
            cout << "Nhap sai kieu du lieu !!! ";
            cin.clear();
            cout << "Nhap lai NgayBD (YYYY-MM-DD): ";
            getline(cin, NgayBD);
        }
    }
    cout << "Nhap NgayKT (YYYY-MM-DD): ";
    fflush(stdin);
    getline(cin, NgayKT);
    for (int i = 0; i < (sizeof(NgayKT) / sizeof(string)); i++)
    {
        while (NgayKT[4] != '-' || NgayKT[7] != '-' || NgayKT[0] != '2' || NgayKT[1] != '0' || NgayKT[2] != '2' || NgayKT[3] > '5' || NgayKT[5] >= '2' || NgayKT[5] == '1' && NgayKT[6] >= '3' || NgayKT[8] >= '4' || NgayKT[8] == '3' && NgayKT[9] >= '2'|| NgayKT[5] == '0' && NgayKT[6] == '2' && NgayKT[8] == '3' || NgayKT[3] > '0' && NgayKT[3] <= '5' && NgayKT[5] == '0' && NgayKT[6] == '2' && NgayKT[9] == '9' || NgayKT[5] == '0' && NgayKT[6] == '4' && NgayKT[8] == '3' && NgayKT[9] >= '1'|| NgayKT[5] == '0' && NgayKT[6] == '6' && NgayKT[8] == '3' && NgayKT[9] >= '1'|| NgayKT[5] == '0' && NgayKT[6] == '9' && NgayKT[8] == '3' && NgayKT[9] >= '1'|| NgayKT[5] == '1' && NgayKT[6] == '1' && NgayKT[8] == '3' && NgayKT[9] >= '1')
        {
            cout << "Nhap sai kieu du lieu !!! ";
            cin.clear();
            cout << "Nhap lai NgayKT (YYYY-MM-DD): ";
            getline(cin, NgayKT);
        }
    }
    for (int i = 0; i < (sizeof(NgayBD) / sizeof(string)); i++)
    {
        for (int j = 0; j < (sizeof(NgayKT) / sizeof(string)); j++)
        {
            while ((int(NgayBD[0] + NgayBD[1] + NgayBD[2] + NgayBD[3]) == int(NgayKT[0]+ NgayKT[1]+ NgayKT[2]+ NgayKT[3])) && (int(NgayBD[5]+ NgayBD[6]) == int(NgayKT[5]+ NgayKT[6])) && (int(NgayBD[8]+ NgayBD[9]) > int(NgayKT[8]+ NgayKT[9])) || (int(NgayBD[0] + NgayBD[1] + NgayBD[2] + NgayBD[3]) == int(NgayKT[0]+ NgayKT[1]+ NgayKT[2]+ NgayKT[3])) && (int(NgayBD[5]+ NgayBD[6]) > int(NgayKT[5]+ NgayKT[6])) || int(NgayBD[0] + NgayBD[1] + NgayBD[2] + NgayBD[3]) > int(NgayKT[0]+ NgayKT[1]+ NgayKT[2]+ NgayKT[3]))
            {
                cout << "Nhap sai kieu du lieu !!! ";
                cin.clear();
                cout << "Nhap lai NgayKT (YYYY-MM-DD): ";
                getline(cin, NgayKT);
            }
        }
    }
    cout << "Nhap Giatour: ";
    cin >> Gia;
    while (cin.fail())
    {
        cout << "Nhap sai kieu du lieu !!! ";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Nhap lai Giatour: ";
        cin >> Gia;
    }
    cout << endl
         << endl;
}
void Tour::Show()
{
    cout << "\t" << setw(20) << Matour << setw(40) << Tentour << setw(30) << NgayBD << setw(20) << NgayKT << setw(20) << Gia << endl;
}
void Tour::SetMatour(string Matour)
{
    this->Matour = Matour;
}
void Tour::SetTentour(string Tentour)
{
    this->Tentour = Tentour;
}
void Tour::SetNgayBD(string NgayBD)
{
    this->NgayBD = NgayBD;
}
void Tour::SetNgayKT(string NgayKT)
{
    this->NgayKT = NgayKT;
}
void Tour::SetGia(int Gia)
{
    this->Gia = Gia;
}
string Tour::GetMatour()
{
    return this->Matour;
}
string Tour::GetTentour()
{
    return this->Tentour;
}
string Tour::GetNgayBD()
{
    return this->NgayBD;
}
string Tour::GetNgayKT()
{
    return this->NgayKT;
}
int Tour::GetGia()
{
    return this->Gia;
}
ostream &operator<<(ostream &o, const Tour& t)
{
    o << setw(20) << t.Matour << setw(40) << t.Tentour << setw(20) << t.NgayBD << setw(20) << t.NgayKT << setw(20) << t.Gia;
    return o;
}
