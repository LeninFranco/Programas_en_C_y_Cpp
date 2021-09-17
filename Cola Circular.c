#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define max 10

// 0 1 2 3 4 5 6 7 8 9
// 3   5 5 6 9 2 5 6 7 
//inicio 2
//final 0

// 0 1 2 3 4 5 6 7 8 9
//     5 5 6 9 2 5 6 7 
//inicio 2
//final 9

typedef struct{
	int front;
	int rear;
	int vector[max];
}queve;

void CreateQueve(queve *q){
	q->front=-1;
	q->rear=-1;
}

int IsEmpty(queve *q){
	if(q->rear==-1){
		return 1;
	}
	else{
		return 0;
	}
	
}

int Elements(queve *q){
	if(IsEmpty(q)){
		return 0;
	}
	else{
		if(q->front<=q->rear){
			return q->rear-q->front+1;
		}
		else{
			return max-q->front+q->rear+1;
		}
	}
}

int IsFull(queve *q){
	if(Elements(q)==max){
		return 1;
	}
	else{
		return 0;
	}
}

void Insert(queve *q, int n){
	if(!IsFull(q)){
		if(IsEmpty(q)){
			q->front=0;
		}
		if(q->rear==max-1){
			q->rear=0;
		}
		else{
			q->rear++;	
		}
		q->vector[q->rear]=n;
		printf("Se ha agregado el elemento correctamente\n");
		printf("[ENTER PARA CONTINUAR]"); getch();
	}
	else{
		printf("La cola esta llena UwU\n");
		printf("[ENTER PARA CONTINUAR]"); getch();
	}
}

void Delete(queve *q){
	if(!IsEmpty(q)){
		int temp = q->vector[q->front];
		if(Elements(q)== 1){
			CreateQueve(q);
		}
		else{
			q->front++;
		}
		printf("El elemento %d ha sido eliminado\n", temp);
		printf("[ENTER PARA CONTINUAR]"); getch();
	}else{
		printf("La cola esta vacia UwU\n");
		printf("[ENTER PARA CONTINUAR]"); getch();
	}
}

int main(){
	queve q;
	int opc, n;
	CreateQueve(&q);
	printf("Se ha creado la cola correctamente :D\n");
	printf("[ENTER PARA CONTINUAR]"); getch();
	do{
		system("cls");
		printf("Seleccione la operacion que desea realizar\n1.Insertar elemento\n2.Eliminar elemento\n3.Salir\n\nOpcion: ");
		scanf("%d", &opc);
		switch(opc){
			case 1:
			printf("Ingrese el elemento: ");
			scanf("%d", &n);
			Insert(&q,n);
			break;
			case 2:
			Delete(&q);
			break;
		}
	}while(opc!=3);
	return 0;
	getch();
}
