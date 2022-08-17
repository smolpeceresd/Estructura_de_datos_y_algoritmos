#include "grafo.h"
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
#include <limits>
// PARTICIPANTES:
//CARMEN SANCHEZ HERNANDEZ
//SANTIAGO MOLPECERES DIAZ
Grafo::Grafo(int v)
{
    vertices=v;
    vector<vector<AristaGrafo*>> aristass;
    vector<AristaGrafo*> inserta;
    AristaGrafo* P{nullptr};
    inserta.resize(v,P);
    for(int i=0;i< vertices;i++){
        aristass.push_back(inserta);
    }
    aristas=aristass;

}

Grafo::~Grafo()
{

}

int Grafo::coste(int v, int w)
{
    return( v>=1 && v<=vertices && w>=1 && w<= vertices && aristas[v-1][w-1]!=nullptr)? aristas[v-1][w-1]->coste:Grafo::INFINITO;

}

void Grafo::inserta(int v, int w, int coste, string origen, string destino)
{
    if(v>=1 && v<=vertices && w>=1 && w<=vertices){// si los valores estan dentro de lo que permite el grafo
        aristas[v-1][w-1]=new AristaGrafo(v,w,coste,origen,destino);
        inserta_del_reves(w,v,coste,destino,origen);
    }
}

void Grafo::inserta_del_reves(int v, int w, int coste, string origen, string destino)
{
    aristas[v-1][w-1]=new AristaGrafo(v,w,coste,origen,destino);//si se cumple para uno , se cumple para el otro
}

void Grafo::inserta_de_prim(AristaGrafo *const & P)
{
    aristas[P->v-1][P->w-1]=P;
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

std::list<AristaGrafo *> Grafo::viajanteComercioVecino(Grafo G, int v){
    vector<int> vertices2;
    for(int i=0;i<G.totalVertices();i++){if(i==v-1){continue;}else{vertices2.push_back(i);};}
    vector<int>S{v-1};
    list<AristaGrafo*> Punteros;
    int fila=v-1;
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
            fila=0;
            Punteros.pop_back();

        }else if(cantidad!=0){
            for(unsigned int i=0;i<vertices2.size();i++){
                if(vertices2.at(i)==eliminar){
                    vertices2.erase(vertices2.begin()+i);
                }
            }
            Punteros.push_back(G.getAristas().at(fila).at(eliminar));
            fila=eliminar;
            S.push_back(eliminar);
        }else{
            continue;//por si falla el QT
        }
    }

    Punteros.push_back(G.getAristas().at(S.at(S.size()-1)).at(v-1));
    return Punteros;
}

std::list<AristaGrafo *> Grafo::viajanteComercioPrim(Grafo G, int v)
{
    list<AristaGrafo*> Punteros;// lista que devuelvo
    vector<int> T{v-1};// mi tour
    vector<int> W;for(int i=0;i<G.totalVertices();i++){if(i!=(v-1)){W.push_back(i);}};// no visitados
    vector<int> D;D.resize(G.totalVertices(),0);// grado de los vertices
    int fila=0;
    D.at(T.at(0))++;// lo incio a 1 para que no se pueda volver a usar tras la primera iteracion
    while(W.size()!=0){// mientras no visite todo
        int cantidad=0;
        int eliminar;
        for(unsigned int t=0;t<T.size();t++){
            if(D.at(T.at(t))<2){// si el grado es 0 o 1 funciona ->
                for(unsigned int w=0;w<W.size();w++){// comparo con cada V
                    if(cantidad==0 && G.coste(T.at(t)+1,W.at(w)+1)!=Grafo::INFINITO){
                        cantidad=G.coste(T.at(t)+1,W.at(w)+1);
                        eliminar=W.at(w);
                        fila=T.at(t);
                    }else if(cantidad!=0 && G.coste(T.at(t)+1,W.at(w)+1)!=Grafo::INFINITO){
                        if(cantidad>G.coste(T.at(t)+1,W.at(w)+1)){
                            cantidad=G.coste(T.at(t)+1,W.at(w)+1);
                            eliminar=W.at(w);
                            fila=T.at(t);
                        }
                    }else{
                        continue;//es infinito
                    }
                }
            }else{
                continue;//-> como el grado es 2 , no ejecuto nada;
            }
        }
        //ya he encontrado un camino aptimo
        T.push_back(eliminar);// meto mi vertice nuevo a mi tour
        D.at(fila)++;//aumento el grado
        D.at(eliminar)++;//aumento el grado
        for(unsigned int i=0;i<W.size();i++){if(W.at(i)==eliminar){W.erase(W.begin()+i);}}//elimino el nuevo vertice de T de W
        Punteros.push_back(G.getAristas().at(fila).at(eliminar));// introduzco el puntero
    }
    Punteros.push_back(G.getAristas().at(T.at(T.size()-1)).at(v-1));// introduzco la vuelta a casa
    return Punteros;
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
        T.inserta_de_prim(G.getAristas().at(fila).at(eliminar));
    }
    return T;
}

string Grafo::imprime(string s)
{
    std::stringstream ss;
    ss<<"\n\n"<<s<<"\n\n";
    for(int i=0;i<vertices;i++){
        if(i<vertices-1){
            ss<<"\n["<<aristas[i][i+1]->origen<<"] ";
        }else{
            ss<<"\n["<<aristas[i][i-1]->origen<<"] ";
        }
        for(int j=0;j<vertices;j++){
            if(aristas[i][j]==nullptr){
                ss<<"  --  ";
            }else{
                ss<<"  "<<aristas[i][j]->coste<<"  ";
            }
        }
    }
    ss<<"\n\n";
    return ss.str();
}

string Grafo::imprime_prim(string s)
{
    std::stringstream ss;
    ss<<"\n\n"<<s<<"\n\n";
    for(int i=0;i<vertices;i++){
        ss<<"\n["<<(i+1)<<"]";
        for(int j=0;j<vertices;j++){
            if(aristas[i][j]==nullptr){
                ss<<"  --  ";
            }else{
                ss<<"  "<<aristas[i][j]->coste<<"  ";
            }
        }
    }
    ss<<"\n\n";
    return ss.str();
}
std::string Grafo::profundidad(int v, bool *&visitado) {//se le pasa el vertice y el array de visitado ¿?
    std::stringstream ss;
    visitado[v] = true;
    ss << v + 1 << " ";
    // selecciona la arista i que lleva a un vértice no visitado
    for (int i = 0; i < vertices; i++)
        if (aristas[v][i] != nullptr && !visitado[i])// si existe un camino viable y no he visitado el vertice
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

string Grafo::imprimeLista(string s, list<AristaGrafo *> listado)
{
    int n=0;
    std::stringstream ss;
    ss<<"\n"<<s<<"\n\n";
    for(auto elem:listado){
        ss<<elem->origen<<" - "<<elem->destino<<" \tcoste: "<<elem->coste;
        n=n+elem->coste;
        ss<<"\n";
    }
    ss<<"\n\n El coste total del viaje es: "<<n<<"\n\tBuen Viaje :)\n\n\n\n";
    return ss.str();
}

vector<vector<AristaGrafo *> > Grafo::getAristas() const
{
    return aristas;
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
