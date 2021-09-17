#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "string.h"
#include "time.h"
#include "conio.h"
#include "windows.h"


typedef struct vuelo{
	char destination[15];
	char company[15];
	char departureTime[6];
	int passengers;
}vuelo;

typedef struct tiempo{
	int hora;
	int minutos;
}tiempo;

vuelo NewFlight(){
	system("cls");
	char destino[15];
	char compania[15];
	char tiempoDePartida[15];
	int pasajeros;
	vuelo flight;
	printf("Registro del proximo vuelo\n");
	printf("Destino: ");
	scanf("%s", &destino);
	printf("Aerolinea: ");
	scanf("%s", &compania);
	printf("Hora de Salida (formato XX:XX): ");
	scanf("%s", &tiempoDePartida);
	printf("Numero de pasajeros: ");
	scanf("%d", &pasajeros);
	
	strcpy(flight.destination,destino);
	strcpy(flight.company,compania);
	strcpy(flight.departureTime,tiempoDePartida);
	flight.passengers=pasajeros;
	system("cls");
	
	return flight;
}

/*Transforma el formato cadena del tiempo a formato time formado por dos enteros*/
tiempo TransfTime(char* Strtime){
	tiempo time;
	int hora,minutos;
	int i;
	int num;
	
	for(i=0;i<2;i++){
		num=Strtime[i] - '0';
		if(i==0){
			hora=num*10;
		}
		else if(i==1){
			hora=hora+num;
		}
	}
	for(i=3;i<5;i++){
		num=Strtime[i] - '0';
		if(i==3){
			minutos=num*10;
		}
		else if(i==4){
			minutos=minutos+num;
		}
	}
	time.hora=hora;
	time.minutos=minutos;
	
	return time;
}

/*Regresa la posicion en que debe de insertar el vuelo (0,1,...,n)*/
int CmpTime(vuelo* vuelos, vuelo v){
	tiempo tiempoVuelo, tiempoVueloVar;
	char timeVar[6];
	int posicion,i;
	
	tiempoVuelo=TransfTime(v.departureTime);
	for(i=0;i<10;i++){
		strcpy(timeVar,(vuelos[i]).departureTime);
		tiempoVueloVar=TransfTime(timeVar);
		
		if(tiempoVuelo.hora<tiempoVueloVar.hora){
			posicion=i;
			return posicion;
		}
		
		else if(tiempoVuelo.hora==tiempoVueloVar.hora){
			if(tiempoVuelo.minutos<=tiempoVueloVar.minutos){
				posicion=i;
				return posicion;
			}
		}
	}
}


void Registrar(vuelo* vuelos){
	vuelo flight=NewFlight();
	int posicion,i;
	vuelo aux1, aux2;
	
	posicion = CmpTime(vuelos, flight);
	aux1=flight;
	
	printf("Vuelo Numero: %d\n", posicion);
	
	for(i=posicion;i<10;i++){
		aux2=vuelos[i];
		vuelos[i]=aux1;
		aux1=aux2;
	}
	vuelos[10]=aux1;
}

void Show(vuelo* v){
	int i;
	
	for(i=0;i<10;i++){
		if((v[i]).passengers==0)
			break;
		printf("\n--------------------------");
		printf("\n->Vuelo numero %d<-\n",i+1);
		printf("->Destino: %s<-\n",(v[i]).destination);
		printf("->Aerolinea: %s<-\n",(v[i]).company);
		printf("->Hora de salida: %s<-\n",(v[i]).departureTime);
		printf("->Numeros Pasajeros: %d<-\n",(v[i]).passengers);
		printf("--------------------------");
	}
}

void Delete(vuelo* v, int indice){
	int posindice;
	indice--;
	while(indice<10){
		posindice=indice+1;
		v[indice]=v[posindice];
		indice++;
	}
}



void CompruebaTime(vuelo* vuelos, struct tm* mitiempo){
	char timeVar[6];
	tiempo tiempoVueloVar;
	int i,j;
	
	//Es decir preguntamos si no hay ningun vuelo registrado
	if(vuelos[0].passengers==0){
		printf("\nNingun vuelo ha sido registrado\n");
		return;
	}
	else{
		Show(vuelos);
		for(i=0;i<10;i++){
			strcpy(timeVar,(vuelos[i]).departureTime);
			tiempoVueloVar=TransfTime(timeVar);
			if(tiempoVueloVar.hora <= mitiempo->tm_hour){
				if(tiempoVueloVar.minutos <= mitiempo->tm_min){
					system("CLS");
					printf("**********¡ATENCION!**********\n");
					printf("El vuelo con destino a %s esta saliendo\n", (vuelos[i]).destination);
					printf("******************************\n");
					//Retardo de 3 segundos
					for(j = 3; j >= 0; j--){
						Sleep(1000);
					}
					Delete(vuelos, 0);
				}
				else
					return;
			}
			else
				return;
		}
	}
}

vuelo NewFlight();
void Registrar(vuelo*);
void Show(vuelo*);
void Delete(vuelo*, int indice);
int CmpTime(vuelo*, vuelo);
tiempo TransfTime(char* Strtime);
void CompruebaTime(vuelo*, struct tm*); //Esta funcion comprueba que ningun vuelo salga en este momento

int main(){
	vuelo vuelos[10];
	int opc, menusel;
	int i,j;
	time_t tiempoahora;
	int indice;
	
	menusel=0;
	
	//Inicializamos
	for(i=0;i<10;i++){
		strcpy((vuelos[i]).destination,"");
		strcpy((vuelos[i]).company,"");
		strcpy((vuelos[i]).departureTime,"23:59");
		(vuelos[i]).passengers=0;
	}
	
	do{
		system("CLS");
		time(&tiempoahora);
		struct tm *mitiempo = localtime(&tiempoahora);
		printf("*************************************Aerolineas Mexico*************************************\n\n");
		printf("Hora actual -> %d:%d",mitiempo->tm_hour,mitiempo->tm_min);
		CompruebaTime(vuelos, mitiempo);
		printf("\n********************************************************************************************\n");
		printf("Para ingresar al menu, presione el numero 1, en caso de salir del programa presione 2\n Opcion: ");
		
		//Delay de 250ms segundo
		Sleep(250);
		
		if (kbhit()){ //Esta funcion regresa 1 si detecta que se oprime una tecla
			scanf("%d", &menusel);
		}
		
		if(menusel==1){
			system("CLS");
			printf("\n********** MENU **********\n\n");
			printf("1.Registrar un nuevo vuelo\n");
			printf("2.Cancelar un vuelo\n");
			printf("\n**************************\n\n");
			printf("Escoja una opcion: ");
			scanf("%d", &opc);
			
			if(opc==1)
				Registrar(vuelos);
			else if(opc==2){
				printf("Ingrese el numero de vuelo:");
				scanf("%d", &indice);
				Delete(vuelos, indice);
			}
			menusel=0;
		}
	}while(menusel!=2);
	
	return 0;
}
