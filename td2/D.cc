#include "CString2.h"
#include <iostream>

using namespace std;
//exo similaire a Vecteur2 : liste chainee
//classe composée
class Defition  
{
	public :
	int taille 
	
	
	
	
	private :
	
	
	
}


class Noeud
{
	private:
		Definition mot;
		Noeud *nextNoeud;
		
	public:
		Noeud(Definition def);
		Noeud(const Noeud& nd);
		~Noeud();
		Definition getMot() const;
		Noeud* getNext() const;
		void setMot(Definition mot2);
		void setNext(Noeud *next);
		Noeud& operator=(const Noeud& nd);
};

Noeud::Noeud(Definition def): mot(def){ nextNoeud = NULL; }
Noeud::Noeud(const Noeud& nd): mot(nd.getMot())
{	
	Noeud *tmp2 = nd.getNext();
	if(tmp2 == NULL)
		nextNoeud = NULL;
	else
	{
		nextNoeud = new Noeud(tmp2->getMot());
		Noeud *tmp = nextNoeud;
		
		tmp2 = tmp2->getNext();
		while(tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getMot()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
}

Noeud& Noeud::operator=(const Noeud& nd)
{
	mot = nd.getMot();
	
	if(nextNoeud != NULL)
		delete nextNoeud;
		
		
	Noeud *tmp2 = nd.getNext();
	if(tmp2 == NULL)
		nextNoeud = NULL;
	else
	{
		nextNoeud = new Noeud(tmp2->getMot());
		Noeud *tmp = nextNoeud;
		
		tmp2 = tmp2->getNext();
		while(tmp2 != NULL)
		{
			tmp->setNext(new Noeud(tmp2->getMot()));
			tmp = tmp->getNext();
			tmp2 = tmp2->getNext();
		}
	}
	return *this;
}

Noeud::~Noeud()
{
	if(nextNoeud != NULL)
	{
		delete nextNoeud;
	}
}

Definition Noeud::getMot() const{ return mot; }
Noeud* Noeud::getNext() const{ return nextNoeud; }
void Noeud::setMot(Definition mot2){ mot = mot2; } 
void Noeud::setNext(Noeud *next){ nextNoeud = next; }




