#include "nodoarbolbinariobusqueda.h"
#include "arbolbinariobusqueda.h"
#include <sstream>
#include <iostream>
using namespace std;
ArbolBinariodeBusqueda::ArbolBinariodeBusqueda(){
    raiz=nullptr;
}


/*ArbolBinariodeBusqueda::~ArbolBinariodeBusqueda(){
    delete raiz;
}
*/
bool ArbolBinariodeBusqueda::vacio(){
    return (raiz == nullptr);
}

void ArbolBinariodeBusqueda::inserta(int v){
    inserta(raiz, v);
}

void ArbolBinariodeBusqueda::inserta(NodoArbolBinariodeBusqueda *& r, int v){ // & = insertamos en nodo, la direccion.

    if(r == nullptr){
        r = insertaNodo(v);
    }else{
        if(v<r->dato){
            if(r->izquierdo==nullptr){
                r->izquierdo=insertaNodo(v);
            }else{
                inserta(r->izquierdo,v);
            }
        }else{
            if(v>r->dato){
                if(r->derecho==nullptr){
                    r->derecho=insertaNodo(v);
                }else{
                    inserta(r->derecho,v);
                }
            }
        }
    }
}
bool ArbolBinariodeBusqueda::existe(int v){
    return existe(raiz, v);
}




string ArbolBinariodeBusqueda::preorder(){
    return preorder(raiz);

}

string ArbolBinariodeBusqueda::inorder(){
    return inorder(raiz);
}


string ArbolBinariodeBusqueda::postorder(){

    return postorder(raiz);
}
string ArbolBinariodeBusqueda::preorder(NodoArbolBinariodeBusqueda *r){

    stringstream ss;

    if(r != nullptr){
        ss << r->dato << ", " << preorder(r->izquierdo) << preorder(r->derecho);
    }

    return ss.str();
}

string ArbolBinariodeBusqueda::inorder(NodoArbolBinariodeBusqueda *r){

    stringstream ss;

    if(r != nullptr){
        ss << inorder(r->izquierdo) << r->dato << ", " << inorder(r->derecho);
        }
    return ss.str();
}

string ArbolBinariodeBusqueda::postorder(NodoArbolBinariodeBusqueda *r){

    stringstream ss;

    if(r != nullptr){
        ss << postorder(r->izquierdo) << postorder(r->derecho) << r->dato << ", ";
    }
    return ss.str();
}
string ArbolBinariodeBusqueda::imprime(){

    stringstream ss;

    ss << "\n";
    ss << "preorder \t" << preorder(raiz);
    ss << "\n";
    ss << "inorder \t" << inorder(raiz);
    ss << "\n";
    ss << "postorder \t" << postorder(raiz);
    ss << "\n";

return ss.str();}

NodoArbolBinariodeBusqueda *ArbolBinariodeBusqueda::insertaNodo(int v){

    NodoArbolBinariodeBusqueda* nodo = new NodoArbolBinariodeBusqueda;

    nodo->dato = v;
    nodo->izquierdo = nullptr;
    nodo->derecho = nullptr;

    return nodo;
}

bool ArbolBinariodeBusqueda::existe(NodoArbolBinariodeBusqueda * r, int v){

    if(r != nullptr)
    if(r->dato == v) return true;
    else{
        return existe(r->izquierdo, v) || existe(r->derecho, v);
    }else
    return false;
}
