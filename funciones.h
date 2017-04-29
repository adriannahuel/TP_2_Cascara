#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/** \brief permite cargar los datos y los asigna a la estructura
 *
 * \param recibe una estructura a ser cargada
 * \param recibe el tamaño para implementar los for
 * \return vacio
 *
 */
void cargarPersona(EPersona [], int );


/** \brief muestra los datos de la estructura segun los datos pedidos
 *
 * \param recibe una estructura a ser mostrada
 * \param recibe el tamaño para implementar los for
 * \return vacio
 */

void mostrarPersona(EPersona [], int );


/** \brief hace burbujeo para ordenar la estructura por nombre y luego por dni
 *
 * \param recibe una estructura a ser ordenada
 * \param recibe el tamaño para implementar los for
 * \return vacio
 *
 */

void ordenarPersona(EPersona [], int );


/** \brief busca un dni dentro de la estructura, la muestra y, si hace el cambi, hace una baja virtual poniendo el estado en 0
 *
 * \param recibe una estructura en la cual se busca para borrar
 * \param recibe el tamaño para implementar los for
 * \return vacio
 *
 */

void borrarPersona(EPersona [], int);


/** \brief cuenta las edades<18, las 18-35, y las >35. Luego asigna * segun la cantidad de veces que se repiten esas edades,
 *    ordena los astretiscis con un burbujeo para que aparezcan todos los * uno al lado del otro, y lo graba en los array.
 *
 * \param recibe una estructura para tomar el dato de las edades cargadas
 * \param recibe array menores a 18
 * \param recibe array mayores a 18
 * \param recibe array mayores a 35
 * \return vacio
 *
 */

void ordenaredad(EPersona [],char[], char[],char[], int);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
