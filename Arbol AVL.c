#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct nodo{
	int Dato;
	int High;
	struct nodo* Izq;
	struct nodo* Der;
}SubArbol;

void menu();
SubArbol *crearHijo(int Dato);
SubArbol *Insertar(SubArbol *Actual, int Dato);
SubArbol *Buscar(SubArbol *Actual, int Dato);
SubArbol *Eliminar(SubArbol *Actual, int Dato);
SubArbol *Sust(SubArbol *Actual, SubArbol *Remplazo);
SubArbol *BuskU(SubArbol *Actual);
SubArbol *BuskD(SubArbol *Actual);
SubArbol *Rot_Izq(SubArbol *Actual);
SubArbol *Rot_Der(SubArbol *Actual);
SubArbol *Rot_Dob_Izq(SubArbol *Actual);
SubArbol *Rot_Dob_Der(SubArbol *Actual);
void Pre(SubArbol *Actual);
void In(SubArbol *Actual);
void Post(SubArbol *Actual);
void Nodos(SubArbol *Actual, int *Dato);
void Display(SubArbol *Actual, int n);
int Update(SubArbol *Actual, int H);
int High(SubArbol *Actual);
int Max(int A, int B);


int main(){
	SubArbol *Raiz=NULL;
	int Op, Dato;
	do{
		do{
			system("cls");
			menu();
			scanf("%d", &Op);
		}while(Op<1 || Op>10);
		if(Op==1){
			printf("\nIngrese dato: ");
			scanf("%d", &Dato);
			Raiz = Insertar(Raiz, Dato);
		}
		else if(Op==2){
			printf("\nIndique dato: ");
			scanf("%d", &Dato);
			Raiz = Eliminar(Raiz, Dato);
		}
		else if(Op==3){
			printf("\nIndique dato: ");
			scanf("%d", &Dato);
			SubArbol *Aux = Buscar(Raiz, Dato);
			if(Aux == NULL) printf("\n\nDato no perteneciente al arbol.\n\n");
			else printf("\n\nEncontrado, %d es un dato perteneciente al arbol.\n\n", Dato);
		}
		else if(Op==4){
			SubArbol *Min = BuskD(Raiz);
			if(Min == NULL) printf("\n\nNo existe minimo.\n\n");
			else if(Raiz->Izq==NULL) printf("\n\nEl minimo es el nodo raiz. %d\n\n", Raiz->Dato);
			else printf("\n\nMinimo: %d\n\n", Min->Dato);	
		}
		else if(Op==5){
			SubArbol *Max = BuskU(Raiz);
			if(Max == NULL) printf("\n\nNo existe maximo.\n\n");
			else if(Raiz->Der==NULL) printf("\n\nEl Maximo es el nodo raiz. %d\n\n", Raiz->Dato);
			else printf("\n\nMaximo: %d\n\n", Max->Dato);	
		}
		else if(Op==6){
			printf("\n\nPre-Order: \n");
			Pre(Raiz);
			printf("\n\n");
			printf("In-Orden: \n");
			In(Raiz);
			printf("\n\n");
			printf("Post-Order: \n");
			Post(Raiz);
			printf("\n\n");
		}
		else if(Op==7){
			Dato = 0;
			Nodos(Raiz, &Dato);
			printf("\n\nNumero de nodos en el arbol: %d\n\n", Dato);
		}
		else if(Op==8){
			Dato = High(Raiz);
			printf("\n\nAltura del arbol: %d\n\n", Dato);
		}
		else if(Op==9){
			Dato=0;
			printf("\n\nArbol: \n\n");
			Display(Raiz, Dato);
		}
		system("Pause");
	}while(Op>0 && Op<10);
	free(Raiz);
	return 0;
}

void menu(){
	printf("\t\tMenu\n\n");
	printf("\t1.-Insertar elemento.\n");
	printf("\t2.-Eliminar elemento.\n");
	printf("\t3.-Buscar elemento.\n");
	printf("\t4.-Ver elemento minimo.\n");
	printf("\t5.-Ver elemento maximo.\n");
	printf("\t6.-Recorridos del arbol.\n");
	printf("\t7.-Numero de nodos en el arbol.\n");
	printf("\t8.-Altura del arbol.\n");
	printf("\t9.-Mostrar arbol.\n");
	printf("\t10.-Salir.\n\n");
	printf("Opcion: ");
}

void Pre(SubArbol *Actual){
	if(Actual != NULL) {
		printf("%d ", Actual->Dato);
		Pre(Actual->Izq);
		Pre(Actual->Der);
	}
}

void In(SubArbol *Actual){
	if(Actual != NULL) {
		In(Actual->Izq);
		printf("%d ", Actual->Dato);	
		In(Actual->Der);
	}
}

void Post(SubArbol *Actual){
	if(Actual != NULL) {	
		Post(Actual->Izq);
		Post(Actual->Der);
		printf("%d ", Actual->Dato);
	}
}

void Nodos(SubArbol *Actual, int *Dato){
	if(Actual != NULL) {
		Nodos(Actual->Izq, Dato);
		*Dato +=1;	
		Nodos(Actual->Der, Dato);
	}
}

int High(SubArbol *Actual){
	if(Actual == NULL ) return -1; 
	else return(Actual -> High);
}

int Max(int A, int B){
    return A>B? A:B;
}

void Display(SubArbol *Arbol, int n){
    if(Arbol==NULL) return;
	Display(Arbol->Der, n+1);
	int i;
    for(i=0; i<n; i++) printf("\t");
    printf("%d\n", Arbol->Dato);
    Display(Arbol->Izq, n+1);
}

SubArbol *crearHijo(int Dato){
	SubArbol *New = (SubArbol*)malloc(sizeof(SubArbol));
	if(New != NULL){
		New->Dato = Dato;
		New->High = 0;
		New->Der = NULL;
		New->Izq = NULL;
	}
	return New;
}

SubArbol *Buscar(SubArbol *Actual, int Dato){
	if(Actual==NULL || Actual->Dato==Dato) return Actual;
	else if(Dato<Actual->Dato) return Buscar(Actual->Izq, Dato);
	else return Buscar(Actual->Der, Dato);
}

SubArbol *BuskU(SubArbol *Actual){
	if(Actual == NULL || Actual->Der == NULL) return Actual;
	else return BuskU(Actual->Der);
}

SubArbol *BuskD(SubArbol *Actual){
	if(Actual == NULL || Actual->Izq == NULL) return Actual;
	else return BuskD(Actual->Izq);
}

SubArbol *Rot_Izq(SubArbol *Actual){
	SubArbol *Aux = Actual->Izq;
	Actual->Izq = Aux->Der; 
	Aux->Der = Actual;
	Actual->High = Max(High(Actual->Izq), High(Actual->Der)) + 1; 
	Aux->High = Max(High(Aux->Izq), High(Aux->Der)) + 1;
	return Aux;
}

SubArbol *Rot_Der(SubArbol *Actual){
	SubArbol *Aux = Actual->Der;
	Actual->Der = Aux->Izq; 
	Aux->Izq = Actual;
	Actual->High = Max(High(Actual->Izq), High(Actual->Der)) + 1; 
	Aux->High = Max(High(Aux->Izq), High(Aux->Der)) + 1;
	return Aux;
}

SubArbol *Rot_Dob_Izq(SubArbol *Actual){
	Actual->Izq = Rot_Der(Actual->Izq); 
	return Rot_Izq(Actual);
}

SubArbol *Rot_Dob_Der(SubArbol *Actual) {
	Actual->Der = Rot_Izq(Actual->Der); 
	return Rot_Der(Actual);
}

SubArbol *Insertar(SubArbol *Actual, int Dato){
	if(Actual == NULL){
		Actual = crearHijo(Dato);
		if (Actual == NULL) printf("\nError, no se puede agregar nodo.\n");
	}
	else if(Dato<Actual->Dato) {
		Actual->Izq = Insertar(Actual->Izq, Dato);
		if(High(Actual->Der) - High(Actual->Izq) == -2) 
		if(Dato<Actual->Izq->Dato) Actual = Rot_Izq(Actual);
		else Actual = Rot_Dob_Izq(Actual);
	}
	else if(Dato>Actual->Dato) {
		Actual->Der = Insertar(Actual->Der, Dato);
		if(High(Actual->Der) - High(Actual->Izq) == 2) 
		if(Dato>Actual->Der->Dato) Actual = Rot_Der(Actual);
		else Actual = Rot_Dob_Der(Actual);
	}
	Actual->High = Max(High(Actual->Izq), High(Actual->Der)) + 1;
	return Actual;
}

SubArbol *Sust(SubArbol *Actual, SubArbol *Remplazo){
	if (Remplazo->Izq != NULL) Remplazo->Izq = Sust(Actual, Remplazo->Izq);
	else{
		SubArbol *Trash = Remplazo;
		Actual->Dato = Remplazo->Dato;
		Remplazo = Remplazo->Der;
		free(Trash);
	}
	return Remplazo;
}

int Update(SubArbol *Actual, int H){
	int L=0; 
	int R=0;
	if(Actual != NULL){
		if(Actual->Izq!=NULL) L = Update(Actual->Izq, H+1);
		else if (Actual->Der==NULL) return H;
		if(Actual->Der!=NULL) R = Update(Actual->Der, H+1);	
		else if (Actual->Izq==NULL) return H;
	}
	return Max(L, R);
}

SubArbol *Eliminar(SubArbol *Actual, int Dato){
	if(Actual == NULL);
	else if(Dato<Actual->Dato) {
		Actual->Izq = Eliminar(Actual->Izq, Dato);
		if(High(Actual->Der) - High(Actual->Izq) == 2) {
			if(High(Actual->Der->Der) - High(Actual->Der->Izq)>0) Actual = Rot_Der(Actual);	
			else Actual = Rot_Dob_Der(Actual);
		}
	}
	else if(Dato>Actual->Dato) {
		Actual->Der = Eliminar(Actual->Der, Dato);
		if(High(Actual->Der) - High(Actual->Izq) == -2) {
			if(High(Actual->Izq->Der) - High(Actual->Izq->Izq)<0) Actual = Rot_Izq(Actual);
			else Actual = Rot_Dob_Izq(Actual);	
		}
	}
	else{
			SubArbol *Temp = Actual;
			if(Actual->Der==NULL) {
				Actual = Actual->Izq;	
				free(Temp);
			}
			else if(Actual->Izq==NULL) {
				Actual = Actual->Der;	
				free(Temp);
			}
			else Actual->Der = Sust(Temp, Temp->Der);
	}
	if(Actual != NULL) Actual->High = Update(Actual, 0);
	return Actual;
}
