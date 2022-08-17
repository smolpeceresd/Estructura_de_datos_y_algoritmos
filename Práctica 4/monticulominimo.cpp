#include "monticulominimo.h"
#include <sstream>
using namespace std;
MonticuloMinimos::MonticuloMinimos(int c) {
    if (c <= 0)
        throw std::runtime_error("Tamaño de montículo no válido");
    ultimo = -1;
    capacidad = c;
    prioridad = new int[capacidad];
}
bool MonticuloMinimos::vacio() {
    return (ultimo < 0);
}
void MonticuloMinimos::inserta(int p) {
    if (ultimo == capacidad - 1)
        throw std::runtime_error("Monticulo lleno");
    ultimo++;
    prioridad[ultimo] = p;
    intercambioAscendente((ultimo - 1) / 2, ultimo);
}
int MonticuloMinimos::eliminaMinimo() {
    if (vacio())
        throw std::runtime_error("Monticulo vacío");
    int min = prioridad[0];
    prioridad[0] = prioridad[ultimo--];
    intercambioDescendente(0);
    return min;
}
std::string MonticuloMinimos::imprime() {
    std::stringstream ss;
    ss << "{";
    for (int i = 0; i <= ultimo; i++)
        ss << prioridad[i] << ", ";
    ss << "} \n";
    return ss.str();
}

void MonticuloMinimos::intercambioAscendente(int padre, int hijo)
{
    if(prioridad[hijo]<prioridad[padre]){
        intercambio(padre,hijo);
    }
    if(padre!=0){
        intercambioAscendente((padre-1)/2,padre);
    }
}

void MonticuloMinimos::intercambioDescendente(int padre)
{
    int izquierda=2*padre+1;
    int derecha=2*padre+2;
    if(izquierda<=ultimo){
        if(prioridad[izquierda]< prioridad[derecha]){
            if(prioridad[padre]>prioridad[izquierda]){
                intercambio(padre,izquierda);
                intercambioDescendente(izquierda);
            }
        }else{
            if(prioridad[padre]>prioridad[derecha]){
                intercambio(padre,derecha);
                intercambioDescendente(derecha);
            }
        }
    }else{
        if(prioridad[padre]>prioridad[izquierda]){
            intercambio(padre,izquierda);
            intercambioDescendente(izquierda);
        }
    }
}
bool MonticuloMinimos::minimo(int &min) {
    if (vacio())
        return false;
    else
        min = prioridad[0];
    return true;
}
void MonticuloMinimos::intercambio(int i, int j) {
    int v = prioridad[i];
    prioridad[i] = prioridad[j];
    prioridad[j] = v;
}
