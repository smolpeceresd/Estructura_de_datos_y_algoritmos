#include <iostream>
#include "lista.h"
#include "nodolista.h"
using namespace std;

int main()
{
    Lista L=Lista();
    if(L.vacia()==true){
        cout<<"\n La lista esta vacia";
    }
    L.insertaInicio(50);
    L.insertaInicio(40);
    L.insertaInicio(30);
    L.insertaFin(60);
    L.insertaFin(30);
    L.insertaInicio(30);
    L.insertaInicio(20);
    L.insertaFin(30);
    L.insertaFin(80);
    L.insertaFin(30);
    L.insertaFin(50);
    L.insertaFin(30);
    L.insertaFin(30);
    L.insertaInicio(10);
    cout<< L.toString("\nLISTA L\n");

    if(L.existe(20)==true){
        cout<<"\nEXISTEEEEE :P\n";
    }else{
        cout<<"\nQUE TE DEN , NO EXISTE ";
    }
    L.eliminaInicio();
    L.eliminaInicio();
    L.eliminaFin();
    cout<<L.toString("\nLISTA: ");
    try {
        L.elimina(30);
        cout<<L.toString("\nLISTA: ");
    } catch (std::string msg) {
        cout<<"\nERROR: "<<msg;
    }
    cout<<"\nLEYENDO J";
    Lista J=Lista();
    J=L.invierte();
    cout<<J.toString("\nLISTA: ");
    cout<<"\nCONCADENANDO Lista J a L\n";
    L=L.concatena(J);
    cout<<L.toString("\nLISTA: ");
    L.elimina(60);
    cout<<L.toString("\nLISTA: ");
    L.eliminaTodo();
    cout<<L.toString("\nLISTA: ");
    return 0;}
