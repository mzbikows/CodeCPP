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

Couple* bestClient(Couple* cpls, int size, Banks bank)
{
	int counter_max;
	int max_balance;
	bool mark;
	
if (size == 0) return NULL;
else
{		
	for(int counter = 0; counter < size; ++counter)
	{
		if( (cpls[counter].he.account.bank == bank) || (cpls[counter].she.account.bank == bank) )
		{
			if(mark==0)
			{
				counter_max=counter;
				max_balance=cpls[counter].he.account.balance + cpls[counter].she.account.balance;
				mark = 1;
			}
			if((mark == 1) && (max_balance<cpls[counter].he.account.balance + cpls[counter].she.account.balance))
			{
				counter_max = counter;
				max_balance = cpls[counter].he.account.balance + cpls[counter].she.account.balance;
			}
		}	
	}
	
	if(mark==0)
	{
		return NULL;
	}
	else
	{
		return (&(cpls[counter_max]));
	}
}

}
/***************************************/
void ShowCouple(Couple* p)
{
    if (p == NULL)
    { 
          cout << "Zadana osoba z par nie ma konta w podanym banku" << endl;
    }
    else
    {
          cout << (p->he).name  << " and " << (p->she).name 
               << " : " << (p->he).account.balance + (p->she).account.balance 
               << endl;
    }
}

int main()
{
	Couple cpls[4];
	Couple *p;
	
	/**************JOHNY********************/
	cpls[0].he.name[0] = 'J';
	cpls[0].he.name[1] = 'o';
	cpls[0].he.name[2] = 'h';
	cpls[0].he.name[3] = 'n';
	cpls[0].he.name[4] = 'y';
	cpls[0].he.name[5] = (char)NULL;
	cpls[0].he.account.bank = PKO;
	cpls[0].he.account.balance = 1100;
	/**************MARY********************/
	cpls[0].she.name[0] = 'M';
	cpls[0].she.name[1] = 'a';
	cpls[0].she.name[2] = 'r';
	cpls[0].she.name[3] = 'y';
	cpls[0].she.name[4] = (char)NULL;
	cpls[0].she.account.bank = BGZ;
	cpls[0].she.account.balance = 1500;
 /*--------------------------------------------*/	
	/**************PETER********************/
	cpls[1].he.name[0] = 'P';
	cpls[1].he.name[1] = 'e';
	cpls[1].he.name[2] = 't';
	cpls[1].he.name[3] = 'e';
	cpls[1].he.name[4] = 'r';
	cpls[1].he.name[5] =  (char) NULL;
	cpls[1].he.account.bank = BGZ;
	cpls[1].he.account.balance = 1400;
	/**************SUZY********************/
	cpls[1].she.name[0] = 'S';
	cpls[1].she.name[1] = 'u';
	cpls[1].she.name[2] = 'z';
	cpls[1].she.name[3] = 'y';
	cpls[1].she.name[4] =  (char) NULL;
	cpls[1].she.account.bank = BRE;
	cpls[1].she.account.balance = 1300;
 /*--------------------------------------------*/	
	/**************KEVIN********************/
	cpls[2].he.name[0] = 'K';
	cpls[2].he.name[1] = 'e';
	cpls[2].he.name[2] = 'v';
	cpls[2].he.name[3] = 'i';
	cpls[2].he.name[4] = 'n';
	cpls[2].he.name[5] = (char) NULL;
	cpls[2].he.account.bank = PKO;
	cpls[2].he.account.balance = 1600;
	/**************KATY********************/
	cpls[2].she.name[0] = 'K';
	cpls[2].she.name[1] = 'a';
	cpls[2].she.name[2] = 't';
	cpls[2].she.name[3] = 'y';
	cpls[2].she.name[4] = (char) NULL;
	cpls[2].she.account.bank = BPH;
	cpls[2].she.account.balance = 1500;
 /*--------------------------------------------*/	
	/**************KENNY********************/
	cpls[3].he.name[0] = 'K';
	cpls[3].he.name[1] = 'e';
	cpls[3].he.name[2] = 'n';
	cpls[3].he.name[3] = 'n';
	cpls[3].he.name[4] = 'y';
	cpls[3].he.name[5] = (char) NULL;
	cpls[3].he.account.bank = BPH;
	cpls[3].he.account.balance = 1800;
	/**************LUCY********************/
	cpls[3].she.name[0] = 'L';
	cpls[3].she.name[1] = 'u';
	cpls[3].she.name[2] = 'c';
	cpls[3].she.name[3] = 'y';
	cpls[3].she.name[4] = (char) NULL;
	cpls[3].she.account.bank = BRE;
	cpls[3].she.account.balance = 1700;
 /*--------------------------------------------*/
 
	p = bestClient(cpls, 4, BGZ);
    	ShowCouple(p);
 
	//system("pause");
	return 0;
}
