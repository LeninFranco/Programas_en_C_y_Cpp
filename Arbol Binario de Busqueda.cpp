#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *izq;
	Nodo *der;
	Nodo *padre;
}*arbol=NULL, *arbolOrd=NULL;

//---------Funcíónes Insertar Nodo---------
Nodo *CreateNodo(int n, Nodo *padre){
	Nodo *nuevo = new Nodo();
	nuevo->dato=n;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	nuevo->padre=padre;
	return nuevo;
}

void Insertar(Nodo *&arbol, int n, Nodo *padre){
	if(arbol==NULL){
		Nodo *nuevo=CreateNodo(n,padre);
		arbol=nuevo;
	}
	else{
		if(n<arbol->dato){
			Insertar(arbol->izq,n,arbol);
		}
		else{
			Insertar(arbol->der,n,arbol);
		}
	}
}

//---------Funciónes de eliminacion---------

//Función para determinar el nodo más izquierdo (CASO ---> 2)
Nodo *minimo(Nodo *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izq) {//Si tiene hijo izq, busca la parte más izq posible
		return minimo(arbol->izq);
	}
	else {
		return arbol;//No tiene hijo izq, retorna el mismo árbol
	}
}

//Función para reemplazar 2 nodos (CASO---> 3)
void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
	if (arbol->padre) {
		if (arbol->dato == arbol->padre->izq->dato) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->dato == arbol->padre->der->dato) {
			arbol->padre->der = nuevoNodo;
		}
	}
	
	if (nuevoNodo) {
		nuevoNodo->padre = arbol->padre;//Su nuevo padre
	}

}

//Función para destruir un nodo		
void destruir(Nodo *nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;
	delete(nodo);
}


//Función para Eliminar el nodo encontrado 
void eliminarNodo(Nodo *nodoEliminar) {
	if (nodoEliminar->izq && nodoEliminar->der) {
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if (nodoEliminar->izq) {
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruir(nodoEliminar);
	}
	else if (nodoEliminar->der) {
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
	}
	else {//Caso de nodos Hojas  (CASO 1)
		reemplazar(nodoEliminar, NULL);
		destruir(nodoEliminar);
		 
	}
}

void eliminar(Nodo *arbol, int n){
	if (arbol == NULL) {
		return;
	}
	else if (n < arbol->dato) {//Dato a eliminar < valor del arbol actual
		eliminar(arbol->izq, n);//Busca por la izquierda
	}
	else if (n > arbol->dato) {
		eliminar(arbol->der, n);//Busca por la derecha
	}
	else {
		eliminarNodo(arbol);
		//arbol posición de nodo actual
	}
}

//---------Función Buscar Arbol---------
bool Search(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}else if(n<arbol->dato){
		return Search(arbol->izq,n);
	}
	else{
		return Search(arbol->der,n);
	}
}

//---------Función Mostrar Arbol---------
void Show(Nodo *&arbol,int contador){
	if(arbol==NULL){
		return;
	}
	else{
		Show(arbol->der,contador+1);
		for(int i=0;i<contador;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		Show(arbol->izq,contador+1);
	}
}

//****************Funciones de recorrido --> en Profundidad******************

void PreOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<"-";
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
}

void InOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		InOrden(arbol->izq);
		cout<<arbol->dato<<"-";
		InOrden(arbol->der);
	}
}

void PosOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		InOrden(arbol->izq);
		InOrden(arbol->der);
		cout<<arbol->dato<<"-";
	}
}

//---------Funcion para determinar el Mayor y el Menor---------

int Min(Nodo *arbol){
	if(arbol==NULL){
		return(NULL);
	}
	else if(arbol->izq==NULL){
		return(arbol->dato);
	}
	else{
		return(Min(arbol->izq));
	}
}

int Max(Nodo *arbol){
	if(arbol==NULL){
		return(NULL);
	}
	else if(arbol->der==NULL){
		return(arbol->dato);
	}
	else{
		return(Max(arbol->der));
	}
}

int main(){
	int dato, opc, n;
	bool eval;
	do{
		system("cls");
		cout<<"Menu Arbol Binario de Busqueda"<<endl;
		cout<<"1. Insetar nuevo elemento"<<endl;
		cout<<"2. Buscar un elemento"<<endl;
		cout<<"3. Eliminar Elemento"<<endl;
		cout<<"4. Mostrar arbol completo"<<endl;
		cout<<"5. Mostrar el elemento Mayor"<<endl;
		cout<<"6. Mostrar el elemento Menor"<<endl;
		cout<<"7. Mostrar recorridos"<<endl;
		cout<<"8. Crear arbol de ordenamiento ascendente"<<endl;
		cout<<"9. Salir"<<endl;
		cout<<"Opcion: "; cin>>opc;
		switch(opc){
			case 1: 
			cout<<"Ingrese el dato a insertar: "; cin>>dato;
			Insertar(arbol,dato,NULL);
			cout<<"Dato Insertado correctamente"<<endl;
			system("Pause");
			break;
			case 2:
			if(arbol==NULL){
				cout<<"El arbol esta vacio"<<endl;
				system("Pause");
			}
			else{
				cout<<"Ingrese el elemento a buscar: "; cin>>dato;
				eval=Search(arbol,dato);
				if(eval){
					cout<<"El elemento "<<dato<<" se encontro correctamente"<<endl;
					system("Pause");
				}
				else{
					cout<<"El elemento "<<dato<<" no se encontro correctamente"<<endl;
					system("Pause");
				}
			}
			break;
			case 3:
				if(arbol==NULL){
					cout<<"El arbol esta vacio"<<endl;
					system("Pause");
				}
				else{
					cout<<"Ingrese el dato a elimimar: "; cin>>dato;
					eliminar(arbol,dato);
					system("Pause");
				}
			break;
			case 4: 
				if(arbol==NULL){
					cout<<"El arbol esta vacio"<<endl;
					system("Pause");
				}
				else{
					Show(arbol,0);
					system("Pause");
				}
			break;
			case 5:
				if(arbol==NULL){
					cout<<"El arbol esta vacio"<<endl;
				}
				else{
					cout<<"El elemento Maximo del arbol es: "<<Max(arbol)<<endl;
				}
				system("Pause");
			break;
			case 6:
				if(arbol==NULL){
					cout<<"El arbol esta vacio"<<endl;
				}
				else{
					cout<<"El elemento Minimo del arbol es: "<<Min(arbol)<<endl;
				}
				system("Pause");
			break;
			case 7:
				if(arbol==NULL){
					cout<<"El arbol esta vacio"<<endl;
				}
				else{
					cout<<"Recorrido en PreOrden"<<endl;
					PreOrden(arbol);
					cout<<endl;
					cout<<"Recorrido en InOrden"<<endl;
					InOrden(arbol);
					cout<<endl;
					cout<<"Recorrido en PosOrden"<<endl;
					PosOrden(arbol);
					cout<<endl;
				}
				system("Pause");
			break;
			case 8:
				cout<<"Ingresar el numero de elementos a ordenar: "; cin>>n;
				int num[n];
				system("cls");
				for(int i=0;i<n;i++){
					cout<<"Numero "<<i+1<<" : "; cin>>num[i];
				}
				for(int i=0;i<n;i++){
					Insertar(arbolOrd,num[i],NULL);
				}
				cout<<"Datos sin ordenar"<<endl;
				for(int i=0;i<n;i++){
					cout<<num[i]<<"-";
				}
				cout<<endl<<"Datos ordenados"<<endl;
				InOrden(arbolOrd);
				cout<<endl;
				arbolOrd=NULL;
				system("Pause");
			break;
		}
	}while(opc!=9);
}
