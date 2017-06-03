#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
int main()

{
//    pause("<< ENTER para continuar >>");
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {

        menu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("@cls||clear");
                agregarPelicula(movie);
                break;
            case 2:
                system("@cls||clear");
                borrarPelicula(movie);
                break;
            case 3:
                system("@cls||clear");
                modificarPelicula(movie);
               break;
            case 4:
                generarHTML(movie);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
