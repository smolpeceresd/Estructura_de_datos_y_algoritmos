#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <limits>
#include <list>
#include <vector>
#include "aristagrafo.h"
using namespace std;
// PARTICIPANTES:
//CARMEN SANCHEZ HERNANDEZ
//SANTIAGO MOLPECERES DIAZ

class Grafo {
public:
 Grafo(int v);
 ~Grafo();
 int coste(int v, int w);

 void inserta(int v, int w, int coste,string origen , string destino);
 void inserta_del_reves(int v, int w, int coste,string origen , string destino);
 void inserta_de_prim(AristaGrafo* const & P);


 int totalVertices();
 static vector<int> dijkstra(Grafo G);
 static Grafo prim(Grafo G);

 static std::list<AristaGrafo*> viajanteComercioVecino(Grafo G, int v);
 static std::list<AristaGrafo*> viajanteComercioPrim(Grafo G, int v);


 std::string imprime(std::string s);
 std::string imprime_prim(std::string s);
 std::string profundidad(int inicio);
 static std::string imprimeVector(std::string s,vector<int> vector);
 static std::string imprimeLista(std::string s,list<AristaGrafo*>listado);

 vector<vector<AristaGrafo *>> getAristas() const ;

private:
 static const int INFINITO =
         std::numeric_limits<unsigned short int>::max();
 int vertices;
 vector<vector<AristaGrafo*>> aristas;
 int verticeNoVisitado(bool *visitado, int vertices);
 std::string profundidad(int v, bool *&visitado);
};

#endif // GRAFO_H
