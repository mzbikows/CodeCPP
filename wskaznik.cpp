#include <iostream>
using namespace std;
 
 int main ()
 {
   int liczba = 80;
   int *wskaznik = &liczba;
   
   cout << liczba << " jjjj" << &liczba << endl;
   cout << wskaznik << " " << *wskaznik << endl;
 
   *wskaznik = 42;
   cout << liczba << " " << *wskaznik << endl;
   
   liczba =32;
   cout << liczba << " " << *wskaznik << endl;
   
   liczba =0x30;
   cout << liczba << " " << *wskaznik << endl;
	
   //system("Pause");
   return 0;
 }
