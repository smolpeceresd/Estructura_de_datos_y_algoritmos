#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>
class Conjunto {

public:

    Conjunto(int c);
    Conjunto(int f, int c, int cant);
    Conjunto(int c, bool pertenece);
    ~Conjunto();

    bool vacio() const;
    void inserta(int e);
    void elimina(int e);
    bool pertenece(int e);
    bool esIgual(Conjunto A);

    static Conjunto une(Conjunto A, Conjunto B);
    static Conjunto resta(Conjunto A, Conjunto B);
    static Conjunto intersecta(Conjunto A, Conjunto B);

    std::string imprime(std::string s);

private:

    int cardinalidad;
    bool *elementos;

};
#endif // CONJUNTO_H
