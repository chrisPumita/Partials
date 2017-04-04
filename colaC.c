/*
*
* Muestra la codificación del ADT de una Lista Doble Circular
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DL_int.h"

#define clear() printf("\033[H\033[J") // Para limpiar pantalla


	/*
	************ OPERACIONES **********
	*	UNION
	*	INTERSECCCION
	*	IGUALDAD
	*	DIFERENTE
	*	COMPLEMENTO	
	*/
	
Lista * Create_Conjunto(int min, int max){
	//Crea el conjunto en una lista Con cardinalidad entre min y max
	int tam = max-min;
	Lista * miLista = Lista_Create(tam);
	return miLista;
}

Bool AddItem_Conjunto(Lista* this, int val){
	if (Lista_Insert(this,val)==TRUE)
	{
		return TRUE;
	}
	return FALSE;
}

Bool BuscaEnConjunto(Lista* conjunto, int val){
	return Lista_FindIf(conjunto,val);
}

Bool Igualdad_Conjunto(Lista * conjunto1, Lista * conjunto2){
	//COmenzar a recorrer todo el arreglo y compararlo con
	//el otro, tomar Conjunto2 Será la base para comparar

	for (size_t i = 0; i < conjunto1->last; ++i)
	{
		if(Lista_FindIf(conjunto2,conjunto1->lista[i]) != TRUE)
		return FALSE;
	}
	return TRUE;
}

Bool Union_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3){
	//Toma dos conjuntos y hace la operacion union,
	//Verificamos que los conjuntos no esten vacios
	if (Lista_IsEmpty(conjunto1)&&Lista_IsEmpty(conjunto2))
	{
		//Si ambos son TRUE significa que estan vacios ambos
		//Regresamos FALSE para denotar que estan vacios
		return FALSE;
	}

	else if (Igualdad_Conjunto(conjunto1,conjunto2))
	{
		//Si regresa TRUE, es porque ambos conjuntos son iguales y solo se copia un conjunto
		for (size_t i = 0; i < conjunto1 -> last; ++i)
		{
		//Tomo el primer conjunto y lleno por completo el conjunto3
			AddItem_Conjunto(conjunto3,conjunto1->lista[i]);
		}
		return TRUE;
	}

	//Agregamos al 3er conjunto todos los elementos base
	else 
	{
		for (size_t i = 0; i < conjunto1 -> last; ++i)
		{
			//Tomo el primer conjunto y lleno por completo el conjunto3
			AddItem_Conjunto(conjunto3,conjunto1->lista[i]);
		}
		for (size_t i = 0; i < conjunto2 -> last; ++i)
		{
			//Busca si hay elemento igual del conjunto2 en Conjunto3
			if (BuscaEnConjunto(conjunto3,conjunto2->lista[i])!=TRUE)
			{
				//Tomo el primer conjunto y lleno por completo el conjunto3
				AddItem_Conjunto(conjunto3,conjunto2->lista[i]);
			}
		}
	return TRUE;
	}
}


Bool Interseccion_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3){
	//Toma dos conjuntos y hace la operacion Interseccion,
	//Verificamos que los conjuntos no esten vacios
	if (Lista_IsEmpty(conjunto1)&&Lista_IsEmpty(conjunto2))
	{
		//Si ambos son TRUE significa que estan vacios ambos
		//Regresamos FALSE para denotar que estan vacios
		return FALSE;
	}
	else if (Igualdad_Conjunto(conjunto1,conjunto2))
	{
		//Si regresa TRUE, es porque ambos conjuntos son iguales y solo se copia un conjunto
		for (size_t i = 0; i < conjunto1 -> last; ++i)
		{
		//Tomo el primer conjunto y lleno por completo el conjunto3
			AddItem_Conjunto(conjunto3,conjunto1->lista[i]);
		}
		//La interseccion son todos los elementos
		return TRUE;
	}

	else 
	{
		for (size_t i = 0; i < conjunto1 -> last; ++i)
		{
			//Busca si hay elemento igual del conjunto2 en Conjunto3
			if (BuscaEnConjunto(conjunto2,conjunto1->lista[i]))
			{
				//Tomo el primer conjunto y lleno por completo el conjunto3
				AddItem_Conjunto(conjunto3,conjunto1->lista[i]);
			}
		}
	return TRUE;
	}

}



/*-----------------------------------------------------------------------------
 *                           Driver program
 *-----------------------------------------------------------------------------*/
 int main(void)
 {

	// Lista* miLista = Lista_Create (5);
	int min, max;
	min = 5;
	max = 10;

	Lista* A = Create_Conjunto (min,max);
	Lista* B = Create_Conjunto (min,max);
	Lista* C = Create_Conjunto (min,max);
	Lista* D = Create_Conjunto (min,max);


		AddItem_Conjunto(A,1);
		AddItem_Conjunto(A,2);
		AddItem_Conjunto(A,3);


		AddItem_Conjunto(B,3);
		AddItem_Conjunto(B,4);
		AddItem_Conjunto(B,5);


//COMPARANDO CONJUNTOS
		if (Igualdad_Conjunto(A,B)==TRUE)
		{
			printf("SON IGUALES\n");
		}
		else{
			printf("NO SON IGUALES\n");
		}
		
	Union_Conjunto(A,B,C);
	printf("\nCOnjunto A\n");
	Lista_Show(A);
	printf("\nConjunto B\n");
	Lista_Show(B);
	printf("\nConjunto C [UNION]\n");
	Lista_Show(C);

	Interseccion_Conjunto(A,B,D);
		printf("\nConjunto C [INTERSECCION]\n");
	Lista_Show(D);



	 /*
	 int menuOp, valor;
	char mje[50]= "BIENVENIDO";
	 // creamos a un objeto del tipo Lista
	do
	{
		clear();
		printf("MENSAJE: >>>\t%s\n",mje);
		Lista_Show(miLista);

		printf("\n+---------------------------+\n");
		printf("\nOpciones:\n1 Agregar nuevo elemento\n2 Quitar un elemento\n3 Buscar numero\n4 Salir \nDame una opcion: ");

		scanf("%i",&menuOp);
		if(menuOp==1)
		{
			if (Lista_IsFull(miLista)== TRUE){
				 strcpy( mje, "LISTA LLENA" );
			}
			else{
				printf ("Nuevo valor: ");
				scanf ("%d", &valor);
				Lista_Insert(miLista, valor);
				strcpy( mje, "ELEMENTO AGREGADO" );
			}
		}

		if(menuOp==2)
		{
			int date;
			int *p = &date;
			if(Lista_Remove(miLista, p)){
				strcpy( mje, "Se eliminó elmento\n");
			}
		}


		if(menuOp==3)
		{
			printf ("Busca numero: ");
			scanf ("%d", &valor);
			if(Lista_FindIf(miLista, valor)== TRUE){
				strcpy( mje, "Ya existe elemento\n");
			}
			else{
				strcpy( mje, "No existe elemento\n");
			}
		}

			
	}
			while(menuOp==1 || menuOp==2 || menuOp==3 ); 

	 */
 Lista_Destroy (A);
 Lista_Destroy (B);
 Lista_Destroy (C);


 }