#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

class lokata { 
private:
string imie;        
string nazwisko;
int kwotalok;
int ildni;

public:
lokata() {imie=""; nazwisko=""; kwotalok=0; ildni=0;}//k bez par
//lokata(string pimie, string pnazwisko, int pkwotalok, int pildni) {imie=pimie; nazwisko=pnazwisko; kwotalok=pkwotalok; ildni=pildni;}
lokata(string pimie, string pnazwisko, int pkwotalok, int pildni) {imie=pimie; nazwisko=pnazwisko; kwotalok=pkwotalok; ildni=pildni;}//k par

void obliczodsetki () {
 float procent=0.06, odsetki=0;
  if (kwotalok>20000) procent=0.07;
  odsetki=kwotalok*ildni*procent;
  cout<<"Imie: "<<imie<<endl<<"Nazwisko: "<<nazwisko<<endl<<"Odsetki: "<<odsetki<<endl<<endl;  }
  };

int main()
{ //konstruktor dla danego obiektu wywolujemy tylko raz
lokata klient1; //wywolujemy tu konstruktor ktory wczesniej byl zdefiniowany bez nawiasow bo nie bylo paramterow
klient1.obliczodsetki();

lokata klient2("Adammmmmmmmmmmmmmmmm","Skoczynski",20000,2);
klient2.obliczodsetki();
                   
  system("Pause");
    return 0;
}

/*
/* projekt lokata 
   pola
imie
nazwisko
kwota lokaty
   metody
oblicz odsetki parametr ilosc dni
jesli ktos wplacil powyzej 20tys to 7% jezeli ponizej 20tys 6% 


// projekt decyzja kredytowa

pola

imie
nazwisko
wynagrodzenie
czy ma auto
czy ma mieszkanie
plec(sprawdzanie na podstawie fnkcji strcpy i ostatniej litery imienia czy jest a)
czy przelewa wynagrodzenie na konto w naszym banku
czy ma karte kredyt

metoda

dycyzja wymyslic wlasna regule

// 
*/
