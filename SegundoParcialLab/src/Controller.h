#include "libro.h"
#include "editorial.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"

int controller_LoadFromText(LinkedList* pArrayList, int (*pFunc) (FILE*,LinkedList*));

int controller_ListLibro(LinkedList* thisLibro ,LinkedList* thisEditorial);
int controller_OrdenarLibrosPorAutor(LinkedList* pListaLibros);
int controller_saveAsTextMinotauro(char* path , LinkedList* listaLibros);
int controller_saveAsTextDesc(char* path , LinkedList* listaLibros);


/*int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);*/




