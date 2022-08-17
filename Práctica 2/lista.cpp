#include "lista.h"
#include "nodolista.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
Lista::Lista()
{
    inicio=nullptr;
    fin=nullptr;
}

bool Lista::vacia()
{
    if(inicio==nullptr){
        return true;

    }else{
        return false;
    }
}

int Lista::elementos()
{
    int contador=0;
    NodoLista *P=inicio;
    while (P!=nullptr){
        contador++;
        P=P->siguiente;
    }
    return contador;
}

bool Lista::existe(int v)
{
    NodoLista *P=inicio;
    while(P!=nullptr){
        if(P->dato==v){
            return true;
        }
        P=P->siguiente;
    }
    return false;}

void Lista::insertaInicio(int v)
{
    NodoLista *p=new NodoLista;
    p->dato=v;
    if(vacia()==true){
        p->siguiente=nullptr;
        inicio=p;
        fin=p;
    }else{
        p->siguiente=inicio;
        inicio=p;
    }
}

void Lista::insertaFin(int v)
{
    NodoLista *P=new NodoLista;
    P->dato=v;
    P->siguiente=nullptr;
    fin->siguiente=P;
    fin=P;
}

int Lista::eliminaInicio()
{
    if(vacia()==true){
        throw std::string{"\nLA LISTA ESTA YA VACIA"};
    }
    NodoLista*P=inicio;
    int v=P->dato;
    if(inicio==fin){
        inicio=nullptr;
        fin=nullptr;
    }else{
        inicio=inicio->siguiente;
    }
    delete P;
    return v;}

void Lista::eliminaTodo()
{
    if(inicio==fin){
        inicio=nullptr;
        fin=nullptr;
    }else{
        while(inicio!=fin){//elimina todos los incios q suceden
            eliminaInicio();
        }
        if(inicio==fin){
            inicio=nullptr;
            fin=nullptr;
        }
    }
}
    int Lista::eliminaFin()
    {
        if(fin==nullptr){
            throw std::string{"Lista Vacia"};
        }
        NodoLista *P=fin;
        int v=P->dato;
        if(inicio==fin){
            inicio=nullptr;
            fin=nullptr;
        }else{
            NodoLista *q=inicio;
            while(q->siguiente!=fin){
                q=q->siguiente;
            }
            fin=q;
            fin->siguiente=nullptr;
        }
        delete(P);
        return v;}

    void Lista::elimina(int v)
    {
        if(vacia()==true){
            throw std::string{"LA LISTA ESTA VACIA"};
        }else if(existe(v)==false){
            throw std::string{"EL NUMERO NO EXISTE EN LA LISTA"};
        }else{
            if(inicio==fin){
                inicio=nullptr;
                fin=nullptr;
            }else{
                while(inicio->dato==v){//elimina todos los incios q suceden
                    eliminaInicio();
                }
                while(fin->dato==v){//elimina todos los fines con q suceden
                    eliminaFin();
                }
                NodoLista *I=inicio;
                while (I!=fin){
                    if(I->siguiente->dato == v) {
                        NodoLista * e = I->siguiente->siguiente;
                        delete (I->siguiente);
                        I->siguiente = e;
                    }else{
                        I=I->siguiente;
                    }
                }
            }
        }
    }
    std::string Lista::toString(std::string s)
    {
        std::stringstream ss;
        NodoLista *P=inicio;
        if(P==nullptr){
            ss<< "\nLista vacia\n";
        }else{
            ss<<s<<" { ";
            while(P!=nullptr){
                ss<<P->dato<<",";
                P=P->siguiente;
            }
            ss<<"}\n";
        }
        return ss.str();
    }

    void Lista::elimina(NodoLista *p)
    {
        delete p;
    }

    Lista Lista::invierte()
    {
        Lista L=Lista();
        NodoLista *J=inicio;
        while(J!=nullptr){
            L.insertaInicio(J->dato);
            J=J->siguiente;}
        return L;
    }

    Lista Lista::concatena(Lista C)
    {
        Lista M=Lista();
        if(vacia()==true){
            M=C;
            return C;
        }
        NodoLista *D=inicio;
        M.insertaInicio(inicio->dato);
        D=D->siguiente;
        while(D!=nullptr){
            M.insertaFin(D->dato);
            D=D->siguiente;
        }
        NodoLista *R=C.inicio;
        while(R!=nullptr){
            M.insertaFin(R->dato);
            R=R->siguiente;
        }
        return M;}
