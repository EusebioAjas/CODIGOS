#include <stdio.h>
#define N 100

void ordSeleccion (int a[], int n);
void entradaLista (int a[], int n);
void imprimirLista (int a[], int n);
int main(){
	int n;
	int v[N];
	
	do{
		printf("\nIntroduzca el numero de elementos:\n ");
		scanf("%d", &n);
	} while((n<1) && (n>N));
	
	entradaLista(v, n);
	printf("\nLista original de %d elementos\n", n);
	imprimirLista(v, n);
	
	ordSeleccion(v, n);
	printf("\nLista ordenada por seleccion de %d elementos\n", n);
	imprimirLista(v, n);
	return 0;
}
void ordSeleccion (int a[], int n){
	int indiceMenor;
	for(int i=0; i<n-1; i++){
		indiceMenor=i;
		for(int j=i+1; j<n; j++){
			if (a[j]<a[indiceMenor]){
				indiceMenor=j;
			}
		}
		if(i!=indiceMenor){
			int aux=a[i];
			a[i]=a[indiceMenor];
			a[indiceMenor]=aux;
		}
	}
}
void imprimirLista(int a[], int n ){
	for(int i=0; i<n; i++){
		char c;
		c=(i%10==0)?'\n':' ';
		printf("%c%d", c, a[i]);
	}
}
void entradaLista(int a[], int n){
	printf("\n Entrada de los elementos\n");
	for(int i=0; i<n; i++){
		printf("a[%d] = ",i);
		scanf("%d", a+i);
	}
}
