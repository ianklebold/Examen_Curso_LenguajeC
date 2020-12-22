#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char devolucion(char *punt,char cadena[],int n); //Devolverá un caracter
int main(){

	char cadena[100], *punt, result; //Definimos nuetra cadena de caracteres, puntero y la variable que nos dará el resultado
 	int n;

 	printf("Ingrese la cadena de caracter: "); gets(cadena); //Ingresamos la cadena de caracteres
 	

 	n = strlen(cadena); //n = longitud de la cadena 
 	punt = (char *)malloc(n); //reserve dinamica de memoria para el puntero

 	result = devolucion(punt,cadena,n); //Invocamos a la funcion

 	printf("Las cadena copiada comienza con : %c", result); //Resultado de la funcion
 	free(punt); //Liberamos memoria reservada

	return 0;
}

char devolucion(char *punt,char cadena[],int n){
	int i, j=0; //Aqui tenemos indices que nos ayudaran a copiar todo en el puntero
	if (punt==NULL){ 
 		printf("Error: memoria llena"); exit(0); 
 	}

 	for (i=0; i<strlen(cadena); i++) //copiamos lo que habia en cadena al puntero con el tamaño necesario
 		{ punt[j] = cadena[i]; 
 		  j++; 
 		}
 	return punt[0];  // Retornamos el valor del primer caracter
}

// Este programa seria aun mas interesante si pasamos como parametro el valor del caracter que a nosotros nos gustaria ver
// El programa lo hice de tal forma que esa oportunidad de saber el caracter en determinada posicion sea sencilla. 