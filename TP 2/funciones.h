#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    char edad[3];
    int estado;
    int edadI;
    int dni;
    char dniC[9];

}EPersona;


/**
 * Muestra el menu por pantalla.
 * @param Ninguno.
 * @return void.
 */
void menu();

/**
 * Obtiene caracteres de un array de char.
 * @param array para leer
 * @return cantidad de caracteres en el array de chars
 */
int validoCantidad(char variable[]);

/**
 * Valida si un char contiene letras.
 * @param array para leer
 * @return 0 y 1.
 */
int validoLetra(char variable[]);

/**
 * Valida si un char tiene numeros.
 * @param array para leer.
 * @return 0 y 1.
 */
int esNumero(char dato[]);

/**
 * Convierte cadena a entero.
 * @param array de chars para convertir a int.
 * @return datos del array de chars como int.
 */
int charAInt(char variable[]);

/**
 * La variable estado dentro de la estructura vale 0.
 * @param Estructura y tamaño del array de la misma.
 * @return void.
 */
void init(EPersona unaPersona[], int tam);

/**
 * Carga un array de estructuras.
 * @param Estructura y tamaño del array de la misma.
 * @return void.
 */
void agregarPersona(EPersona unaPersona[], int tam);

/**
 * Elimina un dato dentro del array de estructuras.
 * @param Estructura y tamaño del array de la misma.
 * @return void.
 */
void borrarPersona(EPersona unaPersona[], int tam);

/**
 * Muestra el array de estructuras en pantalla.
 * @param Estructura y tamaño del array de la misma.
 * @return void.
 */
void listarPersona(EPersona unaPersona[], int tam);

/**
 * Realiza grafica de edad segun los datos cargados al array.
 * @param Estructura y tamaño del array de la misma.
 * @return void.
 */
void graficarEdades(EPersona unaPersona[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona unaPersona[], int dni, int tam);

#endif // FUNCIONES_H_INCLUDED
