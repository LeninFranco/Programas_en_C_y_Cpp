#include <iostream>

using namespace std;

int Potencia(int a, int b){
	if(b==0){
		return 1;
	}
	else{
		return(a*Potencia(a,b-1));
	}
}

int main(){
	int a, b, r;
	cout<<"Ingrese la base a: "; cin>>a;
	cout<<"Ingrese el exponente b: "; cin>>b;
	r=Potencia(a,b);
	cout<<"El resultado de "<<a<<" ^ "<<b<<" = "<<r<<endl;
}
