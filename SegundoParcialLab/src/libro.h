/*
 * libro.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Ludo
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char titulo[50];
	char autor[50];
	int precio;
	int idEditorial;
}eLibro;

eLibro* Libro_new();
eLibro* Libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* idEditorialStr);


int Libro_setId(eLibro* this,int id);
int Libro_getId(eLibro* this,int* id);

int Libro_setTitulo(eLibro* this,char* titulo);
int Libro_getTitulo(eLibro* this,char* titulo);

int Libro_setAutor(eLibro* this,char* autor);
int Libro_getAutor(eLibro* this,char* autor);

int Libro_setPrecio(eLibro* this,int precio);
int Libro_getPrecio(eLibro* this,int* precio);

int Libro_setIdEditorial(eLibro* this,int idEditorial);
int Libro_getIdEditorial(eLibro* this,int* idEditorial);

void MostrarUnLibro(eLibro* UnLibro, LinkedList* thisEditorial);

int Libro_compararPorAutor(void* x, void* y);

int FiltrarEditorialMinotauro(LinkedList* thisEditorial);
int filtrarMinotauro(void* unLibro);
int AplicarDescuentoLibro(void* unLibro);
void Libro_delete();

#endif /* LIBRO_H_ */
