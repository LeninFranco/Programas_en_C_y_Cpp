#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Op1(int *M, int C, int p, int i);
void Op2(int *Ml, int *Mk, int C);
void Op3(int *Mk, int *Mi, int C, int p, int i);
int Primo(int p);
void Sol(int *M, int C, int i, int p, int D);
int Inverso(int M, long E, int p);

int main(){
	int p,r;
	int i, j;
	int F=0, C=0;
	do{
		do{
			system("cls");
			printf("Introduzca el numero primo para definir el campo: ");
			scanf("%d", &p);
		}while(Primo(p)==0);
		printf("\nSistema de ecuaciones.\n\n");
		do{
			printf("\nIngrese la cantidad de ecuaciones que hay en el sistema: ");
			scanf("%d", &F);	
		}while(F==0);
		do{
			printf("Ingrese la cantidad de indeterminadas diferentes que hay en el sistema: ");
			scanf("%d", &C);	
		}while(C==0);
		printf("\n");
		int M[F][C+1];
		for(i=0;i<F;i++){
			printf("\nEcuacion %d: ", i+1);
			for(j=0;j<C;j++){
				printf("\nCoeficiente para %c: ",90-C+j+1);
				scanf("%d", &M[i][j]);
			}
			printf("\nValor del %d%c termino independiente: ",i+1, 248);
			scanf("%d", &M[i][j]);
		}
		i=0;
		j=0;
		int k;
		O:
		while(M[i][j]!=0 && i<F && j<C){
			Op1(&M[i][0], C+1, p, j);
			for(k=0;k<F;k++) if(k!=i) Op3(&M[k][0],&M[i][0], C+1, p, j);
			i++;
			j++;
		}
		if (M[i][j]==0 && i<F-1){
			k=i+1;
			while(M[k][j]==0 && k<F-1) k++;
			if(M[k][j]!=0){
				Op2(&M[i][0], &M[k][0], C+1);
				goto O;
			} else {
				if(j<C){
					j++;
					goto O;	
				}
			}
		}
		int F0=0;
		for(i=F-1;i>=0;i--){
			for(j=0;j<C;j++){ 
				if(M[i][j]!=0) break;
				else if(j==C-1){
					if(M[i][C]==0) F0++;
					else {
						printf("\n\nSistema inconsistente.\n\n");
						goto F;
					}
				}
			}
		}
		if(F-F0==C) printf("\n\nSistema consistente solucion unica.\n\n");
		else printf("\n\nSistema consistente multiples soluciones.\n\n");
		if(F-F0==0) F0=F-C;
		for(i=0;i<F-F0;i++) Sol(&M[i][0], C, i, p, F-F0);
		for(i=0;i<F;i++) {
			for(j=0;j<=C;j++) { 
				printf("|%d|", (M[i][j]));
				if(j==C) printf("\n");
			}
		}
		F:
		system("PAUSE");
	}while(1);
	return 0;
}

int Primo(int p){
	int i;
	if(p==1 || p==0) return 0;
	for(i=2;i<=sqrt(p);i++) if(p%i==0) return 0;
	return 1;
}

int Inverso(int M, long E, int p){
    int Res = 1;
    while(E>0){
        if((E&1)==1) Res=(M*Res)%p;
    	E>>=1;
    	M=((M%p)*(M%p))%p;
    }
return Res;
}

void Sol(int *M, int C, int i, int p, int D){
	int j;
	if(M[i]==0 && D!=C) i++;
	printf("\n%c = %d",90-C+i+1, M[C]);	
	for(j=i+1;j<C;j++) if(M[j]!=0) {
		int AdN = p - M[j]%p;
		printf(" + %d%C", AdN,90-C+j+1);	
	}
	printf("\n\n");
}

void Op1(int *M, int C, int p, int i){
	int j = Inverso(M[i], p-2, p);
	int k;
	for(k=i;k<C;k++) M[k] = (M[k]*j)%p;
}
void Op2(int *Ml, int *Mk, int C){
	int t;
	for(t=0;t<C;t++){
		int Temp = Mk[t];
		Mk[t] = Ml[t];
		Ml[t] = Temp;
	}
}
void Op3(int *Mk, int *Mi, int C, int p, int i){
	int AdN = p - Mk[i]%p;
	int k;
	for(k=0;k<C;k++) Mk[k] = (Mk[k]+AdN*Mi[k])%p;
}
