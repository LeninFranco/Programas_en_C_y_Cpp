#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *sig;
};

void insert(Nodo *&lista, int num){
	Nodo *new_nodo=new Nodo();
	new_nodo->dato=num;
	Nodo *aux1 = lista;
	Nodo *aux2;
	while((aux1!=NULL)&&(aux1->dato<num)){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	if(lista == aux1){
		lista = new_nodo;
	}
	else{
		aux2->sig=new_nodo;
	}
	new_nodo->sig=aux1;
	cout<<"Elemento "<<num<<" insertado a la lista correctamente"<<endl;
	cout<<"[ENTER PARA CONTINUAR]"; getch();
}

void del(Nodo *&lista, int num){
	if(lista!=NULL){
		Nodo *aux_delete;
		Nodo *before=NULL;
		aux_delete=lista;
		while((aux_delete!=NULL)&&(aux_delete->dato!=num)){
			before=aux_delete;
			aux_delete=aux_delete->sig;
		}
		if(aux_delete==NULL){
			cout<<"El elemento no existe en la lista"<<endl;
			cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
		}
		else if(before==NULL){
			lista=lista->sig;
			delete aux_delete;
			cout<<"El elemento "<<num<<" ha sido eliminado correctamente"<<endl;
			cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
		}
		else{
			before->sig=aux_delete->sig;
			delete aux_delete;
			cout<<"El elemento "<<num<<" ha sido eliminado correctamente"<<endl;
			cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
		}
	}
}

void display(Nodo *&lista){
	Nodo *show=new Nodo();
	show=lista;
	while(show!=NULL){
		cout<<show->dato<<"->";
		show=show->sig;
	}
	cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
}

bool search(Nodo *&lista, int num){
	Nodo *look=new Nodo();
	look=lista;
	while((look!=NULL)&&(look->dato<=num)){
		if(look->dato==num){
			return true;
		}
		look=look->sig;
	}
}

int main(){
	int opc, num;
	Nodo *lista = NULL;
	do{
		system("cls");
		cout<<"Menu Principal"<<endl<<endl<<"1.Insertar elemento"<<endl<<"2.Eliminar elemento"<<endl<<"3.Buscar elemento"<<endl<<"4.Mostrar Lista"<<endl<<"5.Salir"<<endl<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
				cout<<"Ingrese el elemento: "; cin>>num;
				insert(lista,num);
			break;
			case 2:
				cout<<"Ingrese el elemento al eliminar: "; cin>>num;
				del(lista,num);
			break;
			case 3:
				cout<<"Ingrese el elemento a buscar: "; cin>>num;
				if(search(lista,num)){
					cout<<"El elemento "<<num<<" esta en la lista"<<endl;
					cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
				}
				else{
					cout<<"El elemento "<<num<<" no esta en la lista"<<endl;
					cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
				}
			break;
			case 4:
				display(lista);
			break;
		}
	}while(opc!=5);
	return 0;
	getch();
}


