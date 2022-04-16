/*
 * utn.h
 *
 *  Created on: 15 abr. 2022
 *      Author: edilynlarez
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
/**
 * \brief muestra el menu de opciones y retorna la opcion selecionada
 * \@return int
 */

int menu ();

/**
 * \brief muestra el submenu de opciones y retorna la opcion selecionada
 * @return int
 */
int subMenu ();

/**
 * \brief ingresar kilometros, validarlos y retorna el valor ingresado
 * @return float
 */
float kmsIngresados ();

/**
 * \brief ingresar precios de vuelos, validarlos y retorna el valor ingresado
 * @param opcion
 * @return int
 */
float preciosVuelos(int opcion);

/**
 * \brief calcular descuento sobre los precios ingresados
 * @param valor
 * @return float
 */

float pagoConDebito (float valor);

/**
 * \brief calcular interes sobre los precios ingresados
 * @param valor
 * @return float
 */
float pagoConCredito (float valor);

/**
 * \brief convierte pesos argentinos a bitcoin
 * @param valor
 * @return float
 */
float pagoConBitcoin (float valor);

/**
 * \brief calcula el precio unitario por kilometro
 * @param valor1
 * @param valor2
 * @return float
 */
float precioUnitario (float valor1, float valor2);

/**
 * \ muestra resultados
 * @param kms
 * @param precioAero
 * @param precioLatam
 * @param precioTdAero
 * @param precioTcAero
 * @param precioBitcoinAero
 * @param precioUnitarioAero
 * @param precioTdLm
 * @param precioTcLm
 * @param precioBitcoinLm
 * @param precioUnitarioLm
 * @param diferenciaPrecio
 */

void mostrarResultados (float kms, float precioAero, float precioLatam, float precioTdAero, float precioTcAero, float precioBitcoinAero, float precioUnitarioAero, float precioTdLm, float precioTcLm, float precioBitcoinLm, float precioUnitarioLm, float diferenciaPrecio);
