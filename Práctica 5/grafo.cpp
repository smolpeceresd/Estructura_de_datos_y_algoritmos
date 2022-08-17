#include "grafo.h"
#include <sstream>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#include <limits>
Grafo::Grafo(int v)
{
    vertices=v;
    aristas=new int *[vertices];//tabla?
    for(int i=0;i< vertices;i++){
        aristas[i]=new int[vertices];
    }
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            aristas[i][j]=Grafo::INFINITO;
        }
    }
}

Grafo::~Grafo()
{
    for(int i=0;i<vertices;i++){
        delete[]aristas[i];
    }
    delete aristas;
}

int Grafo::coste(int v, int w)
{
    return( v>=1 && v<=vertices && w>=1 && w<= vertices)? aristas[v-1][w-1]:Grafo::INFINITO;

}

void Grafo::inserta(int v, int w, int coste)
{
    if(v>=1 && v<=vertices && w>=1 && w<=vertices){// si los valores estan dentro de lo que permite el grafo
        aristas[v-1][w-1]=coste;
    }
}

int Grafo::totalVertices()
{
    return vertices;
}


vector<int> Grafo::dijkstra(Grafo G)
{
    vector<int> vertices2;for(int i=1;i<G.totalVertices();i++){vertices2.push_back(i);};
    vector<int>S{0};
    vector<int> costes;
    int fila=0;
    while(vertices2.size()!=0){
        int cantidad=0;
        int eliminar;
        for(unsigned int j=0;j<vertices2.size();j++){
            if(cantidad==0 && G.coste(fila+1,vertices2.at(j)+1)!=Grafo::INFINITO){
                cantidad=G.coste(fila+1,vertices2.at(j)+1);
                eliminar=vertices2.at(j);
            }else if (cantidad!=0 && G.coste(fila+1,vertices2.at(j)+1)!=Grafo::INFINITO){
                if(cantidad>G.coste(fila+1,vertices2.at(j)+1)){
                    cantidad=G.coste(fila+1,vertices2.at(j)+1);
                    eliminar=vertices2.at(j);
                }
            }else{
                continue;//es infinito
            }
        }
        if(cantidad==0){//no hemos encontrado nada
            vertices2.push_back(S.at(S.size()-1));//introduce el ultimo camino valido;
            S.pop_back();
            costes.pop_back();
            fila=0;

        }else if(cantidad!=0){
            costes.push_back(cantidad);
            for(unsigned int i=0;i<vertices2.size();i++){
                if(vertices2.at(i)==eliminar){
                    vertices2.erase(vertices2.begin()+i);
                }
            }
            fila=eliminar;
            S.push_back(eliminar);
        }else{
            continue;//por si falla el QT
        }
    }
    return costes;
}

Grafo Grafo::prim(Grafo G)
{
    Grafo T(G.totalVertices());
    vector<int> U{0};
    vector<int> V;for(int i=1;i<G.totalVertices();i++){V.push_back(i);};
    int fila=0;
    while(V.size()!=0){
        int cantidad=0;
        int eliminar;
        for(unsigned int u=0;u<U.size();u++){
            for(unsigned int v=0;v<V.size();v++){
                if(cantidad==0 && G.coste(U.at(u)+1,V.at(v)+1)!=Grafo::INFINITO){
                    cantidad=G.coste(U.at(u)+1,V.at(v)+1);
                    eliminar=V.at(v);
                    fila=U.at(u);
                }else if(cantidad!=0 && G.coste(U.at(u)+1,V.at(v)+1)!=Grafo::INFINITO){
                    if(cantidad>G.coste(U.at(u)+1,V.at(v)+1)){
                        cantidad=G.coste(U.at(u)+1,V.at(v)+1);
                        eliminar=V.at(v);
                        fila=U.at(u);
                    }
                }else{
                    continue;//es infinito
                }
            }
        }
        U.push_back(eliminar);
        for(unsigned int i=0;i<V.size();i++){if(V.at(i)==eliminar){V.erase(V.begin()+i);}}
        T.inserta(fila+1,eliminar+1,cantidad);
    }
    return T;
}

string Grafo::imprime(string s)
{
    std::stringstream ss;
    ss<<"\n"<<s<<"\n";
    for(int i=0;i<vertices;i++){
        ss<<"\n["<<(i+1)<<"] ";
        for(int j=0;j<vertices;j++){
            if(aristas[i][j]==Grafo::INFINITO){
                ss<<"  --  ";
            }else{
                ss<<"  "<<aristas[i][j]<<"  ";
            }
        }
    }
    ss<<"\n";
    return ss.str();
}
std::string Grafo::profundidad(int v, bool *&visitado) {//se le pasa el vertice y el array de visitado ¿?
    std::stringstream ss;
    visitado[v] = true;
    ss << v + 1 << " ";
    // selecciona la arista i que lleva a un vértice no visitado
    for (int i = 0; i < vertices; i++)
        if (aristas[v][i] != Grafo::INFINITO && !visitado[i])// si existe un camino viable y no he visitado el vertice
            ss << profundidad(i, visitado);
    return ss.str();
}
std::string Grafo::profundidad(int inicio) {
    std::stringstream ss;
    bool *visitado = new bool[vertices];// el puntero que recoge un bool , es un nueva array de bool?
    for (int i = 0; i < vertices; i++)
        visitado[i] = false;
    ss << "\nRecorrido en profundidad \n";
    int v = inicio - 1;//los vertices como se guardan en una array , usamos el numero -1 como en array
    do {
        ss << "\n " << profundidad(v, visitado);// teoricamente ha recorrido todos los vertices
        // comprueba si existe un vértice v del grafo que no ha
        // sido visitado
        v = verticeNoVisitado(visitado, vertices);
    } while (v != -1);
    ss << "\n";
    return ss.str();
}

string Grafo::imprimeVector(string s, vector<int>vector)
{
    std::stringstream ss;
    ss<<"\n"<<s<<" [ ";
    for(unsigned int i=0;i<vector.size();i++){
        ss<<vector[i]<<" ";
    }
    ss<<"]";
    return ss.str();
}


int Grafo::verticeNoVisitado(bool *visitado, int vertices)
{
    for(int i=0;i<vertices;i++){
        if(visitado[i]==false){
            return i;
        }
    }
    return -1;
}
