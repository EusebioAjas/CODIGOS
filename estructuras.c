#include <stdio.h>
#include <conio.h>

typedef struct {
	char nombres[15];
	int edad;
	char genero [15];
}persona;
persona per[5];

int main(int argc, char *argv[]) {
	int nPersonas;
	printf("ingrese numero de personas\n");
	scanf("%d",&nPersonas);
	for (int i=0; i<nPersonas; i++){
		printf("ingresar nombre\n");
		scanf("%s",per[i].nombres);
		printf("ingresar edad\n");
		scanf("%d",&per[i].edad);
		printf("ingrese genero\n");
		scanf("%s",per[i].genero);
		
	}
	
	for (int i=0; i<nPersonas; i++){
		printf("\n Nombre:%15s\n",per[i].nombres);
		printf("Edad: %d\n",per[i].edad);
		printf("Genero: %15s\n",per[i].genero);
	}
	
	return 0;
}

