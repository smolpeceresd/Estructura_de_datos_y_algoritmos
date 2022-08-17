#include "conjuntos.h"
#include <sstream>
#include <iostream>

Conjunto::Conjunto(int c) {
    cardinalidad = c;
    elementos = new bool[cardinalidad];

    for (int i = 0; i < cardinalidad; i++)
        elementos[i] = false;
}

Conjunto::Conjunto(int c, bool pertenece) {
    cardinalidad = c;
    elementos = new bool[cardinalidad];

    for (int i = 0; i < cardinalidad; i++)
        elementos[i] = pertenece;
}

Conjunto::~Conjunto() {
    delete[] elementos;
}

bool Conjunto::vacio() const {
    bool vacio = true;

    for (int i = 0; i < cardinalidad; i++)
        if (elementos[i]) {
            vacio = false;
            break;
        }

    return vacio;
}

void Conjunto::inserta(int e) {
    if (e >= 1 && e <= cardinalidad)
        elementos[e - 1] = true;
}

void Conjunto::elimina(int e) {
    if (e >= 1 && e <= cardinalidad)
        elementos[e - 1] = false;
}

bool Conjunto::pertenece(int e) {
    bool existe;

    if (e >= 1 && e <= cardinalidad)
        existe = elementos[e - 1];
    else
        existe = false;

    return existe;
}

bool Conjunto::esIgual(Conjunto A) {
    bool iguales;

    if (A.cardinalidad == cardinalidad) {
        iguales = true;

        for (int i = 0; i < A.cardinalidad; i++)
            if (A.elementos[i] != elementos[i]) {
                iguales = false;
                break;
            }
    }
    else
        iguales = false;

    return iguales;
}

Conjunto Conjunto::une(Conjunto A, Conjunto B) {
    Conjunto C = Conjunto(A.cardinalidad);

    if (A.cardinalidad == B.cardinalidad) {
        for (int i = 1; i <= A.cardinalidad; i++)
            if (A.pertenece(i) || B.pertenece(i))
                C.inserta(i);
    }

    return C;
}

Conjunto Conjunto::resta(Conjunto A, Conjunto B) {
    Conjunto C = Conjunto(A.cardinalidad);

    if (A.cardinalidad == B.cardinalidad) {
        for (int i = 1; i <= A.cardinalidad; i++)
            if (A.pertenece(i) && !B.pertenece(i))
                C.inserta(i);
    }

    return C;
}

Conjunto Conjunto::intersecta(Conjunto A, Conjunto B) {
    Conjunto C = Conjunto(A.cardinalidad);

    if (A.cardinalidad == B.cardinalidad) {
        for (int i = 1; i <= A.cardinalidad; i++)
            if (A.pertenece(i) && B.pertenece(i))
                C.inserta(i);
    }

    return C;
}

std::string Conjunto::imprime(std::string s) {
    std::stringstream ss;

    ss << s << " {";

    for (int i = 0; i < cardinalidad; i++)
        if (elementos[i])
            ss << " " << (i + 1);

    ss << " } \n";

    return ss.str();
}
