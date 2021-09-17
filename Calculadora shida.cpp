#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void suma1(float num, float &c){
	c=c+num;
}
void suma2(float num1, float num2, float &c){
	c=num1+num2;
}

void resta1(float num, float &c){
	c=c-num;
}
void resta2(float num1, float num2, float &c){
	c=num1-num2;
}

void multi1(float num, float &c){
	c=c*num;
}
void multi2(float num1, float num2, float &c){
	c=num1*num2;
}

void divi1(float num, float &c){
	c=c/num;
}
void divi2(float num1, float num2, float &c){
	c=num1/num2;
}

int main(){
	float c=0, num, num1, num2;
	char ope[2];
	do{
		system("cls");
		cout<<"Las operaciones que puede realizar es: suma(+), resta(-), multiplicacion(*), division(/), limpiar memoria(c), salir(e)"<<endl;
		cout<<"R: "<<c<<endl;
		cout<<"Operacion: "; cin.getline(ope,2);
		if(c!=0){
			if(strcmp(ope,"+")==0){
				cout<<"Numero: "; cin>>num;
				suma1(num,c);
			}
			else if(strcmp(ope,"-")==0){
				cout<<"Numero: "; cin>>num;
				resta1(num,c);
			}
			else if(strcmp(ope,"*")==0){
				cout<<"Numero: "; cin>>num;
				multi1(num,c);
			}
			else if(strcmp(ope,"/")==0){
				cout<<"Numero: "; cin>>num;
				divi1(num,c);
			}
			else if(strcmp(ope,"c")==0){
				c=0;
			}
			else if(strcmp(ope,"e")==0){
				break;
			}
			else{
				continue;
			}
		}
		else{
			if(strcmp(ope,"+")==0){
				cout<<"Numero 1: "; cin>>num1;
				cout<<"Numero 2: "; cin>>num2;
				suma2(num1,num2,c);	
			}
			else if(strcmp(ope,"-")==0){
				cout<<"Numero 1: "; cin>>num1;
				cout<<"Numero 2: "; cin>>num2;
				resta2(num1,num2,c);
			}
			else if(strcmp(ope,"*")==0){
				cout<<"Numero 1: "; cin>>num1;
				cout<<"Numero 2: "; cin>>num2;
				multi2(num1,num2,c);
			}
			else if(strcmp(ope,"/")==0){
				cout<<"Numero 1: "; cin>>num1;
				cout<<"Numero 2: "; cin>>num2;
				divi2(num1,num2,c);
			}
			else if(strcmp(ope,"c")==0){
				c=0;
			}
			else if(strcmp(ope,"e")==0){
				break;
			}
			else{
				continue;
			}
		}
	}while(true);
	system("cls");
	cout<<"Gracias por usarme bb"<<endl;
	system("pause");
}
