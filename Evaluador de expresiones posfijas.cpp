#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>

using namespace std;

int main(){
	stack<int>pila;
	int n1, n2, ntemp, i, res, restemp;
	char exp[100], chartemp[10];
	cout<<"Favor de introducir la expresion posfija: "; cin>>exp;
	for(i=0;i<strlen(exp);i++){
		if(isdigit(exp[i])){
			chartemp[0]=exp[i];
			ntemp=atoi(chartemp);
			pila.push(ntemp);
		}
		else{
			switch(exp[i]){
				case '^':
				n2=pila.top();
				pila.pop();
				n1=pila.top();
				pila.pop();
				restemp=pow(n1,n2);
				pila.push(restemp);
				break;
				case '*':
				n2=pila.top();
				pila.pop();
				n1=pila.top();
				pila.pop();
				restemp=n1*n2;
				pila.push(restemp);
				break;
				case '/':
				n2=pila.top();
				pila.pop();
				n1=pila.top();
				pila.pop();
				restemp=n1/n2;
				pila.push(restemp);
				break;
				case '+':
				n2=pila.top();
				pila.pop();
				n1=pila.top();
				pila.pop();
				restemp=n1+n2;
				pila.push(restemp);
				break;
				case '-':
				n2=pila.top();
				pila.pop();
				n1=pila.top();
				pila.pop();
				restemp=n1-n2;
				pila.push(restemp);
				break;
			}
		}
	}
	res=pila.top();
	pila.pop();
	cout<<"El resultado de la expresion es de: "<<res<<endl;
	getch();
}
