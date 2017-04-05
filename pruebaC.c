#include <stdio.h>
#include "Conjunto.h"
#define clear() printf("\033[H\033[J") // Para limpiar pantalla

/**
 * @return devuelve valo entero que es el numero del menú
 */
int menu(){
	int opcion = 0;
	//clear();
	do {

		printf("\t+----------+-----------+-------------+----------+-----------+----------+-------+\n");
		printf("\t|  Nuevo   |    Ver    | Operaciones | Comparar |    Ver    | Creditos | Salir |\n");
		printf("\t| Conjunto | Max y Min |             |  A y B   | Conjuntos |     ?    |   X   |\n");
		printf("\t|  --> 1   |  --> 2    |   --> 3     |  --> 4   |   --> 5   | --> 6    | --> 0 |\n");
		printf("\t+----------+-----------+-------------+----------+-----------+----------+-------+\n");
		printf("Elija una opcion: ");
		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 6);

	printf ("\n");
	return opcion;
}

/**
 * @return devuelve entero que corresponde al numero de operacion que realizará
 */
int menuOpera(){
	int opcion = 0;

	do {

		printf("\t+---------+--------------+-------------+-------------+--------+\n");
		printf("\t|  UNION  | INTERSECCION | DIFERENCIA  | COMPLEMENTO | SALIR  |\n");
		printf("\t|  --> 1  |     --> 2    |   --> 3     |  --> 4      |  --> 0 |\n");
		printf("\t+---------+--------------+-------------+-------------+--------+\n");
		printf("Elija una operacion: ");
		scanf ("%d", &opcion);
	} while (opcion < 0 || opcion > 6);

	printf ("\n");
	return opcion;
}

/**
 * @param this Apuntador del conjunto de tipo Lista
 * @param min Valor minimo definido por el usuario
 * @param max Valor maximo definido por el usuario
 * @param val Elemento que será insertado en el conjunto
 */
 void LlenaConjunto(Lista * this, int min, int max, int val){
 	if (val >= min && val <= max)
 	{
 		AddItem_Conjunto(this,1);
 	}
 }

/**
 * Muestra informacion del programa y creditos
 */
 void Info(){
 		printf("\t\t***CREDITOS***\n");
    	printf("\tPROGRAMADOR: Pioquinto Hernandez Christian René\n");
    	printf("\t\t\t(RCGS)\n");
    	printf("\tGrupo: 03\n");
    	printf("\tEstructrua de Datos\n");
 		printf("* Para estas operaciones se asignara una letra para hacer cada operacion\n");
		printf("* Ejemplo: Dos elementos inicales seran A y B\n");
		printf("+---------------+----------------------+\n");
		printf("| TABLA DE REFERENCIA DE CONJUNTOS     |\n");
		printf("+-------+------------------------------+\n");
		printf("|LETRA| Operacio que almacena          |\n");
		printf("+-------+------------------------------+\n");
		printf("|  A  | Es el PRIMER conjunto          |\n");
		printf("+-------+------------------------------+\n");
		printf("|  B  | Es el SEGUNDO conjunto         |\n");
		printf("+-------+------------------------------+\n");
		printf("|  C  | Es la UNION de A y B           |\n");
		printf("+-------+------------------------------+\n");
		printf("|  D  | Es la INTERSECCION de A y B    |\n");
		printf("+-------+------------------------------+\n");
		printf("|  E  | Es el la DIFERENCIA de A y B   |\n");
		printf("+-------+------------------------------+\n");
		printf("|  F  | Es el COMPLEMENTO de A y U*    |\n");
		printf("+-------+------------------------------+\n");
		printf("|  U* | Representa el UNIVERSO         |\n");
		printf("+-------+------------------------------+\n");

 }



/** Driver Program
 * @return devielve 0 se ejecuto de forma correcta
 */
int main()
{
	/**
	 * Limpiamos la pantalla para iniciar el programa
	 */
	 clear();

	 /*
	 Definimos las variables y algunas las inicializamos
	  */
	 int min=0, max=0;
	 int opcion; //para el menu
	 int op; //Para las operaciones
	 int i=0,j=0;
	 int val, val2;
	 Bool llenoA = FALSE;
	 Bool llenoB = FALSE;
	 /*
		* Para estas operaciones se asignara una letra para hacer cada operacion
		* Ejemplo: Dos elementos inicales seran A y B
		+---------------+----------------------+
		| TABLA DE REFERENCIA DE CONJUNTOS     |
		+-------+------------------------------+
		|LETRA| Operacio que almacena          |
		+-------+------------------------------+
		|  A  | Es el PRIMER conjunto          |
		+-------+------------------------------+
		|  B  | Es el SEGUNDO conjunto         |
		+-------+------------------------------+
		|  C  | Es la UNION de A y B           |
		+-------+------------------------------+
		|  D  | Es la INTERSECCION de A y B    |
		+-------+------------------------------+
		|  E  | Es el la DIFERENCIA de A y B   |
		+-------+------------------------------+
		|  F  | Es el COMPLEMENTO de A y U*    |
		+-------+------------------------------+
		|  G  |      				           |
		+-------+------------------------------+
		|  U* | Representa el UNIVERSO         |
		+-------+------------------------------+
	 */
	 	while(min<=0){	
    		printf("Dame el valor del Minimo\n");
    		scanf("%d",&min);
    	}
    	while(max<=0){	
    		printf("Defina el valor del Maximo\n");
    		scanf("%d",&max);
    	}

	Lista* A = Create_Conjunto (min,max);
	Lista* B = Create_Conjunto (min,max);
	Lista* C = Create_Conjunto (min,max);
	Lista* D = Create_Conjunto (min,max);
	Lista* E = Create_Conjunto (min,max);
	Lista* F = Create_Conjunto (min,max);
	Lista* U = CreaUniverso_Conjunto(min,max);

do{
	 opcion = menu();
	 switch ( opcion )
        {
	
            case 1:

						while(val!= -1)
						{
							printf("--INGRESE ELEMTOS DE A -----\n");
							if (llenoA!= TRUE)
							{
								printf("Agregados a A: %d >",i);
								printf("Escriba -1 para agregar elementos a B\nDame valor para Conjunto A:\n");
								scanf("%d",&val);
								if (val>-1)
								{
									if (val>=min && val <=max)
									{
										if (AddItem_Conjunto(A,val)!= TRUE)
										{
											printf("No se puede agregar mas elemento\n");
											llenoA = TRUE;
										}
										else i++;
											
									}
									else
									{
										printf("Elemento no pertenece a UNIVERSO\n");
									}
								}

							}
							else{
								val=-1;
							}
							
						}
					
						while(val2!=-1)
						{
						printf("--INGRESE ELEMTOS DE B -----\n");
							if (llenoB!=TRUE)
							{
								printf("Agregados a B: %d >",j);
								printf("Escriba -1 para terminar\nDame valores para Conjunto B:\n");
								scanf("%d",&val2);
								if (val2>-1)
								{
									if (val2>=min && val2 <=max)
									{
										if (AddItem_Conjunto(B,val2)!= TRUE)
										{
											printf("No se puede agregar mas elemento\n");
											llenoB = TRUE;
										}
										else j++;
											
									}
									else
									{
										printf("Elemento no pertenece a UNIVERSO\n");
									}
								}
							}
							else{
								val2=-1;
							}
						}

			break;
            case 2:
            	printf("Valor de Min %d\n",min);
            	printf("Valor de Max %d\n",max );
            break;
            case 3:
            	op = menuOpera();
            	switch (op){

	            	case 1:
	            			Union_Conjunto(A,B,C);
	            			printf("\nA:");
	            			Lista_Show(A);
	            			printf("\nB:");
            				Lista_Show(B);
            				printf("\nC:");
            				Lista_Show(C);
	            	break;

	            	case 2:
	            			Interseccion_Conjunto(A,B,D);
	            			printf("\nA:");
	            			Lista_Show(A);
	            			printf("\nB:");
            				Lista_Show(B);
            				printf("\nD:");
            				Lista_Show(D);
	            	break;

	            	case 3:
	            			Diferencia_Conjunto(A,B,E);
	            			printf("\nA:");
	            			Lista_Show(A);
	            			printf("\nB:");
            				Lista_Show(B);
            				printf("\nE:");
            				Lista_Show(E);
	            	break;

	            	case 4:
	            		Complemento_Conjunto(A,U,F);

	            			printf("\nA:");
	            			Lista_Show(A);
	            			printf("\nUNIVERSO:");
            				Lista_Show(U);
            				printf("\nF:");
            				Lista_Show(F);
            				printf("\n");
	            	break;
            	}

            break;
            case 4:
            				if (Igualdad_Conjunto(A,B)==TRUE)	{	printf("Los conjuntos A y B SON IGUALES\n");	}
							else {	printf("Los conjuntos A y B NO SON IGUALES\n");	}
            break;

            case 5:
            		printf("\nA:");
            		Lista_Show(A);
            		printf("\nB:");
            		Lista_Show(B);
            		printf("\nC:");
            		Lista_Show(C);
            		printf("\nD:");
            		Lista_Show(D);
            		printf("\nE:");
            		Lista_Show(E);
            		printf("\nF:");
            		Lista_Show(F);
            		printf("\nUNIVERSO:");
            		Lista_Show(U);
            		printf("\n");
            break;
            case 6:
            	Info();
            break;
            case 7:
            	clear();
            break;

        }

    } while(opcion!=0);

	 Lista_Destroy (A);
	 Lista_Destroy (B);
	 Lista_Destroy (C);
	 Lista_Destroy (D);
	 Lista_Destroy (E);
	 Lista_Destroy (F);
	 Lista_Destroy (U);

	return 0;
}