#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Customer
{
protected:
    string Makhachhang;
    string Tenkhachhang;
    string Diachi;
    int SDT;

public:
    Customer();
    Customer(string, string, string, int);
    ~Customer();
    void Get();
    virtual void Show();
    void SetMakhachhang(string);
    void SetTenkhachhang(string);
    void SetDiachi(string);
    void SetSDT(int);
    string GetMakhachhang();
    string GetTenkhachhang();
    string GetDiachi();
    int GetSDT();
    friend ostream &operator<<(ostream &, const Customer &);
};
