//Mariusz Zbikowski
#include <iostream>
#include <cstring>
#include <cstdlib> //free && mallock w cstdlib
//las
using namespace std;


class Person {
      char* name;     //private
      
      public:
      
      friend class Couple;   
      
      friend ostream& operator<<(ostream& str, const Person& os)
      {
      str<<os.name;
      };
      
      Person(const char* n)
      {
       name = (char*)n; 
       cout<<"konstr1   "<<name<<endl;                  
      };
      
      Person(const Person& os)
      {
      name = os.name;
      cout<<"konstr 2 "<<name<<endl;
      };
      
      Person& operator=(const Person& os)
      {
      this->name = os.name;        
      return *this;   //this to wskaznik na aktualny obiekt
      };
      
       ~Person()
       {
       free(name); //funkcja zwalniajaca pamiec               
       cout<<"destr"<<endl;
       };

       char* getName(){
       return name;
       };

};

class Couple {

      Person *husb, *wife;
      
      public:
      
      friend ostream& operator<<(ostream& str, const Couple& p)
      {
      str<<"He: "<<*p.husb<<", She: "<<*p.wife;       
      };
      
      Couple(const char* m, const char* z)
      {
      husb = new Person(m);
      wife = new Person(z);    
      cout<<"coup1"<<endl;         
      };
      
      Couple(const Couple& p)
      {
      husb = new Person(*p.husb);
      wife = new Person(*p.wife);
       cout<<"coup2"<<endl;
      };
      
      Couple& operator=(const Couple& p)
      {
      this->husb = new Person(*p.husb);
      this->wife = new Person(*p.wife);
      return *this;
      };
     
     
     ~Couple()
     {
     free(husb->name);
     free(wife->name);
     free(husb);
     free(wife);         
     };

};

int main(void) {


Couple *c1 = new Couple("John","Sue");
Couple c2("Bert","Elsa");
*c1 = c2;
Couple c3(*c1);
delete c1;
cout << c3 << endl;


/*
Person person1("naaapis");
Person person2(person1);
Person person3("Waldek");

cout<<person1<<" "<<person2<<endl;

person1 = person3;

cout<<person1<<endl;

Couple c2("Bert","Elsa");
Couple c3(c2);
Couple c4("Benny","Ann");
c3 = c4;
cout<<c3<<endl;
*/




//system("PAUSE");
return 0;

}

