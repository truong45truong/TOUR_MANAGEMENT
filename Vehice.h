#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Vehice
{
private:
    string Matour;
    string Maphuongtien;
    string Tenphuongtien;
    string Loaiphuongtien;
    int Socho;

public:
    Vehice();
    Vehice(string, string, string, string, int);
    ~Vehice();
    void Get();
    void Show();
    void SetMaphuongtien(string);
    void SetTenphuongtien(string);
    void SetLoaiphuongtien(string);
    void SetSocho(int);
    void SetMatour(string);
    string GetMatour();
    string GetMaphuongtien();
    string GetTenphuongtien();
    string GetLoaiphuongtien();
    int GetSocho();
};
