#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <queue>
#define max 10

using namespace std;

int array[max];

bool FullList_T(){
	int n=0;
	for(int i=0;i<max;i++){
		if(array[i]!=0){
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
bool EmptyList_T(){
	int n=0;
	for(int i=0;i<max;i++){
		if(array[i]==0){
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
void FullList(){
	if(FullList_T()){
		cout<<"La lista esta llena"<<endl;
	}
	else{
		cout<<"La lista no esta llena"<<endl;
	}
}
void EmptyList(){
	if(EmptyList_T()){
		cout<<"La Lista esta vacia"<<endl;
	}
	else{
		cout<<"La Lista no esta vacia"<<endl;
	}
}
void Insert(){
	int dato, pos;
	if(FullList_T()){
		cout<<"La Lista esta llena"<<endl;
	}
	else{
		cout<<"Ingrese el Dato: "; cin>>dato;
		cout<<"Ingrese la Posicion: "; cin>>pos;
		pos--;
		for(int i=max-1;i>=pos;i--){
			array[i+1]=array[i];
			if(pos==i){
				array[pos]=dato;
			}
		}
		cout<<"El Dato ha sido guardado correctamente"<<endl;
	}
}
void Delete(){
	int pos, temp;
	if(EmptyList_T()){
		cout<<"La Lista esta vacia"<<endl;
	}
	else{
		cout<<"Ingrese la posicion: "; cin>>pos;
		pos--;
		temp=array[pos];
		for(int i=pos;i<max;i++){
			array[i]=array[i+1];
		}
		cout<<"Se ha eliminado el dato "<<temp<<" correctamente"<<endl;
	}
	
}
void SortList_Desc(){
	if(EmptyList_T()){
		cout<<"La lista esta vacia"<<endl;
	}
	else{
		int n=0;
		priority_queue<int> QPrior;
		for(int i=0;i<max;i++){
				if(array[i]!=0){
				QPrior.push(array[i]);
				n++;
				}
		}
		for(int i=0;i<n;i++){
			array[i]=QPrior.top();
			QPrior.pop();
		}
		cout<<"Operacion realizada correctamente"<<endl;
	}
}
void SortList_Asc(){
	if(EmptyList_T()){
		cout<<"La lista esta vacia"<<endl;
	}
	else{
		int n=0;
		priority_queue<int, deque<int>, greater<int> > QPrior;
		for(int i=0;i<max;i++){
				if(array[i]!=0){
				QPrior.push(array[i]);
				n++;
				}
		}
		for(int i=0;i<n;i++){
			array[i]=QPrior.top();
			QPrior.pop();
		}
		cout<<"Operacion realizada correctamente"<<endl;
	}
}
void DeleteList(){
	for(int i=0;i<max;i++){
		array[i]=NULL;
	}
	cout<<"La Lista se ha vaciado correctamente"<<endl;
}
void SearchList_Element(){
	int dato;
	cout<<"Ingrese el elemento a buscar: "; cin>>dato;
	for(int i=0;i<max;i++){
		if(array[i]==dato){
			cout<<"El dato se ha encontrado en la posicion: "<<i+1<<endl;
			break;
		}
		else{
			if(i==max-1){
				cout<<"No hubo resultados en la busqueda"<<endl;
			}
		}
	}	
}
void SearhList_Position(){
	int pos,posprint;
	cout<<"Ingrese la posicion: "; cin>>pos;
	posprint=pos;
	pos--;
	if(array[pos]==0){
		cout<<"No hay ningun elemento en esta posicion"<<endl;
	}
	else{
		cout<<"En la posicion "<<posprint<<" esta el elemento "<<array[pos]<<endl;
	}
}
void ShowList(){
	for(int i=0;i<max;i++){
		if(array[i]==0){
			cout<<"0"<<endl;
		}
		else{
			cout<<array[i]<<endl;
		}
	}
}

int main(){
	int opc;
	do{
		system("cls");
		cout<<"OPERACIONES CON LA LISTA"<<endl<<endl<<"1.Insetar Dato"<<endl<<"2.Eliminar Dato"<<endl<<"3.Lista Llena"<<endl<<"4.Lista Vacia"<<endl<<"5.Ordenar Lista(Descendente)"<<endl<<"6.Ordenar Lista(Ascendente)"<<endl<<"7.Vaciar Lista"<<endl<<"8.Buscar por Elemento"<<endl<<"9.Buscar por Posicion"<<endl<<"10.Mostrar Lista"<<endl<<"11.Salir"<<endl<<endl<<"Opcion: ";
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
			FullList();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 4:
			system("cls");
			EmptyList();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 5:
			system("cls");
			SortList_Desc();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 6:
			system("cls");
			SortList_Asc();
			cout<<"[ENTER PARA CONTINUAR]"; getch();	
			break;
			case 7:
			system("cls");
			DeleteList();
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 8:
			system("cls");
			SearchList_Element();	
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
			case 9:
			system("cls");
			SearhList_Position();
			cout<<"[ENTER PARA CONTINUAR]"; getch();	
			break;
			case 10:
			system("cls");
			ShowList();	
			cout<<"[ENTER PARA CONTINUAR]"; getch();
			break;
		}
	}while(opc!=11);
	
	return 0;
	getch();
}
