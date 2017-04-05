
 #ifndef CONJUNTO_INC
 #define CONJUNTO_INC value

/**
 * Para operaciones de la lista
 */
 #include "DL_int.h"

/**
 * @param this Apuntador al conjunto tipo lista
 */
void DestruyeConjunto(Lista* this;);

/**
 * @param this Es el apuntador a la lista que implementa el conjunto
 * @return TRUE Si el conjunto está vacio
 */
Bool Vacio_Conjunto(Lista* this);

/**
 * @param min Valor minimo definido por el usuario
 * @param max Valor maximo definido por el usuario
 * @return Lista Apuntador al conjunto de tipo Lista
 */
Lista * Create_Conjunto(int min, int max);

/**
 * @param this Es el apuntador a la lista que implementa el conjunto
 * @param val elemento que va a agregar a la lista del conjunto
 * @return TRUE si logro insertarlo
 */
Bool AddItem_Conjunto(Lista* this, int val);

/**
 * @param min Valor minimo definido por el usuario
 * @param max Valor maximo definido por el usuario
 * @return Lista Apuntador al conjunto de tipo 
 */
Lista* CreaUniverso_Conjunto(int min, int max);

/**
 * @param conjunto regrerencia al apuntador
 * @param val valor del elemento que buscará
 * @return TRUE si encontro elemento identido en conjunto
 */
Bool BuscaEnConjunto(Lista* conjunto, int val);

/**
 * @param conjunto1 Conjunto A que sera operado con B
 * @param conjunto2 Conjunto B que sera operado con A
 * @param conjunto3 Conjunto C resultado de operar A y B
 * @return TRUE si se logro la operacion
 */

	/*
	************ OPERACIONES **********
	*	UNION
	*	INTERSECCCION
	*	IGUALDAD
	*	DIFERENTE
	*	COMPLEMENTO	
	************************************/

Bool Union_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3);

/**
 * @param conjunto1 Conjunto A que sera operado con B
 * @param conjunto2 Conjunto B que sera operado con A
 * @param conjunto3 Conjunto D resultado de operar A y B
 * @return TRUE si se logro la operacion
 */
Bool Interseccion_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3);

/**
 * @param conjunto1 Conjunto A que sera operado con B
 * @param conjunto2 Conjunto B que sera operado con A
 * @param conjunto3 Conjunto E resultado de operar A y B
 * @return TRUE si se logro la operacion
 */
Bool Diferencia_Conjunto(Lista* conjunto1,Lista* conjunto2,Lista* conjunto3);

/**
 * @param conjunto1 Conjunto A que sera operado con B
 * @param conjunto2 Conjunto B que sera operado con A
 * @param conjunto3 Conjunto F resultado de operar A y Universo (U)
 * @return TRUE si se logro la operacion
 */
Bool Complemento_Conjunto(Lista* conjunto1, Lista* universo, Lista* conjunto3);
 
 /**
  * @param conjunto1 Conjunto A que sera comparado con B
  * @param conjunto2 Conjunto B que sera comparado con A
  * @return TRUE si A y B son iguales
  */
Bool Igualdad_Conjunto(Lista * conjunto1, Lista * conjunto2);

 #endif