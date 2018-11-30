#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
int menu(void);
float *leer (int n);
void imprimir (int n,float *x);
float * burbumejo (int n,float *x);
int facto (int n,float *x);
int conovec (int n,float *x,float *y);
float *vecrepe(int n,float *x);
float *sumavectorial (int n,float *x,float *y,float *z);
int main(void)
{
	int op,i; float *x,*y,*z,*a,n;
	op=menu();
	while (op!=8){
	switch (op){
	case 1:
	printf ("\nIngresar dimension del vector: ");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
	x=leer(n);
	for (i=0;i<n;i++)
	printf ("\nVector leido[%d]:%2.0f ",i,*(x+i));
	break;
	case 2:
    printf ("\nIngresar dimension del vector: ");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
    for (i=0;i<n;i++){
    printf ("\nIngresar numero: ");
    scanf ("%f",(x+i));}
	imprimir(n,x);
	break;
	case 3:
	printf ("\nIngresar dimension del vector:");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
	x=leer(n);
	x=burbumejo(n,x);
	for (i=0;i<n;i++)
	printf ("\nVector ordenado[%d]:%2.0f ",i,*(x+i));
	break;
	case 4:
	printf ("\nIngresar dimension del vector:");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
	x=leer(n);
	facto(n,x);
	printf ("\nHay %d elementos cuyo factorial es mayor a 2500",facto(n,x));
	break;
	case 5:
	printf ("\nIngresar dimension del vector: ");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
	printf ("\nPrimer vector");
	x=leer(n);
    y=(float *)malloc(n*sizeof(float));
	printf ("\nSegundo vector");
	y=leer(n);
	conovec(n,x,y);
	printf ("\nHay %d elementos contenidos en el segundo vector",conovec(n,x,y));
	break;
	case 6:
	printf ("\nIngresar dimension del vector:");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
	y=(float *)malloc(n*sizeof(float));
	x=leer(n);
	printf ("\nVector Ingresado:");
	for (i=0;i<n;i++){
	printf ("%2.0f ",*(x+i));}
	y=vecrepe(n,x);
	printf ("\n\nElementos repetidos:\n");
	for (i=0;i<n;i++)
	printf ("[%d]=%2.0f\n",i,*(y+i));
	break;
	case 7:
	printf ("\nIngresar dimension de los vectores: ");
	scanf ("%f",&n);
	x=(float *)malloc(n*sizeof(float));
	printf ("\nPrimer vector");
	x=leer(n);
    y=(float *)malloc(n*sizeof(float));
	printf ("\nSegundo vector");
	y=leer(n);
	z=(float *)malloc(n*sizeof(float));
	printf ("\nTercer vector");
	z=leer(n);
	a=(float *)malloc(n*sizeof(float));
	a=sumavectorial(n,x,y,z);
    printf ("\nSuma vectorial:");
	for (i=0;i<n;i++){
	printf ("\n[%d]=%2.0f",i,*(a+i));
	}
	break;
	default:
	printf ("\nopcion no valida");
	break;}
	getch();
	op=menu();
	}
	return 0;
}
int menu(void)
{
	int opcion;
	system("CLS");
	printf("              MENU");
	printf("\n\n1:leer vector ");
	printf("\n2:Imprimir vector ");
	printf("\n3:Ordenar por metodo burbuja ");
	printf("\n4:Calcular elementos cuyo factorial sea mayor a 2500 ");
	printf("\n5:Calcular elementos contenidos en otro vector ");
	printf("\n6:Calcular elementos repetidos en el vector ");
	printf("\n7:Calcular suma vectorial de 3 vectores ");
	printf("\n8:Terminar ");
	printf("\nEscoja una opcion:");
	scanf("%d",&opcion);
	return opcion;
}
float* leer (int n){
float *a; int i;
a=(float*)malloc(n*sizeof(float));
for (i=0;i<n;i++){
printf ("\nIngresar numero al vector [%d]:",i);
scanf ("%f",(a+i));
}
return a;
}
void imprimir (int n,float *x)
{
int i;
for (i=0;i<n;i++)
	printf ("%2.0f",*(x+i));
return;
}

float * burbumejo (int n,float *x){
int i,j; float aux;
	
	for(i=0;i<n-1;i++)
	{
		if(*(x+i)>*(x+i+1))
		{
			aux=*(x+i);
			*(x+i)=*(x+i+1);
			*(x+i+1)=aux;
			if(i!=0)
			{
				for(j=i;j>=1;j--)
				{
					if(*(x+j-1)>*(x+j))
					{
						aux=*(x+j);
						*(x+j)=*(x+j-1);
						*(x+j-1)=aux;
					}
					else 
						j=1;
				}
			}
		}
	}
	
return x;
}
int facto (int n,float *x){
int i,j,con; float fac;
con=0;
for (i=0;i<n;i++){

if (*(x+i)>0){
fac=1;
for (j=1;j<=*(x+i);j++){
fac=fac*j;
}
if (fac>2500)
con++;}
}
return con;
}
int conovec (int n,float *x,float *y){
int i,j,cont,aux;
cont=0;
for (i=0;i<n;i++){
aux=0;
for (j=0;j<n;j++){
if (*(x+i)==*(y+j))
aux++;
}
if (aux>=1)
cont++;
}
return cont;
}
float *vecrepe(int n,float *x){
float *y; int i,j,aux;
y=(float *)malloc(n*sizeof(float));
for (i=0;i<n;i++){
aux=0;
if ((i!=0)&&(i!=n-1)){
aux=-1;
for (j=0;j<n;j++){
if (*(x+i)==*(x+j))
aux++;
}
*(y+i)=aux;
}
else{
if (i==0){
for (j=1;j<n;j++){
if (*(x+i)==*(x+j))
aux++;}
*(y+i)=aux;}
else{ 
for (j=0;j<n-1;j++){
if (*(x+i)==*(x+j)){
aux++;
}
}
*(y+i)=aux;
}
}
}
return y;
}
float *sumavectorial (int n,float *x,float *y,float *z){
float *a; int i;
a=(float *)malloc(n*sizeof(float));
for (i=0;i<n;i++){
*(a+i)=*(x+i)+*(y+i)+*(z+i);
}
return a;
}
