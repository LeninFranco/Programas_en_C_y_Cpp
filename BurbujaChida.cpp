#include <iostream>

using namespace std;

int main(){
	int n,dato;
	int i,j,aux;
	cout<<"BUBBLESORT"<<endl;
	cout<<"Ingrese el numero de elementos: "; cin>>n;
	int array[n];
	for(i=0;i<n;i++){
		cout<<"Elemento "<<i+1<<" :"; cin>>array[i];
	}
	cout<<endl;
	cout<<"Sin ordenar"<<endl;
	for(i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl<<endl;
	bool bandera;
	for(i=1;i<n;i++){
		bandera=false;
		for(j=n-1;j>=i;j--){
			if(array[j-1]>array[j]){
				aux=array[j-1];
				array[j-1]=array[j];
				array[j]=aux;
				bandera=true;
			}
		}
		if(bandera==false){
			break;
		}
	}
	cout<<"Ordenado"<<endl;
	for(i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
}
