#include <iostream>
using namespace std;

int Factorial(int n){
	if(n==0){
		return 1;
	}
	else{
		return(n*Factorial(n-1));
	}
}

int main(){
	int k, n, r, c, nf, kf, rf;
	cout<<"Ingrese el numero total de elementos: "; cin>>n;
	cout<<"Ingrese las la cantidad de elementos que se iran tomando: "; cin>>k;
	r=n-k;
	nf=Factorial(n);
	kf=Factorial(k);
	rf=Factorial(r);
	c=(nf)/(kf*rf);
	cout<<"El numero de combinaciones SIN repeticion de "<<n<<" elementos tomados de "<<k<<" en "<<k<<" es de: "<<c;
}
