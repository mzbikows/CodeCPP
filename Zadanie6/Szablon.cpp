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

}

int main()
{
	Couple cpls[]={
                  
                  };
	
    Couple *p = bestClient(cpls, 4, BGZ);
    
    //system("Pause");
	return 0;
}
