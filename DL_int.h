#ifndef LISTA_INC
#define LISTA_INC

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

/*-----------------------------------------------------------------------------
 *  Definición del ADT: DL_int.h
 *-----------------------------------------------------------------------------*/
 struct Lista_Type
 {
	 int* lista;

	 int first;
	 int last;
	 int max;

	 Bool empty;
	 Bool full;
 };
 typedef struct Lista_Type Lista;
 /**
 * @brief Estructura de la lista en memoria dinamica
 *
 * @param lista Apuntador a un arreglo dinamico
 * @param first Primer elemento en la lista leido de Izq a Der
 * @param last Ultimo elemento de la lista leido de Izq a Der
 * @param max Tamaño maximo del arreglo definido por al TDU
 * @param empty Bandera que indica si la lista esta vacia (TRUE)
 * @param full Bandera que indica que la lista esta llena (TRUE)
 */
 /*--------- Estructura del LA LISTA ------------*/


/*--------- Fuinciones de la Lista ------------*/
	Lista* Lista_Create (int tam);
/**
 * @brief Crea en memoria dinamica un ADT tipo Lista y le asigna un tamaño
 *
 * @param tam es el tamaño maximo que tendra la lista
 */

	void Lista_Destroy (Lista* this);
/**
 * @brief Destruye la lista devlviendo la memoria
 *
 * @param this Referencia a un objeto de tipo Lista
 */

	Bool Lista_Insert (Lista* this, int val);
	/**
 * @brief Agrega un elemento a la lista
 *
 * @param this Referencia a un objeto de tipo Lista
 * @param val El valor del elemento que se agregará a la lista
 */

	Bool Lista_Remove (Lista* this, int* val);
/**
 * @brief Quita al elemento posicionado en first
 *
 * @param val elemento removido que regresa la funcion.
*/

	Bool Lista_IsEmpty (Lista* this);
/**
 * @brief Devuleve Boleano indicando si la lista esta Vacia
 *
 * @param this Referencia a un objeto de tipo Lista
*/

	void order(Lista * this);
/**
 * @brief Trata de ordenar la lista [No implementado]
 *
 * @param this Referencia a un objeto de tipo Lista
*/


	Bool Lista_IsFull (Lista* this);
/**
 * @brief Devuleve Boleano indicando si la lista esta llena
 *
 * @param this Referencia a un objeto de tipo Lista
*/


	Bool Lista_FindIf (Lista* this, int val);
/**
 * @brief Busca un elemento en la lista y regresa TRUE si ya existe o FALSE si no existe
 *
 * @param val valor que va a buscar en la lista
 * @param this Referencia a un objeto de tipo Lista
*/


	void Lista_Show(Lista * this);
/**
 * @brief Imprime en pantalla la lista con formato amigable
 *
 * @param this Referencia a un objeto de tipo Lista
*/
Bool Lista_Search(Lista* this, int val);
/**
 * @brief IBusca un elemento en la lista y lo quita
 *
 * @param this Referencia a un objeto de tipo Lista
 * @param val Valor que buscara en la lista para quitarla
*/

/*--------- Fuinciones de la Lista ------------*/


#endif /* -----ifndef LISTA_INC ------*/