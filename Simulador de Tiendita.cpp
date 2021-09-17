#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;


struct Articulos{
	int ID;
	string Nombre;
	float Precio;
	int Cantidad;
}art, Ven;

struct Nodo{
	Articulos Dato;
	Nodo *sig;
}*frente, *ultimo;

void Menu(int &opc){
	cout<<"************MENU DE LA CAJA************"<<endl;
	cout<<"* 1. Agregar Articulo Nuevo           *"<<endl;
	cout<<"* 2. Eliminar Articulo                *"<<endl;
	cout<<"* 3. Buscar Articulo                  *"<<endl;
	cout<<"* 4. Desplegar la lista de articulos  *"<<endl;
	cout<<"* 5. Registrar Venta                  *"<<endl;
	cout<<"* 6. Desplegar archivo de facturas    *"<<endl;
	cout<<"* 7. Salir                            *"<<endl;
	cout<<"***************************************"<<endl<<endl;
	cout<<"Opcion: "; cin>>opc;
}

void Insert(Articulos art){
	Nodo *nuevo=new Nodo();
	nuevo->Dato=art;
	if(frente==NULL){
		frente=nuevo;
		frente->sig=NULL;
		ultimo=nuevo;
	}
	else{
		ultimo->sig=nuevo;
		nuevo->sig=NULL;
		ultimo=nuevo;
	}
	cout<<"Se ha agredado el articulo correctamente"<<endl;
}

void Delete(int Ide){
	Nodo *aux=new Nodo();
	Nodo *ant=new Nodo();
	ant=NULL;
	aux=frente;
	bool encontrado=false;
	if(frente!=NULL){
		while(aux!=NULL){
			if(aux->Dato.ID==Ide){
				encontrado=true;
				if(aux==frente){
					frente=frente->sig;
				}
				else if(aux==ultimo){
					ant->sig=NULL;
					ultimo=ant;
				}
				else{
					ant->sig=aux->sig;	
				}
			}
			ant=aux;
			aux=aux->sig;
		}
		if(!encontrado){
			cout<<"No se encontro el articulo en el registro"<<endl;
		}
	}
	else{
		cout<<"No hay ningun articulo en el registro"<<endl;
	}
}

void Search(int Ide){
	Nodo *aux=new Nodo();
	aux=frente;
	bool encontrado=false;
	if(frente!=NULL){
		while(aux!=NULL){
			if(aux->Dato.ID==Ide){
				encontrado=true;
				cout<<"Se ha encontrado el articulo correctamente"<<endl;
				cout<<"-----------------------------------------------------"<<endl;
				cout<<"ID: "<<aux->Dato.ID<<endl;
				cout<<"Articulo: "<<aux->Dato.Nombre<<endl;
				cout<<"Precio unitario: $"<<aux->Dato.Precio<<endl;
				cout<<"Unidades en existencia: "<<aux->Dato.Cantidad<<endl;
				cout<<"-----------------------------------------------------"<<endl;
			}
			aux=aux->sig;
		}
		if(!encontrado){
			cout<<"No se encontro el articulo en el registro, las posibles razones son: "<<endl;
			cout<<"a) Usted lo elimino manualmente"<<endl;
			cout<<"b) Se elimino de manera automatica por haberse acabado la existencia"<<endl;
		}
	}
	else{
		cout<<"No hay ningun articulo en el registro"<<endl;
	}
}

void Show(){
	Nodo *aux=new Nodo();
	aux=frente;
	if(frente!=NULL){
		while(aux!=NULL){
			cout<<"-----------------------------------------------------"<<endl;
			cout<<"ID: "<<aux->Dato.ID<<endl;
			cout<<"Articulo: "<<aux->Dato.Nombre<<endl;
			cout<<"Precio unitario: $"<<aux->Dato.Precio<<endl;
			cout<<"Unidades en existencia: "<<aux->Dato.Cantidad<<endl;
			cout<<"-----------------------------------------------------"<<endl;
			aux=aux->sig;
		}
	}
	else{
		cout<<"No hay ningun articulo en el registro"<<endl;
	}
}

void Add(Articulos &art){
	cout<<"Ingrese el ID del articulo: "; cin>>art.ID;
	fflush(stdin);
	cout<<"Ingrese el nombre del articulo: "; getline(cin,art.Nombre);
	cout<<"Ingrese el precio del articulo: $"; cin>>art.Precio;
	cout<<"Ingrese la cantidad de unidades del articulo: "; cin>>art.Cantidad;
	Insert(art);
}

void Registro_Venta(float Pago){
	ofstream archive;
	archive.open("Ventas.txt",ios::app);
	if(archive.fail()){
		cout<<"No se pudo abrir el archivo de ventas"<<endl;
	}
	else{
		archive<<"--------------------------------------------------"<<endl;
		archive<<"ID: "<<Ven.ID<<endl;
		archive<<"Articulo: "<<Ven.Nombre<<endl;
		archive<<"Precio unitario: $"<<Ven.Precio<<endl;
		archive<<"Total del Pago: $"<<Pago<<endl;
		archive<<"--------------------------------------------------"<<endl;
	}
	archive.close();
}

void Ver_Registro(){
	ifstream archive;
	string text;
	archive.open("Ventas.txt",ios::in);
	if(archive.fail()){
		cout<<"No se pudo abrir el archivo de ventas"<<endl;
	}
	else{
		while(!archive.eof()){
		getline(archive,text);
		cout<<text<<endl;
		}
	}
	archive.close();
}

void Venta(int Ide){
	int cant=0;
	float pago=0;
	Nodo *aux=new Nodo();
	aux=frente;
	bool encontrado=false;
	if(frente!=NULL){
		while(aux!=NULL){
			if(aux->Dato.ID==Ide){
				encontrado=true;
				if(aux->Dato.Cantidad==0){
					Delete(aux->Dato.ID);
					cout<<"El articulo ha sido eliminado porque ya no hay existencias"<<endl;
				}
				else{
					cout<<"-----------------------------------------------------"<<endl;
					cout<<"ID: "<<aux->Dato.ID<<endl;
					cout<<"Articulo: "<<aux->Dato.Nombre<<endl;
					cout<<"Precio unitario: $"<<aux->Dato.Precio<<endl;
					cout<<"-----------------------------------------------------"<<endl;
					cout<<"Cantidad de unidades a vender: "; cin>>cant;
					if(cant>aux->Dato.Cantidad){
						cout<<"La cantidad que desea vender es mayor de lo que hay disponible"<<endl;
						cout<<"Favor de volver intertarlo"<<endl;
					}else{
						pago=(aux->Dato.Precio)*cant;
						aux->Dato.Cantidad=aux->Dato.Cantidad-cant;
						cout<<"Precio a pagar es: $"<<pago<<endl;
						Ven.ID=aux->Dato.ID;
						Ven.Nombre=aux->Dato.Nombre;
						Ven.Precio=aux->Dato.Precio;
						Ven.Cantidad=cant;
						Registro_Venta(pago);
					}
				}
			}
			aux=aux->sig;
		}
		if(!encontrado){
			cout<<"No se encontro el articulo en el registro, las posibles razones son: "<<endl;
			cout<<"a) Usted lo elimino manualmente"<<endl;
			cout<<"b) Se elimino de manera automatica por haberse acabado la existencia"<<endl;
		}
	}
	else{
		cout<<"No hay ningun articulo en el registro"<<endl;
	}
}


int main(){
	int opc, Ide;
	do{
		system("cls");
		Menu(opc);
		switch(opc){
			case 1:
			system("cls");
			Add(art);
			system("Pause");
			break;
			case 2:
			cout<<"Ingrese el ID del producto a eliminar: "; cin>>Ide;
			Delete(Ide);
			system("Pause");	
			break;
			case 3:
			system("cls");
			cout<<"Ingrese el ID del producto a buscar: "; cin>>Ide;
			Search(Ide);
			system("Pause");	
			break;
			case 4:
			system("cls");
			Show();
			system("Pause");	
			break;
			case 5:
			system("cls");
			cout<<"Ingrese el ID del producto a vender: "; cin>>Ide;
			Venta(Ide);
			system("Pause");	
			break;
			case 6: 
			system("cls");
			Ver_Registro();
			system("Pause");
			break;
		}
	}while(opc!=7);
	return 0;
}
