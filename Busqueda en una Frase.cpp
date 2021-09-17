#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;


void Coincidencias(string P,string C){
	int pos=P.find(C,0);
	if(pos==-1){
		cout<<"No hay ninguna subcadena en '"<<P<<"' que coincida con '"<<C<<"'"<<endl;
	}
	else{
		cout<<"Posiciones donde se encuentra la subcadena '"<<C<<"' en '"<<P<<"'"<<endl;
		cout<<"{ "<<pos<<" ";
		while(true){
		pos=P.find(C,pos+1);
			if(pos!=-1){
				cout<<pos<<" ";
			}
			else{
				break;
			}
		}
		cout<<"}"<<endl;
	}
}

int main(){
	string P;
	string C;
	cout<<"Ingrese la Cadena principal: "; getline(cin,P);
	cout<<"Ingrese la SubCadena a buscar: "; getline(cin,C);
	cout<<endl;
	Coincidencias(P,C);

}
