/*
 * libro.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Ludo
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "libro.h"
#include "validaciones.h"
#include "LinkedList.h"
#include "editorial.h"
#include "controller.h"


eLibro* Libro_new()
{
	eLibro* pLibro = (eLibro*)malloc(sizeof(eLibro));
	if(pLibro!= NULL)
	{
		Libro_setId(pLibro,0);
		Libro_setTitulo(pLibro,"");
		Libro_setAutor(pLibro,"");
		Libro_setPrecio(pLibro,0);
		Libro_setIdEditorial(pLibro,0);
	}
	return pLibro;
}

eLibro* Libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* idEditorialStr)
{
	eLibro* pLibroParam;
	int auxId;
	int auxPrecio;
	int auxIdEditorial;
	pLibroParam = Libro_new();
	if(pLibroParam != NULL && idStr != NULL && tituloStr !=NULL && autorStr != NULL && precioStr != NULL)
	{
		auxId = atoi(idStr);
		auxPrecio = atoi(precioStr);
		auxIdEditorial = atoi(idEditorialStr);
		Libro_setId(pLibroParam, auxId);
		Libro_setTitulo(pLibroParam, tituloStr);
		Libro_setAutor(pLibroParam, autorStr);
		Libro_setPrecio(pLibroParam, auxPrecio);
		Libro_setIdEditorial(pLibroParam,auxIdEditorial);
	}

	return pLibroParam;
}

int Libro_setId(eLibro* this,int id)
{
	int retorno = -1;
	if (this != NULL && id>=0)
	{
		this ->id = id;
		retorno = 0;
	}
	return retorno;
}
int Libro_getId(eLibro* this,int* id)
{
	int retorno = -1;

	if (this != NULL && id != NULL)
	{
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}

int Libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
	if (this != NULL && titulo != NULL && VerificarNombre(titulo))
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}
	return retorno;
}

int Libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;

	if (this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 0;
	}
	return retorno;
}

int Libro_setAutor(eLibro* this, char* autor)
{
	int retorno = -1;
	if (this != NULL && autor != NULL && VerificarNombre(autor))
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}
	return retorno;
}

int Libro_getAutor(eLibro* this,char* autor)
{
	int retorno = -1;

	if (this != NULL && autor != NULL)
	{
		strcpy(autor,this->autor);
		retorno = 0;
	}
	return retorno;
}

int Libro_setPrecio(eLibro* this,int precio)
{
	int retorno = -1;
	if (this != NULL && precio>=0)
	{
		this ->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Libro_getPrecio(eLibro* this,int* precio)
{
	int retorno = -1;

	if (this != NULL && precio != NULL)
	{
		*precio=this->precio;
		retorno = 0;
	}
	return retorno;
}

int Libro_setIdEditorial(eLibro* this,int idEditorial)
{
	int retorno = -1;
	if (this != NULL && idEditorial>=0)
	{
		this ->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}
int Libro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno = -1;

	if (this != NULL && idEditorial != NULL)
	{
		*idEditorial=this->idEditorial;
		retorno = 0;
	}
	return retorno;
}


void MostrarUnLibro(eLibro* UnLibro, LinkedList* thisEditorial)
{
	int id;
	char titulo[50];
	char autor[50];
	int precio;
	char nombreEditorial[50];

	Libro_getId(UnLibro, &id);
	Libro_getTitulo(UnLibro, titulo);
	Libro_getAutor(UnLibro, autor);
	Libro_getPrecio(UnLibro, &precio);
	Obtener_Editorial(UnLibro, thisEditorial, nombreEditorial);


	printf("%-4d       %-30s   %-25s   %-4d       %-20s \n",id,titulo,autor,precio,nombreEditorial);
}

int Libro_compararPorAutor(void* x, void* y)
{
	int retornoCompara;
    char autor1[25];
    char autor2[25];

    eLibro* unLibro;
    eLibro* otroLibro;

    unLibro = (eLibro*) x; //unboxing de la variable, desempaquetar.
    otroLibro = (eLibro*) y;
    Libro_getAutor(unLibro, autor1);
    Libro_getAutor(otroLibro, autor2);

    retornoCompara = strcmp(autor1, autor2);

   return retornoCompara;
}


int filtrarMinotauro(void* unLibro)
{
    int retorno = 0;
    eLibro* auxLibro;
    int auxId;

    auxLibro= (eLibro*) unLibro;

    Libro_getIdEditorial(auxLibro, &auxId);

    if (auxId == 4)
    {
    	retorno = 1;
    }

    return retorno;
}

/** PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200) */
// laburo sobre la lista de libros

int AplicarDescuentoLibro(void* unLibro)
{
	eLibro* auxLibro;
	int retorno;
	int id;
	int precio;
	int descuento;
	retorno = 0;

	if(unLibro != NULL)
	{
		auxLibro = (eLibro*)unLibro;
		Libro_getIdEditorial(auxLibro, &id);
		Libro_getPrecio(auxLibro, &precio);

		if(id == 1 && precio >= 300 ) //20%des editorial planeta
		{
			descuento = precio * 0.8;
			Libro_setPrecio(auxLibro,descuento);
			retorno = 1;
		}
		else
		{
			if(id == 2 && precio <= 200)
			{
				descuento = precio * 0.9;
				Libro_setPrecio(auxLibro,descuento); //10%de ed siglo
				retorno = 1;
			}
		}
	}
	return retorno;
}


