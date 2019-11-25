#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LONGITUD_MAXIMA_NRO 1024

int nro_juego;

int longitud(char * cadena);
int terminaEnNro(int nro);
int sumanNroJuego(int nro);
void ejecutar_juego(int nro_maximo);
int cumpleCondicionJuego(int nro);

int longitud(char * cadena)
{
    int i = 0;
    while(cadena[i]!=0)
    {
        i++;
    }
    return i;
}

int terminaEnNro(int nro)
{
    char * aux = (char *) malloc(LONGITUD_MAXIMA_NRO);
    sprintf(aux,"%d",nro);

    char aux_nro_juego = (int) nro_juego + '0';

    char ultimoNro = aux[longitud(aux)-1];

    free(aux);

    if(ultimoNro == aux_nro_juego)
        return 1;
    return 0;
    
}

int esMultiplo(int nro)
{
    if(nro % nro_juego == 0)
        return 1;
    return 0;
}

int sumanNroJuego(int nro)
{
    char * aux = (char *) malloc(LONGITUD_MAXIMA_NRO);
    sprintf(aux,"%d",nro);

    int longitud_cadena = longitud(aux);

    int total = 0;

    for(int i = 0;i<longitud_cadena;i++)
    {
        total += (aux[i] - '0');
    }

    if(total == nro_juego)
        return 1;
    return 0;

}


int cumpleCondicionJuego(int nro)
{
    if(sumanNroJuego(nro) == 1 || esMultiplo(nro) == 1 || terminaEnNro(nro) == 1)
        return 1;
    return 0;   
}

void ejecutar_juego(int nro_maximo)
{
    int contador = 1;
    for(int aux = 1;aux <= nro_maximo;aux++)
    {
        if(cumpleCondicionJuego(aux) == 1)
        {
                printf("Numero: %d Valor: %d\n",contador,aux);
                contador++;
        }
    }
}


