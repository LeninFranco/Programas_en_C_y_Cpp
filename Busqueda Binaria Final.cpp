#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

typedef struct datos{
	int Bol;
	char nom[20];
	char apeP[20];
	char apeM[20];
	float prom;
}Alumno;

int main(){
int n,opc,dato, pos, r=1, opc1;
char bus[10];
	cout<<"Ingrese el numero de elementos: "; cin>>n;
	Alumno array[n], aux;
	for(int i=0;i<n;i++){
		cout<<endl;
		cout<<"Registro "<<r<<endl;
		cout<<"Boleta: "; cin>>array[i].Bol;
		cout<<"Nombre: "; cin>>array[i].nom;
		cout<<"Apellido Paterno: "; cin>>array[i].apeP;
		cout<<"Apellido Materno: "; cin>>array[i].apeM;
		cout<<"Promedio: "; cin>>array[i].prom;
		r++;
	}
	bool bandera;
	for(int i=1;i<n;i++){
		bandera=false;
		for(int j=n-1;j>=i;j--){
			if(array[j-1].Bol>array[j].Bol){
				aux=array[j-1];
				array[j-1]=array[j];
				array[j]=aux;
				bandera=true;
			}
		}
		if(bandera==false){
			break;
		}
	}
	do{
		int half, linf=0, lsup=n, band;
		system("cls");
		cout<<"MENU"<<endl<<"1.Buscar Elemento"<<endl<<"2.Mostrar todos los elementos"<<endl<<"3.Salir"<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
				system("cls");
				cout<<"BUSQUEDA"<<endl<<"1.Por Boleta"<<endl<<"2.Por Apellido Paterno"<<endl<<"Opcion: "; cin>>opc1;
				switch(opc1){
					case 1:
						band=0;
						cout<<"Ingrese la boleta del alumno: "; cin>>dato;
						while(linf<=lsup){
						half=(linf+lsup)/2;
						if(dato==array[half].Bol){
						cout<<endl;
						cout<<"Boleta: "<<array[half].Bol<<endl;
						cout<<"Nombre: "<<array[half].nom<<endl;
						cout<<"Apellido Paterno: "<<array[half].apeP<<endl;
						cout<<"Apellido Materno: "<<array[half].apeM<<endl;
						cout<<"Promedio: "<<array[half].prom<<endl;
						band=1;
						break;
						}	
						if(dato<array[half].Bol){
							lsup=half-1;
						}
						else{
							linf=half+1;
						}
						}	
						if(band==0){
						cout<<"No se ha encontrado al alumno"<<endl;
						}
						cout<<"[ENTER PARA CONTINUAR]"; getch();
					break;
					case 2:
						band=0;
						cout<<"Ingrese el apellido paterno del alumno: "; cin>>bus;
						for(int i=0;i<n;i++){
							if(strcmp(array[i].apeP,bus)==0){
								cout<<"Boleta: "<<array[i].Bol<<endl;
								cout<<"Nombre: "<<array[i].nom<<endl;
								cout<<"Apellido Paterno: "<<array[i].apeP<<endl;
								cout<<"Apellido Materno: "<<array[i].apeM<<endl;
								cout<<"Promedio: "<<array[i].prom<<endl;
								band=1;
								break;
							}
						}
						if(band==0){
						cout<<"No se ha encontrado al alumno"<<endl;
						}
						cout<<"[ENTER PARA CONTINUAR]"; getch();
					break;
			}
			break;
			case 2:
				r=1;
				for(int i=0;i<n;i++){
					cout<<endl;
					cout<<"Registro "<<r<<endl;
					cout<<"Boleta: "<<array[i].Bol<<endl;
					cout<<"Nombre: "<<array[i].nom<<endl;
					cout<<"Apellido Paterno: "<<array[i].apeP<<endl;
					cout<<"Apellido Materno: "<<array[i].apeM<<endl;
					cout<<"Promedio: "<<array[i].prom<<endl;
					r++;
				}
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
		}
	}while(opc!=3);
	
}
