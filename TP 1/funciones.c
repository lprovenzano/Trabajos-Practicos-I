#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

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
        system("CLS");
        suma(b, c);
        resta(b, c);
        multiplica(b, c);
        divide(b, c);
        factorial(b);
        break;
    default:
        return 0;
    }
}

float primerNumero()
{
    float num1;
    printf("\n \n Ingrese el 1er Operando: ");
    scanf("%f", &num1);
    return num1;
}

float segundoNumero()
{
    float num2;
    printf("\n \n Ingrese el 2do Operando: ");
    scanf("%f", &num2);
    return num2;
}

float suma(float a, float b)
{
    float total;
    total = a+b;
    printf("\n ------------------------ \n %.4f + %.4f = %.4f \n \n", a, b, total);
    return total;
}

float resta(float a, float b)
{
    float total;
    total = a-b;
    printf("\n ------------------------ \n %.4f - %.4f = %.4f \n \n", a, b, total);
    return total;
}

float multiplica(float a, float b)
{
    float total;
    total = a*b;
    printf("\n ------------------------ \n %.4f * %.4f = %.4f \n \n", a, b, total);
    return total;
}

float divide(float a, float b)
{
    float total;
    if(b==0)
    {
        printf("\n ------------------------ \n ERROR! Operacion invalida \n \n");
        return 0;
    }
    total = a/b;
    printf("\n ------------------------ \n %.4f / %.4f = %.4f \n \n", a, b, total);
    return total;
}

//DEBE SER INT, REHACER
float factorial(float a)
{
    float acumulador;
    float antecesores;
    acumulador = 0;
    for(antecesores=a;antecesores>0;antecesores--)
    {
        acumulador += antecesores;
    }
    printf("\n ------------------------ \n Factorial de %.4f: %.4f \n \n", a,acumulador);
    return acumulador;
}
