#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1416
//https://www.matesfacil.com/BAC/complejos/numeros-complejos-forma-polar-binomica-calculadora-producto-problemas-resueltos.html
//https://www.varsitytutors.com/hotmath/hotmath_help/spanish/topics/operations-with-complex-numbers
typedef struct comp{
	float real;
	float imag;
}complejo;

void suma(struct comp num1, struct comp num2){
	complejo num3;
	num3.real=(num1.real)+(num2.real);
	num3.imag=(num1.imag)+(num2.imag);
	printf("El resultado de la suma de [(%.0f)+(%0.fi)]+[(%.0f)+(%0.fi)]=[(%.0f)+(%0.fi)]",num1.real,num1.imag,num2.real,num2.imag,num3.real,num3.imag);
	printf("\nPresione ENTER para continuar");
	getch();
}
void resta(struct comp num1, struct comp num2){
	complejo num3;
	num3.real=(num1.real)-(num2.real);
	num3.imag=(num1.imag)-(num2.imag);
	printf("El resultado de la resta de [(%.0f)+(%0.fi)]-[(%.0f)+(%0.fi)]=[(%.0f)+(%0.fi)]",num1.real,num1.imag,num2.real,num2.imag,num3.real,num3.imag);
	printf("\nPresione ENTER para continuar");
	getch();
}
void multi(struct comp num1, struct comp num2){
	complejo num3;
	num3.real=((num1.real*num2.real)-(num1.imag*num2.imag));
	num3.imag=((num1.real*num2.imag)+(num1.imag*num2.real));
	printf("El resultado de la multiplicacion de [(%.0f)+(%0.fi)]X[(%.0f)+(%0.fi)]=[(%.0f)+(%0.fi)]",num1.real,num1.imag,num2.real,num2.imag,num3.real,num3.imag);
	printf("\nPresione ENTER para continuar");
	getch();
}
void divis(struct comp num1, struct comp num2){
	complejo num3;
	num3.real=((num1.real*num2.real)+(num1.imag*num2.imag))/((pow(num2.real,2))+(pow(num2.imag,2)));
	num3.imag=((num1.imag*num2.real)-(num1.real*num2.imag))/((pow(num2.real,2))+(pow(num2.imag,2)));
	printf("El resultado de la division de [(%.0f)+(%.0fi)]/[(%.0f)+(%.0fi)]=[(%.5f)+(%.5fi)]",num1.real,num1.imag,num2.real,num2.imag,num3.real,num3.imag);
	printf("\nPresione ENTER para continuar");
	getch();
}
void polar(struct comp num1){
	complejo mod, angulo, raiz;
	raiz.real=(pow(num1.real,2))+(pow(num1.imag,2));
	mod.real=sqrt((pow(num1.real,2))+(pow(num1.imag,2)));
	angulo.real=atan(num1.imag/num1.real);
	angulo.real=angulo.real*(180/PI);
	printf("El numero complejo [(%.0f)+(%.0fi)] en polar es:\nModulo=raiz(%.0f)=%.5f\nAngulo=%.0f grados",num1.real,num1.imag,raiz.real,mod.real,angulo.real);
	printf("\nPresione ENTER para continuar");
	getch();
}

int main(){
	complejo num1, num2, num3;
	int opc;
	do{
		system("cls");
		printf("CALCULADORA DE NUMEROS COMPLEJOS RECTANGULARES\n");
		printf("Seleccione una de las siguiemtes operaciones:\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n5.Rectangular a Polar\n6.Salir\n\nOpcion: ");
		scanf("%d", &opc);
		switch(opc){
			case 1:
			system("cls");
			printf("Numero 1\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num1.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num1.imag);
			printf("Numero 2\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num2.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num2.imag);
			suma(num1,num2);
			break;
			case 2:
			system("cls");
			printf("Numero 1\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num1.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num1.imag);
			printf("Numero 2\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num2.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num2.imag);
			resta(num1,num2);
			break;
			case 3:
			system("cls");
			printf("Numero 1\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num1.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num1.imag);
			printf("Numero 2\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num2.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num2.imag);
			multi(num1,num2);
			break;
			case 4:
			system("cls");
			printf("Numero 1\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num1.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num1.imag);
			printf("Numero 2\nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num2.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num2.imag);
			divis(num1,num2);
			break;
			case 5:
			system("cls");
			printf("Numero \nDe la forma (+/-)a(+/-)bi\nIngrese la parte real a: ");
			scanf("%f", &num1.real);
			printf("Ingrese la parte imaginaria bi: ");
			scanf("%fi", &num1.imag);
			polar(num1);
			break;
		}	
	}while(opc!=6);
}
