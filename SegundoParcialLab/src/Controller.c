//LUDMILA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libro.h"
#include "editorial.h"
#include "parser.h"
#include "validaciones.h"

// EL CONTROLLER SOLO ABRE Y CIERRA CON LO Q TIENE Q TRABAJAR PARSER
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_LoadFromText(LinkedList* pArrayList, int (*pFunc) (FILE*,LinkedList*))
{
	FILE* pArchivo;
	int retorno = -1;
	char path[50];

	if(pFunc != NULL && pArrayList != NULL)
	{
		myGets(path,"Ingrese nombre del archivo que desea abrir\n",sizeof(path));
		strcat(path,".csv");
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			retorno = pFunc(pArchivo,pArrayList);
			fclose(pArchivo);
			printf("Parser ok \n");
		}
	}
	printf("\n%d",ll_len(pArrayList));
    return retorno;
}



/// brief Listar empleados
///  \param path char*
/// \param pArrayListEmployee LinkedList*
/// \return int
/// */

int controller_ListLibro(LinkedList* thisLibro ,LinkedList* thisEditorial)
{
	int retorno = -1;
	eLibro* pLibro;
	int len;

	len= ll_len(thisLibro);
	if(thisLibro != NULL)
	{
		printf("Id Libro   Titulo                           Autor                       Precio     Nombre Editorial\n");
		for(int i=0; i< len;i++)
		{
			pLibro = (eLibro*)ll_get(thisLibro,i);
			MostrarUnLibro(pLibro,thisEditorial);
			retorno = 1;
		}
	}
	return retorno;
}

int controller_OrdenarLibrosPorAutor(LinkedList* pListaLibros)
{
    int len;
    int retornoSort;
    int retorno = 0;
    len = ll_len(pListaLibros);

    if(len > 1)
    {
        puts("\nSe esta ordenando la lista, esto puede tardar unos minutos...");
        retornoSort = ll_sort(pListaLibros, Libro_compararPorAutor, 1);
        if(retornoSort == 0)
        {
            retorno = 1;
        }
        else
        {
            puts("\nHubo un error al tratar de ordenar la lista.");
        }
    }
    else
    {
        puts("\nNo hay libros suficientes en la lista para efectuar el ordenamiento.");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsTextMinotauro(char* path , LinkedList* listaLibros)
{
	FILE* pArchivo;
	eLibro* pLibro;
	LinkedList* listaMinotauro;
	int retorno;
	int len;
	int idAux;
	char tituloAux[50];
	char autorAux[50];
	int precioAux;
	retorno = 0;

	if(path != NULL && listaLibros != NULL &&  !ll_isEmpty(listaLibros))
	{
		listaMinotauro = ll_filter(listaLibros, filtrarMinotauro);

		len = ll_len(listaMinotauro);
		if(listaMinotauro != NULL)
		{
			pArchivo = fopen(path,"w");
			fprintf(pArchivo,"Id Libro,Titulo,Autor,Precio\n");
			if(pArchivo != NULL)
			{
				for(int i = 0; i<len; i++)
				{
					pLibro = (eLibro*)ll_get(listaMinotauro,i);
					if(!Libro_getId(pLibro, &idAux) && !Libro_getTitulo(pLibro, tituloAux)
						&& !Libro_getAutor(pLibro, autorAux) && !Libro_getPrecio(pLibro, &precioAux))
					{
						fprintf(pArchivo, "%d, %s, %s, %d\n", idAux, tituloAux, autorAux, precioAux);
						retorno = 1;
					}
				}
				fclose(pArchivo);
			}

		}
	}

	return retorno;
}

int controller_saveAsTextDesc(char* path , LinkedList* listaLibros)
{
	FILE* pArchivo;
	eLibro* pLibro;
	LinkedList* listaDescuentos;
	int retorno;
	int len;
	int idAux;
	char tituloAux[50];
	char autorAux[50];
	int precioAux;
	int idEditorial;
	retorno = 0;

	if(path != NULL && listaLibros != NULL &&  !ll_isEmpty(listaLibros))
	{
		listaDescuentos = ll_map(listaLibros, AplicarDescuentoLibro);

		len = ll_len(listaDescuentos);
		if(listaDescuentos != NULL)
		{
			pArchivo = fopen(path,"w");
			fprintf(pArchivo,"Id Libro,Titulo,Autor,Precio,Id Editorial\n");
			if(pArchivo != NULL)
			{
				for(int i = 0; i<len; i++)
				{
					pLibro = (eLibro*)ll_get(listaDescuentos,i);
					if(!Libro_getId(pLibro, &idAux) && !Libro_getTitulo(pLibro, tituloAux)
						&& !Libro_getAutor(pLibro, autorAux) && !Libro_getPrecio(pLibro, &precioAux)&&!Libro_getIdEditorial(pLibro, &idEditorial))
					{
						fprintf(pArchivo, "%d, %s, %s, %d,%d\n", idAux, tituloAux, autorAux, precioAux,idEditorial);
						retorno = 1;
					}
				}
				fclose(pArchivo);
			}

		}
	}

	return retorno;
}



