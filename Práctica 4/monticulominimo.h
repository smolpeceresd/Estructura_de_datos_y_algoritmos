#ifndef MONTICULOMINIMO_H
#define MONTICULOMINIMO_H
#include <iostream>

class MonticuloMinimos{
public:
MonticuloMinimos(int c);//
//~MonticuloMinimos();
bool vacio();//
void inserta(int p);//
int eliminaMinimo();//
std::string imprime();//
private:
bool minimo(int &min);//
void intercambio(int i, int j);//
void intercambioAscendente(int padre, int hijo);//
void intercambioDescendente(int padre);
int ultimo;//
int capacidad;//
int *prioridad;//
};

#endif // MONTICULOMINIMO_H
