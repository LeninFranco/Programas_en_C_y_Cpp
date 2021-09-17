#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct nodo{
	int valor;
	nodo *next;
};
void Push(nodo *&s, int item){
	nodo *new_nodo=new nodo();
	new_nodo->valor=item;
	new_nodo->next=s;
	s=new_nodo;
	cout<<"Se ha añadido el dato correctamente"<<endl;
}
void Pop(nodo *&s, int &item){
	if(s==NULL){
		cout<<"La pila esta vacia"<<endl;
	}
	else{
		nodo *aux=s;
		item=aux->valor;
		s=aux->next;
		delete aux;
		cout<<"Se he eliminado el dato correctamente"<<endl;
	}
}
void ShowStack(nodo *&s){
	int item;
	if(s->valor==NULL){
		cout<<"La pila esta vacia"<<endl;
	}
	else{
		nodo *aux=s;
		while(aux!=NULL){
			item=aux->valor;
			cout<<"|"<<item<<"|"<<endl;
			aux=aux->next;
		}
	}
}
int main(){
	int item, opc;
	nodo *S1=NULL;
	cout<<"Se ha creado la pila correctamente"<<endl;
	cout<<"Presione ENTER para continuar";
	getch();
	do{
		system("cls");
		cout<<"---------MENU PRINCIPAL---------"<<endl;
		cout<<"1. Ingreso de datos a la pila(Push)"<<endl;
		cout<<"2. Eliminar datos de la pila"<<endl;
		cout<<"3. Mostrar datos de la pila"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"---------------------------------"<<endl<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
			cout<<"Ingrese un dato a la pila: "; cin>>item;
			Push(S1, item);
			cout<<"Presione ENTER para continuar"<<endl;
			getch();
			break;
			case 2:
			Pop(S1, item);
			cout<<"Presione ENTER para continuar"<<endl;
			getch();
			break;
			case 3:
			ShowStack(S1);
			cout<<"Presione ENTER para continuar"<<endl;
			getch();
			break;
		}
	}while(opc!=4);
	
}
