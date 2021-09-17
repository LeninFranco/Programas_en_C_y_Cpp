#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <queue>
#define max 10
#define tam 20

using namespace std;

int L1[max];
int L2[max];

bool FullList_L1(){
	int n=0;
	for(int i=0;i<max;i++){
		if(L1[i]!=0){
			n++;
		}	
	}
	if(n==max){
		return true;
	}
	else{
		return false;
	}	
}
bool EmptyList_L1(){
	int n=0;
	for(int i=0;i<max;i++){
		if(L1[i]==0){
			n++;
		}	
	}
	if(n==max){
		return true;
	}
	else{
		return false;
	}
}
bool FullList_L2(){
	int n=0;
	for(int i=0;i<max;i++){
		if(L2[i]!=0){
			n++;
		}	
	}
	if(n==max){
		return true;
	}
	else{
		return false;
	}	
}
bool EmptyList_L2(){
	int n=0;
	for(int i=0;i<max;i++){
		if(L2[i]==0){
			n++;
		}	
	}
	if(n==max){
		return true;
	}
	else{
		return false;
	}
}

void Size_Tester(){
	if(FullList_L1()){
		cout<<"La lista 1 esta llena"<<endl;
	}
	else if(EmptyList_L1()){
		cout<<"La lista 1 esta vacia"<<endl;
	}
	else{
		cout<<"La lista tiene datos almacenados"<<endl;
	}
	if(FullList_L2()){
		cout<<"La lista 2 esta llena"<<endl;
	}
	else if(EmptyList_L2()){
		cout<<"La lista 2 esta vacia"<<endl;
	}
	else{
		cout<<"La lista tiene datos almacenados"<<endl;
	}
}

void Delete_Lists(){
	for(int i=0;i<max;i++){
		L1[i]=NULL;
	}
	cout<<"La Lista 1 se ha vaciado correctamente"<<endl;
	for(int i=0;i<max;i++){
		L2[i]=NULL;
	}
	cout<<"La Lista 2 se ha vaciado correctamente"<<endl;
}

void Show_Lists(){
	cout<<"Lista 1"<<endl;
	for(int i=0;i<max;i++){
		if(L1[i]==0){
			cout<<"NULL ";
		}
		else{
			cout<<L1[i]<<" ";
		}
	}
	cout<<endl;
	cout<<"Lista 2"<<endl;
	for(int i=0;i<max;i++){
		if(L2[i]==0){
			cout<<"NULL ";
		}
		else{
			cout<<L2[i]<<" ";
		}
	}
	cout<<endl;
}

void Insert(){
	int opc, dato, pos;
	do{
		system("cls");
		cout<<"Seleccione la lista a la que se insertara el dato"<<endl<<"1.Lista 1"<<endl<<"2.Lista 2"<<endl<<"3.Salir"<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
			if(FullList_L1()){
				cout<<"La Lista esta llena"<<endl;
			}
			else{
				cout<<"Ingrese el Dato: "; cin>>dato;
				cout<<"Ingrese la Posicion: "; cin>>pos;
				pos--;
				for(int i=max-1;i>=pos;i--){
				L1[i+1]=L1[i];
					if(pos==i){
						L1[pos]=dato;
					}
				}
				cout<<"El Dato ha sido guardado correctamente a la lista 1"<<endl;
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			}	
			break;
			case 2:
			if(FullList_L2()){
				cout<<"La Lista esta llena"<<endl;
			}
			else{
				cout<<"Ingrese el Dato: "; cin>>dato;
				cout<<"Ingrese la Posicion: "; cin>>pos;
				pos--;
				for(int i=max-1;i>=pos;i--){
				L2[i+1]=L2[i];
					if(pos==i){
						L2[pos]=dato;
					}
				}
				cout<<"El Dato ha sido guardado correctamente a la lista 2"<<endl;
				cout<<"[ENTER PARA CONTINUAR]"; getch();
			}	
			break;
		}
	}while(opc!=3);
}

void Delete(){
	int opc, dato, pos;
	do{
		system("cls");
		cout<<"Seleccione la lista a la que se eliminara un dato"<<endl<<"1.Lista 1"<<endl<<"2.Lista 2"<<endl<<"3.Salir"<<endl<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1:
			if(EmptyList_L1()){
				cout<<"La Lista esta vacia"<<endl;
			}
			else{
			cout<<"Ingrese la posicion: "; cin>>pos;
			pos--;
			dato=L1[pos];
			for(int i=pos;i<max;i++){
				L1[i]=L1[i+1];
			}
			cout<<"Se ha eliminado el dato "<<dato<<" correctamente de la lista 1"<<endl;
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			}
			break;
			case 2:
			if(EmptyList_L2()){
				cout<<"La Lista esta vacia"<<endl;
			}
			else{
			cout<<"Ingrese la posicion: "; cin>>pos;
			pos--;
			dato=L2[pos];
			for(int i=pos;i<max;i++){
				L2[i]=L2[i+1];
			}
			cout<<"Se ha eliminado el dato "<<dato<<" correctamente de la lista 2"<<endl;
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			}
			break;
		}
	}while(opc!=3);
}

void Join_Lists(){
	queue<int> aux;
	int n;
	for(int i=0;i<max;i++){
		if(L1[i]!=0){
			aux.push(L1[i]);
			n++;
		}
	}
	for(int i=0;i<max;i++){
		if(L2[i]!=0){
			aux.push(L2[i]);
			n++;
		}
	}
	cout<<"Lista 1 y Lista 2 Unidas :D"<<endl;
	for(int i=0;i<n;i++){
		cout<<aux.front()<<" ";
		aux.pop();
	}
	cout<<endl;
}

void Copy_List(){
	int opc, temp;
	cout<<"Seleccione una opcion: "<<endl<<"1. Copiar Lista 1 y pegar en Lista 2"<<endl<<"2. Copiar Lista 2 y pegar en Lista 1"<<endl<<"Opcion: "; cin>>opc;
	if(opc==1){
		for(int i=0;i<max;i++){
			temp=L1[i];
			L2[i]=temp;
		}
		cout<<"Operacion realizada correctamente"<<endl;
	}
	else if(opc==2){
		for(int i=0;i<max;i++){
			temp=L2[i];
			L1[i]=temp;
		}
		cout<<"Operacion realizada correctamente"<<endl;
	}
	else{
		cout<<"No existe esta opcion, intente de nuevo"<<endl;
	}
}

void Change_List(){
	int aux;
	for(int i=0;i<max;i++){
		aux=L1[i];
		L1[i]=L2[i];
		L2[i]=aux;
	}
	cout<<"Listas intercambiadas correctamente"<<endl;	
}

void Common_Items(){
	int aux[20];
	int n=0;
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			if(L1[i]==L2[j]&&L1[i]!=0&&L2[j]!=0){
				aux[n]=L1[i];
				n++;
			}
		}
	}
	cout<<"Elementos en comun"<<endl;
	for(int i=0;i<n;i++){
		cout<<aux[i]<<endl;
	}
}

bool Equal_List(){
	int n=0;
	for(int i=0;i<max;i++){
		if(L1[i]==L2[i]){
			n++;
		}
		else{
			return false;
			break;
		}
	}
	if(n==max){
		return true;
	}
}

void show_ListsV2(){
	queue<int> aux;
	int n;
	for(int i=0;i<max;i++){
		if(L1[i]!=0&&L2[i]!=0){
			aux.push(L1[i]);
			n++;
			aux.push(L2[i]);
			n++;
		}
	}
	cout<<"Lista Intercalada"<<endl;
	for(int i=0;i<n;i++){
		cout<<aux.front()<<" ";
		aux.pop();
	}
	cout<<endl;
}

int main(){
	int opc;
	do{
		system("cls");
		cout<<"OPERACIONES CON LA LISTA"<<endl<<endl<<"1.Insetar Dato"<<endl<<"2.Eliminar Dato"<<endl<<"3.Lista Llena o Lista Vacia"<<endl<<"4.Mostrar Listas"<<endl<<"5.Unir las dos listas"<<endl<<"6.Copiar lista"<<endl<<"7.Intercambiar lista"<<endl<<"8.Elementos comunes"<<endl<<"9.Verificar similitud"<<endl<<"10.Intercalar elementos y mostrar"<<endl<<"11.Vaciar Listas"<<endl<<"12.Salir"<<endl<<endl<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
			system("cls");
			Insert();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 2:
			system("cls");
			Delete();
			cout<<"[ENTER PARA CONTINUAR]"; getch();	
			break;
			case 3:
			system("cls");
			Size_Tester();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 4:
			system("cls");
			Show_Lists();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 5:
			system("cls");
			Join_Lists();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 6:
			system("cls");
			Copy_List();
			cout<<"[ENTER PARA CONTINUAR]"; getch();	
			break;
			case 7:
			system("cls");
			Change_List();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 8:
			system("cls");
			Common_Items();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 9:
			system("cls");
			if(Equal_List()){
				cout<<"Las listas son iguales"<<endl;
			}
			else{
				cout<<"Las listas son diferentes"<<endl;
			}
			cout<<"[ENTER PARA CONTINUAR]"; getch();	
			break;
			case 10:
			system("cls");
			show_ListsV2();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 11:
			system("cls");
			Delete_Lists();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
		}
	}while(opc!=12);
	
	return 0;
	getch();
}
