#include <iostream>
#include <conio.h>

using namespace std;

void Torre_Hanoi(int disco, int torre1, int torre2, int torre3){
	if(disco==1){
		cout<<"Mover el disco de la torre "<<torre1<<" hacia la torre "<<torre3<<endl;
		
	}
	else{
		Torre_Hanoi(disco-1,torre1,torre3,torre2);
		cout<<"Mover el disco de la torre "<<torre1<<" hacia la torre "<<torre3<<endl;
		Torre_Hanoi(disco-1,torre2,torre1,torre3);
	}
}
int main(){
	int disco=0, Torre1=1, Torre2=2, Torre3=3;
	cout<<"Ingrese el numero de discos: "; cin>>disco;
	Torre_Hanoi(disco,Torre1,Torre2,Torre3);
}
