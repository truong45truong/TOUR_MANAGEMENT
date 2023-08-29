#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Landscape
{
private:
    string Matour;
    string Makhachsan;
    string Madtq;
    string Tendtq;
    string DiadiemTQuan;

public:
    Landscape();
    Landscape(string, string, string, string, string);
    ~Landscape();
    void Get();
    void Show();
    void SetMadtq(string);
    void SetTendtq(string);
    void SetDiadiemTQuan(string);
    void SetMatour(string);
    void SetMakhachsan(string);
    string GetMatour();
    string GetMadtq();
    string GetTendtq();
    string GetDiadiemTQuan();
    string GetMakhachsan();
    //friend ostream& operator<<(ostream& , const Landscape&);
};