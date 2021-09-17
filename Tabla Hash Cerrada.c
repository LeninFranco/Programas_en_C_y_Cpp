#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 10

typedef struct {
	char name[256];
	int age;
}person;

person *hash_table[size];//Se crea un arreglo de estructuras de tipo apuntador

unsigned int hash(int age){
	unsigned int hash_value=age%size;
	return hash_value;
}//Funcion de dispersion;

void Create_Table(){
	int i;
	for(i=0;i<size;i++){
		hash_table[i]=NULL;
	}
}

void Insert_Hash(person *p){
	int band=0, i;
	int index=hash(p->age);
	if(hash_table[index]==NULL){
		hash_table[index]=p;
	}
	else{
		for(i=index;i<size;i++){
			if(hash_table[i]==NULL){
				hash_table[i]=p;
				band=1;
				break;
			}
		}
		if(band==0){
			for(i=index;i>=0;i--){
				if(hash_table[i]==NULL){
				hash_table[i]=p;
				band=1;
				break;
				}	
			}
		}
	}
}

void Show_Table(){
	int i;
	for(i=0;i<size;i++){
		if(hash_table[i]==NULL){
			printf("%d ------------------\n", i);
		}
		else{
			printf("%d Nombre: %s Edad: %d\n", i, hash_table[i]->name, hash_table[i]->age);
		}
	}
}

void Search(int age){
	int i, band=0;
	for(i=0;i<size;i++){
		if(hash_table[i]==NULL){
			continue;
		}
		else if(age==hash_table[i]->age){
			printf("El dato ha sido encontrado satisfactoriamente\n");
			printf("%d Nombre: %s Edad: %d\n", i, hash_table[i]->name, hash_table[i]->age);
			band=1;
			break;
		}
	}
	if(band==0){
		printf("No se ha encontrado el dato joven\n");
	}
}

int main(){
	person p[10];
	int r=0;
	int opc, age;
	do{
		system("cls");
		printf("MENU\n1.Insertar dato\n2.Buscar dato\n3.Mostrar Tabla Hash\n4.Salir\nOpcion: "); scanf("%d", &opc);
		switch(opc){
			case 1:
			if(r<10){
				fflush(stdin);
				printf("Ingrese el nombre: "); gets(p[r].name);
				printf("Ingrese la edad: "); scanf("%d", &p[r].age);
				Insert_Hash(&p[r]);	
				r++;
				printf("Dato ingresado correctamente\n");
			}
			else{
				printf("La tabla esta llena joven\n");
			}
			system("Pause");
			break;
			case 2:
			printf("Inserte la edad de la persona a buscar: "); scanf("%d", &age);
			Search(age);
			system("Pause");
			break;
			case 3:
			Show_Table();
			system("Pause");	
			break;
		}
	}while(opc!=4);
}
