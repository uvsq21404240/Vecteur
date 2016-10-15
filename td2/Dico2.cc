#include "CString2.h"

using namespace std;

//classe composée
class Definition
{
	private:
		CString clef;
		CString def;
		
	public:
		Definition(const char *c1, const char *c2);
		~Definition();
		CString getClef();
		CString getDef();
		Definition& operator=(const Definition& d); //a coder
};

//Utilisation implicite des constructeurs de CString
Definition::Definition(const char *c1, const char *c2): clef(c1), def(c2){}
Definition::~Definition(){}
CString Definition::getClef(){return clef;}
CString Definition::getDef(){return def;}


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
		void setMot(); //redef operateur = pour classe definition
		void setNext();
		Noeud& operator=(const Noeud& nd);
};

Definition Noeud::getMot() const{ return mot; }
Noeud* Noeud::getNext() const{ return nextNoeud; }
void Noeud::setMot(Definition mot2){ mot = mot2; } 
void Noeud::setNext(Noeud *next){ nextNoeud = next; }

//liste chainee, triee de definitions (dans l'ordre alphabetique des clefs)
class Dictionnaire
{
	private:
		Noeud *tete;
		int taille;
		
	public:
		Dictionnaire();
		Dictionnaire(const Dictionnaire& dico):
		~Dictionnaire();
		int getTaille() const;
		int getTete() const;
		Dictionnaire& operator=(const Dictionnaire& dico);
		Dictionnaire& operator+=(const Definition& def);
		bool recherche(Definition def);
		void affiche(Definition def);
};

int Dictionnaire::getTaille() const{ return taille; }
int Dictionnaire::getTete() const{ return tete; }

int main()
{
	return 0;
}
