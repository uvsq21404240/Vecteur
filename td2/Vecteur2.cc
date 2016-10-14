using namespace std;

#include <iostream>

class Noeud
{
	private:
		int val;
		Noeud *nextNoeud;
	
	public:
	Noeud(int valeur);
	~Noeud();
	int getVal();
	Noeud* getNext();
	void setNext(Noeud *next);
};

Noeud::Noeud(int valeur)
{
	val = valeur;
	nextNoeud = NULL;
}


Noeud::~Noeud()
{
	if(nextNoeud != NULL)
	{
		cout << val << ' ';
		delete nextNoeud;
	}
	else
	{
		cout << val<< " fin destruction" << endl;
	}
}

int Noeud::getVal(){ return val; }
Noeud* Noeud::getNext(){ return nextNoeud; }
void Noeud::setNext(Noeud *next){ nextNoeud = next; }

class Liste
{
	private:
		Noeud *tete;
		int taille;
		
	public:
		Liste();
		Liste(const Liste& v);
		~Liste();
		Noeud* getTete() const;
		int getTaille() const;
		void ajoutNoeud(Noeud n);
};

Liste::Liste()
{
	tete = new Noeud(0);
	taille = 1;
}

Noeud* Liste::getTete() const{ return tete; }
int Liste::getTaille() const{ return taille; }

Liste::Liste(const Liste& l)
{
	if(l.getTete() != NULL)
	{
		Noeud *tete_tmp = l.getTete();
		taille = l.getTaille();

		Noeud *ptr = new Noeud(tete_tmp->getVal());
		tete_tmp = tete_tmp->getNext();
		tete = ptr;
		while(tete_tmp != NULL)
		{
			ptr->setNext(new Noeud(tete_tmp->getVal()));
			tete_tmp = tete_tmp->getNext();
			ptr = ptr->getNext();
		}
	}
	else
	{
		taille = 0;
		tete = NULL;
	}
}

Liste::~Liste()
{
	delete tete;
}

/* Liste::Liste(int nbreElt)
 * {
 * 		taille = nbreElt;
 * 		int i = taille;
 * 		tete = new Noeud(i);
 * 		Noeud *ptr = tete;
 * 		i--;
 * 		while(i > 0)
 * 		{
 * 			ptr->setNext(new Noeud(i));
 * 			ptr = ptr->getNext();
 * 			i--;
 * 		}
 * }
 * */

int main()
{
	Liste *l1 = new Liste();
	Liste *l2 = new Liste(*l1);
	
	delete l1;
	delete l2;

	return 0;
}
