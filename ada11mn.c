#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
int menu (void);
float *lee_vector (int n);
int num_primos (int n,float *y);
void imprime_perfectos (int n,float *y);

int main(void) 
{
	float *y,n; int op;
	op=menu();
	while (op!=4){
	switch (op){
	case 1:
	printf ("\nIngresar dimension del vector: ");
	scanf ("%f",&n);
	y=(float *)malloc(n*sizeof(float));
    y=lee_vector(n);
	op=menu();
	break;
	case 2:
	num_primos(n,y);
	break;
	case 3:
	imprime_perfectos(n,y);
	break;
	default:
	printf ("\nOpcion no valida");
	break;
    }
	getch();
	op=menu();
	}
	return 0;
}
int menu (void)
{
int opcion;
printf ("            MENU");
printf ("\n1.- float *lee_vector (int n)");
printf ("\n2.- int num_primos (int n,float *y");
printf ("\n3.- void imprime_perfectos(int n,float *y)");
printf ("\n4.-Terminar");
printf ("\nEscoge una opcion: ");
scanf ("%d",&opcion);
return opcion;
}

float *lee_vector (int n){
float *y; int i;
y=(float *)malloc(n*sizeof(float));
for (i=0;i<n;i++){
printf ("\nIngresar numero: ");
scanf ("%f",(y+i));
}
return y;
}
int num_primos (int n,float *y){
int np,npr,i,j;
npr=0;
for (i=0;i<n;i++){
np=2;
for (j=1;j<=*(y+i);j++){
if (fmod(*(y+i),j)==0)
np++;
}
if (np==2)
npr++;
}
return npr;
}

void imprime_perfectos (int n,float *y){
float m,ent,res; int j,i;
for (j=0;j<n;j++){
m=0;
i=1;
while(i<*(y+j)){
ent=floor(*(y+j)/i);
res=*(y+j)-(ent*i);
if (res==0){
m+=i;}
i++;
}
if (m==*(y+j)){
printf ("\nEl numero %2.0f es perfecto",*(y+j));
}
return;
}}

