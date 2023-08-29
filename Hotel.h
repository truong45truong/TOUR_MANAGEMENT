#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Hotel
{
private:
    string Matour;
    string Makhachsan;
    string Tenkhachsan;
    string DiadiemKhachsan;

public:
    Hotel();
    Hotel(string, string, string, string);
    ~Hotel();
    void Get();
    void Show();
    void SetMakhachsan(string);
    void SetTenkhachsan(string);
    void SetDiadiemKS(string);
    void SetMatour(string);
    string GetMaTour();
    string GetMakhachsan();
    string GetTenkhachsan();
    string GetDiadiemKS();
    //friend ostream& operator<<(ostream& , const Hotel&);
};
