#include "funciones.h"
#include <string.h>
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define A 20


void cargarPersona(EPersona persona[], int libre)
{
    int i;
    int edad, dni;
    char nombre[20];
    int flagdni, flagedad;
    int estado;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    strcpy(persona[libre].nombre, nombre);
    strupr(persona[libre].nombre);

    printf("Ingrese edad: ");
    scanf("%d", &edad );
    persona[libre].edad= edad;

    printf("Ingrese DNI: ");
    scanf("%d", &dni );
    persona[libre].dni= dni;

    estado= 1;
    persona[libre].estado= estado;
};

void mostrarPersona(EPersona persona[], int tam)
{
    int i;
    printf("\nPersonas:\n");
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado!= 0)
        {
            printf("%s\t%d\t%d\n", persona[i].nombre, persona[i].edad, persona[i].dni);
        }
    };
}



void ordenarPersona(EPersona persona[], int tam)
{
    int i, j, num;
    EPersona nombre;
    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)==1)
            {
                nombre= persona[i];
                persona[i]= persona[j];
                persona[j]= nombre;
            }
            else if(strcmp(persona[i].nombre, persona[j].nombre)==0)
            {
                if(persona[i].dni>persona[j].dni)
                {
                    nombre= persona[i];
                    persona[i]= persona[j];
                    persona[j]= nombre;
                }
            }
        }
    }
}



void borrarPersona(EPersona persona[], int tam)
{
    int aux, i;
    int flagEncontro = 0;
    char respuesta;

    printf("ingrese DNI de la persona que desea borrar: "),
           scanf("%d", &aux);
    for(i=0; i<A; i++)
    {
        if(persona[i].estado!=0 && aux==persona[i].dni)
        {
            printf("%d\t%s\t%d\n", persona[i].edad, persona[i].nombre, persona[i].dni);

            printf("Esta seguro de eliminar a esta persona? s/n ");
            respuesta = getche();
            if(respuesta=='s')
            {
                persona[i].estado = 0;
            }
            else
            {
                printf("cancelado");
            }
            flagEncontro = 1;
            break;
        }
    }
    if(flagEncontro==0)
    {
        printf("DNI inexistente");
    }
}

void ordenaredad(EPersona persona[],char menos18[], char mas18[],char mas35[], int tam)
{
    int con18=0, con19=0, con35=0;
    char auxme18, auxma18, auxma35;
    int i, j;

    for(i=0; i<A; i++)
    {
        if(persona[i].edad<18&& persona[i].edad>0)
        {
            con18++;
        };
        if(persona[i].edad>18 && persona[i].edad<35)
        {
            con19++;
        };
        if(persona[i].edad>35&& persona[i].edad<150)
        {
            con35++;
        };

    };

    for(i=0; i<con18; i++)
    {
        menos18[i]='*';
    };
    for(i=0; i<con19; i++)
    {
        mas18[i]='*';
    };
    for(i=0; i<con35; i++)
    {
        mas35[i]='*';
    };
    for(i=0; i<A; i++)
    {
        for(j=i+1; j<A; j++)
        {
            if(menos18[i]=='*')
            {
                auxme18= menos18[i];
                menos18[i]= menos18[j];
                menos18[j]= auxme18;
            };
        };
    };
    for(i=0; i<A; i++)
    {
        for(j=i+1; j<A; j++)
        {
            if(mas18[i]=='*')
            {
                auxma18= mas18[i];
                mas18[i]= mas18[j];
                mas18[j]= auxma18;
            };
        };
    };
    for(i=0; i<A; i++)
    {
        for(j=i+1; j<A; j++)
        {
            if(mas35[i]=='*')
            {
                auxma35= mas35[i];
                mas35[i]= mas35[j];
                mas35[j]= auxma35;
            };
        };
    };
}





