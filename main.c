#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include<ctype.h>

#define A 20


int main()
{
    char seguir='s', otrap;
    int opcion=0;
    EPersona persona[A];
    int i, libre=-1;
    int j;
    char menos18[A];
    char mas18[A];
    char mas35[A];
    char auxme18, auxma18, auxma35;

    for(i=0; i<A; i++)
    {
        persona[i].estado=0;
        persona[i].edad=0;
        menos18[i]=' ';
        mas18[i]=' ';
        mas35[i]=' ';
    };

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            do
            {
                for(i=0; i<A; i++)
                {
                    if(persona[i].estado==0)
                    {
                        libre=i;
                        break;
                    }
                };
                if(persona[i].estado==0)
                {
                    cargarPersona(persona, libre);
                    printf("desea cargar otra persona? s/n");
                    fflush(stdin);
                    scanf("%c",&otrap);
                }
                else
                {
                    printf("no hay espacio disponible: ");
                    break;
                }

            }
            while(otrap=='s');

            break;
        case 2:
            borrarPersona(persona, A);
            break;
        case 3:
            ordenarPersona(persona, A);
            mostrarPersona(persona, A);
            break;
        case 4:
            ordenaredad(persona, menos18, mas18, mas35, A);
            for(i=0; i<A; i++)
            {
                printf("%c\t%c\t%c\n", menos18[i], mas18[i], mas35[i]);
            };
            printf("\n<18\t19-35\t>35\n\n");
            break;
        case 5:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    };
    return 0;
}

