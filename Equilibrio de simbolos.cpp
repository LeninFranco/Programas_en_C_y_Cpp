#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>

using namespace std;

int main(){
	char expr[100];
	int i, error=0, j=0;;
	stack<char>pila;
	cout<<"EVALUADOR DE EXPRESIONES CON (), [], {}"<<endl;
	cout<<"Ingrese la expresion: "; cin>>expr;
	for(i=0;i<strlen(expr);i++){
		j++;
		if(expr[i]==40||expr[i]==91||expr[i]==123){
			pila.push(expr[i]);
		}
		else{
			switch(expr[i]){
				case ')':
				if(pila.empty()){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Inicio la expresion con un simbolo de cierre"<<endl;
					error++;
					break;
				}
				if(pila.top()=='['){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Cerro la operacion con un simbolo incorrecto"<<endl;
					error++;
					break;
				}
				if(pila.top()=='{'){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Cerro la operacion con un simbolo incorrecto"<<endl;
					error++;
					break;
				}
				if(pila.top()=='('){
					pila.pop();
				}
				break;
				case ']':
				if(pila.empty()){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Inicio la expresion con un simbolo de cierre"<<endl;
					error++;
					break;
				}
				if(pila.top()=='('){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Cerro la operacion con un simbolo incorrecto"<<endl;
					error++;
					break;
				}
				if(pila.top()=='{'){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Cerro la operacion con un simbolo incorrecto"<<endl;
					error++;
					break;
				}
				if(pila.top()=='['){
					pila.pop();
				}
				break;
				case '}':
				if(pila.empty()){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Inicio la expresion con un simbolo de cierre"<<endl;
					error++;
					break;
				}
				if(pila.top()=='['){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Cerro la operacion con un simbolo incorrecto"<<endl;
					error++;
					break;
				}
				if(pila.top()=='('){
					cout<<"Error en el digito "<<i+1<<endl;
					cout<<"Cerro la operacion con un simbolo incorrecto"<<endl;
					error++;
					break;
				}
				if(pila.top()=='{'){
					pila.pop();
				}
				break;
			}
		}
	}
	if(!pila.empty()&&pila.size()==1){
		cout<<"Error en el digito "<<j+1<<endl;
		cout<<"No cerro el ultimo simbolo para acompletar la expresion"<<endl;
	}
	if(pila.empty()&&error==0){
		cout<<"La expresion esta correctamente hecha ;D"<<endl;
	}
	return 0;
	getch();
}
