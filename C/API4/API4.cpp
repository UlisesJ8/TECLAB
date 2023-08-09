#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int validarMinimo(char texto[],int minimo){
int num;
do{
	
	printf("%s", texto);
	scanf("%i", &num);
	
}while(num <= minimo ); 

return num;
}


int validarRangos(char texto[], int min, int max){

int num;
int contador = 0;

	printf("%s", texto);	
	scanf("%i", &num);
	
while(num < min || num > max){
	printf("\n Ingrese un numero entre los rangos establecidos por favor:");
	scanf("%i", &num);
}

return num;
}

void ordenarImprimirArray(int array[], int contador){
	
	int aux;	
 if(contador >1 ){ //condicional para acomodar el array despues de que contador supera a 1 

	for(int l = 0; l < contador-1 ; l++){  // bucle for para acomodar el array
	 	
		for(int k = 0; k < (contador-1)-l; k++){
			if(array[k] > array[k+1]){
				aux = array[k];
	  			array[k] = array[k+1];
	  			array[k+1] = aux;
			}
		}
		
 	}
 }

printf("\n Numeros Ingresados: ");
for(int j = 0 ; j < contador; j++){  // bucle para escribir el array ordenado previamente  
	if(j == contador-1){
		printf("%i ", array[j]);
	}else{
		printf("%i /", array[j]);
	}
}
	

}


int main(){
	int min, max, intentos, num, aleatorio, contador = 0;
	bool flag = true;
	
printf("Bienvenidos al juego de adivinanza");

// se llama a la funcion validarMinimo para que el rango inferior sea mayor a 0
char mensaje[] = "\n Ingrese el rango inferior del numero aleatorio que desea generar:";
min = validarMinimo(mensaje,0);
// se llama a la funcion validarMinimo para que el rango mayor sea mayor a el minimo.
char mensaje1[] = "\n Ingrese el rango mayor del numero aleatorio que desea generar:";
max = validarMinimo(mensaje1, min);

 //se llama a la funcion validarMinimo para que el usuario ingrese numeros mayores a 0.
 char mensaje2[] = "\n Ingrese un numero de intentos:";
intentos = validarMinimo(mensaje2,0);

const int cantidad = intentos;
int array[cantidad];

aleatorio = rand() % ((max-min)+1) + min;  // generar numero Aleatorio

do{ // bucle do while que saldra cuando el numero sea igual al aleatorio o supere la cantidad de intentos necesarios.

//funcion para validar que el numero generado este entre los rangos establecidos
char mensaje3[] = "\n Ingrese el numero que crees que se genero: ";
int num = validarRangos(mensaje3,min, max);

bool validarRepetido = false;

if(contador >= 1){   // Utilizo un if para validar que el array que se encuentra por debajo ya tenga guardado un numero para realizar la comparacion con el numero ingresado

		do{  // utilizo un do while para que se repita hasta que el numero ingresado no se encuentre dentro del array.
			validarRepetido = false;
				for(int i = 0; i < contador; i++){  // utilizo un bucle for para recorrer todo el array con los numeros ingresados hasta el momento y compararlo con el numero ingresado.
					if (array[i] == num){ // utilizo un if para ir comparando todos los numeros ingresados con el numero ingresado por teclado. si se da esta condicion ingresa al if y ejecuta el bloque de codigo y rompe el for con el break.
		 				
						// llamando esta funcion valido que ingrese un numero que este entre los rangos
						char mensaje4[] = "\n Ingrese un numero que no este repetido:  ";
						num = validarRangos(mensaje4,min, max);
		 				validarRepetido = true;
		 				break;
					}	
				}
		}while(validarRepetido == true);
}

intentos = intentos - 1;

array[contador] = num; // guardo en el array los valores de num ingresado por teclado 
contador = contador+1;

if (num > aleatorio){  // condicional if para determinar si el numero ingresado es menor al aleatorio 
printf(" El numero ingresado es mayor al aleatorio");

}else if (aleatorio == num){ // condicional else if para determinar si el aleatorio es igual al numero ingresado por teclado y de esta manera lograr salir del bucle principal do while.
	flag = false;
	intentos = intentos + 1;
}else{
printf(" El numero ingresado es menor al aleatorio");
}




printf("\n Lleva %i intentos ", contador );
printf(" y le quedan %i intentos", intentos);
// llamo a la funcion que ordena el array y los imprime, paso los valores necesarios por parametro.

ordenarImprimirArray(array, contador);

printf("\n");

}while(intentos > 0 && flag == true);


if(intentos > 0){
printf("\n Usted gano el juego!!!!!!!");
printf("\n El numero era %i", aleatorio);

}else{
printf("\n Usted perdio el juego:( ");
printf("\n El numero era %i", aleatorio);
}


return 0;

}



