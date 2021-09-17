#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <queue>
#define max 9

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
	float temp, aux[100], size;
	priority_queue<float> QPrior;
	queue<float> QPrin;
	Registro_Alumno();
	for(int a=0;a<max;a++){
		QPrin.push(alumno[a].promedio);
	}
	do{
		for(int b=0;b<3;b++){
		QPrior.push(QPrin.front());
		QPrin.pop();
		}
		system("cls");
		temp=QPrior.top();
		QPrior.pop();
		for(int c=0;c<max;c++){
			if(alumno[c].promedio==temp){
				cout<<"Atendiendo"<<endl;
				cout<<"Nombre: "<<alumno[c].nombre<<endl;
				cout<<"Apellido: "<<alumno[c].apellido<<endl;
				cout<<"Promedio: "<<alumno[c].promedio<<endl<<endl;
			}
		}
		size=QPrior.size();
		for(int d=0;d<size;d++){
			aux[d]=QPrior.top();
			QPrior.pop();
			for(int e=0;e<max;e++){
			if(alumno[e].promedio==aux[d]){
				cout<<"En espera"<<endl;
				cout<<"Nombre: "<<alumno[e].nombre<<endl;
				cout<<"Apellido: "<<alumno[e].apellido<<endl;
				cout<<"Promedio: "<<alumno[e].promedio<<endl<<endl;
			}
			}
		}
		for(int f=0;f<size;f++){
			QPrior.push(aux[f]);
		}
		cout<<"[ENTER PARA CONTINUAR]"; getch();
	}while(!QPrior.empty());
	return 0;
	getch();
}
