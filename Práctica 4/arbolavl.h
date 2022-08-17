#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include "nodoarbolavl.h"

class ArbolAVL {
public:
ArbolAVL();
//~ArbolAVL();
bool vacio();//
void inserta(int v);//
void elimina(int v);//
NodoArbolAVL* busca(int v);//
std::string imprime();//
std::string preorder();//
std::string inorder();//
std::string postorder();//
int altura();//
private:
NodoArbolAVL* r;
void inserta(NodoArbolAVL*& r, int v);//
NodoArbolAVL* insertaNodo(int v);//
void elimina(NodoArbolAVL*& r, int v);//
int eliminaMinimo(NodoArbolAVL*& r);//
NodoArbolAVL *busca(NodoArbolAVL* r, int v);//
std::string preorder(NodoArbolAVL* r);//
std::string inorder(NodoArbolAVL* r);//
std::string postorder(NodoArbolAVL* r);//
int max(int a, int b);//
int altura(NodoArbolAVL* r);//
int equilibrio(NodoArbolAVL* r);//
void rotacionIzquierda(NodoArbolAVL*& r);//
void rotacionDerecha(NodoArbolAVL*& n1);
void autobalance(NodoArbolAVL*& r);//
NodoArbolAVL* minimo(NodoArbolAVL* r);//
NodoArbolAVL *maximo(NodoArbolAVL* r);//
};

#endif // ARBOLAVL_H
