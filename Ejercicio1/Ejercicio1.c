// --Fernández Ian Santiago--

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

typedef	struct F_Arch{
		char NombreArchivo[30];
		char Formato[7];
		float Tamanio;
		struct F_Arch *prox;

}NODO;

typedef NODO *F_puntero;


void imprimir_lista(F_puntero PRIM);

int main(){

	char ingreso_primernombre[30];
	char ingreso_primerformato[7];
	float ingreso_primertamanio;

	char rta_carga;
	int habilitador;

	F_puntero PRIM; // Creamos e inicializamos el puntero inicial
	PRIM = NULL;
	F_puntero aux; // Puntero auxiliar que utilizare mas adelante
	aux=NULL;

	printf("\tGestion de archivos COMPUTEX\n");
	printf("\tPresione cualquier tecla para continuar ...\n");
	getchar();
	system("cls");

	printf("ALTO AHI!...\n");
	getchar();
	system("cls");

	printf("Instrucciones : \n");
	getchar();
	printf("\n");
	printf("El sistema le pediran los datos tales como :\n");
	printf("\tNombre del archivo [30 caracteres]\n\n \tFormato del archivo [7 caracteres]\n\n \tTamano del archivo \n\n");
	printf("Presione cualquier tecla para continuar...\n");
	getchar();
	system("cls");

	//Carga de datos

	printf("NOMBRE DE ARCHIVO : ");
	gets(ingreso_primernombre);
	printf("\n");
	printf("FORMATO : ");
	gets(ingreso_primerformato);
	printf("\n");
	printf("TAMANIO : ");
	scanf("%f", &ingreso_primertamanio);
	printf("\n");

	printf("\n");

	PRIM = malloc(sizeof(NODO)); //Aqui reservamos memoria

	strcpy(PRIM->NombreArchivo , ingreso_primernombre);
	strcpy(PRIM->Formato , ingreso_primerformato);
	PRIM->Tamanio = ingreso_primertamanio;
	//Puntero apunta a sus datos y los carga por primera vez

	PRIM->prox = NULL; //Puntero principal punta a Nulo por ser el primero
	aux = PRIM;  //Resguardo el puntero principal

	printf("¿Desea ingresar otra operacion? (s/n) : ");
	scanf(" %c", &rta_carga);
	system("cls");

	if (rta_carga == 's'){
		habilitador = 1;
	}else {
		habilitador = 0;
	}

	while (habilitador == 1){ 
		fflush(stdin);

		char ingreso_nombre[30];
		char ingreso_formato[7];
		float ingreso_tam;

		printf("NOMBRE DE ARCHIVO : ");
		gets(ingreso_nombre);
		printf("\n");

		printf("FORMATO : ");
		gets(ingreso_formato);
		printf("\n");

		printf("TAMANIO : ");
		scanf("%f", &ingreso_tam);
		printf("\n");
	
		getchar();
		system("cls");

		F_puntero nuevo; //Creamos nuevo nodo con el mismo formato 
		nuevo = malloc(sizeof(NODO)); //Este nuevo nodo tendrá el tamaño necesario

		//Cargamos el NODO
		strcpy(nuevo->NombreArchivo , ingreso_nombre);
		strcpy(nuevo->Formato , ingreso_formato);
		nuevo->Tamanio = ingreso_tam;

		//Ordenamos con respecto a TAMAÑO de mayor a menor 
		if(aux->Tamanio >= ingreso_tam){

			//Lo siguiente hace que el nodo se inserte a lo ultimo
			nuevo->prox = NULL;
			aux->prox = nuevo;

		} else if(PRIM->Tamanio <= ingreso_tam){
			//Lo siguiente hace que el nodo se inserte primero
			nuevo->prox = PRIM;
			PRIM = nuevo;

		} else {
			//Lo siguiente recorre la lista y lo inserta donde corresponde
			F_puntero aux_2; // Creo un auxiliar para recorrer a partir de él
			F_puntero actual;

			aux_2 = PRIM; 

			while(aux_2->Tamanio >= ingreso_tam){ 
				actual = aux_2;
				aux_2 = aux_2->prox; 
			}
			actual->prox = nuevo;
			nuevo->prox = aux_2;
			// Los colocamos de nuevo al principio
			aux_2 = PRIM;
			actual = PRIM;
			}

		printf("\n");
		printf("¿Desea ingresar otra operacion? (s/n) : ");
		scanf(" %c", &rta_carga);
		system("cls");

		if (rta_carga == 's'){
			habilitador = 1;
		}else {
			habilitador = 0;
		}

	} // Fin Bucle While

	printf ("\nPROCESO DE GUARDADO DE ARCHIVO : ");
	printf("\n");
	printf ("\nPresione cualquier tecla para continuar... ");
	getchar();
	system("cls");

	imprimir_lista(PRIM); //Procedimiento que resguarda las listas.  



	return 0;

} //Cierre de bloque principal

void imprimir_lista(F_puntero PRIM){
	FILE *arch = fopen("Resg_Computex.txt", "a");  //Nombre del archivo
	if(arch == NULL){
		perror("Error en la creacion del archivo\n\n");
	} else {
		//Variables que utilizaremos luego
		time_t t;
		struct tm *tm;
		char fechayhora[100];

		t=time(NULL);
  		tm=localtime(&t);
  		strftime(fechayhora, 100, "%d/%m/%Y", tm);

		fprintf(arch, "---FECHA DE OPERACION ->|%s|-\n", fechayhora);
		fflush(arch);
		while (PRIM != NULL){ //Hasta no llegar al final el puntero resguarda todos los datos. 
			fprintf(arch," NOMBRE : %s", PRIM->NombreArchivo);
			fprintf(arch," FORMATO :%s", PRIM->Formato);
			fprintf(arch," TAMANO : %.2f", PRIM->Tamanio);
			fprintf(arch,"\n");
			PRIM = PRIM->prox;
			fflush(arch);
		}
		fprintf(arch, "\n");
		fclose(arch);
		printf("Datos guardados satisfactoriamente...\n"); 
		printf("Presione cualquier tecla para continuar...\n");
		getchar();	}
}

