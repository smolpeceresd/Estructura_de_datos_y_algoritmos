#ifndef ARISTAGRAFO_H
#define ARISTAGRAFO_H
#include <string>
// PARTICIPANTES:
//CARMEN SANCHEZ HERNANDEZ
//SANTIAGO MOLPECERES DIAZ


using namespace std;

class AristaGrafo {
public:
int v, w, coste;
string origen,destino;
AristaGrafo(int v1, int v2, int c,string _origen, string _destino);
int getCoste() const;
};

#endif // ARISTAGRAFO_H
