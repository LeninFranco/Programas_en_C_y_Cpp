#include <iostream>
#include <conio.h>
#define max 20
using namespace std;

typedef struct datos{
	int ID;
	char nom[20];
	char ape[20];
	float prom;
	int busq=0;
}Alumno;

int main(){
	int opc,dato, pos, r=1, n=0;
	Alumno array[max], aux;
	do{
		system("cls");
		cout<<"MENU"<<endl<<"1.Buscar Elemento"<<endl<<"2.Agregar elemento"<<endl<<"3.Mostrar la lista"<<endl<<"4.Salir"<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
				cout<<"Ingrese el ID del alumno: "; cin>>dato;
				for(int i=0;i<n;i++){
					if(array[i].ID==dato){
						cout<<"El alumno se ha encontrado en la posicion: "<<i+1<<endl;
						cout<<"Resultado de la busqueda: "<<endl;
						cout<<"ID: "<<array[i].ID<<endl;
						cout<<"Nombre: "<<array[i].nom<<endl;
						cout<<"Apellido: "<<array[i].ape<<endl;
						cout<<"Promedio: "<<array[i].prom<<endl;
						pos=i;
						array[i].busq++;
						break;
					}
					else{
						if(i==n-1){
							cout<<"No hubo resultados en la busqueda"<<endl;
						}
					}
				}
				if(array[pos].busq<=3){
					if(pos!=0){
					aux=array[pos-1];
					array[pos-1]=array[pos];
					array[pos]=aux;	
					}	
				}
				else{
					if(pos!=0){
					aux=array[0];
					array[0]=array[pos];
					array[pos]=aux;
					for(int i=pos;i>1;i--){
						aux=array[i-1];
						array[i-1]=array[i];
						array[i]=aux;
					}
					}	
				}
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 2:
			cout<<"Registro "<<r<<endl;
			cout<<"ID: "; cin>>array[n].ID;
			cout<<"Nombre: "; cin>>array[n].nom;
			cout<<"Apellido: "; cin>>array[n].ape;
			cout<<"Promedio: "; cin>>array[n].prom;	
			r++;
			n++;
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 3:
				r=1;
				for(int i=0;i<n;i++){
					cout<<endl;
					cout<<"Registro "<<r<<endl;
					cout<<"ID: "<<array[i].ID<<endl;
					cout<<"Nombre: "<<array[i].nom<<endl;
					cout<<"Apellido: "<<array[i].ape<<endl;
					cout<<"Promedio: "<<array[i].prom<<endl;
					r++;
				}
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
		}
	}while(opc!=4);
	
}
