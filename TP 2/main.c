#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 20


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona unaPersona[MAX];
    init(unaPersona, MAX);
    while(seguir=='s')
    {

        menu();

        do
        {
           scanf("%d",&opcion);
        }while(opcion<0 || opcion>5);


        switch(opcion)
        {
            case 1:
                agregarPersona(unaPersona, MAX);
                break;
            case 2:
                borrarPersona(unaPersona, MAX);
                break;
            case 3:
                listarPersona(unaPersona, MAX);
                break;
            case 4:
                graficarEdades(unaPersona, MAX);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
