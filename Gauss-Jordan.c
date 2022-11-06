#include<stdio.h>
#include<stdlib.h>

void header();
void mxn(int *m, int *n);
void getMatriz(int fila,int columna,float mat[][6]);
void putMatriz(int fila,int columna,float mat[][6]);
void gauss_jordan(int fila,int columna,float mat[][6],float raw[],int *contador);
int leerUltFila(int fila,int columna,float mat[][6],float raw[]);
void despejarVar(int fila, int columna,int m,float mat[m][6],float raw[],int aux);
int analizarFila(int fila, int columna,int m,float mat[m][6],float raw[]);
void putResp(int fila, int columna,float mat[][6],float raw[],int contador);


int main(){
	int fila,columna;
	float matriz[6][6]={0*36};
	float raw[6]; /*Se usara para analizar la ultima fila de la matriz 
					 y saber si el sistema es consistente (sol. unica o inf.) o inconsistente .*/
	char op;
	int contador;

	int i,j;
	for(i=0;i<fila;i++){//inicializar valores de la matriz con 0 para no arrastrar basura
		for(j=0;j<=columna;j++){
			matriz[i][j]=0;
		}
	}

	do{				 
		system("cls");
		header();
		
		mxn(&fila,&columna);
		
		getMatriz(fila,columna,matriz);
		system("cls");
		header();
		printf("\nMatriz aumentada: \n");
		putMatriz(fila,columna,matriz);
		
		printf("\nSolucionando... \n");
		gauss_jordan(fila,columna,matriz,raw,&contador);
		if(leerUltFila(fila,columna,matriz,raw)==1&&fila==columna){
			printf("\n\n\t | El sistema es consistente con solucion unica |\n");
			putResp(fila,columna,matriz,raw,contador);
		}
		else if(leerUltFila(fila,columna,matriz,raw)==2||fila<columna){
			printf("\n\n | El sistema es consistente con un conjunto infinito de soluciones |");
			printf("\n Tal que:\n");
			putResp(fila,columna,matriz,raw,contador);
		}
		else{
			printf("\n\n\t | El sistema es inconsistente |");
		}

			
		printf("\n\nDesea realizar otra operacion? (s/n) "); fflush(stdin);
		scanf("%c",&op);
		
	}while(op=='s'||op=='S');
	
	
	return 0;
}


void header(){
	printf("\t\t---------------------------------------------\n");
	printf("\t\t Solucion de Sistemas de Ecuaciones Lineales\n");
	printf("\t\t---------------------------------------------\n");
	printf("\t\t\t |Metodo de Gauss - Jordan|\n");
}

void mxn(int *m, int *n){

	printf("\nINSTRUCCIONES: Ingrese el numero de filas y columnas de la matriz con valores enteros del 1 al 5");
	printf("\n\n\t Filas: ");
	scanf("%i",m);
	if(*m>5||*m<1){
		printf("\nError! El dato ingresado (filas) es invalido, intente con un nuevo valor.\n");
		exit(1);
	}	
	printf("\t Columnas: ");
	scanf("%i",n);
	if(*n>5||*n<1){
		printf("\nError! El dato ingresado (columnas) es invalido, intente con un nuevo valor.\n");
		exit(1);
	}
	
}

void getMatriz(int fila,int columna,float mat[][6]){
	printf("\nIngresa los valores de cada variable.\n");
	int i,j;
	for(i=0;i<fila;i++){
		for(j=0;j<columna;j++){
			printf("a%i%i: ",i+1,j+1);
			scanf("%f",&mat[i][j]);
		}
		printf("b%i: ",i+1);
		scanf("%f",&mat[i][j]);
	}
}

void putMatriz(int fila,int columna,float mat[][6]){
	int i,j;
	printf("\n\t");
	for(i=0;i<fila;i++){
		printf("(");
		for(j=0;j<columna;j++){
			printf("  %.2f  ",mat[i][j]);
		}
		printf("|  %.2f  )",mat[i][j]);
		printf("\n\t");
	}
}

void gauss_jordan(int fila,int columna,float mat[][6],float raw[],int *contador){

	float aux,aux2,auxResp;
	int i,j,m,n;
	int analisis;
	
	for(i=0;i<fila;i++){
		analisis=leerUltFila(fila,columna,mat,raw);
		
		if(analisis==1){
			aux=mat[i][i];
			for(j=0;j<=columna;j++){
				mat[i][j]/=aux;
			}
			for(m=0;m<fila;m++){
				if(m!=i){
					aux2=mat[m][i];
					for(n=0;n<=columna;n++){
						mat[m][n]+=(aux2*mat[i][n]*(-1));
					}
				}
			}
			putMatriz(fila,columna,mat);
			*contador=i+1;
		}
	}
}

int leerUltFila(int fila,int columna,float mat[][6],float raw[]){
	int i,j;
	raw[0]=raw[1]=raw[2]=raw[3]=raw[4]=0;//Todos los valores del vector se igualan con 0 para evitar almacenar basura
	
	for(i=0;i<=columna;i++){//se guardaran en el vector los valores de la fila de la matriz correspondiente al valor de la ultima variable
		raw[i]=mat[fila-1][i];
	}
	
	float mayor,menor;
	menor=raw[0];
	mayor=menor;
	for(i=0;i<columna;i++){// Identificara el num. mayor y el menor del vector desde la columna 0 
		if(menor>raw[i])   // hasta la columna n-1
			menor=raw[i];
		if(mayor<raw[i])
			mayor=raw[i];
	}
	
	if(menor==0&&mayor==0&&raw[columna]==0){//si, num mayor=num menor=valor en vector b = 0
		
		return 2;
	}else if(menor==0&&mayor==0&&raw[columna]!=0){//si, num mayor=num menor=0 y valor en vecor b es !=0
		
		return 3;
	}else{
		return 1;
	}
}


void despejarVar(int fila, int columna,int m,float mat[m][6],float raw[],int aux){
	int i,j;
	raw[0]=raw[1]=raw[2]=raw[3]=raw[4]=0;//Todos los valores del vector se igualan con 0 para evitar almacenar basura
	
	
	for(i=aux;i<columna;i++){//se guardaran en el vector los valores de la fila m de la matriz a partir de la columna correspondiente a la variable libre.
		raw[i]=mat[m][i];
	}

	printf("%.2f ",mat[m][columna]);
	for(i=aux;i<columna;i++){
		if(mat[m][i]<0){
			printf("+ %.2f X%i  ",mat[m][i]*(-1),i+1);
		}else{
			printf(" %.2f X%i  ",mat[m][i]*(-1),i+1);
		}
	}

}

void putResp(int fila, int columna,float mat[][6],float raw[],int contador){
	int i,j;

	for(i=0;i<columna;i++){
		printf("\nX%i = ",i+1);
		if(analizarFila(fila,columna,i,mat,raw)==2){//Significa que es una variable libre
			printf("X%i",i+1);
		}else{
			despejarVar(fila,columna,i,mat,raw,contador);
		}
	}

}

int analizarFila(int fila, int columna,int m,float mat[m][6],float raw[]){
	int i,j;
	raw[0]=raw[1]=raw[2]=raw[3]=raw[4]=0;//Todos los valores del vector se igualan con 0 para evitar almacenar basura
	
	for(i=0;i<=columna;i++){//se guardaran en el vector los valores de la fila de la matriz correspondiente al valor de la ultima variable
		raw[i]=mat[m][i];
	}
	
	float mayor,menor;
	menor=raw[0];
	mayor=menor;
	for(i=0;i<columna;i++){// Identificara el num. mayor y el menor del vector desde la columna 0 
		if(menor>raw[i])   // hasta la columna n-1
			menor=raw[i];
		if(mayor<raw[i])
			mayor=raw[i];
	}
	
	if(menor==0&&mayor==0&&raw[columna]==0){//si, num mayor=num menor=valor en vector b = 0
		
		return 2;
	}else{
		return 1;
	}
}