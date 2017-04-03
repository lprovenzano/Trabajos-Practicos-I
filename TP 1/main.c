#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    float num1, num2;
    int operador;
    char respuesta;

    do
    {
    system("CLS");

    do
    {
        system("CLS");
        printf("\n \n MENU \n ------------------------ \n");
        printf("\n 1 - INGRESAR EL 1ER OPERANDO (A=%f)\n 2 - INGRESAR EL 2DO OPERANDO (B=%f) \n 3 - SUMA (A+B) \n 4 - RESTA (A-B) \n 5 - MULTIPLICACION (A*B) \n 6 - DIVISION (A/B) \n 7 - FACTORIAL (A!) \n 8 - TODAS LAS OPERACIONES \n\n 9 - SALIR", num1, num2);
        printf("\n \n OPCION: ");
        scanf("%d", &operador);
        system("CLS");
        printf("\n \n MENU \n ------------------------ \n");
        printf("\n 1 - INGRESAR EL 1ER OPERANDO (A=%f)\n 2 - INGRESAR EL 2DO OPERANDO (B=%f) \n 3 - SUMA (A+B) \n 4 - RESTA (A-B) \n 5 - MULTIPLICACION (A*B) \n 6 - DIVISION (A/B) \n 7 - FACTORIAL (A!) \n 8 - TODAS LAS OPERACIONES \n\n 9 - SALIR", num1, num2);
        if(operador<=0 || operador>8)
        {
            system("CLS");
        }

        switch (operador)
        {
            case 1:
                num1 = primerNumero();
            break;
            case 2:
                num2 = segundoNumero();
            break;
        }
    }while(operador<=0 || operador==1 || operador==2 || operador>8);

    calculo(operador, num1, num2);

    printf("\n Desea operar de nuevo? (s|n): ");
    respuesta = tolower(getch());

    }while(respuesta == 's');

    return 0;
}
