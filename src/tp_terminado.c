#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"


#define NADA 0
#define KILOMETROS 1
#define VUELOS 2
#define COSTOS 3
#define RESULTADO 4

int main(void)
{
	setbuf (stdout, NULL);

	float kms = 0;
	float precioAero = 0;
	float precioLatam = 0;
	float precioTdAero;
	float precioTcAero;
	float precioBitcoinAero;
	float precioUnitarioAero;
	float precioTdLm;
	float precioTcLm;
	float precioBitcoinLm;
	float precioUnitarioLm;
	float diferenciaPrecio;
	int flag = NADA;
	int flagVuelos = 0;
	int vuelo;


	char seguir ='s';

	do
	{
		switch (menu())
		{
		case 1:
			//Ingresar Kilometros
			kms = kmsIngresados ();
			flag = KILOMETROS;
			break;

		case 2:
			//Ingresar precios de Vuelos
			if (flag == KILOMETROS)
			{
				vuelo = subMenu ();
				if (vuelo == 1)
				{
					precioAero = preciosVuelos (vuelo);
					flagVuelos = 1;
				}
				else
				{
					precioLatam = preciosVuelos (vuelo);
					flagVuelos = 2;
				}

				if (flagVuelos == 1)
				{
					precioLatam = preciosVuelos (2);
				}
				else
				{
					precioAero = preciosVuelos (1);
				}
				flag = VUELOS;
			}
			else
			{
				printf ("Para ingresar precios primero debemos ingresar kilometros\n");
			}
			break;

		case 3:
			//Calcular costos
			if (flag == VUELOS)
			{
				precioTdAero = pagoConDebito (precioAero);
				precioTcAero = pagoConCredito (precioAero);
				precioBitcoinAero = pagoConBitcoin (precioAero);
				precioUnitarioAero =  precioUnitario (precioAero, kms);
				precioTdLm = pagoConDebito (precioLatam);
				precioTcLm = pagoConCredito (precioLatam);
				precioBitcoinLm = pagoConBitcoin (precioLatam);
				precioUnitarioLm = precioUnitario (precioLatam, kms);
				diferenciaPrecio = precioAero - precioLatam;
				flag = COSTOS;

			}
			else if (flag == KILOMETROS)
			{
				printf ("Para hacer calculos primero deberiamos ingresar precios del vuelo\n");
			}
			else
			{
				printf ("Para hacer calculos primero deberiamos ingresar kilometros\n");
			}
			break;
		case 4:
			if (flag == COSTOS)
			{
				mostrarResultados (kms,precioAero,precioLatam,precioTdAero,precioTcAero,precioBitcoinAero,precioUnitarioAero,precioTdLm,precioTcLm,precioBitcoinLm,precioUnitarioLm,diferenciaPrecio);
				flag = RESULTADO;
			}
			else if (flag == KILOMETROS)
			{
				printf ("Para mostrar resultados primero deberiamos ingresar precios del vuelo\n");
			}
			else if (flag == VUELOS)
			{
				printf ("Para mostrar resultados primero deberiamos realizar los calculos\n");
			}
			else {
				printf ("Para mostrar resultados primero deberiamos ingresar kilometros\n");
			}
			break;

		case 5:
			kms = 7090;
			precioAero = 162965;
			precioLatam = 159339;
			precioTdAero = pagoConDebito (precioAero);
			precioTcAero = pagoConCredito (precioAero);
			precioBitcoinAero = pagoConBitcoin (precioAero);
			precioUnitarioAero =  precioUnitario (precioAero, kms);
			precioTdLm = pagoConDebito (precioLatam);
			precioTcLm = pagoConCredito (precioLatam);
			precioBitcoinLm = pagoConBitcoin (precioLatam);
			precioUnitarioLm = precioUnitario (precioLatam, kms);
			diferenciaPrecio = precioAero - precioLatam;
			mostrarResultados (kms,precioAero,precioLatam,precioTdAero,precioTcAero,precioBitcoinAero,precioUnitarioAero,precioTdLm,precioTcLm,precioBitcoinLm,precioUnitarioLm,diferenciaPrecio);
			break;

		case 6:
			seguir = 'n';
			break;

		default:
			printf ("Opción Invalida\n");

		}

	} while (seguir == 's');

	return EXIT_SUCCESS;
}
