#include <iostream>
#include <string>
using namespace std;

class Ticket
{
private:
    string Matour;
    string Makhachhang;
    string Mave;
    string Tenve;
    
public:
    Ticket();
    Ticket(string, string, string, string);
    ~Ticket();
    void SetMatour(string);
    void SetMakhachhang(string);
    void SetMave(string);
    void SetTenve(string);
    string GetMatour();
    string GetMakhachhang();
    string GetMave();
    string GetTenve();
    friend ostream& operator<<(ostream&, const Ticket&);
};
