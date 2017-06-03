#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

void menu()
{
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");
}

int agregarPelicula(EMovie *movie)
{
    movie = (EMovie*)malloc(sizeof(EMovie));
    FILE *archivo;

    if ((archivo=fopen("bin.dat", "rb+"))==NULL)
    {
        if ((archivo=fopen("bin.dat", "wb+"))==NULL)
        {
            pause("No se pudo abrir el archivo (ENTER)");
            return 0;
        }
    }
    if(movie == NULL)
    {
        printf("No se puede cargar peliculas.");
        pause("<< ENTER para continuar >>");
        return 0;
    }
    while(1)
    {
        fflush(stdin);
        movie->id = getValidInt("ID Pelicula: ", "Solo numerico", 1, 100);
        printf("Titulo: ");
        fflush(stdin);
        fgets(movie->titulo, 20, stdin);
        //Genero
        printf("\nGenero: ");
        fflush(stdin);
        fgets(movie->genero, 20, stdin);
        //Duracion
        movie->duracion = getValidInt("\nDuracion: ", "Solo numeros",1,500);
        //Descripcion
        printf("\nDescripcion: ");
        fflush(stdin);
        fgets(movie->descripcion, 250, stdin);
        //Puntaje
        movie->puntaje = getValidInt("\nPuntaje: ", "Solo numeros",1,10);
        //Descripcion
        printf("\nLink de la imagen: ");
        fflush(stdin);
        fgets(movie->linkImagen, 500, stdin);
        movie->estado=1;

        break;
    }

    fflush(stdin);
    fseek(archivo, 0L, SEEK_END);
    fwrite(movie, sizeof(EMovie), 1, archivo);

    fclose(archivo);
    free(movie);
    pause("\nSe cargo con exito. (ENTER)");
    return 1;
}

int borrarPelicula(EMovie *movie)
{
    FILE *archivo;
    EMovie movieEstatico;
    movie = (EMovie*)malloc(sizeof(EMovie));
    int id;

    int contador = 0;

    archivo = fopen("bin.dat","rb+");
    if(archivo == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    id = getValidInt("ID Pelicula: ", "Solo numerico.", 1,100);

    while(!feof(archivo))
    {
        while(fread(movie,sizeof(EMovie),1,archivo)!=0)
        {
            movieEstatico = *movie;
            if(id == movie->id && movie->estado == 1)
            {
                movieEstatico.estado = 0;
                rewind(archivo);
                fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                pause("\nSe ha dado de baja correctamente (ENTER para continuar)");
                break;
            }

            contador++;
        }
        break;
    }
    fclose(archivo);
    free(movie);
    pause("<< ENTER para continuar >>");
    return 1;
}

int modificarPelicula(EMovie *movie)
{
    FILE *archivo;
    EMovie movieEstatico;
    movie = (EMovie*)malloc(sizeof(EMovie));
    int id, rta;

    int contador = 0;

    archivo = fopen("bin.dat","rb+");
    if(archivo == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    id = getValidInt("ID Pelicula: ", "Solo numerico.", 1,100);

    while(!feof(archivo))
    {
        while(fread(movie,sizeof(EMovie),1,archivo)!=0)
        {
            movieEstatico = *movie;
            if(id == movie->id && movie->estado == 1)
            {
                printf("Que desea modificar?\n\n");
                printf("1- Titulo \n");
                printf("2- Genero \n");
                printf("3- Duracion \n");
                printf("4- Descripcion \n");
                printf("5- Puntaje \n");
                printf("6- Imagen \n\n");
                printf("0- Salir \n\n");
                rta = getValidInt(" ", "Solo numeros", 0, 6);
                do
                {
                    switch(rta)
                    {
                    case 1:
                        printf("\nTitulo: ");
                        fflush(stdin);
                        fgets(movieEstatico.titulo, 20, stdin);
                        rewind(archivo);
                        fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                        fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                        printf("\nTitulo: %s\nId: %d\nDescripcion: %s\nEstado: %d",movieEstatico.titulo,movieEstatico.id,movieEstatico.descripcion, movieEstatico.estado);
                        getChar("\nSe ha modificado el titulo correctamente");
                        rta=0;
                        break;
                    case 2:
                        printf("\nGenero: ");
                        fflush(stdin);
                        fgets(movieEstatico.genero, 20, stdin);
                        rewind(archivo);
                        fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                        fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                        getChar("\nSe ha modificado el genero correctamente");
                        rta=0;
                        break;
                    case 3:
                        fflush(stdin);
                        movieEstatico.duracion = getValidInt("\nDuracion: ", "Solo numeros", 1,500);
                        rewind(archivo);
                        fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                        fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                        getChar("\nSe ha modificado la duracion correctamente");
                        rta=0;
                        break;
                    case 4:
                        printf("\nDescripcion: ");
                        fflush(stdin);
                        fgets(movieEstatico.descripcion, 250, stdin);
                        rewind(archivo);
                        fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                        fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                        getChar("\nSe ha modificado la descripcion correctamente");
                        rta=0;
                        break;
                    case 5:
                        fflush(stdin);
                        movieEstatico.puntaje = getValidInt("\nPuntaje: ", "Solo numeros", 1,500);
                        rewind(archivo);
                        fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                        fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                        getChar("\nSe ha modificado el puntaje correctamente");
                        rta=0;
                        break;
                    case 6:
                        printf("\nImagen: ");
                        fflush(stdin);
                        fgets(movieEstatico.linkImagen, 500, stdin);
                        rewind(archivo);
                        fseek(archivo,sizeof(EMovie)*contador,SEEK_SET);
                        fwrite(&movieEstatico,sizeof(EMovie),1,archivo);
                        getChar("\nSe ha modificado la imagen correctamente");
                        rta=0;
                        break;
                    }
                }while(rta!=0);
            }

            contador++;
        }
        break;
    }
    fclose(archivo);
    free(movie);
    pause("<< ENTER para continuar >>");
    return 1;
}

void generarHTML(EMovie *movie)
{
    FILE *archivo;
    FILE *HTML;
    EMovie movieEstatica;
    movie = (EMovie*)malloc(sizeof(EMovie));

    archivo = fopen("bin.dat","rb+");
    if(archivo == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    HTML = fopen("index.html","w+");
    if(HTML == NULL)
    {
        printf("\nError al abrir el archivo");
    }

    while(!feof(archivo))
    {
        while(fread(movie,sizeof(EMovie),1,archivo)!=0)
        {
            movieEstatica = *movie;

            if(movie->estado == 1)
            {
                    fprintf(HTML,"<!DOCTYPE html>\n");
                    fprintf(HTML,"<!-- Template by Quackit.com -->\n");
                    fprintf(HTML,"<html lang='en'>\n");
                    fprintf(HTML,"<head>");
                    fprintf(HTML,"    <meta charset='utf-8'>\n");
                    fprintf(HTML,"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
                    fprintf(HTML,"    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
                    fprintf(HTML,"    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
                    fprintf(HTML,"    <title>Lista peliculas</title>\n");
                    fprintf(HTML,"    <!-- Bootstrap Core CSS -->\n");
                    fprintf(HTML,"    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
                    fprintf(HTML,"    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
                    fprintf(HTML,"    <link href='css/custom.css' rel='stylesheet'>\n");
                    fprintf(HTML,"    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
                    fprintf(HTML,"    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
                    fprintf(HTML,"    <!--[if lt IE 9]>\n");
                    fprintf(HTML,"        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
                    fprintf(HTML,"        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
                    fprintf(HTML,"    <![endif]-->\n");
                    fprintf(HTML,"</head>\n");
                    fprintf(HTML,"<body>\n");
                    fprintf(HTML,"    <div class='container'>\n");
                    fprintf(HTML,"        <div class='row'>\n\n\n");

                    fprintf(HTML,"            <article class='col-md-4 article-intro'>\n");
                    fprintf(HTML,"                <a href='#'>\n");
                    fprintf(HTML,"                    <img class='img-responsive img-rounded' src='");
                    fprintf(HTML,"%s",movieEstatica.linkImagen);
                    fprintf(HTML,"' alt=''>\n");
                    fprintf(HTML,"                </a>\n");
                    fprintf(HTML,"                <h3>\n");
                    fprintf(HTML,"                    <a href='#'>");
                    fprintf(HTML,"%s",movieEstatica.titulo);
                    fprintf(HTML,"</a>\n");
                    fprintf(HTML,"                </h3>\n");
                    fprintf(HTML,"				<ul>\n");
                    fprintf(HTML,"					<li>");
                    fprintf(HTML,"Genero: %s",movieEstatica.genero);
                    fprintf(HTML,"</li>\n");
                    fprintf(HTML,"					<li>");
                    fprintf(HTML,"Puntaje: %d",movieEstatica.puntaje);
                    fprintf(HTML,"</li>\n");
                    fprintf(HTML,"					<li>");
                    fprintf(HTML,"Duracion: %d",movieEstatica.duracion);
                    fprintf(HTML,"</li>\n");
                    fprintf(HTML,"				</ul>\n");
                    fprintf(HTML,"                <p>");
                    fprintf(HTML,"%s",movieEstatica.descripcion);
                    fprintf(HTML,"</p>\n");
                    fprintf(HTML,"            </article>\n\n\n");

                    fprintf(HTML,"        </div>");
                    fprintf(HTML,"        <!-- /.row -->");
                    fprintf(HTML,"    </div>");
                    fprintf(HTML,"    <!-- /.container -->");
                    fprintf(HTML,"    <!-- jQuery -->");
                    fprintf(HTML,"    <script src='js/jquery-1.11.3.min.js'></script>");
                    fprintf(HTML,"    <!-- Bootstrap Core JavaScript -->");
                    fprintf(HTML,"    <script src='js/bootstrap.min.js'></script>");
                    fprintf(HTML,"	<!-- IE10 viewport bug workaround -->");
                    fprintf(HTML,"	<script src='js/ie10-viewport-bug-workaround.js'></script>");
                    fprintf(HTML,"	<!-- Placeholder Images -->");
                    fprintf(HTML,"	<script src='js/holder.min.js'></script>");
                    fprintf(HTML,"</body>");
                    fprintf(HTML,"</html>");

            }

        }
        break;
    }
    getChar("Se creo con exito");

    fclose(archivo);
    fclose(HTML);
    free(movie);
}



