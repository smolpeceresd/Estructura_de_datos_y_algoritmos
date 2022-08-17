#include <iostream>
#include <arbolbinario.h>
#include <arbolbinariodebusqueda.h>
#include <nodoarbolbinario.h>
#include <sstream>
using namespace std;

int main()
{
    NodoArbolBinario* n1=ArbolBinario::insertaHoja(20);
    NodoArbolBinario* n2=ArbolBinario::insertaHoja(10);
    NodoArbolBinario* n3=ArbolBinario::insertaNodo(30,n1,n2);
    NodoArbolBinario* n4=ArbolBinario::insertaHoja(40);
    NodoArbolBinario* n5=ArbolBinario::insertaHoja(60);
    NodoArbolBinario* n6=ArbolBinario::insertaNodo(100,n4,n5);
    ArbolBinario ab= ArbolBinario(5,n3,n6);
    if(ab.vacio()==true){
        cout<<"ESTA VACIA";
    }else{
        cout<<"no va";
    }
    std::cout << "\n";
    std::cout << "\nJoder";
    cout<<ab.imprime();
    if(ab.existe(30)==true){
        std::cout << "existe el numero 30";
    }else{
        cout<<"\nNO EXISTE 12";
    }
    if(ab.existe(25)==true){
        std::cout << "existe el numero 25";
    }else{
        cout<<"\nNO EXISTE 25";
    }

    return 0;
}
