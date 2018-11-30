#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
float* leer (float n);
void comparar (float *x,float *y,float n,float m);
void numperfec (float *a,float n2);
float* ordenar (float *b,float n3);
void imprimir (float *c,float n3);
int menu(void);
int main(void)
{
	int op,i,j; float n,n2,n3,m,*x,*y,*a,*b,*c;
	op=menu();
	while (op!=4){
	switch (op){
	case 1:
	printf ("\nIngresar dimension del primer vector: ");
	scanf ("%f",&n);
	printf ("\nPrimer vector: ");
	x=(float*)malloc(n*sizeof(float));
	x=leer(n);
	printf ("\nIngresar dimension del segundo vector: ");
	scanf ("%f",&m);
	printf ("\nSegundo vector: ");
	y=(float*)malloc(m*sizeof(float));
	y=leer(m);
	comparar(x,y,n,m);
	break;
	case 2:
	printf ("\nIngresar dimension del vector: ");
	scanf ("%f",&n3);
	b=(float*)malloc(n3*sizeof(float));
	c=(float*)malloc(n3*sizeof(float));
    for (i=0;i<n3;i++){
	printf ("\nIngresar numero: ");
	scanf ("%f",(b+i));}
	c=ordenar(b,n3);
	imprimir(c,n3);
	break;
	case 3:
	printf ("\nIngresar dimension del vector:");
	scanf ("%f",&n2);
	a=(float*)malloc(n2*sizeof(float));
    for (j=0;j<n2;j++){
	printf ("\nIngresar numero:");
	scanf ("%f",(a+j));}
	numperfec(a,n2);
	break;
	default:
	break;}
	getch();
	op=menu();
	}
	return 0;
}
float* leer (float n){
float *a; int i;
a=(float*)malloc(n*sizeof(float));
for (i=0;i<n;i++){
printf ("\nIngresar numero al vector [%d]:",i);
scanf ("%f",(a+i));
}
return a;
}
void comparar (float *x,float *y,float n,float m)
{
int a,ban;
	if (n==m){
	ban=0;
	a=0;
	while ((ban==0)&&(a<n)){
	if ( *(x+a)!=*(y+a)){
	ban=1;}
	else
	a++;
	}
	if (ban==0){
	printf ("\nLos vectores son iguales");
	}
	else
	printf ("\nLos vectores son diferentes");
	}
	else
	printf ("\nLos vectores son diferentes");
return;
}
int menu(void)
{
	int opcion;
	system("CLS");
	printf("              MENU");
	printf("\n\n1:Determinar si los vectores son iguales");
	printf("\n2:Ordenar vector de mayor a menor");
	printf("\n3:Numeros perfectos");
	printf ("\n4:Terminar");
	printf("\nEscoge una opcion: ");
	scanf("%d",&opcion);
	return opcion;
}
void numperfec (float *a,float n2){
float *b,m; int i,j;
b=(float*)malloc(n2*sizeof(float));
for (i=0;i<n2;i++){
*(b+i)=*(a+i);
}
for (i=0;i<n2;i++){
if (*(b+i)>=1){
j=1;
m=0;
while (j<*(b+i)){
if (fmod(*(b+i),j)==0){
m+=j;}
j++;
}
if (*(b+i)==m){
printf ("\nEl numero %2.0f es perfecto",*(b+i));}

}
else 
printf (" ");
}
return;
}
float* ordenar (float *b,float n3){
	int e,c,i; float *d,aux;
	d=(float*)malloc(n3*sizeof(float));
	for (e=1;e<n3;e++)
	{
	for (c=0;c<n3-1;c++){
	if(*(b+c)<*(b+e)){  /*< funciona para ordenar de mayor a menor*/
	aux=*(b+c);
	*(b+c)=*(b+e);
	*(b+e)=aux;
	}
	}
	}
	for (i=0;i<n3;i++){
	*(d+i)=*(b+i);
	}
return d;
}
void imprimir (float *c,float n3){
int i;
printf ("\nVector Ordenado: ");
for (i=0;i<n3;i++){
printf ("%2.0f",*(c+i));}
return;
}
