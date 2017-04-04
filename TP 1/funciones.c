#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 * @brief Vista del menu.
 * @param A - Primer operando
 * @param B - Segundo operando
 * @return Retorna valores (A^B) en el mismo.
 */
float menu(float a, float b)
{
    printf("\n \n MENU \n ------------------------ \n");
    printf("\n 1 - INGRESAR EL 1ER OPERANDO (A=%f)\n 2 - INGRESAR EL 2DO OPERANDO (B=%f) \n 3 - SUMA (A+B) \n 4 - RESTA (A-B) \n 5 - MULTIPLICACION (A*B) \n 6 - DIVISION (A/B) \n 7 - FACTORIAL (A!) \n 8 - TODAS LAS OPERACIONES \n\n 9 - SALIR", a, b);
}

/**
 * @brief Solicita el primer operando y lo retorna (A)
 * @return Retorna un float ingresado.
 */
float primerNumero()
{
    float num1;
    printf("\n \n Ingrese el 1er Operando: ");
    scanf("%f", &num1);
    return num1;
}

/**
 * @brief Solicita el segundo operando y lo retorna (B)
 * @return Retorna un float ingresado.
 */
float segundoNumero()
{
    float num2;
    printf("\n \n Ingrese el 2do Operando: ");
    scanf("%f", &num2);
    return num2;
}

/**
 * @brief Calcula la suma entre el primer y el segundo operando (A^B)
 * @param A - Primer operando.
 * @param B - Segundo operando.
 * @return Retorna el total de la operación suma.
 */
float suma(float a, float b)
{
    float total;
    total = a+b;
    printf("\n \n ------------------------ \n %.4f + %.4f = %.4f \n ", a, b, total);
    return total;
}

/**
 * @brief Calcula la resta entre el primer y el segundo operando (A^B)
 * @param A - Primer operando.
 * @param B - Segundo operando.
 * @return Retorna el total de la operación resta.
 */
float resta(float a, float b)
{
    float total;
    total = a-b;
    printf("\n \n ------------------------ \n %.4f - %.4f = %.4f \n ", a, b, total);
    return total;
}

/**
 * @brief Calcula el producto entre el primer y el segundo operando (A^B)
 * @param A - Primer operando.
 * @param B - Segundo operando.
 * @return Retorna el total del producto.
 */
float multiplica(float a, float b)
{
    float total;
    total = a*b;
    printf("\n \n ------------------------ \n %.4f * %.4f = %.4f \n ", a, b, total);
    return total;
}

/**
 * @brief Calcula la división entre el primer y el segundo operando (A^B)
 * @param A - Primer operando.
 * @param B - Segundo operando.
 * @return Retorna el total de la división.
 */
float divide(float a, float b)
{
    float total;
    if(b==0)
    {
        printf("\n \n ------------------------ \n ERROR! \n Operacion invalida \n ");
        return 0;
    }
    total = a/b;
    printf("\n \n ------------------------ \n %.4f / %.4f = %.4f \n ", a, b, total);
    return total;
}

/**
 * @brief Calcula el factorial del primer operando.
 * @param A - Primer operando.
 * @return Retorna la multiplicacion de los numeros que anteceden al primer operando (A)
 */
float factorial(float a)
{
    float acumulador;
    float antecesores;
    acumulador = 1;
    if (a>=0)
    {
        for(antecesores=a;antecesores>0;antecesores--)
        {
            acumulador *= antecesores;
        }
        printf("\n \n ------------------------ \n Factorial de %.0f: %.0f \n ", a,acumulador);
        return acumulador;
    }
    else
    {
        printf("\n \n ------------------------ \n ERROR! Operacion invalida \n");
        return 0;
    }
}

/**
 * @brief Realiza las operaciones de suma, resta, multiplicacion, division, factorial, todas las anteriores y la salida del programa.
 * @param A - Opcion elegida por el usuario (Operacion)
 * @param B - Primer operando.
 * @param C - Segundo operando.
 * @return Retorna el total de cada operación según el caso elegido.
 */
float calculo(int a, float b, float c)
{
    switch(a)
    {
    case 3:
        suma(b, c);
        break;
    case 4:
        resta(b, c);
        break;
    case 5:
        multiplica(b, c);
        break;
    case 6:
        divide(b, c);
        break;
    case 7:
        factorial(b);
        break;
    case 8:
        suma(b, c);
        resta(b, c);
        multiplica(b, c);
        divide(b, c);
        factorial(b);
        break;
    case 9:
        exit(0);
    }
}

