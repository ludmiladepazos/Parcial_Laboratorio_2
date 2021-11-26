/*
 ============================================================================
 Name        : SegundoParcialLabo.c
 Author      : Ludmila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"

int main(void)
{
	setbuf(stdout,NULL);
    char salir;
    salir = 'n';
    //creo la lista, aun no esta creada en memoria, por eso llamo a new:
    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditorial = ll_newLinkedList();
    int flagLibros;
    int flagEditorial;
    flagLibros = 0;
    flagEditorial = 0;

    do{
		switch(MenuPrincipal())
		{
			case 1://Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.
				if(controller_LoadFromText(listaLibros,parser_LibrofromText))
				{
					flagLibros = 1;
				}
				break;
			case 2://Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.
				if(controller_LoadFromText(listaEditorial,parser_EditorialfromText))
				{
					flagEditorial = 1;
				}
				break;
			case 3://Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente
				if(controller_OrdenarLibrosPorAutor(listaLibros) && flagLibros == 1)
				{
					printf("Lista ordenada con exito\n");
				}
				else
				{
					printf("No se puede ordenar la lista si antes no paso por opcion 1");
				}
				break;
			case 4://Imprimir por pantalla todos los datos de los libros. ACLARACIÓN: Se deberá imprimir la descripción de la editorial
				if(controller_ListLibro(listaLibros,listaEditorial) && flagLibros == 1 && flagEditorial == 1)
				{
					printf("Listado Ok");
				}
				else
				{
					printf("No se puede acceder a esta opcion si previamente no paso por las opciones 1 y 2");
				}
				break;
			case 5://Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
				if(controller_saveAsTextMinotauro("listaMinotauro.csv", listaLibros))
				{
					printf("Lista creada\n");

				}
				else
				{
					printf("No se creo la lista\n");
				}
				break;
			case 6:
				if(controller_saveAsTextDesc("mapeado.csv", listaLibros))
				{
					printf("Si el precio es mayor o igual a 300 y la editorial es Planeta tiene un 20%% de descuento\n"
							"Si el precio es menor igual a 200  y la editorial es Siglo XXI Editores tiene un 10%% de descuento\n"
							"Archivo creado con exito\n");

				}
				else
				{
					printf("No se pudo aplicar el descuento\n");
				}
				break;
			case 7:
				printf("Confirma salida s/n: \n");
				fflush(stdin);
				scanf("%c",&salir);
				if(salir == 's')
				{
					ll_deleteLinkedList(listaLibros);
					ll_deleteLinkedList(listaEditorial);
				}
				break;
		   default:
				printf("Error,opcion invalida \n");
		}
	  }while(salir != 's');

    return EXIT_SUCCESS;
}


