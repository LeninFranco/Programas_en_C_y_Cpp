#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define max 10
using namespace std;

typedef struct Auto{
	char matricula[7];
	int contador=0;
}car;

struct Nodo{
	car dato;
	Nodo *next;
}*first[max],*last[max];

int Disp(car dato){//Analiza la matricula y el primer numero que encuentre en la matricula, sera la posicion en la que se almacena o se realizara la busqueda
	char cpy[7],aux[7];
	int pos;
	strcpy(cpy,dato.matricula);
	for(int i=0;i<strlen(cpy);i++){
		if(isdigit(cpy[i])){
			aux[0]=cpy[i];
			pos=atoi(aux);
			break;
		}
	}
	return pos;
}

int Search_to_Insert(int pos, car dato){
	Nodo *aux=new Nodo();
	aux=first[pos];
	bool found=false;
	if(first[pos]!=NULL){
		while(aux!=NULL){
			if(strcmp(aux->dato.matricula,dato.matricula)==0){
				found=true;
				aux->dato.contador++;
				return 1;
				break;
			}
			aux=aux->next;
		}
		if(found==false){
			return 0;
		}
	}
	else{
		return 0;
	}
}

void Search(int pos, car dato){
	Nodo *aux=new Nodo();
	aux=first[pos];
	bool found=false;
	if(first[pos]!=NULL){
		while(aux!=NULL){
			if(strcmp(aux->dato.matricula,dato.matricula)==0){
				found=true;
				cout<<"se ha encontrado el dato satisfactoriamente: "<<endl;
				cout<<pos<<"  "<<"Matricula: "<<aux->dato.matricula<<" Multas: "<<aux->dato.contador<<endl;
				break;
			}
			aux=aux->next;
		}
		if(found==false){
			cout<<"No se ha encontrado el dato"<<endl;
		}
	}
	else{
		cout<<"No se ha encontrado el dato"<<endl;
	}
}

void Insert(int pos,car dato){
	Nodo *nuevo=new Nodo();
	nuevo->dato=dato;
	if(first[pos]==NULL){
		first[pos]=nuevo;
		first[pos]->next=NULL;
		last[pos]=nuevo;
	}
	else{
		last[pos]->next=nuevo;
		nuevo->next=NULL;
		last[pos]=nuevo;
	}
	cout<<"Se ha guardado el dato correctamente"<<endl;
}

void Show(){
	Nodo *aux=new Nodo();
	for(int i=0;i<max;i++){
		aux=first[i];
		if(first[i]!=NULL){
			cout<<i<<"  ";
			while(aux!=NULL){
				cout<<"Matricula: "<<aux->dato.matricula<<" Multas: "<<aux->dato.contador<<"->";
				aux=aux->next;
			}
			cout<<endl;
		}
		else{
			cout<<i<<"  NULL"<<endl;
		}
	}
}

int main(){
	for(int i=0;i<max;i++){
		first[i]=NULL;
		last[i]=NULL;
	}
	int opc,pos,limite=80, cond, velocidad;
	do{
		car dato;
		system("cls");
		cout<<"MENU"<<endl<<"1.Insertar Registro"<<endl<<"2.Buscar Registro"<<endl<<"3.Mostrar Tabla"<<endl<<"4.Salir"<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
			cout<<"Ingrese la matricula(tres numeros y tres letras): "; cin>>dato.matricula;
			pos=Disp(dato);
			cond=Search_to_Insert(pos,dato);
			if(cond==0){
				cout<<"Ingrese la velocidad: "; cin>>velocidad;
				if(velocidad>limite){
					dato.contador++;
					Insert(pos,dato);
				}
				else{
					cout<<"Este auto no revaso el limite de velocidad"<<endl;
				}
			}
			else{
				cout<<"El auto ya tiene multas, favor de checar la opcion de Mostrar tabla para ver su numero de multas :3"<<endl;
			}
			cout<<"[ENTER PARA CONTINUAR]"<<endl; getch();
			break;
			case 2:
			cout<<"Ingrese la matricula(tres numeros y tres letras): "; cin>>dato.matricula;
			pos=Disp(dato);
			Search(pos, dato);
			cout<<"[ENTER PARA CONTINUAR]"<<endl; getch();
			break;
			case 3:
			Show();
			cout<<"[ENTER PARA CONTINUAR]"<<endl; getch();
			break;
		}
	}while(opc!=4);
}
