#include <iostream>
#include <typeinfo>
#include "CString2.h"
#include <string.h>
using namespace std;

template<class T>
class Pair
{
	private:
		T e1;
		T e2;
	public:
		Pair(T a, T b) : e1(a), e2(b){
			if((strcmp(typeid(T).name(),"f") == 0) || (strcmp(typeid(T).name(),"i")==0))
			{
				this->e1 = a ;
				this->e2 = b;
			}
			else {
				cout << "erreur " << endl ;
				e1 = (int)a;
				e2 = (int)b;
				
				
				
				}}
		~Pair(){} 
		T getMax(){
		if (e1 > e2)
			{return e1 ;}
		else return e2;
}
};



int main(){
int i=5, j=6;
float l=10.0, m=5.0;
Pair<int> myInts (i,j);
Pair<float> myFloats (l,m);
cout << myInts.getMax()<< endl; //affiche le plus grand des 2 entiers
cout << myFloats.getMax()<<endl; //affiche le plus grand des 2 flottants
char c1='c', c2='d';
Pair<char> myChars(c1,c2); //creer un objet qui contient une paire d’entiers
cout << myChars.getMax()<< endl;
return 0 ;
}
