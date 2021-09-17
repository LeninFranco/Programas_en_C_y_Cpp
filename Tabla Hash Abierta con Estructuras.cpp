#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#define MAX 10

using namespace std;

typedef struct{
	long int ID;
	string Nombre_Completo;
	int Edad;
	string Numero_Telefono;
}Persona;

struct Nodo{
	Persona Dato;
	Nodo *sig;	
}*frente[MAX],*ultimo[MAX];

void Menu(int &opc){
	system("cls");
	cout<<"\t\t*****************************************************"<<endl<<"\t\t*               MENU DE REGISTRO                    *"<<endl<<"\t\t*****************************************************"<<endl;
	cout<<endl<<"\t1.Registar Persona"<<endl<<"\t2.Eliminar Registro"<<endl<<"\t3.Buscar Persona"<<endl<<"\t4.Mostrar Todos los registros"<<endl<<"\t5.Salir"<<endl<<"\tOpcion: "; cin>>opc;
}

void Dispersion(Persona Reg, int &pos){
	pos=Reg.ID%10;
}

void Insertar_Tabla(Persona Reg, int pos){
	Nodo *nuevo=new Nodo();
	nuevo->Dato=Reg;
	if(frente[pos]==NULL){
		frente[pos]=nuevo;
		frente[pos]->sig=NULL;
		ultimo[pos]=nuevo;
	}
	else{
		ultimo[pos]->sig=nuevo;
		nuevo->sig=NULL;
		ultimo[pos]=nuevo;
	}
}

void Buscar_Tabla(int pos, long int ID_Bus){
	bool band=false;
	Nodo *aux=new Nodo();
	aux=frente[pos];
	if(frente[pos]!=NULL){
		while(aux!=NULL){
			if(aux->Dato.ID==ID_Bus){
				band=true;
				cout<<"Se ha encontrado el dato correctamente"<<endl;
				cout<<"-----------------------------------------------------------------------------------------------"<<endl;
				cout<<"Numero de Identificacion: "<<aux->Dato.ID<<endl;
				cout<<"Nombre Completo: "<<aux->Dato.Nombre_Completo<<endl;
				cout<<"Edad: "<<aux->Dato.Edad<<endl;
				cout<<"Numero de Telefono: "<<aux->Dato.Numero_Telefono<<endl<<endl;
				cout<<"-----------------------------------------------------------------------------------------------"<<endl;
				break;
			}
			aux=aux->sig;
		}
		if(band==false){
			cout<<"No se encontro el registro"<<endl;
		}
	}
	else{
		cout<<"No se encontro el registro"<<endl;
	}
}

void Eliminar(int pos, long int ID_Bus){
	bool band=false;
	Nodo *aux=new Nodo();
	Nodo *anterior=new Nodo();
	aux=frente[pos];
	if(frente[pos]!=NULL){
		while(aux!=NULL){
			if(aux->Dato.ID==ID_Bus){
				band=true;
				if(aux==frente[pos]){
					frente[pos]=frente[pos]->sig;
				}
				else if(aux==ultimo[pos]){
					anterior->sig=NULL;
					ultimo[pos]=anterior;
				}
				else{
					anterior->sig=aux->sig;
				}
				break;
			}
			anterior=aux;
			aux=aux->sig;
		}
		if(band==false){
			cout<<"No se encontro el registro a eliminar"<<endl;
		}
		else{
			cout<<"Se ha eliminado el registro correctamente"<<endl;
		}
	}
	else{
		cout<<"No se encontro el registro a eliminar"<<endl;
	}
}

void Registro(Persona &Reg){
	int pos;
	cout<<"Ingrese el Numero de Identificacion: "; cin>>Reg.ID;
	fflush(stdin);
	cout<<"Ingrese el Nombre Completo: "; getline(cin, Reg.Nombre_Completo);
	cout<<"Ingrese la Edad: "; cin>>Reg.Edad;
	cout<<"Ingrese el Numero de Telefono(10 digitos): "; cin>>Reg.Numero_Telefono;
	Dispersion(Reg, pos);
	Insertar_Tabla(Reg, pos);
}

void Mostrar(){
	Nodo *aux=new Nodo();
	for(int i=0;i<MAX;i++){
		aux=frente[i];
		if(aux!=NULL){
			while(aux!=NULL){
				cout<<"-----------------------------------------------------------------------------------------------"<<endl;
				cout<<"Numero de Identificacion: "<<aux->Dato.ID<<endl;
				cout<<"Nombre Completo: "<<aux->Dato.Nombre_Completo<<endl;
				cout<<"Edad: "<<aux->Dato.Edad<<endl;
				cout<<"Numero de Telefono: "<<aux->Dato.Numero_Telefono<<endl<<endl;
				cout<<"-----------------------------------------------------------------------------------------------"<<endl;
				aux=aux->sig;
			}
		}
		else{
			continue;
		}
		
	}
}


int main(){
	int opc, pos;
	long int ID_Bus;
	Persona Reg;
	do{
		Menu(opc);
		switch(opc){
			case 1:
			cout<<endl<<endl;
			Registro(Reg);
			system("Pause");
			break;
			case 2:
			cout<<endl<<endl;
			cout<<"Ingrese el ID a eliminar: "; cin>>ID_Bus;
			pos=ID_Bus%10;
			Eliminar(pos,ID_Bus);
			system("Pause");
			break;
			case 3:
			cout<<endl<<endl;
			cout<<"Ingrese el ID a buscar: "; cin>>ID_Bus;
			pos=ID_Bus%10;
			Buscar_Tabla(pos,ID_Bus);
			system("Pause");
			break;
			case 4:
			cout<<endl<<endl;
			Mostrar();
			system("Pause");
			break;
		}
	}while(opc!=5);
}
