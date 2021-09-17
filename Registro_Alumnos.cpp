#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <queue>
#define max 3

using namespace std;

struct datos_alumno{
	char nombre[20];
	char apellido[20];
	float promedio;
}alumno[max]; 

void Registro_Alumno(){
	for(int i=0;i<max;i++){
		system("cls");
		cout<<"<<-----Registro de Alumnos----->>"<<endl;
		cout<<"Nombre del Alumno "<<i+1<<": "; cin>>alumno[i].nombre;
		cout<<"Apellido del Alumno "<<i+1<<": "; cin>>alumno[i].apellido;
		cout<<"Promedio del Alumno "<<i+1<<": "; cin>>alumno[i].promedio;
	}
}


int main(){
	int pos=0;
	Registro_Alumno();
	system("cls");
	priority_queue<float> QPrior;
	queue<float> QPrin;
	for(int i=0;i<max;i++){
		QPrior.push(alumno[i].promedio);
	}
	for(int i=0;i<max;i++){
		QPrin.push(QPrior.top());
		QPrior.pop();
	}
	for(int i=0;i<max;i++){
		system("cls");
		float temp, aux;
		temp=QPrin.front();
		QPrin.pop();
		for(int j=0;j<max;j++){
			if(alumno[j].promedio==temp){
				pos+=1;
				cout<<"Atendido "<<pos<<endl;
				cout<<"Nombre: "<<alumno[j].nombre<<endl;
				cout<<"Apellido: "<<alumno[j].apellido<<endl;
				cout<<"Promedio: "<<alumno[j].promedio<<endl<<endl;
				if(QPrin.empty()){
					cout<<"No hay nadie mas en la fila"<<endl;
				}
				aux=QPrin.front();
				for(int k=0;k<max;k++){
					if(alumno[k].promedio==aux){
						cout<<"Siguiente en atender"<<endl;
						cout<<"Nombre: "<<alumno[k].nombre<<endl;
						cout<<"Apellido: "<<alumno[k].apellido<<endl;
						cout<<"Promedio: "<<alumno[k].promedio<<endl<<endl;
					}
				}
			}
		}
		cout<<"[ENTER PARA CONTINUAR]"; getch();
	}
	system("cls");
	cout<<"Ha finalizado con la inscripcion"<<endl;
	return 0;
	getch();
}
