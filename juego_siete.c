#include "juego_siete.h"



int main(int argc, char ** argv)
{
    if(argc != 3)
        return -1;

    nro_juego = atoi(argv[1]);
    int nro_maximo = atoi(argv[2]);

    ejecutar_juego(nro_maximo);
}