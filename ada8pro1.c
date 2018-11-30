#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
float* leer (float n);
void recta (float *x,float *y,float n);
int* valpos(int *z,int ndim,int dim);
int npos (int *z,int dim);
int menu(void);
int main(void)
{
	int op,i,j,*z,dim,ndim,*pos; float n,*x,*y;
	op=menu();
	while (op!=3){
	switch (op){
	case 1:
	printf ("\nIngresar dimension de los vectores: ");
	scanf ("%f",&n);
	printf ("\nPrimer vector: ");
	x=(float*)malloc(n*sizeof(float));
	x=leer(n);
	printf ("\nSegundo vector: ");
	y=(float*)malloc(n*sizeof(float));
	y=leer(n);
	recta(x,y,n);
	break;
	case 2:
	printf ("Ingresar dimension del vector: ");
	scanf ("%d",&dim);
	z=(int*)malloc(dim*sizeof(int));
	for (i=0;i<dim;i++){
	printf ("Ingresar numero [%d]:",i);
	scanf ("%d",(z+i));}
	ndim=npos(z,dim);
	pos=(int*)malloc(ndim*sizeof(int));
	pos=valpos(z,ndim,dim);
	printf ("\nLos numeros pares positivos en el vector son: ");
	for (j=0;j<ndim;j++){
	printf ("%d ",*(pos+j));
	}
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
void recta (float *x,float *y,float n)
{
int i; float A,B,s=0,s2=0,s3=0,a=0,a2=0,a3=0;
for (i=0;i<n;i++){
s+=*(y+i);
s2+=*(x+i);
s3+=(*(x+i))*(*(y+i));
a+=(*(x+i))*(*(y+i));
a2+=(*(x+i))*(*(x+i));
a3+=*(x+i);
}
A=(((s)*(s2))-((s2)*(s3)))/(((n)*(s2))-((s2)*(s2)));
B=(((a)*(a2))-((a3)*(a)))/(((n)*(a2))-((a3)*(a3)));
printf ("Los coeficientes son A=%4.2f y B=%4.2f",A,B);
return;
}
int* valpos(int *z,int ndim,int dim){
int *p,i,j;
p=(int*)malloc(ndim*sizeof(int));
j=0;
i=0;
while (j<ndim){
if ((*(z+i)>1)&&(*(z+i)%2==0)){
*(p+j)=*(z+i);
j++;}
i++;
}
return p;
}
int npos (int *z,int dim){
int i,n;
for (i=0;i<dim;i++){
if ((*(z+i)>0)&&(*(z+i)%2==0))
n++;
}
return n;
}
int menu(void)
{
	int opcion;
	system("CLS");
	printf("              MENU");
	printf("\n\n1:Calcular coefifcientes de A y B.\nDe la recta Y=A X+B");
	printf("\n2:Calcular numeros pares positivos");
	printf("\n3:Terminar");
	printf("\nEscoge una opcion: ");
	scanf("%d",&opcion);
	return opcion;
}
