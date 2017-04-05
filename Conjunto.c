/*
*
* Muestra la codificación del ADT de una Lista Doble Circular
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DL_int.h"

	/*
	************ OPERACIONES **********
	*	UNION
	*	INTERSECCCION
	*	IGUALDAD
	*	DIFERENTE
	*	COMPLEMENTO	
	*/

/*	*****************************************
	* FUNCIONES LOGICAS						*
	*****************************************
*/

Bool Vacio_Conjunto(Lista* this){
	return Lista_IsEmpty(this);
}
	
Lista * Create_Conjunto(int min, int max)
{
	//Crea el conjunto en una lista Con cardinalidad entre min y max
	int tam = max-min;
	Lista * miLista = Lista_Create(tam+1);
	return miLista;
}

Bool AddItem_Conjunto(Lista* this, int val)
{
	if (Lista_Insert(this,val)==TRUE)
	{
		return TRUE;
	}
	return FALSE;
}

Bool BuscaEnConjunto(Lista* conjunto, int val)
{
	return Lista_FindIf(conjunto,val);
}

Lista* CreaUniverso_Conjunto(int min, int max)
{
	//Crea al universo y lo llena de forma automatica considerando al valor
	//Maximo y al valor minimo

	Lista * UNI = Create_Conjunto(min,max);
	for (size_t i = 0; i < UNI->max; ++i)
	{
		//Llenamos el universo
		AddItem_Conjunto(UNI,min);
		min++;
	}
	return UNI;
}

Bool Igualdad_Conjunto(Lista * conjunto1, Lista * conjunto2)
{
	//COmenzar a recorrer todo el arreglo y compararlo con
	//el otro, tomar Conjunto2 Será la base para comparar

	for (size_t i = 0; i < conjunto1->last; ++i)
	{
		if(Lista_FindIf(conjunto2,conjunto1->lista[i]) != TRUE)
		return FALSE;
	}
	return TRUE;
}

void DestruyeConjunto(Lista* this)
{
	Lista_Destroy(this);
}

/*	*****************************************
	************ OPERACIONES ****************
	*	UNION 								*
	*	INTERSECCCION 						*
	*	IGUALDAD 							*
	*	DIFERENTE 							*
	*	COMPLEMENTO	 						*
	*****************************************
*/

Bool Union_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3)
{
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


Bool Interseccion_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3)
{
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


Bool Diferencia_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3)
{
	/*
	* Diferencia. La diferencia entre dos conjuntos A y B es el conjunto A \ B 
	* que contiene todos los elementos de A que no pertenecen a B.
	*/
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
		//Si regresa TRUE, es porque ambos conjuntos son iguales 
		// Por lo tanto no hay Diferencia Regresamos FALSE para denotar
		//que el no hay elementos que guardar
		return FALSE;
	}

	else{
		for (size_t i = 0; i < conjunto2 -> last; ++i)
		{
			//Busca si hay elemento igual del conjunto1 en Conjunto2
			if (BuscaEnConjunto(conjunto2,conjunto1->lista[i])!=TRUE)
			{
				AddItem_Conjunto(conjunto3,conjunto1->lista[i]);
			}
		}
		return TRUE;
	}
}


Bool Complemento_Conjunto(Lista* conjunto1, Lista* universo, Lista* conjunto3)
{
		/*
		* El complemento de un conjunto A es el conjunto A∁ que contiene 
		* todos los elementos que no pertenecen a A.
		*/
		//Toma dos conjuntos y hace la operacion Interseccion,
		//Creamos el universo

	//Verificamos que los conjuntos no esten vacios
		if (Lista_IsEmpty(conjunto1))
		{
			//Si Conjunto1 = TRUE significa que esta vacio
			//Por lo tanto el complenento es todo el universo
			for (size_t i = 0; i < universo -> last; ++i)
			{
			//Tomo el primer conjunto y lleno por completo el conjunto3
				AddItem_Conjunto(conjunto3,universo->lista[i]);
			}
			//La interseccion son todos los elementos
			return TRUE;
		}

		else if (Igualdad_Conjunto(universo,conjunto1))
		{
			//Si regresa TRUE, es porque U y conjunto1 son iguales 
			// Por lo tanto no hay Complemento Regresamos FALSE para denotar
			//que el no hay elementos que guardar
			return FALSE;
		}

		else
		{
			for (size_t i = 0; i < universo -> last; ++i)
			{
				//Tomo elemento i de universo y lo comparo con conjunto1
				//Si no encuentra alguno, entonces guarda en conjunto 3 el valor
				if (BuscaEnConjunto(conjunto1,universo->lista[i])!=TRUE)
				{
					//Tomo el primer elemento del Universo y verifico:
					// Si existe en conjunto
					AddItem_Conjunto(conjunto3,universo->lista[i]);
				}
			}
			return TRUE;
		}
	}


