#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H


#include <string>
#include "nodoarbolbinario.h"
class ArbolBinario {
public:
    ArbolBinario(int v, NodoArbolBinario* izquierdo,
                 NodoArbolBinario* derecho);
    //~ArbolBinario();
    bool vacio();
    static NodoArbolBinario* insertaHoja(int v);
    static NodoArbolBinario *insertaNodo(int v,
                                         NodoArbolBinario* izquierdo,
                                         NodoArbolBinario* derecho);
    bool existe(int v);
    std::string imprime();
    std::string preorder();
    std::string inorder();
    std::string postorder();
private:
    NodoArbolBinario* raiz;
    bool existe(NodoArbolBinario* r, int v);
    std::string preorder(NodoArbolBinario* r);
    std::string inorder(NodoArbolBinario* r);
    std::string postorder(NodoArbolBinario* r);
};
#endif // ARBOLBINARIO_H
