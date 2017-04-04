#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define clear() printf("\033[H\033[J") //Para limpiar la pantalla

#include "DL_int.h"


 Lista* Lista_Create (int tam)
 {
	 if (tam < 1) { return NULL; }

	 Lista* p = (Lista *) malloc (sizeof (Lista));
	 // pedimos memoria para el objeto

	 if (!p) { return NULL; }
	 // (!p) es equivalente a (p == NULL)

	 p->max = tam;

	 p->lista = (int *) malloc (sizeof (int) * p->max);
	 // pedimos memoria para el contenedor

	 if (p->lista == NULL) {
	 free (p);
	 // si no se pudo otorgar la memoria para el contenedor,
	 // entonces debemos devolver la memoria del objeto
	 // antes de salir

	 return NULL;
 	}	

	 p->first = p->last = 0;
	 p->empty = TRUE;
	 p->full = FALSE;

	 return p;
 // devolvemos la referencia al nuevo objeto
 }

 void Lista_Destroy (Lista* this)
 {
	 if (!this) { return; }

	 if (this->lista) { free (this->lista); }
	 // devolvemos la memoria del contenedor

	 free (this);
	 // devolvemos la memoria del objeto
 }

 Bool Lista_Insert (Lista* this, int val)
 {
 	//La lista esta llena?
	 if (this->full) { return FALSE; } //Lista llena
	 this->lista[this->last] = val;
	 ++this->last;
	 if (this->last == this->max) {	this->full = TRUE;	}
	 if (this->max == this->first) { this->full = TRUE; }
	 this->empty = FALSE;
	 return TRUE;
 }

 Bool Lista_Remove (Lista* this, int* val)
 {
	 if (this->empty) { return FALSE; }
	 --this -> last;
	 *val = this->lista[this->first];
	 //Tomando el valor de la posicion First
	 //EN lugar de recorrer el array, tomo el valor que esta en 
	 // last y lo guardo

	 this->lista[this->first] = this->lista[this->last];
	 //El ultimo valor lo mando al inicio
	 //Decremento el valor de last y se coloca un lugar atras
	 
	  if (this->first == this->last) 
	  { 
	  	//Significa que esta vacio y no recorro nada
	 	this->empty = TRUE; 
	 	this->first = this ->last = 0;
	 }

	 this->full = FALSE;
	 return TRUE;
}

	 Bool Lista_IsEmpty (Lista* this)
	 {
		 return this->empty;
 	}

 void order(Lista * this){ // FUNCION NO IMPLEMENTADA
 	if (this->first!=0)
 	{
 		int i;
 		int val;
 		//Moviendo elementos a la 1era posicion
 		for (i = 0; i < this -> last; ++i)
 		{
 			val = this->lista[this->last];
 			this->lista[i] = val;
 			this->first++;
 		}
 		this->first = 0;
 		this->last = i;
 	}
 } 

 Bool Lista_IsFull (Lista* this)
 {
	 return this->full;
 }

 void Lista_Clear (Lista* this)
 {
	 this->first = this->last = 0;
	 this->empty = TRUE;
	 this->full = FALSE;
 }

  Bool Lista_FindIf (Lista* this, int val)
 {
//this->lista[this->first];
	 for (size_t i = 0; i < this->last; ++i)
	 {
		 if (this->lista[i] == val) { return TRUE; } //Hay uno igual
		 //Recorre el arreglo al sig elemento
	 }
	 return FALSE;
 }

 /*

LS* LinkedList_Search(LinkedList* this, int val){
 	LS * it = this -> first;
 	//Devuelve la direccion del primer nodo

 	while(it != NULL)
 	{
 		if (it->info == val)
 		{
 			//Encontró el valor buscado
 			return it;
 		}
 		it = it -> next;
 		//Se pasa al siguiente nodo
 	}
 	return NULL; // NO Encontro el elemento, por lo tanto es NULL;
 }

 */


void Lista_Show(Lista * this) // Funcion que imprime la lista en pantalla
{	
	if(this->empty == TRUE)
	{
		printf("\n\t**Lista vacia**\n");
	}

	else
	{

		printf("\n\n\tLISTA [");
		for (size_t i = this->first; i < this -> last; ++i)
		{
			printf(" %d, ",this -> lista[i]);
		}
				printf("]\n\nValor Front: %d\tValor Last: %d",this->first,this->last);
	}
}
