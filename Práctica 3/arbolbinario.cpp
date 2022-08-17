#include "arbolbinario.h"
#include <sstream>
using namespace std;
ArbolBinario::ArbolBinario(int v, NodoArbolBinario *izquierdo, NodoArbolBinario *derecho)
{
    NodoArbolBinario* nodo= new NodoArbolBinario;
    nodo->dato=v;
    nodo->izquierdo=izquierdo;
    nodo->derecho=derecho;
    raiz=nodo;
}

bool ArbolBinario::vacio()
{
    return (raiz==nullptr);
}

NodoArbolBinario *ArbolBinario::insertaHoja(int v)
{
    NodoArbolBinario* nodo=new NodoArbolBinario;
    nodo->dato=v;
    nodo->derecho=nullptr;
    nodo->izquierdo=nullptr;
    return nodo;
}

NodoArbolBinario *ArbolBinario::insertaNodo(int v, NodoArbolBinario *izquierdo, NodoArbolBinario *derecho)
{
    NodoArbolBinario* nodo=new NodoArbolBinario;
    nodo->dato=v;
    nodo->derecho=derecho;
    nodo->izquierdo=izquierdo;
    return nodo;
}

bool ArbolBinario::existe(int v)
{
    return existe(raiz,v);
}

std::string ArbolBinario::imprime()
{
    std::stringstream ss;
    ss<<"\n";
    ss<<"Preorder:\t"<<preorder(raiz);
    ss<<"\n";
    ss<<"Inorder:\t"<<inorder(raiz);
    ss<<"\n";
    ss<<"Postorder:\t"<<postorder(raiz);
    ss<<"\n";
    return ss.str();
}

std::string ArbolBinario::preorder()
{
    return preorder(raiz);
}

std::string ArbolBinario::inorder()
{
    return inorder(raiz);
}

std::string ArbolBinario::postorder()
{
    return postorder(raiz);
}

bool ArbolBinario::existe(NodoArbolBinario *r, int v)
{
    if(r!=nullptr){
        if(r->dato==v){
            return true;
        }else{
            return existe(r->izquierdo,v) || existe(r->derecho,v);
        };
    } else {
        return false;
    }
}

string ArbolBinario::preorder(NodoArbolBinario *r){

    stringstream ss;

    if(r != nullptr){
        ss << r->dato << ", " << preorder(r->izquierdo) << preorder(r->derecho);
    }

    return ss.str();
}

string ArbolBinario::inorder(NodoArbolBinario *r){

    stringstream ss;

    if(r != nullptr){
        ss << inorder(r->izquierdo) << r->dato << ", " << inorder(r->derecho);
        }
    return ss.str();
}

string ArbolBinario::postorder(NodoArbolBinario *r){

    stringstream ss;

    if(r != nullptr){
        ss << postorder(r->izquierdo) << postorder(r->derecho) << r->dato << ", ";
    }
    return ss.str();
}



