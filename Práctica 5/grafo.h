#ifndef GRAFO_H
#define GRAFO_H
#include "conjuntos.h"
#include <limits>
#include <vector>
using namespace std;
class Grafo {
public:
 Grafo(int v);
 ~Grafo();
 int coste(int v, int w);//
 void inserta(int v, int w, int coste);//
 int totalVertices();
 static vector<int> dijkstra(Grafo G);//
 static Grafo prim(Grafo G);
 static void costeMinimoArista(Grafo G, Conjunto U,Conjunto W, int &u, int &w);
 std::string imprime(std::string s);//
 std::string profundidad(int inicio);//
 static std::string imprimeVector(std::string s,vector<int> vector);//

private:
 static const int INFINITO =
 std::numeric_limits<unsigned short int>::max();
 int vertices;
 int **aristas;
 int verticeNoVisitado(bool *visitado, int vertices);//
 std::string profundidad(int v, bool *&visitado);//
};

#endif // GRAFO_H
