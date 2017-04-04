/*******************************************************************
*
*   Programa:
*   ~ Calculadora | Trabajo Práctico N° 1.
*
*   Objetivo:
*   Ingresar dos números (A^B) y realizar operaciones de
*   suma, resta, multiplicacion, división y factorial.
*
*
*   Version:
*   0.1 del 04 de abril de 2017.
*
*   Autor:
*   Luca Provenzano | 1F.
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    float num1, num2;
    int operador;

    num1 = 0;
    num2 = 0;

    menu(num1, num2);

    do
    {
        switch (operador)
        {
            case 1:
                num1 = primerNumero();
                system("CLS");
                menu(num1, num2);
            break;
            case 2:
                num2 = segundoNumero();
                system("CLS");
                menu(num1, num2);
            break;
        }

        calculo(operador, num1, num2);

        printf("\n \n OPCION: ");
        scanf("%d", &operador);
        system("CLS");
        menu(num1, num2);

    }while(operador!=9);

    return 0;
}
