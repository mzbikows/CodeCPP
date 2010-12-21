#include <iostream>
#include <cstdlib>

using namespace std;

/***************************************/

enum Banks {PKO, BGZ, BRE, BPH, ING};

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

Couple* bestClient(Couple* cpls, int size, Banks bank)
{
	int counter_max;
	int max_balance;
	bool mark;//domyslnie mark=false
	
if (size == 0) return NULL;
else
{		
	for(int counter = 0; counter < size; ++counter)
	{
		if( (cpls[counter].he.account.bank == bank) || (cpls[counter].she.account.bank == bank) )
		{
			if(mark==0)//za pierwszym razem
			{
				counter_max=counter;
				max_balance=cpls[counter].he.account.balance + cpls[counter].she.account.balance;
				
			}
			//za kazdym nastepnym razem
			if((mark !=0) && (max_balance<cpls[counter].he.account.balance + cpls[counter].she.account.balance))
			{
				counter_max = counter;
				max_balance = cpls[counter].he.account.balance + cpls[counter].she.account.balance;
			}
			mark = 1; 
		}	
	}
	
	if(mark==0)
	{
		return NULL;
	}
	else
	{
		return (&cpls[counter_max]);
	}
}
}

void ShowCouple(Couple* p)
{
    if (p == NULL)
    { 
          cout << "Zadana osoba z par nie ma konta w podanym banku" << endl;
    }
    else
    {
          cout << p->he.name  << " and " << p->she.name << " : " << p->he.account.balance + p->she.account.balance << endl;
    }
}

int main()
{
	Couple cpls[]={ {{"Johny",{PKO,1100}},{"Mary",{BGZ,1500} }},
                    {{"Peter",{BGZ,1400}},{"Suzy",{BRE,1300} }},
                    {{"Kevin",{PKO,1600}},{"Katy",{BPH,1500} }},
                    {{"Johny",{BPH,1800}},{"Mary",{BRE,1700} }}
                  };

	Couple *p = bestClient(cpls, 4, BGZ);
    	ShowCouple(p);
       	p = bestClient(cpls, 4, ING);
    	ShowCouple(p);
 
	//system("pause");
	return 0;
}
