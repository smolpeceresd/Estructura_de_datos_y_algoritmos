#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H


#include <string>
#include "nodoarbolbinariobusqueda.h"
class ArbolBinariodeBusqueda {
public:
 ArbolBinariodeBusqueda();
 //~ArbolBinarioBusqueda();
 bool vacio();
 void inserta(int v);
 bool existe(int v);
 std::string imprime();
 std::string preorder();
 std::string inorder();
 std::string postorder();
private:
 NodoArbolBinariodeBusqueda* raiz;
 void inserta(NodoArbolBinariodeBusqueda* & r, int v);
 NodoArbolBinariodeBusqueda* insertaNodo(int v);
 bool existe(NodoArbolBinariodeBusqueda* r, int v);
 std::string preorder(NodoArbolBinariodeBusqueda* r);
 std::string inorder(NodoArbolBinariodeBusqueda* r);
 std::string postorder(NodoArbolBinariodeBusqueda* r);
};

#endif // ARBOLBINARIOBUSQUEDA_H
