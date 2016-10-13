using namespace std;

#include <iostream>

void tableauEcriture(int *tab, int taille)
{
	int i;
	
	for(i = 0; i < taille; i++)
	{
		tab[i] = i;
	}
}

void tableauLecture(const int *tab, int taille)
{
	int i;
	
	for(i = 0; i < taille; i++)
	{
		cout << tab[i] << "\n";
	}
}
/* On peut récupérer la taille
 * avec un sizeof sinon (sizeof tab / sizeof int)
 * */
int main()
{
	int tab[10];
	
	tableauEcriture(tab, 10);
	tableauLecture(tab, 10);
	
}
