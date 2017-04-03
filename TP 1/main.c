#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float primerNumero, segundoNumero;
    int operador;
    char respuesta;

    do
    {
    system("CLS");
    printf("\n \n BIENVENIDO \n ------------------------ \n");

    printf("\n Ingrese un numero (A): ");
    scanf("%f", &primerNumero);

    printf("\n Ingrese otro numero (B): ");
    scanf("%f", &segundoNumero);

    system("CLS");

    do
    {
        menu();
        printf("\n \n RESPUESTA: ");
        scanf("%d", &operador);
        system("CLS");
        menu();
        if(operador<=0 || operador>6)
        {
            system("CLS");
        }

    }while(operador<=0 || operador>6);

    calculo(operador, primerNumero, segundoNumero);

    printf("\n \n Desea operar de nuevo? (s|n): ");
    respuesta = getch();

    }while(respuesta == 's');

    return 0;

}
