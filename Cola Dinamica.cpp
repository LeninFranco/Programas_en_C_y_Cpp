#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct queue{
	int dato;
	queue *next_element;
}*primero,*cola,*ultimo=NULL;

void Insert(){
	cola=new(queue);
	cout<<"Ingrese el dato: "; cin>>cola->dato;
	if(ultimo!=NULL){
		ultimo->next_element=cola;
		cola->next_element=NULL;
		ultimo=cola;
		cout<<"Dato ingresado correctamente"<<endl<<"[ENTER PARA CONTINUAR]"; getch();
	}
	else{
		primero=ultimo=cola;
		cout<<"Dato ingresado correctamente"<<endl<<"[ENTER PARA CONTINUAR]"; getch();
	}
}

void Delete(){
	if(primero!=NULL){
		cola=primero;
		cout<<"Dato "<<primero->dato<<" eliminado"<<endl<<"[ENTER PARA CONTINUAR]"; getch();
		primero=cola->next_element;
		delete(cola);
		if(primero==NULL){
			cola=NULL;
			ultimo=NULL;
		}
	}
	else{
		cout<<"La cola esta vacia"<<endl<<"[ENTER PARA CONTINUAR]"; getch();
	}
}

void ShowQueue(){
	if(primero==NULL){
		cout<<"La cola esta vacia"<<endl<<"[ENTER PARA CONTINUAR]"; getch();
		return;
	}
		cola=primero;
		while(cola!=NULL){
			cout<<cola->dato<<"  ";
			cola=cola->next_element;
		}
		cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
	}
int main(){
	int opc;
	do{
		system("cls");
		cout<<"Menu Principal"<<endl<<endl<<"1.Ingresar dato a la cola"<<endl<<"2.Eliminar dato de la cola"<<endl<<"3.Mostrar cola"<<endl<<"4.Salir"<<endl<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
			Insert();	
			break;
			case 2:
			Delete();
			break;
			case 3:
			ShowQueue();	
			break;
		}
	}while(opc!=4);
}
