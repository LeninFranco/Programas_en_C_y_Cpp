#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
int mat1[40][40];
int mat2[40][40];
int mat1t[40][40];
int mat2t[40][40];
int multi[40][40];
char archivo[10000];
void leer(char entrada[]){
    char *secuencia;
    FILE *ptrs;
    ptrs= fopen(entrada,"r");
    if(ptrs==NULL){
        printf("No hay datos");
        exit(1);
    }else{
        while (fgets((char*)&archivo, sizeof(archivo), ptrs)){
            printf("%s",archivo);
        }
        fclose(ptrs);
    }
}
void guardar(){
    char *secuencia;
    FILE *ptrs,*ptrs2;
    int i,j;
    ptrs= fopen("mat1.txt","r");
    ptrs2= fopen("mat2.txt","r");
    if(ptrs==NULL){
        printf("No hay datos");
        exit(1);
    }else{
        for(i = 0; i < 7; i++)
            for(j = 0; j < 7; j++)
                fscanf(ptrs,"%d", &mat1[i][j]);
        fclose(ptrs);
    }
    if(ptrs2==NULL){
        printf("No hay datos");
        exit(1);
    }else{
        for(i = 0; i < 7; i++)
            for(j = 0; j < 7; j++)
                fscanf(ptrs2,"%d", &mat2[i][j]);
        fclose(ptrs2);
    }
}
int main(){
    double total_time;
    clock_t start, end;
    start = clock();
    guardar();
    int i,j,k;
    FILE* fichero;
    fichero = fopen("suma.txt","w");
    for(i=0; i<7; i++) {
        for(j=0; j<7; j++) {
            fprintf(fichero,"%d ", (int)(mat1[i][j]+mat2[i][j]));
        }
        fprintf(fichero,"\n");
    }
    fclose(fichero);
    fichero = fopen("resta.txt","w");
    for(i=0; i<7; i++) {
        for(j=0; j<7; j++) {
            fprintf(fichero,"%d ", (int)(mat1[i][j]-mat2[i][j]));
        }
        fprintf(fichero,"\n");
    }
    fclose(fichero);
    fichero = fopen("multi.txt", "w");
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            multi[i][j] = 0;
            for (k = 0; k < 7; k++)
                multi[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
    for(i=0; i<7; i++) {
        for(j=0; j<7; j++) {
            fprintf(fichero, "%d ", (int)(multi[i][j]));
        }
        fprintf(fichero,"\n");
    }
    fclose(fichero);
    for(i=0; i<7; i++) {
        for(j=0; j<7; j++) {
            mat1t[i][j] = mat1[j][i];
            mat2t[i][j] = mat2[j][i];
        }
    }
    fichero = fopen("transpuesta.txt", "w");
    for(i=0; i<7; i++) {
        for(j=0; j<7; j++) {
            fprintf(fichero, "%d ", (int)(mat1t[i][j]));
        }
    fprintf(fichero,"\n");
    }
    fprintf(fichero,"\n");
    for(i=0; i<7; i++) {
        for(j=0; j<7; j++) {
            fprintf(fichero, "%d ", (int)(mat2t[i][j]));
        }
    fprintf(fichero,"\n");
    }
    fclose(fichero);
    printf("\n=== Suma ===\n");
    leer("suma.txt");
    printf("\n=== Resta ===\n");
    leer("resta.txt");
    printf("\n=== Multiplicacion ===\n");
    leer("multi.txt");
    printf("\n=== Traspuesta ===\n");
    leer("transpuesta.txt");
    end = clock();
    total_time = ((double) (end - start)) / CLK_TCK;
    printf("\n\t----El tiempo de ejecucion fue de: %f\n", total_time);
}