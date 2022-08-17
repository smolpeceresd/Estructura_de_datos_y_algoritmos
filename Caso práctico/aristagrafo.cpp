#include "aristagrafo.h"
#include <iostream>
// PARTICIPANTES:
//CARMEN SANCHEZ HERNANDEZ
//SANTIAGO MOLPECERES DIAZ
int AristaGrafo::getCoste() const
{
    return coste;
}

AristaGrafo::AristaGrafo(int v1, int v2, int c, string _origen, string _destino)
{
    v = v1;
    w = v2;
    coste = c;
    origen=_origen;
    destino=_destino;
}
