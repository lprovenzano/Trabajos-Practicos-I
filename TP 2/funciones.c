#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

void menu()
{
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
}

int validoCantidad(char variable[])
{
    int cant;
    cant = strlen(variable);
    return cant;
}

int validoLetra(char variable[])
{
    int flag, cant, i;
    flag = 0;
    cant = strlen(variable);
    for(i=0; i<cant; i++)
    {
        if(!isdigit(variable[i]))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int esNumero(char dato[])
{
    int i, flag, cant;
    flag = 0;
    cant = strlen(dato);
    for(i=0; i<cant; i++)
    {
        if(isdigit(dato[i]))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void init(EPersona unaPersona[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        unaPersona[i].estado=0;
    }
}

int charAInt(char variable[])
{
    int i;
    i=atoi(variable);
    return i;
}

int buscarPorDni(EPersona unaPersona[], int dni, int tam)
{
    int i, flag;

    for(i=0; i<tam; i++)
    {
        if(unaPersona[i].dni==dni)
        {
            flag=i;
            break;
        }
        else
        {
            flag=-1;
        }
    }
    return flag;
}


void agregarPersona(EPersona unaPersona[], int tam)
{
    int i, validoIgualdad,flag, cant, validoDNI, validoNom, validoEdad, dniNuevo;
    char dni[9];
    flag =0;
    for(i=0; i<tam; i++)
    {
        if(unaPersona[i].estado==0)
        {
            do
            {
                system("CLS");
                menu();
                printf("\nNombre: ");
                fflush(stdin);
                fgets(unaPersona[i].nombre, 50, stdin);
                validoNom=esNumero(unaPersona[i].nombre);
                cant=validoCantidad(unaPersona[i].nombre);
            }
            while(validoNom!=0 || cant<=3);
            do
            {
                printf("\nDNI (sin puntos): ");
                fflush(stdin);
                fgets(unaPersona[i].dniC, 9, stdin);

                cant=validoCantidad(unaPersona[i].dniC);

                validoDNI = esNumero(unaPersona[i].dniC);

                dniNuevo = atoi(unaPersona[i].dniC);
                validoIgualdad = buscarPorDni(unaPersona, dniNuevo, tam);
                while(validoIgualdad!=-1)
                {
                    printf("DNI repetido.");
                    printf("\nDNI (sin puntos): ");
                    fflush(stdin);
                    fgets(unaPersona[i].dniC, 9, stdin);

                    cant=validoCantidad(unaPersona[i].dniC);

                    validoDNI = esNumero(unaPersona[i].dniC);

                    dniNuevo = atoi(unaPersona[i].dniC);
                    validoIgualdad = buscarPorDni(unaPersona, dniNuevo, tam);
                }
                unaPersona[i].dni=dniNuevo;

            }
            while(cant!=8);
            do
            {
                printf("\nEDAD: ");
                fflush(stdin);
                fgets(unaPersona[i].edad, 3, stdin);

                cant=validoCantidad(unaPersona[i].edad);

                validoEdad = esNumero(unaPersona[i].edad);

                unaPersona[i].edadI = atoi(unaPersona[i].edad);
            }
            while(unaPersona[i].edadI<1 || unaPersona[i].edadI>100 || validoEdad!=1);
            flag = 1;
            unaPersona[i].estado=1;
            system("CLS");
            break;

        }
    }
    if(flag==0)
    {
        printf("\n\nNo hay espacio suficiente");
    }
}

void listarPersona(EPersona unaPersona[], int tam)
{
    system("CLS");
    int i,j;
    EPersona auxiliar;
    printf("EDAD\tDNI\t\tNOMBRE\n");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(unaPersona[i].nombre, unaPersona[j].nombre)>0)
            {
                auxiliar = unaPersona[i];
                unaPersona[i] = unaPersona[j];
                unaPersona[j] = auxiliar;
            }
        }
    }
    for(i=0; i<tam; i++)
    {
        if(unaPersona[i].estado!=0)
        {
            printf("%d\t%d\t%s\n", unaPersona[i].edadI, unaPersona[i].dni, unaPersona[i].nombre);
        }
    }
}

void borrarPersona(EPersona unaPersona[], int tam) //REVISAR
{
    int i, flag, rtaInt, cant, validoDNI;
    char confirma, rta[9];
    flag=0;
    system("CLS");
    listarPersona(unaPersona, tam);
    menu();
    do
    {
        printf("\nDNI de la persona a borrar: ");
        fflush(stdin);
        fgets(rta, 9, stdin);
        cant=validoCantidad(rta);
        validoDNI =validoLetra(rta);
        rtaInt = atoi(rta);
    }
    while(validoDNI==1 || cant!=8);
    for(i=0; i<tam; i++)
    {
        if(rtaInt == unaPersona[i].dni && unaPersona[i].estado!=0)
        {
            do
            {
                printf("Esta seguro que desea borrar a esta persona? (s|n)");
                confirma = tolower(getche());
            }
            while(confirma!='s' && confirma!='n');
            if(confirma=='s')
            {
                unaPersona[i].estado=0;
                system("CLS");
                listarPersona(unaPersona, tam);
                printf("\nSe ha eliminado correctamente.\n\n");
                flag=1;
            }
            else
            {
                system("CLS");
                printf("\nAccion cancelada por el usuario\n\n");
                flag=1;
                break;
            }

        }
    }
    if(flag==0)
    {
        printf("\nNo existe esa persona.\n\n");
    }

}

void graficarEdades(EPersona unaPersona[], int tam)
{
    int i,j, flag, may,de0a18=0, de19a35=0, mayor35=0;

    for(j=0; j<tam; j++)
    {
        if(unaPersona[j].estado==1)
        {
            if(unaPersona[j].edadI<19)
            {
                de0a18++;
            }
            else
            {
                if(unaPersona[j].edadI>=35)
                {
                    mayor35++;
                }
                else
                {
                    de19a35++;
                }
            }
        }
    }
    if(de0a18 >= de19a35 && de0a18 >= mayor35)
    {
        may = de0a18;
    }
    else
    {
        if(de19a35 >= de0a18 && de19a35 >= mayor35)
        {
            may = de19a35;
        }
        else
        {
            may = mayor35;
        }
    }
    system("CLS");
    for(i=may; i>0; i--)
    {
        printf("%02d|",i);

        if(i<= de0a18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayor35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }

            if(flag==1)
            {
                printf("\t*");
            }
        }

        printf("\n");
    }
    printf("__|___________________");
    printf("\n  |<18\t19-35\t>35\n");
    printf("\n   %d\t%d\t%d\n\n", de0a18, de19a35, mayor35);
}
