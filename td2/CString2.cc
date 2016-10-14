using namespace std;

#include <iostream>
#include <string.h>

class CString
{
	private:
		char *s;
		int size;
		static int nbrChaines;
	
	public:
		CString();
		CString(const char *chaine);
		CString(const char c);
		~CString();
		static int nbrChaine(){ return CString::nbrChaines; }
		const char* getString();
		char getChar(int i);
		int getSize();
		CString& operator=(const CString mot);
		bool operator>=(CString mot);
		bool operator<(CString mot);
		CString operator+(CString mot);
		CString plusGrand(CString s);
};

int CString::nbrChaines = 0;
CString::CString()
{
	size = 0;
	s = new char[1];
	s[0] = '\0';
	nbrChaines++;
}

CString::CString(const char *chaine)
{
	size = strlen(chaine);
	s = new char[size + 1];
	strcpy(this->s, chaine);
	nbrChaines++;
}

CString::CString(const char c)
{
	size = 1;
	s = new char[2];
	s[0] = c;
	s[1] = '\0';
	nbrChaines++;
}

const char* CString::getString(){ return s; }
int CString::getSize(){ return size; }
char CString::getChar(int i){ return s[i]; }

CString::~CString()
{
	cout << "destruction de la chaine " << s << endl;
	delete[] s;
	nbrChaines--;
}

CString& CString::operator=(CString mot)
{
	delete[] this->s;
	s = new char[mot.getSize() + 1];
	size = mot.getSize();
	
	strcpy(s, mot.getString());	
	return *this;
}

bool CString::operator>=(CString mot)
{
	return strcmp(this->getString(), mot.getString()) > 0;
}

bool CString::operator<(CString mot)
{
	return !(*this >= mot);
}

CString CString::operator+(CString mot)
{
	int taille = this->getSize() + mot.getSize() + 1;
	char *s2 = new char[taille];
	
	strcpy(s2, this->getString());
	strcat(s2, mot.getString());
	
	CString *CS2 = new CString(s2);
	return *CS2;
}

CString CString::plusGrand(CString chaine)
{
	if(*this >= chaine)
		return *this;
	return chaine;
}

int main()
{
	CString *s01 = new CString("toto");
	CString *s02 = new CString( 'q' );
	CString *s03 = new CString();
	
	CString& s1 = *s01;
	CString& s2 = *s02; 
	CString& s3 = *s03; 
	
	cout << "nbrChaines" << CString::nbrChaine() << endl;
	
	CString w( 'w' );
	s3 = s1 + w;
	cout << "s3=" << s3.getString() << endl;
	
	if(s1 >= s2)
		cout << "plus grand" << endl;
		
	if(s1 < s2)
		cout << "plus petit" << endl;
	
	s3 = s1.plusGrand(s2);
	cout << "s3=" << endl;
	
	delete s01;
	delete s02;
	delete s03;
	return 0;
}
