/*
 ============================================================================
 Name        : PrimerParcialLabo2021.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "Fecha.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"
#include <string.h>
#define TAMANIO 100
#define TAM 5

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int alta;
	int modificacion;
	int iEncontrado=0;
	int orden;
	Mascota misMascotas[TAMANIO];
	Tipo misTipos[TAM]={{1000,"Ave"},{1001,"Perro"},{1002,"Roedor"},{1003,"Gato"},{1004,"Pez"}};
	Color misColores[TAM]={{5000,"Negro"},{5001,"Blanco"},{5002,"Rojo"},{5003,"Gris"},{5004,"Azul"}};
	Servicio misServicios[TAM]={{20000,"Corte",450},{20001,"Desparasitado",800},{20002,"Castrado",600}};


	inicializarMascotas(misMascotas,TAMANIO);
	do
	{
		utn_getNumero(&opcion,"\nBienvenido al menú  \n1:Alta Mascota  \n2:Modificar Mascota  \n3:Baja Mascota: "
				"   \n4:Listar Mascotas  \n5:Listar Tipos  \n6:Listar Colores  \n7:Listar Servicios  \n8:Alta trabajo  "
				"\n9:Listar Trabajos  :","Error, reingrese la opción nuevamente:  ",1,10,3);
		switch(opcion)
		{
			case 1:
				alta=ocuparEspacioLibre(misMascotas,TAMANIO);
				if(alta!=-1)
				{
					printf("\nAlta realizada con éxito  \n");
				}
				else
				{
					printf("\nNo se pudo realizar el alta");
				}
			break;

			case 2:
				printf("\nIngrese el id de la mascota a encontrar:  ");
				scanf("%d",&modificacion);
				iEncontrado=encontrarMascota(misMascotas,TAMANIO,modificacion);
				if(iEncontrado!=-1)
				{
					modificarMascota(misMascotas,TAMANIO,iEncontrado);
				}
				else
				{
					printf("\nEl id de la mascota no fue encontrada.  ");
				}
			break;

			case 3:
				printf("\nIngrese el id de la mascota a encontrar:  ");
				scanf("%d",&modificacion);
				iEncontrado=encontrarMascota(misMascotas,TAMANIO,modificacion);
				if(iEncontrado!=-1)
				{
					bajaMascota(misMascotas,TAMANIO,iEncontrado);
				}
				else
				{
					printf("\nEl id de la mascota no fue encontrada.  \n");
				}
			break;

			case 4:
				orden=ordenarMascotas(misMascotas,TAMANIO);
				if(orden!=1)
				{

					mostrarMascotas(misMascotas,TAMANIO);
				}
				else
				{
					printf("\nNo se puede mostrar las mascotas.  ");
				}

			break;

			case 5:
				mostrarTipos(misTipos,TAM);
			break;

			case 6:
				mostrarColores(misColores,TAM);
			break;

			case 7:
				mostrarServicios(misServicios,TAM);
			break;

			case 8:
			break;

			case 9:
			break;

			case 10:
				printf("Salir del menú.  ");
			break;
		}
	}while(opcion!=10);




	return EXIT_SUCCESS;
}
