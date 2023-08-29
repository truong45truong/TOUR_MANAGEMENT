#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Registration
{
private:
    string Matour;
    string Makhachhang;
    int Soluongve;
    string Madangky;

public:
    Registration();
    Registration(string, string, int, string);
    ~Registration();
    void Get();
    void Show();
    void SetSoluongve(int);
    void SetMadangky(string);
    void SetMatour(string);
    void SetMakhachhang(string);
    int GetSoluongve();
    string GetMadangky();
    string GetMatour();
    string GetMakhachhang();
    friend ostream &operator<<(ostream &, const Registration &);
};
