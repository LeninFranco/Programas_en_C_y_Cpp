#include <iostream>
#include <string>

using namespace std;

//No dejar espacios al final

int main(){
	string cadena;
	int contador = 0, i;
	cout<<"Escriba una frase: "; getline(cin,cadena);
	for(i=0;i<=cadena.length();i++){
		if(cadena[i] == ' ' && cadena[i+1] != ' '){
			contador += 1;
		}
		else if(cadena[i] != ' ' && i == cadena.length()){
			contador += 1;
		}
		else{
			continue;
		}
	}
	cout<<"La frase contine un total de "<<contador<<" palabras"<<endl;
	system("Pause");
}
