#include <iostream>
#include <cstdlib>

using namespace std;

/***************************************/

enum Banks {PKO, BGZ, BRE, BPH};

/***************************************/

struct Account
{
 Banks bank;
 int balance;
};

struct Person
{
 char name[20];
 Account account;
};

struct Couple
{
 Person he;
 Person she;
};

/***************************************/
void WypiszTabliceChar(char *tablica, int size)
{
 int licznik;
 
 cout << "\n";
 for(licznik = 0; licznik < size; ++licznik)
 {
  cout << "Pozycja #" << licznik
       << " : " << tablica[licznik]
       << " : " << (int)tablica[licznik]
       << "\n";
 }
}
/***************************************/
void WypiszPare(Couple* para)
{
 cout << (para->he).name << " & "
      << (para->she).name << " : "
      << (para->he).account.balance + (para->she).account.balance << "\n";
}
/***************************************/

Couple* bestClient(Couple* cpls, int size, Banks bank)
{
 int licznik;
 int findstatus, licznikmax, sumamax;

 findstatus = 0; 
 for(licznik = 0; licznik < size; ++licznik)
 {
  if( (cpls[licznik].he.account.bank == bank) || (cpls[licznik].she.account.bank == bank) )
  {
   if(findstatus == 0)
   {
    licznikmax = licznik;
    sumamax = cpls[licznik].he.account.balance + cpls[licznik].she.account.balance;
    findstatus = 1;
   }
   else if ((findstatus == 1) && (sumamax < cpls[licznik].he.account.balance + cpls[licznik].she.account.balance) )
   {
    licznikmax = licznik;
    sumamax = cpls[licznik].he.account.balance + cpls[licznik].she.account.balance;
   }
   
  }
 }
 
 //cout << "Wynik z wewnatrz : " << cpls[licznikmax].he.account.balance << "\n";
 
 if(findstatus == 0)
 {
  return NULL;
 }
 else
 {
  return (&(cpls[licznikmax]));
 }
}

/***************************************/
int main()
{
 Couple cpls[4];
 Couple *wynik;
 
 cpls[0].he.name[0] = 'J';
 cpls[0].he.name[1] = 'o';
 cpls[0].he.name[2] = 'h';
 cpls[0].he.name[3] = 'n';
 cpls[0].he.name[4] = 'y';
 cpls[0].he.name[5] = NULL;
 cpls[0].he.account.bank = PKO;
 cpls[0].he.account.balance = 1100;
 
 cpls[0].she.name[0] = 'M';
 cpls[0].she.name[1] = 'a';
 cpls[0].she.name[2] = 'r';
 cpls[0].she.name[3] = 'y';
 cpls[0].she.name[4] = NULL;
 cpls[0].she.account.bank = BGZ;
 cpls[0].she.account.balance = 1500;

 cpls[1].he.name[0] = 'P';
 cpls[1].he.name[1] = 'e';
 cpls[1].he.name[2] = 't';
 cpls[1].he.name[3] = 'e';
 cpls[1].he.name[4] = 'r';
 cpls[1].he.name[5] = NULL;
 cpls[1].he.account.bank = BGZ;
 cpls[1].he.account.balance = 1400;
 
 cpls[1].she.name[0] = 'S';
 cpls[1].she.name[1] = 'u';
 cpls[1].she.name[2] = 'z';
 cpls[1].she.name[3] = 'y';
 cpls[1].she.name[4] = NULL;
 cpls[1].she.account.bank = BRE;
 cpls[1].she.account.balance = 1300;

 cpls[2].he.name[0] = 'K';
 cpls[2].he.name[1] = 'e';
 cpls[2].he.name[2] = 'v';
 cpls[2].he.name[3] = 'i';
 cpls[2].he.name[4] = 'n';
 cpls[2].he.name[5] = NULL;
 cpls[2].he.account.bank = PKO;
 cpls[2].he.account.balance = 1600;
 
 cpls[2].she.name[0] = 'K';
 cpls[2].she.name[1] = 'a';
 cpls[2].she.name[2] = 't';
 cpls[2].she.name[3] = 'y';
 cpls[2].she.name[4] = NULL;
 cpls[2].she.account.bank = BPH;
 cpls[2].she.account.balance = 1500;

 cpls[3].he.name[0] = 'K';
 cpls[3].he.name[1] = 'e';
 cpls[3].he.name[2] = 'n';
 cpls[3].he.name[3] = 'n';
 cpls[3].he.name[4] = 'y';
 cpls[3].he.name[5] = NULL;
 cpls[3].he.account.bank = BPH;
 cpls[3].he.account.balance = 1800;
 
 cpls[3].she.name[0] = 'L';
 cpls[3].she.name[1] = 'u';
 cpls[3].she.name[2] = 'c';
 cpls[3].she.name[3] = 'y';
 cpls[3].she.name[4] = NULL;
 cpls[3].she.account.bank = BRE;
 cpls[3].she.account.balance = 1700;

 wynik = bestClient(cpls, 4, BGZ);
 WypiszPare(wynik);

 //cout << "Wynik z zewnatrz " << (wynik->he).account.balance << "\n";
 //WypiszTabliceChar(wynik->she.name, 20);
 
 
 //system("pause");
}
