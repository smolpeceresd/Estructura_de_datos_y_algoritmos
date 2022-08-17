#ifndef LISTA_H
#define LISTA_H
#include <string>
#include "nodolista.h"
class Lista {
public:
 Lista();
 //~Lista();
 bool vacia();
 int elementos();
 bool existe(int v);
 void insertaInicio(int v);
 void insertaFin(int v);
 int eliminaInicio();
 void eliminaTodo();
 int eliminaFin();
 void elimina(int v);
 std::string toString(std::string s);
 void elimina(NodoLista *p);
 Lista invierte();
 Lista concatena(Lista c);
private:
 NodoLista *inicio, *fin;
};
#endif // LISTA_H
