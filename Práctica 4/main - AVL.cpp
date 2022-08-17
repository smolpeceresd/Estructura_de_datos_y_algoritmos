#include <iostream>
#include "arbolavl.h"
#include "nodoarbolavl.h"
using namespace std;

int main()
{
    std::cout << "Arbol balanceado AVL \n";
    //
    // caso 1. rotacion simple a la izquierda
    //
    ArbolAVL avl1 = ArbolAVL();
    avl1.inserta(8);
    avl1.inserta(1);
    avl1.inserta(12);
    avl1.inserta(10);
    avl1.inserta(15);
    std::cout << "\n";
    std::cout << "\n- caso 1. rotacion simple a la izquierda";
    std::cout << "\n";
    std::cout << avl1.imprime();
    avl1.inserta(20);
    std::cout << "\n- caso 1. rotacion después de insertar el 20 \n";
    std::cout << avl1.imprime();
    //
    // caso 2. rotacion simple a la derecha
    //
    ArbolAVL avl2 = ArbolAVL();
    avl2.inserta(15);
    avl2.inserta(10);
    avl2.inserta(20);
    avl2.inserta(5);
    avl2.inserta(12);
    std::cout << "\n";
    std::cout << "\n- caso 2. rotacion simple a la derecha";
    std::cout << "\n";
    std::cout << avl2.imprime();
    avl2.inserta(2);
    std::cout << "\n- caso 2. rotacion despues de insertar el 2 \n";
    std::cout << avl2.imprime();
    //
    // caso 3. rotacion doble izquierda-derecha
    //
    ArbolAVL avl3 = ArbolAVL();
    avl3.inserta(15);
    avl3.inserta(2);
    avl3.inserta(20);
    avl3.inserta(1);
    avl3.inserta(6);
    avl3.inserta(25);
    avl3.inserta(5);
    avl3.inserta(8);
    std::cout << "\n";
    std::cout << "\n- caso 3. rotacion doble izquierda-derecha";
    std::cout << "\n";
    std::cout << avl3.imprime();
    avl3.inserta(3);
    std::cout << "\n- caso 3. rotacion después de insertar el 3 \n";
    std::cout << avl3.imprime();
    //
    // caso 4. rotacion doble derecha-izquierda
    //
    ArbolAVL avl4 = ArbolAVL();
    avl4.inserta(5);
    avl4.inserta(3);
    avl4.inserta(15);
    avl4.inserta(1);
    avl4.inserta(8);
    avl4.inserta(20);
    avl4.inserta(6);
    avl4.inserta(9);
    std::cout << "\n";
    std::cout << "\n- caso 4. rotacion doble derecha-izquierda";
    std::cout << "\n";
    std::cout << avl4.imprime();
    avl4.inserta(10);
    std::cout << "\n- caso 4. rotacion despues de insertar el 10 \n";
    std::cout << avl4.imprime();
    ArbolAVL avl5 = ArbolAVL();
    avl5.inserta(2);
    avl5.inserta(1);
    avl5.inserta(8);
    avl5.inserta(0);
    avl5.inserta(5);
    avl5.inserta(9);
    avl5.inserta(4);
    avl5.inserta(10);
    std::cout << "\n";
    std::cout << "\n- eliminacion de nodos";
    std::cout << "\n";
    std::cout << avl5.imprime();
    avl5.elimina(4);
    std::cout << "\n- elimina nodo 4 \n";
    std::cout << avl5.imprime();
    avl5.elimina(9);
    std::cout << "\n- elimina nodo 9 \n";
    std::cout << avl5.imprime();
    avl5.elimina(2);
    std::cout << "\n- elimina nodo 2 \n";
    std::cout << avl5.imprime();
    avl5.elimina(0);
    std::cout << "\n- elimina nodo 0 \n";
    std::cout << avl5.imprime();
    avl5.elimina(1);
    std::cout << "\n- elimina nodo 1 \n";
    std::cout << avl5.imprime();
}
