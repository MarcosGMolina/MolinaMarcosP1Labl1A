/*
 * PrimerParcialFunciones.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
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
int inicializarMascotas(Mascota lasMascotas[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		lasMascotas[i].isEmpty=0;
	}

	return 0;
}

int buscarEspacioLibre(Mascota lasMascotas[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(lasMascotas[i].isEmpty==0)
		{
			break;
		}
	}
	return i;
}
int ocuparEspacioLibre(Mascota lasMascotas[],int tam)
{
	int i;
	i=buscarEspacioLibre(lasMascotas,tam);
	if(i!=-1)
	{
		lasMascotas[i]=datosMascota();
		lasMascotas[i].isEmpty=1;
	}
	return i;
}

Mascota datosMascota()
{
	Mascota miMascota;

	printf("\nIngrese el id: ");
	scanf("%d",&miMascota.id);
	fflush(stdin);


	printf("\nIngrese el nombre:  ");
	gets(miMascota.nombre);
	fflush(stdin);

	printf("\nIngrese el id del Tipo:  ");
	scanf("%d",&miMascota.idTipo);
	while(miMascota.idTipo<1000)
	{
		printf("\nError, reingrese el id del tipo:  ");
		scanf("%d",&miMascota.idTipo);
	}

	printf("\nIngrese el id del Color:  ");
	scanf("%d",&miMascota.idColor);
	while(miMascota.idColor<5000)
	{
		printf("\nError, reingrese el id del color:  ");
		scanf("%d",&miMascota.idColor);
	}

	printf("\nIngrese la edad:  ");
	scanf("%d",&miMascota.edad);
	while(miMascota.edad<0)
		{
			printf("\nError, reingrese la edad de la mascota:  ");
			scanf("%d",&miMascota.edad);
		}

	fflush(stdin);
	printf("\nIngrese el estado de vacunado s/n  ");
	scanf("%c",&miMascota.vacunado);

	return miMascota;
}

int encontrarMascota(Mascota lasMascotas[],int tam,int id)
{
	int i;
	int MascotaEncontrada;
	MascotaEncontrada=0;

	for(i=0;i<tam;i++)
	{
		if(id==lasMascotas[i].id)
		{
			printf("\nSe encontró la mascota.  ");
			MascotaEncontrada=1;
			break;
		}

	}
	if(MascotaEncontrada==1)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
int modificarMascota(Mascota lasMascotas[],int tam, int indice)
{

	printf("\nIngrese nuevamente el id del Tipo:  ");
	scanf("%d",&lasMascotas[indice].idTipo);
	while(lasMascotas[indice].idTipo<1000)
	{
		printf("\nError, reingrese el id del tipo:  ");
		scanf("%d",&lasMascotas[indice].idTipo);
	}


	printf("\nIngrese nuevamente el estado de vacunado s/n:  ");
	scanf("%c",&lasMascotas[indice].vacunado);

	printf("\nLos datos se han modificado.  ");
	return 0;
}
int bajaMascota(Mascota lasMascotas[],int tam,int indice)
{
	int opcionIngresada;

	printf("¿Esta seguro que desea dar de baja a la mascota? Presione 1 para confirmar o 2 para cancelar: ");
	scanf("%d",&opcionIngresada);
	if(opcionIngresada==1)
	{
		lasMascotas[indice].isEmpty=0;
		printf("\nMascota dada de baja.  ");
	}
	else
	{
		printf("\nOperación cancelada. \n");
	}
	return 0;
}
int ordenarMascotas(Mascota lasMascotas[],int tam)
{
	int i;
	int j;
	int retorno=-1;
	Mascota auxId;
	Mascota auxNombre;
	for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(lasMascotas[i].id>lasMascotas[j].id)
				{
					auxId=lasMascotas[i];
					lasMascotas[i]=lasMascotas[j];
					lasMascotas[j]=auxId;
				}
				if(strcmp(lasMascotas[i].nombre, lasMascotas[j].nombre)>0)
				{
					auxNombre=lasMascotas[i];
					lasMascotas[i]=lasMascotas[j];
					lasMascotas[j]=auxNombre;
				}
			}
		}
	retorno=0;
	return retorno;
}
int mostrarMascotas(Mascota lasMascotas[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(lasMascotas[i].isEmpty!=0)
		{
			printf("%d  %s  %d  %d  %d  %c", lasMascotas[i].id, lasMascotas[i].nombre, lasMascotas[i].idTipo,
											 lasMascotas[i].idColor, lasMascotas[i].edad, lasMascotas[i].vacunado);
		}

	}
	return 0;
}
int mostrarTipos(Tipo losTipos[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("\n%s  ",losTipos[i].descripcion);
	}
	return 0;
}
int mostrarColores(Color losColores[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("\n%s  ",losColores[i].nombreColor);
	}
	return 0;
}
int mostrarServicios(Servicio misServicios[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		printf("\n%s  %d  ",misServicios[i].descripcion, misServicios[i].precio);
	}
	return 0;
}

