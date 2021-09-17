#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int i, dato, opc, n, temp[100], n1,n2, n3, t;
	queue<int>Q1;
	queue<int>Q2;
	queue<int>Q3;
	stack<int>aux;
	do{
		system("cls");
		cout<<"MENU DE OPERACIONES"<<endl<<endl<<"1.Ingresar datos en la cola 1"<<endl<<"2.Ingresar daros de la cola 2"<<endl<<"3.Borrar datos de la cola 1"<<endl<<"4.Borrar datos de la cola 2"<<endl<<"5.Invertir Cola 1"<<endl<<"6.Invertir Cola 2"<<endl<<"7.Mostrar colas 1 y 2"<<endl<<"8.Concatenar colas 1 y 2"<<endl<<"9.Salir"<<endl<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
			cout<<"Digite el dato para la cola 1: "; cin>>dato;
			Q1.push(dato);	
			cout<<"Se ha almacenado el dato correctamente"<<endl<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 2:
			cout<<"Digite el dato para la cola 2: "; cin>>dato;
			Q2.push(dato);	
			cout<<"Se ha almacenado el dato correctamente"<<endl<<"[ENTER PARA CONTINUAR]"; getch();	
			break;
			case 3:
			if(Q1.empty()){
				cout<<"La cola 1 esta vacia"<<endl;
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			}	
			else{
				cout<<"Se ha eliminado el dato: "<<Q1.front()<<endl;
				Q1.pop();
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			}
			break;
			case 4:
			if(Q2.empty()){
				cout<<"La cola 2 esta vacia"<<endl;
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			}	
			else{
				cout<<"Se ha eliminado el dato: "<<Q2.front()<<endl;
				Q2.pop();
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			}
			break;
			case 5:
			if(Q1.empty()){
				cout<<"La cola 1 esta vacia"<<endl;
				cout<<"[ENTER PARA CONTINUAR]"; getch();	
			}
			else{
				n=Q1.size();
				for(i=0;i<n;i++){
					aux.push(Q1.front());
					Q1.pop();
				}
				n=aux.size();
				for(i=0;i<n;i++){
					Q1.push(aux.top());
					aux.pop();
				}
				cout<<"Se ha completado la operacion correctamente"<<endl<<"[ENTER PARA CONTINUAR]"; getch();	
			}
			break;
			case 6:
				if(Q2.empty()){
				cout<<"La cola 2 esta vacia"<<endl;
				cout<<"[ENTER PARA CONTINUAR]"; getch();	
				}
				else{
				n=Q2.size();
				for(i=0;i<n;i++){
					aux.push(Q2.front());
					Q2.pop();
				}
				n=aux.size();
				for(i=0;i<n;i++){
					Q2.push(aux.top());
					aux.pop();
				}
				cout<<"Se ha completado la operacion correctamente"<<endl<<"[ENTER PARA CONTINUAR]"; getch();	
			}
			break;
			case 7:
			cout<<"Cola 1: "<<endl;
			n1=Q1.size();
			for(i=0;i<n1;i++){
				temp[i]=Q1.front();
				cout<<temp[i]<<"  ";
				Q1.pop();
			}	
			for(i=0;i<n1;i++){
				Q1.push(temp[i]);
			}
			cout<<endl<<"Cola 2: "<<endl;
			n2=Q2.size();
			for(i=0;i<n2;i++){
				temp[i]=Q2.front();
				cout<<temp[i]<<"  ";
				Q2.pop();
			}	
			for(i=0;i<n2;i++){
				Q2.push(temp[i]);
			}
			cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
			break;	
			case 8:
			n1=Q1.size();
			n2=Q2.size();
			for(i=0;i<n1;i++){
				Q3.push(Q1.front());
				Q1.pop();
			}
			for(i=0;i<n2;i++){
				Q3.push(Q2.front());
				Q2.pop();
			}
			n3=Q3.size();
			cout<<"Cola concatenada: "<<endl;
			for(i=0;i<n3;i++){
				temp[i]=Q3.front();
				cout<<temp[i]<<"  ";
				Q3.pop();
			}
			for(i=0;i<n1;i++){
				Q1.push(temp[i]);
			}
			n2=n2+n1;
			for(i=n1;i<n2;i++){
				Q2.push(temp[i]);
			}
			cout<<endl<<"[ENTER PARA CONTINUAR]"; getch();
			break;
		}
	}while(opc!=9);
	getch();
}
