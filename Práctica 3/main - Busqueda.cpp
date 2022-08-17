#include <iostream>
#include "nodoarbolbinariobusqueda.h"
#include "arbolbinariobusqueda.h"
using namespace std;

int main()
{
    ArbolBinariodeBusqueda abb = ArbolBinariodeBusqueda();
    abb.inserta(10);
    abb.inserta(15);
    abb.inserta(12);
    abb.inserta(5);
    abb.inserta(7);
    abb.inserta(1);
    abb.inserta(12);
    if(abb.vacio()==true){
        cout<<"ESTA VACIA";
    }else{
        cout<<"NO ESTA VACIA";
    }
    cout << abb.imprime();
    cout << "\n";
    cout << "\n exist(12) = ";
    if(abb.existe(12)==true){
        cout<<"\nEXISTE 12";
    }else{
        cout<<"\nNO EXISTE 12";

    return 0;
}

}
