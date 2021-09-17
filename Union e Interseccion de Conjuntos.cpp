#include <iostream>
#include <vector>
#define MAX 255
using namespace std;

void Union(int A[], int B[], int m, int n){
	vector<int> U;
	for(int i=0;i<m;i++){
		U.push_back(A[i]);
	}
	for(int i=0;i<n;i++){
		bool repetidos = false; 
		for(int j=0;j<U.size();j++){
			if(B[i] == U[j]){
				repetidos = true;
			}
		}
		if(repetidos == false){
			U.push_back(B[i]);
		}
	}
	cout<<"A union con B es igual a { ";
	for(int i=0;i<U.size();i++){
		cout<<U[i]<<" ";
	}
	cout<<"}"<<endl;
}

void Interseccion(int A[], int B[], int m, int n){
	vector<int> I;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(A[i]==B[j]){
				I.push_back(A[i]);
			}
		}
	}
	cout<<"A interseccion con B es igual a { ";
	for(int i=0;i<I.size();i++){
		cout<<I[i]<<" ";
	}
	cout<<"}"<<endl;
}


int main(){
	int m, n;
	cout<<"Ingrese la cantidad de elementos del conjunto A: "; cin>>m;
	cout<<"Ingrese la cantidad de elementos del conjunto B: "; cin>>n;
	int A[m], B[n], U[MAX], I[MAX];
	for(int i=0;i<m;i++){
		cout<<"Ingrese un elemento al conjunto A: "; cin>>A[i];
	}
	for(int i=0;i<n;i++){
		cout<<"Ingrese un elemento al conjunto B: "; cin>>B[i];
	}
	cout<<endl;
	Union(A,B,m,n);
	Interseccion(A,B,m,n);
}

