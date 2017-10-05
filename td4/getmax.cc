#include <iostream>
#include "CString2.h"
using namespace std;

template<class T>
T GetMax( T& a,  T& b)
{
	return (a > b) ? a : b;
}

int main(){
	int i=5, j=6, k;
	float l=10.0, m=5.0, n;
	
	k = GetMax(i, j); //retourne le plus grand entre i et j
	n = GetMax(l, m); //retourne le plus grand entre l et m
	cout << k << endl;
	cout << n << endl;

	CString s1("toto"), s2('s'), s3;
	s3 = GetMax(s1, s2); 
	cout << s3.getString() << endl;
	
cout << k << endl;
cout << n << endl;
return 0 ;
}

