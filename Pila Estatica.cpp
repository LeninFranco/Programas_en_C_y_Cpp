#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
using namespace std;

typedef struct stack{
	int top;//Ultimo dato introducido
	int vector[MAX];//Arreglo de direcciones
}Stack;
int StackFull(Stack *s){
	if(s->top>=MAX){
		return 1;
	}
	else{
		return 0;
	}
}
int StackEmpty(Stack *s){
	if(s->top<=0){
		return 1;
	}
	else{
		return 0;
	}
}
void CreateStack(Stack *s){
	s->top=0;
	cout<<"La pila se ha creado exitosamente"<<endl;
}
void Push(Stack *s, int item){
	if(StackFull(s)){
		cout<<"La pila esta llena"<<endl;
	}
	else{
		s->vector[s->top++]=item;
		cout<<"Se ha añadido correctamente el dato"<<endl;
	}
}
void Pop(Stack *s, int &item){
	if(StackEmpty(s)){
		cout<<"La pila esta vacia"<<endl;
	}
	else{
		item=s->vector[s->top--];
		cout<<"Se ha eliminado el ultimo dato correctamente"<<endl;
	}
}
void ShowStack(Stack *s){
	int i, item;
	if(StackEmpty(s)){
		cout<<"La pila esta vacia"<<endl;
	}
	else{
		for(i=1;i<=s->top;i++){
			item=s->vector[s->top-i];
			cout<<"|"<<item<<"|"<<endl;
			s->vector[s->top+i]=item;
		}
	}
}
int main(){
	Stack S1;
	int opc, item;
	CreateStack(&S1);
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
			Push(&S1, item);
			cout<<"Presione ENTER para continuar"<<endl;
			getch();
			break;
			case 2:
			Pop(&S1, item);
			cout<<"Presione ENTER para continuar"<<endl;
			getch();
			break;
			case 3:
			ShowStack(&S1);
			cout<<"Presione ENTER para continuar"<<endl;
			getch();
			break;
		}
	}while(opc!=4);
	
}
