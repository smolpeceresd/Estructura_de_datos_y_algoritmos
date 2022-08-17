#include "arbolavl.h"
#include"nodoarbolavl.h"
#include <sstream>
using namespace std;
ArbolAVL::ArbolAVL()
{
    r=nullptr;
}

bool ArbolAVL::vacio()
{
    return (r==nullptr);
}

void ArbolAVL::inserta(int v)
{
    inserta(r,v);
}

void ArbolAVL::elimina(int v)
{
    elimina(r,v);
}

NodoArbolAVL *ArbolAVL::busca(int v)
{
    return  busca(r,v);
}

string ArbolAVL::imprime()
{
    stringstream ss;

    ss << "\n";
    ss << "preorder \t" << preorder(r);
    ss << "\n";
    ss << "inorder \t" << inorder(r);
    ss << "\n";
    ss << "postorder \t" << postorder(r);
    ss << "\n";

    return ss.str();
}

string ArbolAVL::preorder()
{
    return preorder(r);
}

string ArbolAVL::inorder()
{
    return inorder(r);
}

string ArbolAVL::postorder()
{
    return postorder(r);
}

int ArbolAVL::altura()
{
    return altura(r);
}
void ArbolAVL::inserta(NodoArbolAVL*& r, int v) {
    if (r == nullptr){
        r = insertaNodo(v);
    }else{
        if (v < r->dato){
            if (r->izquierdo == nullptr){
                r->izquierdo = insertaNodo(v);
            }else{
                inserta(r->izquierdo, v);
            }
        }else{
            if (v > r->dato){
                if (r->derecho == nullptr){
                    r->derecho = insertaNodo(v);
                }else{
                    inserta(r->derecho, v);
                }
            }

        }
        r->altura = altura(r);
        r->equilibrio = equilibrio(r);
        if (abs(r->equilibrio) > 1){// autobalance del árbol
            autobalance(r);
        }
    }
}

NodoArbolAVL *ArbolAVL::insertaNodo(int v)
{
    NodoArbolAVL* nodo=new NodoArbolAVL;
    nodo->dato=v;
    nodo->altura=0;
    nodo->equilibrio=0;
    nodo->izquierdo=nullptr;
    nodo->derecho=nullptr;
    return nodo;
}

void ArbolAVL::elimina(NodoArbolAVL *&r, int v)
{
    if(r!=nullptr){
        if(v<r->dato){
            elimina(r->izquierdo,v);
        }else if(v>r->dato){
            elimina(r->derecho,v);
        }else{
            //para una hoja
            if(r->izquierdo==nullptr && r->derecho==nullptr){
                r=nullptr;
            }else if(r->izquierdo==nullptr){
                r=r->derecho;
            }else if(r->derecho==nullptr){
                r=r->izquierdo;
            }else{
                r->dato=eliminaMinimo(r->derecho);
            }
        }
    }
}

int ArbolAVL::eliminaMinimo(NodoArbolAVL *&r)
{
    int minimo;
    if(r->izquierdo==nullptr){
        minimo=r->dato;
        r=r->derecho;
    }else{
        minimo=eliminaMinimo(r->izquierdo);
    }
    return minimo;
}

NodoArbolAVL *ArbolAVL::busca(NodoArbolAVL *r, int v)
{
    NodoArbolAVL* nodo;
    if(r==nullptr){
        nodo=nullptr;
    }else{
        if(r->dato==v){
            nodo=r;
        }else if(r->dato<v){
            nodo=busca(r->derecho,v);
        }else{
            nodo=busca(r->izquierdo,v);
        }
    }
    return nodo;
}

std::string ArbolAVL::preorder(NodoArbolAVL *r)
{
    stringstream ss;

    if(r != nullptr){
        ss << r->dato << ", " << preorder(r->izquierdo) << preorder(r->derecho);
    }

    return ss.str();
}

string ArbolAVL::inorder(NodoArbolAVL *r)
{
    stringstream ss;

    if(r != nullptr){
        ss << inorder(r->izquierdo) << r->dato << ", " << inorder(r->derecho);
    }
    return ss.str();
}

string ArbolAVL::postorder(NodoArbolAVL *r)
{
    stringstream ss;

    if(r != nullptr){
        ss << postorder(r->izquierdo) << postorder(r->derecho) << r->dato << ", ";
    }
    return ss.str();
}

int ArbolAVL::max(int a, int b)
{
    return (a>=b)?a :b;
}

int ArbolAVL::altura(NodoArbolAVL *r)
{
    return ((r==nullptr)? -1:max(altura(r->izquierdo),altura(r->derecho))+1);
}

int ArbolAVL::equilibrio(NodoArbolAVL *r)
{
    return (altura(r->derecho)-altura(r->izquierdo));
}

void ArbolAVL::rotacionIzquierda(NodoArbolAVL *&n1)
{
    NodoArbolAVL*n2;
    n2=n1->derecho;
    n1->derecho=n2->izquierdo;
    n2->izquierdo=n1;

    n1->altura=altura(n1);
    n1->equilibrio=equilibrio(n1);

    n2->altura=altura(n2);
    n2->equilibrio=equilibrio(n2);

    if(r==n1){
        r=n2;
    }else{
        n1=n2;
    }
}

void ArbolAVL::rotacionDerecha(NodoArbolAVL *&n1)
{
    NodoArbolAVL *n2;
    n2=n1->izquierdo;
    n1->izquierdo=n2->derecho;
    n2->derecho=n1;

    n1->altura=altura(n1);
    n1->equilibrio=equilibrio(n1);

    n2->altura=altura(n2);
    n2->equilibrio=equilibrio(n2);

    if(r==n1){
        r=n2;
    }else{
        n1=n2;
    }
}

void ArbolAVL::autobalance(NodoArbolAVL *&r)
{
    if(r->equilibrio==2){
        rotacionIzquierda(r);
    }else if(r->equilibrio==-2){
        rotacionDerecha(r);
    }
}

NodoArbolAVL *ArbolAVL::minimo(NodoArbolAVL *r)
{
    while(r->izquierdo!=nullptr){
        r=r->izquierdo;
    }
    return r;
}

NodoArbolAVL *ArbolAVL::maximo(NodoArbolAVL *r)
{
    while(r->derecho!=nullptr){
        r=r->derecho;
    }
    return r;
}
