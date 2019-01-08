#include <stdio.h>

struct alumnos{
	int matricula;
	char nombre[15];
	int edad; 
	char licen[15];
	int cred;
	char sem[15];
	char aslib[15];
}alumno[15];
FILE *ap;

void altaAlumnos();
void listaAlumnos();
int menu();
int main() {
	int op;
	op=menu();
	while(op!=9){
		switch(op){
		case 1: 
			altaAlumnos();
			break;
		case 5:
			listaAlumnos();
			break;
		}
		getchar();
		op=menu();
	}
	
	return 0;
}

int menu(){
	int op;
	printf("1.-ALTA ALUMNO\n");
	printf("2.-BAJA ALUMNO\n");
	printf("3.-MODIFICAR ALUMNO\n");
	printf("4.-BUSCAR ALUMNO\n");
	printf("5.-LISTA ALUMNOS\n");
	printf("6.-LISTA FILTROS\n");
	printf("7.-TOTAL DE ALUMNOS\n");
	printf("8.-INSCRIBIRSE A ASIGNATURA LIBRE\n");
	printf("9.-TERMINAR\n");
	printf("ingrese opcion:\n");
	scanf("%d",&op);
	return op;
}
void altaAlumnos(){/*matricula, nombre, edad, licenciatura, creditos, semestre*/
	char arch[15];
	int n;
	printf("\ningresar nombre del archivo:");
	scanf("%s",arch);
	printf("\nCuantos registros va dar de alta:");
	scanf("%d",&n);
	ap=fopen(arch,"wt");
	for (int i=0; i<n; i++){
		printf("\ningrese matricula del alumno: ");
		scanf("%d",&alumno[i].matricula);
		printf("\ningrese nombre del alumno: ");
		scanf("%s",alumno[i].nombre);
		printf("\ningrese edad: ");
		scanf("%d",&alumno[i].edad);
		printf("\ningrese licenciatura: ");
		scanf("%s",alumno[i].licen);
		printf("\ningrese semestre: ");
		scanf("%s",alumno[i].sem);
		printf("\ningrese asignatura libre: ");
		scanf("%s",alumno[i].aslib);
		
		fprintf(ap,"%d", alumno[i].matricula);
		fprintf(ap, "%15s\n", alumno[i].nombre);
		fprintf(ap, "%d", alumno[i].edad);
		fprintf(ap, "%15s\n", alumno[i].licen);
		fprintf(ap, "%15s\n", alumno[i].sem );
		fprintf(ap, "%15s\n", alumno[i].aslib);
	}
	fclose(ap);
}

void listaAlumnos(){
	char arch[15];
	int n;
	printf("ingresar nombre del archivo:");
	scanf("%s",arch);
	printf("\nCuantos registros va dar de alta:");
	scanf("%d",&n);
	
	ap=fopen(arch,"r");
	for (int i=0; i<n; i++){
		fscanf(ap, "%d", &alumno[i].matricula);
		fscanf(ap, "%15s", alumno[i].nombre);
		fscanf(ap, "%d", &alumno[i].edad);
		fscanf(ap, "%15s", alumno[i].licen);
		fscanf(ap, "%15s", alumno[i].sem);
		fscanf(ap, "%15s", alumno[i].aslib);
		
		printf("\nMATRICULA: %d",alumno[i].matricula);
		printf("\nNOMBRE: %15s",alumno[i].nombre);
		printf("\nEDAD: %d", alumno[i].edad);
		printf("\nLICENCIATURA: %15s", alumno[i].licen);
		printf("\nSEMESTRE: %15s", alumno[i].sem);
		printf("\nASIGNATURA LIBRE: %15s", alumno[i].aslib);
	}
	fclose(ap);
	
}
