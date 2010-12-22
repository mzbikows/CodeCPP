#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
class decyzja { 

private:
string nazwisko;
int wynagr;
bool czyauto;
bool czychata;
bool czym;
bool czyprzelewa;
bool czykarta;
 
public:
decyzja() {nazwisko=""; wynagr=0; czyauto=false; czychata=false; czym=false; czyprzelewa=false; czykarta=false;}//k bez par

decyzja(string pnazwisko, int pwynagr, bool pczyauto, bool pczychata, bool pczym, bool pczyprzelewa, bool pczykarta) 
{nazwisko=pnazwisko; wynagr=pwynagr; czyauto=pczyauto; czychata=pczychata; czym=pczym; czyprzelewa=pczyprzelewa; czykarta=pczykarta;}//k par

void podejmij () {
int param=0;
  if (wynagr<1000) param=-10;
  if (wynagr>2000) param++;
  if (wynagr>4000) param++;
  if (czyauto=true) param++;
  if (czychata=true) param++;
  if (czym=true) param++;  
  if (czyprzelewa=true) param++;
  if (czykarta=true) param++;
  
  if (param>4)
  cout<<"Pan "<<nazwisko<<endl<<" otrzymal pozytttttttttttywna decyzje kredytowa :) "<<endl<<endl;
  else 
  cout<<"Pan "<<nazwisko<<endl<<" NIE otrzymal pozytywnej decyzji kredytowej :( "<<endl<<endl;
  };
}; //musi tu byc srednik!
int main()
{
decyzja klient1; //wywolujemy tu konstruktor ktory wczesniej byl zdefiniowany bez nawiasow bo nie bylo paramterow
klient1.podejmij();

decyzja klient2("Skoczynski",800,true,true,true,true,true);
klient2.podejmij();
                   
  system("Pause");
    return 0;
}
/*pola

imie
nazwisko
wynagrodzenie
czy ma auto
czy ma mieszkanie
plec(sprawdzanie na podstawie fnkcji strcpy i ostatniej litery imienia czy jest a)
czy przelewa wynagrodzenie na konto w naszym banku
czy ma karte kredyt

metoda

dycyzja wymyslic wlasna regule*/
