#include <iostream>
#include <conio.h>
#define max 10
using namespace std;

struct Nodo{
	int dato;
	Nodo *next;
}*first[max],*last[max];

void Insert(int pos,int dato){
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

void Search(int pos, int dato){
	Nodo *aux=new Nodo();
	aux=first[pos];
	bool found=false;
	if(first[pos]!=NULL){
		while(aux!=NULL){
			if(aux->dato==dato){
				found=true;
				cout<<"se ha encontrado el dato satisfactoriamente: "<<endl;
				cout<<pos<<"  "<<aux->dato<<endl;
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

void Show(){
	Nodo *aux=new Nodo();
	for(int i=0;i<max;i++){
		aux=first[i];
		if(first[i]!=NULL){
			cout<<i<<"  ";
			while(aux!=NULL){
				cout<<aux->dato<<"->";
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
	int opc,dato,pos;
	do{
		system("cls");
		cout<<"MENU"<<endl<<"1.Insertar dato"<<endl<<"2.Buscar dato"<<endl<<"3.Mostrar Tabla"<<endl<<"4.Salir"<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
			cout<<"Ingrese el dato: "; cin>>dato;
			pos=dato%max;//Metodo de dipersion modular
			Insert(pos,dato);
			cout<<"[ENTER PARA CONTINUAR]"<<endl; getch();
			break;
			case 2:
			cout<<"Ingrese el dato a buscar: "; cin>>dato;
			pos=dato%max;
			Search(pos,dato);
			cout<<"[ENTER PARA CONTINUAR]"<<endl; getch();
			break;
			case 3:
			Show();	
			cout<<"[ENTER PARA CONTINUAR]"<<endl; getch();
			break;
		}
	}while(opc!=4);
}
