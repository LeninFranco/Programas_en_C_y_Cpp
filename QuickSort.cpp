#include <iostream>
using namespace std;
void quicksort(int A[],int izq,int der)
{
	int i,j,x,aux;
	i=izq;
	j=der;
	x=A[(izq+der)/2];
	do{
		while((A[i]<x)&&(j<=der))
		{	
			i++;
		}
		while((x<A[j])&&(j>izq))
		{
			j--;
		}
		if(i<=j)
		{
			aux=A[i];
			A[i]=A[j];
			A[j]=aux;
			i++;
			j--;
		}
	} while(i<=j);
	if(izq<j){
		quicksort(A,izq,j);
	}
	if(i<der){
		quicksort(A,i,der);
	}
}

int main(){
	int A[100],n,i;
	cout<<"QUICKSORT"<<endl;
	cout<<"Cantidad de numeros a ingresar:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Numero "<< i+1 <<": ";
		cin>>A[i];
	}
	cout<<endl;	 
	cout<<"Sin ordenar:"<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" "; 
	}
	cout<<endl<<endl;
	quicksort(A,0,n-1);
	cout<<"Ordenado:"<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" "; 
	}
}
