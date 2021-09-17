#include <stdio.h>
#include <stdlib.h>
struct registro{
	char titulo[30];
	char editorial[20];
	char formato[10];
	int precio;
}comic[5];

int main(){
	int i;
	for(i=1;i<6;i++){
		system("cls");
		fflush(stdin);
		printf("Registro %d\n", i);
		printf("Nombre del comic: ");
		gets(comic[i].titulo); 
		printf("Editorial: "); 
		gets(comic[i].editorial); 
		printf("Formato del comic: "); 
		gets(comic[i].formato); 
		printf("Precio de portada: $"); 
		scanf("%d", &comic[i].precio);
	}
	system("cls");
	printf("Mostrando Registro\n");
	for(i=1;i<6;i++){
		printf("-------------------------------------------------\n");
		printf("Registro %d\n", i);
		printf("Nombre del comic: %s\n", comic[i].titulo);
		printf("Editorial: %s\n", comic[i].editorial);
		printf("Formato del comic: %s\n", comic[i].formato);
		printf("Precio de portada: $%d\n", comic[i].precio);
		printf("-------------------------------------------------\n");
	}
	return 0;
}
