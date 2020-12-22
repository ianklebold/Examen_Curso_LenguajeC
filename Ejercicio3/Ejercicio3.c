// --Fernández Ian Santiago--
#include <stdio.h>
#include<stdlib.h>
#include <string.h>


//Esto esta agregado por mi ya que tanto el procedimiento como la funcion no fueron declaradas. GRAVE ERROR ;(
char entero(int n, char s[]);
void natural(int n, char s[]); 

int main() {

	int n; 
	char s[n];

	//No se define con anterioridad el valor que tiene la cadena de caracteres "s" MAX_LEN no tiene valor

	/* Como veo que esto lo que hace es convertir un entero a caracter
	 considero que "s" que guarda el entero debe tener la misma longitud
	 que el entero ingresado que es n */

	printf("escribe el entero a convertir : ");
	scanf("%d",&n);  // scanf("%c",&n);  <--- Eso era lo que habia. Esta mal porque n es un entero, la instruccion %c es para caracteres

	entero(n,s);
	printf("%s",s);
}

void natural (int n, char s[]) {  /* string s[] <-- Eso se estaba pasando como argumento lo cual esta mal
									Si bien es un string (Cadena de caracteres) la definicion es char*/
	int i=0, j; char t[n]; //Nuevamente MAX_LEN no tiene un valor definido para esta cadena de caracteres

do {
	t[i++]=n%10+(int)'0';
	}while ((n/=10)>0);  //<-- El do-while estaba mal escrito

for (j=0; j<i; j++){ // Bucle For mal escrito
	s[j]=t[i-j-1];
	s[i]='\0';
		}
}


char entero(int n, char s[]) { //<--- ESTO PASO A SER UNA FUNCION, NO PUEDE SER UN VOID!!!

	if (n<0) {

	  s[0]='-'; 
	  natural(n,s+1);  // -n <--- Como argumento se pasaba -n, lo cual es incorrecto, es n lo que se debe pasar

	} else {
		natural(n,s);
	}

	return s[n]; // La funcion posterior tenia return s; enrealidad esto si devuelve algo por loque debemos colocar que es una funcion

}