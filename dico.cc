class Definition
{
	private:
		CString Clef;
		CString Def;
	public:
		Definition(char *c1, char *c2);
		~Definition();
		CString getClef();
		CString getDef();
};

Definition::Definition(char *c1, char *c2): Clef(c1), Def(c2){}
Definition::~Definition(){}
CString Definition::getClef(){return Clef;}
CString Definition::getDef(){return Def;}

int main()
{
	Definition homer("Homer", "Buveur de biere");
	cout << "la definition du mot " << homer.getClef() << " est " << homer.getDef() << endl;
}
