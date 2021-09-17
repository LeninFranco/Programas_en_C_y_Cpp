#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Tam 40

typedef struct stack{
	char Dato[Tam];
	int Top;
}Stack;

typedef struct nodo{
	char Dato;
	struct nodo* Izq;
	struct nodo* Der;
}SubArbol;

typedef struct node{
	SubArbol *Expre;
	struct node *Prev;
}NodE;

typedef struct pile{
	NodE *Top;
	int Total;
}PilE;

NodE *crearNode(SubArbol* Elem);
void Pref(SubArbol *Actual);
void In(SubArbol *Actual);
void Post(SubArbol *Actual);
void Display(SubArbol *Actual, int n);
int NPref(Stack *A, char *Intra, char *Pre);
SubArbol *crearHijo(char Elem);
SubArbol *Insertar(char *Pre, PilE *H, int Pos);

int main(){
	do{
		int i;
		system("cls");
		char Intra[Tam]="\0";
		char Pre[Tam]="\0";
		Stack A;
		PilE H;
		A.Top=0;
		H.Total=0;
		H.Top=NULL;
		printf("\tArbol de expresiones.\n\n");
		printf("Operandos validos simples: [A-Z], [a-z], [1-9].\n\n");
		printf("Operadores binarios validos: [+], [-], [*], [/], [^].\n\n\n");
		printf("Ingrese la expresion: ");
		scanf("%s", Intra);
		i=NPref(&A, Intra, Pre);
		if (i){
			printf("\n\nArbol de expresion: \n\n", Pre);
			SubArbol *Raiz = Insertar(Pre, &H, 0);
			Display(Raiz, 0);
			printf("\n\nNotacion prefija: \n");
			Pref(Raiz);
			printf("\n\n");
			printf("\n\n");
			printf("Notacion postfija: \n");
			Post(Raiz);
			printf("\n\n");
		}
		printf("\n\n");
		system("PAUSE");
	}while(1);
	return 0;
}

int NPref(Stack *A, char *Intra, char *Pre){
	int i;
	int PosP=0;
	int Part=0;
	int Ord=1;
	int Cop=0;
	int Cap=0;
	for(i=strlen(Intra)-1;i>-1;i--){
		if(isalnum(Intra[i])){
			Pre[PosP++]=Intra[i];
			Cop++;
		}
		else if(Intra[i] == ')'){ 
			Part++;
			Ord = 0;
			A->Dato[A->Top++] = ')';
		}
		else if(Intra[i] == '('){
			Part--;
			Ord=1;
			while(A->Dato[--A->Top] != ')' && A->Top>0) Pre[PosP++] = A->Dato[A->Top];
		}
		else if(Intra[i] == '+'||Intra[i] == '-'){
			while((A->Dato[A->Top-1] == '*'||A->Dato[A->Top-1] == '/'||A->Dato[A->Top-1] == '^') && A->Top>0) Pre[PosP++] = A->Dato[--A->Top];
			A->Dato[A->Top++] = Intra[i];
			Cap++;
		}
		else if(Intra[i] == '*'||Intra[i] == '/'){
			while((A->Dato[A->Top-1] == '^') && A->Top>0) Pre[PosP++] = A->Dato[--A->Top];
			A->Dato[A->Top++] = Intra[i];
			Cap++;
		}
		else if(Intra[i] == '^'){
			A->Dato[A->Top++] = Intra[i];
			Cap++;
		}
		else break;
		if(i>0 && Intra[i] != '(' && Intra[i] != ')' && isalnum(Intra[i]) && isalnum(Intra[i-1])) break;
		else if((Intra[i] == '(' && Intra[i+1] != '(' && (isalnum(Intra[i-1])||!(isalnum(Intra[i+1]))))||(Intra[i] == ')' && Intra[i-1] != ')' && (isalnum(Intra[i+1])||!(isalnum(Intra[i-1]))))) break;
	}
	while(A->Top>0) Pre[PosP++] = A->Dato[--A->Top];
	if(Part != 0 || Ord==0 || i>-1 || Cap!=Cop-1) {
		printf ("\nExpresion no valida.");
		PosP=strlen(Pre);
		for(i=0;i<PosP;i++) Pre[i]='\0';
		return 0;
	}
	return 1;	
}

void Pref(SubArbol *Actual){
	if(Actual != NULL) {
		printf("%c", Actual->Dato);
		Pref(Actual->Izq);
		Pref(Actual->Der);
	}
}

void Post(SubArbol *Actual){
	if(Actual != NULL) {	
		Post(Actual->Izq);
		Post(Actual->Der);
		printf("%c", Actual->Dato);
	}
}

void Display(SubArbol *Arbol, int n){
    if(Arbol==NULL) return;
	Display(Arbol->Der, n+1);
	int i;
    for(i=0; i<n; i++) printf("\t");
    printf("%c\n", Arbol->Dato);
    Display(Arbol->Izq, n+1);
}


SubArbol *crearHijo(char Elem){
	SubArbol *New = (SubArbol*)malloc(sizeof(SubArbol));
	if(New != NULL){
		New->Dato = Elem;
		New->Der = NULL;
		New->Izq = NULL;
	}
	return New;
}

NodE *crearNode(SubArbol* Elem){
	NodE *New = (NodE*)malloc(sizeof(NodE));
	if(New != NULL){
		New->Expre = Elem;
		New->Prev = NULL;
	}
	return New;
}

SubArbol *Insertar(char *Pre, PilE *H, int Pos){
	if(Pos<strlen(Pre)){
		if(isalnum(Pre[Pos])){
			NodE *New = crearNode(crearHijo(Pre[Pos]));
			New->Prev=H->Top;
			H->Top=New;
			++H->Total;
		}
		else{
			if(H->Total>1){
				SubArbol *New = crearHijo(Pre[Pos]);
				NodE *Aux = H->Top;
				New->Izq = H->Top->Expre;
				New->Der = H->Top->Prev->Expre;
				NodE *Act = crearNode(New);
				Act->Prev = H->Top->Prev->Prev;
				H->Top = Act;
				free(Aux);
				H->Total-=1;
			}
		}
		Insertar(Pre, H, ++Pos);
	}
	return H->Top->Expre;
};
