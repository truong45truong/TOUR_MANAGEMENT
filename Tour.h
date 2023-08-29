#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Tour
{
private:
    string Matour;
    string Tentour;
    string NgayBD;
    string NgayKT;
    int Gia;

public:
    Tour();
    Tour(string, string, string, string, int);
    ~Tour();
    void Get();
    void Show();
    void SetMatour(string);
    void SetTentour(string);
    void SetNgayBD(string);
    void SetNgayKT(string);
    void SetGia(int);
    string GetMatour();
    string GetTentour();
    string GetNgayBD();
    string GetNgayKT();
    int GetGia();
    friend ostream &operator<<(ostream &, const Tour &);
};
