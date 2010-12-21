#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Person
{
 char* name;

 public:
 friend class Couple;
 /********************************************************/
 friend ostream& operator<<(ostream& str, const Person& os)
 {
  cout << "Person: " << os.name << "\n";
 }
 
 /*******************************************/
 Person()
 {
  name = NULL;
 }
 /*******************************************/
 Person(const char* n)
 {
  /* Jak dluga jest tablica? */
  int licznik, licznik1;
  const char *glowicar;
  char* glowicaw;
  
  glowicar = n;
  licznik = 0;
  while( *glowicar != 0)
  {
   ++glowicar;
   ++licznik;
  }
  cout << "as = " <<(int) glowicar << endl;
  /* Kopiowanie. */
  glowicar = n;
  name = (char*)malloc( (licznik + 1)*sizeof(char) );
  glowicaw = name;
  for(licznik1 = 0; licznik1 < licznik + 1; ++licznik1)
  {
   *glowicaw = (char)(*glowicar);
   ++glowicaw;
   ++glowicar;
  }
  
  /* Wydruk testowy. */
  cout << "Person : " << name << "\n";
 }


 /*******************************************/
 Person(const Person& os)
 {

  /* Jak dluga jest tablica? */
  int licznik, licznik1;
  char *glowicar;
  char* glowicaw;
  
  glowicar = os.name;
  licznik = 0;
  while( *glowicar != 0)
  {
   ++glowicar;
   ++licznik;
  }
  
  /* Kopiowanie. */
  glowicar = os.name;
  name = (char*)malloc( (licznik + 1)*sizeof(char) );
  glowicaw = name;
  for(licznik1 = 0; licznik1 < licznik + 1; ++licznik1)
  {
   *glowicaw = (char)(*glowicar);
   ++glowicaw;
   ++glowicar;
  }
  
  /* Wydruk testowy. */
  cout << "Person : " << name << "\n";
 }
 /*************************************/
 Person& operator=(const Person& os)
 {
  
  /* Jak dluga jest tablica? */
  int licznik, licznik1;
  char *glowicar;
  char* glowicaw;
  
  glowicar = os.name;
  licznik = 0;
  while( *glowicar != 0)
  {
   ++glowicar;
   ++licznik;
  }
  
  /* Kopiowanie. */
  glowicar = os.name;
  free(this->name);
  this->name = (char*)malloc( (licznik + 1)*sizeof(char) );
  glowicaw = this->name;
  for(licznik1 = 0; licznik1 < licznik + 1; ++licznik1)
  {
   *glowicaw = (char)(*glowicar);
   ++glowicaw;
   ++glowicar;
  }
  
  /* Wydruk testowy. */
  cout << "Person : " << this->name << "\n";

  return *this;
 }
 /*************************************/
 /*************************************/
 ~Person()
 {
  free(name);
 }
};

class Couple
{
 Person *husb, *wife;

 public:
 friend ostream& operator<<(ostream& str, const Couple& p)
 {
  cout << "Husband: " << *(p.husb) << " & wife: " << *(p.wife) << "\n";
 }
 /***********************************/
 Couple(const char* m, const char* z)
 {
  husb = new Person(m);
  wife = new Person(z);

 }
 /*********************/ 
 Couple(const Couple& p)
 {
  husb = new Person(*(p.husb));
  wife = new Person(*(p.wife));
 }
 /********************************/
 Couple& operator=(const Couple& p)
 {
  free(this->husb->name);
  free(this->wife->name);
  free(this->husb);
  free(this->wife);
  
  this->husb = new Person(*(p.husb));
  this->wife = new Person(*(p.wife));
  
  return *this;
  
 }
 /*******/
 ~Couple()
 {
  free(husb->name);
  free(wife->name);
  free(husb);
  free(wife);
 }
};

int main(void)
{
 Couple *c1 = new Couple("John","Sue");
 Couple c2("Bert","Elsa");
 *c1 = c2;
 Couple c3(*c1);
 delete c1;
 cout << c3 << endl;


 //Person p1("DUPA1");
 //Person p2("DUPA2"); 
 //p1 = p2;
 //cout << p1;
 
}
