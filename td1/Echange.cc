using namespace std;

#include <iostream>

void echange(int &a, int &b)
{
	int c = a; 
	c = a;
	a = b;
	b = c;
}

/* 3 types de passage en argument aux fonctions
 * valeur 		-> C C++ Java
 * adresse		-> C C++
 * reference		->   C++ Java (que les objets pour java) 
 * */

int main()
{
	int obj1 = 1;
	int obj2 = 3;
	
	cout << obj1 << obj2 << "\n";
	
	echange(obj1, obj2);
	
	cout << obj1 << obj2 << "\n";
}
