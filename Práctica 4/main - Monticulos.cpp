#include <iostream>
#include "monticulominimo.h"
using namespace std;

int main()
{
    std::cout << "Monticulo de minimos \n";
    MonticuloMinimos m = MonticuloMinimos(50);
    m.inserta(4);
    m.inserta(5);
    m.inserta(6);
    m.inserta(3);
    m.inserta(11);
    m.inserta(7);
    m.inserta(9);
    m.inserta(14);
    m.inserta(10);
    m.inserta(8);
    std::cout << m.imprime();
    std::cout << "inserta 2 \n";
    m.inserta(2);
    std::cout << m.imprime();
    int min;
    min = m.eliminaMinimo();
    std::cout << "elimina minimo=" << min << "\n";
    std::cout << m.imprime();
    min = m.eliminaMinimo();
    std::cout << "elimina minimo=" << min << "\n";
    std::cout << m.imprime();
    return 0;
}
