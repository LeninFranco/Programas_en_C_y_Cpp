#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

typedef struct Fraccion{
	int num;
	int dem;
}Q;

void Menu(int &opc){
	cout<<"MENU PRINCIPAL"<<endl;
	cout<<"1. Suma"<<endl;
	cout<<"2. Resta"<<endl;
	cout<<"3. Multiplicacion"<<endl;
	cout<<"4. Division"<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"Opcion: "; cin>>opc;
}

void Insert(Q &q1, Q &q2){
	cout<<"Fraccion 1"<<endl;
	cout<<"    Numerador: "; cin>>q1.num;
	cout<<"    Denominador: "; cin>>q1.dem;
	cout<<"Fraccion 2"<<endl;
	cout<<"    Numerador: "; cin>>q2.num;
	cout<<"    Denominador: "; cin>>q2.dem;
}

void Simplif(Q &r){
	for(int i=2;i<=100;i++){
		while(r.num%i==0 && r.dem%i==0){
			r.num=r.num/i;
			r.dem=r.dem/i;
		}
	}
}

void Suma(Q q1, Q q2, Q &r){
	r.num = ((q1.num*q2.dem)+(q1.dem*q2.num));
	r.dem = q1.dem*q2.dem;
	Simplif(r);
}

void Resta(Q q1, Q q2, Q &r){
	r.num = ((q1.num*q2.dem)-(q1.dem*q2.num));
	r.dem = q1.dem*q2.dem;
	Simplif(r);
}

void Multi(Q q1, Q q2, Q &r){
	r.num = q1.num * q2.num;
	r.dem = q1.dem * q2.dem;
	Simplif(r)
}

void Divi(Q q1, Q q2, Q &r){
	r.num = q1.num * q2.dem;
	r.dem = q1.dem * q2.num;
	Simplif(r);
}

int main(){
	int opc;
	Q q1, q2, r;
	do{
		system("cls");
		Menu(opc);
		cout<<"\n\n";
		switch(opc){
			case 1:
				Insert(q1,q2);
				Suma(q1,q2,r);
				cout<<"\nResultado de la suma: "<<q1.num<<"/"<<q1.dem<<" + "<<q2.num<<"/"<<q2.dem<<" = "<<r.num<<"/"<<r.dem<<endl;
			break;
			case 2:
				Insert(q1,q2);
				Resta(q1,q2,r);
				cout<<"\nResultado de la resta: "<<q1.num<<"/"<<q1.dem<<" - "<<q2.num<<"/"<<q2.dem<<" = "<<r.num<<"/"<<r.dem<<endl;
			break;
			case 3:
				Insert(q1,q2);
				Multi(q1,q2,r);
				cout<<"\nResultado de la Multiplicacion: "<<q1.num<<"/"<<q1.dem<<" * "<<q2.num<<"/"<<q2.dem<<" = "<<r.num<<"/"<<r.dem<<endl;
			break;
			case 4:
				Insert(q1,q2);
				Divi(q1,q2,r);
				cout<<"\nResultado de la division: "<<q1.num<<"/"<<q1.dem<<" / "<<q2.num<<"/"<<q2.dem<<" = "<<r.num<<"/"<<r.dem<<endl;
			break;
		}
		system("Pause");
	}while(opc!=5);
}



