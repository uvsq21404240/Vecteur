using namespace std;

#include <iostream>
#include <cstring>

void q_a()
{
	int tab[10];
	int *p = tab;
	int i = 0;
	
	while(i < 10)
	{
		tab[i] = i;
		i++;
	}
	
	i = 0;
	while(i++ < 10)
	{
		cout << *p++ << "\n";
	}
}

void q_b()
{
	const char *tab[3] = {"truc", "machin", "chose"};
	
	int i = 0;
	char *ptr[3];
	while(i < 3)
	{
		ptr[i] = new char[strlen(tab[i]) + 1]; //pour caract de fin de chaine
		strcpy(ptr[i], tab[i]);
		cout << ptr[i] << "\n";
		i++;
	}
	
	i = 0;
	while(i < 3)
	{
		delete ptr[i];
		i++;
	}
}

int main()
{
	q_a();
	q_b();
}
