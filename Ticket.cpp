#include "Ticket.h"

Ticket::Ticket()
{
  this->Mave = Mave;
  this->Tenve = Tenve;
  this->Matour = Matour;
  this->Makhachhang = Makhachhang;
}
Ticket::Ticket(string mave, string tenve, string matour, string makhachhang)
: Mave(mave), Tenve(tenve), Matour(matour), Makhachhang(makhachhang)
{
}
Ticket::~Ticket()
{
}
void Ticket::SetMatour(string matour)
{
  this->Matour = matour;
}
void Ticket::SetTenve(string tenve)
{
  this->Tenve = tenve;
}
void Ticket::SetMakhachhang(string makhachhang)
{
  this->Makhachhang = makhachhang;
}
void Ticket::SetMave(string mave)
{
  this->Mave = mave;
}
string Ticket::GetMatour()
{
  return this->Matour;
}
string Ticket::GetMave()
{
  return this->Mave;
}
string Ticket::GetTenve()
{
  return this->Tenve;
}
string Ticket::GetMakhachhang()
{
  return this->Makhachhang;
}
ostream &operator<<(ostream &o, const Ticket &ti)
{
  o << "Mave: " << ti.Mave << endl
    << "Tenve: " << ti.Tenve << endl
    << "Matour" << ti.Matour << endl
    << "Makhachhang" << ti.Makhachhang << endl;
  return o;
}