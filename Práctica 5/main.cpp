#include <iostream>
#include "grafo.h"
using namespace std;

int main()
{
    Grafo g1 = Grafo(5);
    g1.inserta(1, 2, 10);
    g1.inserta(1, 4, 30);
    g1.inserta(1, 5, 100);
    g1.inserta(2, 3, 50);
    g1.inserta(3, 5, 10);
    g1.inserta(4, 3, 20);
    g1.inserta(4, 5, 60);
    std::cout << g1.imprime("Grafo");
    // recorrido en profundidad
    Grafo g2 = Grafo(7);
    g2.inserta(1, 2, 10);
    g2.inserta(2, 3, 10);
    g2.inserta(2, 4, 10);
    g2.inserta(3, 1, 10);
    g2.inserta(4, 1, 10);
    g2.inserta(5, 6, 10);
    g2.inserta(5, 7, 10);
    g2.inserta(6, 2, 10);
    g2.inserta(7, 4, 10);
    g2.inserta(7, 6, 10);
    std::cout << g2.imprime("Grafo");
    std::cout << g2.profundidad(1);
    // el camino mas corto: Dijkstra
    Grafo d = Grafo(5);
   /* d.inserta(1, 2, 10);
    d.inserta(1, 4, 30);
    d.inserta(1, 5, 100);
    d.inserta(2, 2, 10);
    d.inserta(2, 3, 60);
    d.inserta(2, 4, 30);
    d.inserta(2, 5, 100);
    d.inserta(3, 2, 10);
    d.inserta(3, 3, 50);
    d.inserta(3, 4, 30);
    d.inserta(3, 5, 60);
    d.inserta(4, 2, 10);
    d.inserta(4, 3, 50);
    d.inserta(4, 4, 30);
    d.inserta(4, 5, 90);
    d.inserta(5, 2, 10);
    d.inserta(5, 3, 50);
    d.inserta(5, 4, 30);
    d.inserta(5, 5, 60);*/
    d.inserta(1, 2, 10);
    d.inserta(1, 4, 30);
    d.inserta(1, 5, 100);
    d.inserta(2, 3, 50);
    d.inserta(3, 5, 10);
    d.inserta(4, 3, 20);
    d.inserta(4, 5, 60);


    std::cout << d.imprime("Grafo para Dijkstra");
    vector<int> C = Grafo::dijkstra(d);
    std::cout << Grafo::imprimeVector("Costes Dijkstra", C);
    cout<<"\n";
    Grafo p = Grafo(6);//prim
    p.inserta(1, 2, 6);
    p.inserta(2, 1, 6);
    p.inserta(1, 3, 1);
    p.inserta(3, 1, 1);
    p.inserta(1, 4, 5);
    p.inserta(4, 1, 5);
    p.inserta(2, 3, 5);
    p.inserta(3, 2, 5);
    p.inserta(2, 5, 3);
    p.inserta(5, 2, 3);
    p.inserta(3, 4, 5);
    p.inserta(4, 3, 5);
    p.inserta(3, 5, 6);
    p.inserta(5, 3, 6);
    p.inserta(3, 6, 4);
    p.inserta(6, 3, 4);
    p.inserta(4, 6, 2);
    p.inserta(6, 4, 2);
    p.inserta(5, 6, 6);
    p.inserta(6, 5, 6);
    std::cout << p.imprime("Grafo para Prim");
    Grafo r = Grafo::prim(p);
    std::cout << r.imprime("Arbol de recubrimiento minimo de P");
    return 0;
}
