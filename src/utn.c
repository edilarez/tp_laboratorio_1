/*
 * utn.c
 *
 *  Created on: 15 abr. 2022
 *      Author: edilynlarez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

int menu ()
{
	int opcion;

			printf ("\n\nMenu de opciones\n\n");
			printf ("1. Ingresar Kilometros\n");
			printf ("2. Ingresar precios de vuelos\n");
			printf ("3. Calcular los costos\n");
			printf ("4. Informar resultados\n");
			printf ("5. Carga forzada de datos\n");
			printf ("6. Salir\n\n");
			printf ("Ingrese opcion: ");
			scanf ("%d", &opcion);

			return opcion;
}

float kmsIngresados ()
{
	float kiloms;
	int k;
	printf ("Ingrese kilometros ");
	k = scanf ("%f",&kiloms);

	while (kiloms <= 0 || k == 0)
	{
		fflush (stdin);
		printf ("Error, Ingrese kilometros ");
		scanf ("%f", &kiloms);
		k = kiloms;
	}

	return kiloms;
}


int subMenu ()
{
	int opcion;

			printf ("1. Precio vuelo Aerolineas\n");
			printf ("2. Precio vuelo Latam\n");
			printf ("Ingrese opcion: ");
			scanf ("%d", &opcion);

			return opcion;
}

float preciosVuelos(int opcion)
{
	fflush (stdin);
	float precio;
	int p;

	if (opcion == 1)
	{
		printf ("Ingrese Precio vuelo Aerolinea ");
		scanf ("%f", &precio);
		while (precio < 1 || p == 0)
		{
			fflush (stdin);
			printf ("Error, Ingrese Precio vuelo ");
			scanf ("%f", &precio);
			p = precio;
		}
	}
	else
	{
		printf ("Ingrese Precio vuelo Latam ");
		scanf ("%f", &precio);
		while (precio < 1 || p == 0)
		{
			fflush (stdin);
			printf ("Error, Ingrese Precio vuelo ");
			scanf ("%f", &precio);
			p = precio;
		}
	}

	return precio;
}

float pagoConDebito (float valor)
{
	float porcentajeDescuento;
	float precioConDescuento;

	porcentajeDescuento = (valor*10)/100;
	precioConDescuento = valor - porcentajeDescuento;

	return precioConDescuento;
}

float pagoConCredito (float valor)
{
	float porcentajeInteres;
	float precioConInteres;

	porcentajeInteres = (valor*25)/100;
	precioConInteres = valor + porcentajeInteres;

	return precioConInteres;
}

float pagoConBitcoin (float valor)
{
	float precioEnBitcoin;

	precioEnBitcoin = valor / 4606954.55;

	return precioEnBitcoin;
}

float precioUnitario (float valor1, float valor2)
{
	float precioPorKms;

	precioPorKms = valor1 / valor2;

	return precioPorKms;
}

void mostrarResultados (float kms, float precioAero, float precioLatam, float precioTdAero, float precioTcAero, float precioBitcoinAero, float precioUnitarioAero, float precioTdLm, float precioTcLm, float precioBitcoinLm, float precioUnitarioLm, float diferenciaPrecio)
{
		printf ("\nKMs Ingresados: %.2f km\n\n", kms);
		printf ("Precios Aerolineas: $%.2f\n", precioAero);
		printf ("a) Precio con tarjeta de debito: $ %.2f\n", precioTdAero);
		printf ("b) Precio con tarjeta de credito: $ %.2f\n", precioTcAero);
		printf ("c) Precio pagando con bitcoin: %.2f BTC\n", precioBitcoinAero);
		printf ("d) Mostrar precio unitario: $ %.2f\n\n", precioUnitarioAero);
		printf ("Precios Latam: $%.2f\n", precioLatam);
		printf ("a) Precio con tarjeta de debito: $ %.2f\n", precioTdLm);
		printf ("b) Precio con tarjeta de credito: $ %.2f\n", precioTcLm);
		printf ("c) Precio pagando con bitcoin: %.2f BTC\n", precioBitcoinLm);
		printf ("d) Mostrar precio unitario: $ %.2f\n\n", precioUnitarioLm);
		printf ("La diferencia de precio es: $ %.2f", diferenciaPrecio);
}

