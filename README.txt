Pour compiler Dico.cc :
-> Supprimer ou commenter le main de CString
-> g++ -c CString.cc
-> g++ -c Dico.cc
-> g++ CString.o Dico.o