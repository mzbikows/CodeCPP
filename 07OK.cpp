#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Person 
{
	char* name;
public:
	friend class Couple;
	friend ostream& operator<<(ostream& str, const Person& os)
	{
		//str << "Person : " << os.name << endl;
		str << os.name;
	};

	Person(const char* n)
	{
		//name = (char*) n;
		
		/* Jak dluga jest tablica? */
		int licznik, licznik1;
		const char *glowicar;
		char* glowicaw;
  
		glowicar = n;
		cout << "n : " << n << endl;
		cout << "glowicar : " << glowicar << endl;
  
		licznik = 0;
		while( *glowicar != 0)
		{
			++glowicar;
			++licznik;
		}
		cout << "n : " << n << endl;
		cout << "glowicar : " << glowicar << endl;
  
		/* Kopiowanie. */
		glowicar = n;
		cout << "aa:" << (int)glowicar << endl;
		name = (char*)malloc( (licznik + 1)*sizeof(char) );
		glowicaw = name;

		for(licznik1 = 0; licznik1 < licznik + 1; ++licznik1)
		{
			*glowicaw = (char)(*glowicar);
			++glowicaw;
			++glowicar;
		}
		
		/* Wydruk testowy. */
		cout << "test : " << (int) name << endl ;
    };
	Person(const Person& os)
	{
		//name = os.name;
		
		/* Jak dluga jest tablica? */
		int licznik, licznik1;
		const char* glowicar;
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
		cout << "test2 : " << (int) name << endl ;
		
	};

	Person& operator=(const Person& os)
	{
        //free(this->name);    
		this->name=os.name;
		
		return *this;
	};
	
	~Person()
	{  
        //cout << "Desktruktor ~Person" << endl;     
		free(name);
	};
};

class Couple 
{
	Person *husb, *wife;
public:
	friend ostream& operator<<(ostream& str, const Couple& p)
	{
		str << "He: " << *p.husb << " , She: " << *p.wife << endl;
	};
	Couple(const char* m, const char* z)
	{
		husb = new Person(m);
		wife = new Person(z);
	};
	Couple(const Couple& p)
	{
		husb = new Person( *p.husb );
		wife = new Person( *p.wife );       
	};
	Couple& operator=(const Couple& p)
	{
		//free(this->husb->name);
		//free(this->wife->name);
		//free(this->husb);
		//free(this->wife);
  
		this->husb = new Person(*p.husb);
		this->wife = new Person(*p.wife);
  
		return *this;
	};
	~Couple()
	{
		//cout << "Desktruktor ~Couple" << endl;   
		free(husb->name);
		free(wife->name);
		
		free(husb);
		free(wife);
	};
};

int main(void) 
{	
	Person person1("Mariusz");
    Person person2(person1);
	
	cout << person1 << endl;
    cout << person2 << endl;
	
	Person *person_c1 = new Person("John");
	Person person_c2("Bert");
	*person_c1 = person_c2;
	Person person_c3(*person_c1);
	delete person_c1;
	cout << person_c3 << endl;
	
	Couple *c1 = new Couple("John","Sue");
	Couple c2("Bert","Elsa");
	*c1 = c2;
	Couple c3(*c1);
	delete c1;
	cout << c3 << endl; //He: Bert, She: Elsa

	//system("Pause");
	return 0;
}
